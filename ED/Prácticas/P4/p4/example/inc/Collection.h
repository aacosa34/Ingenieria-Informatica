#ifndef __COLLECTION__
#define __COLLECTION__

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

template <class T, class U>
class Collection {
private:
  vector<pair<T, U>> elements;

public:
  Collection();
  void add(pair<T, U> element);
  void remove(int pos);
  int size();

  class iterator {
  private:
    typename vector<pair<T, U>>::iterator vit;
    iterator(typename vector<pair<T, U>>::iterator it);
    friend class Collection<T, U>;

  public:
    //iterator();
    iterator(const iterator &it);

    iterator &operator=(const iterator &it);

    iterator &operator++();
    iterator &operator--();
    pair<T, U> &operator*();

    bool operator!=(const iterator &it) const;
    bool operator==(const iterator &it) const;
  };

  iterator begin();
  iterator end();
};

template <class T, class U>
ostream &operator<<(ostream &os, const Collection<T, U> &c);

#include "Collection.cpp"

#endif
