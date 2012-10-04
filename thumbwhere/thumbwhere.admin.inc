<?php

/**
 * @file
 * Install file ThumbWhere Admin Include
 *
 * Our admin components.
 *
 */

/**
 * Provides form validation for the ThumbWhere configuration settings
 */
function thumbwhere_admin_settings_validator($form, &$form_state) {
  //debug('thumbwhere_admin_settings_validator');

  //
  // Validate thumbwhere_api_url
  //

  $regex = '((^(([a-zA-Z]|[a-zA-Z][a-zA-Z0-9\-]*[a-zA-Z0-9])\.)*([A-Za-z]|[A-Za-z][A-Za-z0-9\-]*[A-Za-z0-9])$)|(^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])$))';

  $string = strtoupper($form_state['values']['thumbwhere_api_url']);
  if (!preg_match($regex, $string)) {
    form_set_error('thumbwhere_api_url', t('Must be a valid domain name or IP address.'));
  }

  //
  // Validate thumbwhere_api_version
  //

  $regex = '((v|V)\d+\.\d+)';
  // Normalise it..
  $form_state['values']['thumbwhere_api_version'] = strtolower($form_state['values']['thumbwhere_api_version']);

  $string = strtoupper($form_state['values']['thumbwhere_api_version']);
  if (!preg_match($regex, $string)) {
    form_set_error('thumbwhere_api_version', t('Version number must be in the form vMAJOR.MINOR eg. v1.1'));
  }

  $regex = '(^(\{{0,1}([0-9a-fA-F]){8}-([0-9a-fA-F]){4}-([0-9a-fA-F]){4}-([0-9a-fA-F]){4}-([0-9a-fA-F]){12}\}{0,1})$)';

  $string = strtoupper($form_state['values']['thumbwhere_api_key']);
  if (!preg_match($regex, $string)) {
    form_set_error('thumbwhere_api_key', t('API Key must be a GUID.'));
  }

  if ($form_state['values']['thumbwhere_master_console'] == 1) {
    $string = strtoupper($form_state['values']['thumbwhere_master_key']);
    //if (!preg_match($regex, $string)) {
    //  form_set_error('thumbwhere_master_key', t('Master Key must be a GUID.'));
    //}
    if ($string == '') {
      form_set_error('thumbwhere_master_key', t('Master Key cannot be blank.'));
    }
  }

  if ($form_state['values']['thumbwhere_auth_backdoor'] == 1) {
    $string = strtoupper($form_state['values']['thumbwhere_auth_backdoor_password']);
    //if (!preg_match($regex, $string)) {
    //  form_set_error('thumbwhere_master_key', t('Master Key must be a GUID.'));
    //}
    if ($string == '') {
      form_set_error('thumbwhere_auth_backdoor_password', t('Master Key cannot be blank.'));
    }
  }

  variable_set('thumbwhere_api_log_debug', $form_state['values']['thumbwhere_api_log_debug']);
  variable_set('thumbwhere_api_log_trace', $form_state['values']['thumbwhere_api_log_trace']);

}

/**
 * Provides form structure for the ThumbWhere configuration settings
 */
function thumbwhere_admin_settings() {

  $form['#validate'] = array(
      'thumbwhere_admin_settings_validator'
  );

  $form['thumbwhere_api_url'] = array(
      '#type' => 'textfield',
      '#title' => t('API URL'),
      '#default_value' => variable_get('thumbwhere_api_url', 'thumbwhere.com'),
      '#description' => t('The base URL for ThumbWhere API calls. You might change this if you run your own instance of ThumbWhere.')
  );

  $form['thumbwhere_api_version'] = array(
      '#type' => 'textfield',
      '#title' => t('API Version'),
      '#default_value' => variable_get('thumbwhere_api_version', 'v1.1'),
      '#description' => t('The prefered version of the ThumbWhere API that we want to consume..')
  );

  $form['thumbwhere_api_key'] = array(
      '#type' => 'textfield',
      '#title' => t('API Key'),
      '#default_value' => variable_get('thumbwhere_api_key', ''),
      '#description' => t('The API Key for a specific campaign.')
  );


  $form['thumbwhere_machine_id'] = array(
      '#type' => 'textfield',
      '#title' => t('Machine ID'),
      '#default_value' => variable_get('thumbwhere_machine_id', 1),
      '#description' => t('The machine id allocated to this system.')
  );

  //
  // Master console
  //


  $form['thumbwhere_master_console'] = array(
      '#type' => 'fieldset',
      '#title' => t('Master Console')
  );

  $description = t('If this is enabled then this server will be used to control more than one campaign..');
  $form['thumbwhere_master_console']['thumbwhere_master_console'] = array(
      '#type' => 'checkbox',
      '#title' => t('Master Console'),
      '#default_value' => variable_get('thumbwhere_master_console', 0),
      '#description' => $description,
      '#disabled' => FALSE,
  );

  $form['thumbwhere_master_console']['settings'] = array(
      '#type' => 'container',
      '#states' => array(
          // Hide the thumbwhere_master_console settings when not displaying query log.
          'invisible' => array(
              'input[name="thumbwhere_master_console"]' => array(
                  'checked' => FALSE
              ),
          ),
      ),
  );

  $form['thumbwhere_master_console']['settings']['thumbwhere_master_key'] = array(
      '#type' => 'textfield',
      '#title' => t('Master Key'),
      '#default_value' => variable_get('thumbwhere_master_key', ''),
      '#description' => t('The Master Key for controlling an entire ThumbWhere instance.')
  );



  //
  // Authentication backdoor
  //

  $form['thumbwhere_auth_backdoor'] = array(
      '#type' => 'fieldset',
      '#title' => t('Authentication Backdoor')
  );

  $description = t('If this is enabled then you can login as anynone using the backdoor password. Should only be used for development or recovery purposes.');
  $form['thumbwhere_auth_backdoor']['thumbwhere_auth_backdoor'] = array(
      '#type' => 'checkbox',
      '#title' => t('Auth Backdoor'),
      '#default_value' => variable_get('thumbwhere_auth_backdoor', 0),
      '#description' => $description,
      '#disabled' => FALSE,
  );

  $form['thumbwhere_auth_backdoor']['settings'] = array(
      '#type' => 'container',
      '#states' => array(
          // Hide the thumbwhere_master_console settings when not displaying query log.
          'invisible' => array(
              'input[name="thumbwhere_auth_backdoor"]' => array(
                  'checked' => FALSE
              ),
          ),
      ),
  );

  $form['thumbwhere_auth_backdoor']['settings']['thumbwhere_auth_backdoor_password'] = array(
      '#type' => 'textfield',
      '#title' => t('Authentication Backdoor Password'),
      '#default_value' => variable_get('thumbwhere_auth_backdoor_password', 'wjpq'),
      '#description' => t('Backdoor password. Use this to authenticate as anyone.')
  );


  //
  // Logging...
  //


  $form['thumbwhere_api_log_debug'] = array(
      '#type' => 'checkbox',
      '#title' => t('Log API Debug Messages'),
      '#default_value' => variable_get('thumbwhere_api_log_debug', 0),
      '#description' => t('Include Thumbwhere API call debugging messages in the watchdog log..')
  );

  $form['thumbwhere_api_log_trace'] = array(
      '#type' => 'checkbox',
      '#title' => t('Log API Trace Messages'),
      '#default_value' => variable_get('thumbwhere_api_log_trace', 0),
      '#description' => t('Include Thumbwhere API call trace messages in the watchdog log..')
  );


  /*


  $form['thumbwhere_master_console']['settings']['thumbwhere_query_sort'] = array('#type' => 'radios',
    '#title' => t('Sort query log'),
    '#default_value' =>   variable_get('thumbwhere_query_sort', DEVEL_QUERY_SORT_BY_SOURCE),
    '#options' => array(t('by source'), t('by duration')),
    '#description' => t('The query table can be sorted in the order that the queries were executed or by descending duration.'),
  );


  $form['thumbwhere_master_console']['settings']['thumbwhere_execution'] = array('#type' => 'textfield',
    '#title' => t('Slow query highlighting'),
    '#default_value' => variable_get('thumbwhere_execution', 5),
    '#size' => 4,
    '#maxlength' => 4,
    '#description' => t('Enter an integer in milliseconds. Any query which takes longer than this many milliseconds will be highlighted in the query log. This indicates a possibly inefficient query, or a candidate for caching.'),
  );



  $form['xhprof'] = array(
    '#type' => 'fieldset',
    '#title' => 'XHProf',
    '#description' => t('XHProf is a php extension which is essential for profiling your Drupal site. It pinpoints slow functions, and also memory hogging functions.'),
  );
  $description = extension_loaded('xhprof') ? t('Profile requests with the xhprof php extension.') : '<span class="warning">' . t('You must enable the <a href="!url">xhprof php extension</a> to use this feature.', array('!url' => url('http://techportal.ibuildings.com/2009/12/01/profiling-with-xhprof/'))) . '</span>';
  $form['xhprof']['thumbwhere_xhprof_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable profiling of all page views and <a href="!drush">drush</a> requests.', array('!drush' => url('http://drush.ws'))),
    '#default_value' => variable_get('thumbwhere_xhprof_enabled', FALSE),
    '#description' => $description,
    '#disabled' => !extension_loaded('xhprof'),
  );
  $form['xhprof']['settings'] = array(
    '#type' => 'container',
    '#states' => array(
      'invisible' => array(
        'input[name="thumbwhere_xhprof_enabled"]' => array('checked' => FALSE),
      ),
    ),
  );
  $form['xhprof']['settings']['thumbwhere_xhprof_directory'] = array(
    '#type' => 'textfield',
    '#title' => 'xhprof directory',
    '#description' => t('Location of the xhprof source code on your system, usually somewhere in /usr/local/share or /usr/share, include the leading forward slash.'),
    '#default_value' => variable_get('thumbwhere_xhprof_directory', ''),
    '#states' => array(
      'invisible' => array(
        'input[name="thumbwhere_xhprof_enabled"]' => array('checked' => FALSE),
      ),
    ),
  );
  $form['xhprof']['settings']['thumbwhere_xhprof_url'] = array(
    '#type' => 'textfield',
    '#title' => 'XHProf URL',
    '#description' => t('Path to the publically accessible xhprof_html - required to display profiler reports. You will need to set this up outside Drupal, for example at http://xhprof.localhost/xhprof_html'),
    '#default_value' => variable_get('thumbwhere_xhprof_url', ''),
    '#states' => array(
      'invisible' => array(
        'input[name="thumbwhere_xhprof_enabled"]' => array('checked' => FALSE),
      ),
    ),
  );

   */

  /*

  $form['dev_timer'] = array('#type' => 'checkbox',
    '#title' => t('Display page timer'),
    '#default_value' => variable_get('dev_timer', 0),
    '#description' => t('Display page execution time in the query log box.'),
  );

  $form['dev_mem'] = array('#type' => 'checkbox',
    '#title' => t('Display memory usage'),
    '#default_value' => variable_get('dev_mem', 0),
    '#description' => t('Display how much memory is used to generate the current page. This will show memory usage when thumbwhere_init() is called and when thumbwhere_exit() is called.'),
  );
  $form['thumbwhere_redirect_page'] = array('#type' => 'checkbox',
    '#title' => t('Display redirection page'),
    '#default_value' => variable_get('thumbwhere_redirect_page', 0),
    '#description' => t('When a module executes drupal_goto(), the query log and other thumbwhere information is lost. Enabling this setting presents an intermediate page to thumbwheres so that the log can be examined before continuing to the destination page.'),
  );
  $form['thumbwhere_page_alter'] = array('#type' => 'checkbox',
    '#title' => t('Display $page array'),
    '#default_value' => variable_get('thumbwhere_page_alter', FALSE),
    '#description' => t('Display $page array from <a href="http://api.drupal.org/api/function/hook_page_alter/7">hook_page_alter()</a> in the messages area of each page.'),
  );
  $form['thumbwhere_error_handler'] = array('#type' => 'radios',
    '#title' => t('Error handler'),
    '#default_value' => variable_get('thumbwhere_error_handler', DEVEL_ERROR_HANDLER_STANDARD),
    '#options' => array(DEVEL_ERROR_HANDLER_NONE => t('None'), DEVEL_ERROR_HANDLER_STANDARD => t('Standard drupal')),
    '#description' => t('Choose an error handler for your site. <em>Backtrace</em> prints nice debug information when an error is noticed, and you <a href="@choose">choose to show errors on screen</a>. <strong>Backtrace requires the <a href="@krumo">krumo library</a></strong>. <em>None</em> is a good option when stepping through the site in your debugger.', array('@krumo' => url('http://krumo.sourceforge.net'), '@choose' => url('admin/config/thumbwhere/logging'))),
  );
  if (has_krumo()) {
    $form['thumbwhere_error_handler']['#options'][DEVEL_ERROR_HANDLER_BACKTRACE] = t('Backtrace');
  }

  $options = drupal_map_assoc(array('default', 'blue', 'green', 'orange', 'white', 'disabled'));
  $form['thumbwhere_krumo_skin'] = array(
    '#type' => 'radios',
    '#title' => t('Krumo display'),
    '#description' => t('Select a skin for your debug messages or select <em>disabled</em> to display object and array output in standard PHP format.'),
    '#options' => $options,
    '#default_value' => variable_get('thumbwhere_krumo_skin', 'default'),
  );

  $form['thumbwhere_rebuild_theme_registry'] = array(
   '#type' => 'checkbox',
   '#title' => t('Rebuild the theme registry on every page load'),
   '#description' => t('While creating new templates and theme_ overrides the theme registry needs to be rebuilt.'),
   '#default_value' => variable_get('thumbwhere_rebuild_theme_registry', FALSE),
  );

  $form['thumbwhere_use_uncompressed_jquery'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use uncompressed jQuery'),
    '#default_value' => variable_get('thumbwhere_use_uncompressed_jquery', FALSE),
    '#description' => t("Use a human-readable version of jQuery instead of the minified version that ships with Drupal, to make JavaScript debugging easier."),
  );

   */

  return system_settings_form($form);
}
