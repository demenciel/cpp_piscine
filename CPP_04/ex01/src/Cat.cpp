#include "../inc/Cat.hpp"

using std::cout;
using std::endl;
Cat::Cat()
{
      std::cout << "Cat constructor is called" << std::endl;
      type = "Cat";
      brain = new Brain();
}

Cat::Cat(Cat const &copy)
{
      std::cout << "Cat copy constructor is called" << std::endl;
      type = copy.type;
      brain = new Brain(*copy.brain);
}

Cat &Cat::operator=(Cat const &rhs)
{
      if (this == &rhs)
      {
            return *this;
      }
      type = rhs.type;
      delete brain;
      brain = new Brain(*rhs.brain);
      return *this;
}

Cat::~Cat()
{
      std::cout << "Cat destructor is called" << std::endl;
      delete brain;
}

void Cat::makeSound() const
{
      cout << "Meooww" << endl;
}
