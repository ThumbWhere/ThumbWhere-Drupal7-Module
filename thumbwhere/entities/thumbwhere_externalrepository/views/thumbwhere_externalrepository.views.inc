<?php

/**
 * @file
 * Providing extra functionality for the ThumbWhereExternalRepository UI via views.
 *
 * NOTE: This file was generated by autogen_model_implementation_drupal.xsl
 *   
 */

/**
 * Implements hook_views_data().
 */
 function thumbwhere_externalrepository_views_data_alter(&$data) {
 	
  /* Add any special formatters for special types */	
 	
 
 	
  $data['thumbwhere_externalrepository']['link_thumbwhere_externalrepository'] = array(
      'field' => array(
          'title' => t('Link'),
          'help' => t('Provide a link to the thumbwhere_externalrepository.'),
          'handler' => 'thumbwhere_externalrepository_handler_link_field',
      ),
  );
  $data['thumbwhere_externalrepository']['edit_thumbwhere_externalrepository'] = array(
      'field' => array(
          'title' => t('Edit Link'),
          'help' => t('Provide a link to the edit form for the thumbwhere_externalrepository.'),
          'handler' => 'thumbwhere_externalrepository_handler_edit_link_field',
      ),
  );
  $data['thumbwhere_externalrepository']['delete_thumbwhere_externalrepository'] = array(
      'field' => array(
          'title' => t('Delete Link'),
          'help' => t('Provide a link to delete the thumbwhere_externalrepository.'),
          'handler' => 'thumbwhere_externalrepository_handler_delete_link_field',
      ),
  );
  // This content of this field are decided based on the menu structure that
  // follows thumbwhere_externalrepositorys/thumbwhere_externalrepository/%thumbwhere_externalrepository_id/op
  $data['thumbwhere_externalrepository']['operations'] = array(
      'field' => array(
          'title' => t('Operations links'),
          'help' => t('Display all operations available for this thumbwhere_externalrepository.'),
          'handler' => 'thumbwhere_externalrepository_handler_thumbwhere_externalrepository_operations_field',
      ),
  );
}

/**
 * Implements hook_views_default_views().
 */
function thumbwhere_externalrepository_views_default_views() {
  $views = array();

  //
  // PASTE EXPORT HERE
  //
  // vvvvvvvvvvvvvvvvv
  //

  $view = new view;
  $view->name = 'thumbwhere_externalrepositorys';
  $view->description = 'A list of all thumbwhere_externalrepositorys';
  $view->tag = 'thumbwhere_externalrepositorys';
  $view->base_table = 'thumbwhere_externalrepository';
  $view->human_name = 'ExternalRepository';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'ExternalRepository';
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
    'pk_externalrepository' => 'pk_externalrepository',
    'fk_externalrepositorytype' => 'fk_externalrepositorytype',
    'fk_host' => 'fk_host',
    'fk_apikey' => 'fk_apikey',
    'url' => 'url',
    'link_thumbwhere_externalrepository' => 'link_thumbwhere_externalrepository',
    'operations' => 'operations',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
      'pk_externalrepository' => array(
          'sortable' => 0,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
      ),
      'fk_externalrepositorytype' => array(
          'sortable' => 0,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
      ),
      'fk_host' => array(
          'sortable' => 0,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
      ),
      'fk_apikey' => array(
          'sortable' => 0,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
      ),
      'url' => array(
          'sortable' => 0,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
      ),
      'link_thumbwhere_externalrepository' => array(
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
  $handler->display->display_options['empty']['area']['content'] = 'No thumbwhere_externalrepositorys have been created yet';
    
    
  /* Field: Bulk operations: ThumbWhereContentIngest */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'thumbwhere_externalrepository';
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
  
    

/* Field: ThumbWhereExternalRepository: pk_externalrepository */
  $handler->display->display_options['fields']['pk_externalrepository']['id'] = 'pk_externalrepository';
  $handler->display->display_options['fields']['pk_externalrepository']['table'] = 'thumbwhere_externalrepository';
  $handler->display->display_options['fields']['pk_externalrepository']['field'] = 'pk_externalrepository';
  $handler->display->display_options['fields']['pk_externalrepository']['label'] = 'pk_externalrepository';
  $handler->display->display_options['fields']['pk_externalrepository']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['pk_externalrepository']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['pk_externalrepository']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['pk_externalrepository']['alter']['external'] = 0;
  $handler->display->display_options['fields']['pk_externalrepository']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['pk_externalrepository']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['pk_externalrepository']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['pk_externalrepository']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['pk_externalrepository']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['pk_externalrepository']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['pk_externalrepository']['alter']['html'] = 0;
  $handler->display->display_options['fields']['pk_externalrepository']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['pk_externalrepository']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['pk_externalrepository']['hide_empty'] = 0;
  $handler->display->display_options['fields']['pk_externalrepository']['empty_zero'] = 0;
  
  /* Field: ThumbWhereExternalRepository: fk_externalrepositorytype */
  $handler->display->display_options['fields']['fk_externalrepositorytype']['id'] = 'fk_externalrepositorytype';
  $handler->display->display_options['fields']['fk_externalrepositorytype']['table'] = 'thumbwhere_externalrepository';
  $handler->display->display_options['fields']['fk_externalrepositorytype']['field'] = 'fk_externalrepositorytype';
  $handler->display->display_options['fields']['fk_externalrepositorytype']['label'] = 'fk_externalrepositorytype';
  $handler->display->display_options['fields']['fk_externalrepositorytype']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['fk_externalrepositorytype']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['fk_externalrepositorytype']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['fk_externalrepositorytype']['alter']['external'] = 0;
  $handler->display->display_options['fields']['fk_externalrepositorytype']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['fk_externalrepositorytype']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['fk_externalrepositorytype']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['fk_externalrepositorytype']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['fk_externalrepositorytype']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['fk_externalrepositorytype']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['fk_externalrepositorytype']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['fk_externalrepositorytype']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['fk_externalrepositorytype']['alter']['html'] = 0;
  $handler->display->display_options['fields']['fk_externalrepositorytype']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['fk_externalrepositorytype']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['fk_externalrepositorytype']['hide_empty'] = 0;
  $handler->display->display_options['fields']['fk_externalrepositorytype']['empty_zero'] = 0;
  $handler->display->display_options['fields']['fk_externalrepositorytype']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['fk_externalrepositorytype']['format_plural'] = 0;
  /* Field: ThumbWhereExternalRepository: fk_host */
  $handler->display->display_options['fields']['fk_host']['id'] = 'fk_host';
  $handler->display->display_options['fields']['fk_host']['table'] = 'thumbwhere_externalrepository';
  $handler->display->display_options['fields']['fk_host']['field'] = 'fk_host';
  $handler->display->display_options['fields']['fk_host']['label'] = 'fk_host';
  $handler->display->display_options['fields']['fk_host']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['fk_host']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['fk_host']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['fk_host']['alter']['external'] = 0;
  $handler->display->display_options['fields']['fk_host']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['fk_host']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['fk_host']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['fk_host']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['fk_host']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['fk_host']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['fk_host']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['fk_host']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['fk_host']['alter']['html'] = 0;
  $handler->display->display_options['fields']['fk_host']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['fk_host']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['fk_host']['hide_empty'] = 0;
  $handler->display->display_options['fields']['fk_host']['empty_zero'] = 0;
  $handler->display->display_options['fields']['fk_host']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['fk_host']['format_plural'] = 0;
  /* Field: ThumbWhereExternalRepository: fk_apikey */
  $handler->display->display_options['fields']['fk_apikey']['id'] = 'fk_apikey';
  $handler->display->display_options['fields']['fk_apikey']['table'] = 'thumbwhere_externalrepository';
  $handler->display->display_options['fields']['fk_apikey']['field'] = 'fk_apikey';
  $handler->display->display_options['fields']['fk_apikey']['label'] = 'fk_apikey';
  $handler->display->display_options['fields']['fk_apikey']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['fk_apikey']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['fk_apikey']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['fk_apikey']['alter']['external'] = 0;
  $handler->display->display_options['fields']['fk_apikey']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['fk_apikey']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['fk_apikey']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['fk_apikey']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['fk_apikey']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['fk_apikey']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['fk_apikey']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['fk_apikey']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['fk_apikey']['alter']['html'] = 0;
  $handler->display->display_options['fields']['fk_apikey']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['fk_apikey']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['fk_apikey']['hide_empty'] = 0;
  $handler->display->display_options['fields']['fk_apikey']['empty_zero'] = 0;
  $handler->display->display_options['fields']['fk_apikey']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['fk_apikey']['format_plural'] = 0;
  /* Field: ThumbWhereExternalRepository: url */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'thumbwhere_externalrepository';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = 'url';
  $handler->display->display_options['fields']['url']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['url']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['url']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['url']['alter']['external'] = 0;
  $handler->display->display_options['fields']['url']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['url']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['url']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['url']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['url']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['url']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['url']['alter']['html'] = 0;
  $handler->display->display_options['fields']['url']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['url']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['url']['hide_empty'] = 0;
  $handler->display->display_options['fields']['url']['empty_zero'] = 0;

    
    
    
  /* Field: ThumbWhereExternalRepository: Link */
  $handler->display->display_options['fields']['link_thumbwhere_externalrepository']['id'] = 'link_thumbwhere_externalrepository';
  $handler->display->display_options['fields']['link_thumbwhere_externalrepository']['table'] = 'thumbwhere_externalrepository';
  $handler->display->display_options['fields']['link_thumbwhere_externalrepository']['field'] = 'link_thumbwhere_externalrepository';
  $handler->display->display_options['fields']['link_thumbwhere_externalrepository']['label'] = 'View';
  $handler->display->display_options['fields']['link_thumbwhere_externalrepository']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_externalrepository']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_externalrepository']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_externalrepository']['alter']['external'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_externalrepository']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_externalrepository']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_externalrepository']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['link_thumbwhere_externalrepository']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['link_thumbwhere_externalrepository']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_externalrepository']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_externalrepository']['alter']['html'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_externalrepository']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['link_thumbwhere_externalrepository']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['link_thumbwhere_externalrepository']['hide_empty'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_externalrepository']['empty_zero'] = 0;


  /* Field: ThumbWhereExternalRepository: Operations links */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'thumbwhere_externalrepository';
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
  
  
  /* Sort criterion: ThumbWhereExternalRepository: Name */
  /*
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'thumbwhere_externalrepository';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  */
  /* Filter criterion: Search Name */
  /*
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'thumbwhere_externalrepository';
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
  $handler = $view->new_display('page', 'Page', 'thumbwhere_externalrepositorys_admin_page');
  $handler->display->display_options['path'] = 'admin/thumbwhere/thumbwhere_externalrepositorys/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'ExternalRepository';
  $handler->display->display_options['tab_options']['description'] = 'Manage thumbwhere_externalrepositorys';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  //
  // ^^^^^^^^^^^^^^^^^
  //
  // PASTE EXPORT HERE
  //

  $translatables['thumbwhere_externalrepositorys'] = array(
      t('Master'),
      t('ExternalRepository'),
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
      t('No thumbwhere_externalrepositorys have been created yet'),
      t('ThumbWhereExternalRepository ID'),
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
