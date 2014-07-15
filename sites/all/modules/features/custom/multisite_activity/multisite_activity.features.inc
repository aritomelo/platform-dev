<?php
/**
 * @file
 * multisite_activity.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function multisite_activity_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function multisite_activity_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_message_type().
 */
function multisite_activity_default_message_type() {
  $items = array();
  $items['multisite_content_delete'] = entity_import('message_type', '{
    "name" : "multisite_content_delete",
    "description" : "content deletion",
    "argument_keys" : [ "!user-picture" ],
    "argument" : [],
    "category" : "message_type",
    "data" : { "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" } },
    "language" : "en",
    "arguments" : [],
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E\\u0022\\u003Ca title=\\u0022Insert this token into your form\\u0022\\u003E[message:field-node-ref:title]\\u003C\\/a\\u003E\\u0022 has been deleted by \\u003Ca title=\\u0022Insert this token into your form\\u0022\\u003E[message:field-node-ref:author]\\u003C\\/a\\u003E\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u0022\\u003Ca title=\\u0022Insert this token into your form\\u0022\\u003E[message:field-node-ref:title]\\u003C\\/a\\u003E\\u0022 has been deleted by \\u003Ca title=\\u0022Insert this token into your form\\u0022\\u003E[message:field-node-ref:author]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n"
        }
      ],
      "und" : [
        {
          "value" : "[message:user:picture]",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:picture]\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Ca href=\\u0022[message:user:url]\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E created \\u003Ca href=\\u0022[message:field-node-ref:url]\\u0022\\u003E[message:field-node-ref:title]\\u003C\\/a\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Ca href=\\u0022[message:user:url]\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E created \\u003Ca href=\\u0022[message:field-node-ref:url]\\u0022\\u003E[message:field-node-ref:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "[message:field-node-ref:node-teaser]",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:field-node-ref:node-teaser]\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['multisite_content_update'] = entity_import('message_type', '{
    "name" : "multisite_content_update",
    "description" : "content update",
    "argument_keys" : [ "!user-picture" ],
    "argument" : [],
    "category" : "message_type",
    "data" : { "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" } },
    "language" : "en",
    "arguments" : [],
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E \\u0022\\u003Ca title=\\u0022Insert this token into your form\\u0022\\u003E[message:field-node-ref:title]\\u003C\\/a\\u003E\\u0022 has been updated by \\u003Ca title=\\u0022Insert this token into your form\\u0022\\u003E[message:field-node-ref:author]\\u003C\\/a\\u003E\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E \\u0022\\u003Ca title=\\u0022Insert this token into your form\\u0022\\u003E[message:field-node-ref:title]\\u003C\\/a\\u003E\\u0022 has been updated by \\u003Ca title=\\u0022Insert this token into your form\\u0022\\u003E[message:field-node-ref:author]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n"
        }
      ],
      "und" : [
        {
          "value" : "[message:user:picture]",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:picture]\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Ca href=\\u0022[message:user:url]\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E created \\u003Ca href=\\u0022[message:field-node-ref:url]\\u0022\\u003E[message:field-node-ref:title]\\u003C\\/a\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Ca href=\\u0022[message:user:url]\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E created \\u003Ca href=\\u0022[message:field-node-ref:url]\\u0022\\u003E[message:field-node-ref:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "[message:field-node-ref:node-teaser]",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:field-node-ref:node-teaser]\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['multisite_create_comment'] = entity_import('message_type', '{
    "name" : "multisite_create_comment",
    "description" : "new comment",
    "argument_keys" : [ "!teaser" ],
    "argument" : [],
    "category" : "message_type",
    "data" : { "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" } },
    "language" : "en",
    "arguments" : null,
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003EA new comment has been posted on \\u0022\\u003Ca title=\\u0022Insert this token into your form\\u0022\\u003E[message:field-node-ref:title]\\u003C\\/a\\u003E\\u0022 by \\u003Ca title=\\u0022Insert this token into your form\\u0022\\u003E[message:field-node-ref:author]\\u003C\\/a\\u003E\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EA new comment has been posted on \\u0022\\u003Ca title=\\u0022Insert this token into your form\\u0022\\u003E[message:field-node-ref:title]\\u003C\\/a\\u003E\\u0022 by \\u003Ca title=\\u0022Insert this token into your form\\u0022\\u003E[message:field-node-ref:author]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n"
        }
      ],
      "und" : [
        {
          "value" : "[message:user:picture]",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:picture]\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Ca href=\\u0022[message:user:url]\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E \\u003Ca href=\\u0022[message:field-comment-ref:url]\\u0022\\u003Ecommented\\u003C\\/a\\u003E on [message:field-node-ref:title]",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Ca href=\\u0022[message:user:url]\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E \\u003Ca href=\\u0022[message:field-comment-ref:url]\\u0022\\u003Ecommented\\u003C\\/a\\u003E on [message:field-node-ref:title]\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "[message:field-comment-ref:comment-teaser]",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:field-comment-ref:comment-teaser]\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['multisite_create_node'] = entity_import('message_type', '{
    "name" : "multisite_create_node",
    "description" : "new content creation",
    "argument_keys" : [ "!user-picture" ],
    "argument" : [],
    "category" : "message_type",
    "data" : { "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" } },
    "language" : "en",
    "arguments" : [],
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003EA new \\u003Ca title=\\u0022Insert this token into your form\\u0022\\u003E[message:field-node-ref:content-type]\\u003C\\/a\\u003E \\u0022\\u003Ca title=\\u0022Insert this token into your form\\u0022\\u003E[message:field-node-ref:title]\\u003C\\/a\\u003E\\u0022 has been created by \\u003Ca title=\\u0022Insert this token into your form\\u0022\\u003E[message:field-node-ref:author]\\u003C\\/a\\u003E\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EA new \\u003Ca title=\\u0022Insert this token into your form\\u0022\\u003E[message:field-node-ref:content-type]\\u003C\\/a\\u003E \\u0022\\u003Ca title=\\u0022Insert this token into your form\\u0022\\u003E[message:field-node-ref:title]\\u003C\\/a\\u003E\\u0022 has been created by \\u003Ca title=\\u0022Insert this token into your form\\u0022\\u003E[message:field-node-ref:author]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n"
        }
      ],
      "und" : [
        {
          "value" : "[message:user:picture]",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:picture]\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Ca href=\\u0022[message:user:url]\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E created \\u003Ca href=\\u0022[message:field-node-ref:url]\\u0022\\u003E[message:field-node-ref:title]\\u003C\\/a\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Ca href=\\u0022[message:user:url]\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E created \\u003Ca href=\\u0022[message:field-node-ref:url]\\u0022\\u003E[message:field-node-ref:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "[message:field-node-ref:node-teaser]",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:field-node-ref:node-teaser]\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}