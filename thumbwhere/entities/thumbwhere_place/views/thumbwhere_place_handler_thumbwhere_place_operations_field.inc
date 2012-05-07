<?php

/**
 * @file
 * Provides list of operations that are possible in the thumbwhere_place editing view.
 *
 * NOTE: This file was generated by autogen_model_implementation_drupal.xsl
 *   
 */

/**
 * This field handler aggregates operations that can be done on a thumbwhere_place
 * under a single field providing a more flexible way to present them in a view
 */
class thumbwhere_place_handler_thumbwhere_place_operations_field extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['pk_place'] = 'pk_place';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {

    $links = menu_contextual_links('thumbwhere_place', 'admin/content/thumbwhere_places/thumbwhere_place', array($this->get_value($values, 'pk_place')));

    if (!empty($links)) {
      return theme('links', array('links' => $links, 'attributes' => array('class' => array('links', 'inline', 'operations'))));
    }
  }
}