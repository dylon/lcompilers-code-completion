#include "prefix_cursor.h"

namespace LCompilers::LDictionary {

  PrefixCursor::PrefixCursor(PrefixNode *node)
    : m_curr(node),
      m_prev(node->parent()) {
    // empty
  }

  PrefixCursor::PrefixCursor()
    : m_curr(nullptr),
      m_prev(nullptr) {
    // empty
  }

  auto PrefixCursor::seek(const std::string &suffix) -> bool {
    for (int i = 0, k = suffix.size();
         (i < k) && (m_curr != nullptr);
         i++) {
      const char &label = suffix[i];
      m_prev = m_curr;
      m_curr = m_curr->transition(label);
    }
    return (m_curr != nullptr);
  }

  auto PrefixCursor::rewind(int num_steps) -> bool {
    while ((num_steps > 0) && (m_prev != nullptr)) {
      m_curr = m_prev;
      m_prev = m_curr->parent();
      num_steps--;
    }
    return (m_curr != nullptr);
  }

  auto PrefixCursor::begin() const -> PrefixIterator {
    return PrefixIterator(m_curr);
  }

  auto PrefixCursor::end() const -> PrefixIterator {
    return PrefixIterator();
  }

  auto PrefixCursor::curr() const -> PrefixNode * {
    return m_curr;
  }

  auto PrefixCursor::prev() const -> PrefixNode * {
    return m_prev;
  }

} // namespace LCompilers::LDictionary
