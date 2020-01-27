// lang::CwC

#include "map.h"
#include "object.h"
#include "string.h"
#include<assert.h>

// tests for strings [equal and hash]
void test1() {
  String* s = new String("hello");
  String* t = new String("world");
  String* u = new String("hello");
  assert(s->equals(s));
  assert(!s->equals(t));
  assert(s->equals(u));
  assert(s->hash() == s->hash());
  assert(!s->hash() == t->hash());
  assert(s->hash() == u->hash());
}

// tests for StrToStrMap [get, put, contains_key, len]
void test2() {
  StrToStrMap* smap = new StrToStrMap();
  String* k = new String("key");
  String* v = new String("value");
  String* u = new String("unused");
  String* k2 = new String("second key");
  assert(smap->size() == 0);         // initial length of map is zero
  assert(smap->put(k, v) == 0);      // add one key/value pair return 0
  assert(smap->contains_key(k));     // contains key added
  assert(!smap->contains_key(u));    // does not contain a non-added key
  assert(smap->get(k)->equals(v));   // key returns matching value
  assert(smap->size() == 1);         // length is now 1
  assert(smap->put(k2, u) == 0);     // add a second pair
  assert(smap->contains_key(k2));    // second key is in map
  assert(smap->get(k2)->equals(u));  // get second value
  assert(smap->size() == 2);         // length is now 2
  assert(
      smap->put(k, u)->equals(v));  // replace first value, return first value
  assert(smap->get(k)->equals(v));  // new value now exists at first key
  assert(!smap->get(k)->equals(v));
}

// tests for StrToStrMap put_all
void test3() {
  StrToStrMap* a = new StrToStrMap();
  StrToStrMap* b = new StrToStrMap();
  StrToStrMap* c = new StrToStrMap();
  String* ak = new String("a key");
  String* av = new String("a value");
  String* n = new String("new value");
  a->put(ak, av);              // puts key/val pair into a
  c->put(ak, av);              // puts same key/val pair into c
  assert(b->put_all(a) == 0);  // put_all of a into b returns 0
  a->put(ak, n);               // replaces value in a
  assert(b->put_all(a)->equals(
      c));  // put_all of updated a into b returns map with same pair as c
}

// tests for Map [get, put, contains_key, len]
void test4() {
  Map* smap = new Map();
  String* s = new String("key");
  String* t = new String("another key");
  String* u = new String("yet another one");
  Object* o1 = new Object();
  Object* o2 = new Object();
  assert(smap->size() == 0);         // initial length of map is zero
  assert(smap->put(s, o1) == 0);     // add one key/value pair return 0
  assert(smap->contains_key(s));     // contains key added
  assert(!smap->contains_key(u));    // does not contain a non-added key
  assert(smap->get(s)->equals(o1));  // key returns matching value
  assert(smap->size() == 1);         // length is now 1
  assert(smap->put(t, o2) == 0);     // add a second pair
  assert(smap->contains_key(t));     // second key is in map
  assert(smap->get(t)->equals(o2));  // get second value
  assert(smap->size() == 2);         // length is now 2
  assert(smap->put(s, o2)->equals(o1));  // replace first value, return first value
  assert(smap->get(s)->equals(o2));   // new value now exists at first key
}

// tests for Map put_all
void test5() {
  Map* a = new Map();
  Map* b = new Map();
  Map* c = new Map();
  String* k = new String("a key");
  Object* o1 = new Object();
  Object* o2 = new Object();
  a->put(k, o1);               // puts key/val pair into a
  c->put(k, o1);               // puts same key/val pair into c
  assert(b->put_all(a) == 0);  // put_all of a into b returns 0
  a->put(k, o2);               // replaces value in a
  assert(b->put_all(a)->equals(
      c));  // put_all of updated a into b returns map with same pair as c
}

int main() {
  test1();
  test2();
  test3();
  test4();
  test5();
  return 0;
}
