<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying deletes links
 * as fields
 */


class producer_handler_delete_link_field extends producer_handler_link_field {
  function construct() {
    parent::construct();
   // $this->additional_fields['type'] = 'type';
  }


  function render($values) {
    //$type = $values->{$this->aliases['type']};
    
    //Creating a dummy producer to check access against
    //$dummy_producer = (object) array('type' => $type);
    //if (!producer_access('edit', $dummy_producer)) {
    //  return;
    //}
    
    $text = !empty($this->options['text']) ? $this->options['text'] : t('delete');
    $producer_id = $values->{$this->aliases['producer_id']};
    
    return l($text, 'admin/content/producers/producer/' . $producer_id . '/delete');
  }
}
