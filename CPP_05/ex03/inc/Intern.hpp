#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
private:
    Intern();

public:
    Intern(Intern const *copy);
    Intern &operator=(Intern const &rhs);
    ~Intern();
    typedef AForm *(*FormCreator)(std::string const &target);

    class   FormNotAvailableException : public std::exception {
        public:
            const char *what() const throw();
    };

    AForm   *makeForm(std::string const &formName, std::string const &target);
};

#endif