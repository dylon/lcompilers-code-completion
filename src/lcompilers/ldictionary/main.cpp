#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

#include "prefix_trie.h"

namespace ld = LCompilers::LDictionary;

void seek_and_print_results(
    ld::PrefixCursor &cursor,
    std::stringstream &ss,
    const std::string &suffix) {
  const std::string &query = ss.str();
  int num_results = 0;
  if (cursor.seek(suffix)) {
    std::for_each(cursor.begin(), cursor.end(), [&](const std::string &candidate) {
      std::cout << "(\"" << query << "\" + \"" << suffix << "\") = \""
                << query << suffix << "\" ~ \"" << candidate << '"' << std::endl;
      num_results ++;
    });
  }
  ss << suffix;
  std::cout << "Found " << num_results << " result(s) for query \"" << ss.str() << "\"" << std::endl;
}

void insert(ld::PrefixTrie &dict, const std::string &term) {
  dict.insert(term);
  std::cout << "Inserted \"" << term << "\" into dict." << std::endl;
}

int main(int argc, char *argv[]) {
  ld::PrefixTrie dict;
  insert(dict, "");
  insert(dict, "foo");
  insert(dict, "bar");
  insert(dict, "baz");
  insert(dict, "qux");
  insert(dict, "quo");
  std::cout << "Inserted " << dict.size() << " terms in dict." << std::endl;

  std::stringstream ss;

  ld::PrefixCursor cursor = dict.cursor();
  seek_and_print_results(cursor, ss, "");   // query = ""
  seek_and_print_results(cursor, ss, "b");  // query = "b"
  seek_and_print_results(cursor, ss, "a");  // query = "ba"
  seek_and_print_results(cursor, ss, "r");  // query = "bar"
  seek_and_print_results(cursor, ss, "d");  // query = "bard"

  std::cout << "Rewinding by 2 characters." << std::endl;
  cursor.rewind(2);
  ss.str(**cursor.curr());
  ss.seekp(std::ios_base::end);             // query = "ba"
  seek_and_print_results(cursor, ss, "z");  // query = "baz"
  seek_and_print_results(cursor, ss, "z");  // query = "bazz"

  return 0;
}
