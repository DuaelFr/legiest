<?php 


class LegiestSubscriptionEntity extends Entity {

  public $subscription_id;

  // database fields
  public $uid, $product_id, $status;
  public $created, $changed, $revoked, $ending;

  // derived fields
  protected $owner, $product;

  /**
   * Overridden __construct()
   *  - set fixed entity type
   *  - initialize fields
   */
  public function __construct($values = array(), $entityType = NULL) {
    parent::__construct($values, LEGIEST_SUBSCRIPTION_ENTITY_NAME);
  }

  // -----------------------------------------------------------------------
  // Base Class overridden methods

  /**
   * Implements save()
   */
  public function save() {
    return parent::save();
  }

  /**
   * Implements buildContent()
   *  - add custom fields to the output.
   */
  public function buildContent($view_mode = 'full', $langcode = NULL) {
    return $this->get_controller()->buildContent($this, $view_mode, $langcode, $content);
  }

  /**
   * Specifies the default label, which is picked up by label() by default.
   */
  protected function defaultLabel() {
    $parts = array();
    $product = $this->get_product();
    $owner = $this->get_owner();
    if (!empty($product)) {
      $parts[] = $product->title;
    }
    if (!empty($owner->name)) {
      $parts[] = ' ' . t('owned by ') . $owner->name;
    }

    if (!empty($parts)) {
      return implode(' ', $parts);
    }

    return $this->entityInfo['label'] . ' ' . $this->internalIdentifier();
  }

  /**
   * Specifies the default uri, which is picked up by uri() by default.
   */
  protected function defaultURI() {
    return array(
      'path' => 'user/' . $this->get_owner()->uid . '/subscriptions/' . $this->subscription_id . '/view',
    );
  }


  // -----------------------------------------------------------------------
  // Class Methods

  /**
   * Access callback
   */
  public function access($op = 'view', $account = NULL) {
    return entity_access($op, $this->entityType, $this, $account);
  }

  /**
   * Invoke hook
   */
  public function invoke($hook) {
    $this->get_controller()->invoke($hook, $this);
    return $this;
  }

  /**
   * Returns true if license is in the allowed state
   */
  public function is_allowed() {
    return $this->get_state() == 'allowed';
  }

  /**
   * Returns true if license is in the active status
   */
  public function is_active() {
    return $this->status == 'active';
  }

  /**
   * ALLOW - sets state to 'allowed' with the default status
   */
  public function allow() {
    if (!$this->is_allowed()) {
      $this->set_state('allowed');
    }
    return $this;
  }

  /**
   * DENY - sets state to 'denied' with the default status
   */
  public function deny() {
    if ($this->is_allowed()) {
      $this->set_state('denied');
    }
    return $this;
  }


  // -----------------------------------------------------------------------
  // Properties

  /**
   * Entity controller
   *  - Read only
   */
  public function get_controller() {
    return entity_get_controller($this->entityType);
  }

  /**
   * Wrapper
   *  - Read only
   */
  public function get_wrapper() {
    return entity_metadata_wrapper(COMMERCE_FILE_LICENSE_ENTITY_NAME, $this);
  }

  /**
   * Bundle
   *  - Read only
   */
  public function get_bundle() {
    if (!isset($this->bundle)) {
      // If no bundle key provided, then we assume a single bundle, named after the
      // entity type.
      $this->bundle = !empty($this->bundleKey) ? $this->{$this->bundleKey} : $this->entityType;
    }
    return $this->bundle;
  }

  /**
   * Status
   *  - Read / Write
   */
  public function set_status($value) {
    $statuses = commerce_file_license_statuses();
    if (!isset($statuses[$value])) {
      throw new Exception("Invalid Status: Attempted to set license status to an invalid value of '$value'.");
    }

    // update status
    $this->status = $value;

    // update state to corresponding state of status
    $this->set_state($statuses[$value]['state']);

    return $this;
  }

  /**
   * State
   *  - Read / Write
   */
  public function get_state() {
    if (!isset($this->state)) {
      $state = FALSE;
      if (isset($this->status)) {
        $status = commerce_file_license_status_load($this->status);
        $state = $status['state'];
      }

      $this->state = $state;
    }

    return $this->state;
  }
  /**
   * Set state
   * @param $value
   *   State name
   */
  public function set_state($value) {
    $state = commerce_file_license_state_load($value);
    if (empty($state)) {
      throw new Exception("Invalid State: Attempted to set license state to an invalid value of '$value'.");
    }
    if (empty($state['default_status'])) {
      throw new Exception("Invalid State: Attempted to set license state to '$value' which does not define a default status.");
    }

    // update state
    $original_state = $this->get_state();
    $this->state = $state['name'];

    // only update status if we're changing states
    if ($original_state != $state['name']) {
      $this->status = $state['default_status'];
    }

    return $this;
  }


  /**
   * uid
   *  - Read / Write
   */
  public function set_uid($value) {
    if ($this->uid != $value) {
      $this->uid = $value;
      unset($this->owner);
    }
  }

  /**
   * Owner
   *  - Read only
   */
  public function get_owner() {
    if (!isset($this->owner)) {
      $this->owner = NULL;
      if (isset($this->uid)) {
        $this->owner = user_load($this->uid);
      }
    }
    return $this->owner;
  }

  /**
   * File
   *  - Read / Write
   */
  public function get_product() {
    if (!isset($this->product)) {
      $this->product = commerce_product_load($this->product_id);
    }
    return $this->product;
  }

  public function set_product($product = array()) {
    if (!empty($product)) {
      $this->product = $product;
      $this->product_id = $product->product_id;
      return TRUE;
    }

    return FALSE;
  }

  // -----------------------------------------------------------------------
  // Magic Methods

  /**
   * Get / Set
   *  - method is preferred with lazy fallback to object property
   */
  public function __get($name) {
    $method = "get_$name";
    if (method_exists($this, $method)) {
      return $this->{$method}();
    }

    // allow lazy get
    if (isset($this->{$name})) {
      return $this->{$name};
    }
    return NULL;
  }

  public function __set($name, $value) {
    $method = "set_$name";
    if (method_exists($this, $method)) {
      $this->{$method}($value);
    }
    elseif (!method_exists($this, "get_$name")) {
      // allow lazy setting for non read only properties
      $this->{$name} = $value;
    }
  }

  public function __isset($name) {
    $value = $this->__get($name);
    return isset($value);
  }

  public function __unset($name) {
    unset($this->{$name});
  }

}
