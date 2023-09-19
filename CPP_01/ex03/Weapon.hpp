/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:09:44 by acouture          #+#    #+#             */
/*   Updated: 2023/09/19 16:50:05 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>
#include <string>

class Weapon
{
    private:
        std::string type;

    public:
        Weapon(std::string type) : type(type) {}
        ~Weapon();
        const std::string& getType();
        void setType(std::string newValue);
};


#endif