<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying deletes links
 * as fields
 *
 * NOTE: This file was generated by autogen_model_implementation_drupal.xsl
 * 
 */

class thumbwhere_like_handler_delete_link_field extends thumbwhere_like_handler_link_field {
  function construct() {
    parent::construct();
  }

  function render($values) {

    $text = !empty($this->options['text']) ? $this->options['text'] : t('delete');
    $thumbwhere_like_id = $values->{$this->aliases['pk_like']};

    return l($text, 'admin/thumbwhere/thumbwhere_likes/thumbwhere_like/' . $pk_like . '/delete');
  }
}
