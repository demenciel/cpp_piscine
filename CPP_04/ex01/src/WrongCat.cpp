#include "../inc/WrongCat.hpp"
using std::cin;
using std::cout;
using std::endl;
WrongCat::WrongCat()
{
      std::cout << "WrongCat constructor is called" << std::endl;
      this->type = "Wrong Cat";
};

WrongCat::WrongCat(WrongCat const *copy)
{
      std::cout << "WrongCat copy constructor is called" << std::endl;
      *this = copy;
};
WrongCat &WrongCat::operator=(WrongCat const &rhs)
{
      if (this == &rhs)
            return *this;
      this->type = rhs.type;
      return *this;
};

WrongCat::~WrongCat()
{
      std::cout << "WrongCat destructor is called" << std::endl;
};

