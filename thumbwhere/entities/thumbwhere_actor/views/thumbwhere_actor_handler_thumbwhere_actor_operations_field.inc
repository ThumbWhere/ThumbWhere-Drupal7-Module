<?php

/**
 * @file
 * Provides list of operations that are possible in the thumbwhere_actor editing view.
 *
 * NOTE: This file was generated by autogen_model_implementation_drupal.xsl
 *   
 */

/**
 * This field handler aggregates operations that can be done on a thumbwhere_actor
 * under a single field providing a more flexible way to present them in a view
 */
class thumbwhere_actor_handler_thumbwhere_actor_operations_field extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['pk_actor'] = 'pk_actor';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {

    $links = menu_contextual_links('thumbwhere_actor', 'admin/thumbwhere/thumbwhere_actors/thumbwhere_actor', array($this->get_value($values, 'pk_actor')));

    if (!empty($links)) {
      return theme('links', array('links' => $links, 'attributes' => array('class' => array('links', 'inline', 'operations'))));
    }
  }
}
