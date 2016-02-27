#include "llist.h"

llist::llist() : head(NULL), tail(NULL), size_(0) {
/*  head = NULL;
  tail = NULL;

  size_ = 0;*/
}

llist::~llist() {
  clear();
}

void llist::push_back(int val) {
  Node* newItem = new Node;
  newItem->next = NULL;
  newItem->value = val;
  // single item
  if (is_empty()) {
    head = newItem;
    tail = newItem;

    newItem->prev = NULL;
  }
  else {
    tail->next = newItem;
    newItem->prev = tail;
    tail = newItem;
  }
  size_++;
}

void llist::pop_back() {
  if (!is_empty()) {
    if (size() == 1) {
      delete tail;
      head = NULL;
      tail = NULL;
    }
    else {
      Node* temp = tail;
      tail = tail->prev;
      delete temp;
    }
    size_--;
  }
}

void llist::push_front(int val) {
  Node* newItem = new Node;
  newItem->prev = NULL;
  newItem->value = val;
  // single item
  if (is_empty()) {
    head = newItem;
    tail = newItem;

    newItem->next = NULL;
  }
  else {
    head->prev = newItem;
    newItem->next = head;
    head = newItem;
  }
  size_++;
}

void llist::pop_front() {
  if (!is_empty()) {
    if (size() == 1) {
      delete head;
      head = NULL;
      tail = NULL;
    }
    else {
      Node* temp = head;
      head = head->next;
      delete temp;
    }
    size_--;
  }
}

void llist::insert(int loc, int val) {
  if (loc > -1 && loc <= size_) {
    if (is_empty()) {
      Node * newItem = new Node();
      newItem->value = val;

      head = newItem;
      tail = newItem;
      newItem->next = NULL;
      newItem->prev = NULL;

      size_++;
    }
    else {
      if (loc == 0)
        push_front(val);
      else if (loc == size_)
        push_back(val);
      else {
        Node * newItem = new Node();
        newItem->value = val;
        
        Node * curr = get_node(loc)->prev;
        newItem->next = curr->next;
        curr->next = newItem;
        newItem->prev = curr;
        size_++;
      }
    }
  }
}
void llist::update(int loc, int val) {
  if ( loc < -1 || loc >= size_)
    throw "Invalid location";
  else
    get_node(loc)->value = val;
}

void llist::remove(int loc) {
  if (loc > -1 && loc <= size_) {
    if (is_empty() || loc == 1)
      pop_front();
    else if (loc == size() - 1)
      pop_back();
    else {
      Node * toDel = get_node(loc);
      toDel->next->prev = toDel->prev;
      toDel->prev->next = toDel->next;

      delete toDel;
      size_--;
    }
  }
}

int llist::get_front() {
  if (is_empty()) {
    throw "List is empty. Nothing to return.";
  }
  else {
    return head->value;
  }
}

int llist::get_back() {
  if (is_empty()) {
    throw "List is empty. Nothing to return.";
  }
  else {
    return tail->value;
  }
}

int llist::get_at(int loc) {
  if ( loc < -1 || loc >= size_)
    throw "Invalid location";
  return get_node(loc)->value;
}

bool llist::is_empty() {
  return size_ == 0;
}

int llist::size() {
  return size_;
}

void llist::clear() {
  while (head != NULL) {
    Node* temp = head->next;
    delete head;
    head = temp;
  }
  tail = NULL;
  size_ = 0;
}

Node* llist::get_node(int loc) {
  if (loc < -1 || loc >= size_)
    throw "Invalid location";
  else {
    Node* temp = head;
    int curr = 0;
    while (curr != loc) {
      temp = temp->next;
      curr++;
    }
    return temp;
  }
}

// Multiple llist functions
/*void FrontBackSplit(llist target1, llist target2, bool preserve) {
  for ()
}*/