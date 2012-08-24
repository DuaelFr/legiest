
Taxonomy access fix
====

This module

* adds 1 per mission per vocabulary: `add terms in VOCABULARY_ID`
* changes the way vocabulary specific permissions are handled
* changes the admin pages accesss callback to a custom access check
* alters to vocabularies overview table to show only what you have access
  to edit or delete

The module does what native Taxonomy should have done: check and
define Taxonomy permissions better.

**NOTE:** A module can't add permissions to another module, so the extra
"add terms" permissions are located under "Taxonomy access fix" and not
under "Taxonomy".
