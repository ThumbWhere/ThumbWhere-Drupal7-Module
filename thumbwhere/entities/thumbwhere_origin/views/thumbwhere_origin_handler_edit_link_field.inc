<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying edit links
 * as fields
 *
 * NOTE: This file was generated by autogen_model_implementation_drupal.xsl
 * 
 */


class thumbwhere_origin_handler_edit_link_field extends thumbwhere_origin_handler_link_field {
  function construct() {
    parent::construct();
    //$this->additional_fields['type'] = 'type';
  }


  function render($values) {
    //$type = $values->{$this->aliases['type']};

    //Creating a dummy thumbwhere_origin to check access against
    //$dummy_thumbwhere_origin = (object) array('type' => $type);
    //if (!thumbwhere_origin_access('edit', $dummy_thumbwhere_origin)) {
    //  return;
    //}

    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    $thumbwhere_origin_id = $values->{$this->aliases['pk_origin']};

    return l($text, 'admin/thumbwhere/thumbwhere_origins/thumbwhere_origin/' . $thumbwhere_origin_id . '/edit');
  }
}