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

int main()
{
    Bureaucrat Lowman("Lowman", 150);
    std::cout << Lowman << std::endl << std::endl;

    Bureaucrat Bossman("Bossman", 1);
    std::cout << Bossman << std::endl << std::endl;
    

    return 0;
}
