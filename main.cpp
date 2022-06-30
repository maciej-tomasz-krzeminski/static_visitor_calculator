#include <string>
#include <cassert>

#include "tokenizer.hpp"
#include "parser.hpp"

#define asser1(arg) assert(arg)

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
        asser1("Error empty input" == calc(""));
        asser1("2" == calc("2"));
        asser1("3" == calc("3"));
        asser1("4" == calc(" 4 "));
        asser1("5" == calc("2+3"));
        asser1("7" == calc("2 + 5"));
        asser1("3" == calc("4-1"));
        asser1("15" == calc("5*3"));
        asser1("4" == calc("16/4"));
        asser1("55" == calc("7*8+ (3-4)"));
        asser1("Error division by zero" == calc("4/0"));
        asser1("Syntax error: missing parenthesis or number" == calc("()"));
        asser1("Syntax error: Missing closing parenthesis" == calc("2*(3+4"));
        // asser1("Syntax error: Missing closing parenthesis" == calc("2*)3+4")); TODO - unexpected token
        // asser1("Syntax error: Missing closing parenthesis" == calc("2*^3+4")); TODO - unexpected token
    }
}

int main()
{
    calcs::test_first();
    return 0;
}
