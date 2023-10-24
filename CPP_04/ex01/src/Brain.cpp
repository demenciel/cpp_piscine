#include "../inc/Brain.hpp"
using std::cin;
using std::cout;
using std::endl;
Brain::Brain()
{
        cout << "Brain constructor is called" << endl;
}

Brain::Brain(Brain const &copy)
{
        cout << "Brain copy constructor is called" << endl;
        for (int i = 0; i < 100; ++i)
        {
                ideas[i] = copy.ideas[i];
        }
}

Brain &Brain::operator=(const Brain &rhs)
{
        if (this == &rhs)
        {
                return *this;
        }
        for (int i = 0; i < 100; ++i)
        {
                ideas[i] = rhs.ideas[i];
        }

        return *this;
}

Brain::~Brain()
{
        cout << "Brain destructor is called" << endl;
}