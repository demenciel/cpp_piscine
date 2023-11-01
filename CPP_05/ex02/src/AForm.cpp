#include "../inc/AForm.hpp"

const char *AForm::GradeTooHighException::what() const throw()
{
      return "Grade too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
      return "Grade too low!";
}

const char *AForm::FormNotSignedException::what() const throw()
{
      return "Form is not signed!";
}

AForm::AForm(std::string const &Name, int const SigningGrade, int const ExecGrade) : name(Name), signingGrade(SigningGrade), execGrade(ExecGrade), isSigned(false)
{
      std::cout << "AForm constructor is called" << std::endl;
      if (signingGrade > 150 || execGrade > 150)
      {
            throw AForm::GradeTooHighException();
      }
      else if (signingGrade <= 0 || execGrade <= 0)
      {
            throw AForm::GradeTooLowException();
      }
};

AForm::AForm(AForm const &copy) : name(copy.name), signingGrade(copy.signingGrade), execGrade(copy.execGrade), isSigned(copy.isSigned)
{
      std::cout << "AForm copy constructor is called" << std::endl;
};

AForm &AForm::operator=(AForm const &rhs)
{
      if (this == &rhs)
            return *this;
      this->isSigned = rhs.isSigned;
      return *this;
};

AForm::~AForm()
{
      std::cout << "AForm destructor is called" << std::endl;
};

void AForm::beSigned(Bureaucrat &bureaucrat)
{
      int grade = bureaucrat.getGrade();
      if (grade > this->execGrade || grade > this->signingGrade)
            throw AForm::GradeTooLowException();
}

std::string AForm::getFormName() const
{
      return name;
};

bool AForm::getIsSigned() const
{
      return isSigned;
};

int AForm::getSigningGrade() const
{
      return signingGrade;
};

int AForm::getExecGrade() const
{
      return execGrade;
};

std::ostream &operator<<(std::ostream &os, const AForm &Aform)
{
      std::string valueIsSigned;
      if (!Aform.getIsSigned())
      {
            valueIsSigned = "false";
      }
      else
      {
            valueIsSigned = "true";
      }
      os << "AForm name: " << Aform.getFormName() << ". Is it signed: " << valueIsSigned << ". Grade to sign: " << Aform.getSigningGrade() << ", to execute : " << Aform.getExecGrade();
      return os;
}