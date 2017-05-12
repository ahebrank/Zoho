<?php

/**
 * @file
 * Contains zoho_webforms_views_handler_field_xml
 */

/**
 * Views handler for displaying a log message.
 */
class zoho_webforms_views_handler_field_xml extends views_handler_field {

  /**
   * Override parent::render().
   */
  public function render($values) {
    $message = trim($values->{$this->field_alias});

    // Messages that are too long may generate a PDO exception when calling t()
    // if Drupal tries to add them in {locales_source} table.
    $message = truncate_utf8($message, 65000, TRUE, TRUE);

    return '<xmp>' . $message . '</xmp>';
  }

  /**
   * Disallow advanced rendering.
   */
  public function allow_advanced_render() {
    return FALSE;
  }

}
