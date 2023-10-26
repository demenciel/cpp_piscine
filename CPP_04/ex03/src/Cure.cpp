#include "../inc/Cure.hpp"

using std::cin;
using std::cout;
using std::endl;

Cure::Cure()
{
      cout << "Cure constructor is called" << std::endl;
      type = "cure";
};

Cure::Cure(Cure const &copy)
{
      std::cout << "Cure copy constructor is called" << std::endl;
      type = copy.type;
};
Cure &Cure::operator=(Cure const &rhs)
{
      if (this == &rhs)
      {
            return *this;
      }
      this->type = rhs.type;
      return *this;
};

Cure::~Cure()
{
      std::cout << "Cure destructor is called" << std::endl;
};

const std::string &Cure::getType() const
{
      return type;
}

AMateria *Cure::clone() const
{
      return new Cure(*this);
}