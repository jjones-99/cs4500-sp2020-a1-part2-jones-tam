// lang::CwC

#pragma once

/**
 * An Object is a basic type. Serves as the root class.
 */
class Object {
 public:
  /**
   * Constructs a new Object.
   */
  Object() {
    // TODO: Method stub.
  }

  /**
   * Prints the Object.
   */
  virtual void print() {
    // TODO: Method stub.
  }

  /**
   * Returns whether given Object is equal to this Object.
   */
  virtual bool equals(Object* o) {
    // TODO: Method stub.
    return false;
  }

  /**
   * Returns the hashcode for this Object.
   */
  virtual long hash() {
    // TODO: Method stub.
    return 0;
  }
};