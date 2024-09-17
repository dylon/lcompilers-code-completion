#include "prefix_trie.h"

namespace LCompilers::LDictionary {

  PrefixTrie::PrefixTrie()
    : _root(new PrefixNode()),
      _size(0) {
    // empty
  }

  PrefixTrie::~PrefixTrie() {
    delete _root;
  }

  auto PrefixTrie::size() const -> std::size_t {
    return _size;
  }

  auto PrefixTrie::insert(const std::string &term) -> bool {
    PrefixNode *curr = _root;
    for (const char &label : term) {
      curr = curr->add_edge(label);
    }
    if (curr->is_final()) {  // term already in dictionary
      return false;
    }
    curr->is_final(true);
    _size++;
    return true;
  }

  auto PrefixTrie::lookup(const std::string &term) const -> PrefixIterator {
    PrefixNode *curr = _root;
    for (const char &c : term) {
      curr = curr->transition(c);
      if (curr == nullptr) {
        break;
      }
    }
    if (curr == nullptr) {
      return end();
    }
    return PrefixIterator(curr);
  }

  auto PrefixTrie::begin() const -> PrefixIterator {
    return PrefixIterator(_root);
  }

  auto PrefixTrie::end() const -> PrefixIterator {
    return PrefixIterator();
  }

} // namespace LCompilers::LDictionary
