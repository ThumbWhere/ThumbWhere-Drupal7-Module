<?php

/**
 * @file
 * Provides list of operations that are possible in the thumbwhere_hostorder editing view.
 *
 * NOTE: This file was generated by autogen_model_implementation_drupal.xsl
 *   
 */

/**
 * This field handler aggregates operations that can be done on a thumbwhere_hostorder
 * under a single field providing a more flexible way to present them in a view
 */
class thumbwhere_hostorder_handler_thumbwhere_hostorder_operations_field extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['pk_hostorder'] = 'pk_hostorder';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {

    $links = menu_contextual_links('thumbwhere_hostorder', 'admin/thumbwhere/thumbwhere_hostorders/thumbwhere_hostorder', array($this->get_value($values, 'pk_hostorder')));

    if (!empty($links)) {
      return theme('links', array('links' => $links, 'attributes' => array('class' => array('links', 'inline', 'operations'))));
    }
  }
}
