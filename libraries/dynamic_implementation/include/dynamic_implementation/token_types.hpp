#pragma once

#include <memory>
#include <iostream>
#include "visitor.hpp"


namespace static_variant_showcase
{

inline void print_implementation_used()
{
    std::cout << "dynamic implementation in use\n";
}


class abstract_token
{
public:
    virtual int accept(const abstract_token_visitor&)const = 0;
    virtual ~abstract_token() = default;
};


class add : public abstract_token
{
public:
    add() : a(0), b(0) {}
    virtual int accept(const abstract_token_visitor&v) const override{return v.operator()(*this);}
private:
    int a;
    int b;
};

class subtract : public abstract_token
{
public:
    subtract(int a_a, int b_b) : a(a_a), b(b_b) {}
    subtract() : a(0), b(0) {}
    int difference() { return a - b; }
    virtual int accept(const abstract_token_visitor&v) const override{return v.operator()(*this);}

private:
    int a;
    int b;
};

class multiply : public abstract_token
{
public:
    multiply(int a_a, int b_b) : a(a_a), b(b_b) {}
    multiply() : a(0), b(0) {}
    int product() { return a * b; }
    virtual int accept(const abstract_token_visitor&v) const override{return v.operator()(*this);}

private:
    int a;
    int b;
};

class divide : public abstract_token
{
public:
    divide(int a_a, int b_b) : a(a_a), b(b_b) {}
    divide() : a(0), b(0) {}
    int division() { return a / b; }
    virtual int accept(const abstract_token_visitor&v) const override{return v.operator()(*this);}

private:
    int a;
    int b;
};

class opening_parenthesis : public abstract_token
{
    virtual int accept(const abstract_token_visitor&v) const override{return v.operator()(*this);}
};

class closing_parenthesis : public abstract_token
{
    virtual int accept(const abstract_token_visitor&v) const override{return v.operator()(*this);}
};

class number : public abstract_token
{
public:
    number(int a_n) : n(a_n) {}
    number() : n(0) {}
    int get_number() const { return n; }
    virtual int accept(const abstract_token_visitor&v) const override{return v.operator()(*this);}

private:
    int n;
};

class iteration_sentinel : public abstract_token
{
    virtual int accept(const abstract_token_visitor&v) const override {return v.operator()(*this);}
};

using abstract_token_ptr = std::unique_ptr<abstract_token>;

using token_t = abstract_token_ptr;

template<typename tokenT>
void token_assign(token_t& tok_to_assign, tokenT value)
{
    tok_to_assign.reset(new tokenT(value));
}
//TODO above func in other token_type - here at the end of header

}
