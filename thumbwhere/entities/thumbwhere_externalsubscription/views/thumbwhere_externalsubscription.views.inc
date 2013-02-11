<?php

/**
 * @file
 * Providing extra functionality for the ThumbWhereExternalSubscription UI via views.
 *
 * NOTE: This file was generated by autogen_model_implementation_drupal.xsl
 *   
 */

/**
 * Implements hook_views_data().
 */
 function thumbwhere_externalsubscription_views_data_alter(&$data) {
 	
  /* Add any special formatters for special types */	
 	
 
 	
  $data['thumbwhere_externalsubscription']['link_thumbwhere_externalsubscription'] = array(
      'field' => array(
          'title' => t('Link'),
          'help' => t('Provide a link to the thumbwhere_externalsubscription.'),
          'handler' => 'thumbwhere_externalsubscription_handler_link_field',
      ),
  );
  $data['thumbwhere_externalsubscription']['edit_thumbwhere_externalsubscription'] = array(
      'field' => array(
          'title' => t('Edit Link'),
          'help' => t('Provide a link to the edit form for the thumbwhere_externalsubscription.'),
          'handler' => 'thumbwhere_externalsubscription_handler_edit_link_field',
      ),
  );
  $data['thumbwhere_externalsubscription']['delete_thumbwhere_externalsubscription'] = array(
      'field' => array(
          'title' => t('Delete Link'),
          'help' => t('Provide a link to delete the thumbwhere_externalsubscription.'),
          'handler' => 'thumbwhere_externalsubscription_handler_delete_link_field',
      ),
  );
  // This content of this field are decided based on the menu structure that
  // follows thumbwhere_externalsubscriptions/thumbwhere_externalsubscription/%thumbwhere_externalsubscription_id/op
  $data['thumbwhere_externalsubscription']['operations'] = array(
      'field' => array(
          'title' => t('Operations links'),
          'help' => t('Display all operations available for this thumbwhere_externalsubscription.'),
          'handler' => 'thumbwhere_externalsubscription_handler_thumbwhere_externalsubscription_operations_field',
      ),
  );
}

/**
 * Implements hook_views_default_views().
 */
function thumbwhere_externalsubscription_views_default_views() {
  $views = array();

  //
  // PASTE EXPORT HERE
  //
  // vvvvvvvvvvvvvvvvv
  //

  $view = new view;
  $view->name = 'thumbwhere_externalsubscriptions';
  $view->description = 'A list of all thumbwhere_externalsubscriptions';
  $view->tag = 'thumbwhere_externalsubscriptions';
  $view->base_table = 'thumbwhere_externalsubscription';
  $view->human_name = 'ExternalSubscription';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'ExternalSubscription';
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
    'pk_externalsubscription' => 'pk_externalsubscription',
    'fk_externalrepository' => 'fk_externalrepository',
    'fk_repositoryresource' => 'fk_repositoryresource',
    'active' => 'active',
    'link_thumbwhere_externalsubscription' => 'link_thumbwhere_externalsubscription',
    'operations' => 'operations',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
      'pk_externalsubscription' => array(
          'sortable' => 0,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
      ),
      'fk_externalrepository' => array(
          'sortable' => 0,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
      ),
      'fk_repositoryresource' => array(
          'sortable' => 0,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
      ),
      'active' => array(
          'sortable' => 0,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
      ),
      'link_thumbwhere_externalsubscription' => array(
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
  $handler->display->display_options['empty']['area']['content'] = 'No thumbwhere_externalsubscriptions have been created yet';
    
    
  /* Field: Bulk operations: ThumbWhereContentIngest */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'thumbwhere_externalsubscription';
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
  
    

/* Field: ThumbWhereExternalSubscription: pk_externalsubscription */
  $handler->display->display_options['fields']['pk_externalsubscription']['id'] = 'pk_externalsubscription';
  $handler->display->display_options['fields']['pk_externalsubscription']['table'] = 'thumbwhere_externalsubscription';
  $handler->display->display_options['fields']['pk_externalsubscription']['field'] = 'pk_externalsubscription';
  $handler->display->display_options['fields']['pk_externalsubscription']['label'] = 'pk_externalsubscription';
  $handler->display->display_options['fields']['pk_externalsubscription']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['pk_externalsubscription']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['pk_externalsubscription']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['pk_externalsubscription']['alter']['external'] = 0;
  $handler->display->display_options['fields']['pk_externalsubscription']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['pk_externalsubscription']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['pk_externalsubscription']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['pk_externalsubscription']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['pk_externalsubscription']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['pk_externalsubscription']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['pk_externalsubscription']['alter']['html'] = 0;
  $handler->display->display_options['fields']['pk_externalsubscription']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['pk_externalsubscription']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['pk_externalsubscription']['hide_empty'] = 0;
  $handler->display->display_options['fields']['pk_externalsubscription']['empty_zero'] = 0;
  
  /* Field: ThumbWhereExternalSubscription: fk_externalrepository */
  $handler->display->display_options['fields']['fk_externalrepository']['id'] = 'fk_externalrepository';
  $handler->display->display_options['fields']['fk_externalrepository']['table'] = 'thumbwhere_externalsubscription';
  $handler->display->display_options['fields']['fk_externalrepository']['field'] = 'fk_externalrepository';
  $handler->display->display_options['fields']['fk_externalrepository']['label'] = 'fk_externalrepository';
  $handler->display->display_options['fields']['fk_externalrepository']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['fk_externalrepository']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['fk_externalrepository']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['fk_externalrepository']['alter']['external'] = 0;
  $handler->display->display_options['fields']['fk_externalrepository']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['fk_externalrepository']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['fk_externalrepository']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['fk_externalrepository']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['fk_externalrepository']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['fk_externalrepository']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['fk_externalrepository']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['fk_externalrepository']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['fk_externalrepository']['alter']['html'] = 0;
  $handler->display->display_options['fields']['fk_externalrepository']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['fk_externalrepository']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['fk_externalrepository']['hide_empty'] = 0;
  $handler->display->display_options['fields']['fk_externalrepository']['empty_zero'] = 0;
  $handler->display->display_options['fields']['fk_externalrepository']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['fk_externalrepository']['format_plural'] = 0;
  /* Field: ThumbWhereExternalSubscription: fk_repositoryresource */
  $handler->display->display_options['fields']['fk_repositoryresource']['id'] = 'fk_repositoryresource';
  $handler->display->display_options['fields']['fk_repositoryresource']['table'] = 'thumbwhere_externalsubscription';
  $handler->display->display_options['fields']['fk_repositoryresource']['field'] = 'fk_repositoryresource';
  $handler->display->display_options['fields']['fk_repositoryresource']['label'] = 'fk_repositoryresource';
  $handler->display->display_options['fields']['fk_repositoryresource']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['fk_repositoryresource']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['fk_repositoryresource']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['fk_repositoryresource']['alter']['external'] = 0;
  $handler->display->display_options['fields']['fk_repositoryresource']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['fk_repositoryresource']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['fk_repositoryresource']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['fk_repositoryresource']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['fk_repositoryresource']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['fk_repositoryresource']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['fk_repositoryresource']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['fk_repositoryresource']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['fk_repositoryresource']['alter']['html'] = 0;
  $handler->display->display_options['fields']['fk_repositoryresource']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['fk_repositoryresource']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['fk_repositoryresource']['hide_empty'] = 0;
  $handler->display->display_options['fields']['fk_repositoryresource']['empty_zero'] = 0;
  $handler->display->display_options['fields']['fk_repositoryresource']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['fk_repositoryresource']['format_plural'] = 0;
  /* Field: ThumbWhereExternalSubscription: active */
  $handler->display->display_options['fields']['active']['id'] = 'active';
  $handler->display->display_options['fields']['active']['table'] = 'thumbwhere_externalsubscription';
  $handler->display->display_options['fields']['active']['field'] = 'active';
  $handler->display->display_options['fields']['active']['label'] = 'active';
  $handler->display->display_options['fields']['active']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['active']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['active']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['active']['alter']['external'] = 0;
  $handler->display->display_options['fields']['active']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['active']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['active']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['active']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['active']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['active']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['active']['alter']['html'] = 0;
  $handler->display->display_options['fields']['active']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['active']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['active']['hide_empty'] = 0;
  $handler->display->display_options['fields']['active']['empty_zero'] = 0;

    
    
    
  /* Field: ThumbWhereExternalSubscription: Link */
  $handler->display->display_options['fields']['link_thumbwhere_externalsubscription']['id'] = 'link_thumbwhere_externalsubscription';
  $handler->display->display_options['fields']['link_thumbwhere_externalsubscription']['table'] = 'thumbwhere_externalsubscription';
  $handler->display->display_options['fields']['link_thumbwhere_externalsubscription']['field'] = 'link_thumbwhere_externalsubscription';
  $handler->display->display_options['fields']['link_thumbwhere_externalsubscription']['label'] = 'View';
  $handler->display->display_options['fields']['link_thumbwhere_externalsubscription']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_externalsubscription']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_externalsubscription']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_externalsubscription']['alter']['external'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_externalsubscription']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_externalsubscription']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_externalsubscription']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['link_thumbwhere_externalsubscription']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['link_thumbwhere_externalsubscription']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_externalsubscription']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_externalsubscription']['alter']['html'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_externalsubscription']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['link_thumbwhere_externalsubscription']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['link_thumbwhere_externalsubscription']['hide_empty'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_externalsubscription']['empty_zero'] = 0;


  /* Field: ThumbWhereExternalSubscription: Operations links */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'thumbwhere_externalsubscription';
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
  
  
  /* Sort criterion: ThumbWhereExternalSubscription: Name */
  /*
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'thumbwhere_externalsubscription';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  */
  /* Filter criterion: Search Name */
  /*
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'thumbwhere_externalsubscription';
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
  $handler = $view->new_display('page', 'Page', 'thumbwhere_externalsubscriptions_admin_page');
  $handler->display->display_options['path'] = 'admin/thumbwhere/thumbwhere_externalsubscriptions/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'ExternalSubscription';
  $handler->display->display_options['tab_options']['description'] = 'Manage thumbwhere_externalsubscriptions';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  //
  // ^^^^^^^^^^^^^^^^^
  //
  // PASTE EXPORT HERE
  //

  $translatables['thumbwhere_externalsubscriptions'] = array(
      t('Master'),
      t('ExternalSubscription'),
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
      t('No thumbwhere_externalsubscriptions have been created yet'),
      t('ThumbWhereExternalSubscription ID'),
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