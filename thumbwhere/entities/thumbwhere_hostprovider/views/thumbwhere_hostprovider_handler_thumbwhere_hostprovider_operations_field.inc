<?php

/**
 * @file
 * Provides list of operations that are possible in the thumbwhere_hostprovider editing view.
 *
 * NOTE: This file was generated by autogen_model_implementation_drupal.xsl
 *   
 */

/**
 * This field handler aggregates operations that can be done on a thumbwhere_hostprovider
 * under a single field providing a more flexible way to present them in a view
 */
class thumbwhere_hostprovider_handler_thumbwhere_hostprovider_operations_field extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['pk_hostprovider'] = 'pk_hostprovider';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {

    $links = menu_contextual_links('thumbwhere_hostprovider', 'admin/thumbwhere/thumbwhere_hostproviders/thumbwhere_hostprovider', array($this->get_value($values, 'pk_hostprovider')));

    if (!empty($links)) {
      return theme('links', array('links' => $links, 'attributes' => array('class' => array('links', 'inline', 'operations'))));
    }
  }
}