// lang::CwC

#include <gtest/gtest.h>
#include <math.h>
#include <stdio.h>

#include "map.h"
#include "object.h"
#include "string.h"

void ERR(const char *msg) { fprintf(stderr, "%s\n", msg); }

void OUT(const char *msg) { printf("%s\n", msg); }

#define t_true(a) ASSERT_EQ((a), true);
#define t_false(a) ASSERT_EQ((a), false);
#define t_exit_zero(a) ASSERT_EXIT(a(), ::testing::ExitedWithCode(0), ".*");

// tests for Map from Object to Object [get, put, contains_key, size, remove]
void testObjToObjMap1() {
  Map *smap = new Map();
  Object *o1 = new Object();
  Object *o2 = new Object();
  Object *o3 = new Object();
  Object *o4 = new Object();
  t_true(smap->size() == 0);         // initial length of map is zero
  t_true(smap->put(o1, o2) == 0);    // add one key/value pair return 0
  t_true(smap->contains_key(o1));    // contains key added
  t_false(smap->contains_key(o2));   // does not contain a non-added key
  t_true(smap->get(o1)->equals(o2)); // key returns matching value
  t_true(smap->size() == 1);         // length is now 1
  t_true(smap->put(o3, o4) == 0);    // add a second pair
  t_true(smap->contains_key(o3));    // second key is in map
  t_true(smap->get(o3)->equals(o4)); // get second value
  t_true(smap->size() == 2);         // length is now 2
  t_true(
          smap->put(o1, o3)->equals(o2)); // replace first value, return first value
  t_true(smap->get(o1)->equals(o3));  // new value now exists at first key
  t_true(smap->remove(o1)->equals(o3)); // remove returns the value at the key
  t_true(smap->size() == 1); // and decreases the size by 1 (if the key was in the map)
  t_true(smap->remove(o1) == nullptr); // and returns nullptr for keys not in the map

  delete smap;
  delete o1;
  delete o2;
  delete o3;
  delete o4;

  exit(0);
}

TEST(Map, testObjToObjMap1
) {
t_exit_zero(testObjToObjMap1) }

// tests for Map from Object to Object [put_all]
void testObjToObjMap2() {
  Map * a = new Map();
  Map * b = new Map();
  Map * c = new Map();
  Object *o1 = new Object();
  Object *o2 = new Object();
  Object *o3 = new Object();
  a->put(o1, o2);             // puts key/val pair into a
  c->put(o1, o2);             // puts same key/val pair into c
  t_true(b->put_all(a) == 0); // put_all of a into b returns 0
  a->put(o1, o3);             // replaces value in a
  t_true(b->put_all(a)->equals(
          c)); // put_all of updated a into b returns map with same pair as c

  delete a;
  delete b;
  delete c;
  delete o1;
  delete o2;
  delete o3;

  exit(0);
}

TEST(Map, testObjToObjMap2
) {
t_exit_zero(testObjToObjMap2) }

// tests for Map from String to Object [get, put, contains_key, len]
void testStrToObjMap1() {
  Map * smap = new Map();
  String *s = new String("key");
  String *t = new String("another key");
  String *u = new String("yet another one");
  Object *o1 = new Object();
  Object *o2 = new Object();
  t_true(smap->size() == 0);        // initial length of map is zero
  t_true(smap->put(s, o1) == 0);    // add one key/value pair return 0
  t_true(smap->contains_key(s));    // contains key added
  t_false(smap->contains_key(u));   // does not contain a non-added key
  t_true(smap->get(s)->equals(o1)); // key returns matching value
  t_true(smap->size() == 1);        // length is now 1
  t_true(smap->put(t, o2) == 0);    // add a second pair
  t_true(smap->contains_key(t));    // second key is in map
  t_true(smap->get(t)->equals(o2)); // get second value
  t_true(smap->size() == 2);        // length is now 2
  t_true(
          smap->put(s, o2)->equals(o1)); // replace first value, return first value
  t_true(smap->get(s)->equals(o2));  // new value now exists at first key

  delete smap;
  delete s;
  delete t;
  delete u;
  delete o1;
  delete o2;

  exit(0);
}

TEST(Map, testStrToObjMap1
) {
t_exit_zero(testStrToObjMap1) }

// tests for Map from String to Object [put_all]
void testStrToObjMap2() {
  Map * a = new Map();
  Map * b = new Map();
  Map * c = new Map();
  String *k = new String("a key");
  Object *o1 = new Object();
  Object *o2 = new Object();
  a->put(k, o1);              // puts key/val pair into a
  c->put(k, o1);              // puts same key/val pair into c
  t_true(b->put_all(a) == 0); // put_all of a into b returns 0
  a->put(k, o2);              // replaces value in a
  t_true(b->put_all(a)->equals(
          c)); // put_all of updated a into b returns map with same pair as c

  delete a;
  delete b;
  delete c;
  delete k;
  delete o1;
  delete o2;

  exit(0);
}

TEST(Map, testStrToObjMap2
) {
t_exit_zero(testStrToObjMap2) }

// tests for StrToStrMap [get, put, contains_key, size, remove]
void testStrToStrMap1() {
  StrToStrMap *smap = new StrToStrMap();
  String *k = new String("key");
  String *v = new String("value");
  String *u = new String("unused");
  String *k2 = new String("second key");

  t_true(smap->size() == 0);          // initial length of map is zero
  t_true(smap->put(k, v) == 0);       // add one key/value pair return 0
  t_true(smap->contains_key(k));      // contains key added
  t_false(smap->contains_key(u));     // does not contain a non-added key
  t_true(smap->get(k)->equals(v));    // key returns matching value
  t_true(smap->size() == 1);          // length is now 1
  t_true(smap->put(k2, u) == 0);      // add a second pair
  t_true(smap->contains_key(k2));     // second key is in map
  t_true(smap->get(k2)->equals(u));   // get second value
  t_true(smap->size() == 2);          // length is now 2
  t_true(smap->put(k, u)->equals(v)); // replace first value, return first value
  t_true(smap->get(k)->equals(u));    // new value now exists at first key
  t_false(smap->get(k)->equals(v));
  t_true(smap->remove(k)->equals(u)); // remove returns the value at the key
  t_true(smap->size() == 1); // and decreases the size by 1 (if the value was in the map)
  t_true(smap->remove(k) == nullptr); // and returns nullptr for keys not in the map

  delete smap;
  delete k;
  delete v;
  delete u;
  delete k2;

  exit(0);
}

TEST(Map, testStrToStrMap1
) {
t_exit_zero(testStrToStrMap1) }

// tests for StrToStrMap put_all
void testStrToStrMap2() {
  StrToStrMap *a = new StrToStrMap();
  StrToStrMap *b = new StrToStrMap();
  StrToStrMap *c = new StrToStrMap();
  String *ak = new String("a key");
  String *av = new String("a value");
  String *n = new String("new value");
  a->put(ak, av);             // puts key/val pair into a
  c->put(ak, av);             // puts same key/val pair into c
  t_true(b->put_all(a) == 0); // put_all of a into b returns 0
  a->put(ak, n);              // replaces value in a
  t_true(b->put_all(a)->equals(
          c)); // put_all of updated a into b returns map with same pair as c

  delete a;
  delete b;
  delete c;
  delete ak;
  delete av;
  delete n;

  exit(0);
}

TEST(Map, testStrToStrMap2
) {
t_exit_zero(testStrToStrMap2) }

void testExtraLargeMap() {
  // setup
  int count = 4096;
  String ***entries = new String **[count];

  char key[64];
  char value[64];
  for (int i = 0; i < count; i++) {
    // creates null terminated string
    sprintf(key, "a long key string %d", i);
    sprintf(value, "value %d", i);
    entries[i] = new String *[2];

    // assumes the String constructor makes a copy
    entries[i][0] = new String(key);
    entries[i][1] = new String(value);
  }

  // start inserting into Map (seperate just to make test clearer)
  StrToStrMap *m = new StrToStrMap();
  for (int i = 0; i < count; i++) {
    String *k = entries[i][0];
    String *v = entries[i][1];
    m->put(k, v);
  }

  // ensure all keys are now contained
  for (int i = 0; i < count; i++) {
    String *k = entries[i][0];
    t_true(m->contains_key(k));
  }

  // try 20 random entries, ensure get back inserted value
  for (int i = 0; i < 20; i++) {
    int r = rand() % count;
    String *k = entries[r][0];
    String *v = entries[r][1];
    t_true(m->get(k) == v);
    t_true(m->get(k)->equals(v));
  }

  // cleanup memory just in case since we allocated a lot
  for (int i = 0; i < count; i++) {
    delete entries[i][0];
    delete entries[i][1];
    delete[] entries[i];
  }
  delete[] entries;

  exit(0);
}

TEST(Map, testExtraLargeMap
) {
t_exit_zero(testExtraLargeMap) }

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}