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
Three executables built:
 -calc_fc using the fc library
 -calc_std uses std::visit
 -calc_dynamic uses hand made dynamic dispatch visitors

The canonical example here would be to create and visit an abstract syntax tree, however the grammar is so simple that the evaluation of expressions is performed while parsing.
So I used tokens of the lexer to be demonstrated as an example.
The predicate like visitors answer the questions if the operation represented by the token is additive, multiplicative or it is a number. Also a sentinel is appended after tokenization  to facilitate the ending condition of the subsequent parsing. Parsing performs the actual arithmetic evaluations.



