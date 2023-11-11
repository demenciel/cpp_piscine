#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>

class RPN
{
public:
    std::stack<double> RPNstack;
    bool isNumber(std::string &token);
    bool isOperator(const std::string &token);
    double makeOperation(double &number1, double &number2, std::string &token);
    RPN();
    RPN(RPN const &copy);
    RPN &operator=(RPN const &rhs);
    ~RPN();

};

#endif