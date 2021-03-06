<?php

/**
 * @file
 * Provides list of operations that are possible in the thumbwhere_hostproviderhosttype editing view.
 *
 * NOTE: This file was generated by autogen_model_implementation_drupal.xsl
 *   
 */

/**
 * This field handler aggregates operations that can be done on a thumbwhere_hostproviderhosttype
 * under a single field providing a more flexible way to present them in a view
 */
class thumbwhere_hostproviderhosttype_handler_thumbwhere_hostproviderhosttype_operations_field extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['pk_hostproviderhosttype'] = 'pk_hostproviderhosttype';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {

    $links = menu_contextual_links('thumbwhere_hostproviderhosttype', 'admin/thumbwhere/thumbwhere_hostproviderhosttypes/thumbwhere_hostproviderhosttype', array($this->get_value($values, 'pk_hostproviderhosttype')));

    if (!empty($links)) {
      return theme('links', array('links' => $links, 'attributes' => array('class' => array('links', 'inline', 'operations'))));
    }
  }
}
