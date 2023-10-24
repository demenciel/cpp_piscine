#ifndef CAT_HPP
#define CAT_HPP

#include "../inc/Animal.hpp"
#include "../inc/Brain.hpp"
#include <iostream>
/* Ainsi, les classes Dog et Cat auront un attribut privé Brain*. */

class Cat : public Animal
{
private:
    Brain *brain;
public:
    Cat();
    Cat(Cat const &copy);
    Cat &operator=(Cat const &rhs);
    ~Cat();

    void makeSound() const;

};

#endif