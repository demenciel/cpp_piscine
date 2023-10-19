#include "../inc/Dog.hpp"

using std::cout;
using std::endl;
Dog::Dog()
{
      std::cout << "Dog constructor is called" << std::endl;
      this->type = "Dog";
};

Dog::Dog(Dog const &copy)
{
      std::cout << "Dog copy constructor is called" << std::endl;
      *this = copy;
};

Dog &Dog::operator=(Dog const &rhs)
{
      if (this == &rhs)
      {
            return *this;
      }
      this->type = rhs.type;

      return *this;
};

Dog::~Dog()
{
      std::cout << "Dog destructor is called" << std::endl;
};

void Dog::makeSound() const
{
      cout << "Woooof" << endl;
}