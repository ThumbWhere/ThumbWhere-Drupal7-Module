<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying deletes links
 * as fields
 */

class thumbwhere_producer_handler_delete_link_field extends thumbwhere_producer_handler_link_field {
  function construct() {
    parent::construct();
   // $this->additional_fields['type'] = 'type';
  }


  function render($values) {
    //$type = $values->{$this->aliases['type']};

    //Creating a dummy thumbwhere_producer to check access against
    //$dummy_thumbwhere_producer = (object) array('type' => $type);
    //if (!thumbwhere_producer_access('edit', $dummy_thumbwhere_producer)) {
    //  return;
    //}

    $text = !empty($this->options['text']) ? $this->options['text'] : t('delete');
    $thumbwhere_producer_id = $values->{$this->aliases['thumbwhere_producer_id']};

    return l($text, 'admin/content/thumbwhere_producers/thumbwhere_producer/' . $thumbwhere_producer_id . '/delete');
  }
}
