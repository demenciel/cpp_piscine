#ifndef DOG_HPP
#define DOG_HPP

#include "../inc/Animal.hpp"
#include "../inc/Brain.hpp"
#include <iostream>

class Dog : public Animal
{
private:
    Brain *brain;
public:
    Dog();
    Dog(Dog const &copy);
    Dog &operator=(Dog const &rhs);
    ~Dog();

    void makeSound() const;
};

#endif