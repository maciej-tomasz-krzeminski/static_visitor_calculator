#pragma once

namespace calcs
{

    class add;
    class subtract;
    class multiply;
    class divide;

    class number;
    class opening_parenthesis;
    class closing_parenthesis;
    class iteration_sentinel;

    struct abstract_token_visitor
    {
        virtual int operator()(add arg) const = 0;
        virtual int operator()(subtract arg) const = 0;
        virtual int operator()(multiply arg) const = 0;
        virtual int operator()(divide arg) const = 0;

        virtual int operator()(number arg) const = 0;
        virtual int operator()(opening_parenthesis arg) const = 0;
        virtual int operator()(closing_parenthesis arg) const = 0;
        virtual int operator()(iteration_sentinel arg) const = 0;
    };

}
