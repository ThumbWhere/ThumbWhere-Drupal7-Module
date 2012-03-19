<?php

/**
 * @file
 * Provides list of operations that are possible in the thumbwhere_content editing view.
 */

/**
 * This field handler aggregates operations that can be done on a thumbwhere_content
 * under a single field providing a more flexible way to present them in a view
 */
class thumbwhere_content_handler_thumbwhere_content_operations_field extends views_handler_field {
  function construct() {
    parent::construct();

    //$this->additional_fields['thumbwhere_content_id'] = 'thumbwhere_content_id';
    $this->additional_fields['pk_content'] = 'pk_content';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {

    //$links = menu_contextual_links('thumbwhere_content', 'admin/content/thumbwhere_contents/thumbwhere_content', array($this->get_value($values, 'thumbwhere_content_id')));
    $links = menu_contextual_links('thumbwhere_content', 'admin/content/thumbwhere_contents/thumbwhere_content', array($this->get_value($values, 'pk_content')));

    if (!empty($links)) {
      return theme('links', array('links' => $links, 'attributes' => array('class' => array('links', 'inline', 'operations'))));
    }
  }
}
