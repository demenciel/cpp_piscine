/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:42:49 by acouture          #+#    #+#             */
/*   Updated: 2023/08/31 12:57:57 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits> 

#define ADD "ADD"
#define SEARCH "SEARCH"
#define EXIT "EXIT"


class PhoneBook {
    public:
        Contact myContact[8];
        int contactCount;
        int contactIndex;
        PhoneBook() : contactCount(0), contactIndex(0) {}
};

// MAIN FUNCTIONS
bool isInteger(const std::string& s);

#endif

