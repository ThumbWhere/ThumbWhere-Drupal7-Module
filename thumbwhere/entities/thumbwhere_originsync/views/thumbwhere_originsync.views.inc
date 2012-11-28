<?php

/**
 * @file
 * Providing extra functionality for the ThumbWhereOriginSync UI via views.
 *
 * NOTE: This file was generated by autogen_model_implementation_drupal.xsl
 *   
 */

/**
 * Implements hook_views_data().
 */
 function thumbwhere_originsync_views_data_alter(&$data) {
 	
  /* Add any special formatters for special types */	
 	
 
	
  // Handle type DateTime
  $data['thumbwhere_originsync']['last_sync'] = array(
      'title' => t('originsync'),
      'field' => array(
          'handler' => 'views_handler_field_date',
          'click sortable' => TRUE,
      ),
      //'sort' => array(
      //    'handler' => 'views_handler_sort_date',
      //),
      //'filter' => array(
      //   'handler' => 'views_handler_filter_date',
      //),
  );	


 	
  $data['thumbwhere_originsync']['link_thumbwhere_originsync'] = array(
      'field' => array(
          'title' => t('Link'),
          'help' => t('Provide a link to the thumbwhere_originsync.'),
          'handler' => 'thumbwhere_originsync_handler_link_field',
      ),
  );
  $data['thumbwhere_originsync']['edit_thumbwhere_originsync'] = array(
      'field' => array(
          'title' => t('Edit Link'),
          'help' => t('Provide a link to the edit form for the thumbwhere_originsync.'),
          'handler' => 'thumbwhere_originsync_handler_edit_link_field',
      ),
  );
  $data['thumbwhere_originsync']['delete_thumbwhere_originsync'] = array(
      'field' => array(
          'title' => t('Delete Link'),
          'help' => t('Provide a link to delete the thumbwhere_originsync.'),
          'handler' => 'thumbwhere_originsync_handler_delete_link_field',
      ),
  );
  // This content of this field are decided based on the menu structure that
  // follows thumbwhere_originsyncs/thumbwhere_originsync/%thumbwhere_originsync_id/op
  $data['thumbwhere_originsync']['operations'] = array(
      'field' => array(
          'title' => t('Operations links'),
          'help' => t('Display all operations available for this thumbwhere_originsync.'),
          'handler' => 'thumbwhere_originsync_handler_thumbwhere_originsync_operations_field',
      ),
  );
}

/**
 * Implements hook_views_default_views().
 */
function thumbwhere_originsync_views_default_views() {
  $views = array();

  //
  // PASTE EXPORT HERE
  //
  // vvvvvvvvvvvvvvvvv
  //

  $view = new view;
  $view->name = 'thumbwhere_originsyncs';
  $view->description = 'A list of all thumbwhere_originsyncs';
  $view->tag = 'thumbwhere_originsyncs';
  $view->base_table = 'thumbwhere_originsync';
  $view->human_name = 'OriginSync';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'OriginSync';
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
    'pk_originsync' => 'pk_originsync',
    'fk_origin' => 'fk_origin',
    'resource' => 'resource',
    'last_sync' => 'last_sync',
    'max' => 'max',
    'complete' => 'complete',
    'link_thumbwhere_originsync' => 'link_thumbwhere_originsync',
    'operations' => 'operations',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
      'pk_originsync' => array(
          'sortable' => 0,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
      ),
      'fk_origin' => array(
          'sortable' => 0,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
      ),
      'resource' => array(
          'sortable' => 0,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
      ),
      'last_sync' => array(
          'sortable' => 0,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
      ),
      'max' => array(
          'sortable' => 0,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
      ),
      'complete' => array(
          'sortable' => 0,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
      ),
      'link_thumbwhere_originsync' => array(
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
  $handler->display->display_options['empty']['area']['content'] = 'No thumbwhere_originsyncs have been created yet';
    
    
  /* Field: Bulk operations: ThumbWhereContentIngest */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'thumbwhere_originsync';
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
  
    

/* Field: ThumbWhereOriginSync: pk_originsync */
  $handler->display->display_options['fields']['pk_originsync']['id'] = 'pk_originsync';
  $handler->display->display_options['fields']['pk_originsync']['table'] = 'thumbwhere_originsync';
  $handler->display->display_options['fields']['pk_originsync']['field'] = 'pk_originsync';
  $handler->display->display_options['fields']['pk_originsync']['label'] = 'pk_originsync';
  $handler->display->display_options['fields']['pk_originsync']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['pk_originsync']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['pk_originsync']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['pk_originsync']['alter']['external'] = 0;
  $handler->display->display_options['fields']['pk_originsync']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['pk_originsync']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['pk_originsync']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['pk_originsync']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['pk_originsync']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['pk_originsync']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['pk_originsync']['alter']['html'] = 0;
  $handler->display->display_options['fields']['pk_originsync']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['pk_originsync']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['pk_originsync']['hide_empty'] = 0;
  $handler->display->display_options['fields']['pk_originsync']['empty_zero'] = 0;
  
  /* Field: ThumbWhereOriginSync: fk_origin */
  $handler->display->display_options['fields']['fk_origin']['id'] = 'fk_origin';
  $handler->display->display_options['fields']['fk_origin']['table'] = 'thumbwhere_originsync';
  $handler->display->display_options['fields']['fk_origin']['field'] = 'fk_origin';
  $handler->display->display_options['fields']['fk_origin']['label'] = 'fk_origin';
  $handler->display->display_options['fields']['fk_origin']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['fk_origin']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['fk_origin']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['fk_origin']['alter']['external'] = 0;
  $handler->display->display_options['fields']['fk_origin']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['fk_origin']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['fk_origin']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['fk_origin']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['fk_origin']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['fk_origin']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['fk_origin']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['fk_origin']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['fk_origin']['alter']['html'] = 0;
  $handler->display->display_options['fields']['fk_origin']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['fk_origin']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['fk_origin']['hide_empty'] = 0;
  $handler->display->display_options['fields']['fk_origin']['empty_zero'] = 0;
  $handler->display->display_options['fields']['fk_origin']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['fk_origin']['format_plural'] = 0;
  /* Field: ThumbWhereOriginSync: resource */
  $handler->display->display_options['fields']['resource']['id'] = 'resource';
  $handler->display->display_options['fields']['resource']['table'] = 'thumbwhere_originsync';
  $handler->display->display_options['fields']['resource']['field'] = 'resource';
  $handler->display->display_options['fields']['resource']['label'] = 'resource';
  $handler->display->display_options['fields']['resource']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['resource']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['resource']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['resource']['alter']['external'] = 0;
  $handler->display->display_options['fields']['resource']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['resource']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['resource']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['resource']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['resource']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['resource']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['resource']['alter']['html'] = 0;
  $handler->display->display_options['fields']['resource']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['resource']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['resource']['hide_empty'] = 0;
  $handler->display->display_options['fields']['resource']['empty_zero'] = 0;

  /* Field: ThumbWhereOriginSync: last_sync */
  $handler->display->display_options['fields']['last_sync']['id'] = 'last_sync';
  $handler->display->display_options['fields']['last_sync']['table'] = 'thumbwhere_originsync';
  $handler->display->display_options['fields']['last_sync']['field'] = 'last_sync';
  $handler->display->display_options['fields']['last_sync']['label'] = 'last_sync';
  $handler->display->display_options['fields']['last_sync']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['last_sync']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['last_sync']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['last_sync']['alter']['external'] = 0;
  $handler->display->display_options['fields']['last_sync']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['last_sync']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['last_sync']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['last_sync']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['last_sync']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['last_sync']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['last_sync']['alter']['html'] = 0;
  $handler->display->display_options['fields']['last_sync']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['last_sync']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['last_sync']['hide_empty'] = 0;
  $handler->display->display_options['fields']['last_sync']['empty_zero'] = 0;

  /* Field: ThumbWhereOriginSync: max */
  $handler->display->display_options['fields']['max']['id'] = 'max';
  $handler->display->display_options['fields']['max']['table'] = 'thumbwhere_originsync';
  $handler->display->display_options['fields']['max']['field'] = 'max';
  $handler->display->display_options['fields']['max']['label'] = 'max';
  $handler->display->display_options['fields']['max']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['max']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['max']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['max']['alter']['external'] = 0;
  $handler->display->display_options['fields']['max']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['max']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['max']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['max']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['max']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['max']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['max']['alter']['html'] = 0;
  $handler->display->display_options['fields']['max']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['max']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['max']['hide_empty'] = 0;
  $handler->display->display_options['fields']['max']['empty_zero'] = 0;

  /* Field: ThumbWhereOriginSync: complete */
  $handler->display->display_options['fields']['complete']['id'] = 'complete';
  $handler->display->display_options['fields']['complete']['table'] = 'thumbwhere_originsync';
  $handler->display->display_options['fields']['complete']['field'] = 'complete';
  $handler->display->display_options['fields']['complete']['label'] = 'complete';
  $handler->display->display_options['fields']['complete']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['complete']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['complete']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['complete']['alter']['external'] = 0;
  $handler->display->display_options['fields']['complete']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['complete']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['complete']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['complete']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['complete']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['complete']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['complete']['alter']['html'] = 0;
  $handler->display->display_options['fields']['complete']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['complete']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['complete']['hide_empty'] = 0;
  $handler->display->display_options['fields']['complete']['empty_zero'] = 0;

    
    
    
  /* Field: ThumbWhereOriginSync: Link */
  $handler->display->display_options['fields']['link_thumbwhere_originsync']['id'] = 'link_thumbwhere_originsync';
  $handler->display->display_options['fields']['link_thumbwhere_originsync']['table'] = 'thumbwhere_originsync';
  $handler->display->display_options['fields']['link_thumbwhere_originsync']['field'] = 'link_thumbwhere_originsync';
  $handler->display->display_options['fields']['link_thumbwhere_originsync']['label'] = 'View';
  $handler->display->display_options['fields']['link_thumbwhere_originsync']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_originsync']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_originsync']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_originsync']['alter']['external'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_originsync']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_originsync']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_originsync']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['link_thumbwhere_originsync']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['link_thumbwhere_originsync']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_originsync']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_originsync']['alter']['html'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_originsync']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['link_thumbwhere_originsync']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['link_thumbwhere_originsync']['hide_empty'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_originsync']['empty_zero'] = 0;


  /* Field: ThumbWhereOriginSync: Operations links */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'thumbwhere_originsync';
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
  
  
  /* Sort criterion: ThumbWhereOriginSync: Name */
  /*
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'thumbwhere_originsync';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  */
  /* Filter criterion: Search Name */
  /*
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'thumbwhere_originsync';
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
  $handler = $view->new_display('page', 'Page', 'thumbwhere_originsyncs_admin_page');
  $handler->display->display_options['path'] = 'admin/thumbwhere/thumbwhere_originsyncs/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'OriginSync';
  $handler->display->display_options['tab_options']['description'] = 'Manage thumbwhere_originsyncs';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  //
  // ^^^^^^^^^^^^^^^^^
  //
  // PASTE EXPORT HERE
  //

  $translatables['thumbwhere_originsyncs'] = array(
      t('Master'),
      t('OriginSync'),
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
      t('No thumbwhere_originsyncs have been created yet'),
      t('ThumbWhereOriginSync ID'),
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