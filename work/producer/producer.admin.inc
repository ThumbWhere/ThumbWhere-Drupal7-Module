<?php

/**
 * @file
 * Producer editing UI.
 *
 * We make very little use of the EntityAPI interface for this - preferring instead to use
 * views. That offers more flexibility to change a UI that will, more often than not,
 * be end-user facing.
 */

//ddl('producer.admin.inc');

/**
 * UI controller.
 */
class ProducerUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults. Main reason for doing this is that
   * parent class hook_menu() is optimized for entity type administration.
   */
  public function hook_menu() {

    $items = array();
    $id_count = count(explode('/', $this->path));
    $wildcard = isset($this->entityInfo['admin ui']['menu wildcard']) ? $this->entityInfo['admin ui']['menu wildcard'] : '%' . $this->entityType;

    $items[$this->path] = array(
      'title' => 'Producers',
      'description' => 'Add edit and update producers.',
      'page callback' => 'system_admin_menu_block_page',
      'access arguments' => array('access administration pages'),
      'file path' => drupal_get_path('module', 'system'),
      'file' => 'system.admin.inc',
    );

    // Change the overview menu type for the list of producers.
    $items[$this->path]['type'] = MENU_LOCAL_TASK;

    // Change the add page menu to multiple types of entities
    $items[$this->path . '/add'] = array(
      'title' => 'Add a producer',
      'description' => 'Add a new producer',
      'page callback'  => 'producer_add_page',
      'access callback'  => 'producer_access',
      'access arguments' => array('edit'),
      'type' => MENU_NORMAL_ITEM,
      'weight' => 20,
      'file' => 'producer.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])

    );

    $items[$this->path . '/add/' . 'producer'] = array(
      'title' => 'Add ' . 'Producer',
      'page callback' => 'producer_form_wrapper',
      'page arguments' => array(producer_create(array('type' => 'producer'))),
      'access callback' => 'producer_access',
      'access arguments' => array('edit', 'edit ' . 'producer'),
      'file' => 'producer.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );

    // Loading and editing producer entities
    $items[$this->path . '/producer/' . $wildcard] = array(
      'page callback' => 'producer_form_wrapper',
      'page arguments' => array($id_count + 1),
      'access callback' => 'producer_access',
      'access arguments' => array('edit', $id_count + 1),
      'weight' => 0,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
      'file' => 'producer.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );
    $items[$this->path . '/producer/' . $wildcard . '/edit'] = array(
      'title' => 'Edit',
      'type' => MENU_DEFAULT_LOCAL_TASK,
      'weight' => -10,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
    );

    $items[$this->path . '/producer/' . $wildcard . '/delete'] = array(
      'title' => 'Delete',
      'page callback' => 'producer_delete_form_wrapper',
      'page arguments' => array($id_count + 1),
      'access callback' => 'producer_access',
      'access arguments' => array('edit', $id_count + 1),
      'type' => MENU_LOCAL_TASK,
      'context' => MENU_CONTEXT_INLINE,
      'weight' => 10,
      'file' => 'producer.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );

    // Menu item for viewing producers
    $items['producer/' . $wildcard] = array(
      //'title' => 'Title',
      'title callback' => 'producer_page_title',
      'title arguments' => array(1),
      'page callback' => 'producer_page_view',
      'page arguments' => array(1),
      'access callback' => 'producer_access',
      'access arguments' => array('view', 1),
      'type' => MENU_CALLBACK,
    );
    return $items;
  }


  /**
   * Create the markup for the add Producer Entities page within the class
   * so it can easily be extended/overriden.
   */
  public function addPage() {
    $item = menu_get_item();
    $content = system_admin_menu_block($item);

    if (count($content) == 1) {
      $item = array_shift($content);
      drupal_goto($item['href']);
    }

    return theme('producer_add_list', array('content' => $content));
  }

}


/**
 * Form callback wrapper: create or edit a producer.
 *
 * @param $producer
 *   The producer object being edited by this form.
 *
 * @see producer_edit_form()
 */
function producer_form_wrapper($producer) {
  // Add the breadcrumb for the form's location.
  producer_set_breadcrumb();
  return drupal_get_form('producer_edit_form', $producer);
}


/**
 * Form callback wrapper: delete a producer.
 *
 * @param $producer
 *   The producer object being edited by this form.
 *
 * @see producer_edit_form()
 */
function producer_delete_form_wrapper($producer) {
  // Add the breadcrumb for the form's location.
  //producer_set_breadcrumb();
  return drupal_get_form('producer_delete_form', $producer);
}


/**
 * Form callback: create or edit a producer.
 *
 * @param $producer
 *   The producer object to edit or for a create form an empty producer object
 *     with only a producer type defined.
 */
function producer_edit_form($form, &$form_state, $producer) {
  // Add the default field elements.
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Producer Name'),
    '#default_value' => isset($producer->name) ? $producer->name : '',
    '#maxlength' => 255,
    '#required' => TRUE,
    '#weight' => -5,
  );

  $form['data']['#tree'] = TRUE;

  /*
  $form['data']['sample_data'] = array(
    '#type' => 'checkbox',
    '#title' => t('An interesting producer switch'),
    '#default_value' => isset($producer->data['sample_data']) ? $producer->data['sample_data'] : 1,
  );
	*/


  // Add the field related form elements.
  $form_state['producer'] = $producer;
  field_attach_form('producer', $producer, $form, $form_state);

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
    '#value' => t('Save producer'),
    '#submit' => $submit + array('producer_edit_form_submit'),
  );

  if (!empty($producer->name)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete producer'),
      '#suffix' => l(t('Cancel'), 'admin/content/producers'),
      '#submit' => $submit + array('producer_form_submit_delete'),
      '#weight' => 45,
    );
  }

  // We append the validate handler to #validate in case a form callback_wrapper
  // is used to add validate handlers earlier.
  $form['#validate'][] = 'producer_edit_form_validate';
  return $form;
}


/**
 * Form API validate callback for the producer form
 */
function producer_edit_form_validate(&$form, &$form_state) {
  $producer = $form_state['producer'];

  // Notify field widgets to validate their data.
  field_attach_form_validate('producer', $producer, $form, $form_state);
}


/**
 * Form API submit callback for the producer form.
 *
 * @todo remove hard-coded link
 */
function producer_edit_form_submit(&$form, &$form_state) {

  $producer = entity_ui_controller('producer')->entityFormSubmitBuildEntity($form, $form_state);
  // Save the producer and go back to the list of producers

  // Add in created and changed times.
  if ($producer->is_new = isset($producer->is_new) ? $producer->is_new : 0) {
    $producer->created = time();
  }

  $producer->changed = time();

  $producer->save();
  $form_state['redirect'] = 'admin/content/producers';
}

/**
 * Form API submit callback for the delete button.
 *
 * @todo Remove hard-coded path
 */
function producer_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/content/producers/producer/' . $form_state['producer']->producer_id . '/delete';
}


/**
 * Form callback: confirmation form for deleting a producer.
 *
 * @param $producer
 *   The producer to delete
 *
 * @see confirm_form()
 */
function producer_delete_form($form, &$form_state, $producer) {
  $form_state['producer'] = $producer;

  $form['#submit'][] = 'producer_delete_form_submit';

  $form = confirm_form($form,
    t('Are you sure you want to delete producer %name?', array('%name' => $producer->name)),
    'admin/content/producers/producer',
    '<p>' . t('This action cannot be undone.') . '</p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
  );

  return $form;
}

/**
 * Submit callback for producer_delete_form
 */
function producer_delete_form_submit($form, &$form_state) {
  $producer = $form_state['producer'];

  producer_delete($producer);

  drupal_set_message(t('The producer %name has been deleted.', array('%name' => $producer->name)));
  watchdog('producer', 'Deleted producer %name.', array('%name' => $producer->name));

  $form_state['redirect'] = 'admin/content/producers';
}



/**
 * Page to add Producer Entities.
 *
 * @todo Pass this through a proper theme function
 */
function producer_add_page() {
  $controller = entity_ui_controller('producer');
  return $controller->addPage();
}


/**
 * Displays the list of available producer types for producer creation.
 *
 * @ingroup themeable
 */
function theme_producer_add_list($variables) {


  //$content = $variables['content'];
  $output = '';
  /*
  if ($content) {
    $output = '<dl class="producer-type-list">';
    foreach ($content as $item) {
      $output .= '<dt>' . l($item['title'], $item['href']) . '</dt>';
      $output .= '<dd>' . filter_xss_admin($item['description']) . '</dd>';
    }
    $output .= '</dl>';
  }
  else {
    if (user_access('administer producer types')) {
      $output = '<p>' . t('Producer Entities cannot be added because you have not created any producer types yet. Go to the <a href="@create-producer-type">producer type creation page</a> to add a new producer type.', array('@create-producer-type' => url('admin/structure/producer_types/add'))) . '</p>';
    }
    else {
      $output = '<p>' . t('No producer types have been created yet for you to use.') . '</p>';
    }
  }
	*/
  return $output;
}





/**
 * Sets the breadcrumb for administrative producer pages.
 */
function producer_set_breadcrumb() {
  $breadcrumb = array(
    l(t('Home'), '<front>'),
    l(t('Administration'), 'admin'),
    l(t('Content'), 'admin/content'),
    l(t('Producers'), 'admin/content/producers'),
  );

  drupal_set_breadcrumb($breadcrumb);
}



