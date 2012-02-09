(function ($) {

Drupal.thumbwhere_activity = {};
Drupal.thumbwhere_activity.active = 1;

Drupal.behaviors.thumbwhere_activity = {
  attach: function (context) {
    setTimeout("Drupal.thumbwhere_activity.refresh()", 5000);
    
    $('#devel-debug-log-messages-table').click(function () {
      Drupal.thumbwhere_activity.active = 0;
    });
  }
};

Drupal.thumbwhere_activity.refresh = function() {
  if (Drupal.thumbwhere_activity.active == 1) {
    $.ajax({
      url: '/devel-debug-log/callback',
      dataType: 'json',
      success: function(data) {
        $('#devel-debug-log-messages-table').html(data['content']);
      }
    });
  
    setTimeout("Drupal.thumbwhere_activity.refresh()", 5000);
  }
}

})(jQuery);
