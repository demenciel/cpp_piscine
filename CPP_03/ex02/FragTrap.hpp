/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:21:31 by acouture          #+#    #+#             */
/*   Updated: 2023/10/17 15:28:29 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Maintenant, implémentez une classe FragTrap héritant de ClapTrap. Elle est très similaire à ScavTrap. Ses messages de construction et de destruction doivent cependant être
// différents. Vos tests devront montrer que l’enchaînement des constructeurs/destructeurs
// s’effectue bien dans le bon ordre. Quand on crée un FragTrap, le programme commence
// par créer un ClapTrap. La destruction s’effectue dans l’ordre inverse.
// Même chose pour les attributs, mais avec des valeurs différentes :
// • Name, son nom, qui sera passé en paramètre d’un constructeur
// • Hit points (100)
// • Energy points (100)
// • Attack damage (30)
// FragTrap possède aussi une capacité spéciale :
// void highFivesGuys(void);
// Cette fonction membre affiche une demande de high fives sur la sortie standard.
// À nouveau, enrichissez vos tests.

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

class FragTrap : public ClapTrap
{
public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(FragTrap const &copy);
    ~FragTrap();
    FragTrap &operator=(FragTrap const &rhs);

    void highFivesGuys(void);
};

int applyDamageFragVSScav(FragTrap &attacker, ScavTrap &target);

#endif