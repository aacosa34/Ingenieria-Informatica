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
    iterator();
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

  class const_iterator {
  private:
    typename vector<pair<T, U>>::const_iterator vit;
    const_iterator(typename vector<pair<T, U>>::const_iterator it);
    friend class Collection<T, U>;

  public:
    const_iterator();
    const_iterator(const const_iterator &it);

    const_iterator &operator=(const const_iterator &it);

    const_iterator &operator++();
    const_iterator &operator--();
    const pair<T, U> &operator*() const;

    bool operator!=(const const_iterator &it) const;
    bool operator==(const const_iterator &it) const;
  };

  const_iterator cbegin() const;
  const_iterator cend() const;

  class ordered_iterator {
  private:
    typename vector<pair<T, U>>::const_iterator vit;
    typename vector<pair<T, U>>::const_iterator vbegin;
    typename vector<pair<T, U>>::const_iterator vend;
    ordered_iterator(typename vector<pair<T, U>>::const_iterator vit,
                     typename vector<pair<T, U>>::const_iterator vitbegin,
                     typename vector<pair<T, U>>::const_iterator vitend);
    friend class Collection<T, U>;

  public:
    ordered_iterator();
    ordered_iterator(const ordered_iterator &it);

    ordered_iterator &operator=(const ordered_iterator &it);

    ordered_iterator &operator++();
    const pair<T, U> &operator*() const;

    bool operator!=(const ordered_iterator &it) const;
    bool operator==(const ordered_iterator &it) const;
  };

  ordered_iterator obegin() const;
  ordered_iterator oend() const;
};

template <class T, class U>
ostream &operator<<(ostream &os, const Collection<T, U> &c);

#include "Collection.cpp"

#endif
