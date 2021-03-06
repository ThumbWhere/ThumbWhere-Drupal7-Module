<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying edit links
 * as fields
 *
 * NOTE: This file was generated by autogen_model_implementation_drupal.xsl
 * 
 */


class thumbwhere_produce_handler_edit_link_field extends thumbwhere_produce_handler_link_field {
  function construct() {
    parent::construct();
    //$this->additional_fields['type'] = 'type';
  }


  function render($values) {
    //$type = $values->{$this->aliases['type']};

    //Creating a dummy thumbwhere_produce to check access against
    //$dummy_thumbwhere_produce = (object) array('type' => $type);
    //if (!thumbwhere_produce_access('edit', $dummy_thumbwhere_produce)) {
    //  return;
    //}

    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    $thumbwhere_produce_id = $values->{$this->aliases['pk_produce']};

    return l($text, 'admin/thumbwhere/thumbwhere_produces/thumbwhere_produce/' . $thumbwhere_produce_id . '/edit');
  }
}
