/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:37:31 by acouture          #+#    #+#             */
/*   Updated: 2023/11/01 16:58:03 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"


int main()
{
    std::cout << "\033[1;32m" << std::endl << "---------- Bureaucrat Construct ------------" << "\033[0m" << std::endl;
    Bureaucrat Lowman("Lowman", 150);
    std::cout << Lowman << std::endl << std::endl;

    Bureaucrat Bossman("Bossman", 1);
    std::cout << Bossman << std::endl << std::endl;
    
    std::cout << "\033[1;32m" << std::endl << "---------- Presidential Form Construct ------------" << "\033[0m" << std::endl;
    PresidentialPardonForm presidential("White House");
    std::cout << presidential << std::endl << std::endl;


    std::cout << "\033[1;31m" << std::endl << "------------ Sign and fail ----------" << "\033[0m" << std::endl;
    try {
        Bossman.signForm(presidential);
        presidential.execute(Lowman);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\033[1;32m" << std::endl << "---------- Sign and execute ------------" << "\033[0m" << std::endl;
    try {
        Bossman.executeForm(presidential);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }


    std::cout << "\033[1;34m" << std::endl << "--------------------------------------------" << "\033[0m" << std::endl;
    std::cout << "\033[1;32m" << std::endl << "---------- Robotomy Form ------------" << "\033[0m" << std::endl;
    RobotomyRequestForm robotomy("Bender");

    std::cout << std::endl << "---------- Sign and execute ------------" << std::endl;
    try {
        Bossman.signForm(robotomy);
        Bossman.executeForm(robotomy);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\033[1;34m" << std::endl << "--------------------------------------------" << "\033[0m" << std::endl;
    std::cout << "\033[1;32m" << std::endl << "---------- Shruberry Form ------------" << "\033[0m" << std::endl;
    ShrubberyCreationForm shrubbery("Home");

    std::cout << std::endl << "---------- Sign and execute ------------" << std::endl;
    try {
        Bossman.signForm(shrubbery);
        Bossman.executeForm(shrubbery);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\033[1;31m" << std::endl << "---------------- CLEAN -------------------" << "\033[0m" << std::endl;
    return 0;
}
