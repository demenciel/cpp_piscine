/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:37:31 by acouture          #+#    #+#             */
/*   Updated: 2023/10/31 17:34:44 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main()
{
    Bureaucrat Alain("Alain", 75);
    std::cout << Alain << std::endl;

    std::cout << " ---- Increment ----- " << "\n" << std::endl;
    try {
        Alain.incrementGrade(10);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << " ---- Increment ----- " << "\n" << std::endl;
    try {
        Alain.incrementGrade(75);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << " ---- Decrement ----- " << "\n" << std::endl;
    try {
        Alain.decrementGrade(22);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << " ---- New Bureaucrat ----- " << "\n" << std::endl;
    try
    {
        Bureaucrat Bob("Bob", 151);
        std::cout << Bob << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << "\n" << std::endl;
    }

    std::cout << " ---- New Bureaucrat ----- " << "\n" << std::endl;
    try
    {
        Bureaucrat Gilles("Gilles", -20);
        std::cout << Gilles << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }


    return 0;
}
