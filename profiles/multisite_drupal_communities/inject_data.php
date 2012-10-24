<?php

inject_data();

function inject_data() {
  // populate users fields of dummy users
  $account = user_load_by_name("admin");
  $account1 = user_load_by_name("user_administrator");
  $account2 = user_load_by_name("user_contributor");
  $account3 = user_load_by_name("user_editor"); 

  $account->field_firstname['und'][0]['value'] = 'John';
  $account->field_lastname['und'][0]['value'] = 'Doe';
  user_save($account);
	
  $account1->field_firstname['und'][0]['value'] = 'John';
  $account1->field_lastname['und'][0]['value'] = 'Smith';
  user_save($account1);	
	
  $account2->field_firstname['und'][0]['value'] = 'John';
  $account2->field_lastname['und'][0]['value'] = 'Name';
  user_save($account2);	
  
  $account3->field_firstname['und'][0]['value'] = 'John';
  $account3->field_lastname['und'][0]['value'] = 'Blake';
  user_save($account3);	

  // multilingual support -----------------------------------------------------------------------------------------
  // set the main-menu as multilingual 
  /*
  db_update('menu_custom')
    ->fields(array('i18n_mode' => 5))
    ->condition('menu_name', 'main-menu')
    ->execute();

 $main_menu = menu_load("main-menu");
 module_invoke_all('menu_update', $main-menu);
*/
	
  // allow menu items to be translatables
/*
  $links = menu_load_links('main-menu');
  foreach ($links as $link) {
    //$menu = module_invoke('i18n_menu', 'menu_link_update', $link);
	//menu_link_save($link);
	//i18n_string_object_update('menu_link', $link);
  }

  menu_cache_clear_all();
*/
	
  
  //custom Filter and custom Ckeditor profile activation for comments
  $html_update = db_insert('ckeditor_input_format') // Table name no longer needs {}
    ->fields(array(
      'name' => 'Basic',
      'format' => 'basic_html',
    ))
    ->execute();
    
  module_enable(array("i18n_taxonomy"));
  
  
  // create content -----------------------------------------
  
  $node = new stdClass();
  $node->type = 'page';
  node_object_prepare($node);
  
  $node->title    = 'Welcome to your site !';
  $node->language = LANGUAGE_NONE;

  $node->path = array('alias' => 'content/welcome-your-site');
  $node->status = '1';
  $node->uid = '1';
  $node->promote = '0';
  $node->sticky = '0';
  $node->created = '1330594184';
  $node->comment = '1';
  $node->translate = '0';
  $node->revision = 1;
  
 
  $node->body[$node->language][0]['value'] = 
    '<p>Notice:</p>
    <p>You have to login in order to perform any of the action described below &gt;&gt; <a href="../../user">Login</a></p>
    <p>&nbsp;</p>
    <p>To complete the configuration of your site, here are&nbsp;some additional&nbsp;steps :</p>
    <p>- to access the <strong>Feature set</strong> configuration page which helps you to choose the features you wish to install on your site &gt;&gt; <a href="../../admin/structure/feature-set"><font color="#3366ff">click here</font></a></p>
    <p><font color="#000000">- to access the <strong>user creation</strong> page in order to add some users and to choose the role you wish to give them &gt;&gt;</font> <a href="../../admin/people"><font color="#3366ff">click here</font></a></p>
    <p>&nbsp;</p>
    <p>Some information about&nbsp;roles&nbsp;:</p>
    <p>- admin user can do everything on the site, but will mainly be used to approve/refuse user account creation or community creation</p>
    <p>- community manager will act as admin in its community to approve/refuse membership requests and creation of contents inside the community</p>
    <p>Management will be done through the <strong>Workbench </strong>you can access thru this <a href="../../admin/workbench"><font color="#3366ff">link</font></a>.</p>
    <p>For more information about the various functionalities,&nbsp;a contextual help exists and can be accessed&nbsp;thru the &quot;Help&quot; link.&nbsp;The help section depends on your localisation on the site and gives details about the page.</p>
    <p>&nbsp;</p>
    ';
  $node->body[$node->language][0]['summary'] = '';
  $node->body[$node->language][0]['format']  = 'full_html';

  $path = 'content/welcome-your-site';
  $node->path = array('alias' => $path);

  if($node = node_submit($node)) { // Prepare node for saving
    node_save($node);
    echo "Node saved!\n";
  }  
 
  //delete mails from the update manager module
  variable_del("update_notify_emails");
 
  // clear links from the linkchecker scanning
  drush_linkchecker_clear();
}



