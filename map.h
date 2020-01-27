// lang:CwC

#pragma once

#include "object.h"
#include "string.h"

/**
 * An Map represents an array of key/value pairs.
 */
class Map : public Object {
 public:
  /**
   * Constructs a new Map.
   */
  Map() {
    // TODO: Method stub.
  }

  /**
   * Returns how many key/value pairs in the map.
   */
  int size() {
    // TODO: Method stub.
    return 0;
  }

  /**
   * Returns value at given key.
   */
  Object* get(Object* key) {
    // TODO: Method stub.
    return 0;
  }

  /**
   * Puts key/value pair in the map and returns
   * null pointer if the key didn't previously exist. If the key already exists,
   * replaces the previous value with the given and returns the replaced value.
   */
  Object* put(Object* key, Object* value) {
    // TODO: Method stub.
    return 0;
  }

  /**
   * Remove the key/value pair at given key from the map and return the removed
   * value, or nullptr if the key was not in the map.
   */
  Object* remove(Object* key) {
    // TODO: Method stub.
    return 0;
  }

  /**
   * Returns true if key is already in the map.
   */
  bool contains_key(Object* key) {
    // TODO: Method stub.
    return false;
  }

  /**
   * Puts all from other into this. If any keys are replaced, returns those
   * key/value pairs in a new Map. If no keys are replaced, returns a null
   * pointer.
   */
  Map* put_all(Map* other) {
    // TODO: Method stub.
    return 0;
  }
};