#include "../inc/ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm()
{
        std::cout << "ShrubberyCreationForm constructor is called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy)
{
        std::cout << "ShrubberyCreationForm copy constructor is called" << std::endl;
        *this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
        if (this == &rhs)
        {
                return *this;
        }

        return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
        std::cout << "ShrubberyCreationForm destructor is called" << std::endl;
}