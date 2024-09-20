#include "prefix_iterator.h"

namespace LCompilers::LDictionary {

  PrefixIterator::PrefixIterator(PrefixNode *node) {
    if (node != nullptr) {
      m_pending.push(node);
      ++(*this);
    }
  }

  PrefixIterator::PrefixIterator() {
    // empty
  }

  auto PrefixIterator::operator++() -> PrefixIterator & {
    m_ss.str(std::string());
    while (!m_pending.empty()) {
      PrefixNode *node = m_pending.front();
      m_pending.pop();
      for (const auto &[label, child] : node->m_edges) {
        m_pending.push(child);
      }
      if (node->is_final()) {
        node->buffer(m_ss);
        break;
      }
    }
    return *this;
  }

  auto PrefixIterator::operator*() const -> std::string {
    return m_ss.str();
  }

  auto PrefixIterator::operator==(const PrefixIterator &other) const -> bool {
    return (m_pending.size() == other.m_pending.size())
      && (m_ss.str() == other.m_ss.str());
  }

} // namespace LCompilers::LDictionary
