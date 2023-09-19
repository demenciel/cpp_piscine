/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:05:49 by acouture          #+#    #+#             */
/*   Updated: 2023/09/18 16:53:30 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    int n = 3;
    std::string name = "IM A ZOMBIE";

    Zombie *horde = zombieHorde(n, name);
    
    delete[] horde;
}