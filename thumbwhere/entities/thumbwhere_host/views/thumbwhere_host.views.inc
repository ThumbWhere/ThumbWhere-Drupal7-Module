<?php

/**
 * @file
 * Providing extra functionality for the ThumbWhereHost UI via views.
 *
 * NOTE: This file was generated by autogen_model_implementation_drupal.xsl
 *   
 */

/**
 * Implements hook_views_data().
 */
 function thumbwhere_host_views_data_alter(&$data) {
 	
  /* Add any special formatters for special types */	
 	
 
 	
  $data['thumbwhere_host']['link_thumbwhere_host'] = array(
      'field' => array(
          'title' => t('Link'),
          'help' => t('Provide a link to the thumbwhere_host.'),
          'handler' => 'thumbwhere_host_handler_link_field',
      ),
  );
  $data['thumbwhere_host']['edit_thumbwhere_host'] = array(
      'field' => array(
          'title' => t('Edit Link'),
          'help' => t('Provide a link to the edit form for the thumbwhere_host.'),
          'handler' => 'thumbwhere_host_handler_edit_link_field',
      ),
  );
  $data['thumbwhere_host']['delete_thumbwhere_host'] = array(
      'field' => array(
          'title' => t('Delete Link'),
          'help' => t('Provide a link to delete the thumbwhere_host.'),
          'handler' => 'thumbwhere_host_handler_delete_link_field',
      ),
  );
  // This content of this field are decided based on the menu structure that
  // follows thumbwhere_hosts/thumbwhere_host/%thumbwhere_host_id/op
  $data['thumbwhere_host']['operations'] = array(
      'field' => array(
          'title' => t('Operations links'),
          'help' => t('Display all operations available for this thumbwhere_host.'),
          'handler' => 'thumbwhere_host_handler_thumbwhere_host_operations_field',
      ),
  );
}

/**
 * Implements hook_views_default_views().
 */
function thumbwhere_host_views_default_views() {
  $views = array();

  //
  // PASTE EXPORT HERE
  //
  // vvvvvvvvvvvvvvvvv
  //

  $view = new view;
  $view->name = 'thumbwhere_hosts';
  $view->description = 'A list of all thumbwhere_hosts';
  $view->tag = 'thumbwhere_hosts';
  $view->base_table = 'thumbwhere_host';
  $view->human_name = 'Host';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Host';
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
    'pk_host' => 'pk_host',
    'fk_hosttype' => 'fk_hosttype',
    'fk_hostcredential' => 'fk_hostcredential',
    'address' => 'address',
    'online' => 'online',
    'link_thumbwhere_host' => 'link_thumbwhere_host',
    'operations' => 'operations',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
      'pk_host' => array(
          'sortable' => 0,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
      ),
      'fk_hosttype' => array(
          'sortable' => 0,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
      ),
      'fk_hostcredential' => array(
          'sortable' => 0,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
      ),
      'address' => array(
          'sortable' => 0,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
      ),
      'online' => array(
          'sortable' => 0,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
      ),
      'link_thumbwhere_host' => array(
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
  $handler->display->display_options['empty']['area']['content'] = 'No thumbwhere_hosts have been created yet';
    
    
  /* Field: Bulk operations: ThumbWhereContentIngest */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'thumbwhere_host';
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
  
    

/* Field: ThumbWhereHost: pk_host */
  $handler->display->display_options['fields']['pk_host']['id'] = 'pk_host';
  $handler->display->display_options['fields']['pk_host']['table'] = 'thumbwhere_host';
  $handler->display->display_options['fields']['pk_host']['field'] = 'pk_host';
  $handler->display->display_options['fields']['pk_host']['label'] = 'pk_host';
  $handler->display->display_options['fields']['pk_host']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['pk_host']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['pk_host']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['pk_host']['alter']['external'] = 0;
  $handler->display->display_options['fields']['pk_host']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['pk_host']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['pk_host']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['pk_host']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['pk_host']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['pk_host']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['pk_host']['alter']['html'] = 0;
  $handler->display->display_options['fields']['pk_host']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['pk_host']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['pk_host']['hide_empty'] = 0;
  $handler->display->display_options['fields']['pk_host']['empty_zero'] = 0;
  
  /* Field: ThumbWhereHost: fk_hosttype */
  $handler->display->display_options['fields']['fk_hosttype']['id'] = 'fk_hosttype';
  $handler->display->display_options['fields']['fk_hosttype']['table'] = 'thumbwhere_host';
  $handler->display->display_options['fields']['fk_hosttype']['field'] = 'fk_hosttype';
  $handler->display->display_options['fields']['fk_hosttype']['label'] = 'fk_hosttype';
  $handler->display->display_options['fields']['fk_hosttype']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['fk_hosttype']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['fk_hosttype']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['fk_hosttype']['alter']['external'] = 0;
  $handler->display->display_options['fields']['fk_hosttype']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['fk_hosttype']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['fk_hosttype']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['fk_hosttype']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['fk_hosttype']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['fk_hosttype']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['fk_hosttype']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['fk_hosttype']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['fk_hosttype']['alter']['html'] = 0;
  $handler->display->display_options['fields']['fk_hosttype']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['fk_hosttype']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['fk_hosttype']['hide_empty'] = 0;
  $handler->display->display_options['fields']['fk_hosttype']['empty_zero'] = 0;
  $handler->display->display_options['fields']['fk_hosttype']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['fk_hosttype']['format_plural'] = 0;
  /* Field: ThumbWhereHost: fk_hostcredential */
  $handler->display->display_options['fields']['fk_hostcredential']['id'] = 'fk_hostcredential';
  $handler->display->display_options['fields']['fk_hostcredential']['table'] = 'thumbwhere_host';
  $handler->display->display_options['fields']['fk_hostcredential']['field'] = 'fk_hostcredential';
  $handler->display->display_options['fields']['fk_hostcredential']['label'] = 'fk_hostcredential';
  $handler->display->display_options['fields']['fk_hostcredential']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['fk_hostcredential']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['fk_hostcredential']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['fk_hostcredential']['alter']['external'] = 0;
  $handler->display->display_options['fields']['fk_hostcredential']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['fk_hostcredential']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['fk_hostcredential']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['fk_hostcredential']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['fk_hostcredential']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['fk_hostcredential']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['fk_hostcredential']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['fk_hostcredential']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['fk_hostcredential']['alter']['html'] = 0;
  $handler->display->display_options['fields']['fk_hostcredential']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['fk_hostcredential']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['fk_hostcredential']['hide_empty'] = 0;
  $handler->display->display_options['fields']['fk_hostcredential']['empty_zero'] = 0;
  $handler->display->display_options['fields']['fk_hostcredential']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['fk_hostcredential']['format_plural'] = 0;
  /* Field: ThumbWhereHost: address */
  $handler->display->display_options['fields']['address']['id'] = 'address';
  $handler->display->display_options['fields']['address']['table'] = 'thumbwhere_host';
  $handler->display->display_options['fields']['address']['field'] = 'address';
  $handler->display->display_options['fields']['address']['label'] = 'address';
  $handler->display->display_options['fields']['address']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['address']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['address']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['address']['alter']['external'] = 0;
  $handler->display->display_options['fields']['address']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['address']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['address']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['address']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['address']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['address']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['address']['alter']['html'] = 0;
  $handler->display->display_options['fields']['address']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['address']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['address']['hide_empty'] = 0;
  $handler->display->display_options['fields']['address']['empty_zero'] = 0;

  /* Field: ThumbWhereHost: online */
  $handler->display->display_options['fields']['online']['id'] = 'online';
  $handler->display->display_options['fields']['online']['table'] = 'thumbwhere_host';
  $handler->display->display_options['fields']['online']['field'] = 'online';
  $handler->display->display_options['fields']['online']['label'] = 'online';
  $handler->display->display_options['fields']['online']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['online']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['online']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['online']['alter']['external'] = 0;
  $handler->display->display_options['fields']['online']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['online']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['online']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['online']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['online']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['online']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['online']['alter']['html'] = 0;
  $handler->display->display_options['fields']['online']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['online']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['online']['hide_empty'] = 0;
  $handler->display->display_options['fields']['online']['empty_zero'] = 0;

    
    
    
  /* Field: ThumbWhereHost: Link */
  $handler->display->display_options['fields']['link_thumbwhere_host']['id'] = 'link_thumbwhere_host';
  $handler->display->display_options['fields']['link_thumbwhere_host']['table'] = 'thumbwhere_host';
  $handler->display->display_options['fields']['link_thumbwhere_host']['field'] = 'link_thumbwhere_host';
  $handler->display->display_options['fields']['link_thumbwhere_host']['label'] = 'View';
  $handler->display->display_options['fields']['link_thumbwhere_host']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_host']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_host']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_host']['alter']['external'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_host']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_host']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_host']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['link_thumbwhere_host']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['link_thumbwhere_host']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_host']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_host']['alter']['html'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_host']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['link_thumbwhere_host']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['link_thumbwhere_host']['hide_empty'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_host']['empty_zero'] = 0;


  /* Field: ThumbWhereHost: Operations links */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'thumbwhere_host';
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
  
  
  /* Sort criterion: ThumbWhereHost: Name */
  /*
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'thumbwhere_host';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  */
  /* Filter criterion: Search Name */
  /*
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'thumbwhere_host';
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
  $handler = $view->new_display('page', 'Page', 'thumbwhere_hosts_admin_page');
  $handler->display->display_options['path'] = 'admin/thumbwhere/thumbwhere_hosts/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Host';
  $handler->display->display_options['tab_options']['description'] = 'Manage thumbwhere_hosts';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  //
  // ^^^^^^^^^^^^^^^^^
  //
  // PASTE EXPORT HERE
  //

  $translatables['thumbwhere_hosts'] = array(
      t('Master'),
      t('Host'),
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
      t('No thumbwhere_hosts have been created yet'),
      t('ThumbWhereHost ID'),
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
