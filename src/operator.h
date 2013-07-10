#pragma once

namespace exodb {
 
template <typename T>
class Operator {
 public:
  virtual void Open() = 0;
  virtual bool GetNext(T *out) = 0;
  virtual void Close() = 0;

  virtual ~Operator() { }
};

}
