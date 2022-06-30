#include "token_types.hpp"
#include "visitor.hpp"

using namespace std::literals::string_literals;

namespace calcs
{

    template <typename tokenT, typename visitorT>
    int vis(tokenT &token, visitorT visitor)
    {

        number *n = dynamic_cast<number *>(token.get());
        n = n;
        return token->accept(visitor);
    }

    struct is_number_operation_visitor : public abstract_token_visitor
    {
        int operator()(add arg) const override { return false; }
        int operator()(subtract arg) const override { return false; }
        int operator()(multiply arg) const override { return false; }
        int operator()(divide arg) const override { return false; }

        int operator()(number arg) const override { return true; }
        int operator()(opening_parenthesis arg) const override { return false; }
        int operator()(closing_parenthesis arg) const override { return false; }
        int operator()(iteration_sentinel arg) const override { return false; }
    };

    struct is_open_parenthesis_visitor : public abstract_token_visitor
    {
        int operator()(add arg) const override { return false; }
        int operator()(subtract arg) const override { return false; }
        int operator()(multiply arg) const override { return false; }
        int operator()(divide arg) const override { return false; }

        int operator()(number arg) const override { return false; }
        int operator()(opening_parenthesis arg) const override { return true; }
        int operator()(closing_parenthesis arg) const override { return false; }
        int operator()(iteration_sentinel arg) const override { return false; }
    };

    struct is_close_parenthesis_visitor : public abstract_token_visitor
    {
        int operator()(add arg) const override { return false; }
        int operator()(subtract arg) const override { return false; }
        int operator()(multiply arg) const override { return false; }
        int operator()(divide arg) const override { return false; }

        int operator()(number arg) const override { return false; }
        int operator()(opening_parenthesis arg) const override { return false; }
        int operator()(closing_parenthesis arg) const override { return true; }
        int operator()(iteration_sentinel arg) const override { return false; }
    };

    struct is_multiplicative_operation_visitor : public abstract_token_visitor
    {
        int operator()(add arg) const override { return false; }
        int operator()(subtract arg) const override { return false; }
        int operator()(multiply arg) const override { return true; }
        int operator()(divide arg) const override { return true; }

        int operator()(number arg) const override { return false; }
        int operator()(opening_parenthesis arg) const override { return false; }
        int operator()(closing_parenthesis arg) const override { return false; }
        int operator()(iteration_sentinel arg) const override { return false; }
    };

    struct is_additive_operation_visitor : public abstract_token_visitor
    {
        int operator()(add arg) const override { return true; }
        int operator()(subtract arg) const override { return true; }
        int operator()(multiply arg) const override { return false; }
        int operator()(divide arg) const override { return false; }

        int operator()(number arg) const override { return false; }
        int operator()(opening_parenthesis arg) const override { return false; }
        int operator()(closing_parenthesis arg) const override { return false; }
        int operator()(iteration_sentinel arg) const override { return false; }
    };

    struct calculation_visitor : public abstract_token_visitor
    {

        calculation_visitor(int a_a, int a_b) : a(a_a), b(a_b) {}

        int operator()(add arg) const override { return a + b; }
        int operator()(subtract arg) const override { return a - b; }
        int operator()(multiply arg) const override { return a * b; }
        int operator()(divide arg) const override
        {
            if (b == 0)
                throw CalcError("Error division by zero"s);

            return a / b;
        }

        int operator()(number arg) const override { return arg.get_number(); }
        int operator()(opening_parenthesis arg) const override { return 0; }
        int operator()(closing_parenthesis arg) const override { return 0; }
        int operator()(iteration_sentinel arg) const override { return 0; }

    private:
        int a;
        int b;
    };

}
