```shell
clang++ -std=c++20 -o app \
  src/lcompilers/ldictionary/prefix_node.cpp \
  src/lcompilers/ldictionary/prefix_iterator.cpp \
  src/lcompilers/ldictionary/prefix_cursor.cpp \
  src/lcompilers/ldictionary/prefix_trie.cpp \
  src/lcompilers/ldictionary/main.cpp
```

``` shell
./app
Inserted "" into dict.
Inserted "foo" into dict.
Inserted "bar" into dict.
Inserted "baz" into dict.
Inserted "qux" into dict.
Inserted "quo" into dict.
Inserted 6 terms in dict.
("" + "") = "" ~ ""
("" + "") = "" ~ "bar"
("" + "") = "" ~ "baz"
("" + "") = "" ~ "foo"
("" + "") = "" ~ "quo"
("" + "") = "" ~ "qux"
Found 6 result(s) for query ""
("" + "b") = "b" ~ "bar"
("" + "b") = "b" ~ "baz"
Found 2 result(s) for query "b"
("b" + "a") = "ba" ~ "bar"
("b" + "a") = "ba" ~ "baz"
Found 2 result(s) for query "ba"
("ba" + "r") = "bar" ~ "bar"
Found 1 result(s) for query "bar"
Found 0 result(s) for query "bard"
Rewinding by 2 characters.
("ba" + "z") = "baz" ~ "baz"
Found 1 result(s) for query "baz"
Found 0 result(s) for query "bazz"
```
