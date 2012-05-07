<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying edit links
 * as fields
 *
 * NOTE: This file was generated by autogen_model_implementation_drupal.xsl
 * 
 */


class thumbwhere_mediaitem_handler_edit_link_field extends thumbwhere_mediaitem_handler_link_field {
  function construct() {
    parent::construct();
    //$this->additional_fields['type'] = 'type';
  }


  function render($values) {
    //$type = $values->{$this->aliases['type']};

    //Creating a dummy thumbwhere_mediaitem to check access against
    //$dummy_thumbwhere_mediaitem = (object) array('type' => $type);
    //if (!thumbwhere_mediaitem_access('edit', $dummy_thumbwhere_mediaitem)) {
    //  return;
    //}

    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    $thumbwhere_mediaitem_id = $values->{$this->aliases['pk_mediaitem']};

    return l($text, 'admin/content/thumbwhere_mediaitems/thumbwhere_mediaitem/' . $thumbwhere_mediaitem_id . '/edit');
  }
}