#pragma once

#include "common/exceptions.hpp"
#include "token_types.hpp"

template <typename tokenT, typename visitorT>
int visitate(tokenT token, visitorT visitor)
{
    return token.visit(visitor);
}

using namespace std::literals::string_literals;

namespace calcs
{

    struct is_number_operation_visitor
    {
        using result_type = bool;

        bool operator()(add arg) const { return false; }
        bool operator()(subtract arg) const { return false; }
        bool operator()(multiply arg) const { return false; }
        bool operator()(divide arg) const { return false; }

        bool operator()(number arg) const { return true; }
        bool operator()(opening_parenthesis arg) const { return false; }
        bool operator()(closing_parenthesis arg) const { return false; }
        bool operator()(iteration_sentinel arg) const { return false; }
    };

    struct is_open_parenthesis_visitor
    {
        using result_type = bool;

        bool operator()(add arg) const { return false; }
        bool operator()(subtract arg) const { return false; }
        bool operator()(multiply arg) const { return false; }
        bool operator()(divide arg) const { return false; }

        bool operator()(number arg) const { return false; }
        bool operator()(opening_parenthesis arg) const { return true; }
        bool operator()(closing_parenthesis arg) const { return false; }
        bool operator()(iteration_sentinel arg) const { return false; }
    };

    struct is_close_parenthesis_visitor
    {
        using result_type = bool;

        bool operator()(add arg) const { return false; }
        bool operator()(subtract arg) const { return false; }
        bool operator()(multiply arg) const { return false; }
        bool operator()(divide arg) const { return false; }

        bool operator()(number arg) const { return false; }
        bool operator()(opening_parenthesis arg) const { return false; }
        bool operator()(closing_parenthesis arg) const { return true; }
        bool operator()(iteration_sentinel arg) const { return false; }
    };

    struct is_multiplicative_operation_visitor
    {
        using result_type = bool;

        bool operator()(add arg) const { return false; }
        bool operator()(subtract arg) const { return false; }
        bool operator()(multiply arg) const { return true; }
        bool operator()(divide arg) const { return true; }

        bool operator()(number arg) const { return false; }
        bool operator()(opening_parenthesis arg) const { return false; }
        bool operator()(closing_parenthesis arg) const { return false; }
        bool operator()(iteration_sentinel arg) const { return false; }
    };

    struct is_additive_operation_visitor
    {
        using result_type = bool;

        bool operator()(add arg) const { return true; }
        bool operator()(subtract arg) const { return true; }
        bool operator()(multiply arg) const { return false; }
        bool operator()(divide arg) const { return false; }

        bool operator()(number arg) const { return false; }
        bool operator()(opening_parenthesis arg) const { return false; }
        bool operator()(closing_parenthesis arg) const { return false; }
        bool operator()(iteration_sentinel arg) const { return false; }
    };

    struct calculation_visitor
    {

        calculation_visitor(int a_a, int a_b) : a(a_a), b(a_b) {}
        using result_type = int;

        int operator()(add arg) const { return a + b; }
        int operator()(subtract arg) const { return a - b; }
        int operator()(multiply arg) const { return a * b; }

        int operator()(divide arg) const
        {
            if (b == 0)
                throw CalcError("Error division by zero"s);

            return a / b;
        }

        int operator()(number arg) const { return arg.get_number(); }
        int operator()(opening_parenthesis arg) const { return 0; }
        int operator()(closing_parenthesis arg) const { return 0; }
        int operator()(iteration_sentinel arg) const { return 0; }

    private:
        int a;
        int b;
    };

}
