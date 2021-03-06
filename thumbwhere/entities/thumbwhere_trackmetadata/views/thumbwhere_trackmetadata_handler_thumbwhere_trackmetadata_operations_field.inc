<?php

/**
 * @file
 * Provides list of operations that are possible in the thumbwhere_trackmetadata editing view.
 *
 * NOTE: This file was generated by autogen_model_implementation_drupal.xsl
 *   
 */

/**
 * This field handler aggregates operations that can be done on a thumbwhere_trackmetadata
 * under a single field providing a more flexible way to present them in a view
 */
class thumbwhere_trackmetadata_handler_thumbwhere_trackmetadata_operations_field extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['pk_trackmetadata'] = 'pk_trackmetadata';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {

    $links = menu_contextual_links('thumbwhere_trackmetadata', 'admin/thumbwhere/thumbwhere_trackmetadatas/thumbwhere_trackmetadata', array($this->get_value($values, 'pk_trackmetadata')));

    if (!empty($links)) {
      return theme('links', array('links' => $links, 'attributes' => array('class' => array('links', 'inline', 'operations'))));
    }
  }
}
