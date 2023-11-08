#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <vector>
#include <list>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    typedef typename std::deque<T>::iterator iterator;

    MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack<T>& src) : std::stack<T>(src) {}
    ~MutantStack() {}

    MutantStack& operator=(const MutantStack<T>& rhs)
    {
        if (this != &rhs)
        {
            std::stack<T>::operator=(rhs);
        }
        return *this;
    }

    iterator begin()
    {
        return std::stack<T>::c.begin();
    }

    iterator end()
    {
        return std::stack<T>::c.end();
    }
};
#endif