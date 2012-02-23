<?php

/**
 * @file
 * Providing extra functionality for the ThumbWhereProducer UI via views.
 */


/**
 * Implements hook_views_data().
 */
function thumbwhere_producer_views_data_alter(&$data) {
  $data['thumbwhere_producer']['link_thumbwhere_producer'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a link to the thumbwhere_producer.'),
      'handler' => 'thumbwhere_producer_handler_link_field',
    ),
  );
  $data['thumbwhere_producer']['edit_thumbwhere_producer'] = array(
    'field' => array(
      'title' => t('Edit Link'),
      'help' => t('Provide a link to the edit form for the thumbwhere_producer.'),
      'handler' => 'thumbwhere_producer_handler_edit_link_field',
    ),
  );
  $data['thumbwhere_producer']['delete_thumbwhere_producer'] = array(
    'field' => array(
      'title' => t('Delete Link'),
      'help' => t('Provide a link to delete the thumbwhere_producer.'),
      'handler' => 'thumbwhere_producer_handler_delete_link_field',
    ),
  );
  // This content of this field are decided based on the menu structure that
  // follows thumbwhere_producers/thumbwhere_producer/%thumbwhere_producer_id/op
  $data['thumbwhere_producer']['operations'] = array(
    'field' => array(
      'title' => t('Operations links'),
      'help' => t('Display all operations available for this thumbwhere_producer.'),
      'handler' => 'thumbwhere_producer_handler_thumbwhere_producer_operations_field',
    ),
  );
}


/**
 * Implements hook_views_default_views().
 */
function thumbwhere_producer_views_default_views() {
  $views = array();

  //
  // PASTE EXPORT HERE
  //
  // vvvvvvvvvvvvvvvvv
  //


  $view = new view;
  $view->name = 'thumbwhere_producers';
  $view->description = 'A list of all thumbwhere_producers';
  $view->tag = 'thumbwhere_producers';
  $view->base_table = 'thumbwhere_producer';
  $view->human_name = 'ThumbWhereProducers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'ThumbWhereProducers';
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
    'thumbwhere_producer_id' => 'thumbwhere_producer_id',
    'thumbwhere_id' => 'thumbwhere_id',
    'name' => 'name',
    'link_thumbwhere_producer' => 'link_thumbwhere_producer',
    'operations' => 'operations',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'thumbwhere_producer_id' => array(
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
    'link_thumbwhere_producer' => array(
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
  $handler->display->display_options['empty']['area']['content'] = 'No thumbwhere_producers have been created yet';
  /* Field: ThumbWhereProducer: ThumbWhereProducer ID */
  $handler->display->display_options['fields']['thumbwhere_producer_id']['id'] = 'thumbwhere_producer_id';
  $handler->display->display_options['fields']['thumbwhere_producer_id']['table'] = 'thumbwhere_producer';
  $handler->display->display_options['fields']['thumbwhere_producer_id']['field'] = 'thumbwhere_producer_id';
  $handler->display->display_options['fields']['thumbwhere_producer_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['thumbwhere_producer_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['thumbwhere_producer_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['thumbwhere_producer_id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['thumbwhere_producer_id']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['thumbwhere_producer_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['thumbwhere_producer_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['thumbwhere_producer_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['thumbwhere_producer_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['thumbwhere_producer_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['thumbwhere_producer_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['thumbwhere_producer_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['thumbwhere_producer_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['thumbwhere_producer_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['thumbwhere_producer_id']['empty_zero'] = 0;
  /* Field: ThumbWhereProducer: Thumbwhere_id */
  $handler->display->display_options['fields']['thumbwhere_id']['id'] = 'thumbwhere_id';
  $handler->display->display_options['fields']['thumbwhere_id']['table'] = 'thumbwhere_producer';
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
  /* Field: ThumbWhereProducer: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'thumbwhere_producer';
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
  /* Field: ThumbWhereProducer: Link */
  $handler->display->display_options['fields']['link_thumbwhere_producer']['id'] = 'link_thumbwhere_producer';
  $handler->display->display_options['fields']['link_thumbwhere_producer']['table'] = 'thumbwhere_producer';
  $handler->display->display_options['fields']['link_thumbwhere_producer']['field'] = 'link_thumbwhere_producer';
  $handler->display->display_options['fields']['link_thumbwhere_producer']['label'] = 'View';
  $handler->display->display_options['fields']['link_thumbwhere_producer']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_producer']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_producer']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_producer']['alter']['external'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_producer']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_producer']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_producer']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['link_thumbwhere_producer']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['link_thumbwhere_producer']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_producer']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_producer']['alter']['html'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_producer']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['link_thumbwhere_producer']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['link_thumbwhere_producer']['hide_empty'] = 0;
  $handler->display->display_options['fields']['link_thumbwhere_producer']['empty_zero'] = 0;
  /* Field: ThumbWhereProducer: Operations links */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'thumbwhere_producer';
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
  /* Sort criterion: ThumbWhereProducer: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'thumbwhere_producer';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Filter criterion: Search Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'thumbwhere_producer';
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
  $handler = $view->new_display('page', 'Page', 'thumbwhere_producers_admin_page');
  $handler->display->display_options['path'] = 'admin/content/thumbwhere_producers/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'ThumbWhereProducers';
  $handler->display->display_options['tab_options']['description'] = 'Manage thumbwhere_producers';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  //
  // ^^^^^^^^^^^^^^^^^
  //
  // PASTE EXPORT HERE
  //



  $translatables['thumbwhere_producers'] = array(
    t('Master'),
    t('ThumbWhereProducers'),
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
    t('No thumbwhere_producers have been created yet'),
    t('ThumbWhereProducer ID'),
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
