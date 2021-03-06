<?php

/**
 * @file
 * Providing extra functionality for the ThumbWhereActor UI via views.
 *
 * NOTE: This file was generated by autogen_model_implementation_drupal.xsl
 *   
 */

/**
 * Implements hook_views_data().
 */
 function thumbwhere_actor_views_data_alter(&$data) {
 	
  /* Add any special formatters for special types */	
 	
 
 	
  $data['thumbwhere_actor']['link_thumbwhere_actor'] = array(
      'field' => array(
          'title' => t('Link'),
          'help' => t('Provide a link to the thumbwhere_actor.'),
          'handler' => 'thumbwhere_actor_handler_link_field',
      ),
  );
  $data['thumbwhere_actor']['edit_thumbwhere_actor'] = array(
      'field' => array(
          'title' => t('Edit Link'),
          'help' => t('Provide a link to the edit form for the thumbwhere_actor.'),
          'handler' => 'thumbwhere_actor_handler_edit_link_field',
      ),
  );
  $data['thumbwhere_actor']['delete_thumbwhere_actor'] = array(
      'field' => array(
          'title' => t('Delete Link'),
          'help' => t('Provide a link to delete the thumbwhere_actor.'),
          'handler' => 'thumbwhere_actor_handler_delete_link_field',
      ),
  );
  // This content of this field are decided based on the menu structure that
  // follows thumbwhere_actors/thumbwhere_actor/%thumbwhere_actor_id/op
  $data['thumbwhere_actor']['operations'] = array(
      'field' => array(
          'title' => t('Operations links'),
          'help' => t('Display all operations available for this thumbwhere_actor.'),
          'handler' => 'thumbwhere_actor_handler_thumbwhere_actor_operations_field',
      ),
  );
}

/**
 * Implements hook_views_default_views().
 */
function thumbwhere_actor_views_default_views() {
  $views = array();

  //
  // PASTE EXPORT HERE
  //
  // vvvvvvvvvvvvvvvvv
  //

  $view = new view;
  $view->name = 'thumbwhere_actors';
  $view->description = 'A list of all thumbwhere_actors';
  $view->tag = 'thumbwhere_actors';
  $view->base_table = 'thumbwhere_actor';
  $view->human_name = 'Actor';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Actor';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'pk_actor' => 'pk_actor',
    'fk_member' => 'fk_member',
    'fk_identity' => 'fk_identity',
    'fk_producer' => 'fk_producer',
    'fk_consumer' => 'fk_consumer',
    'link_thumbwhere_actor' => 'link_thumbwhere_actor',
    'operations' => 'operations',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
      'pk_actor' => array(
          'sortable' => 0,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
      ),
      'fk_member' => array(
          'sortable' => 0,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
      ),
      'fk_identity' => array(
          'sortable' => 0,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
      ),
      'fk_producer' => array(
          'sortable' => 0,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
      ),
      'fk_consumer' => array(
          'sortable' => 0,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
      ),
      'link_thumbwhere_actor' => array(
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
      ),
      'operations' => array(
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
      ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Empty ';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No thumbwhere_actors have been created yet';
    
    
  /* Field: Bulk operations: ThumbWhereContentIngest */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'thumbwhere_actor';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['external'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['html'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_empty'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['empty_zero'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['operations'] = array(
	  'action::views_bulk_operations_delete_item' => array(
	    'selected' => 1,
	    'use_queue' => 0,
	    'skip_confirmation' => 0,
	    'override_label' => 0,
	    'label' => '',
	  ),
	  'action::system_message_action' => array(
	    'selected' => 0,
	    'use_queue' => 0,
	    'skip_confirmation' => 0,
	    'override_label' => 0,
	    'label' => '',
	  ),
	  'action::views_bulk_operations_script_action' => array(
	    'selected' => 0,
	    'use_queue' => 0,
	    'skip_confirmation' => 0,
	    'override_label' => 0,
	    'label' => '',
	  ),
	  'action::views_bulk_operations_modify_action' => array(
	    'selected' => 0,
	    'use_queue' => 0,
	    'skip_confirmation' => 0,
	    'override_label' => 0,
	    'label' => '',
	    'settings' => array(
	      'show_all_tokens' => 1,
	      'display_values' => array(
	        '_all_' => '_all_',
	      ),
	    ),
	  ),
	  'action::views_bulk_operations_argument_selector_action' => array(
	    'selected' => 0,
	    'skip_confirmation' => 0,
	    'override_label' => 0,
	    'label' => '',
	    'settings' => array(
	      'url' => '',
	    ),
	  ),
	  'action::system_goto_action' => array(
	    'selected' => 0,
	    'use_queue' => 0,
	    'skip_confirmation' => 0,
	    'override_label' => 0,
	    'label' => '',
	  ),
	  'action::system_send_email_action' => array(
	    'selected' => 0,
	    'use_queue' => 0,
	    'skip_confirmation' => 0,
	    'override_label' => 0,
	    'label' => '',
	  ),
	);
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_result'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['merge_single_action'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['force_single'] = 0;
  
    

/* Field: ThumbWhereActor: pk_actor */
  $handler->display->display_options['fields']['pk_actor']['id'] = 'pk_actor';
  $handler->display->display_options['fields']['pk_actor']['table'] = 'thumbwhere_actor';
  $handler->display->display_options['fields']['pk_actor']['field'] = 'pk_actor';
  $handler->display->display_options['fields']['pk_actor']['label'] = 'pk_actor';
  $handler->display->display_options['fields']['pk_actor']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['pk_actor']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['pk_actor']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['pk_actor']['alter']['external'] = 0;
  $handler->display->display_options['fields']['pk_actor']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['pk_actor']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['pk_actor']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['pk_actor']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['pk_actor']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['pk_actor']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['pk_actor']['alter']['html'] = 0;
  $handler->display->display_options['fields']['pk_actor']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['pk_actor']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['pk_actor']['hide_empty'] = 0;
  $handler->display->display_options['fields']['pk_actor']['empty_zero'] = 0;
  
  /* Field: ThumbWhereActor: fk_member */
  $handler->display->display_options['fields']['fk_member']['id'] = 'fk_member';
  $handler->display->display_options['fields']['fk_member']['table'] = 'thumbwhere_actor';
  $handler->display->display_options['fields']['fk_member']['field'] = 'fk_member';
  $handler->display->display_options['fields']['fk_member']['label'] = 'fk_member';
  $handler->display->display_options['fields']['fk_member']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['fk_member']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['fk_member']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['fk_member']['alter']['external'] = 0;
  $handler->display->display_options['fields']['fk_member']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['fk_member']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['fk_member']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['fk_member']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['fk_member']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['fk_member']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['fk_member']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['fk_member']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['fk_member']['alter']['html'] = 0;
  $handler->display->display_options['fields']['fk_member']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['fk_member']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['fk_member']['hide_empty'] = 0;
  $handler->display->display_options['fields']['fk_member']['empty_zero'] = 0;
  $handler->display->display_options['fields']['fk_member']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['fk_member']['format_plural'] = 0;
  /* Field: ThumbWhereActor: fk_identity */
  $handler->display->display_options['fields']['fk_identity']['id'] = 'fk_identity';
  $handler->display->display_options['fields']['fk_identity']['table'] = 'thumbwhere_actor';
  $handler->display->display_options['fields']['fk_identity']['field'] = 'fk_identity';
  $handler->display->display_options['fields']['fk_identity']['label'] = 'fk_identity';
  $handler->display->display_options['fields']['fk_identity']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['fk_identity']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['fk_identity']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['fk_identity']['alter']['external'] = 0;
  $handler->display->display_options['fields']['fk_identity']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['fk_identity']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['fk_identity']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['fk_identity']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['fk_identity']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['fk_identity']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['fk_identity']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['fk_identity']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['fk_identity']['alter']['html'] = 0;
  $handler->display->display_options['fields']['fk_identity']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['fk_identity']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['fk_identity']['hide_empty'] = 0;
  $handler->display->display_options['fields']['fk_identity']['empty_zero'] = 0;
  $handler->display->display_options['fields']['fk_identity']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['fk_identity']['format_plural'] = 0;
  /* Field: ThumbWhereActor: fk_producer */
  $handler->display->display_options['fields']['fk_producer']['id'] = 'fk_producer';
  $handler->display->display_options['fields']['fk_producer']['table'] = 'thumbwhere_actor';
  $handler->display->display_options['fields']['fk_producer']['field'] = 'fk_producer';
  $handler->display->display_options['fields']['fk_producer']['label'] = 'fk_producer';
  $handler->display->display_options['fields']['fk_producer']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['fk_producer']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['fk_producer']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['fk_producer']['alter']['external'] = 0;
  $handler->display->display_options['fields']['fk_producer']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['fk_producer']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['fk_producer']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['fk_producer']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['fk_producer']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['fk_producer']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['fk_producer']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['fk_producer']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['fk_producer']['alter']['html'] = 0;
  $handler->display->display_options['fields']['fk_producer']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['fk_producer']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['fk_producer']['hide_empty'] = 0;
  $handler->display->display_options['fields']['fk_producer']['empty_zero'] = 0;
  $handler->display->display_options['fields']['fk_producer']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['fk_producer']['format_plural'] = 0;
  /* Field: ThumbWhereActor: fk_consumer */
  $handler->display->display_options['fields']['fk_consumer']['id'] = 'fk_consumer';
  $handler->display->display_options['fields']['fk_consumer']['table'] = 'thumbwhere_actor';
  $handler->display->display_options['fields']['fk_consumer']['field'] = 'fk_consumer';
  $handler->display->display_options['fields']['fk_consumer']['label'] = 'fk_consumer';
  $handler->display->display_options['fields']['fk_consumer']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['fk_consumer']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['fk_consumer']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['fk_consumer']['alter']['external'] = 0;
  $handler->display->display_options['fields']['fk_consumer']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['fk_consumer']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['fk_consumer']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['fk_consumer']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['fk_consumer']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['fk_consumer']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['fk_consumer']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['fk_consumer']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['fk_consumer']['alter']['html'] = 0;
  $handler->display->display_options['fields']['fk_consumer']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['fk_consumer']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['fk_consumer']['hide_empty'] = 0;
  $handler->display->display_options['fields']['fk_consumer']['empty_zero'] = 0;
  $handler->display->display_options['fields']['fk_consumer']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['fk_consumer']['format_plural'] = 0;
    
    
    
  /* Field: ThumbWhereActor: Link */
  $handler->display->display_options['fields']['link_thumbwhere_actor']['id'] = 'link_thumbwhere_actor';
  $handler->display->display_options['fields']['link_thumbwhere_actor']['table'] = 'thumbwhere_actor';
  $handler->display->display_options['fields']['link_thumbwhere_actor']['field'] = 'link_thumbwhere_actor';
  $handler->display->display_options['fields']['link_thumbwhere_actor']['label'] = 'View';
  $handler->display->display_options['fields']['link_thumbwhere_actor']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_actor']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_actor']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_actor']['alter']['external'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_actor']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_actor']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_actor']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['link_thumbwhere_actor']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['link_thumbwhere_actor']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_actor']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_actor']['alter']['html'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_actor']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['link_thumbwhere_actor']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['link_thumbwhere_actor']['hide_empty'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_actor']['empty_zero'] = 0;


  /* Field: ThumbWhereActor: Operations links */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'thumbwhere_actor';
  $handler->display->display_options['fields']['operations']['field'] = 'operations';
  $handler->display->display_options['fields']['operations']['label'] = 'operations';
  $handler->display->display_options['fields']['operations']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['external'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['operations']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['operations']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['html'] = 0;
  $handler->display->display_options['fields']['operations']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['operations']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['operations']['hide_empty'] = 0;
  $handler->display->display_options['fields']['operations']['empty_zero'] = 0;
  
  
  /* Sort criterion: ThumbWhereActor: Name */
  /*
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'thumbwhere_actor';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  */
  /* Filter criterion: Search Name */
  /*
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'thumbwhere_actor';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['ui_name'] = 'Search Name';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['name']['expose']['use_operator'] = 1;
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['required'] = 0;
  $handler->display->display_options['filters']['name']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['name']['expose']['multiple'] = FALSE;
  */

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'thumbwhere_actors_admin_page');
  $handler->display->display_options['path'] = 'admin/thumbwhere/thumbwhere_actors/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Actor';
  $handler->display->display_options['tab_options']['description'] = 'Manage thumbwhere_actors';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  //
  // ^^^^^^^^^^^^^^^^^
  //
  // PASTE EXPORT HERE
  //

  $translatables['thumbwhere_actors'] = array(
      t('Master'),
      t('Actor'),
      t('more'),
      t('Apply'),
      t('Reset'),
      t('Sort by'),
      t('Asc'),
      t('Desc'),
      t('Items per page'),
      t('- All -'),
      t('Offset'),
      t('Empty'),
      t('No thumbwhere_actors have been created yet'),
      t('ThumbWhereActor ID'),
      t('.'),
      t(','),
      t('Name'),
      t('View'),
      t('Operations links'),
      t('Page'),
  );
  $views[$view->name] = $view;
  return $views;

}
