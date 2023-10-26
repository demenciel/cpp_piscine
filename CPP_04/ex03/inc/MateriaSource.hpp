#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#pragma once

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
protected:
    AMateria* learnedMateria[4];
    int count;

public:
    MateriaSource();
    MateriaSource(MateriaSource const &copy);
    MateriaSource &operator=(MateriaSource const &rhs);
    virtual ~MateriaSource();

    virtual void learnMateria(AMateria *);
    virtual AMateria *createMateria(std::string const &);
};

#endif