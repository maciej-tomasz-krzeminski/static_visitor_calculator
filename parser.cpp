#include "common/exceptions.hpp"
#include "visitors.hpp"
#include "parser.hpp"

using namespace std::literals::string_literals;
namespace calcs
{

    int Parser::parse_primary_expression()
    {
        if (visitate(get_token(), is_number_operation_visitor()))
        {
            const token_t &token = get_token();
            eat_token();
            calculation_visitor calc_vo(0, 0);
            return visitate(token, calc_vo);
        }
        else if (visitate(get_token(), is_open_parenthesis_visitor()))
        {
            eat_token();
            int a = parse_additive_epression();
            if (visitate(get_token(), is_close_parenthesis_visitor()))
            {
                eat_token();
                return a;
            }
            else
            {
                throw CalcError("Syntax error: Missing closing parenthesis");
            }
        }
        throw CalcError("Syntax error: missing parenthesis or number");
        return 0;
    }

    int Parser::parse_multiplicative_expression()
    {
        int a = parse_primary_expression();

        while (visitate(get_token(), is_multiplicative_operation_visitor()))
        {
            const token_t &token = get_token();
            eat_token();
            int b = parse_primary_expression();
            calculation_visitor calc_vo(a, b);
            a = visitate(token, calc_vo);
        }
        return a;
    }

    int Parser::parse_additive_epression()
    {
        int a = parse_multiplicative_expression();

        while (visitate(get_token(), is_additive_operation_visitor()))
        {
            const token_t &token = get_token();
            eat_token();
            int b = parse_multiplicative_expression();
            calculation_visitor calc_vo(a, b);
            a = visitate(token, calc_vo);
        }
        return a;
    }

    int Parser::parse()
    {
        return Parser::parse_additive_epression();
    }

    Parser::Parser(std::vector<token_t> a_tokens) : tokens(std::move(a_tokens)) {}

}
