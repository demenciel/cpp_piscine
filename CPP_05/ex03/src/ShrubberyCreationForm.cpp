#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("Formulaire de création d'arbustes)", 145, 137), target(target)
{
        std::cout << "ShrubberyCreationForm constructor is called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm(copy), target(copy.target)
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
        AForm::operator=(rhs);
        return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
        std::cout << "ShrubberyCreationForm destructor is called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
        if (this->getIsSigned() == false)
                throw AForm::FormNotSignedException();
        else if (executor.getGrade() > this->getExecGrade())
                throw AForm::GradeTooLowException();
        else
        {
                std::cout << "Check the root directory for the forest!" << std::endl;
                std::ofstream ofs;
                ofs.open((this->target + "_shrubbery").c_str());
                for (size_t i = 0; i < 5; i++)
                {
                        ofs << "       _-_" << std::endl;
                        ofs << "    /~~   ~~\\" << std::endl;
                        ofs << " /~~         ~~\\" << std::endl;
                        ofs << "{               }" << std::endl;
                        ofs << " \\  _-     -_  /" << std::endl;
                        ofs << "   ~  \\\\ //  ~" << std::endl;
                        ofs << "_- -   | | _- _" << std::endl;
                        ofs << "  _ -  | |   -_" << std::endl;
                        ofs << "      // \\\\" << std::endl;
                }
                ofs.close();
        }
}
