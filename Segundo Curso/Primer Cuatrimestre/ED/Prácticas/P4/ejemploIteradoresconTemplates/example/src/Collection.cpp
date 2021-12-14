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
Collection<T, U>::iterator::iterator(
    typename vector<pair<T, U>>::iterator vit) {
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

// Collection::const_iterator

template <class T, class U>
Collection<T, U>::const_iterator::const_iterator(
    typename vector<pair<T, U>>::const_iterator vit) {
  this->vit = vit;
}

template <class T, class U>
Collection<T, U>::const_iterator::const_iterator() {
  this->vit = NULL;
}

template <class T, class U>
Collection<T, U>::const_iterator::const_iterator(const const_iterator &it) {
  this->vit = it.vit;
}

template <class T, class U>
typename Collection<T,U>::const_iterator &
Collection<T, U>::const_iterator::operator=(const const_iterator &it) {
  if (this != &it) {
    vit = it.vit;
  }

  return *this;
}

template <class T, class U>
typename Collection<T, U>::const_iterator &
Collection<T, U>::const_iterator::operator++() {
  vit++;
  return *this;
}

template <class T, class U>
typename Collection<T, U>::const_iterator &
Collection<T, U>::const_iterator::operator--() {
  vit--;
  return *this;
}

template <class T, class U>
const pair<T, U> &Collection<T, U>::const_iterator::operator*() const {
  return *vit;
}

template <class T, class U>
bool Collection<T, U>::const_iterator::operator==(
    const Collection<T, U>::const_iterator &it) const {
  return this.vit == it.vit;
}

template <class T, class U>
bool Collection<T, U>::const_iterator::operator!=(
    const Collection<T, U>::const_iterator &it) const {
  return this->vit != it.vit;
}

template <class T, class U>
typename Collection<T, U>::const_iterator Collection<T, U>::cbegin() const {
  return Collection<T, U>::const_iterator(elements.cbegin());
}

template <class T, class U>
typename Collection<T, U>::const_iterator Collection<T, U>::cend() const {
  return Collection<T, U>::const_iterator(elements.cend());
}

// Collection::ordered_iterator
template <class T, class U>
Collection<T, U>::ordered_iterator::ordered_iterator(
    typename vector<pair<T, U>>::const_iterator vit,
    typename vector<pair<T, U>>::const_iterator vitbegin,
    typename vector<pair<T, U>>::const_iterator vitend) {
  this->vit = vit;
  this->vbegin = vitbegin;
  this->vend = vitend;
}

template <class T, class U>
Collection<T, U>::ordered_iterator::ordered_iterator() {}

template <class T, class U>
Collection<T, U>::ordered_iterator::ordered_iterator(
    const ordered_iterator &it) {
  this->vit = it.vit;
}

template <class T, class U>
typename Collection<T, U>::ordered_iterator &
Collection<T, U>::ordered_iterator::operator=(const ordered_iterator &it) {
  if (this != &it) {
    vit = it.vit;
    vbegin = it.vbegin;
    vend = it.vend;
  }

  return *this;
}

template <class T, class U>
typename Collection<T, U>::ordered_iterator &
Collection<T, U>::ordered_iterator::operator++() {
  typename vector<pair<T, U>>::const_iterator explorer;
  T current_key = (*vit).first;
  T current_next = current_key;
  vit = vend;

  for (explorer = vbegin; explorer != vend && current_next <= current_key;
       explorer++)
    if (current_key < (*explorer).first) {
      vit = explorer;
      current_next = (*explorer).first;
    }

  for (; explorer != vend; explorer++)
    if ((*explorer).first > current_key && (*explorer).first < current_next) {
      vit = explorer;
      current_next = (*explorer).first;
    }

  return *this;
}

template <class T, class U>
const pair<T, U> &Collection<T, U>::ordered_iterator::operator*() const {
  return *vit;
}

template <class T, class U>
bool Collection<T, U>::ordered_iterator::operator==(
    const Collection<T, U>::ordered_iterator &it) const {
  return (vit == it.vit && vbegin == it.vbegin && vend == it.vend);
}

template <class T, class U>
bool Collection<T, U>::ordered_iterator::operator!=(
    const Collection<T, U>::ordered_iterator &it) const {
  return (vit != it.vit || vbegin != it.vbegin || vend != it.vend);
}

template <class T, class U>
typename Collection<T, U>::ordered_iterator Collection<T, U>::obegin() const {
  typename vector<pair<T, U>>::const_iterator it;
  typename vector<pair<T, U>>::const_iterator pos = elements.cbegin();
  typename vector<pair<T, U>>::const_iterator vbegin = elements.cbegin();
  typename vector<pair<T, U>>::const_iterator vend = elements.cend();
  T minimum = (*elements.cbegin()).first;

  for (it = vbegin; it != vend; it++) {
    if ((*it).first < minimum) {
      minimum = (*it).first;
      pos = it;
    }
  }

  return Collection<T, U>::ordered_iterator(pos, vbegin, vend);
}

template <class T, class U>
typename Collection<T, U>::ordered_iterator Collection<T, U>::oend() const {
  return Collection<T, U>::ordered_iterator(elements.cend(), elements.cbegin(),
                                            elements.cend());
}

// Operador de Salida

template <class T, class U>
ostream &operator<<(ostream &os, const Collection<T, U> &c) {

  for (typename Collection<T, U>::const_iterator it = c.cbegin();
       it != c.cend(); ++it) {
    os << '(' << (*it).first << ',' << (*it).second << ')' << endl;
  }
  return os;
}
