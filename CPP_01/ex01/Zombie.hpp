/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:59:18 by acouture          #+#    #+#             */
/*   Updated: 2023/09/18 16:48:09 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

// The main goal of a constructor is to 
// initalize the object's attributes
class Zombie {
    private:
        std::string name;
    public:
        Zombie();  
        Zombie(std::string n);
        void announce(void);
};

Zombie* zombieHorde( int N, std::string name );

#endif