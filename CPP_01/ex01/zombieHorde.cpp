/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:59:22 by acouture          #+#    #+#             */
/*   Updated: 2023/09/18 16:44:03 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {

    Zombie* horde = new Zombie[N];

    for (int i = 0; i < N; i++) {
        horde[i] = Zombie(name);
        horde[i].announce();
    }
    return (horde);
}