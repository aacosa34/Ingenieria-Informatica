template <class T, class U> Collection<T, U>::Collection() {}

template <class T, class U> void Collection<T, U>::add(pair<T, U> element) {
  elements.push_back(element);
}

template <class T, class U> void Collection<T, U>::remove(int pos) {
  elements.remove(elements.begin() + pos);
}

template <class T, class U> int Collection<T, U>::size() {
  return elements.size();
}

// Collection::iterator

template <class T, class U>
Collection<T, U>::iterator::iterator(typename vector<pair<T, U>>::iterator vit) {
  this.vit = vit;
}

template <class T, class U> Collection<T, U>::iterator::iterator() {
  this.vit = NULL;
}

template <class T, class U>
Collection<T, U>::iterator::iterator(const iterator &it) {
  this.vit = it.vit;
}

template <class T, class U>
typename Collection<T, U>::iterator &
Collection<T, U>::iterator::operator=(const iterator &it) {
  if (this != &it) {
    vit = it.vit;
  }

  return *this;
}

template <class T, class U>
typename Collection<T, U>::iterator &Collection<T, U>::iterator::operator++() {
  vit++;
  return *this;
}

template <class T, class U>
typename Collection<T, U>::iterator &Collection<T, U>::iterator::operator--() {
  vit--;
  return *this;
}

template <class T, class U>
pair<T, U> &Collection<T, U>::iterator::operator*() {
  return *vit;
}

template <class T, class U>
bool Collection<T, U>::iterator::operator==(
    const Collection<T, U>::iterator &it) const {
  return this.vit == it.vit;
}

template <class T, class U>
bool Collection<T, U>::iterator::operator!=(
    const Collection<T, U>::iterator &it) const {
  return this.vit != it.vit;
}

template <class T, class U>
typename Collection<T, U>::iterator Collection<T, U>::begin() {
  return Collection<T, U>::iterator(elements.begin());
}

template <class T, class U>
typename Collection<T, U>::iterator Collection<T, U>::end() {
  return Collection<T, U>::iterator(elements.end());
}
