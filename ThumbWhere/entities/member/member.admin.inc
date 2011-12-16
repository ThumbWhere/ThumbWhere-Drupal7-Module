<?php

/**
 * @file
 * Member editing UI.
 *
 * We make very little use of the EntityAPI interface for this - preferring instead to use
 * views. That offers more flexibility to change a UI that will, more often than not,
 * be end-user facing.
 */




/**
 * Form callback wrapper: create or edit a member.
 *
 * @param $member
 *   The member object being edited by this form.
 *
 * @see member_edit_form()
 */
function member_form_wrapper($member) {
  // Add the breadcrumb for the form's location.
  member_set_breadcrumb();
  return drupal_get_form('member_edit_form', $member);
}


/**
 * Form callback wrapper: delete a member.
 *
 * @param $member
 *   The member object being edited by this form.
 *
 * @see member_edit_form()
 */
function member_delete_form_wrapper($member) {
  // Add the breadcrumb for the form's location.
  //member_set_breadcrumb();
  return drupal_get_form('member_delete_form', $member);
}


/**
 * Form callback: create or edit a member.
 *
 * @param $member
 *   The member object to edit or for a create form an empty member object
 *     with only a member type defined.
 */
function member_edit_form($form, &$form_state, $member) {
  // Add the default field elements.
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Member Name'),
    '#default_value' => isset($member->name) ? $member->name : '',
    '#maxlength' => 255,
    '#required' => TRUE,
    '#weight' => -5,
  );
  
  $form['data']['#tree'] = TRUE;
  $form['data']['sample_data'] = array(
    '#type' => 'checkbox',
    '#title' => t('An interesting member switch'),
    '#default_value' => isset($member->data['sample_data']) ? $member->data['sample_data'] : 1,
  );

  // Add the field related form elements.
  $form_state['member'] = $member;
  field_attach_form('member', $member, $form, $form_state);

  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
    '#weight' => 400,
  );

  // We add the form's #submit array to this button along with the actual submit
  // handler to preserve any submit handlers added by a form callback_wrapper.
  $submit = array();

  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save member'),
    '#submit' => $submit + array('member_edit_form_submit'),
  );
  
  if (!empty($member->name)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete member'),
      '#suffix' => l(t('Cancel'), 'admin/content/members'),
      '#submit' => $submit + array('member_form_submit_delete'),
      '#weight' => 45,
    );
  }

  // We append the validate handler to #validate in case a form callback_wrapper
  // is used to add validate handlers earlier.
  $form['#validate'][] = 'member_edit_form_validate';
  return $form;
}


/**
 * Form API validate callback for the member form
 */
function member_edit_form_validate(&$form, &$form_state) {
  $member = $form_state['member'];
  
  // Notify field widgets to validate their data.
  field_attach_form_validate('member', $member, $form, $form_state);
}


/**
 * Form API submit callback for the member form.
 * 
 * @todo remove hard-coded link
 */
function member_edit_form_submit(&$form, &$form_state) {
  
  $member = entity_ui_controller('member')->entityFormSubmitBuildEntity($form, $form_state);
  // Save the member and go back to the list of members
  
  // Add in created and changed times.
  if ($member->is_new = isset($member->is_new) ? $member->is_new : 0) {
    $member->created = time();
  }

  $member->changed = time();
  
  $member->save();
  $form_state['redirect'] = 'admin/content/members';
}

/**
 * Form API submit callback for the delete button.
 * 
 * @todo Remove hard-coded path
 */
function member_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/content/members/member/' . $form_state['member']->member_id . '/delete';
}


/**
 * Form callback: confirmation form for deleting a member.
 *
 * @param $member
 *   The member to delete
 *
 * @see confirm_form()
 */
function member_delete_form($form, &$form_state, $member) {
  $form_state['member'] = $member;

  $form['#submit'][] = 'member_delete_form_submit';

  $form = confirm_form($form,
    t('Are you sure you want to delete member %name?', array('%name' => $member->name)),
    'admin/content/members/member',
    '<p>' . t('This action cannot be undone.') . '</p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
  );
  
  return $form;
}

/**
 * Submit callback for member_delete_form
 */
function member_delete_form_submit($form, &$form_state) {
  $member = $form_state['member'];

  member_delete($member);

  drupal_set_message(t('The member %name has been deleted.', array('%name' => $member->name)));
  watchdog('member', 'Deleted member %name.', array('%name' => $member->name));

  $form_state['redirect'] = 'admin/content/members';
}



/**
 * Page to add Member Entities.
 *
 * @todo Pass this through a proper theme function
 */
function member_add_page() {
  $controller = entity_ui_controller('member');
  return $controller->addPage();
}


/**
 * Displays the list of available member types for member creation.
 *
 * @ingroup themeable
 */
function theme_member_add_list($variables) {
  $content = $variables['content'];
  $output = '';
  if ($content) {
    $output = '<dl class="member-type-list">';
    foreach ($content as $item) {
      $output .= '<dt>' . l($item['title'], $item['href']) . '</dt>';
      $output .= '<dd>' . filter_xss_admin($item['description']) . '</dd>';
    }
    $output .= '</dl>';
  }
  else {
    if (user_access('administer member types')) {
      $output = '<p>' . t('Member Entities cannot be added because you have not created any member types yet. Go to the <a href="@create-member-type">member type creation page</a> to add a new member type.', array('@create-member-type' => url('admin/structure/member_types/add'))) . '</p>';
    }
    else {
      $output = '<p>' . t('No member types have been created yet for you to use.') . '</p>';
    }
  }

  return $output;
}





/**
 * Sets the breadcrumb for administrative member pages.
 */
function member_set_breadcrumb() {
  $breadcrumb = array(
    l(t('Home'), '<front>'),
    l(t('Administration'), 'admin'),
    l(t('Content'), 'admin/content'),
    l(t('Members'), 'admin/content/members'),
  );

  drupal_set_breadcrumb($breadcrumb);
}



