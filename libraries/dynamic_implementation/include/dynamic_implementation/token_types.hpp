#pragma once

#include <memory>
#include <iostream>
#include "visitor.hpp"

namespace calcs
{

    inline void print_implementation_used()
    {
        std::cout << "dynamic implementation in use\n";
    }

    class abstract_token
    {
    public:
        virtual int accept(const abstract_token_visitor &) const = 0;
        virtual ~abstract_token() = default;
    };

    class add : public abstract_token
    {
    public:
        virtual int accept(const abstract_token_visitor &v) const override { return v.operator()(*this); }
    };

    class subtract : public abstract_token
    {
    public:
        virtual int accept(const abstract_token_visitor &v) const override { return v.operator()(*this); }
    };

    class multiply : public abstract_token
    {
    public:
        virtual int accept(const abstract_token_visitor &v) const override { return v.operator()(*this); }
    };

    class divide : public abstract_token
    {
    public:
        virtual int accept(const abstract_token_visitor &v) const override { return v.operator()(*this); }
    };

    class opening_parenthesis : public abstract_token
    {
        virtual int accept(const abstract_token_visitor &v) const override { return v.operator()(*this); }
    };

    class closing_parenthesis : public abstract_token
    {
        virtual int accept(const abstract_token_visitor &v) const override { return v.operator()(*this); }
    };

    class number : public abstract_token
    {
    public:
        number(int a_n) : n(a_n) {}
        number() : n(0) {}
        int get_number() const { return n; }
        virtual int accept(const abstract_token_visitor &v) const override { return v.operator()(*this); }

    private:
        int n;
    };

    class iteration_sentinel : public abstract_token
    {
        virtual int accept(const abstract_token_visitor &v) const override { return v.operator()(*this); }
    };

    using abstract_token_ptr = std::unique_ptr<abstract_token>;

    using token_t = abstract_token_ptr;

    template <typename tokenT>
    void token_assign(token_t &tok_to_assign, tokenT value)
    {
        tok_to_assign.reset(new tokenT(value));
    }

}
