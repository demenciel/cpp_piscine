#include "../inc/Span.hpp"

Span::Span(unsigned int n) : _n(n)
{
    std::cout << "Span constructor is called" << std::endl;
}

Span::Span(const Span &copy) : _n(copy._n), _list(copy._list)
{
    std::cout << "Span copy constructor is called" << std::endl;
}

Span &Span::operator=(const Span &rhs)
{
    if (this != &rhs)
        _n = rhs._n;
    return *this;
}

Span::~Span()
{
    std::cout << "Span destructor is called" << std::endl;
}

void Span::addNumber(unsigned int input)
{
    if (_list.size() < _n)
        _list.push_back(input);
    else
    {
        throw Span::SpanIsFullException();
    }
}

unsigned int Span::shortestSpan()
{
    if (_list.size() < 2)
    {
        throw Span::SpanIsFullException();
    }

    std::list<unsigned int> sorted_list(_list);
    sorted_list.sort();

    unsigned int shortest_span = UINT_MAX;
    std::list<unsigned int>::iterator it = sorted_list.begin();
    std::list<unsigned int>::iterator next_it = std::next(it);

    while (next_it != sorted_list.end())
    {
        unsigned int span = *next_it - *it;
        if (span < shortest_span)
        {
            shortest_span = span;
        }
        it = next_it;
        ++next_it;
    }

    return shortest_span;
}

unsigned int Span::longestSpan()
{
    if (_list.size() < 2)
    {
        throw Span::SpanIsFullException();
    }
    std::list<unsigned int> sorted_list(_list);
    sorted_list.sort();

    return sorted_list.back() - sorted_list.front();
}

// GETTER
int Span::getValue()
{
    return _n;
}

// STREAM OVERLOAD TO PRINT LIST
std::ostream &operator<<(std::ostream &out, Span &span)
{
    for (std::list<unsigned int>::iterator i = span._list.begin(); i != span._list.end(); ++i)
        out << *i << ", ";
    std::cout << std::endl;
    return out;
}

const char* Span::SpanIsFullException::what() const throw()
{
    return ("Span is full!");
}