#ifndef LCOMPILERS_LDICTIONARY_PREFIX_ITERATOR_H
#define LCOMPILERS_LDICTIONARY_PREFIX_ITERATOR_H

#include <queue>
#include <sstream>
#include <string>

#include "prefix_node.h"

namespace LCompilers::LDictionary {

  class PrefixIterator {
  public:
    PrefixIterator(PrefixNode *node);
    PrefixIterator();
    auto operator++() -> PrefixIterator &;
    auto operator*() const -> std::string;
    auto operator==(const PrefixIterator &other) const -> bool;
  private:
    std::queue<PrefixNode *> _pending;
    std::stringstream ss;
    void buffer(PrefixNode *node);
  }; // class PrefixIterator

} // namespace LCompilers::LDictionary

#endif // LCOMPILERS_LDICTIONARY_PREFIX_ITERATOR_H
