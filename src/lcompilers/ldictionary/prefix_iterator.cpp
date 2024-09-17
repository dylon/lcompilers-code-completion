#include "prefix_iterator.h"

namespace LCompilers::LDictionary {

  PrefixIterator::PrefixIterator(PrefixNode *node) {
    if (node != nullptr) {
      _pending.push(node);
      ++(*this);
    }
  }

  PrefixIterator::PrefixIterator() {
    // empty
  }

  auto PrefixIterator::operator++() -> PrefixIterator & {
    ss.str(std::string());
    while (!_pending.empty()) {
      PrefixNode *node = _pending.front();
      _pending.pop();
      for (const auto &[label, child] : node->_edges) {
        _pending.push(child);
      }
      if (node->is_final()) {
        node->buffer(ss);
        break;
      }
    }
    return *this;
  }

  auto PrefixIterator::operator*() const -> std::string {
    return ss.str();
  }

  auto PrefixIterator::operator==(const PrefixIterator &other) const -> bool {
    return (_pending.size() == other._pending.size())
      && (ss.str() == other.ss.str());
  }

} // namespace LCompilers::LDictionary
