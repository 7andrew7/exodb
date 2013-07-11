#pragma once

#include <assert.h>
#include <fstream>

#include "operator.h"

namespace exodb {

template <typename T>
class FileStreamScan : public Operator<T> {
 public:
  explicit FileStreamScan(const std::string &file_name):
      file_name_(file_name), ifstream_() { }

  virtual void Open() {
    ifstream_.open(file_name_);
  }

  virtual bool GetNext(T *out) {
    ifstream_ >> *out;
    return ifstream_;
  }

  virtual void Close() {
    ifstream_.close();
  }

 private:
  const std::string file_name_;
  std::ifstream ifstream_;
};

}
