/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:59:18 by acouture          #+#    #+#             */
/*   Updated: 2023/09/18 16:20:42 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
    private:
        std::string name;
    public:
        Zombie(std::string n) : name(n) {}
        void announce( void );
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif