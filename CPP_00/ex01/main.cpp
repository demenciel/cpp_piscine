/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:42:02 by acouture          #+#    #+#             */
/*   Updated: 2023/08/31 15:08:50 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

bool isInteger(const std::string& s) {
    for (std::string::size_type i = 0; i < s.size(); ++i) {
        if (!std::isdigit(s[i])) {
            return false;
        }
    }
    return true;
}

void printContacts(PhoneBook &myBook) {
    int index = 1;

    std::cout << std::right;
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nick Name" << std::endl;

    for (int i = 0; i < myBook.contactCount; i++) {
        myBook.myContact[i].putDataCol();
    }

    std::cout << "Choose the contact index to see his info" << std::endl;

    while (true) {
        if (std::cin >> index) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (index >= 0 && index < myBook.contactCount) {
                myBook.myContact[index].putDataFull();
                break;
            } else {
                std::cout << "Invalid index. Index must be between 0 - ." << myBook.contactCount << std::endl;
            }
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter an integer." << std::endl;
        }
    }
}


int main()
{
    PhoneBook myPhone;
    std::string input;

    int oldestIndex = 0;

    while (true && !std::cin.eof())
    {
        std::cout << "Enter your prompt : ";
        getline(std::cin, input);
        if (input.compare(ADD) == 0)
        {
            if (myPhone.myContact[myPhone.contactIndex].getData(myPhone.contactIndex) == 0) {
                myPhone.contactIndex++;
                if (myPhone.contactCount < 8)
                    myPhone.contactCount++;
                else
                    oldestIndex = (oldestIndex + 1) % 8;
            } else std::cout << "Invalid input\n";

            if (myPhone.contactIndex == 8) myPhone.contactIndex = oldestIndex;
        }
        else if (input.compare(SEARCH) == 0) {
            if (myPhone.contactCount != 0) printContacts(myPhone);
            else std::cout << "Your Phonebook is empty" << std::endl;
        }
        else if (input.compare(EXIT) == 0)
            exit(0);
        else
            std::cout << "Please enter a valid command : ADD, SEARCH or EXIT\n" << std::endl;
    }
    return (0);
}
