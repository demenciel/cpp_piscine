/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:50:13 by acouture          #+#    #+#             */
/*   Updated: 2023/09/04 12:55:01 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int Contact::getData(int i)
{
    while (true)
    {
        std::cout << "Enter the first name of your contact: \n";
        std::getline(std::cin, firstName);
        if (std::cin.eof()) {
            std::cout << "End of file detected. Exiting.\n";
            exit(0);
        }
        if (std::cin.eof() || !(firstName.empty() || firstName.length() > 20))
            break;
        std::cout << "Invalid input. Please try again.\n";
    }

    while (true)
    {
        std::cout << "Enter the last name of " << firstName << std::endl;
        std::getline(std::cin, lastName);
        if (std::cin.eof()) {
            std::cout << "End of file detected. Exiting.\n";
            exit(0);
        }
        if (std::cin.eof() || !(lastName.empty() || lastName.length() > 20))
            break;
        std::cout << "Invalid input. Please try again.\n";
    }

    while (true)
    {
        std::cout << "Enter the nick name of " << firstName << std::endl;
        std::getline(std::cin, nickName);
        if (std::cin.eof()) {
            std::cout << "End of file detected. Exiting.\n";
            exit(0);
        }
        if (std::cin.eof() || !(nickName.empty() || nickName.length() > 20))
            break;
        std::cout << "Invalid input. Please try again.\n";
    }

    while (true)
    {
        std::cout << "Enter the phone number of " << firstName << std::endl;
        std::getline(std::cin, phoneNumber);
        if (std::cin.eof()) {
            std::cout << "End of file detected. Exiting.\n";
            exit(0);
        }
        if (std::cin.eof() || (isInteger(phoneNumber) && !phoneNumber.empty() && !(phoneNumber.length() > 11)))
            break;
        std::cout << "Invalid input. Please try again.\n";
    }

    while (true)
    {
        std::cout << "What is the darkest secret of " << nickName << std::endl;
        std::getline(std::cin, darkestSecret);
        if (std::cin.eof()) {
            std::cout << "End of file detected. Exiting.\n";
            exit(0);
        }
        if (std::cin.eof() || !(darkestSecret.empty() || darkestSecret.length() > 100))
            break;
        std::cout << "Invalid input. Please try again.\n";
    }

    index = i;
    return 0;
}

void Contact::putDataCol()
{
    std::cout << std::right;
    std::cout << std::setw(10) << index << "|";

    std::string firstNameSub = firstName.substr(0, 10);
    if (firstNameSub.length() == 10)
        firstNameSub.replace(9, 1, ".");
    std::cout << std::setw(10) << firstNameSub << "|";

    std::string lastNameSub = lastName.substr(0, 10);
    if (lastNameSub.length() == 10)
        lastNameSub.replace(9, 1, ".");
    std::cout << std::setw(10) << lastNameSub << "|";

    std::string nickNameSub = nickName.substr(0, 10);
    if (nickNameSub.length() == 10)
        nickNameSub.replace(9, 1, ".");
    std::cout << std::setw(10) << nickNameSub << "|" << std::endl;
}

void Contact::putDataFull()
{
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nick Name: " << nickName << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

void Contact::setToNull()
{
    firstName.empty();
    lastName.empty();
    nickName.empty();
    darkestSecret.empty();
    index = 0;
}