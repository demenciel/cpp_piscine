#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("Formulaire de demande de robotomie", 72, 45), target(target)
{
        std::cout << "RobotomyRequestForm constructor is called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm(copy), target(copy.target)
{
        std::cout << "RobotomyRequestForm copy constructor is called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
        if (this == &rhs)
        {
                return *this;
        }
        AForm::operator=(rhs);
        return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
        std::cout << "RobotomyRequestForm destructor is called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
        if (this->getIsSigned() == false)
                throw AForm::FormNotSignedException();
        else if (executor.getGrade() > this->getExecGrade())
                throw AForm::GradeTooLowException();
        else
        {
                std::cout << "* drilling noises *" << std::endl;
                if (rand() % 2 == 0)
                        std::cout << this->target << " has been robotomized successfully." << std::endl;
                else
                        std::cout << this->target << " robotomization failed." << std::endl;
        }
}