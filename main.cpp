#include <string>
#include <cassert>

#include "tokenizer.hpp"
#include "parser.hpp"

#define ASSERT(arg) assert(arg)

namespace calcs
{

    std::string calc(const std::string &s)
    {
        if (s.empty())
            return "Error empty input";

        Tokenizer tokenizer(s);

        try
        {
            auto container = tokenizer.tokenize(s);
            auto calulation_result = Parser(std::move(container)).parse();
            return std::to_string(calulation_result);
        }
        catch (const std::exception &e) // TODO - particlar exceptions here, not everyting
        {
            std::string s = e.what();
            return s;
        }
    }

    void test_first()
    {
        print_implementation_used();
        ASSERT("Error empty input" == calc(""));
        ASSERT("2" == calc("2"));
        ASSERT("3" == calc("3"));
        ASSERT("4" == calc(" 4 "));
        ASSERT("5" == calc("2+3"));
        ASSERT("7" == calc("2 + 5"));
        ASSERT("3" == calc("4-1"));
        ASSERT("15" == calc("5*3"));
        ASSERT("4" == calc("16/4"));
        ASSERT("55" == calc("7*8+ (3-4)"));
        ASSERT("Arithmetic error: division by zero" == calc("4/0"));
        ASSERT("Syntax error: missing parenthesis or number" == calc("()"));
        ASSERT("Syntax error: Missing closing parenthesis" == calc("2*(3+4"));
        ASSERT("Syntax error: missing parenthesis or number" == calc("2*)3+4"));
        ASSERT("Lexer error: unexpected token ^" == calc("2*^3+4"));
    }
}

int main()
{
    calcs::test_first();
    return 0;
}
