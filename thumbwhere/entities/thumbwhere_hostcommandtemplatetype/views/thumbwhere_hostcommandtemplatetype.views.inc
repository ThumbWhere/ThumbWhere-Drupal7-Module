<?php

/**
 * @file
 * Providing extra functionality for the ThumbWhereHostCommandTemplateType UI via views.
 *
 * NOTE: This file was generated by autogen_model_implementation_drupal.xsl
 *   
 */

/**
 * Implements hook_views_data().
 */
 function thumbwhere_hostcommandtemplatetype_views_data_alter(&$data) {
 	
  /* Add any special formatters for special types */	
 	
 
 	
  $data['thumbwhere_hostcommandtemplatetype']['link_thumbwhere_hostcommandtemplatetype'] = array(
      'field' => array(
          'title' => t('Link'),
          'help' => t('Provide a link to the thumbwhere_hostcommandtemplatetype.'),
          'handler' => 'thumbwhere_hostcommandtemplatetype_handler_link_field',
      ),
  );
  $data['thumbwhere_hostcommandtemplatetype']['edit_thumbwhere_hostcommandtemplatetype'] = array(
      'field' => array(
          'title' => t('Edit Link'),
          'help' => t('Provide a link to the edit form for the thumbwhere_hostcommandtemplatetype.'),
          'handler' => 'thumbwhere_hostcommandtemplatetype_handler_edit_link_field',
      ),
  );
  $data['thumbwhere_hostcommandtemplatetype']['delete_thumbwhere_hostcommandtemplatetype'] = array(
      'field' => array(
          'title' => t('Delete Link'),
          'help' => t('Provide a link to delete the thumbwhere_hostcommandtemplatetype.'),
          'handler' => 'thumbwhere_hostcommandtemplatetype_handler_delete_link_field',
      ),
  );
  // This content of this field are decided based on the menu structure that
  // follows thumbwhere_hostcommandtemplatetypes/thumbwhere_hostcommandtemplatetype/%thumbwhere_hostcommandtemplatetype_id/op
  $data['thumbwhere_hostcommandtemplatetype']['operations'] = array(
      'field' => array(
          'title' => t('Operations links'),
          'help' => t('Display all operations available for this thumbwhere_hostcommandtemplatetype.'),
          'handler' => 'thumbwhere_hostcommandtemplatetype_handler_thumbwhere_hostcommandtemplatetype_operations_field',
      ),
  );
}

/**
 * Implements hook_views_default_views().
 */
function thumbwhere_hostcommandtemplatetype_views_default_views() {
  $views = array();

  //
  // PASTE EXPORT HERE
  //
  // vvvvvvvvvvvvvvvvv
  //

  $view = new view;
  $view->name = 'thumbwhere_hostcommandtemplatetypes';
  $view->description = 'A list of all thumbwhere_hostcommandtemplatetypes';
  $view->tag = 'thumbwhere_hostcommandtemplatetypes';
  $view->base_table = 'thumbwhere_hostcommandtemplatetype';
  $view->human_name = 'HostCommandTemplateType';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'HostCommandTemplateType';
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
    'pk_hostcommandtemplatetype' => 'pk_hostcommandtemplatetype',
    'name' => 'name',
    'link_thumbwhere_hostcommandtemplatetype' => 'link_thumbwhere_hostcommandtemplatetype',
    'operations' => 'operations',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
      'pk_hostcommandtemplatetype' => array(
          'sortable' => 0,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
      ),
      'name' => array(
          'sortable' => 0,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
      ),
      'link_thumbwhere_hostcommandtemplatetype' => array(
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
  $handler->display->display_options['empty']['area']['content'] = 'No thumbwhere_hostcommandtemplatetypes have been created yet';
    
    
  /* Field: Bulk operations: ThumbWhereContentIngest */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'thumbwhere_hostcommandtemplatetype';
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
  
    

/* Field: ThumbWhereHostCommandTemplateType: pk_hostcommandtemplatetype */
  $handler->display->display_options['fields']['pk_hostcommandtemplatetype']['id'] = 'pk_hostcommandtemplatetype';
  $handler->display->display_options['fields']['pk_hostcommandtemplatetype']['table'] = 'thumbwhere_hostcommandtemplatetype';
  $handler->display->display_options['fields']['pk_hostcommandtemplatetype']['field'] = 'pk_hostcommandtemplatetype';
  $handler->display->display_options['fields']['pk_hostcommandtemplatetype']['label'] = 'pk_hostcommandtemplatetype';
  $handler->display->display_options['fields']['pk_hostcommandtemplatetype']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['pk_hostcommandtemplatetype']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['pk_hostcommandtemplatetype']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['pk_hostcommandtemplatetype']['alter']['external'] = 0;
  $handler->display->display_options['fields']['pk_hostcommandtemplatetype']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['pk_hostcommandtemplatetype']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['pk_hostcommandtemplatetype']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['pk_hostcommandtemplatetype']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['pk_hostcommandtemplatetype']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['pk_hostcommandtemplatetype']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['pk_hostcommandtemplatetype']['alter']['html'] = 0;
  $handler->display->display_options['fields']['pk_hostcommandtemplatetype']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['pk_hostcommandtemplatetype']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['pk_hostcommandtemplatetype']['hide_empty'] = 0;
  $handler->display->display_options['fields']['pk_hostcommandtemplatetype']['empty_zero'] = 0;
  
  /* Field: ThumbWhereHostCommandTemplateType: name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'thumbwhere_hostcommandtemplatetype';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;

    
    
    
  /* Field: ThumbWhereHostCommandTemplateType: Link */
  $handler->display->display_options['fields']['link_thumbwhere_hostcommandtemplatetype']['id'] = 'link_thumbwhere_hostcommandtemplatetype';
  $handler->display->display_options['fields']['link_thumbwhere_hostcommandtemplatetype']['table'] = 'thumbwhere_hostcommandtemplatetype';
  $handler->display->display_options['fields']['link_thumbwhere_hostcommandtemplatetype']['field'] = 'link_thumbwhere_hostcommandtemplatetype';
  $handler->display->display_options['fields']['link_thumbwhere_hostcommandtemplatetype']['label'] = 'View';
  $handler->display->display_options['fields']['link_thumbwhere_hostcommandtemplatetype']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_hostcommandtemplatetype']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_hostcommandtemplatetype']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_hostcommandtemplatetype']['alter']['external'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_hostcommandtemplatetype']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_hostcommandtemplatetype']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_hostcommandtemplatetype']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['link_thumbwhere_hostcommandtemplatetype']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['link_thumbwhere_hostcommandtemplatetype']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_hostcommandtemplatetype']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_hostcommandtemplatetype']['alter']['html'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_hostcommandtemplatetype']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['link_thumbwhere_hostcommandtemplatetype']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['link_thumbwhere_hostcommandtemplatetype']['hide_empty'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_hostcommandtemplatetype']['empty_zero'] = 0;


  /* Field: ThumbWhereHostCommandTemplateType: Operations links */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'thumbwhere_hostcommandtemplatetype';
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
  
  
  /* Sort criterion: ThumbWhereHostCommandTemplateType: Name */
  /*
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'thumbwhere_hostcommandtemplatetype';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  */
  /* Filter criterion: Search Name */
  /*
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'thumbwhere_hostcommandtemplatetype';
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
  $handler = $view->new_display('page', 'Page', 'thumbwhere_hostcommandtemplatetypes_admin_page');
  $handler->display->display_options['path'] = 'admin/thumbwhere/thumbwhere_hostcommandtemplatetypes/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'HostCommandTemplateType';
  $handler->display->display_options['tab_options']['description'] = 'Manage thumbwhere_hostcommandtemplatetypes';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  //
  // ^^^^^^^^^^^^^^^^^
  //
  // PASTE EXPORT HERE
  //

  $translatables['thumbwhere_hostcommandtemplatetypes'] = array(
      t('Master'),
      t('HostCommandTemplateType'),
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
      t('No thumbwhere_hostcommandtemplatetypes have been created yet'),
      t('ThumbWhereHostCommandTemplateType ID'),
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
