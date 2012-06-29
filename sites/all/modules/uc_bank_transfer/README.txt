-- INSTALLATION - INVOICE TEMPLATE --

To display the bank details on the invoices you need to do the following:
- select the customer-bank_transfer template for on-site invoices:
  -> Administer/Store/Configuration/Order settings
     -> under "Customer settings" choose "customer-bank_transfer" as On-site invoice template
- select the customer-bank_transfer template for email invoices:
  -> Administer/Store/Configuration/Checkout settings/Rules
    -> edit "E-mail customer checkout notification"
      -> edit Action "Email an order invoice"
         -> under "INVOICE TEMPLATE" choose "customer-bank_transfer" as E-mail invoice template

-- MULTILINGUAL SITES --

Please note the difference between i18n variables and i18n constants !

constants: you can translate them in
-> **/admin/config/regional/translate/translate

variables:
-> first you need to enable the variables you would like to translate
  -> **/admin/config/regional/i18n/variable
-> then you have to translate them on the settings page for each language directly
  -> en/admin/store/settings/payment/edit/methods
  -> de/admin/store/settings/payment/edit/methods
  -> fr/admin/store/settings/payment/edit/methods
  -> es/admin/store/settings/payment/edit/methods
  -> etc.
