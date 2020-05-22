
#include <string>

template <typename T>
class Stack {
 public:
  Stack(int capacity) : capacity_(capacity), idx_(0) {
    array_ = new T[capacity_];
    for (int i = 0; i < capacity_; i++) {
      array_[i] = 0;
    }
  };

  void push(T t);
  void pop(T &t);
  void peek(T &t);
  bool isFull();
  bool isEmpty();
  std::string toString() {
    return "Capacity: " + std::to_string(capacity_) + "\n" + "Index: " +
           std::to_string(idx_);
  };
  unsigned size() { return idx_; }

 private:
  const size_t capacity_;
  size_t idx_;
  T *array_;
};


//  Created by Steven Feldman on 11/1/12.
//  Copyright (c) 2012 Steven FELDMAN. All rights reserved.
//

template <typename T>
void Stack<T>::push(T t) {
  array_[idx_++] = t;
}

template <typename T>
void Stack<T>::pop(T &t) {
  t = array_[idx_ - 1];
  idx_--;
}

template <typename T>
void Stack<T>::peek(T &t) {
  t = array_[idx_ - 1];
}

template <typename T>
bool Stack<T>::isFull() {
  return idx_ < capacity_;
}

template <typename T>
bool Stack<T>::isEmpty() {
  return idx_ > 0;
}
