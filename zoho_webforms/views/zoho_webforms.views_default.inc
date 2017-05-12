<?php

/**
 * @file
 * Default view definitions for Zoho Webforms.
 */

/**
 * Implementation of hook_views_default_views().
 */
function zoho_webforms_views_default_views() {
  $views = array();

  $view = new view();
  $view->name = 'zoho_webforms_log';
  $view->description = 'Zoho Webforms log display.';
  $view->tag = 'Zoho Webforms';
  $view->base_table = 'zoho_webforms_log';
  $view->human_name = 'Zoho Webforms log';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer zoho api';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'log_time' => 'log_time',
    'message' => 'message',
    'xml' => 'xml',
    'severity' => 'severity',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'log_time' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'message' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'xml' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'severity' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
     'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no log messages.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Field: Zoho Webforms log: Log time */
  $handler->display->display_options['fields']['log_time']['id'] = 'log_time';
  $handler->display->display_options['fields']['log_time']['table'] = 'zoho_webforms_log';
  $handler->display->display_options['fields']['log_time']['field'] = 'log_time';
  $handler->display->display_options['fields']['log_time']['date_format'] = 'custom';
  $handler->display->display_options['fields']['log_time']['custom_date_format'] = 'Y-m-d H:i:s';
  /* Field: Zoho Webforms log: Log message */
  $handler->display->display_options['fields']['message']['id'] = 'message';
  $handler->display->display_options['fields']['message']['table'] = 'zoho_webforms_log';
  $handler->display->display_options['fields']['message']['field'] = 'message';
  $handler->display->display_options['fields']['message']['label'] = 'Message';
  /* Field: Zoho Webforms log: Log xml */
  $handler->display->display_options['fields']['message']['id'] = 'xml';
  $handler->display->display_options['fields']['message']['table'] = 'zoho_webforms_log';
  $handler->display->display_options['fields']['message']['field'] = 'xml';
  $handler->display->display_options['fields']['message']['label'] = 'XML';
  /* Field: Zoho Webforms log: Severity */
  $handler->display->display_options['fields']['severity']['id'] = 'severity';
  $handler->display->display_options['fields']['severity']['table'] = 'zoho_webforms_log';
  $handler->display->display_options['fields']['severity']['field'] = 'severity';
  /* Sort criterion: Zoho Webforms log: Log id */
  $handler->display->display_options['sorts']['id']['id'] = 'id';
  $handler->display->display_options['sorts']['id']['table'] = 'zoho_webforms_log';
  $handler->display->display_options['sorts']['id']['field'] = 'id';
  $handler->display->display_options['sorts']['id']['order'] = 'DESC';
  /* Filter criterion: Zoho Webforms log: Feed node id */
  $handler->display->display_options['filters']['feed_nid']['id'] = 'webform_nid';
  $handler->display->display_options['filters']['feed_nid']['table'] = 'zoho_webforms_log';
  $handler->display->display_options['filters']['feed_nid']['field'] = 'webform_nid';
  $handler->display->display_options['filters']['feed_nid']['value']['value'] = '0';
  /* Filter criterion: Zoho Webforms log: Severity */
  $handler->display->display_options['filters']['severity']['id'] = 'severity';
  $handler->display->display_options['filters']['severity']['table'] = 'zoho_webforms_log';
  $handler->display->display_options['filters']['severity']['field'] = 'severity';
  $handler->display->display_options['filters']['severity']['exposed'] = TRUE;
  $handler->display->display_options['filters']['severity']['expose']['operator_id'] = 'severity_op';
  $handler->display->display_options['filters']['severity']['expose']['label'] = 'Severity';
  $handler->display->display_options['filters']['severity']['expose']['operator'] = 'severity_op';
  $handler->display->display_options['filters']['severity']['expose']['identifier'] = 'severity';

  /* Display: All entries */
  $handler = $view->new_display('page', 'All entries', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Zoho Webforms log';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Zoho Webforms log: Feed node */
  $handler->display->display_options['relationships']['webform_nid']['id'] = 'webform_nid';
  $handler->display->display_options['relationships']['webform_nid']['table'] = 'zoho_webforms_log';
  $handler->display->display_options['relationships']['webform_nid']['field'] = 'webform_nid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Zoho Webforms log: Log time */
  $handler->display->display_options['fields']['log_time']['id'] = 'log_time';
  $handler->display->display_options['fields']['log_time']['table'] = 'zoho_webforms_log';
  $handler->display->display_options['fields']['log_time']['field'] = 'log_time';
  $handler->display->display_options['fields']['log_time']['date_format'] = 'custom';
  $handler->display->display_options['fields']['log_time']['custom_date_format'] = 'Y-m-d H:i:s';
  /* Field: Zoho Webforms log: Log message */
  $handler->display->display_options['fields']['message']['id'] = 'message';
  $handler->display->display_options['fields']['message']['table'] = 'zoho_webforms_log';
  $handler->display->display_options['fields']['message']['field'] = 'message';
  $handler->display->display_options['fields']['message']['label'] = 'Message';
    /* Field: Zoho Webforms log: Log message */
  $handler->display->display_options['fields']['xml']['id'] = 'xml';
  $handler->display->display_options['fields']['xml']['table'] = 'zoho_webforms_log';
  $handler->display->display_options['fields']['xml']['field'] = 'xml';
  $handler->display->display_options['fields']['xml']['label'] = 'XML';
  /* Field: Zoho Webforms log: Severity */
  $handler->display->display_options['fields']['severity']['id'] = 'severity';
  $handler->display->display_options['fields']['severity']['table'] = 'zoho_webforms_log';
  $handler->display->display_options['fields']['severity']['field'] = 'severity';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'webform_nid';
  $handler->display->display_options['fields']['title']['label'] = 'Webform node';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '40';
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Zoho Webforms log: Severity */
  $handler->display->display_options['filters']['severity']['id'] = 'severity';
  $handler->display->display_options['filters']['severity']['table'] = 'zoho_webforms_log';
  $handler->display->display_options['filters']['severity']['field'] = 'severity';
  $handler->display->display_options['filters']['severity']['exposed'] = TRUE;
  $handler->display->display_options['filters']['severity']['expose']['operator_id'] = 'severity_op';
  $handler->display->display_options['filters']['severity']['expose']['label'] = 'Severity';
  $handler->display->display_options['filters']['severity']['expose']['operator'] = 'severity_op';
  $handler->display->display_options['filters']['severity']['expose']['identifier'] = 'severity';
  $handler->display->display_options['path'] = 'admin/reports/zoho_webforms';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Zoho Webforms log';
  $handler->display->display_options['menu']['description'] = 'Review log messages of Zoho submissions.';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $translatables['zoho_webforms_log'] = array(
    t('Defaults'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('There are no log messages.'),
    t('Log time'),
    t('Message'),
    t('XML'),
    t('Severity'),
    t('All entries'),
    t('Feeds log'),
    t('Webform node'),
  );

  $views[$view->name] = $view;

  return $views;
}
