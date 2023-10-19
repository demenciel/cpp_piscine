#include "../inc/Cat.hpp"


using std::cout;
using std::endl;
Cat::Cat()
{
      std::cout << "Cat constructor is called" << std::endl;
      this->type = "Cat";
}

Cat::Cat(Cat const &copy)
{
      std::cout << "Cat copy constructor is called" << std::endl;
      *this = copy;
}

Cat &Cat::operator=(Cat const &rhs)
{
      if (this == &rhs) {
        return *this;
    }
    this->type = rhs.type;

    return *this;
}

Cat::~Cat()
{
      std::cout << "Cat destructor is called" << std::endl;
}

void Cat::makeSound() const
{
      cout << "Meooww" << endl;
}

