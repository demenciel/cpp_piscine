/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:49:00 by acouture          #+#    #+#             */
/*   Updated: 2023/08/31 15:11:39 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
    private:
        int index;
        std::string phoneNumber;
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string darkestSecret;
    public:
        int     getData(int index);
        void    putDataCol();
        void    putDataFull();
        void    setToNull();
};

#endif