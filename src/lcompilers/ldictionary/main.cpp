#include <algorithm>
#include <iostream>
#include <string>

#include "prefix_trie.h"

namespace ld = LCompilers::LDictionary;

void print_results(const ld::PrefixTrie &dict, const std::string &query) {
  int num_results = 0;
  std::for_each(dict.lookup(query), dict.end(), [&](const std::string &candidate) {
    std::cout << '"' << query << "\" ~ \"" << candidate << '"' << std::endl;
    num_results ++;
  });
  std::cout << "Found " << num_results << " result(s) for query \"" << query << "\"" << std::endl;
}

int main(int argc, char *argv[]) {
  ld::PrefixTrie dict;
  dict.insert("");
  dict.insert("foo");
  dict.insert("bar");
  dict.insert("baz");
  dict.insert("qux");
  dict.insert("quo");
  std::cout << "Inserted " << dict.size() << " terms in dict." << std::endl;
  print_results(dict, "");
  print_results(dict, "b");
  print_results(dict, "ba");
  print_results(dict, "bar");
  print_results(dict, "bard");
  return 0;
}
