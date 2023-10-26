#include "../inc/AMateria.hpp"
#include "../inc/Character.hpp"
using std::cin;
using std::cout;
using std::endl;

Character::Character()
{
      std::cout << "Character constructor is called" << std::endl;
      count = 0;
      for (int i = 0; i < 4; i++)
      {
            inventory[i] = nullptr;
      }
};

Character::Character(std::string const name)
{
      std::cout << "Character name constructor is called" << std::endl;
      this->name = name;
};

Character::Character(Character const &copy)
{
      std::cout << "Character copy constructor is called" << std::endl;
      this->count = copy.count;
      for (int i = 0; i < copy.count; i++)
      {
            this->inventory[i] = copy.inventory[i];
      }
};
Character &Character::operator=(Character const &rhs)
{
      if (this == &rhs)
            return *this;

      for (int i = 0; i < count; ++i)
      {
            delete inventory[i];
      }
      count = rhs.count;
      for (int i = 0; i < rhs.count; ++i)
      {
            inventory[i] = rhs.inventory[i];
      }

      return *this;
};

Character::~Character()
{
      std::cout << "Character destructor is called" << std::endl;
      for (int i = 0; i < this->count; i++)
      {
            delete inventory[i];
      }
};

std::string const &Character::getName()
{
      return this->name;
}

void Character::equip(AMateria *m)
{
      for (int i = 0; i < count; i++)
      {
            if (inventory[i] == nullptr)
            {
                  inventory[i] = m;
            }
      }
}

void Character::unequip(int idx){

};
void Character::use(int idx, ICharacter &target)
{
}