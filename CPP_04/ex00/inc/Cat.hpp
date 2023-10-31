#ifndef CAT_HPP
#define CAT_HPP
#pragma once
#include "../inc/Animal.hpp"
#include <iostream>

class Cat : public Animal
{
private:

public:
    Cat();
    Cat(Cat const &copy);
    Cat &operator=(Cat const &rhs);
    ~Cat();

    void makeSound() const;
};

#endif