<?php

/**
 * @file
 * Providing extra functionality for the ThumbWhereConsumerMember UI via views.
 *
 * NOTE: This file was generated by autogen_model_implementation_drupal.xsl
 *   
 */

/**
 * Implements hook_views_data().
 */
 function thumbwhere_consumermember_views_data_alter(&$data) {
 	
  /* Add any special formatters for special types */	
 	
 
 	
  $data['thumbwhere_consumermember']['link_thumbwhere_consumermember'] = array(
      'field' => array(
          'title' => t('Link'),
          'help' => t('Provide a link to the thumbwhere_consumermember.'),
          'handler' => 'thumbwhere_consumermember_handler_link_field',
      ),
  );
  $data['thumbwhere_consumermember']['edit_thumbwhere_consumermember'] = array(
      'field' => array(
          'title' => t('Edit Link'),
          'help' => t('Provide a link to the edit form for the thumbwhere_consumermember.'),
          'handler' => 'thumbwhere_consumermember_handler_edit_link_field',
      ),
  );
  $data['thumbwhere_consumermember']['delete_thumbwhere_consumermember'] = array(
      'field' => array(
          'title' => t('Delete Link'),
          'help' => t('Provide a link to delete the thumbwhere_consumermember.'),
          'handler' => 'thumbwhere_consumermember_handler_delete_link_field',
      ),
  );
  // This content of this field are decided based on the menu structure that
  // follows thumbwhere_consumermembers/thumbwhere_consumermember/%thumbwhere_consumermember_id/op
  $data['thumbwhere_consumermember']['operations'] = array(
      'field' => array(
          'title' => t('Operations links'),
          'help' => t('Display all operations available for this thumbwhere_consumermember.'),
          'handler' => 'thumbwhere_consumermember_handler_thumbwhere_consumermember_operations_field',
      ),
  );
}

/**
 * Implements hook_views_default_views().
 */
function thumbwhere_consumermember_views_default_views() {
  $views = array();

  //
  // PASTE EXPORT HERE
  //
  // vvvvvvvvvvvvvvvvv
  //

  $view = new view;
  $view->name = 'thumbwhere_consumermembers';
  $view->description = 'A list of all thumbwhere_consumermembers';
  $view->tag = 'thumbwhere_consumermembers';
  $view->base_table = 'thumbwhere_consumermember';
  $view->human_name = 'ConsumerMember';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'ConsumerMember';
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
    'pk_consumermember' => 'pk_consumermember',
    'fk_consumer' => 'fk_consumer',
    'fk_member' => 'fk_member',
    'admin' => 'admin',
    'link_thumbwhere_consumermember' => 'link_thumbwhere_consumermember',
    'operations' => 'operations',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
      'pk_consumermember' => array(
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
      'fk_member' => array(
          'sortable' => 0,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
      ),
      'admin' => array(
          'sortable' => 0,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
      ),
      'link_thumbwhere_consumermember' => array(
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
  $handler->display->display_options['empty']['area']['content'] = 'No thumbwhere_consumermembers have been created yet';
    
    
  /* Field: Bulk operations: ThumbWhereContentIngest */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'thumbwhere_consumermember';
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
  
    

/* Field: ThumbWhereConsumerMember: pk_consumermember */
  $handler->display->display_options['fields']['pk_consumermember']['id'] = 'pk_consumermember';
  $handler->display->display_options['fields']['pk_consumermember']['table'] = 'thumbwhere_consumermember';
  $handler->display->display_options['fields']['pk_consumermember']['field'] = 'pk_consumermember';
  $handler->display->display_options['fields']['pk_consumermember']['label'] = 'pk_consumermember';
  $handler->display->display_options['fields']['pk_consumermember']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['pk_consumermember']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['pk_consumermember']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['pk_consumermember']['alter']['external'] = 0;
  $handler->display->display_options['fields']['pk_consumermember']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['pk_consumermember']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['pk_consumermember']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['pk_consumermember']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['pk_consumermember']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['pk_consumermember']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['pk_consumermember']['alter']['html'] = 0;
  $handler->display->display_options['fields']['pk_consumermember']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['pk_consumermember']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['pk_consumermember']['hide_empty'] = 0;
  $handler->display->display_options['fields']['pk_consumermember']['empty_zero'] = 0;
  
  /* Field: ThumbWhereConsumerMember: fk_consumer */
  $handler->display->display_options['fields']['fk_consumer']['id'] = 'fk_consumer';
  $handler->display->display_options['fields']['fk_consumer']['table'] = 'thumbwhere_consumermember';
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
  /* Field: ThumbWhereConsumerMember: fk_member */
  $handler->display->display_options['fields']['fk_member']['id'] = 'fk_member';
  $handler->display->display_options['fields']['fk_member']['table'] = 'thumbwhere_consumermember';
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
  /* Field: ThumbWhereConsumerMember: admin */
  $handler->display->display_options['fields']['admin']['id'] = 'admin';
  $handler->display->display_options['fields']['admin']['table'] = 'thumbwhere_consumermember';
  $handler->display->display_options['fields']['admin']['field'] = 'admin';
  $handler->display->display_options['fields']['admin']['label'] = 'admin';
  $handler->display->display_options['fields']['admin']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['admin']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['admin']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['admin']['alter']['external'] = 0;
  $handler->display->display_options['fields']['admin']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['admin']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['admin']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['admin']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['admin']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['admin']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['admin']['alter']['html'] = 0;
  $handler->display->display_options['fields']['admin']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['admin']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['admin']['hide_empty'] = 0;
  $handler->display->display_options['fields']['admin']['empty_zero'] = 0;

    
    
    
  /* Field: ThumbWhereConsumerMember: Link */
  $handler->display->display_options['fields']['link_thumbwhere_consumermember']['id'] = 'link_thumbwhere_consumermember';
  $handler->display->display_options['fields']['link_thumbwhere_consumermember']['table'] = 'thumbwhere_consumermember';
  $handler->display->display_options['fields']['link_thumbwhere_consumermember']['field'] = 'link_thumbwhere_consumermember';
  $handler->display->display_options['fields']['link_thumbwhere_consumermember']['label'] = 'View';
  $handler->display->display_options['fields']['link_thumbwhere_consumermember']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_consumermember']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_consumermember']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_consumermember']['alter']['external'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_consumermember']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_consumermember']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_consumermember']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['link_thumbwhere_consumermember']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['link_thumbwhere_consumermember']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_consumermember']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_consumermember']['alter']['html'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_consumermember']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['link_thumbwhere_consumermember']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['link_thumbwhere_consumermember']['hide_empty'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_consumermember']['empty_zero'] = 0;


  /* Field: ThumbWhereConsumerMember: Operations links */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'thumbwhere_consumermember';
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
  
  
  /* Sort criterion: ThumbWhereConsumerMember: Name */
  /*
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'thumbwhere_consumermember';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  */
  /* Filter criterion: Search Name */
  /*
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'thumbwhere_consumermember';
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
  $handler = $view->new_display('page', 'Page', 'thumbwhere_consumermembers_admin_page');
  $handler->display->display_options['path'] = 'admin/thumbwhere/thumbwhere_consumermembers/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'ConsumerMember';
  $handler->display->display_options['tab_options']['description'] = 'Manage thumbwhere_consumermembers';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  //
  // ^^^^^^^^^^^^^^^^^
  //
  // PASTE EXPORT HERE
  //

  $translatables['thumbwhere_consumermembers'] = array(
      t('Master'),
      t('ConsumerMember'),
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
      t('No thumbwhere_consumermembers have been created yet'),
      t('ThumbWhereConsumerMember ID'),
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
