bricks
======

An exploratory way to programmatically create user-configurable blocks in Drupal via code.

# Usage

Examine the MYMODULE example module to learn how this works. Or duplicate and modify the example module.

# Reason

In Drupal, blocks are not easily exportable, and they can't be included in Features. One approach is to create blocks through code, so that the code can be managed along with the rest of the code-base.

The system provided by this module allows you to create defaults in code, allows those defaults to be over-ridden in a standardized way, and finally, reverted back to the default.

It also provides a few helper functions to simplify the most common use cases.