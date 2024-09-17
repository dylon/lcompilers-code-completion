#ifndef LCOMPILERS_LDICTIONARY_PREFIX_NODE_H
#define LCOMPILERS_LDICTIONARY_PREFIX_NODE_H

#include <map>

namespace LCompilers::LDictionary {

  class PrefixNode {
  public:
    PrefixNode(PrefixNode *parent, char label);
    PrefixNode();
    ~PrefixNode();
    auto add_edge(char label) -> PrefixNode *;
    auto is_final() const -> bool;
    void is_final(bool is_final);
    auto parent() const -> PrefixNode *;
    auto label() const -> char;
    auto transition(char label) -> PrefixNode *;

  private:
    PrefixNode *_parent;
    char _label;
    bool _is_final;
    std::map<char, PrefixNode *> _edges;
    friend class PrefixTrie;
    friend class PrefixIterator;
  }; // class PrefixNode

} // namespace LCompilers::LDictionary

#endif // LCOMPILERS_LDICTIONARY_PREFIX_NODE_H
