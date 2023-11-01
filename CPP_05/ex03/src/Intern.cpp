#include "../inc/Intern.hpp"

Intern::Intern()
{
      std::cout << "Intern constructor is called" << std::endl;
};

Intern::Intern(Intern const *copy)
{
      std::cout << "Intern copy constructor is called" << std::endl;
      *this = copy;
};

Intern &Intern::operator=(Intern const &rhs)
{
      if (this == &rhs)
            return (*this);
      return (*this);
};

Intern::~Intern()
{
      std::cout << "Intern destructor is called" << std::endl;
};

const char *Intern::FormNotAvailableException::what() const throw()
{
      return "Form not available !";
}

AForm *createPresidential(std::string const &target)
{
      return new PresidentialPardonForm(target);
};

AForm *createRobotomy(std::string const &target)
{
      return new RobotomyRequestForm(target);
};

AForm *createShrubbery(std::string const &target)
{
      return new ShrubberyCreationForm(target);
};

AForm *Intern::makeForm(std::string const &formName, std::string const &target)
{
      std::string availableForms[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
      FormCreator creators[] = {createPresidential, createRobotomy, createShrubbery};

      for (size_t i = 0; i < sizeof(availableForms) / sizeof(std::string); ++i)
      {
            if (formName == availableForms[i]) {
                  std::cout << "Intern creates " << availableForms[i] << std::endl;
                  return creators[i](target);
            }
      }
      throw Intern::FormNotAvailableException();
}