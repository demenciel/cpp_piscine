#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    std::string const target;
    PresidentialPardonForm();

public:
    PresidentialPardonForm(std::string const &target);
    PresidentialPardonForm(PresidentialPardonForm const &copy);
    PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);
    ~PresidentialPardonForm();

    // member functions
    void    virtual execute(Bureaucrat const &executor) const;
};

#endif