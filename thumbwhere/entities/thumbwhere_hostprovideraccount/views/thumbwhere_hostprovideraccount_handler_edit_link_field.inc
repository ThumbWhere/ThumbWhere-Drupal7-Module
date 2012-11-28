<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying edit links
 * as fields
 *
 * NOTE: This file was generated by autogen_model_implementation_drupal.xsl
 * 
 */


class thumbwhere_hostprovideraccount_handler_edit_link_field extends thumbwhere_hostprovideraccount_handler_link_field {
  function construct() {
    parent::construct();
    //$this->additional_fields['type'] = 'type';
  }


  function render($values) {
    //$type = $values->{$this->aliases['type']};

    //Creating a dummy thumbwhere_hostprovideraccount to check access against
    //$dummy_thumbwhere_hostprovideraccount = (object) array('type' => $type);
    //if (!thumbwhere_hostprovideraccount_access('edit', $dummy_thumbwhere_hostprovideraccount)) {
    //  return;
    //}

    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    $thumbwhere_hostprovideraccount_id = $values->{$this->aliases['pk_hostprovideraccount']};

    return l($text, 'admin/thumbwhere/thumbwhere_hostprovideraccounts/thumbwhere_hostprovideraccount/' . $thumbwhere_hostprovideraccount_id . '/edit');
  }
}