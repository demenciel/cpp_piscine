#include "../inc/PMergeMe.hpp"

using std::cin;
using std::cout;
using std::endl;

PMergeMe::PMergeMe() {}

PMergeMe::PMergeMe(PMergeMe const &copy)
{
        cout << "PMergeMe copy constructor is called" << endl;
        *this = copy;
}

PMergeMe &PMergeMe::operator=(const PMergeMe &rhs)
{
        if (this == &rhs)
        {
                return *this;
        }
        return *this;
}

PMergeMe::~PMergeMe() {}

const char *PMergeMe::NumberIsNotValidException::what() const throw()
{
        return "Error: Invalid input";
}
