#pragma once

#include <iostream>
#include <fc/static_variant.hpp>

namespace calcs
{

    inline void print_implementation_used()
    {
        std::cout << "fc implementation in use\n";
    }

    class add
    {
    };

    class subtract
    {
    };

    class multiply
    {
    };

    class divide
    {
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

    template <typename lefttokenT, typename righttokenT>
    void token_assign(lefttokenT &tok, righttokenT value)
    {
        tok = value;
    }

}
