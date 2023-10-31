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
#include "../inc/Form.hpp"

int main()
{
    Bureaucrat Lowman("Lowman", 150);
    std::cout << Lowman << std::endl << std::endl;

    Bureaucrat Bossman("Bossman", 1);
    std::cout << Bossman << std::endl << std::endl;
    
    try {
        Form hiring("Hiring Papers", 150, 150);
        std::cout << hiring << std::endl << std::endl;
        Form bosspapers("Boss Papers", 20, 20);
        std::cout << bosspapers << std::endl << std::endl;

        Lowman.signForm(hiring);
        Bossman.signForm(bosspapers);
        Lowman.signForm(bosspapers);
        Bossman.decrementGrade(100);
        Bossman.signForm(bosspapers);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
