#include "../inc/AMateria.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

AMateria::AMateria()
{
      cout << "AMateria constructor is called" << endl;
};

AMateria::AMateria(std::string const &type)
{
      cout << "AMateria type: " << type << endl;
      cout << "AMateria constructor is called" << endl;
};

AMateria::AMateria(AMateria const &copy)
{
      cout << "AMateria copy constructor is called" << endl;
      this->type = copy.type;
};

AMateria &AMateria::operator=(AMateria const &rhs)
{
      if (this == &rhs)
            return *this;
      type = rhs.type;
      return *this;
};

AMateria::~AMateria()
{
      cout << "AMateria destructor is called" << endl;
};

void AMateria::use(ICharacter &target)
{
      cout << this->type << "* shoots an ice bolt at " << target.getName() << endl;
}

const std::string &AMateria::getType() const
{
      return type;
}