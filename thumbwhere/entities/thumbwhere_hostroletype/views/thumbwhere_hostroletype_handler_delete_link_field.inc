<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying deletes links
 * as fields
 *
 * NOTE: This file was generated by autogen_model_implementation_drupal.xsl
 * 
 */

class thumbwhere_hostroletype_handler_delete_link_field extends thumbwhere_hostroletype_handler_link_field {
  function construct() {
    parent::construct();
  }

  function render($values) {

    $text = !empty($this->options['text']) ? $this->options['text'] : t('delete');
    $thumbwhere_hostroletype_id = $values->{$this->aliases['pk_hostroletype']};

    return l($text, 'admin/thumbwhere/thumbwhere_hostroletypes/thumbwhere_hostroletype/' . $pk_hostroletype . '/delete');
  }
}
