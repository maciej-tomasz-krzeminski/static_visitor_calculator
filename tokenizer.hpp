#pragma once

#include <vector>
#include <string>
#include "token_types.hpp"

namespace calcs
{

    class Tokenizer
    {
    public:
        Tokenizer(const std::string &a_s) : s(a_s) {}

        std::vector<token_t> tokenize(const std::string &str);

    private:
        std::string s;
    };

}
