<?php

/**
 * @file
 * Provides list of operations that are possible in the thumbwhere_bookmark editing view.
 *
 * NOTE: This file was generated by autogen_model_implementation_drupal.xsl
 *   
 */

/**
 * This field handler aggregates operations that can be done on a thumbwhere_bookmark
 * under a single field providing a more flexible way to present them in a view
 */
class thumbwhere_bookmark_handler_thumbwhere_bookmark_operations_field extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['pk_bookmark'] = 'pk_bookmark';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {

    $links = menu_contextual_links('thumbwhere_bookmark', 'admin/thumbwhere/thumbwhere_bookmarks/thumbwhere_bookmark', array($this->get_value($values, 'pk_bookmark')));

    if (!empty($links)) {
      return theme('links', array('links' => $links, 'attributes' => array('class' => array('links', 'inline', 'operations'))));
    }
  }
}