#include "../inc/Dog.hpp"

using std::cout;
using std::endl;
Dog::Dog()
{
      std::cout << "Dog constructor is called" << std::endl;
      type = "Dog";
      brain = new Brain();
};

Dog::Dog(Dog const &copy)
{
      std::cout << "Dog copy constructor is called" << std::endl;
      type = copy.type;
      brain = new Brain(*copy.brain);
};

Dog &Dog::operator=(Dog const &rhs)
{
      if (this == &rhs)
      {
            return *this;
      }
      type = rhs.type;
      delete brain;                 
      brain = new Brain(*rhs.brain);
      return *this;
};

Dog::~Dog()
{
      std::cout << "Dog destructor is called" << std::endl;
      delete brain;
};

void Dog::makeSound() const
{
      cout << "Woooof" << endl;
}