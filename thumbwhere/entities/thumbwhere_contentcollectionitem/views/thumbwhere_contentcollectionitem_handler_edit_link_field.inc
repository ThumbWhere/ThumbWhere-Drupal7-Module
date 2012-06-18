<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying edit links
 * as fields
 *
 * NOTE: This file was generated by autogen_model_implementation_drupal.xsl
 * 
 */


class thumbwhere_contentcollectionitem_handler_edit_link_field extends thumbwhere_contentcollectionitem_handler_link_field {
  function construct() {
    parent::construct();
    //$this->additional_fields['type'] = 'type';
  }


  function render($values) {
    //$type = $values->{$this->aliases['type']};

    //Creating a dummy thumbwhere_contentcollectionitem to check access against
    //$dummy_thumbwhere_contentcollectionitem = (object) array('type' => $type);
    //if (!thumbwhere_contentcollectionitem_access('edit', $dummy_thumbwhere_contentcollectionitem)) {
    //  return;
    //}

    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    $thumbwhere_contentcollectionitem_id = $values->{$this->aliases['pk_contentcollectionitem']};

    return l($text, 'admin/content/thumbwhere_contentcollectionitems/thumbwhere_contentcollectionitem/' . $thumbwhere_contentcollectionitem_id . '/edit');
  }
}