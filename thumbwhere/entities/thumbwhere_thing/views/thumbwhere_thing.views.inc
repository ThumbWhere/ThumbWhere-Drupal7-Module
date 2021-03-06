<?php

/**
 * @file
 * Providing extra functionality for the ThumbWhereThing UI via views.
 *
 * NOTE: This file was generated by autogen_model_implementation_drupal.xsl
 *   
 */

/**
 * Implements hook_views_data().
 */
 function thumbwhere_thing_views_data_alter(&$data) {
 	
  /* Add any special formatters for special types */	
 	
 
 	
  $data['thumbwhere_thing']['link_thumbwhere_thing'] = array(
      'field' => array(
          'title' => t('Link'),
          'help' => t('Provide a link to the thumbwhere_thing.'),
          'handler' => 'thumbwhere_thing_handler_link_field',
      ),
  );
  $data['thumbwhere_thing']['edit_thumbwhere_thing'] = array(
      'field' => array(
          'title' => t('Edit Link'),
          'help' => t('Provide a link to the edit form for the thumbwhere_thing.'),
          'handler' => 'thumbwhere_thing_handler_edit_link_field',
      ),
  );
  $data['thumbwhere_thing']['delete_thumbwhere_thing'] = array(
      'field' => array(
          'title' => t('Delete Link'),
          'help' => t('Provide a link to delete the thumbwhere_thing.'),
          'handler' => 'thumbwhere_thing_handler_delete_link_field',
      ),
  );
  // This content of this field are decided based on the menu structure that
  // follows thumbwhere_things/thumbwhere_thing/%thumbwhere_thing_id/op
  $data['thumbwhere_thing']['operations'] = array(
      'field' => array(
          'title' => t('Operations links'),
          'help' => t('Display all operations available for this thumbwhere_thing.'),
          'handler' => 'thumbwhere_thing_handler_thumbwhere_thing_operations_field',
      ),
  );
}

/**
 * Implements hook_views_default_views().
 */
function thumbwhere_thing_views_default_views() {
  $views = array();

  //
  // PASTE EXPORT HERE
  //
  // vvvvvvvvvvvvvvvvv
  //

  $view = new view;
  $view->name = 'thumbwhere_things';
  $view->description = 'A list of all thumbwhere_things';
  $view->tag = 'thumbwhere_things';
  $view->base_table = 'thumbwhere_thing';
  $view->human_name = 'Thing';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Thing';
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
    'pk_thing' => 'pk_thing',
    'fk_mediaitem' => 'fk_mediaitem',
    'fk_content' => 'fk_content',
    'fk_contentcollection' => 'fk_contentcollection',
    'link_thumbwhere_thing' => 'link_thumbwhere_thing',
    'operations' => 'operations',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
      'pk_thing' => array(
          'sortable' => 0,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
      ),
      'fk_mediaitem' => array(
          'sortable' => 0,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
      ),
      'fk_content' => array(
          'sortable' => 0,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
      ),
      'fk_contentcollection' => array(
          'sortable' => 0,
          'default_sort_order' => 'asc',
          'align' => '',
          'separator' => '',
          'empty_column' => 0,
      ),
      'link_thumbwhere_thing' => array(
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
  $handler->display->display_options['empty']['area']['content'] = 'No thumbwhere_things have been created yet';
    
    
  /* Field: Bulk operations: ThumbWhereContentIngest */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'thumbwhere_thing';
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
  
    

/* Field: ThumbWhereThing: pk_thing */
  $handler->display->display_options['fields']['pk_thing']['id'] = 'pk_thing';
  $handler->display->display_options['fields']['pk_thing']['table'] = 'thumbwhere_thing';
  $handler->display->display_options['fields']['pk_thing']['field'] = 'pk_thing';
  $handler->display->display_options['fields']['pk_thing']['label'] = 'pk_thing';
  $handler->display->display_options['fields']['pk_thing']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['pk_thing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['pk_thing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['pk_thing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['pk_thing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['pk_thing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['pk_thing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['pk_thing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['pk_thing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['pk_thing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['pk_thing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['pk_thing']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['pk_thing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['pk_thing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['pk_thing']['empty_zero'] = 0;
  
  /* Field: ThumbWhereThing: fk_mediaitem */
  $handler->display->display_options['fields']['fk_mediaitem']['id'] = 'fk_mediaitem';
  $handler->display->display_options['fields']['fk_mediaitem']['table'] = 'thumbwhere_thing';
  $handler->display->display_options['fields']['fk_mediaitem']['field'] = 'fk_mediaitem';
  $handler->display->display_options['fields']['fk_mediaitem']['label'] = 'fk_mediaitem';
  $handler->display->display_options['fields']['fk_mediaitem']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['fk_mediaitem']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['fk_mediaitem']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['fk_mediaitem']['alter']['external'] = 0;
  $handler->display->display_options['fields']['fk_mediaitem']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['fk_mediaitem']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['fk_mediaitem']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['fk_mediaitem']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['fk_mediaitem']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['fk_mediaitem']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['fk_mediaitem']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['fk_mediaitem']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['fk_mediaitem']['alter']['html'] = 0;
  $handler->display->display_options['fields']['fk_mediaitem']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['fk_mediaitem']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['fk_mediaitem']['hide_empty'] = 0;
  $handler->display->display_options['fields']['fk_mediaitem']['empty_zero'] = 0;
  $handler->display->display_options['fields']['fk_mediaitem']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['fk_mediaitem']['format_plural'] = 0;
  /* Field: ThumbWhereThing: fk_content */
  $handler->display->display_options['fields']['fk_content']['id'] = 'fk_content';
  $handler->display->display_options['fields']['fk_content']['table'] = 'thumbwhere_thing';
  $handler->display->display_options['fields']['fk_content']['field'] = 'fk_content';
  $handler->display->display_options['fields']['fk_content']['label'] = 'fk_content';
  $handler->display->display_options['fields']['fk_content']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['fk_content']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['fk_content']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['fk_content']['alter']['external'] = 0;
  $handler->display->display_options['fields']['fk_content']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['fk_content']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['fk_content']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['fk_content']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['fk_content']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['fk_content']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['fk_content']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['fk_content']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['fk_content']['alter']['html'] = 0;
  $handler->display->display_options['fields']['fk_content']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['fk_content']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['fk_content']['hide_empty'] = 0;
  $handler->display->display_options['fields']['fk_content']['empty_zero'] = 0;
  $handler->display->display_options['fields']['fk_content']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['fk_content']['format_plural'] = 0;
  /* Field: ThumbWhereThing: fk_contentcollection */
  $handler->display->display_options['fields']['fk_contentcollection']['id'] = 'fk_contentcollection';
  $handler->display->display_options['fields']['fk_contentcollection']['table'] = 'thumbwhere_thing';
  $handler->display->display_options['fields']['fk_contentcollection']['field'] = 'fk_contentcollection';
  $handler->display->display_options['fields']['fk_contentcollection']['label'] = 'fk_contentcollection';
  $handler->display->display_options['fields']['fk_contentcollection']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['fk_contentcollection']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['fk_contentcollection']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['fk_contentcollection']['alter']['external'] = 0;
  $handler->display->display_options['fields']['fk_contentcollection']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['fk_contentcollection']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['fk_contentcollection']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['fk_contentcollection']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['fk_contentcollection']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['fk_contentcollection']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['fk_contentcollection']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['fk_contentcollection']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['fk_contentcollection']['alter']['html'] = 0;
  $handler->display->display_options['fields']['fk_contentcollection']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['fk_contentcollection']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['fk_contentcollection']['hide_empty'] = 0;
  $handler->display->display_options['fields']['fk_contentcollection']['empty_zero'] = 0;
  $handler->display->display_options['fields']['fk_contentcollection']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['fk_contentcollection']['format_plural'] = 0;
    
    
    
  /* Field: ThumbWhereThing: Link */
  $handler->display->display_options['fields']['link_thumbwhere_thing']['id'] = 'link_thumbwhere_thing';
  $handler->display->display_options['fields']['link_thumbwhere_thing']['table'] = 'thumbwhere_thing';
  $handler->display->display_options['fields']['link_thumbwhere_thing']['field'] = 'link_thumbwhere_thing';
  $handler->display->display_options['fields']['link_thumbwhere_thing']['label'] = 'View';
  $handler->display->display_options['fields']['link_thumbwhere_thing']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_thing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_thing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_thing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_thing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_thing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_thing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['link_thumbwhere_thing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['link_thumbwhere_thing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_thing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_thing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_thing']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['link_thumbwhere_thing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['link_thumbwhere_thing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_thing']['empty_zero'] = 0;


  /* Field: ThumbWhereThing: Operations links */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'thumbwhere_thing';
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
  
  
  /* Sort criterion: ThumbWhereThing: Name */
  /*
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'thumbwhere_thing';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  */
  /* Filter criterion: Search Name */
  /*
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'thumbwhere_thing';
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
  $handler = $view->new_display('page', 'Page', 'thumbwhere_things_admin_page');
  $handler->display->display_options['path'] = 'admin/thumbwhere/thumbwhere_things/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Thing';
  $handler->display->display_options['tab_options']['description'] = 'Manage thumbwhere_things';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  //
  // ^^^^^^^^^^^^^^^^^
  //
  // PASTE EXPORT HERE
  //

  $translatables['thumbwhere_things'] = array(
      t('Master'),
      t('Thing'),
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
      t('No thumbwhere_things have been created yet'),
      t('ThumbWhereThing ID'),
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
