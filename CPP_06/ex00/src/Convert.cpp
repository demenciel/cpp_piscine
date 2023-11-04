#include "../inc/Convert.hpp"

using std::cerr;
using std::cout;
using std::endl;
using std::string;

// EXCEPTIONS
const char *Convert::ImpossibleException::what() const throw()
{
      return "impossible";
};

Convert::Convert()
{
      cout << "Convert constructor is called" << endl;
};

Convert::Convert(Convert const *copy)
{
      cout << "Convert copy constructor is called" << endl;
      *this = copy;
};
Convert &Convert::operator=(Convert const &rhs)
{
      if (this == &rhs)
      {
            return *this;
      }
      return *this;
};

Convert::~Convert()
{
      std::cout << "Convert destructor is called" << std::endl;
};

bool Convert::is_number(const string &str)
{
      for (size_t i = 0; i < str.length(); i++)
      {
            if (!isdigit(str[i]))
            {
                  return false;
            }
      }
      return true;
}

bool Convert::is_a_char(const string &str)
{
      for (size_t i = 0; i < str.length(); i++)
      {
            if (!isalpha(str[i]))
            {
                  return false;
            }
      }
      return true;
}

bool Convert::isChar(const string &literal)
{
      if (!literal.empty() && literal.length() == 1 && isprint(literal[0]) && isalpha(literal[0]))
            return true;
      return false;
};

bool Convert::isInt(const std::string &literal)
{
      if (literal.empty())
            return false;
      if (literal == "-inff" || literal == "+inff" || literal == "nanf" || literal == "-inf" || literal == "+inf" || literal == "nan")
            return false;
      size_t startIndex = (literal[0] == '-' || literal[0] == '+') ? 1 : 0;
      if (startIndex == 1 && literal.size() == 1)
            return false;

      for (size_t i = startIndex; i < literal.size(); ++i)
      {
            if (!isdigit(literal[i]))
                  return false;
      }

      try
      {
            long long number = std::stoll(literal);
            if (number < INT_MIN || number > INT_MAX)
                  return false;
      }
      catch (const std::out_of_range &e)
      {
            return false;
      }
      catch (const std::invalid_argument &e)
      {
            return false;
      }

      return true;
};

bool Convert::isFloat(const string &literal)
{
      int fCount = 0;
      if (!literal.empty())
      {
            if (literal == "-inff" || literal == "+inff" || literal == "nanf")
                  return true;
            size_t startIndex = (literal[0] == '-' || literal[0] == '+') ? 1 : 0;
            if ((startIndex == 1 && literal.size() == 1) || !isdigit(literal[startIndex]))
                  return false;
            if (literal[literal.size() - 1] != 'f')
                  return false;
            int fIndex = literal.find('.');
            if (literal[fIndex + 1] == '\0' || literal[fIndex + 1] == 'f')
                  return false;
            for (size_t i = startIndex; i < literal.size(); i++)
            {
                  if (!isdigit(literal[i]) && literal[i] != '.' && literal[i] != 'f')
                        return false;
                  if (literal[i] == 'f')
                        fCount++;
            }
            if (fCount > 1)
                  return false;
            return true;
      }
      return false;
};

bool Convert::isDouble(const string &literal)
{
      if (!literal.empty())
      {
            if (literal == "-inf" || literal == "+inf" || literal == "nan")
                  return true;
            size_t startIndex = (literal[0] == '-' || literal[0] == '+') ? 1 : 0;
            if ((startIndex == 1 && literal.size() == 1) || !isdigit(literal[startIndex]))
                  return false;
            int fIndex = literal.find('.');
            if (fIndex == -1)
                  return false;
            if (literal[fIndex + 1] == '\0')
                  return false;
            for (size_t i = startIndex; i < literal.size(); i++)
            {
                  if (!isdigit(literal[i]) && literal[i] != '.')
                        return false;
            }
            return true;
      }
      return false;
};

char Convert::convertToChar(const string &literal)
{
      if (literal == "-inff" || literal == "+inff" || literal == "nanf" || literal == "-inf" || literal == "+inf" || literal == "nan")
            throw ImpossibleException();
      else if (isChar(literal))
            return literal[0];
      else if (isInt(literal))
            return static_cast<char>(std::stoi(literal));
      else if (isFloat(literal))
            return static_cast<char>(std::stof(literal));
      else if (isDouble(literal))
            return static_cast<char>(std::stod(literal));
      else
            throw ImpossibleException();
};

int Convert::convertToInt(const string &literal)
{
      if (literal == "-inff" || literal == "+inff" || literal == "nanf" || literal == "-inf" || literal == "+inf" || literal == "nan")
            throw ImpossibleException();
      else if (isChar(literal))
            return static_cast<int>(literal[0]);
      else if (isInt(literal))
            return std::stoi(literal);
      else if (isFloat(literal))
            return static_cast<int>(std::stof(literal));
      else if (isDouble(literal))
            return static_cast<int>(std::stod(literal));
      else
            throw ImpossibleException();
};

float Convert::convertToFloat(const string &literal)
{
      if (literal == "-inff")
            return -std::numeric_limits<float>::infinity();
      else if (literal == "+inff")
            return std::numeric_limits<float>::infinity();
      else if (literal == "nanf")
            return std::numeric_limits<float>::quiet_NaN();
      else if (isChar(literal))
            return static_cast<float>(literal[0]);
      else if (isInt(literal))
            return static_cast<float>(std::stoi(literal));
      else if (isFloat(literal))
            return std::stof(literal);
      else if (isDouble(literal))
            return static_cast<float>(std::stod(literal));
      else
            throw ImpossibleException();
};

double Convert::convertToDouble(const string &literal)
{
      if (literal == "-inf")
            return -std::numeric_limits<double>::infinity();
      else if (literal == "+inf")
            return std::numeric_limits<double>::infinity();
      else if (literal == "nan")
            return std::numeric_limits<double>::quiet_NaN();
      else if (isChar(literal))
            return static_cast<double>(literal[0]);
      else if (isInt(literal))
            return static_cast<double>(std::stoi(literal));
      else if (isFloat(literal))
            return static_cast<double>(std::stof(literal));
      else if (isDouble(literal))
            return std::stod(literal);
      else
            throw ImpossibleException();
};

void Convert::convertLiteral(const string &literal)
{
      cout << "char: ";
      try
      {
            char c = convertToChar(literal);
            if (isprint(c))
                  cout << "'" << c << "'" << endl;
            else
                  cout << "Non displayable" << endl;
      }
      catch (const ImpossibleException &e)
      {
            cout << e.what() << endl;
      }

      cout << "int: ";
      try
      {
            int i = convertToInt(literal);
            cout << i << endl;
      }
      catch (const ImpossibleException &e)
      {
            cout << e.what() << endl;
      }

      cout << "float: ";
      try
      {
            float f = convertToFloat(literal);
            cout << std::fixed << std::setprecision(1) << f << 'f' << std::endl;
      }
      catch (const ImpossibleException &e)
      {
            cout << e.what() << endl;
      }

      cout << "double: ";
      try
      {
            double d = convertToDouble(literal);
            cout << std::fixed << std::setprecision(1) << d << std::endl;
      }
      catch (const ImpossibleException &e)
      {
            cout << e.what() << endl;
      }
};