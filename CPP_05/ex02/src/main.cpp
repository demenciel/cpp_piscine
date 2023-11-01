/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:37:31 by acouture          #+#    #+#             */
/*   Updated: 2023/10/31 18:55:17 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"

int main()
{
    std::cout << std::endl << "---------- Bureaucrat Construct ------------" << std::endl;
    Bureaucrat Lowman("Lowman", 150);
    std::cout << Lowman << std::endl << std::endl;

    Bureaucrat Bossman("Bossman", 1);
    std::cout << Bossman << std::endl << std::endl;
    
    std::cout << std::endl << "---------- Presidential Form Construct ------------" << std::endl;
    PresidentialPardonForm presidential("White House");
    std::cout << presidential << std::endl << std::endl;


    std::cout << std::endl << "------------ Sign and fail ----------" << std::endl;
    try {
        Bossman.signForm(presidential);
        presidential.execute(Lowman);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl << "---------- Sign and execute ------------" << std::endl;
    try {
        presidential.execute(Bossman);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl << "---------- Robotomy Form Construct ------------" << std::endl;
    RobotomyRequestForm robotomy("Bender");

    std::cout << std::endl << "---------- Clean ------------" << std::endl << std::endl;
    return 0;
}
