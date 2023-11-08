#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <ostream>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> >
{
public:
    typedef typename std::deque<T>::iterator iterator;

    MutantStack();
    MutantStack(const MutantStack<T> &copy) : std::stack<T, std::deque<T> >(copy) {}
    MutantStack &operator=(const MutantStack<T> &rhs)
    {
        std::stack<T, std::deque<T> >::operator=(rhs);
        return *this;
    }
    ~MutantStack() {}

    iterator begin() { return std::stack<T, std::deque<T> >::c.begin(); }
    iterator end() { return std::stack<T, std::deque<T> >::c.end(); }
};

#endif