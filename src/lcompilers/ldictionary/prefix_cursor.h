#ifndef LCOMPILERS_LDICTIONARY_PREFIX_CURSOR_H
#define LCOMPILERS_LDICTIONARY_PREFIX_CURSOR_H

#include <string>

#include "prefix_node.h"
#include "prefix_iterator.h"

namespace LCompilers::LDictionary {

  class PrefixCursor {
  public:
    PrefixCursor(PrefixNode *node);
    PrefixCursor();
    auto seek(const std::string &suffix) -> bool;
    auto rewind(int num_steps) -> bool;
    auto begin() const -> PrefixIterator;
    auto end() const -> PrefixIterator;
    auto curr() const -> PrefixNode *;
    auto prev() const -> PrefixNode *;
  private:
    PrefixNode *_curr;
    PrefixNode *_prev;
  };

} // namespace LCompilers::LDictionary

#endif // LCOMPILERS_LDICTIONARY_PREFIX_CURSOR_H
