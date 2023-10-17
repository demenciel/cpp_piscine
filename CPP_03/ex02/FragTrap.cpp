/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:40:36 by acouture          #+#    #+#             */
/*   Updated: 2023/10/17 15:12:06 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap constructor called" << std::endl;
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap constructor called" << std::endl;
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
}

FragTrap::FragTrap(FragTrap const &copy) : ClapTrap(copy)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = copy;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
    ClapTrap::operator=(rhs);
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::string answer;

    while (true && !std::cin.eof())
    {
        std::cout << "High five? (yes/no)" << std::endl;
        std::cin >> answer;

        if (answer == "yes")
        {
            std::cout << "High five given!" << std::endl;
            break;
        }
        else if (answer == "no")
        {
            std::cout << "No high five :(" << std::endl;
            break;
        }
        else
            std::cout << "Invalid answer. Please enter 'yes' or 'no'." << std::endl;
    }
}