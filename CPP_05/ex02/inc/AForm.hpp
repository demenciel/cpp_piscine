#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    std::string const name;
    int const signingGrade;
    int const execGrade;
    bool isSigned;
    AForm();

public:
    AForm(std::string const &Name, int const SigningGrade, int const ExecGrade);
    AForm(AForm const &copy);
    AForm &operator=(AForm const &rhs);
    ~AForm();

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

    class FormNotSignedException : public std::exception
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
    void    virtual beSigned(Bureaucrat &bureaucrat) = 0;
    void    virtual execute(Bureaucrat const &executor) const = 0;
};
std::ostream &operator<<(std::ostream& os, const AForm &Aform);

#endif