<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying edit links
 * as fields
 *
 * NOTE: This file was generated by autogen_model_implementation_drupal.xsl
 * 
 */


class thumbwhere_trackmetadata_handler_edit_link_field extends thumbwhere_trackmetadata_handler_link_field {
  function construct() {
    parent::construct();
    //$this->additional_fields['type'] = 'type';
  }


  function render($values) {
    //$type = $values->{$this->aliases['type']};

    //Creating a dummy thumbwhere_trackmetadata to check access against
    //$dummy_thumbwhere_trackmetadata = (object) array('type' => $type);
    //if (!thumbwhere_trackmetadata_access('edit', $dummy_thumbwhere_trackmetadata)) {
    //  return;
    //}

    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    $thumbwhere_trackmetadata_id = $values->{$this->aliases['pk_trackmetadata']};

    return l($text, 'admin/thumbwhere/thumbwhere_trackmetadatas/thumbwhere_trackmetadata/' . $thumbwhere_trackmetadata_id . '/edit');
  }
}
