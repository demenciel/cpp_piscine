#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#pragma once

#include <iostream>


class Animal
{
protected:
    std::string type;

public:
    Animal();
    Animal(Animal const &copy);
    Animal &operator=(Animal const &rhs);
    virtual ~Animal();

    virtual void makeSound() const;
    std::string getType() const;
};

#endif