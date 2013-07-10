#include <iostream>
#include <unordered_map>

int main() {
  std::unordered_map<std::string, int> map;

  map["hello"] = 3;
  map["world"] = 2;

  for (auto &kv : map)
    std::cout << kv.first << "  " << kv.second << std::endl;
}
