#pragma once

#include <vector>

#include "token_types.hpp"

namespace calcs
{

    class Parser
    {
    public:
        Parser(std::vector<token_t> a_tokens);
        int parse();

    private:
        int parse_primary_expression();
        int parse_multiplicative_expression();
        int parse_additive_epression();

        const token_t &get_token() { return tokens[i]; }
        void eat_token() { ++i; }

        size_t i = 0;
        std::vector<token_t> tokens;
    };

}
