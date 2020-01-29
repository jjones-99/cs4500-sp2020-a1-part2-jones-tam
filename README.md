# Assignment 1: Part 2

## Designing a Map API for CwC

---

#### The Object class and the String class.

These are the standardized classes created by @chasebish, from https://github.com/chasebish/cwc_object_string. They are used to allow for a uniform API amongst spec pairs for all teams in
 CS4500.
 
See that README.md for more information.

---

#### The Map class.

Because we don't have any way of using generics or similar strategies in CwC, the Map class
 simply keeps track of Objects. This provides functionality of a map, probably through the Object class' `hash()` and `equals()` methods, using Objects as both keys and values. Note these aren't virtual methods. This Map class does not take ownership over any of the Objects added to it as keys or values.

_This provides the functionality of a String->Object Map._

---

#### The StrtoStrMap class.

The StrtoStrMap class inherits from Map class, and represents a map where both keys and values are Strings. Because we create new methods of the same names (e.g., StrtoStrMap has `String* get(String* key)` and Map has `Object* get(Object* key)`), Map's implementations are hidden from StrtoStrMap. This means we'll be able to use similar method names with the types we'd expect, though it does mean we can't use dynamic dispatch on these methods. These methods probably just delegate to Map's methods, but - because of the invariant that all keys and values are put as Strings - can cast values to Strings before returning them.

_This provides the functionality of a String->String Map._

---

# To Run Tests.

To download Google Test and create a Makefile, run:

```cmake .```

Then run:

```make```

That will create an executable titled `mapTests`. Run it with:

```./mapTests```