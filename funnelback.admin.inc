<?php

/**
 * @file
 * Admin functions for the funnelback module.
 */

/**
 * Form builder for the Funnelback settings page.
 */
function funnelback_admin_form($form, &$form_state) {

  $form['description'] = array(
    '#value' => 'These are the settings for Funnelback search integration.',
    '#prefix' => '<div>',
    '#suffix' => '</div>',
  );
  $form['base_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Base Url'),
    '#description' => t('The base url for the Funnelback XML interface'),
    '#size' => 60,
    '#maxlength' => 255,
    '#default_value' => variable_get('funnelback_base_url', 'https://example.funnelback.com/search/'),
  );
  $form['api_format'] = array(
    '#type' => 'select',
    '#title' => t('API Format'),
    '#description' => t('The API format used to return data'),
    '#options' => array(
      FUNNELBACK_API_HTML => t('HTML'),
      FUNNELBACK_API_XML => t('XML'),
      FUNNELBACK_API_JSON => t('JSON'),
    ),
    '#default_value' => variable_get('funnelback_api_format', FUNNELBACK_API_XML),
  );
  $form['api_path'] = array(
    '#type' => 'textfield',
    '#title' => t('API Path'),
    '#description' => t('The path to the API interface'),
    '#size' => 60,
    '#maxlength' => 255,
    '#default_value' => variable_get('funnelback_api_path', 'xml.cgi'),
  );
  $form['collection_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Collection Name'),
    '#description' => t('The Funnelback collection name'),
    '#size' => 30,
    '#maxlength' => 255,
    '#default_value' => variable_get('funnelback_collection', 'example'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  return $form;
}

/**
 * Form validation callback for the funnelback admin form.
 */
function funnelback_admin_form_validate($form, &$form_state) {
  if ($form_state['values']['base_url'] == '') {
    form_set_error('', t('You must enter a base url.'));
  }
  if ($form_state['values']['api_format'] == '') {
    form_set_error('', t('You must choose an API format.'));
  }
  if ($form_state['values']['api_path'] == '') {
    form_set_error('', t('You must enter an API path.'));
  }
  if ($form_state['values']['collection_name'] == '') {
    form_set_error('', t('You must enter a collection name.'));
  }
}

/**
 * Form submission callback for the funnelback admin form.
 */
function funnelback_admin_form_submit($form, &$form_state) {
  variable_set('funnelback_base_url', $form_state['values']['base_url']);
  variable_set('funnelback_api_format', $form_state['values']['api_format']);
  variable_set('funnelback_api_path', $form_state['values']['api_path']);
  variable_set('funnelback_collection', $form_state['values']['collection_name']);
  drupal_set_message(t('Your settings have been saved.'));
}
