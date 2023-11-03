#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
private:
    std::string const name;
    int grade;
    Bureaucrat();

public:
    // Coplien
    Bureaucrat(std::string const &Name, int Grade);
    Bureaucrat(Bureaucrat const &copy);
    Bureaucrat &operator=(Bureaucrat const &rhs);
    ~Bureaucrat();

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
    std::string getName() const;
    int getGrade() const;

    // member function
    void    incrementGrade(int inc);
    void    decrementGrade(int dec);
};
std::ostream &operator<<(std::ostream& os, const Bureaucrat &bureaucrat);
#endif