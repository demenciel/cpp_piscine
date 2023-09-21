/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:09:38 by acouture          #+#    #+#             */
/*   Updated: 2023/09/21 18:21:52 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
    levelMap["DEBUG"] = &Harl::debug;
    levelMap["INFO"] = &Harl::info;
    levelMap["WARNING"] = &Harl::warning;
    levelMap["ERROR"] = &Harl::error;

    severityMap["DEBUG"] = 1;
    severityMap["INFO"] = 2;
    severityMap["WARNING"] = 3;
    severityMap["ERROR"] = 4;
}

void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
};

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !" << std::endl;
};

void Harl::warning(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !" << std::endl;
};

void Harl::error(void)
{
    std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
};

void Harl::complain(std::string level)
{
    if (levelMap.find(level) != levelMap.end())
    {
        (this->*levelMap[level])();
    }
    else
    {
        std::cout << "Invalid level" << std::endl;
    }
}