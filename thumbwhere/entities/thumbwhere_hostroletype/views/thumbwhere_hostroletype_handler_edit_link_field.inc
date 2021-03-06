<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying edit links
 * as fields
 *
 * NOTE: This file was generated by autogen_model_implementation_drupal.xsl
 * 
 */


class thumbwhere_hostroletype_handler_edit_link_field extends thumbwhere_hostroletype_handler_link_field {
  function construct() {
    parent::construct();
    //$this->additional_fields['type'] = 'type';
  }


  function render($values) {
    //$type = $values->{$this->aliases['type']};

    //Creating a dummy thumbwhere_hostroletype to check access against
    //$dummy_thumbwhere_hostroletype = (object) array('type' => $type);
    //if (!thumbwhere_hostroletype_access('edit', $dummy_thumbwhere_hostroletype)) {
    //  return;
    //}

    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    $thumbwhere_hostroletype_id = $values->{$this->aliases['pk_hostroletype']};

    return l($text, 'admin/thumbwhere/thumbwhere_hostroletypes/thumbwhere_hostroletype/' . $thumbwhere_hostroletype_id . '/edit');
  }
}
