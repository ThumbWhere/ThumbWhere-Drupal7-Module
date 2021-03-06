<?php

/**
 * @file
 * Provides list of operations that are possible in the thumbwhere_member editing view.
 *
 * NOTE: This file was generated by autogen_model_implementation_drupal.xsl
 *   
 */

/**
 * This field handler aggregates operations that can be done on a thumbwhere_member
 * under a single field providing a more flexible way to present them in a view
 */
class thumbwhere_member_handler_thumbwhere_member_operations_field extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['pk_member'] = 'pk_member';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {

    $links = menu_contextual_links('thumbwhere_member', 'admin/thumbwhere/thumbwhere_members/thumbwhere_member', array($this->get_value($values, 'pk_member')));

    if (!empty($links)) {
      return theme('links', array('links' => $links, 'attributes' => array('class' => array('links', 'inline', 'operations'))));
    }
  }
}
