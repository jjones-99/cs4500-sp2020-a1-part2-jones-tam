//lang::CwC
/**
 * Standardized spec for Object for use in CS4500 from Chase Bishop.
 *
 * @author spec designed by github.com/chasebish
 */

#pragma once

#include <stdlib.h>

/**
 * A class that represents the top of the object hierarchy.
 */
class Object {
public:
    /** CONSTRUCTORS & DESTRUCTORS **/

    /* Default Object constructor */
    Object() {
        // TODO: Method stub
    }

    /* Default Object destructor, to be overriden by subclasses */
    virtual ~Object() {
        // TODO: Method stub
    }


    /** VIRTUAL METHODS **/

    /* Returns whether two objects are equal, to be overriden by subclasses */
    virtual bool equals(Object *const obj) {
        // TODO: Method stub
        return false;
    }

    /* Returns an object's hash value. Identical objects should have identical hashes */
    virtual size_t hash() {
        // TODO: Method stub
        return 0;
    }
};