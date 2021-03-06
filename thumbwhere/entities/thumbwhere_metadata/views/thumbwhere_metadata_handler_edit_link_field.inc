<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying edit links
 * as fields
 *
 * NOTE: This file was generated by autogen_model_implementation_drupal.xsl
 * 
 */


class thumbwhere_metadata_handler_edit_link_field extends thumbwhere_metadata_handler_link_field {
  function construct() {
    parent::construct();
    //$this->additional_fields['type'] = 'type';
  }


  function render($values) {
    //$type = $values->{$this->aliases['type']};

    //Creating a dummy thumbwhere_metadata to check access against
    //$dummy_thumbwhere_metadata = (object) array('type' => $type);
    //if (!thumbwhere_metadata_access('edit', $dummy_thumbwhere_metadata)) {
    //  return;
    //}

    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    $thumbwhere_metadata_id = $values->{$this->aliases['pk_metadata']};

    return l($text, 'admin/thumbwhere/thumbwhere_metadatas/thumbwhere_metadata/' . $thumbwhere_metadata_id . '/edit');
  }
}
