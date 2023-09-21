/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:02:21 by acouture          #+#    #+#             */
/*   Updated: 2023/09/21 18:24:44 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>
#include <map>

class Harl
{
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

    std::map<std::string, void (Harl::*)(void)> levelMap;

public:
    Harl();
    void complain(std::string level);
    std::map<std::string, int> severityMap;
};

#endif
