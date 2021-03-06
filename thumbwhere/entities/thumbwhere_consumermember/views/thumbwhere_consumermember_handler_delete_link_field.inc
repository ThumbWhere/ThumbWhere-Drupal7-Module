<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying deletes links
 * as fields
 *
 * NOTE: This file was generated by autogen_model_implementation_drupal.xsl
 * 
 */

class thumbwhere_consumermember_handler_delete_link_field extends thumbwhere_consumermember_handler_link_field {
  function construct() {
    parent::construct();
  }

  function render($values) {

    $text = !empty($this->options['text']) ? $this->options['text'] : t('delete');
    $thumbwhere_consumermember_id = $values->{$this->aliases['pk_consumermember']};

    return l($text, 'admin/thumbwhere/thumbwhere_consumermembers/thumbwhere_consumermember/' . $pk_consumermember . '/delete');
  }
}
