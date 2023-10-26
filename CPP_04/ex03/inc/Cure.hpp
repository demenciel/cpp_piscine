#ifndef CURE_HPP
#define CURE_HPP

#include "../inc/AMateria.hpp"
#include <iostream>

class Cure : public AMateria
{
private:

public:
    Cure();
    Cure(Cure const &copy);
    Cure &operator=(Cure const &rhs);
    ~Cure();

    std::string const &getType() const;
    virtual AMateria *clone() const;
};

#endif