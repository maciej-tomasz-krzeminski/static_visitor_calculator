## Goal

An excercise to implement a simple calculator demonstrating static and dynamic visitor patterns.


## Build instructions


See the requirements for hive:
https://gitlab.syncad.com/hive/hive/-/blob/develop/doc/building.md#building-on-ubuntu-18042004

Then:

```
git clone https://github.com/openhive-network/hive
cd hive
git checkout master
git submodule update --init --recursive
cd programs
echo "add_subdirectory( static_visitor_calculator)" >> CMakeLists.txt 
git submodule add git@github.com:maciej-tomasz-krzeminski/static_visitor_calculator.git
cd ..
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build . --config Debug --target calc_fc calc_std calc_dynamic  --
```


## Features
Three executables are built:
 1.  calc_fc using the fc library
 2.  calc_std uses std::visit
 3.  calc_dynamic uses hand made dynamic dispatch visitors

The canonical example here would be to create and visit an abstract syntax tree. However the grammar is so simple 

```
<expr> ::= <additive_expr>

<additive_expr> ::= <multiplicative_expr> "+" <additive_expr>
        |  <multiplicative_expr>

<multiplicative_expr> ::= <primary_expr> "*" <multiplicative_expr>
        |  <primary_expr>

<primary_expr> ::= "(" <expr> ")"
        |  <number>

<number> ::= integer
```

that the evaluation of expressions is performed while parsing.
So to demonstrate visitors I used the token of the lexer as the visited object. An artificial token -sentinel is appended after tokenization to facilitate subsequent parsing. 
The predicate like visitors answer the questions if the operation represented by the token is additive, multiplicative or it is a number. The calulation proper visitor is there as well. 




#### TODO:


-  headers in CMakelists.txt
-  isolate project from Hive
-  Boost Test
-  CTest a bit
-  CLI
-  Docker
-  cleanups:  separate file for visitate and for token_assign, for print_implementation_used. get rid of difference and the like



