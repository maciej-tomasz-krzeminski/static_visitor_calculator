#include <regex>

#include "tokenizer.hpp"
#include "token_types.hpp"
#include "common/exceptions.hpp"

using namespace std::literals::string_literals;


namespace static_variant_showcase
{

std::vector<token_t> Tokenizer::tokenize(const std::string &str)
{
    const std::regex re(R"(\s*(\d+|\S)\s*)");
    std::sregex_token_iterator it{str.begin(), str.end(), re, 1};
    std::vector<token_t> tokens;

    for (; it != std::sregex_token_iterator(); ++it)
    {
        const std::string &s = (*it);
        if (s.empty())
            continue;

        token_t tok;
        switch (s[0])
        {
        case '+':
            token_assign(tok, add());//TODO it is enough to pass just type of token, no need to construct one
            break;
        case '-':
            token_assign(tok, subtract());
            break;
        case '*':
            token_assign(tok, multiply());
            break;
        case '/':
            token_assign(tok, divide());
            break;
        case '(':
            token_assign(tok, opening_parenthesis());
            break;
        case ')':
            token_assign(tok, closing_parenthesis());
            break;
        default:
            if (std::isdigit(s[0]))
                token_assign(tok, number(std::stoi(s)));
            else
                throw CalcError("Unexpected token "s + s[0]);
        }
        tokens.push_back(std::move(tok));
    }
    token_t tok;
    token_assign(tok, iteration_sentinel());
    tokens.push_back(std::move(tok));
    return tokens;
}


//TODO: cli
}