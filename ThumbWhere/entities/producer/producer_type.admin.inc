<?php

/**
 * @file
 * Producer type editing UI.
 */

/**
 * UI controller.
 */
class ProducerTypeUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = 'Manage producer entity types, including adding and removing fields and the display of fields.';
    return $items;
  }
}

/**
 * Generates the producer type editing form.
 */
function producer_type_form($form, &$form_state, $producer_type, $op = 'edit') {

  if ($op == 'clone') {
    $producer_type->label .= ' (cloned)';
    $producer_type->type = '';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $producer_type->label,
    '#description' => t('The human-readable name of this producer type.'),
    '#required' => TRUE,
    '#size' => 30,
  );
  // Machine-readable type name.
  $form['type'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($producer_type->type) ? $producer_type->type : '',
    '#maxlength' => 32,
//    '#disabled' => $producer_type->isLocked() && $op != 'clone',
    '#machine_name' => array(
      'exists' => 'producer_get_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this producer type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['data']['#tree'] = TRUE;
  $form['data']['sample_data'] = array(
    '#type' => 'checkbox',
    '#title' => t('An interesting producer switch'),
    '#default_value' => !empty($producer_type->data['sample_data']),
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save producer type'),
    '#weight' => 40,
  );

  //Locking not supported yet
  /*if (!$producer_type->isLocked() && $op != 'add') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete producer type'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('producer_type_form_submit_delete')
    );
  }*/
  return $form;
}

/**
 * Form API submit callback for the type form.
 */
function producer_type_form_submit(&$form, &$form_state) {
  $producer_type = entity_ui_form_submit_build_entity($form, $form_state);
  $producer_type->save();
  $form_state['redirect'] = 'admin/structure/producer_types';
}

/**
 * Form API submit callback for the delete button.
 */
function producer_type_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/structure/producer_types/manage/' . $form_state['producer_type']->type . '/delete';
}
