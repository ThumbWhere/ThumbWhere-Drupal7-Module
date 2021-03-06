<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying edit links
 * as fields
 *
 * NOTE: This file was generated by autogen_model_implementation_drupal.xsl
 * 
 */


class thumbwhere_contentcollection_handler_edit_link_field extends thumbwhere_contentcollection_handler_link_field {
  function construct() {
    parent::construct();
    //$this->additional_fields['type'] = 'type';
  }


  function render($values) {
    //$type = $values->{$this->aliases['type']};

    //Creating a dummy thumbwhere_contentcollection to check access against
    //$dummy_thumbwhere_contentcollection = (object) array('type' => $type);
    //if (!thumbwhere_contentcollection_access('edit', $dummy_thumbwhere_contentcollection)) {
    //  return;
    //}

    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    $thumbwhere_contentcollection_id = $values->{$this->aliases['pk_contentcollection']};

    return l($text, 'admin/thumbwhere/thumbwhere_contentcollections/thumbwhere_contentcollection/' . $thumbwhere_contentcollection_id . '/edit');
  }
}
