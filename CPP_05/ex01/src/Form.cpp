#include "../inc/Form.hpp"

const char *Form::GradeTooHighException::what() const throw()
{
      return "Grade too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
      return "Grade too low!";
}

Form::Form(std::string const &Name, int const SigningGrade, int const ExecGrade) : name(Name), signingGrade(SigningGrade), execGrade(ExecGrade), isSigned(false)
{
      std::cout << "Form constructor is called" << std::endl;
      if (signingGrade > 150 || execGrade > 150)
      {
            throw Form::GradeTooHighException();
      }
      else if (signingGrade <= 0 || execGrade <= 0)
      {
            throw Form::GradeTooLowException();
      }
};

Form::Form(Form const &copy) : name(copy.name), signingGrade(copy.signingGrade), execGrade(copy.execGrade), isSigned(copy.isSigned)
{
      std::cout << "Form copy constructor is called" << std::endl;
};

Form &Form::operator=(Form const &rhs)
{
      if (this == &rhs)
            return *this;
      this->isSigned = rhs.isSigned;
      return *this;
};

Form::~Form()
{
      std::cout << "Form destructor is called" << std::endl;
};

void Form::beSigned(Bureaucrat &bureaucrat)
{
      int grade = bureaucrat.getGrade();
      if (grade > this->execGrade || grade > this->signingGrade)
            throw Form::GradeTooLowException();
}

std::string Form::getFormName() const
{
      return name;
};

bool Form::getIsSigned() const
{
      return isSigned;
};

int Form::getSigningGrade() const
{
      return signingGrade;
};

int Form::getExecGrade() const
{
      return execGrade;
};

std::ostream &operator<<(std::ostream &os, const Form &form)
{
      std::string valueIsSigned;
      if (!form.getIsSigned())
      {
            valueIsSigned = "false";
      }
      else
      {
            valueIsSigned = "true";
      }
      os << "Form name: " << form.getFormName() << ". Is it signed: " << valueIsSigned << ". Grade to sign: " << form.getSigningGrade() << ", to execute : " << form.getExecGrade();
      return os;
}