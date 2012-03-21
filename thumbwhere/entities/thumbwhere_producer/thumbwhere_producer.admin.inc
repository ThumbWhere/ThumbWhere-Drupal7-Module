<?php

/**
 * @file
 * ThumbWhereProducer editing UI.
 *
 * We make very little use of the EntityAPI interface for this - preferring instead to use
 * views. That offers more flexibility to change a UI that will, more often than not,
 * be end-user facing.
 */

/**
 * UI controller.
 */
class ThumbWhereProducerUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults. Main reason for doing this is that
   * parent class hook_menu() is optimized for entity type administration.
   */
  public function hook_menu() {

    $items = array();
    $id_count = count(explode('/', $this->path));
    $wildcard = isset($this->entityInfo['admin ui']['menu wildcard']) ? $this->entityInfo['admin ui']['menu wildcard'] : '%' . $this->entityType;

    $items[$this->path] = array(
      'title' => 'ThumbWhereProducers',
      'description' => 'Add edit and update thumbwhere_producers.',
      'page callback' => 'system_admin_menu_block_page',
      'access arguments' => array('access administration pages'),
      'file path' => drupal_get_path('module', 'system'),
      'file' => 'system.admin.inc',
    );

    // Change the overview menu type for the list of thumbwhere_producers.
    $items[$this->path]['type'] = MENU_LOCAL_TASK;

    // Change the add page menu to multiple types of entities
    $items[$this->path . '/add'] = array(
      'title' => 'Add a thumbwhere_producer',
      'description' => 'Add a new thumbwhere_producer',
      'page callback'  => 'thumbwhere_producer_add_page',
      'access callback'  => 'thumbwhere_producer_access',
      'access arguments' => array('edit'),
      'type' => MENU_NORMAL_ITEM,
      'weight' => 20,
      'file' => 'thumbwhere_producer.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])

    );

    $items[$this->path . '/add/' . 'thumbwhere_producer'] = array(
      'title' => 'Add ' . 'ThumbWhereProducer',
      'page callback' => 'thumbwhere_producer_form_wrapper',
      'page arguments' => array(thumbwhere_producer_create(array('type' => 'thumbwhere_producer'))),
      'access callback' => 'thumbwhere_producer_access',
      'access arguments' => array('edit', 'edit ' . 'thumbwhere_producer'),
      'file' => 'thumbwhere_producer.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );

    // Loading and editing thumbwhere_producer entities
    $items[$this->path . '/thumbwhere_producer/' . $wildcard] = array(
      'page callback' => 'thumbwhere_producer_form_wrapper',
      'page arguments' => array($id_count + 1),
      'access callback' => 'thumbwhere_producer_access',
      'access arguments' => array('edit', $id_count + 1),
      'weight' => 0,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
      'file' => 'thumbwhere_producer.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );
    $items[$this->path . '/thumbwhere_producer/' . $wildcard . '/edit'] = array(
      'title' => 'Edit',
      'type' => MENU_DEFAULT_LOCAL_TASK,
      'weight' => -10,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
    );

    $items[$this->path . '/thumbwhere_producer/' . $wildcard . '/delete'] = array(
      'title' => 'Delete',
      'page callback' => 'thumbwhere_producer_delete_form_wrapper',
      'page arguments' => array($id_count + 1),
      'access callback' => 'thumbwhere_producer_access',
      'access arguments' => array('edit', $id_count + 1),
      'type' => MENU_LOCAL_TASK,
      'context' => MENU_CONTEXT_INLINE,
      'weight' => 10,
      'file' => 'thumbwhere_producer.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );

    // Menu item for viewing thumbwhere_producers
    $items['thumbwhere_producer/' . $wildcard] = array(
      //'title' => 'Title',
      'title callback' => 'thumbwhere_producer_page_title',
      'title arguments' => array(1),
      'page callback' => 'thumbwhere_producer_page_view',
      'page arguments' => array(1),
      'access callback' => 'thumbwhere_producer_access',
      'access arguments' => array('view', 1),
      'type' => MENU_CALLBACK,
    );
    return $items;
  }


  /**
   * Create the markup for the add ThumbWhereProducer Entities page within the class
   * so it can easily be extended/overriden.
   */
  public function addPage() {
    $item = menu_get_item();
    $content = system_admin_menu_block($item);

    if (count($content) == 1) {
      $item = array_shift($content);
      drupal_goto($item['href']);
    }

    return theme('thumbwhere_producer_add_list', array('content' => $content));
  }

}


/**
 * Form callback wrapper: create or edit a thumbwhere_producer.
 *
 * @param $thumbwhere_producer
 *   The thumbwhere_producer object being edited by this form.
 *
 * @see thumbwhere_producer_edit_form()
 */
function thumbwhere_producer_form_wrapper($thumbwhere_producer) {
  // Add the breadcrumb for the form's location.
  thumbwhere_producer_set_breadcrumb();
  return drupal_get_form('thumbwhere_producer_edit_form', $thumbwhere_producer);
}


/**
 * Form callback wrapper: delete a thumbwhere_producer.
 *
 * @param $thumbwhere_producer
 *   The thumbwhere_producer object being edited by this form.
 *
 * @see thumbwhere_producer_edit_form()
 */
function thumbwhere_producer_delete_form_wrapper($thumbwhere_producer) {
  // Add the breadcrumb for the form's location.
  //thumbwhere_producer_set_breadcrumb();
  return drupal_get_form('thumbwhere_producer_delete_form', $thumbwhere_producer);
}


/**
 * Form callback: create or edit a thumbwhere_producer.
 *
 * @param $thumbwhere_producer
 *   The thumbwhere_producer object to edit or for a create form an empty thumbwhere_producer object
 *     with only a thumbwhere_producer type defined.
 */
function thumbwhere_producer_edit_form($form, &$form_state, $thumbwhere_producer) {
  // Add the default field elements.
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('ThumbWhereProducer Name'),
    '#default_value' => isset($thumbwhere_producer->name) ? $thumbwhere_producer->name : '',
    '#maxlength' => 255,
    '#required' => TRUE,
    '#weight' => -5,
  );

  $form['data']['#tree'] = TRUE;

  /*
  $form['data']['sample_data'] = array(
    '#type' => 'checkbox',
    '#title' => t('An interesting thumbwhere_producer switch'),
    '#default_value' => isset($thumbwhere_producer->data['sample_data']) ? $thumbwhere_producer->data['sample_data'] : 1,
  );
	*/


  // Add the field related form elements.
  $form_state['thumbwhere_producer'] = $thumbwhere_producer;
  field_attach_form('thumbwhere_producer', $thumbwhere_producer, $form, $form_state);

  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
    '#weight' => 400,
  );

  // We add the form's #submit array to this button along with the actual submit
  // handler to preserve any submit handlers added by a form callback_wrapper.
  $submit = array();

  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save thumbwhere_producer'),
    '#submit' => $submit + array('thumbwhere_producer_edit_form_submit'),
  );

  if (!empty($thumbwhere_producer->name)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete thumbwhere_producer'),
      '#suffix' => l(t('Cancel'), 'admin/content/thumbwhere_producers'),
      '#submit' => $submit + array('thumbwhere_producer_form_submit_delete'),
      '#weight' => 45,
    );
  }

  // We append the validate handler to #validate in case a form callback_wrapper
  // is used to add validate handlers earlier.
  $form['#validate'][] = 'thumbwhere_producer_edit_form_validate';
  return $form;
}


/**
 * Form API validate callback for the thumbwhere_producer form
 */
function thumbwhere_producer_edit_form_validate(&$form, &$form_state) {
  $thumbwhere_producer = $form_state['thumbwhere_producer'];

  // Notify field widgets to validate their data.
  field_attach_form_validate('thumbwhere_producer', $thumbwhere_producer, $form, $form_state);
}


/**
 * Form API submit callback for the thumbwhere_producer form.
 *
 * @todo remove hard-coded link
 */
function thumbwhere_producer_edit_form_submit(&$form, &$form_state) {

  $thumbwhere_producer = entity_ui_controller('thumbwhere_producer')->entityFormSubmitBuildEntity($form, $form_state);
  // Save the thumbwhere_producer and go back to the list of thumbwhere_producers

  // Add in created and changed times.
  if ($thumbwhere_producer->is_new = isset($thumbwhere_producer->is_new) ? $thumbwhere_producer->is_new : 0) {
    $thumbwhere_producer->created = time();
  }

  $thumbwhere_producer->changed = time();

  $thumbwhere_producer->save();
  $form_state['redirect'] = 'admin/content/thumbwhere_producers';
}

/**
 * Form API submit callback for the delete button.
 *
 * @todo Remove hard-coded path
 */
function thumbwhere_producer_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/content/thumbwhere_producers/thumbwhere_producer/' . $form_state['thumbwhere_producer']->thumbwhere_producer_id . '/delete';
}


/**
 * Form callback: confirmation form for deleting a thumbwhere_producer.
 *
 * @param $thumbwhere_producer
 *   The thumbwhere_producer to delete
 *
 * @see confirm_form()
 */
function thumbwhere_producer_delete_form($form, &$form_state, $thumbwhere_producer) {
  $form_state['thumbwhere_producer'] = $thumbwhere_producer;

  $form['#submit'][] = 'thumbwhere_producer_delete_form_submit';

  $form = confirm_form($form,
    t('Are you sure you want to delete thumbwhere_producer %name?', array('%name' => $thumbwhere_producer->name)),
    'admin/content/thumbwhere_producers/thumbwhere_producer',
    '<p>' . t('This action cannot be undone.') . '</p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
  );

  return $form;
}

/**
 * Submit callback for thumbwhere_producer_delete_form
 */
function thumbwhere_producer_delete_form_submit($form, &$form_state) {
  $thumbwhere_producer = $form_state['thumbwhere_producer'];

  thumbwhere_producer_delete($thumbwhere_producer);

  drupal_set_message(t('The thumbwhere_producer %name has been deleted.', array('%name' => $thumbwhere_producer->name)));
  watchdog('thumbwhere_producer', 'Deleted thumbwhere_producer %name.', array('%name' => $thumbwhere_producer->name));

  $form_state['redirect'] = 'admin/content/thumbwhere_producers';
}



/**
 * Page to add ThumbWhereProducer Entities.
 *
 * @todo Pass this through a proper theme function
 */
function thumbwhere_producer_add_page() {
  $controller = entity_ui_controller('thumbwhere_producer');
  return $controller->addPage();
}


/**
 * Displays the list of available thumbwhere_producer types for thumbwhere_producer creation.
 *
 * @ingroup themeable
 */
function theme_thumbwhere_producer_add_list($variables) {


  //$content = $variables['content'];
  $output = '';
  /*
  if ($content) {
    $output = '<dl class="thumbwhere_producer-type-list">';
    foreach ($content as $item) {
      $output .= '<dt>' . l($item['title'], $item['href']) . '</dt>';
      $output .= '<dd>' . filter_xss_admin($item['description']) . '</dd>';
    }
    $output .= '</dl>';
  }
  else {
    if (user_access('administer thumbwhere_producer types')) {
      $output = '<p>' . t('ThumbWhereProducer Entities cannot be added because you have not created any thumbwhere_producer types yet. Go to the <a href="@create-thumbwhere_producer-type">thumbwhere_producer type creation page</a> to add a new thumbwhere_producer type.', array('@create-thumbwhere_producer-type' => url('admin/structure/thumbwhere_producer_types/add'))) . '</p>';
    }
    else {
      $output = '<p>' . t('No thumbwhere_producer types have been created yet for you to use.') . '</p>';
    }
  }
	*/
  return $output;
}





/**
 * Sets the breadcrumb for administrative thumbwhere_producer pages.
 */
function thumbwhere_producer_set_breadcrumb() {
  $breadcrumb = array(
    l(t('Home'), '<front>'),
    l(t('Administration'), 'admin'),
    l(t('Content'), 'admin/content'),
    l(t('ThumbWhereProducers'), 'admin/content/thumbwhere_producers'),
  );

  drupal_set_breadcrumb($breadcrumb);
}


