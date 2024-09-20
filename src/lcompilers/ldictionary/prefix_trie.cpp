#include "prefix_trie.h"

namespace LCompilers::LDictionary {

  PrefixTrie::PrefixTrie()
    : m_root(new PrefixNode()),
      m_size(0) {
    // empty
  }

  PrefixTrie::~PrefixTrie() {
    delete m_root;
  }

  auto PrefixTrie::size() const -> std::size_t {
    return m_size;
  }

  auto PrefixTrie::insert(const std::string &term) -> bool {
    PrefixNode *curr = m_root;
    for (const char &label : term) {
      curr = curr->add_edge(label);
    }
    if (curr->is_final()) {  // term already in dictionary
      return false;
    }
    curr->is_final(true);
    m_size++;
    return true;
  }

  auto PrefixTrie::lookup(const std::string &term) const -> PrefixIterator {
    PrefixNode *curr = m_root;
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

  auto PrefixTrie::cursor() const -> PrefixCursor {
    return PrefixCursor(m_root);
  }

  auto PrefixTrie::begin() const -> PrefixIterator {
    return PrefixIterator(m_root);
  }

  auto PrefixTrie::end() const -> PrefixIterator {
    return PrefixIterator();
  }

} // namespace LCompilers::LDictionary
