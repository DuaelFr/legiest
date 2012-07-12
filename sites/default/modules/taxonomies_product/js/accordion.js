(function($) {

  LegiestAccordion = window.LegiestAccordion || {};
  LegiestAccordion.menus = null;

  /**
   * Event click on list items.
   * 
   * Opens the accordion or go to the link.
   */
  LegiestAccordion.click = function() {
	// If already open do nothing (so go to the link)
    if (!$(this).hasClass('open')) {
      var sub = $(this).find('.category-submenu-lvl2, .category-submenu-lvl3, .category-submenu-lvl4');
      if (sub.length > 1 || sub.html().trim() != '') {
        // Close menus
        $(this).siblings('.open:not(.active)').removeClass('open')
               .children('.views-field-view').slideUp();
        // Open selected menu
        $(this).children('.views-field-view').slideDown()
               .end().addClass('open');
        // Avoid bubling
        return false;        
      }
    }
  };

  /**
   * Entry point.
   * 
   * Set up classes and events.
   */
  LegiestAccordion.init = function() {
	// Find menus
	LegiestAccordion.menus = $('.category-menu > .view-content > .item-list > ul');
	// Enable active trail
	LegiestAccordion.menus.find('a.active').parents('li').addClass('active');
	// Hide submenus except active ones
	LegiestAccordion.menus.find(':not(.active) > .views-field-view').hide();
	// Register click event
	LegiestAccordion.menus.find('li').click(LegiestAccordion.click);
  };
  $(LegiestAccordion.init);

})(jQuery);
