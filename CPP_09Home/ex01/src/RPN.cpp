#include "../inc/RPN.hpp"
using std::cin;
using std::cout;
using std::endl;
RPN::RPN()
{
        cout << "RPN constructor is called" << endl;
}

RPN::RPN(RPN const &copy)
{
        cout << "RPN copy constructor is called" << endl;
        *this = copy;
}

RPN &RPN::operator=(const RPN &rhs)
{
        if (this == &rhs)
        {
                return *this;
        }

        return *this;
}

RPN::~RPN()
{
        cout << "RPN destructor is called" << endl;
}

bool RPN::isNumber(std::string &token)
{
        for (size_t i = 0; i < token.length(); i++)
        {
                if (!isdigit(token[i]))
                {
                        return false;
                }
        }
        return true;
}

bool RPN::isOperator(const std::string &token)
{
        return token == "+" || token == "-" || token == "*" || token == "/";
}

double RPN::makeOperation(double &number1, double &number2, std::string &token)
{
        if (token == "+")
                return (number1 + number2);
        else if (token == "-")
                return (number1 - number2);
        else if (token == "*")
                return (number1 * number2);
        else if (token == "/")
        {
                if (number2 == 0)
                {
                        std::cerr << "Error: Division by zero" << std::endl;
                        return 1;
                }
                return (number1 / number2);
        }
        return 1;
}