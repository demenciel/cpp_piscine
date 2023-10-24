#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
private:
public:
    Brain();
    Brain(Brain const &copy);
    Brain &operator=(Brain const &rhs);
    ~Brain();
    std::string ideas[100];
};

#endif