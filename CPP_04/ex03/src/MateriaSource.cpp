#include "../inc/MateriaSource.hpp"

using std::cin;
using std::cout;
using std::endl;
MateriaSource::MateriaSource()
{
      std::cout << "MateriaSource constructor is called" << std::endl;
      count = 0;
      for (int i = 0; i < 4; i++)
      {
            learnedMateria[i] = nullptr;
      }
};

MateriaSource::MateriaSource(MateriaSource const &copy)
{
      std::cout << "MateriaSource copy constructor is called" << std::endl;
      this->count = copy.count;
      for (int i = 0; i < copy.count; i++)
      {
            this->learnedMateria[i] = copy.learnedMateria[i];
      }
};
MateriaSource &MateriaSource::operator=(MateriaSource const &rhs)
{
      if (this == &rhs)
            return *this;

      for (int i = 0; i < count; ++i)
      {
            delete learnedMateria[i];
      }
      count = rhs.count;
      for (int i = 0; i < rhs.count; ++i)
      {
            learnedMateria[i] = rhs.learnedMateria[i]->clone();
      }

      return *this;
};

MateriaSource::~MateriaSource()
{
      for (int i = 0; i < count; i++)
      {
            delete learnedMateria[i];
      }
      std::cout << "MateriaSource destructor is called" << std::endl;
};

void MateriaSource::learnMateria(AMateria *materia)
{
      if (count < 4 && materia)
      {
            learnedMateria[count] = materia->clone();
            count++;
      }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
      for (int i = 0; i < count; i++) // Loop through learned materia
      {
            if (learnedMateria[i]->getType() == type) // Check if the type matches
            {
                  return learnedMateria[i]->clone(); // Return a clone of the matching materia
            }
      }
      return nullptr;
}
