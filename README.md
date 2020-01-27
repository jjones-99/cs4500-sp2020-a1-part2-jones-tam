# Assignment 1: Part 2

## Designing a Map API for CwC

---

#### The Object class.

The Object class is a really simple "root" class. It provides virtual stubs for common methods like `hash()`, `equals(Object)`, and `print()`, so that dynamic dispatch can be used later, if desired.

---

#### The String class.

The String class is just the usual. It has a `const` `char` array representing its characters, and an `int` representing its length. These are 'private', so the class provides getters. It overrides the functionality in Object as necessary.

---

#### The Map class.

Because we don't have any way of using generics or similar strategies in CwC, the Map class simply keeps track of Objects. This provides functionality of a map, probably through the Object class' `hash()` and `equals()` methods, using Objects as both keys and values.
