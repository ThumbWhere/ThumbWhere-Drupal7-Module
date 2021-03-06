<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying edit links
 * as fields
 *
 * NOTE: This file was generated by autogen_model_implementation_drupal.xsl
 * 
 */


class thumbwhere_hostproviderhosttype_handler_edit_link_field extends thumbwhere_hostproviderhosttype_handler_link_field {
  function construct() {
    parent::construct();
    //$this->additional_fields['type'] = 'type';
  }


  function render($values) {
    //$type = $values->{$this->aliases['type']};

    //Creating a dummy thumbwhere_hostproviderhosttype to check access against
    //$dummy_thumbwhere_hostproviderhosttype = (object) array('type' => $type);
    //if (!thumbwhere_hostproviderhosttype_access('edit', $dummy_thumbwhere_hostproviderhosttype)) {
    //  return;
    //}

    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    $thumbwhere_hostproviderhosttype_id = $values->{$this->aliases['pk_hostproviderhosttype']};

    return l($text, 'admin/thumbwhere/thumbwhere_hostproviderhosttypes/thumbwhere_hostproviderhosttype/' . $thumbwhere_hostproviderhosttype_id . '/edit');
  }
}
