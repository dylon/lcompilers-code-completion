#include "prefix_node.h"

namespace LCompilers::LDictionary {

  PrefixNode::PrefixNode(PrefixNode *parent, char label)
    : _parent(parent),
      _label(label),
      _is_final(false){
    // empty
  }

  PrefixNode::PrefixNode()
    : PrefixNode(nullptr, '\0') {
    // empty
  }

  PrefixNode::~PrefixNode() {
    for (const auto &[label, child] : _edges) {
      delete child;
    }
  }

  auto PrefixNode::add_edge(char label) -> PrefixNode * {
    PrefixNode *child;
    auto iter = _edges.find(label);
    if (iter == _edges.end()) {
      child = new PrefixNode(this, label);
      _edges.emplace(label, child);
    } else {
      child = iter->second;
    }
    return child;
  }

  auto PrefixNode::is_final() const -> bool {
    return _is_final;
  }

  void PrefixNode::is_final(bool is_final) {
    _is_final = is_final;
  }

  auto PrefixNode::parent() const -> PrefixNode * {
    return _parent;
  }

  auto PrefixNode::label() const -> char {
    return _label;
  }

  auto PrefixNode::transition(char label) -> PrefixNode * {
    auto iter = _edges.find(label);
    if (iter == _edges.end()) {
      return nullptr;
    }
    return iter->second;
  }

} // namespace LCompilers::LDictionary
