<?php

/**
 * Callback for retrieving a budget.
 *
 * @param string $name
 * @return object
 */
function _citybudget_retrieve($name) {
  return _citybudget_get_budget_program($name);
}

/**
 * Callback for listing budgets.
 *
 * @param int $page
 * @param array $parameters
 * @return array
 */
function _citybudget_index() {
  return _citybudget_list_programs();
}