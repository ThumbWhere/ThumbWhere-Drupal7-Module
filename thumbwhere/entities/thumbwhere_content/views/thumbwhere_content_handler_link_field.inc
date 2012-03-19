<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying links to entities
 * as fields.
 */

class thumbwhere_content_handler_link_field extends views_handler_field {
  function construct() {
    parent::construct();

    //$this->additional_fields['thumbwhere_content_id'] = 'thumbwhere_content_id';
    $this->additional_fields['pk_content'] = 'pk_content';
    //$this->additional_fields['type'] = 'type';
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['text'] = array('default' => '', 'translatable' => TRUE);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['text'] = array(
      //'#type' => 'textfield',
      '#title' => t('Text to display'),
      '#default_value' => $this->options['text'],
    );
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $text = !empty($this->options['text']) ? $this->options['text'] : t('view');
    //$thumbwhere_content_id = $values->{$this->aliases['thumbwhere_content_id']};
    $thumbwhere_content_id = $values->{$this->aliases['pk_content']};

    return l($text, 'thumbwhere_content/' . $thumbwhere_content_id);
  }
}
