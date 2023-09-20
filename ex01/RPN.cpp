#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

double RPN::execute(const std::string &value)
{
    std::string token;
    std::stack<int> numbers;
    std::istringstream iss(value); 

    while (iss >> token)
    {
        if (token.find_first_not_of("0123456789 -+*/") != std::string::npos)
                throw std::runtime_error("Invalid expression");
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-' && isdigit(token[1])))
            numbers.push(atoi(token.c_str()));
        else if(token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (numbers.size() < 2)
            {
                std::cerr << "ERROR: Not enough numbers for operator" << token << std::endl;
                return 0;
            }
            int nb2 = numbers.top();
            numbers.pop();
            
            int nb3 = numbers.top();
            numbers.pop();

            int result;
            if (token == "+"){
                result = nb2 + nb3;
            }
            if (token == "-"){
                result = nb3 - nb2;
            }
            if (token == "*"){
                result = nb2 * nb3;
            }
            if (token == "/"){
                result = nb2 / nb3;
            }
            numbers.push(result);
        }
    }
    if (numbers.size() != 1)
    {
        std::cerr << "Error: Not enough operators" << std::endl;
        return 0;
    }
    return numbers.top();
}
