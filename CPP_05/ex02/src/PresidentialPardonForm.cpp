#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : target(target), AForm("formulaire de pardon présidentiel", 25, 5)
{
        std::cout << "PresidentialPardonForm constructor is called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : target(copy.target), AForm(copy)
{
        std::cout << "PresidentialPardonForm copy constructor is called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
        if (this == &rhs)
        {
                return *this;
        }
        AForm::operator=(rhs);
        return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
        std::cout << "PresidentialPardonForm destructor is called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
        if (this->getIsSigned() == false)
        {
                throw AForm::FormNotSignedException();
        }
        else if (executor.getGrade() > this->getExecGrade())
        {
                throw AForm::GradeTooLowException();
        }
        else
        {
                std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
        }
}