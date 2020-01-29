// lang:CwC

#pragma once

#include "object.h"
#include "string.h"

/**
 * An Map represents an array of key/value pairs.
 *
 * The Map does not take ownership over any of the key and value Objects.
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
     * Destructs a Map.
     */
    virtual ~Map() {
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
    Object *get(Object *key) {
        // TODO: Method stub.
        return 0;
    }

    /**
     * Puts key/value pair in the map and returns
     * null pointer if the key didn't previously exist. If the key already exists,
     * replaces the previous value with the given and returns the replaced value.
     */
    Object *put(Object *key, Object *value) {
        // TODO: Method stub.
        return 0;
    }

    /**
     * Remove the key/value pair at given key from the map and return the removed
     * value, or nullptr if the key was not in the map.
     */
    Object *remove(Object *key) {
        // TODO: Method stub.
        return 0;
    }

    /**
     * Returns true if key is already in the map.
     */
    bool contains_key(Object *key) {
        // TODO: Method stub.
        return false;
    }

    /**
     * Puts all from other into this. If any keys are replaced, returns those
     * key/value pairs in a new Map. If no keys are replaced, returns a null
     * pointer.
     */
    Map *put_all(Map *other) {
        // TODO: Method stub.
        return 0;
    }
    
    /**
     * Returns true if the given Object is a Map equal to this Map.
     * Two Maps are equal if they have all of the same keys
     * and all of the same mappings to values.
     */
    bool equals(Object *const obj) {
        // TODO: Method stub.
        return false;
    }
    
    /**
     * Returns this Map's hash value.
     */
    size_t hash() {
        // TODO: Method stub
        return 0;
    }
};

/**
 * Represents a map with only strings as the key and value.
 */
class StrToStrMap : public Map {
public:
    /**
     * Constructs a new StrToStrMap.
     */
    StrToStrMap() {
        // TODO: Method stub.
    }

    /**
     * Destructs a StrToStrMap.
     */
    virtual ~StrToStrMap() {
        //TODO: Method stub.
    }

    /**
     * Returns value at given key.
     */
    String *get(String *key) {
        // TODO: Method stub.
        return 0;
    }

    /**
     * Puts key/value pair in the map and returns null pointer if the key didn't
     * previously exist. If the key already exists, replaces the previous value
     * with the given and returns the replaced value.
     */
    String *put(String *key, String *value) {
        // TODO: Method stub.
        return 0;
    }

    /**
     * Remove the key/value pair at given key from the map and return the removed
     * value, or nullptr if the key was not in the map.
     */
    String *remove(String *key) {
        // TODO: Method stub.
        return 0;
    }

    /**
     * Returns true if key is already in the map.
     */
    bool contains_key(String *key) {
        // TODO: Method stub.
        return false;
    }

    /**
     * Puts all from other into this. If any keys are replaced, returns those
     * key/value pairs in a new Map. If no keys are replaced, returns a null
     * pointer.
     */
    StrToStrMap *put_all(StrToStrMap *other) {
        // TODO: Method stub.
        return 0;
    }
};

