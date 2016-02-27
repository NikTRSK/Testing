#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <cstdlib>
#include <stdexcept>
#include <iostream>

template <class T>
class arrayList {
  public:
    arrayList();
    arrayList(int cap);
    arrayList(const arrayList<T>& otherList);
    ~arrayList();
    // setters
    void push_back(T val);
    void pop_back();
    
    void push_front(T val);
    void pop_front();
    
    void insert(int loc, T val);
    void update(int loc, T val);
    void remove(int loc);

    // accessors
    T get_front();
    T get_back();
    T get_at(int loc);

    // utilities
    void resize();
    bool is_empty();
    int size();
    int capacity();
    void clear();

    // operators
    int const & operator[](int loc) const;

  private:
    int _capacity;
    int _size;
    T *data;
};

#include "arrayList.tpp"

#endif