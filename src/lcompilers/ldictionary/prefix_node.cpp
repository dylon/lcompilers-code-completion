#include "prefix_node.h"

namespace LCompilers::LDictionary {

  PrefixNode::PrefixNode(PrefixNode *parent, char label)
    : m_parent(parent),
      m_label(label),
      m_is_final(false){
    // empty
  }

  PrefixNode::PrefixNode()
    : PrefixNode(nullptr, '\0') {
    // empty
  }

  PrefixNode::~PrefixNode() {
    for (const auto &[label, child] : m_edges) {
      delete child;
    }
  }

  auto PrefixNode::add_edge(char label) -> PrefixNode * {
    PrefixNode *child;
    auto iter = m_edges.find(label);
    if (iter == m_edges.end()) {
      child = new PrefixNode(this, label);
      m_edges.emplace(label, child);
    } else {
      child = iter->second;
    }
    return child;
  }

  auto PrefixNode::is_final() const -> bool {
    return m_is_final;
  }

  void PrefixNode::is_final(bool is_final) {
    m_is_final = is_final;
  }

  auto PrefixNode::parent() const -> PrefixNode * {
    return m_parent;
  }

  auto PrefixNode::label() const -> char {
    return m_label;
  }

  auto PrefixNode::transition(char label) -> PrefixNode * {
    auto iter = m_edges.find(label);
    if (iter == m_edges.end()) {
      return nullptr;
    }
    return iter->second;
  }

  void PrefixNode::buffer(std::stringstream &ss) const {
    if (m_parent != nullptr) {
      m_parent->buffer(ss);
      ss << m_label;
    }
    // do not buffer the root node
  }

  auto PrefixNode::operator*() const -> std::string {
    std::stringstream ss;
    buffer(ss);
    return ss.str();
  }

} // namespace LCompilers::LDictionary
