/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:35:13 by acouture          #+#    #+#             */
/*   Updated: 2023/10/13 15:51:00 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap clap("Ragnar");
    ClapTrap clap2("Lagertha");

    clap.attack("Lagertha");
    clap.takeDamage(5);
    clap.beRepaired(5);
    return (0);
}

// Quand ClapTrap attaque, sa cible perd <attack damage> hit points. Quand ClapTrap
// se répare, il regagne <amount> hit points. Les actions attaquer et réparer coûtent chacune
// 1 point d’énergie. Bien entendu, ClapTrap ne peut exécuter aucune action s’il n’a plus
// de vie ou d’énergie.
// Pour toutes ces fonctions membres, vous devez afficher un message descriptif. Par
// exemple, la fonction attack() affichera quelque chose dans le genre (bien sûr, sans les
// chevrons) :
// ClapTrap <name> attacks <target>, causing <damage> points of damage!
// Les constructeurs et le destructeur afficheront également un message. Ceci afin que
// vos pairs puissent vérifier facilement qu’ils ont effectivement été appelés.
// Écrivez et rendez vos propres tests afin de démontrer que votre tout fonctionne comme
// demandé.