<?php

/**
 * @file
 * ThumbWhereContentMetadata editing UI.
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
function _thumbwhere_handle_content_metadata_notify_xml($notification) {

  //
  // Get the operation
  //

  if (!isset($notification->attributes()->op)) {
    drupal_add_http_header('Status', '501 unable to fulfull request..');
    $err = 'We were expecting an \'op\', attribute on the \'content_metadata\', element.';
    print($err);
   	watchdog('thumbwhere_contentmetadata', $err ,array(), WATCHDOG_ERROR);
    exit(0);
  }

  $op = $notification->attributes()->op;

  if (twCanDebug()) debug('op');
  if (twCanDebug()) debug($op);

  //
  // Get the context
  //

  if (!isset($notification->attributes()->key)) {
    drupal_add_http_header('Status', '412 unable to fulfull request..');
    $err = 'We were expecting a \'key\', attribute on the \'content_metadata\', element.';
    print($err);
    watchdog('thumbwhere_contentmetadata', $err ,array(), WATCHDOG_ERROR);
    exit(0);
  }

  $context_key =  $notification->attributes()->key;

  //
  // Now based on the operation..
  //

  switch($op)
  {
  
  
      case 'create':
      {
      
        //
        // What resource are we creating?
        //
      
        //
        // Get the id
        //
		
        if (!isset($notification->attributes()->id)) {
          drupal_add_http_header('Status', '412 Unable to fulfull request.');
          $err = 'We were expecting an \'id\', attribute on the \'content_metadata\', element when we are performing an \'update\' notification..';
          print($err);
          watchdog('thumbwhere_contentmetadata', $err ,array(), WATCHDOG_ERROR);
          exit(0);
        }

        $id = intval($notification->attributes()->id);
		

        if (twCanDebug()) debug('id');
        if (twCanDebug()) debug($id);

      
        //
        // Get the fields
        //
          
        $entities = entity_load('thumbwhere_contentmetadata', array($id));

        if (twCanDebug()) debug('$entities');
        if (twCanDebug()) debug($entities);

        if (count($entities) != 0) {
          //drupal_add_http_header('Status', '409 Resource already exists.');
          $err = '\'content_metadata\' resource already exists with an id of \'' . $id . '\'.';
           //print($err);
          watchdog('thumbwhere_contentmetadata', $err ,array(), WATCHDOG_ERROR);
          //exit(0);

          	
          drupal_add_http_header('Content-Type', 'text/xml');
          print('<response>');
          print('<content_metadata op="' . $op . '" id="' . $id . '" >');
          print('<status>success</status>');
          print('</content_metadata>');
          print('</response>');
          exit(0);          	
          
        }

        // Getting a reference to the entity we asked for
        $entityfields = array();

        //
        // We are only updating what has been passed through.
        // No test for missing values.
        // TODO: Validate incoming values.
        //


        $entityfields['pk_contentmetadata'] = $id;	

        if (isset($notification->contentgenre)) {
          $entityfields['fk_contentgenre'] = intval($notification->contentgenre);
        }

        if (isset($notification->contentclassification)) {
          $entityfields['fk_contentclassification'] = intval($notification->contentclassification);
        }

        if (isset($notification->description)) {
          $entityfields['description'] = (string)($notification->description);
        }

        if (isset($notification->comment)) {
          $entityfields['comment'] = (string)($notification->comment);
        }

        if (isset($notification->year)) {
          $entityfields['year'] = (string)($notification->year);
        }

        if (isset($notification->compilation)) {
          if ((string)($notification->compilation) == 'true') {
            $entityfields['compilation'] = '1';
          }
          else {
            $entityfields['compilation'] = '0';
          }
        }

        if (isset($notification->advisory)) {
          $entityfields['advisory'] = (string)($notification->advisory);
        }

        if (!isset($notification->attributes()->key)) {
          if (twCanDebug()) debug('$entities');
          if (twCanDebug()) debug($entities);
        }

        // We are being notified, so we do not want to ship this out again as a notification...
        // Finally write the entity.
        $entity = entity_create('thumbwhere_contentmetadata', $entityfields);
        $entity->do_not_propagate = TRUE;
        $entity->save();

        //
        // Send the final response
        //

        drupal_add_http_header('Content-Type', 'text/xml');
        print('<response>');
        print('<content_metadata op="' . $op . '" id="' . $id . '" >');
        print('<status>success</status>');
        print('</content_metadata>');
        print('</response>');
        exit(0);			
		
      
      }
  
  
    case 'update':
      {
        //
        // What resource are we updating?
        //
      
        //
        // Get the id
        //
		
        if (!isset($notification->attributes()->id)) {
          drupal_add_http_header('Status', '412 Unable to fulfull request.');
          $err = 'We were expecting an \'id\', attribute on the \'content_metadata\', element when we are performing an \'update\' notification..';
          print($err);
          watchdog('thumbwhere_contentmetadata', $err ,array(), WATCHDOG_ERROR);
          exit(0);
        }

        $id = intval($notification->attributes()->id);
		

        if (twCanDebug()) debug('id');
        if (twCanDebug()) debug($id);

      
        //
        // Get the fields
        //
          
        $entities = entity_load('thumbwhere_contentmetadata', array($id));

        if (twCanDebug()) debug('$entities');
        if (twCanDebug()) debug($entities);

        if (count($entities) == 0) {
          //drupal_add_http_header('Status', '409 No such resource exists.');
          $err = 'No such \'content_metadata\' resource exists with an id of \'' . $id . '\'.';
          //print($err);
          watchdog('thumbwhere_contentmetadata',$err,array(), WATCHDOG_ERROR);
          //exit(0);

////////////////////////////////////////////////////////////////////////
//
// ... for now we will just create the local copy
//
          watchdog('thumbwhere_contentmetadata','creating local version of missing entity',array(), WATCHDOG_ERROR);

        //
        // What resource are we creating?
        //
      
        //
        // Get the id
        //
		
        if (!isset($notification->attributes()->id)) {
          drupal_add_http_header('Status', '412 Unable to fulfull request.');
          $err = 'We were expecting an \'id\', attribute on the \'content_metadata\', element when we are performing an \'update\' notification..';
          print($err);
          watchdog('thumbwhere_contentmetadata', $err ,array(), WATCHDOG_ERROR);
          exit(0);
        }

        $id = intval($notification->attributes()->id);
		

        if (twCanDebug()) debug('id');
        if (twCanDebug()) debug($id);

      
        //
        // Get the fields
        //
          
        $entities = entity_load('thumbwhere_contentmetadata', array($id));

        if (twCanDebug()) debug('$entities');
        if (twCanDebug()) debug($entities);

        if (count($entities) != 0) {
          //drupal_add_http_header('Status', '409 Resource already exists.');
          $err = '\'content_metadata\' resource already exists with an id of \'' . $id . '\'.';
           //print($err);
          watchdog('thumbwhere_contentmetadata', $err ,array(), WATCHDOG_ERROR);
          //exit(0);

          	
          drupal_add_http_header('Content-Type', 'text/xml');
          print('<response>');
          print('<content_metadata op="' . $op . '" id="' . $id . '" >');
          print('<status>success</status>');
          print('</content_metadata>');
          print('</response>');
          exit(0);          	
          
        }

        // Getting a reference to the entity we asked for
        $entityfields = array();

        //
        // We are only updating what has been passed through.
        // No test for missing values.
        // TODO: Validate incoming values.
        //


        $entityfields['pk_contentmetadata'] = $id;	

        if (isset($notification->contentgenre)) {
          $entityfields['fk_contentgenre'] = intval($notification->contentgenre);
        }

        if (isset($notification->contentclassification)) {
          $entityfields['fk_contentclassification'] = intval($notification->contentclassification);
        }

        if (isset($notification->description)) {
          $entityfields['description'] = (string)($notification->description);
        }

        if (isset($notification->comment)) {
          $entityfields['comment'] = (string)($notification->comment);
        }

        if (isset($notification->year)) {
          $entityfields['year'] = (string)($notification->year);
        }

        if (isset($notification->compilation)) {
          if ((string)($notification->compilation) == 'true') {
            $entityfields['compilation'] = '1';
          }
          else {
            $entityfields['compilation'] = '0';
          }
        }

        if (isset($notification->advisory)) {
          $entityfields['advisory'] = (string)($notification->advisory);
        }

        if (!isset($notification->attributes()->key)) {
          if (twCanDebug()) debug('$entities');
          if (twCanDebug()) debug($entities);
        }

        // We are being notified, so we do not want to ship this out again as a notification...
        // Finally write the entity.
        $entity = entity_create('thumbwhere_contentmetadata', $entityfields);
        $entity->do_not_propagate = TRUE;
        $entity->save();

        //
        // Send the final response
        //

        drupal_add_http_header('Content-Type', 'text/xml');
        print('<response>');
        print('<content_metadata op="' . $op . '" id="' . $id . '" >');
        print('<status>success</status>');
        print('</content_metadata>');
        print('</response>');
        exit(0);			
		
//
//
//
////////////////////////////////////////////////////////////////////////
        }

        // Getting a reference to the entity we asked for
        $entity = $entities[$id];

        //
        // We are only updating what has been passed through.
        // No test for missing values.
        // TODO: Validate incoming values.
        //


        if (isset($notification->contentgenre)) {
          $entity->fk_contentgenre = intval($notification->contentgenre);
        }

        if (isset($notification->contentclassification)) {
          $entity->fk_contentclassification = intval($notification->contentclassification);
        }

        if (isset($notification->description)) {
          $entity->description = (string)($notification->description);
        }

        if (isset($notification->comment)) {
          $entity->comment = (string)($notification->comment);
        }

        if (isset($notification->year)) {
          $entity->year = (string)($notification->year);
        }

        if (isset($notification->compilation)) {
          if ((string)($notification->compilation) == 'true') {
            $entity->compilation = '1';
          }
          else {
            $entity->compilation = '0';
          }
        }

        if (isset($notification->advisory)) {
          $entity->advisory = (string)($notification->advisory);
        }

        if (!isset($notification->attributes()->key)) {
          if (twCanDebug()) debug('$entities');
          if (twCanDebug()) debug($entities);
        }

        // We are being notified, so we do not want to ship this out again as a notification...
        $entity->do_not_propagate = TRUE;

        // Finally write the entity.
        entity_save('thumbwhere_contentmetadata', $entity);

        //
        // Send the final response
        //

        drupal_add_http_header('Content-Type', 'text/xml');
        print('<response>');
        print('<content_metadata op="' . $op . '" id="' . $id . '" >');
        print('<status>success</status>');
        print('</content_metadata>');
        print('</response>');
        exit(0);
      }
      
      

    default:
      {
        drupal_add_http_header('Status', '501 Unable to fulfull request..');
        print('We don\'t handle the \'' . $op . '\', notification operation on the \'content_metadata\', element.');
        exit(0);

      }
  }
}



/**
 * Menu callback: React to a notifications for ContentIngest.
 */
function _thumbwhere_content_metadata_notify() {

  if (variable_get('thumbwhere_api_log_debug', 0) == 1) {
    watchdog('thumbwhere_content_metadata', 'incoming notification.');
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
          if ($arg_list[0] == 'content_metadata') {

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
             *      'content_metadata' =>
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
            if (!isset($post_xml->content_metadata)) {
              drupal_add_http_header('Status', '404 not found.');
              print('We were expecting a \'content_metadata\', element in the action payload.');
              exit(0);
            }

            // Handle the incoming notification for content ingest
            _thumbwhere_handle_content_metadata_notify_xml($post_xml->content_metadata);

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
 * ContentMetadata UI controller.
 */
class ThumbWhereContentMetadataUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults. Main reason for doing this is that
   * parent class hook_menu() is optimized for entity type administration.
   */
  public function hook_menu() {

    $items = array();
    
    // Add a notification page...
    $items['thumbwhere/content_metadata/notify'] = array(
        'title' => 'Notifications Callback for "ContentMetadata" Entity',
        'page callback' => '_thumbwhere_content_metadata_notify',
        'access arguments' => array(
            'send thumbwhere contentmetadata notifications'
        ),
        'file' => 'thumbwhere_contentmetadata.admin.inc',
        'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );    
    
    $id_count = count(explode('/', $this->path));
    $wildcard = isset($this->entityInfo['admin ui']['menu wildcard']) ? $this->entityInfo['admin ui']['menu wildcard'] : '%' . $this->entityType;

    $items[$this->path] = array(
      'title' => 'ContentMetadata',
      'description' => 'Add edit and update thumbwhere_contentmetadatas.',
      'page callback' => 'system_admin_menu_block_page',
      'access arguments' => array('access administration pages'),
      'file path' => drupal_get_path('module', 'system'),
      'file' => 'system.admin.inc',
    );

    // Change the overview menu type for the list of thumbwhere_contentmetadatas.
    $items[$this->path]['type'] = MENU_LOCAL_TASK;

    // Change the add page menu to multiple types of entities
    $items[$this->path . '/add'] = array(
      //'title' => 'Add a ContentMetadata',
      'title' => 'Add',
      'description' => 'Add a new ContentMetadata',
      'page callback' => 'thumbwhere_contentmetadata_form_wrapper',
      'page arguments' => array(thumbwhere_contentmetadata_create(array('type' => 'thumbwhere_contentmetadata'))),
      'access callback' => 'thumbwhere_contentmetadata_access',
      'access arguments' => array('edit', 'edit ' . 'thumbwhere_contentmetadata'),
      'file' => 'thumbwhere_contentmetadata.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );


/*
    // Change the add page menu to multiple types of entities
    $items[$this->path . '/add'] = array(
      //'title' => 'Add a ContentMetadata',
      'title' => 'Add',
	  'description' => 'Add a new ContentMetadata',
      'page callback'  => 'thumbwhere_contentmetadata_add_page',
      'access callback'  => 'thumbwhere_contentmetadata_access',
      'access arguments' => array('edit'),
      'type' => MENU_NORMAL_ITEM,
      'weight' => 20,
      'file' => 'thumbwhere_contentmetadata.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])

    );
*/    
/*
    $items[$this->path . '/add/' . 'thumbwhere_contentmetadata'] = array(
      'title' => 'Add ' . 'ThumbWhereContentMetadata',
      'page callback' => 'thumbwhere_contentmetadata_form_wrapper',
      'page arguments' => array(thumbwhere_contentmetadata_create(array('type' => 'thumbwhere_contentmetadata'))),
      'access callback' => 'thumbwhere_contentmetadata_access',
      'access arguments' => array('edit', 'edit ' . 'thumbwhere_contentmetadata'),
      'file' => 'thumbwhere_contentmetadata.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );
*/
    // Loading and editing thumbwhere_contentmetadata entities
    $items[$this->path . '/thumbwhere_contentmetadata/' . $wildcard] = array(
      'page callback' => 'thumbwhere_contentmetadata_form_wrapper',
      'page arguments' => array($id_count + 1),
      'access callback' => 'thumbwhere_contentmetadata_access',
      'access arguments' => array('edit', $id_count + 1),
      'weight' => 0,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
      'file' => 'thumbwhere_contentmetadata.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );
    $items[$this->path . '/thumbwhere_contentmetadata/' . $wildcard . '/edit'] = array(
      'title' => 'Edit',
      'type' => MENU_DEFAULT_LOCAL_TASK,
      'weight' => -10,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
    );

    $items[$this->path . '/thumbwhere_contentmetadata/' . $wildcard . '/delete'] = array(
      'title' => 'Delete',
      'page callback' => 'thumbwhere_contentmetadata_delete_form_wrapper',
      'page arguments' => array($id_count + 1),
      'access callback' => 'thumbwhere_contentmetadata_access',
      'access arguments' => array('edit', $id_count + 1),
      'type' => MENU_LOCAL_TASK,
      'context' => MENU_CONTEXT_INLINE,
      'weight' => 10,
      'file' => 'thumbwhere_contentmetadata.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );

    // Menu item for viewing thumbwhere_contentmetadatas
    $items['thumbwhere_contentmetadata/' . $wildcard] = array(
      //'title' => 'Title',
      'title callback' => 'thumbwhere_contentmetadata_page_title',
      'title arguments' => array(1),
      'page callback' => 'thumbwhere_contentmetadata_page_view',
      'page arguments' => array(1),
      'access callback' => 'thumbwhere_contentmetadata_access',
      'access arguments' => array('view', 1),
      'type' => MENU_CALLBACK,
    );
    return $items;
  }


  /**
   * Create the markup for the add ThumbWhereContentMetadata Entities page within the class
   * so it can easily be extended/overriden.
   */
  public function addPage() {
    $item = menu_get_item();
    $content = system_admin_menu_block($item);

    if (count($content) == 1) {
      $item = array_shift($content);
      drupal_goto($item['href']);
    }

    return theme('thumbwhere_contentmetadata_add_list', array('content' => $content));
  }

}


/**
 * Form callback wrapper: create or edit a thumbwhere_contentmetadata.
 *
 * @param $thumbwhere_contentmetadata
 *   The thumbwhere_contentmetadata object being edited by this form.
 *
 * @see thumbwhere_contentmetadata_edit_form()
 */
function thumbwhere_contentmetadata_form_wrapper($thumbwhere_contentmetadata) {
  // Add the breadcrumb for the form's location.
  thumbwhere_contentmetadata_set_breadcrumb();
  return drupal_get_form('thumbwhere_contentmetadata_edit_form', $thumbwhere_contentmetadata);
}


/**
 * Form callback wrapper: delete a thumbwhere_contentmetadata.
 *
 * @param $thumbwhere_contentmetadata
 *   The thumbwhere_contentmetadata object being edited by this form.
 *
 * @see thumbwhere_contentmetadata_edit_form()
 */
function thumbwhere_contentmetadata_delete_form_wrapper($thumbwhere_contentmetadata) {
  // Add the breadcrumb for the form's location.
  //thumbwhere_contentmetadata_set_breadcrumb();
  return drupal_get_form('thumbwhere_contentmetadata_delete_form', $thumbwhere_contentmetadata);
}


/**
 * Form callback: create or edit a thumbwhere_contentmetadata.
 *
 * @param $thumbwhere_contentmetadata
 *   The thumbwhere_contentmetadata object to edit or for a create form an empty thumbwhere_contentmetadata object
 *     with only a thumbwhere_contentmetadata type defined.
 */
function thumbwhere_contentmetadata_edit_form($form, &$form_state, $thumbwhere_contentmetadata) {

  // Add the default field elements.
  $form['fk_contentgenre'] = array(
    '#type' => 'textfield',
    '#title' => t('ThumbWhereContentMetadata fk_contentgenre'),
    '#default_value' => isset($thumbwhere_contentmetadata->fk_contentgenre) ? $thumbwhere_contentmetadata->fk_contentgenre : '',
    //'#maxlength' => 255,
   /// '#required' => TRUE,
    '#weight' => -5,
    '#autocomplete_path' => 'entity-autocomplete/thumbwhere_contentgenre',
  );
  // Add the default field elements.
  $form['fk_contentclassification'] = array(
    '#type' => 'textfield',
    '#title' => t('ThumbWhereContentMetadata fk_contentclassification'),
    '#default_value' => isset($thumbwhere_contentmetadata->fk_contentclassification) ? $thumbwhere_contentmetadata->fk_contentclassification : '',
    //'#maxlength' => 255,
   /// '#required' => TRUE,
    '#weight' => -5,
    '#autocomplete_path' => 'entity-autocomplete/thumbwhere_contentclassification',
  );
  // Add the default field elements.
    $form['description'] = array(
    '#type' => 'textarea',
    '#title' => t('ThumbWhereContentMetadata description'),

    // '#maxlength' => 255,
   // '#required' => TRUE,
    '#weight' => -5,
  );
  // Add the default field elements.
    $form['comment'] = array(
    '#type' => 'textarea',
    '#title' => t('ThumbWhereContentMetadata comment'),

    // '#maxlength' => 255,
   // '#required' => TRUE,
    '#weight' => -5,
  );
  // Add the default field elements.
    $form['year'] = array(
    '#type' => 'textfield',
    '#title' => t('ThumbWhereContentMetadata year'),

    // '#maxlength' => 255,
   // '#required' => TRUE,
    '#weight' => -5,
  );
  // Add the default field elements.
    $form['compilation'] = array(
    '#type' => 'checkbox',
    '#title' => t('ThumbWhereContentMetadata compilation'),

    // '#maxlength' => 255,
   // '#required' => TRUE,
    '#weight' => -5,
  );
  // Add the default field elements.
    $form['advisory'] = array(
    '#type' => 'textfield',
    '#title' => t('ThumbWhereContentMetadata advisory'),
    '#default_value' => isset($thumbwhere_contentmetadata->advisory) ? $thumbwhere_contentmetadata->advisory : 'false',
    // '#maxlength' => 255,
   // '#required' => TRUE,
    '#weight' => -5,
  );



  $form['data']['#tree'] = TRUE;

  /*
  $form['data']['sample_data'] = array(
    '#type' => 'checkbox',
    '#title' => t('An interesting thumbwhere_contentmetadata switch'),
    '#default_value' => isset($thumbwhere_contentmetadata->data['sample_data']) ? $thumbwhere_contentmetadata->data['sample_data'] : 1,
  );
  */


  // Add the field related form elements.
  $form_state['thumbwhere_contentmetadata'] = $thumbwhere_contentmetadata;
  field_attach_form('thumbwhere_contentmetadata', $thumbwhere_contentmetadata, $form, $form_state);

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
    '#value' => t('Save thumbwhere_contentmetadata'),
    '#submit' => $submit + array('thumbwhere_contentmetadata_edit_form_submit'),
  );

  // Do we show the delete button?
  if (!empty($thumbwhere_contentmetadata->pk_contentmetadata)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete thumbwhere_contentmetadata'),
      '#suffix' => l(t('Cancel'), 'admin/thumbwhere/thumbwhere_contentmetadatas'),
      '#submit' => $submit + array('thumbwhere_contentmetadata_form_submit_delete'),
      '#weight' => 45,
    );
  }

  // We append the validate handler to #validate in case a form callback_wrapper
  // is used to add validate handlers earlier.
  $form['#validate'][] = 'thumbwhere_contentmetadata_edit_form_validate';
  return $form;
}


/**
 * Form API validate callback for the thumbwhere_contentmetadata form
 */
function thumbwhere_contentmetadata_edit_form_validate(&$form, &$form_state) {
   
  //if (twCanDebug()) debug($form);   
  //if (twCanDebug()) debug($form_state);


  // No validation for pk


  // Convert fk autocomplete for fk_contentgenre
  $value = $form['fk_contentgenre']['#value'];
  // If we have something, escape the auto-completion encoding.
  if (!empty($value)) { 
    $value = entity_autocomplete_get_id($value);
    form_set_value($form['fk_contentgenre'], $value,$form_state);
  }
  //if (twCanDebug()) debug($form['fk_contentgenre']);
   if (twCanDebug()) debug('fk_contentgenre = ' . $value);
  // Validate fk fk_contentgenre


  // Convert fk autocomplete for fk_contentclassification
  $value = $form['fk_contentclassification']['#value'];
  // If we have something, escape the auto-completion encoding.
  if (!empty($value)) { 
    $value = entity_autocomplete_get_id($value);
    form_set_value($form['fk_contentclassification'], $value,$form_state);
  }
  //if (twCanDebug()) debug($form['fk_contentclassification']);
   if (twCanDebug()) debug('fk_contentclassification = ' . $value);
  // Validate fk fk_contentclassification


  // Validate normaldescription
  $value = $form['description']['#value'];
  // If we have no default value then we don't care much for checking for emptyness.


  // Validate normalcomment
  $value = $form['comment']['#value'];
  // If we have no default value then we don't care much for checking for emptyness.


  // Validate normalyear
  $value = $form['year']['#value'];
  // If we have no default value then we don't care much for checking for emptyness.


  // Validate normalcompilation
  $value = $form['compilation']['#value'];
  // If we have no default value then we don't care much for checking for emptyness.


  // Validate normaladvisory
  $value = $form['advisory']['#value'];
  // If we have no default value then we don't care much for checking for emptyness.


              

  //form_set_value( array('#parents' => array('array_key_parent', 'array_key_to_replace')) , $value, $form_state);

   
   
  $thumbwhere_contentmetadata = $form_state['thumbwhere_contentmetadata'];

  // Notify field widgets to validate their data.
  field_attach_form_validate('thumbwhere_contentmetadata', $thumbwhere_contentmetadata, $form, $form_state);
    
    
  
}


/**
 * Form API submit callback for the thumbwhere_contentmetadata form.
 *
 * @todo remove hard-coded link
 */
function thumbwhere_contentmetadata_edit_form_submit(&$form, &$form_state) {

  $thumbwhere_contentmetadata = entity_ui_controller('thumbwhere_contentmetadata')->entityFormSubmitBuildEntity($form, $form_state);
  // Save the thumbwhere_contentmetadata and go back to the list of thumbwhere_contentmetadatas

  // Add in created and changed times.
  if ($thumbwhere_contentmetadata->is_new = isset($thumbwhere_contentmetadata->is_new) ? $thumbwhere_contentmetadata->is_new : 0) {
    $thumbwhere_contentmetadata->created = time();
  }

  $thumbwhere_contentmetadata->changed = time();

  $thumbwhere_contentmetadata->save();
  $form_state['redirect'] = 'admin/thumbwhere/thumbwhere_contentmetadatas';
}

/**
 * Form API submit callback for the delete button.
 *
 * @todo Remove hard-coded path
 */
function thumbwhere_contentmetadata_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/thumbwhere/thumbwhere_contentmetadatas/thumbwhere_contentmetadata/' . $form_state['thumbwhere_contentmetadata']->pk_contentmetadata . '/delete';
}





/**
 * Form callback: confirmation form for deleting a thumbwhere_contentmetadata.
 *
 * @param $thumbwhere_contentmetadata
 *   The thumbwhere_contentmetadata to delete
 *
 * @see confirm_form()
 */
function thumbwhere_contentmetadata_delete_form($form, &$form_state, $thumbwhere_contentmetadata) {
  $form_state['thumbwhere_contentmetadata'] = $thumbwhere_contentmetadata;

  $form['#submit'][] = 'thumbwhere_contentmetadata_delete_form_submit';

  $form = confirm_form($form,
    t('Are you sure you want to delete thumbwhere_contentmetadata %name?', array('%name' => $thumbwhere_contentmetadata->pk_contentmetadata)),
    'admin/thumbwhere/thumbwhere_contentmetadatas/thumbwhere_contentmetadata',
    '<p>' . t('This action cannot be undone.') . '</p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
  );

  return $form;
}

/**
 * Submit callback for thumbwhere_contentmetadata_delete_form
 */
function thumbwhere_contentmetadata_delete_form_submit($form, &$form_state) {
  $thumbwhere_contentmetadata = $form_state['thumbwhere_contentmetadata'];

  thumbwhere_contentmetadata_delete($thumbwhere_contentmetadata);

  drupal_set_message(t('The thumbwhere_contentmetadata %name has been deleted.', array('%name' => $thumbwhere_contentmetadata->pk_contentmetadata)));
  watchdog('thumbwhere_contentmetadata', 'Deleted thumbwhere_contentmetadata %name.', array('%name' => $thumbwhere_contentmetadata->pk_contentmetadata));

  $form_state['redirect'] = 'admin/thumbwhere/thumbwhere_contentmetadatas';
}



/**
 * Page to add ThumbWhereContentMetadata Entities.
 *
 * @todo Pass this through a proper theme function
 */
function thumbwhere_contentmetadata_add_page() {
  $controller = entity_ui_controller('thumbwhere_contentmetadata');
  return $controller->addPage();
}


/**
 * Displays the list of available thumbwhere_contentmetadata types for thumbwhere_contentmetadata creation.
 *
 * @ingroup themeable
 */
function theme_thumbwhere_contentmetadata_add_list($variables) {


  //$content = $variables['content'];
  $output = '';
  /*
  if ($content) {
    $output = '<dl class="thumbwhere_contentmetadata-type-list">';
    foreach ($content as $item) {
      $output .= '<dt>' . l($item['title'], $item['href']) . '</dt>';
      $output .= '<dd>' . filter_xss_admin($item['description']) . '</dd>';
    }
    $output .= '</dl>';
  }
  else {
    if (user_access('administer thumbwhere_contentmetadata types')) {
      $output = '<p>' . t('ThumbWhereContentMetadata Entities cannot be added because you have not created any thumbwhere_contentmetadata types yet. Go to the <a href="@create-thumbwhere_contentmetadata-type">thumbwhere_contentmetadata type creation page</a> to add a new thumbwhere_contentmetadata type.', array('@create-thumbwhere_contentmetadata-type' => url('admin/structure/thumbwhere_contentmetadata_types/add'))) . '</p>';
    }
    else {
      $output = '<p>' . t('No thumbwhere_contentmetadata types have been created yet for you to use.') . '</p>';
    }
  }
  */
  return $output;
}





/**
 * Sets the breadcrumb for administrative thumbwhere_contentmetadata pages.
 */
function thumbwhere_contentmetadata_set_breadcrumb() {
  $breadcrumb = array(
    l(t('Home'), '<front>'),
    l(t('Administration'), 'admin'),
    l(t('ContentMetadata'), 'admin/content'),
    l(t('ContentMetadata'), 'admin/thumbwhere/thumbwhere_contentmetadatas'),
  );

  drupal_set_breadcrumb($breadcrumb);
}


