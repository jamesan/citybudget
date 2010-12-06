<?php
// $Id$

/**
 * @file
 * Administration page callbacks for the annotate module.
 */

/**
 * Form builder. Import budget data.
 *
 * @ingroup forms
 */
function citybudget_import_data() {
  $form['citybudget_import_csv'] = array(
    '#type' => 'textarea',
    '#title' => t('CSV dump'),
    '#required' => TRUE,
    '#description' => t('A dump of a CSV to be imported into the City Budget Navigator tables.'),
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Import data'),
  );

  if (!empty($_POST) && form_get_errors()) {
    drupal_set_message(t('The settings have not been saved because of the errors.'), 'error');
  }
  
  return $form;
}

function citybudget_import_data_submit($form, &$form_state) {
  require_once(libraries_get_path('parsecsv') . '/parsecsv.lib.php');
  $csv = new parseCSV($form_state['values']['citybudget_import_csv']);
  $rows = $csv->data;
  
  $clusters = array();
  $programs = array();
  $categories = array();
  
  foreach($rows as $row) {
    if(!isset($clusters[$row['Cluster']])) {
      $clusters[$row['Cluster']] = TRUE;
    }
    if(!isset($programs[$row['Program']])) {
      $programs[$row['Program']] = $row['Cluster'];
    }
    if(!isset($categories[$row['Category']])) {
      if($row['Expense/Revenue'] == 'Expense') {
        $categories[$row['Category']] = CITYBUDGET_CATEGORY_EXPENSE;
      } else if($row['Expense/Revenue'] == 'Revenue') {
        $categories[$row['Category']] = CITYBUDGET_CATEGORY_REVENUE;
      }
    } else if(($row['Expense/Revenue'] == 'Expense' && $categories[$row['Category']] == CITYBUDGET_CATEGORY_REVENUE) ||
              ($row['Expense/Revenue'] == 'Revenue' && $categories[$row['Category']] == CITYBUDGET_CATEGORY_EXPENSE)) {
      $categories[$row['Category']] = CITYBUDGET_CATEGORY_BOTH;
    }
  }
  /*
  db_query('TRUNCATE TABLE {citybudget_clusters}');
  db_query('TRUNCATE TABLE {citybudget_programs}');
  db_query('TRUNCATE TABLE {citybudget_categories}');
  */
  foreach($clusters as $cluster_name => $count) {
    $cluster_record = new StdClass();
    $cluster_record->name = $cluster_name;
    drupal_write_record('citybudget_clusters', $cluster_record);
    $cluster_records[$cluster_name] = $cluster_record;
  }
  
  foreach($programs as $program_name => $cluster_name) {
    $program_record = new StdClass();
    $program_record->name = $program_name;
    $program_record->cluster_id = $cluster_records[$cluster_name]->id;
    drupal_write_record('citybudget_programs', $program_record);
    $program_records[$program_name] = $program_record;
  }
  
  foreach($categories as $category_name => $type) {
    if($type != CITYBUDGET_CATEGORY_BOTH) {
      $category_record = new StdClass();
      $category_record->name = $category_name;
      $category_record->type = $type;
      drupal_write_record('citybudget_categories', $category_record);
      $category_records[$category_record->name] = $category_record;
    } else {
      $category_record_exp = new StdClass();
      $category_record_exp->name = $category_name;
      $category_record_exp->type = CITYBUDGET_CATEGORY_EXPENSE;
      $category_record_rev = new StdClass();
      $category_record_rev->name = $category_name;
      $category_record_rev->type = CITYBUDGET_CATEGORY_REVENUE;
      drupal_write_record('citybudget_categories', $category_record_exp);
      drupal_write_record('citybudget_categories', $category_record_rev);
      $category_records[$category_name] = array(
        'Expense' => $category_record_exp,
        'Revenue' => $category_record_rev
      );
    }
  }
  
  foreach($rows as $row) {
    $line_item = new StdClass();
    $line_item->program_id = $program_records[$row['Program']]->id;
    if(is_object($category_records[$row['Category']])) {
      $line_item->category_id = $category_records[$row['Category']]->id;
    } else {
      $line_item->category_id = $category_records[$row['Category']][$row['Expense/Revenue']]->id;
    }
    $line_item->{'2009_budget'} = (float) $row['2009 Budget'];
    $line_item->{'2009_actual'} = (float) $row['2009 Actual'];
    $line_item->{'2010_budget'} = (float) $row['2010 Budget'];
    $line_item->{'2011_outlook'} = (float) $row['2011 Outlook'];
    $line_item->{'2012_outlook'} = (float) $row['2012 Outlook'];
    
    drupal_write_record('citybudget_line_items', $line_item);
    $line_item_records[] = $line_item;
  }
  
  //$form_state['redirect'] = 'budget';
}