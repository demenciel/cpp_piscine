#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    std::string const name;
    int const signingGrade;
    int const execGrade;
    bool isSigned;

public:
    Form(std::string const &Name, int const SigningGrade, int const ExecGrade);
    Form(Form const &copy);
    Form &operator=(Form const &rhs);
    ~Form();

    // Exceptions
    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    // Getter & Setters
    std::string getFormName() const;
    bool getIsSigned() const;
    int getSigningGrade() const;
    int getExecGrade() const;

    // member functions
    void    beSigned(Bureaucrat &bureaucrat);
};
std::ostream &operator<<(std::ostream& os, const Form &form);

#endif