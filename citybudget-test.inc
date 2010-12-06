function citybudget_test_data() {
  $clusters[] = array(
    'id' => 1,
    'cluster_id' => 1,
    'name' => 'The Accountability Offices',
  );
  
  $programs[] = array(
    'id' => 1,
    'name' => 'Council Appointed Programs'
  );
  
  $expenditure_categories[] = array(
    'id' => 1,
    'name' => 'Salaries and Benefits',
    'type' => 'expense'
  );
  $expenditure_categories[] = array(
    'id' => 2,
    'name' => 'Materials and Supplies',
    'type' => 'expense'
  );
  $expenditure_categories[] = array(
    'id' => 3,
    'type' => 'equipment',
    'type' => 'expense'
  );
  $expenditure_categories[] = array(
    'id' => 4,
    'name' => 'Services & Rents',
    'type' => 'expense'
  );
  $expenditure_categories[] = array(
    'id' => 5,
    'name' => 'Contributions to Capital',
    'type' => 'expense'
  );
  $expenditure_categories[] = array(
    'id' => 6,
    'name' => 'Contributions to Reserve/Res Funds',
    'type' => 'expense'
  );
  $expenditure_categories[] = array(
    'id' => 7,
    'name' => 'Other Expenditures',
    'type' => 'expense'
  );
  $expenditure_categories[] = array(
    'id' => 8,
    'name' => 'Interdivisional Charges',
    'type' => 'expense'
  );
  $expenditure_categories[] = array(
    'id' => 9,
    'name' => 'Interdivisional Recoveries',
    'type' => 'revenue'
  );
  $expenditure_categories[] = array(
    'id' => 10,
    'name' => 'Provincial Subsidies',
    'type' => 'revenue'
  );
  $expenditure_categories[] = array(
    'id' => 11,
    'name' => 'Federal Subsidies',
    'type' => 'revenue'
  );
  $expenditure_categories[] = array(
    'id' => 12,
    'name' => 'Other Subsidies',
    'type' => 'revenue'
  );
  $expenditure_categories[] = array(
    'id' => 13,
    'name' => 'User Fees & Donations',
    'type' => 'revenue'
  );
  $expenditure_categories[] = array(
    'id' => 14,
    'name' => 'Transfers from Capital Fund',
    'type' => 'revenue'
  );
  $expenditure_categories[] = array(
    'id' => 15,
    'name' => 'Contribution from Reserve Funds',
    'type' => 'revenue'
  );
  $expenditure_categories[] = array(
    'id' => 16,
    'name' => 'Contribution from Reserve',
    'type' => 'revenue'
  );
  $expenditure_categories[] = array(
    'id' => 17,
    'name' => 'Sundry Revenues',
    'type' => 'revenue'
  );

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
}