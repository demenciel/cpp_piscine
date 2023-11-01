#include "../inc/RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm()
{
        std::cout << "RobotomyRequestForm constructor is called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy)
{
        std::cout << "RobotomyRequestForm copy constructor is called" << std::endl;
        *this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
     if (this == &rhs) {
      return *this;
}

return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
       std::cout << "RobotomyRequestForm destructor is called" << std::endl;
}