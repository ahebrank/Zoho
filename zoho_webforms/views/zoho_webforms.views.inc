<?php

/**
 * @file
 * Views integration for Zoho Webforms tables.
 *
 * @see http://drupal.org/project/views
 */

/**
 * Implements hook_views_data().
 */
function zoho_webforms_views_data() {
  $data = array();

  /**
   * Expose feeds_log table to views.
   */
  $data['zoho_webforms_log']['table'] = array(
    'group' => 'Zoho Webforms log',
    'base' => array(
      'field' => array('id'),
      'title' => t('Zoho Webforms log'),
      'help' => t('Logs events during Zoho submission.'),
    ),
  );
  $data['zoho_webforms_log']['id'] = array(
    'title' => t('Log id'),
    'help' => t('The id of the log message.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'numeric' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['zoho_webforms_log']['webform_nid'] = array(
    'title' => t('Webform node id'),
    'help' => t('Contains the node id of the webform page node if the feed\'s configuration is attached to a content type, otherwise contains 0.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
      'allow empty' => TRUE,
      'help' => t('Filter on a Webform Source\'s nid field.'),
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'numeric' => TRUE,
      'validate type' => 'nid',
      'help' => t('Argument on a Webform Source\'s nid field.'),
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
      'help' => t('Sort Webform Source\'s nid field.'),
    ),
    'relationship' => array(
      'title' => t('Webform node'),
      'help' => t('Relate a log entry to its webform node if available.'),
      'label' => t('Webform node'),
      'base' => 'node',
      'base field' => 'nid',
    ),
  );
  $data['zoho_webforms_log']['log_time'] = array(
    'title' => t('Log time'),
    'help' => t('The time of the event.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['zoho_webforms_log']['message'] = array(
    'title' => t('Log message'),
    'help' => t('The message logged by the event.'),
    'field' => array(
      'handler' => 'zoho_webforms_views_handler_field_log_message',
      'click sortable' => FALSE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['zoho_webforms_log']['xml'] = array(
    'title' => t('Request XML Data'),
    'help' => t('The XML data submitted.'),
    'field' => array(
      'handler' => 'zoho_webforms_views_handler_field_xml',
      'click sortable' => FALSE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['zoho_webforms_log']['severity'] = array(
    'title' => t('Severity'),
    'help' => t('The severity of the event logged.'),
    'field' => array(
      'handler' => 'zoho_webforms_views_handler_field_severity',
      'click sortable' => FALSE,
    ),
    'filter' => array(
      'handler' => 'zoho_webforms_views_handler_filter_severity',
      'allow empty' => TRUE,
      'help' => t('Filter on the severity of a log message.'),
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['zoho_webforms_log']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'webform_nid',
      'type' => 'LEFT',
    ),
  );

  return $data;
}