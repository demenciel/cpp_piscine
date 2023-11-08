#include "../inc/MutantStack.hpp"

MutantStack::MutantStack() : std::stack<T, std::deque<T> >()
{
      std::cout << "MutantStack constructor is called" << std::endl;
};

MutantStack::MutantStack(MutantStack const *copy)
{
std::cout << "MutantStack copy constructor is called" << std::endl;
*this = copy;
};
MutantStack &MutantStack::operator=(MutantStack const &rhs)
{
};

MutantStack::~MutantStack()
{
      std::cout << "MutantStack destructor is called" << std::endl;
};