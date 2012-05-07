<?php

/**
 * @file
 * ThumbWhereTrackMetadata editing UI.
 *
 * We make very little use of the EntityAPI interface for this - preferring instead to use
 * views. That offers more flexibility to change a UI that will, more often than not,
 * be end-user facing.
 *
 * NOTE: This file was generated by autogen_model_implementation_drupal.xsl
 */




 
/**
 * Handle the notification for content_ingext
 */
function _thumbwhere_handle_track_metadata_notify_xml($notification) {

  //
  // Get the operation
  //

  if (!isset($notification->attributes()->op)) {
    drupal_add_http_header('Status', '501 unable to fulfull request..');
    print('We were expecting an \'op\', attribute on the \'track_metadata\', element.');
    exit(0);
  }

  $op = $notification->attributes()->op;

  if (twCanDebug()) debug('op');
  if (twCanDebug()) debug($op);

  //
  // Get the context
  //

  if (!isset($notification->attributes()->key)) {
    drupal_add_http_header('Status', '501 unable to fulfull request..');
    print('We were expecting a \'key\', attribute on the \'track_metadata\', element.');
    exit(0);
  }

  $context_key =  $notification->attributes()->key;

  //
  // Now based on the operation..
  //

  switch($op)
  {
    case 'update':
      {
        //
        // What resource are we updating?
        //
      
        //
        // Get the id
        //
		
        if (!isset($notification->attributes()->id)) {
          drupal_add_http_header('Status', '501 unable to fulfull request.');
          print('We were expecting an \'id\', attribute on the \'track_metadata\', element when we are performing an \'update\' notification..');
          exit(0);
        }

        $id = intval($notification->attributes()->id);
		

        if (twCanDebug()) debug('id');
        if (twCanDebug()) debug($id);

      
        //
        // Get the fields
        //
          
        $entities = entity_load('thumbwhere_trackmetadata', array($id));

        if (twCanDebug()) debug('$entities');
        if (twCanDebug()) debug($entities);

        if (count($entities) == 0) {
          drupal_add_http_header('Status', '404 No such resource exists.');
          print('No such \'track_metadata\' resource exists with an id of \'' . $id . '\'.');
	    watchdog('thumbwhere_trackmetadata', 'No such \'track_metadata\' resource exists with an id of \'' . $id . '\'.' ,array(), WATCHDOG_ERROR);          exit(0);
        }

        // Getting a reference to the entity we asked for
        $entity = $entities[$id];

        //
        // We are only updating what has been passed through.
        // No test for missing values.
        // TODO: Validate incoming values.
        //


        if (!isset($notification->attributes()->key)) {
          if (twCanDebug()) debug('$entities');
          if (twCanDebug()) debug($entities);
        }

        // Finally write the entity.
        entity_save('thumbwhere_trackmetadata', $entity);

        //
        // Send the final response
        //

        drupal_add_http_header('Content-Type', 'text/xml');
        print('<response>');
        print('<track_metadata op="' . $op . '" id="' . $id . '" >');
        print('<status>success</status>');
        print('</track_metadata>');
        print('</response>');
        exit(0);
      }

    default:
      {
        drupal_add_http_header('Status', '501 Unable to fulfull request..');
        print('We were expecting a \'key\', attribute on the \'track_metadata\', element.');
        exit(0);

      }
  }
}



/**
 * Menu callback: React to a notifications for ContentIngest.
 */
function _thumbwhere_track_metadata_notify() {

  if (variable_get('thumbwhere_api_log_debug', 0) == 1) {
    watchdog('thumbwhere_track_metadata', 'incoming notification.');
  }

  $numargs = func_num_args();
  $arg_list = func_get_args();

  
	if (twCanDebug()) debug('$numargs  = ' . $numargs);
	
	if (twCanDebug()) debug('$arg_list = ' . $arg_list);
	
	if (twCanDebug()) debug('$_REQUEST');
	if (twCanDebug()) debug($_REQUEST);
	
	if (twCanDebug()) debug('$_GET');
	if (twCanDebug()) debug($_GET);
	
	if (twCanDebug()) debug('$_POST');
	if (twCanDebug()) debug($_POST);
	
	//if (twCanDebug()) debug('$HTTP_RAW_POST_DATA');
	//if (twCanDebug()) debug($HTTP_RAW_POST_DATA);
	
	if (twCanDebug()) debug('$_SERVER');
	if (twCanDebug()) debug($_SERVER);
	
	//if (twCanDebug()) debug('$GLOBALS');
	//if (twCanDebug()) debug($GLOBALS);

  

  if (variable_get('thumbwhere_api_log_debug', 0) == 1) {
    foreach ($arg_list as $arg) {
      if (twCanDebug()) debug('$arg  = ' . $arg);
    }
  }


  //////////////////////////////////////////////////
  //
  //

  switch ($_SERVER['REQUEST_METHOD']) {

    case 'POST': {
        if ($numargs == 1) {
          if ($arg_list[0] == 'track_metadata') {

            //
            // Get the POST data as XML
            //

            $post_xml = new SimpleXMLElement('php://input', null, true);
            if (twCanDebug()) debug('$post_xml');
            if (twCanDebug()) debug($post_xml);

            if (twCanDebug()) debug('$post_xml->getName()');
            if (twCanDebug()) debug($post_xml->getName());

            // We expect 'action' as the root element. TODO: I would rather this was the more generic 'request'
            if ($post_xml->getName() != 'action') {
              drupal_add_http_header('Status', '404 not found.');
              print('We were expecting \'action\', as the root element, not \'' . $post_xml->getName() . '\'.');
              exit(0);
            }

            /*
             *  SimpleXMLElement::__set_state(array(
             *      'track_metadata' =>
             *      SimpleXMLElement::__set_state(array(
             *       '@attributes' =>
             *      array (
             *        'key' => '8e9ff318-3cd7-4593-99de-4c37c0fb335a',
             *        'op' => 'create',
             *      ),
             *    )),
             *  ))
             */


            // We expect 'action' as the root element.
            if (!isset($post_xml->track_metadata)) {
              drupal_add_http_header('Status', '404 not found.');
              print('We were expecting a \'track_metadata\', element in the action payload.');
              exit(0);
            }

            // Handle the incoming notification for content ingest
            _thumbwhere_handle_track_metadata_notify_xml($post_xml->track_metadata);

          }
          else {
            drupal_add_http_header('Status', '404 not found.');
            print('Invalid resource');
            exit(0);
          }
        }
        else {
          drupal_add_http_header('Status', '404 not found.');
          print('Invalid notification request url format.');
          exit(0);
        }
      }
      break;

    case 'GET': {

        if ($numargs == 1) {

          // If we are returning the index.xml file for the webservice.
          if ($arg_list[0] == 'index.xml') {
            // return index.xml
            drupal_add_http_header('Content-Type', 'text/xml');
            readfile(dirname(__FILE__) . '/index.xml');
            exit(0);
          }
          else {
            drupal_add_http_header('Status', '404 not found.');
            print('File not found.');
            exit(0);
          }
        }
        else {
          drupal_add_http_header('Status', '404 not found.');
          print('Invalid notification request url format.');
          exit(0);
        }
      }
      break;

    default: {
        drupal_add_http_header('Status', '404 not found.');
        exit(0);
      }
      break;
  }

  //
  //
  ////////////////////////////////////////////////////////////////////////////////////
 
}





/**
 * TrackMetadata UI controller.
 */
class ThumbWhereTrackMetadataUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults. Main reason for doing this is that
   * parent class hook_menu() is optimized for entity type administration.
   */
  public function hook_menu() {

    $items = array();
    
    // Add a notification page...
    $items['thumbwhere/track_metadata/notify'] = array(
        'title' => 'Notifications Callback for "TrackMetadata" Entity',
        'page callback' => '_thumbwhere_track_metadata_notify',
        'access arguments' => array(
            'send thumbwhere trackmetadata notifications'
        ),
        'file' => 'thumbwhere_trackmetadata.admin.inc',
        'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );    
    
    $id_count = count(explode('/', $this->path));
    $wildcard = isset($this->entityInfo['admin ui']['menu wildcard']) ? $this->entityInfo['admin ui']['menu wildcard'] : '%' . $this->entityType;

    $items[$this->path] = array(
      'title' => 'ThumbWhereTrackMetadatas',
      'description' => 'Add edit and update thumbwhere_trackmetadatas.',
      'page callback' => 'system_admin_menu_block_page',
      'access arguments' => array('access administration pages'),
      'file path' => drupal_get_path('module', 'system'),
      'file' => 'system.admin.inc',
    );

    // Change the overview menu type for the list of thumbwhere_trackmetadatas.
    $items[$this->path]['type'] = MENU_LOCAL_TASK;

    // Change the add page menu to multiple types of entities
    $items[$this->path . '/add'] = array(
      'title' => 'Add a thumbwhere_trackmetadata',
      'description' => 'Add a new thumbwhere_trackmetadata',
      'page callback'  => 'thumbwhere_trackmetadata_add_page',
      'access callback'  => 'thumbwhere_trackmetadata_access',
      'access arguments' => array('edit'),
      'type' => MENU_NORMAL_ITEM,
      'weight' => 20,
      'file' => 'thumbwhere_trackmetadata.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])

    );

    $items[$this->path . '/add/' . 'thumbwhere_trackmetadata'] = array(
      'title' => 'Add ' . 'ThumbWhereTrackMetadata',
      'page callback' => 'thumbwhere_trackmetadata_form_wrapper',
      'page arguments' => array(thumbwhere_trackmetadata_create(array('type' => 'thumbwhere_trackmetadata'))),
      'access callback' => 'thumbwhere_trackmetadata_access',
      'access arguments' => array('edit', 'edit ' . 'thumbwhere_trackmetadata'),
      'file' => 'thumbwhere_trackmetadata.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );

    // Loading and editing thumbwhere_trackmetadata entities
    $items[$this->path . '/thumbwhere_trackmetadata/' . $wildcard] = array(
      'page callback' => 'thumbwhere_trackmetadata_form_wrapper',
      'page arguments' => array($id_count + 1),
      'access callback' => 'thumbwhere_trackmetadata_access',
      'access arguments' => array('edit', $id_count + 1),
      'weight' => 0,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
      'file' => 'thumbwhere_trackmetadata.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );
    $items[$this->path . '/thumbwhere_trackmetadata/' . $wildcard . '/edit'] = array(
      'title' => 'Edit',
      'type' => MENU_DEFAULT_LOCAL_TASK,
      'weight' => -10,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
    );

    $items[$this->path . '/thumbwhere_trackmetadata/' . $wildcard . '/delete'] = array(
      'title' => 'Delete',
      'page callback' => 'thumbwhere_trackmetadata_delete_form_wrapper',
      'page arguments' => array($id_count + 1),
      'access callback' => 'thumbwhere_trackmetadata_access',
      'access arguments' => array('edit', $id_count + 1),
      'type' => MENU_LOCAL_TASK,
      'context' => MENU_CONTEXT_INLINE,
      'weight' => 10,
      'file' => 'thumbwhere_trackmetadata.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );

    // Menu item for viewing thumbwhere_trackmetadatas
    $items['thumbwhere_trackmetadata/' . $wildcard] = array(
      //'title' => 'Title',
      'title callback' => 'thumbwhere_trackmetadata_page_title',
      'title arguments' => array(1),
      'page callback' => 'thumbwhere_trackmetadata_page_view',
      'page arguments' => array(1),
      'access callback' => 'thumbwhere_trackmetadata_access',
      'access arguments' => array('view', 1),
      'type' => MENU_CALLBACK,
    );
    return $items;
  }


  /**
   * Create the markup for the add ThumbWhereTrackMetadata Entities page within the class
   * so it can easily be extended/overriden.
   */
  public function addPage() {
    $item = menu_get_item();
    $content = system_admin_menu_block($item);

    if (count($content) == 1) {
      $item = array_shift($content);
      drupal_goto($item['href']);
    }

    return theme('thumbwhere_trackmetadata_add_list', array('content' => $content));
  }

}


/**
 * Form callback wrapper: create or edit a thumbwhere_trackmetadata.
 *
 * @param $thumbwhere_trackmetadata
 *   The thumbwhere_trackmetadata object being edited by this form.
 *
 * @see thumbwhere_trackmetadata_edit_form()
 */
function thumbwhere_trackmetadata_form_wrapper($thumbwhere_trackmetadata) {
  // Add the breadcrumb for the form's location.
  thumbwhere_trackmetadata_set_breadcrumb();
  return drupal_get_form('thumbwhere_trackmetadata_edit_form', $thumbwhere_trackmetadata);
}


/**
 * Form callback wrapper: delete a thumbwhere_trackmetadata.
 *
 * @param $thumbwhere_trackmetadata
 *   The thumbwhere_trackmetadata object being edited by this form.
 *
 * @see thumbwhere_trackmetadata_edit_form()
 */
function thumbwhere_trackmetadata_delete_form_wrapper($thumbwhere_trackmetadata) {
  // Add the breadcrumb for the form's location.
  //thumbwhere_trackmetadata_set_breadcrumb();
  return drupal_get_form('thumbwhere_trackmetadata_delete_form', $thumbwhere_trackmetadata);
}


/**
 * Form callback: create or edit a thumbwhere_trackmetadata.
 *
 * @param $thumbwhere_trackmetadata
 *   The thumbwhere_trackmetadata object to edit or for a create form an empty thumbwhere_trackmetadata object
 *     with only a thumbwhere_trackmetadata type defined.
 */
function thumbwhere_trackmetadata_edit_form($form, &$form_state, $thumbwhere_trackmetadata) {




  $form['data']['#tree'] = TRUE;

  /*
  $form['data']['sample_data'] = array(
    '#type' => 'checkbox',
    '#title' => t('An interesting thumbwhere_trackmetadata switch'),
    '#default_value' => isset($thumbwhere_trackmetadata->data['sample_data']) ? $thumbwhere_trackmetadata->data['sample_data'] : 1,
  );
  */


  // Add the field related form elements.
  $form_state['thumbwhere_trackmetadata'] = $thumbwhere_trackmetadata;
  field_attach_form('thumbwhere_trackmetadata', $thumbwhere_trackmetadata, $form, $form_state);

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
    '#value' => t('Save thumbwhere_trackmetadata'),
    '#submit' => $submit + array('thumbwhere_trackmetadata_edit_form_submit'),
  );

  // Do we show the delete button?
  if (!empty($thumbwhere_trackmetadata->pk_trackmetadata)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete thumbwhere_trackmetadata'),
      '#suffix' => l(t('Cancel'), 'admin/content/thumbwhere_trackmetadatas'),
      '#submit' => $submit + array('thumbwhere_trackmetadata_form_submit_delete'),
      '#weight' => 45,
    );
  }

  // We append the validate handler to #validate in case a form callback_wrapper
  // is used to add validate handlers earlier.
  $form['#validate'][] = 'thumbwhere_trackmetadata_edit_form_validate';
  return $form;
}


/**
 * Form API validate callback for the thumbwhere_trackmetadata form
 */
function thumbwhere_trackmetadata_edit_form_validate(&$form, &$form_state) {
   
  //if (twCanDebug()) debug($form);   
  //if (twCanDebug()) debug($form_state);


  // No validation for pk


              

  //form_set_value( array('#parents' => array('array_key_parent', 'array_key_to_replace')) , $value, $form_state);

   
   
  $thumbwhere_trackmetadata = $form_state['thumbwhere_trackmetadata'];

  // Notify field widgets to validate their data.
  field_attach_form_validate('thumbwhere_trackmetadata', $thumbwhere_trackmetadata, $form, $form_state);
    
    
  
}


/**
 * Form API submit callback for the thumbwhere_trackmetadata form.
 *
 * @todo remove hard-coded link
 */
function thumbwhere_trackmetadata_edit_form_submit(&$form, &$form_state) {

  $thumbwhere_trackmetadata = entity_ui_controller('thumbwhere_trackmetadata')->entityFormSubmitBuildEntity($form, $form_state);
  // Save the thumbwhere_trackmetadata and go back to the list of thumbwhere_trackmetadatas

  // Add in created and changed times.
  if ($thumbwhere_trackmetadata->is_new = isset($thumbwhere_trackmetadata->is_new) ? $thumbwhere_trackmetadata->is_new : 0) {
    $thumbwhere_trackmetadata->created = time();
  }

  $thumbwhere_trackmetadata->changed = time();

  $thumbwhere_trackmetadata->save();
  $form_state['redirect'] = 'admin/content/thumbwhere_trackmetadatas';
}

/**
 * Form API submit callback for the delete button.
 *
 * @todo Remove hard-coded path
 */
function thumbwhere_trackmetadata_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/content/thumbwhere_trackmetadatas/thumbwhere_trackmetadata/' . $form_state['thumbwhere_trackmetadata']->pk_trackmetadata . '/delete';
}





/**
 * Form callback: confirmation form for deleting a thumbwhere_trackmetadata.
 *
 * @param $thumbwhere_trackmetadata
 *   The thumbwhere_trackmetadata to delete
 *
 * @see confirm_form()
 */
function thumbwhere_trackmetadata_delete_form($form, &$form_state, $thumbwhere_trackmetadata) {
  $form_state['thumbwhere_trackmetadata'] = $thumbwhere_trackmetadata;

  $form['#submit'][] = 'thumbwhere_trackmetadata_delete_form_submit';

  $form = confirm_form($form,
    t('Are you sure you want to delete thumbwhere_trackmetadata %name?', array('%name' => $thumbwhere_trackmetadata->pk_trackmetadata)),
    'admin/content/thumbwhere_trackmetadatas/thumbwhere_trackmetadata',
    '<p>' . t('This action cannot be undone.') . '</p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
  );

  return $form;
}

/**
 * Submit callback for thumbwhere_trackmetadata_delete_form
 */
function thumbwhere_trackmetadata_delete_form_submit($form, &$form_state) {
  $thumbwhere_trackmetadata = $form_state['thumbwhere_trackmetadata'];

  thumbwhere_trackmetadata_delete($thumbwhere_trackmetadata);

  drupal_set_message(t('The thumbwhere_trackmetadata %name has been deleted.', array('%name' => $thumbwhere_trackmetadata->pk_trackmetadata)));
  watchdog('thumbwhere_trackmetadata', 'Deleted thumbwhere_trackmetadata %name.', array('%name' => $thumbwhere_trackmetadata->pk_trackmetadata));

  $form_state['redirect'] = 'admin/content/thumbwhere_trackmetadatas';
}



/**
 * Page to add ThumbWhereTrackMetadata Entities.
 *
 * @todo Pass this through a proper theme function
 */
function thumbwhere_trackmetadata_add_page() {
  $controller = entity_ui_controller('thumbwhere_trackmetadata');
  return $controller->addPage();
}


/**
 * Displays the list of available thumbwhere_trackmetadata types for thumbwhere_trackmetadata creation.
 *
 * @ingroup themeable
 */
function theme_thumbwhere_trackmetadata_add_list($variables) {


  //$content = $variables['content'];
  $output = '';
  /*
  if ($content) {
    $output = '<dl class="thumbwhere_trackmetadata-type-list">';
    foreach ($content as $item) {
      $output .= '<dt>' . l($item['title'], $item['href']) . '</dt>';
      $output .= '<dd>' . filter_xss_admin($item['description']) . '</dd>';
    }
    $output .= '</dl>';
  }
  else {
    if (user_access('administer thumbwhere_trackmetadata types')) {
      $output = '<p>' . t('ThumbWhereTrackMetadata Entities cannot be added because you have not created any thumbwhere_trackmetadata types yet. Go to the <a href="@create-thumbwhere_trackmetadata-type">thumbwhere_trackmetadata type creation page</a> to add a new thumbwhere_trackmetadata type.', array('@create-thumbwhere_trackmetadata-type' => url('admin/structure/thumbwhere_trackmetadata_types/add'))) . '</p>';
    }
    else {
      $output = '<p>' . t('No thumbwhere_trackmetadata types have been created yet for you to use.') . '</p>';
    }
  }
  */
  return $output;
}





/**
 * Sets the breadcrumb for administrative thumbwhere_trackmetadata pages.
 */
function thumbwhere_trackmetadata_set_breadcrumb() {
  $breadcrumb = array(
    l(t('Home'), '<front>'),
    l(t('Administration'), 'admin'),
    l(t('TrackMetadata'), 'admin/content'),
    l(t('ThumbWhereTrackMetadatas'), 'admin/content/thumbwhere_trackmetadatas'),
  );

  drupal_set_breadcrumb($breadcrumb);
}


