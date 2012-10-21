(function($) {

ucLegiestCheckout = window.ucLegiestCheckout || {};

ucLegiestCheckout.panels = {
  cart: {
    title: 'Panier et coupons',
    elements: ['cart-pane', 'coupon-pane', 'uc-legiest-control-next'],
    visited: false,
    error: false
  },
  customer: {
    title: 'Compte client',
    elements: ['customer-pane', 'uc-legiest-control-next', 'uc-legiest-control-prev'],
    visited: false,
    error: false
  },
  delivery: {
    title: 'Adresse de livraison',
    elements: ['delivery-pane', 'uc-legiest-control-next', 'uc-legiest-control-prev'],
    visited: false,
    error: false
  },
  billing: {
    title: 'Adresse de facturation',
    elements: ['billing-pane', 'uc-legiest-control-next', 'uc-legiest-control-prev'],
    visited: false,
    error: false
  },
  shipping: {
    title: 'Mode de livraison',
    elements: ['quotes-pane', 'uc-legiest-control-next', 'uc-legiest-control-prev'],
    visited: false,
    error: false
  },
  payment: {
    title: 'Mode de paiement',
    elements: ['payment-pane', 'uc-legiest-control-next', 'uc-legiest-control-prev'],
    visited: false,
    error: false
  },
  final: {
    title: 'Finalisation',
    elements: ['uc_termsofservice_agreement_checkout-pane', 'comments-pane', 'edit-actions', 'uc-legiest-control-prev'],
    visited: false,
    error: false
  }
};
ucLegiestCheckout.activePanel = 'cart';
ucLegiestCheckout.context = null;
ucLegiestCheckout.duration = 500;
ucLegiestCheckout.initialized = false;

/**
 * Hide a panel's components.
 */
ucLegiestCheckout.hidePanel = function(key) {
  var context = ucLegiestCheckout.context;
  // Hide container
  context.fadeOut(ucLegiestCheckout.duration, function() {
    // Hide components
    $.each(ucLegiestCheckout.panels[key].elements, function(key, item) {
      $('#' + item, context).hide();
    });
  });
  // Desactivate step
  $('.step-' + key).removeClass('active');
};

/**
 * Hide all panels' components.
 */
ucLegiestCheckout.hideAllPanels = function() {
  var context = ucLegiestCheckout.context;
  $.each(ucLegiestCheckout.panels, function(key, item) {
    ucLegiestCheckout.hidePanel(key);
  });
};

/**
 * Show a panel's components.
 */
ucLegiestCheckout.showPanel = function(key) {
  var context = ucLegiestCheckout.context;
  // Activate step
  $('.step-' + key).addClass('active').addClass('visited');
  ucLegiestCheckout.panels[key].visited = true;
  // Wait for another animation to end
  if (context.queue()[0] == "inprogress") {
    setTimeout(function() { ucLegiestCheckout.showPanel(key); }, 100);
    return;
  }
  // Show components
  $.each(ucLegiestCheckout.panels[key].elements, function(key, item) {
    $('#' + item, context).show();
  });
  // Show container 
  $(context).fadeIn(ucLegiestCheckout.duration);
};

/**
 * Show all panels' components.
 */
ucLegiestCheckout.showAllPanels = function() {
  var context = ucLegiestCheckout.context;
  $.each(ucLegiestCheckout.panels, function(key, item) {
    ucLegiestCheckout.showPanel(key);
  });
};

/**
 * Hide all elements and switch to the first panel.
 * If there is an error message, enable all panels, mark steps in error and 
 * show the first error panel.
 */
ucLegiestCheckout.initPanels = function() {
  var context = ucLegiestCheckout.context,
      forceEnable = $('#messages .messages.error').length > 0;

  $.each(ucLegiestCheckout.panels, function(key, item) {
    if (forceEnable) {
      item.visited = true;
      $('.step-' + key).addClass('visited');
      $.each(item.elements, function(elementKey, element) {
        if ($('.error:not(.messages)', $('#' + element, context)).length > 0) {
          item.error = true;
          $('.step-' + key).addClass('error');
        }
      });
    }
    ucLegiestCheckout.hidePanel(key);
  });
}

/**
 * Swith to the first panel including errors or in the first of the list.
 */
ucLegiestCheckout.switchToFirstStep = function() {
  $.each(ucLegiestCheckout.panels, function(key, item) {
    if (item.error) {
      ucLegiestCheckout.switchPanel(key);
      return false;
    }
  });
  ucLegiestCheckout.switchPanel(ucLegiestCheckout.activePanel);
}

/**
 * Switch the active panel.
 */
ucLegiestCheckout.switchPanel = function(key) {
  // Hide old elements
  ucLegiestCheckout.hidePanel(ucLegiestCheckout.activePanel);

  // Change active panel
  ucLegiestCheckout.activePanel = key;

  // Show new elements
  ucLegiestCheckout.showPanel(ucLegiestCheckout.activePanel);
};

/**
 * Callback used when clicking on a next button.
 */
ucLegiestCheckout.clickNext = function(e) {
  e.preventDefault();

  var getNext = false;

  $.each(ucLegiestCheckout.panels, function(key, item) {
    if (getNext) {
      ucLegiestCheckout.switchPanel(key);
      return false;
    }
    else if (key == ucLegiestCheckout.activePanel) {
      getNext = true;
    }
  });
};

/**
 * Callback used when clicking on a previous button.
 */
ucLegiestCheckout.clickPrev = function(e) {
  e.preventDefault();

  var previous = false;

  $.each(ucLegiestCheckout.panels, function(key, item) {
    if (key == ucLegiestCheckout.activePanel) {
      ucLegiestCheckout.switchPanel(previous == false ? key : previous);
      return false;
    }
    previous = key;
  });
};

/**
 * Callback used when clicking on a step in the block.
 */
ucLegiestCheckout.clickStep = function(e) {
  e.preventDefault();

  var key = $(this).data('panel'),
      panel = ucLegiestCheckout.panels[key];

  if (key != ucLegiestCheckout.activePanel && panel.visited) {
    ucLegiestCheckout.switchPanel(key);
  }
};

/**
 * Build and attach the steps' block.
 */
ucLegiestCheckout.buildBlock = function() {
  var sidebar = $('.region-sidebar-first-inner'),
      block = $('<section>').addClass('block').addClass('block-uc-legiest'),
      inner = $('<div>').addClass('block-inner').addClass('clearfix')
      title = $('<h2>').addClass('block-title').text('Etapes de la commande'),
      content = $('<div>').addClass('content').addClass('clearfix'),
      steps = $('<ol>').addClass('step-list'),
      step = null;

  // Build HTML structure
  sidebar.prepend(block.append(inner.append(title).append(content.append(steps))));

  // For each defined panels we add an item in the steps list
  $.each(ucLegiestCheckout.panels, function(key, item) {
    step = $('<li>').addClass('step').addClass('step-' + key).text(item.title);
    if (key == ucLegiestCheckout.activePanel) {
      step.addClass('active');
      item.visited = true;
    }
    step.data('panel', key);
    step.click(ucLegiestCheckout.clickStep);

    steps.append(step);
  });

  return block;
};

/**
 * Add two buttons to navigate through the steps.
 */
ucLegiestCheckout.buildControls = function() {
  var actions = $('#edit-actions', ucLegiestCheckout.context),
      container = $('<div>').addClass('uc-legiest-checkout-controls'),
      prevBtn = $('<input>'),
      nextBtn = $('<input>');

  prevBtn.attr('id', 'uc-legiest-control-prev').attr('type', 'submit').attr('name', 'op')
         .addClass('form-submit').addClass('uc-legiest-control').addClass('uc-legiest-control-prev')
         .val('Etape précédente')
         .click(ucLegiestCheckout.clickPrev);
  nextBtn.attr('id', 'uc-legiest-control-next').attr('type', 'submit').attr('name', 'op')
         .addClass('form-submit').addClass('uc-legiest-control').addClass('uc-legiest-control-next')
         .val('Etape suivante')
         .click(ucLegiestCheckout.clickNext);

  actions.before(container.append(prevBtn).append(nextBtn));
}

/**
 * Filter panels to removed useless ones.
 */
ucLegiestCheckout.filterPanels = function() {
  var context = ucLegiestCheckout.context,
      found;

  $.each(ucLegiestCheckout.panels, function(key, item) {
    found = false;
    $.each(item.elements, function(key, item) {
      if ($('#' + item, context).length > 0) {
        found = true;
      }
    });
    if (!found) {
      delete ucLegiestCheckout.panels[key];
    }
  });

  return ucLegiestCheckout.panels;
};

/**
 * Transform the common checkout process in a fake multipart form.
 */
ucLegiestCheckout.attachBehavior = function (context, settings) {
  if ($('.uc-cart-checkout-form').length > 0) {
    // First run only
    if (!ucLegiestCheckout.initialized) {
      ucLegiestCheckout.context = $('.uc-cart-checkout-form', context);

      ucLegiestCheckout.filterPanels();
      ucLegiestCheckout.buildBlock();
      ucLegiestCheckout.buildControls();

      ucLegiestCheckout.initPanels();
      ucLegiestCheckout.switchToFirstStep();

      ucLegiestCheckout.initialized = true;
    }
    else {
      ucLegiestCheckout.initPanels();
      ucLegiestCheckout.switchPanel(ucLegiestCheckout.activePanel);
    }
  }
};

/**
 * 
 */
Drupal.behaviors.ucLegiestCheckout = {
  attach: ucLegiestCheckout.attachBehavior
};

})(jQuery);
