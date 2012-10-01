bricks
======

An exploratory way to programmatically create user-configurable blocks in Drupal via code.

# Usage

In your module, call this function:

bricks_create('blockID', array('subject' => 'This is a block', 'content' => 'Default block content'));

# Reason

In Drupal, blocks are not easily exportable, and they can't be included in Features. One approach is to create blocks through code, so that the code can be managed along with the rest of the code-base. However, this leaves block content un-editable by the user.

# Approach

The approach I'm toying with is creating a set of functions which store default content in code, but allow this content to be overridden with Drupal variables (which can be code-ified using StrongArm and Features). This preserves the flexibility of user-configuration, but allows their content to exist and be processed through the code-base.

# Disclaimer

This is not a particularly great method. A more Drupal-like approach would be to wrap this functionality within a hook function. That will be my next thing to implement.