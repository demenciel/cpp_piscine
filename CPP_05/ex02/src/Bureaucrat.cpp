
#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &Name, int Grade) : name(Name)
{
      if (Grade > 150)
            throw Bureaucrat::GradeTooHighException();
      else if (Grade <= 0)
            throw Bureaucrat::GradeTooLowException();
      else
            grade = Grade;
      std::cout << "Bureaucrat constructor is called" << std::endl;
};

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : name(copy.name), grade(copy.grade)
{
      std::cout << "Bureaucrat copy constructor is called" << std::endl;
};
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
      if (this == &rhs)
            return *this;
      this->grade = rhs.grade;
      return *this;
};

Bureaucrat::~Bureaucrat()
{
      std::cout << "Bureaucrat destructor is called" << std::endl;
};

// functions

std::string Bureaucrat::getName() const
{
      return this->name;
}

int Bureaucrat::getGrade() const
{
      return this->grade;
}

void Bureaucrat::incrementGrade(int inc)
{
      int tmp = this->grade;
      int newGrade = tmp -= inc;
      if (newGrade > 150)
            throw Bureaucrat::GradeTooHighException();
      else if (newGrade <= 0)
            throw Bureaucrat::GradeTooLowException();
      else
            grade = newGrade;
      std::cout << this->name << " new grade is " << this->grade << std::endl;
}

void Bureaucrat::decrementGrade(int dec)
{
      int tmp = this->grade;
      int newGrade = tmp += dec;
      if (newGrade > 150)
            throw Bureaucrat::GradeTooHighException();
      else if (newGrade <= 0)
            throw Bureaucrat::GradeTooLowException();
      else
            grade = newGrade;
      std::cout << this->name << " new grade is " << this->grade << std::endl;
}

void Bureaucrat::signForm(AForm &form) {
    try {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getFormName() << std::endl << std::endl;
    } catch (AForm::GradeTooLowException &e) {
        std::cout << this->getName() << " couldn't sign " << form.getFormName() << " because " << e.what() << std::endl;
    } catch (...) {
        std::cout << this->getName() << " couldn't sign " << form.getFormName() << " for an unknown reason." << std::endl;
    }
}

void  Bureaucrat::executeForm(AForm const &form) {
      try {
            form.execute(*this);
            std::cout << this->getName() << " executed " << form.getFormName() << std::endl << std::endl;
      } catch (AForm::GradeTooLowException &e) {
            std::cout << this->getName() << " couldn't execute " << form.getFormName() << " because " << e.what() << std::endl;
      } catch (...) {
            std::cout << this->getName() << " couldn't execute " << form.getFormName() << " for an unknown reason." << std::endl;
      }
}

// exceptions
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
      return "Grade too low!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
      return "Grade too high!";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
      os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
      return os;
}
