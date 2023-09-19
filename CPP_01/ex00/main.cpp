/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:05:49 by acouture          #+#    #+#             */
/*   Updated: 2023/09/18 16:30:29 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    // Heap
    randomChump("Pedro");
    // Stack
    Zombie* myZombie = newZombie("Bob");
    myZombie->announce();
    delete myZombie;
    return 0;
}