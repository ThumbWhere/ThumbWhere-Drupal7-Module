<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying edit links
 * as fields
 */


class thumbwhere_content_handler_edit_link_field extends thumbwhere_content_handler_link_field {
  function construct() {
    parent::construct();
    //$this->additional_fields['type'] = 'type';
  }


  function render($values) {
    //$type = $values->{$this->aliases['type']};

    //Creating a dummy thumbwhere_content to check access against
    //$dummy_thumbwhere_content = (object) array('type' => $type);
    //if (!thumbwhere_content_access('edit', $dummy_thumbwhere_content)) {
    //  return;
    //}

    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    $thumbwhere_content_id = $values->{$this->aliases['thumbwhere_content_id']};

    return l($text, 'admin/content/thumbwhere_contents/thumbwhere_content/' . $thumbwhere_content_id . '/edit');
  }
}
