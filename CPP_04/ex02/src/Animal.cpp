#include "../inc/Animal.hpp"

using std::cout;
using std::endl;
Animal::Animal()
{
      cout << "Animal constructor is called" << endl;
      this->type = "Animal";
}

Animal::Animal(Animal const &copy)
{
      cout << "Animal copy constructor is called" << endl;
      *this = copy;
}

Animal &Animal::operator=(const Animal &rhs)
{
      if (this == &rhs)
      {
            return *this;
      }
      this->type = rhs.type;

      return *this;
}

Animal::~Animal()
{
      cout << "Animal destructor is called" << endl;
}

void Animal::makeSound() const
{
      cout << this->type << " does not make a sound" << endl;
}

std::string Animal::getType() const
{
      return this->type;
}