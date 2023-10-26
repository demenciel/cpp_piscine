#include "../inc/Ice.hpp"
using std::cin;
using std::cout;
using std::endl;
Ice::Ice()
{
      std::cout << "Ice constructor is called" << std::endl;
};

Ice::Ice(Ice const &copy)
{
      std::cout << "Ice copy constructor is called" << std::endl;
      type = copy.type;
};

Ice &Ice::operator=(Ice const &rhs)
{
      if (this == &rhs)
      {
            return *this;
      }
      this->type = rhs.type;
      return *this;
};

Ice::~Ice()
{
      std::cout << "Ice destructor is called" << std::endl;
};

const std::string &Ice::getType() const
{
      return type;
}

AMateria *Ice::clone() const
{
      return new Ice(*this);
}