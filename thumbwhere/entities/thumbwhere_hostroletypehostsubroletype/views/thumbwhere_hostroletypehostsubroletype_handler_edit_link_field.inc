<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying edit links
 * as fields
 *
 * NOTE: This file was generated by autogen_model_implementation_drupal.xsl
 * 
 */


class thumbwhere_hostroletypehostsubroletype_handler_edit_link_field extends thumbwhere_hostroletypehostsubroletype_handler_link_field {
  function construct() {
    parent::construct();
    //$this->additional_fields['type'] = 'type';
  }


  function render($values) {
    //$type = $values->{$this->aliases['type']};

    //Creating a dummy thumbwhere_hostroletypehostsubroletype to check access against
    //$dummy_thumbwhere_hostroletypehostsubroletype = (object) array('type' => $type);
    //if (!thumbwhere_hostroletypehostsubroletype_access('edit', $dummy_thumbwhere_hostroletypehostsubroletype)) {
    //  return;
    //}

    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    $thumbwhere_hostroletypehostsubroletype_id = $values->{$this->aliases['pk_hostroletypehostsubroletype']};

    return l($text, 'admin/thumbwhere/thumbwhere_hostroletypehostsubroletypes/thumbwhere_hostroletypehostsubroletype/' . $thumbwhere_hostroletypehostsubroletype_id . '/edit');
  }
}
