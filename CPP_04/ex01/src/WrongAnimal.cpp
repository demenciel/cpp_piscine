#include "../inc/WrongAnimal.hpp"
using std::cin;
using std::cout;
using std::endl;
WrongAnimal::WrongAnimal()
{
      std::cout << "WrongAnimal constructor is called" << std::endl;
      this->type = "Wrong Animal";
};

WrongAnimal::WrongAnimal(WrongAnimal const *copy)
{
      std::cout << "WrongAnimal copy constructor is called" << std::endl;
      *this = copy;
};
WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs)
{
      if (this == &rhs)
            return *this;
      this->type = rhs.type;
      return *this;
};

WrongAnimal::~WrongAnimal()
{
      std::cout << "WrongAnimal destructor is called" << std::endl;
};

void WrongAnimal::makeSound() const
{
      cout << "Wrong animal sound" << endl;
}

std::string WrongAnimal::getType() const
{
      return this->type;
}