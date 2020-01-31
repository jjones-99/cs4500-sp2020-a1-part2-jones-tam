//lang::CwC
/**
 * Standardized spec for String for use in CS4500 from Chase Bishop.
 *
 * @author spec designed by github.com/chasebish
 */

#pragma once

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "object.h"

/**
 * An immutable String class representing a char*
 */
class String : public Object {
public:
    /** CONSTRUCTORS & DESTRUCTORS **/

    /* Creates a String copying s */
    String(const char *s) {
        // TODO: Method stub
    }

    /* Copies a String copying the value from s */
    String(String *const s) {
        // TODO: Method stub
    }

    /* Clears String from memory */
    ~String() {
        // TODO: Method stub
    }


    /** INHERITED METHODS **/

    /* Inherited from Object, generates a hash for a String */
    size_t hash() {
        // TODO: Method stub
        return 0;
    }

    /* Inherited from Object, checks equality between an String and an Object */
    bool equals(Object *obj) {
        // TODO: Method stub
        return false;
    }


    /** STRING METHODS **/

    /** Compares strings based on alphabetical order
     * < 0 -> this String is less than String s
     * = 0 -> this String is equal to String s
     * > 0 -> this String is greater than String s
     */
    int cmp(String *const s) {
        // TODO: Method stub
        return 0;
    }

    /* Creates a new String by combining two existing Strings */
    String *concat(String *const s) {
        // TODO: Method stub
        return nullptr;
    }

    /* Returns the current length of the String */
    size_t size() {
        // TODO: Method stub
        return 0;
    }
};
