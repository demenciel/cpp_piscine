#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#pragma once

#include "../inc/AMateria.hpp"
#include "../inc/ICharacter.hpp"
#include <iostream>

class Character : public ICharacter
{
private:
    std::string name;
    AMateria *inventory[4];
    int count;

public:
    Character();
    Character(std::string const name);
    Character(Character const &copy);
    Character &operator=(Character const &rhs);
    ~Character();

    std::string const &getName();
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
};

#endif