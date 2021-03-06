<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying edit links
 * as fields
 *
 * NOTE: This file was generated by autogen_model_implementation_drupal.xsl
 * 
 */


class thumbwhere_externalrepositorysync_handler_edit_link_field extends thumbwhere_externalrepositorysync_handler_link_field {
  function construct() {
    parent::construct();
    //$this->additional_fields['type'] = 'type';
  }


  function render($values) {
    //$type = $values->{$this->aliases['type']};

    //Creating a dummy thumbwhere_externalrepositorysync to check access against
    //$dummy_thumbwhere_externalrepositorysync = (object) array('type' => $type);
    //if (!thumbwhere_externalrepositorysync_access('edit', $dummy_thumbwhere_externalrepositorysync)) {
    //  return;
    //}

    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    $thumbwhere_externalrepositorysync_id = $values->{$this->aliases['pk_externalrepositorysync']};

    return l($text, 'admin/thumbwhere/thumbwhere_externalrepositorysyncs/thumbwhere_externalrepositorysync/' . $thumbwhere_externalrepositorysync_id . '/edit');
  }
}
