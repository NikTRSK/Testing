template <class T>
arrayList<T>::arrayList() {
  data = new T[10];
  _capacity = 10;
  _size = 0;
}

template <class T>
arrayList<T>::arrayList(int cap) {
  data = new T[cap];
  _capacity = cap;
  _size = 0;
}

template <class T>
arrayList<T>::arrayList(const arrayList<T>& otherList) {
  this->_capacity = otherList._capacity;
  this->_size = otherList._size;
  this->data = new T[_capacity];

  for (unsigned int i = 0; i < this->size; i++)
    this->data[i] = otherList.data[i];
}

template <class T>
arrayList<T>::~arrayList() {
  delete [] data;
}

template <class T>
void arrayList<T>::push_back(T val) {
  if (_capacity == _size) {
    this->resize();
  }
  data[_size] = val;
  _size++;
}

template <class T>
void arrayList<T>::pop_back() {
  // mark as empty by moving back one spot
  _size--;
}

template <class T>
void arrayList<T>::push_front(T val) {
  if (_size == _capacity)
    this->resize();
  for (unsigned int i = size - 1; i >= 0; i--)
    data[i+1] = data[i];
  data[0] = val;
  _size++;
}

template <class T>
void arrayList<T>::pop_front() {
  for (unsigned int i = 1; i < _size; i++)
    data[i-1] = data[i];
  _size--;
}

template <class T>
void arrayList<T>::insert(int loc, T val) {
  if (loc > -1 && loc <= _size) { // check if location within range
    if (_size == _capacity) // check if full
      this->resize();
    if (is_empty()) // if list empty
      data[loc] = val;
    else if (loc >= 0 && loc < _size) {
      for (int i = _size - 1; i >= loc; i--)
        data[i+1] = data[i];
    }
    
    data[loc] = val;
    _size++;
  }
}

template <class T>
void arrayList<T>::update(int loc, T val) {
  if ( loc < -1 || loc >= _size)
    throw "Invalid location";
  else
    data[loc] = val;
}

template <class T>
void arrayList<T>::remove(int loc) {
  if (loc > -1 && loc <= _capacity) {
    for (int i = loc; i < _size; i++)
      data[i] = data[i+1];
    _size--;
  }
}

template <class T>
T arrayList<T>::get_front() {
  if (is_empty()) {
    throw "List is empty. Nothing to return.";
  }
  else
    return data[0];
}

template <class T>
T arrayList<T>::get_back() {
  if (is_empty()) {
    throw "List is empty. Nothing to return.";
  }
  else
    return data[_size-1];
}

template <class T>
T arrayList<T>::get_at(int loc) {
  if ( loc < -1 || loc >= _size)
    throw "Invalid location";
  return data[loc];
}

template <class T>
void arrayList<T>::resize() {
  T* tempArray = new T[_capacity*2];
  _capacity *= 2;

  for (int i = 0; i < _size; i++)
    tempArray[i] = data[i];
  delete [] data;
  data = tempArray;
}

template <class T>
bool arrayList<T>::is_empty() {
  return _size == 0;
}

template <class T>
int arrayList<T>::size() {
  return _size;
}

template <class T>
int arrayList<T>::capacity() {
  return _capacity;
}

template <class T>
void arrayList<T>::clear() {
  _size = 0;
}

template <class T>
int const & arrayList<T>::operator[](int loc) const {
  return data[loc];
}