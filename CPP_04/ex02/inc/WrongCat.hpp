#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:

public:
    WrongCat();
    WrongCat(WrongCat const *copy);
    WrongCat &operator=(WrongCat const &rhs);
    ~WrongCat();


};

#endif