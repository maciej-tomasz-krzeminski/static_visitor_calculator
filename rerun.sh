#! /usr/bin/env bash
# run it from hive/build
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build . --config Debug --target calc_fc calc_std calc_dynamic  --
./programs/static_visitor_calculator/calc_dynamic
./programs/static_visitor_calculator/calc_std
./programs/static_visitor_calculator/calc_fc

