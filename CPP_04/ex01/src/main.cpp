/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:35:13 by acouture          #+#    #+#             */
/*   Updated: 2023/10/19 17:03:32 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"
#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"

/*
Implémentez une classe Brain (cerveau) contenant un tableau de 100 std::string appelé ideas (idées).
Ainsi, les classes Dog et Cat auront un attribut privé Brain*.
À la construction, les classes Dog et Cat créeront leur Brain avec new Brain();
À la destruction, les classes Dog et Cat devront delete leur Brain.
Dans votre fonction main, créez et remplissez un tableau d’objets Animal dont la moitié est composée d’objets Dog et l’autre moitié d’objets Cat. À la fin de l’exécution du programme, parcourez ce tableau afin de delete chaque Animal. Vous devez delete directement les chiens et les chats en tant qu’Animal. Les destructeurs correspondants doivent être appelés dans le bon ordre.
N’oubliez pas de vérifier que vous n’avez pas de fuites de mémoire.
La copie d’un objet Dog ou d’un objet Cat ne doit pas être superficielle. Par consé-
quent, vous devez vous assurer que vos copies sont bien des copies profondes. */

int main()
{
    int nb = 5;
    for (int i = 0; i < nb; i++)
    {
        Animal *horde = new Animal();
        horde->getType();
    }
    std::cout << "-------------" << std::endl;
}
