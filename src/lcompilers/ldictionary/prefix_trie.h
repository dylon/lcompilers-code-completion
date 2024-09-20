#ifndef LCOMPILERS_LDICTIONARY_PREFIX_TRIE_H
#define LCOMPILERS_LDICTIONARY_PREFIX_TRIE_H

#include <cstddef>
#include <string>

#include "prefix_node.h"
#include "prefix_cursor.h"
#include "prefix_iterator.h"

namespace LCompilers::LDictionary {

  class PrefixTrie {
  public:
    PrefixTrie();
    ~PrefixTrie();
    auto size() const -> std::size_t;
    auto insert(const std::string &term) -> bool;
    auto lookup(const std::string &term) const -> PrefixIterator;
    auto cursor() const -> PrefixCursor;
    auto begin() const -> PrefixIterator;
    auto end() const -> PrefixIterator;
  private:
    PrefixNode *m_root;
    std::size_t m_size;
  }; // class PrefixTrie

} // namespace LCompilers::LDictionary

#endif // LCOMPILERS_LDICTIONARY_PREFIX_TRIE_H
