#ifndef ICE_HPP
#define ICE_HPP

#include "../inc/AMateria.hpp"
#include <iostream>

class Ice : public AMateria
{
private:
public:
    Ice();
    Ice(Ice const &copy);
    Ice &operator=(Ice const &rhs);
    ~Ice();

    std::string const &getType() const;
    virtual AMateria *clone() const;
};

#endif