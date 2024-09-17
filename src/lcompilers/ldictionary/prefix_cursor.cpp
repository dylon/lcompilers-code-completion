#include "prefix_cursor.h"

namespace LCompilers::LDictionary {

  PrefixCursor::PrefixCursor(PrefixNode *node)
    : _curr(node),
      _prev(node->parent()) {
    // empty
  }

  PrefixCursor::PrefixCursor()
    : _curr(nullptr),
      _prev(nullptr) {
    // empty
  }

  auto PrefixCursor::seek(const std::string &suffix) -> bool {
    for (int i = 0, k = suffix.size();
         (i < k) && (_curr != nullptr);
         i++) {
      const char &label = suffix[i];
      _prev = _curr;
      _curr = _curr->transition(label);
    }
    return (_curr != nullptr);
  }

  auto PrefixCursor::rewind(int num_steps) -> bool {
    while ((num_steps > 0) && (_prev != nullptr)) {
      _curr = _prev;
      _prev = _curr->parent();
      num_steps--;
    }
    return (_curr != nullptr);
  }

  auto PrefixCursor::begin() const -> PrefixIterator {
    return PrefixIterator(_curr);
  }

  auto PrefixCursor::end() const -> PrefixIterator {
    return PrefixIterator();
  }

  auto PrefixCursor::curr() const -> PrefixNode * {
    return _curr;
  }

  auto PrefixCursor::prev() const -> PrefixNode * {
    return _prev;
  }

} // namespace LCompilers::LDictionary
