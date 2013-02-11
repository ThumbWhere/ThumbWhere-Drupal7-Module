<?php

/**
 * @file
 * Provides list of operations that are possible in the thumbwhere_externalsubscription editing view.
 *
 * NOTE: This file was generated by autogen_model_implementation_drupal.xsl
 *   
 */

/**
 * This field handler aggregates operations that can be done on a thumbwhere_externalsubscription
 * under a single field providing a more flexible way to present them in a view
 */
class thumbwhere_externalsubscription_handler_thumbwhere_externalsubscription_operations_field extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['pk_externalsubscription'] = 'pk_externalsubscription';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {

    $links = menu_contextual_links('thumbwhere_externalsubscription', 'admin/thumbwhere/thumbwhere_externalsubscriptions/thumbwhere_externalsubscription', array($this->get_value($values, 'pk_externalsubscription')));

    if (!empty($links)) {
      return theme('links', array('links' => $links, 'attributes' => array('class' => array('links', 'inline', 'operations'))));
    }
  }
}