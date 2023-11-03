#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <exception>
#include <string>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class Convert
{
private:
public:
    Convert();
    Convert(Convert const *copy);
    Convert &operator=(Convert const &rhs);
    ~Convert();

    class ImpossibleException : public std::exception
    {
        public:
            const char *what() const throw();
    };
    
    bool is_number(const string &str);
    bool is_a_char(const string &str);

    bool isChar(const string &literal);
    bool isInt(const string &literal);
    bool isFloat(const string &literal);
    bool isDouble(const string &literal);

    char convertToChar(const string &literal);
    int convertToInt(const string &literal);
    float convertToFloat(const string &literal);
    double convertToDouble(const string &literal);
    void convertLiteral(const string &literal);
};


#endif