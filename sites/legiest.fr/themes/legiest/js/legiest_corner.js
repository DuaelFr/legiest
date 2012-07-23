/**
 * Jquery Corner implementation for Legiest website,
 * following instructions at http://drupal.org/node/1030144
 */
(function ($) {
  Drupal.behaviors.legiest = {
    attach: function(context, settings) {
      // list every element that you would like to adorn with corners below
      $("#block-search-form").corner("tl tr bl br 5px");
      $("#block-views-categories-block-all").corner("tl tr 5px");
      $("#block-boxes-contact-legiest").corner("bl br 5px");
      $("#block-views-news-block-1").corner("tl tr bl br 5px");
      $("#region-content").corner("tl tr bl br 5px");
      $("#views_slideshow_cycle_main_news-block .views-field-field-picture img").corner("bl br 10px");
      $("#views_slideshow_cycle_main_news-block .views-field-body").corner("bl br 10px");
    }
  }
})(jQuery);
