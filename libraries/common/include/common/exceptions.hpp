#pragma once

#include <stdexcept>
#include <string>

namespace static_variant_showcase
{

class CalcError : public std::runtime_error
{
public:
    CalcError(const std::string &what) : runtime_error(what) {}
};

}
