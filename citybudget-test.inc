

function citybudget_test_data() {
  // Insert clusters.
  $clusters[] = array(
    'id' => 1,
    'name' => 'The Accountability Offices',
  );
  foreach($clusters as $cluster) {
    drupal_write_record('citybudget_clusters', $cluster);
  }
  
  // Insert programs.
  $programs[] = array(
    'id' => 1,
    'cluster_id' => 1,
    'name' => 'Council Appointed Programs'
  );
  foreach($programs as $program) {
    drupal_write_record('citybudget_programs', $program);
  }
  
  // Insert expenditure categories.
  $expenditure_categories[] = array(
    'id' => 1,
    'name' => 'Salaries and Benefits',
    'type' => CITYBUDGET_EXPENDITURE_CATEGORY_EXPENSE
  );
  $expenditure_categories[] = array(
    'id' => 2,
    'name' => 'Materials and Supplies',
    'type' => CITYBUDGET_EXPENDITURE_CATEGORY_EXPENSE
  );
  $expenditure_categories[] = array(
    'id' => 3,
    'name' => 'Equipment',
    'type' => CITYBUDGET_EXPENDITURE_CATEGORY_EXPENSE
  );
  $expenditure_categories[] = array(
    'id' => 4,
    'name' => 'Services & Rents',
    'type' => CITYBUDGET_EXPENDITURE_CATEGORY_EXPENSE
  );
  $expenditure_categories[] = array(
    'id' => 5,
    'name' => 'Contributions to Capital',
    'type' => CITYBUDGET_EXPENDITURE_CATEGORY_EXPENSE
  );
  $expenditure_categories[] = array(
    'id' => 6,
    'name' => 'Contributions to Reserve/Res Funds',
    'type' => CITYBUDGET_EXPENDITURE_CATEGORY_EXPENSE
  );
  $expenditure_categories[] = array(
    'id' => 7,
    'name' => 'Other Expenditures',
    'type' => CITYBUDGET_EXPENDITURE_CATEGORY_EXPENSE
  );
  $expenditure_categories[] = array(
    'id' => 8,
    'name' => 'Interdivisional Charges',
    'type' => CITYBUDGET_EXPENDITURE_CATEGORY_EXPENSE
  );
  $expenditure_categories[] = array(
    'id' => 9,
    'name' => 'Interdivisional Recoveries',
    'type' => CITYBUDGET_EXPENDITURE_CATEGORY_REVENUE
  );
  $expenditure_categories[] = array(
    'id' => 10,
    'name' => 'Provincial Subsidies',
    'type' => CITYBUDGET_EXPENDITURE_CATEGORY_REVENUE
  );
  $expenditure_categories[] = array(
    'id' => 11,
    'name' => 'Federal Subsidies',
    'type' => CITYBUDGET_EXPENDITURE_CATEGORY_REVENUE
  );
  $expenditure_categories[] = array(
    'id' => 12,
    'name' => 'Other Subsidies',
    'type' => CITYBUDGET_EXPENDITURE_CATEGORY_REVENUE
  );
  $expenditure_categories[] = array(
    'id' => 13,
    'name' => 'User Fees & Donations',
    'type' => CITYBUDGET_EXPENDITURE_CATEGORY_REVENUE
  );
  $expenditure_categories[] = array(
    'id' => 14,
    'name' => 'Transfers from Capital Fund',
    'type' => CITYBUDGET_EXPENDITURE_CATEGORY_REVENUE
  );
  $expenditure_categories[] = array(
    'id' => 15,
    'name' => 'Contribution from Reserve Funds',
    'type' => CITYBUDGET_EXPENDITURE_CATEGORY_REVENUE
  );
  $expenditure_categories[] = array(
    'id' => 16,
    'name' => 'Contribution from Reserve',
    'type' => CITYBUDGET_EXPENDITURE_CATEGORY_REVENUE
  );
  $expenditure_categories[] = array(
    'id' => 17,
    'name' => 'Sundry Revenues',
    'type' => CITYBUDGET_EXPENDITURE_CATEGORY_REVENUE
  );
  foreach($expenditure_categories as $expenditure_category) {
    drupal_write_record('citybudget_expenditure_categories', $expenditure_category);
  }
  
  // Insert line items.
  $line_items[] = array(
    'program_id' => 1,
    'expenditure_id' => 1,
    '2009_budget' => 1709.9,
    '2009_actual' => 1709.9,
    '2010_budget' => 2057.2,
    '2011_outlook' => 2125.1,
    '2012_outlook' => 2168.6,
  );
  $line_items[] = array(
    'program_id' => 1,
    'expenditure_id' => 2,
    '2009_budget' => 18.1,
    '2009_actual' => 18.1,
    '2010_budget' => 18.1,
    '2011_outlook' => 18.5,
    '2012_outlook' => 18.8,
  );
  $line_items[] = array(
    'program_id' => 1,
    'expenditure_id' => 3,
    '2009_budget' => 10.7,
    '2009_actual' => 10.7,
    '2010_budget' => 10.7,
    '2011_outlook' => 10.8,
    '2012_outlook' => 11.1,
  );
  $line_items[] = array(
    'program_id' => 1,
    'expenditure_id' => 4,
    '2009_budget' => 557.1,
    '2009_actual' => 557.1,
    '2010_budget' => 433,
    '2011_outlook' => 439.2,
    '2012_outlook' => 445.8,
  );
  $line_items[] = array(
    'program_id' => 1,
    'expenditure_id' => 6,
    '2009_budget' => 6.9,
    '2009_actual' => 6.9,
    '2010_budget' => 6.9,
    '2011_outlook' => 6.9,
    '2012_outlook' => 6.9,
  );
  $line_items[] = array(
    'program_id' => 1,
    'expenditure_id' => 8,
    '2009_budget' => 61.4,
    '2009_actual' => 61.4,
    '2010_budget' => 61.4,
    '2011_outlook' => 61.4,
    '2012_outlook' => 61.4,
  );
  foreach($line_items as $line_item) {
    drupal_write_record('citybudget_line_items', $line_item);
  }
}