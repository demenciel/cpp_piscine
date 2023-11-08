#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <exception>
#include <numeric>

class Span
{
private:
    unsigned int _n;
    Span();

public:
    std::list<unsigned int> _list;
    class SpanIsFullException : std::exception
    {
        public:
            const char *what() const throw();
    };

    Span(unsigned int n);
    Span(Span const &copy);
    Span &operator=(Span const &rhs);
    ~Span();

    void addNumber(unsigned int input);
    template <typename Iterator>
    void addRange(Iterator begin, Iterator end)
    {
        if (std::distance(begin, end) + _list.size() > _n)
        {
            throw Span::SpanIsFullException();
        }

        _list.insert(_list.end(), begin, end);
    }
    unsigned int shortestSpan();
    unsigned int longestSpan();
    int getValue();
};
std::ostream &operator<<(std::ostream &out, Span &span);

#endif