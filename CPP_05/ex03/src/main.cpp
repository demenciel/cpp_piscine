/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:37:31 by acouture          #+#    #+#             */
/*   Updated: 2023/11/01 17:03:15 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Intern.hpp"
#include "../inc/AForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"


int main()
{
    std::cout << "\033[1;34m" << std::endl << "---------- Bureaucrat Construct ------------" << "\033[0m" << std::endl;
    Bureaucrat Bossman("Bossman", 1);
    std::cout << Bossman << std::endl << std::endl;
    
    std::cout << "\033[1;34m" << std::endl << "---------- Presidential Form Construct ------------" << "\033[0m" << std::endl;
    PresidentialPardonForm presidential("White House");
    std::cout << presidential << std::endl << std::endl;

    std::cout << "\033[1;34m" << std::endl << "---------- Intern Make Robotomy Form Action ------------" << "\033[0m" << std::endl;
    Intern someRandomIntern;
    
    AForm* rrf;
    try {
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        Bossman.signForm(*rrf);
        Bossman.executeForm(*rrf);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\033[1;34m" << std::endl << "---------- Intern Make Shrubbery Form Action ------------" << "\033[0m" << std::endl;
    AForm* f;
    try {
        f = someRandomIntern.makeForm("shrubbery creation", "Forest");
        Bossman.signForm(*f);
        Bossman.executeForm(*f);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\033[1;31m" << std::endl << "---------- Intern Make Form Action Fail ------------" << "\033[0m" << std::endl;
    AForm* rf;
    try {
        rf = someRandomIntern.makeForm("shrubbery form", "Bender");
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "\033[1;31m" << std::endl << "---------------- CLEAN -------------------" << "\033[0m" << std::endl;

    return 0;
}
