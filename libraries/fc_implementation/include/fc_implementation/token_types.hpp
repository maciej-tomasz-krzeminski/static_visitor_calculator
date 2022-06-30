#pragma once

#include <iostream>
#include <fc/static_variant.hpp>

namespace static_variant_showcase
{

inline void print_implementation_used()
{
    std::cout << "fc implementation in use\n";
}

class add
{
public:
    add() : a(0), b(0) {}

private:
    int a;
    int b;
};

class subtract
{
public:
    subtract(int a_a, int b_b) : a(a_a), b(b_b) {}
    subtract() : a(0), b(0) {}
    int difference() { return a - b; }

private:
    int a;
    int b;
};

class multiply
{
public:
    multiply(int a_a, int b_b) : a(a_a), b(b_b) {}
    multiply() : a(0), b(0) {}
    int product() { return a * b; }

private:
    int a;
    int b;
};

class divide
{
public:
    divide(int a_a, int b_b) : a(a_a), b(b_b) {}
    divide() : a(0), b(0) {}
    int division() { return a / b; }

private:
    int a;
    int b;
};

class opening_parenthesis
{
};

class closing_parenthesis
{
};

class number
{
public:
    number(int a_n) : n(a_n) {}
    number() : n(0) {}
    int get_number() const { return n; }

private:
    int n;
};

class iteration_sentinel
{
};

using token_t = fc::static_variant<add, subtract, multiply, divide, number, opening_parenthesis, closing_parenthesis, iteration_sentinel>;

template<typename lefttokenT, typename righttokenT>
void token_assign(lefttokenT& tok, righttokenT value)
{
    tok = value;
}

}
