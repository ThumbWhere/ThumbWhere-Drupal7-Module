<?php

/**
 * @file
 * Providing extra functionality for the Producer UI via views.
 */


/**
 * Implements hook_views_data().
 */
function producer_views_data_alter(&$data) {
  $data['producer']['link_producer'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a link to the producer.'),
      'handler' => 'producer_handler_link_field',
    ),
  );
  $data['producer']['edit_producer'] = array(
    'field' => array(
      'title' => t('Edit Link'),
      'help' => t('Provide a link to the edit form for the producer.'),
      'handler' => 'producer_handler_edit_link_field',
    ),
  );
  $data['producer']['delete_producer'] = array(
    'field' => array(
      'title' => t('Delete Link'),
      'help' => t('Provide a link to delete the producer.'),
      'handler' => 'producer_handler_delete_link_field',
    ),
  );
  // This content of this field are decided based on the menu structure that
  // follows producers/producer/%producer_id/op
  $data['producer']['operations'] = array(
    'field' => array(
      'title' => t('Operations links'),
      'help' => t('Display all operations available for this producer.'),
      'handler' => 'producer_handler_producer_operations_field',
    ),
  );
}


/**
 * Implements hook_views_default_views().
 */
function producer_views_default_views() {
  $views = array();

  //
  // PASTE EXPORT HERE
  //
  // vvvvvvvvvvvvvvvvv
  //


  $view = new view;
  $view->name = 'producers';
  $view->description = 'A list of all producers';
  $view->tag = 'producers';
  $view->base_table = 'producer';
  $view->human_name = 'Producers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Producers';
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
    'producer_id' => 'producer_id',
    'thumbwhere_id' => 'thumbwhere_id',
    'name' => 'name',
    'link_producer' => 'link_producer',
    'operations' => 'operations',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'producer_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'thumbwhere_id' => array(
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
    'link_producer' => array(
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
  $handler->display->display_options['empty']['area']['content'] = 'No producers have been created yet';
  /* Field: Producer: Producer ID */
  $handler->display->display_options['fields']['producer_id']['id'] = 'producer_id';
  $handler->display->display_options['fields']['producer_id']['table'] = 'producer';
  $handler->display->display_options['fields']['producer_id']['field'] = 'producer_id';
  $handler->display->display_options['fields']['producer_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['producer_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['producer_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['producer_id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['producer_id']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['producer_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['producer_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['producer_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['producer_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['producer_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['producer_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['producer_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['producer_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['producer_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['producer_id']['empty_zero'] = 0;
  /* Field: Producer: Thumbwhere_id */
  $handler->display->display_options['fields']['thumbwhere_id']['id'] = 'thumbwhere_id';
  $handler->display->display_options['fields']['thumbwhere_id']['table'] = 'producer';
  $handler->display->display_options['fields']['thumbwhere_id']['field'] = 'thumbwhere_id';
  $handler->display->display_options['fields']['thumbwhere_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['thumbwhere_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['thumbwhere_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['thumbwhere_id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['thumbwhere_id']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['thumbwhere_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['thumbwhere_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['thumbwhere_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['thumbwhere_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['thumbwhere_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['thumbwhere_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['thumbwhere_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['thumbwhere_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['thumbwhere_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['thumbwhere_id']['empty_zero'] = 0;
  /* Field: Producer: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'producer';
  $handler->display->display_options['fields']['name']['field'] = 'name';
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
  /* Field: Producer: Link */
  $handler->display->display_options['fields']['link_producer']['id'] = 'link_producer';
  $handler->display->display_options['fields']['link_producer']['table'] = 'producer';
  $handler->display->display_options['fields']['link_producer']['field'] = 'link_producer';
  $handler->display->display_options['fields']['link_producer']['label'] = 'View';
  $handler->display->display_options['fields']['link_producer']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['link_producer']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['link_producer']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['link_producer']['alter']['external'] = 0;
  $handler->display->display_options['fields']['link_producer']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['link_producer']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['link_producer']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['link_producer']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['link_producer']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['link_producer']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['link_producer']['alter']['html'] = 0;
  $handler->display->display_options['fields']['link_producer']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['link_producer']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['link_producer']['hide_empty'] = 0;
  $handler->display->display_options['fields']['link_producer']['empty_zero'] = 0;
  /* Field: Producer: Operations links */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'producer';
  $handler->display->display_options['fields']['operations']['field'] = 'operations';
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
  /* Sort criterion: Producer: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'producer';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Filter criterion: Search Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'producer';
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'producers_admin_page');
  $handler->display->display_options['path'] = 'admin/content/producers/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Producers';
  $handler->display->display_options['tab_options']['description'] = 'Manage producers';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  //
  // ^^^^^^^^^^^^^^^^^
  //
  // PASTE EXPORT HERE
  //



  $translatables['producers'] = array(
    t('Master'),
    t('Producers'),
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
    t('No producers have been created yet'),
    t('Producer ID'),
    t('.'),
    t(','),
    t('Name'),
    t('View'),
    t('Operations links'),
    t('Page'),
  );
  $views[] = $view;
  return $views;

}
