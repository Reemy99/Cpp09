#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>


class RPN
{
    private:
    public:

    RPN();
    ~RPN();

    double execute(const std::string &value);
};

#endif
