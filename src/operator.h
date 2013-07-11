#pragma once

namespace exodb {
 
template <typename T>
class Operator {
 public:
  virtual void Open() { }
  virtual bool GetNext(T *out) = 0;
  virtual void Close() { }

  virtual ~Operator() { }
};

}
