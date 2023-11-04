/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:07:49 by acouture          #+#    #+#             */
/*   Updated: 2023/11/04 15:16:40 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime> 

class A;
class B;
class C;

class Base
{
public:
    virtual ~Base();

    Base *generate();
    void identify(Base *p);
    void identify(Base &p);
};


#endif