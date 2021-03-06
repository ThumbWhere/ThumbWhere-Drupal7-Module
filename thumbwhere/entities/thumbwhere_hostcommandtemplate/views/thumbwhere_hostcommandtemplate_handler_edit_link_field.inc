<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying edit links
 * as fields
 *
 * NOTE: This file was generated by autogen_model_implementation_drupal.xsl
 * 
 */


class thumbwhere_hostcommandtemplate_handler_edit_link_field extends thumbwhere_hostcommandtemplate_handler_link_field {
  function construct() {
    parent::construct();
    //$this->additional_fields['type'] = 'type';
  }


  function render($values) {
    //$type = $values->{$this->aliases['type']};

    //Creating a dummy thumbwhere_hostcommandtemplate to check access against
    //$dummy_thumbwhere_hostcommandtemplate = (object) array('type' => $type);
    //if (!thumbwhere_hostcommandtemplate_access('edit', $dummy_thumbwhere_hostcommandtemplate)) {
    //  return;
    //}

    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    $thumbwhere_hostcommandtemplate_id = $values->{$this->aliases['pk_hostcommandtemplate']};

    return l($text, 'admin/thumbwhere/thumbwhere_hostcommandtemplates/thumbwhere_hostcommandtemplate/' . $thumbwhere_hostcommandtemplate_id . '/edit');
  }
}
