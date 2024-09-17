```shell
clang++ -std=c++20 -o app src/lcompilers/ldictionary/{prefix_node,prefix_iterator,prefix_trie,main}.cpp && ./app
Inserted 6 terms in dict.
"" ~ ""
"" ~ "bar"
"" ~ "baz"
"" ~ "foo"
"" ~ "quo"
"" ~ "qux"
Found 6 result(s) for query ""
"b" ~ "bar"
"b" ~ "baz"
Found 2 result(s) for query "b"
"ba" ~ "bar"
"ba" ~ "baz"
Found 2 result(s) for query "ba"
"bar" ~ "bar"
Found 1 result(s) for query "bar"
Found 0 result(s) for query "bard"
```
