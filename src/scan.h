#pragma once

#include <assert.h>
#include <fstream>
#include <tuple>

#include "operator.h"

namespace exodb {
 
template <typename T>
class Scan : public Operator<T> {
 public:
  explicit Scan(const std::string &file_name): file_name_(file_name),
                                               ifstream_() { }

  virtual void Open();
  virtual bool GetNext(T *out);
  virtual void Close();

 private:
  const std::string file_name_;
  std::ifstream ifstream_;
};

template <typename T>
void Scan<T>::Open() {
  ifstream_.open(file_name_);
}

template <typename T>
void Scan<T>::Close() {
  ifstream_.close();
}


template <typename T>
bool Scan<T>::GetNext(T *out) {
  ifstream_ >> *out;
  return ifstream_;
}

}
