#include <iostream>
#include <memory>
#include <tuple>
#include <unordered_map>

#include "scan.h"

struct edge {
  std::string source;
  std::string sink;
};

std::ostream& operator<<(std::ostream &out, const struct edge &edge) {
  out << edge.source << " " << edge.sink;
  return out;
}

std::istream& operator>>(std::istream &is, struct edge &edge)
{
  is >> edge.source >> edge.sink;
  return is;
}

int main() {
  //  auto op = std::unique_ptr<exodb::Operator<std::string, std::string>>(
  //  new exodb::Scan<std::string, std::string>("../data/small.al"));
  exodb::Operator<edge> *op =
      new exodb::Scan<edge>("../data/tiny.al");

  op->Open();

  edge tuple;


  while (op->GetNext(&tuple)) {
    std::cout << tuple << std::endl;
  }

  op->Close();
}
