/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:35:09 by acouture          #+#    #+#             */
/*   Updated: 2023/11/06 13:47:01 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
T const max(T const &x, const T &y)
{
    if (x == y)
        return (y);
    return (x > y ? x : y);
};

template <typename T>
T const min(T const &x, T const &y)
{
    if (x == y)
        return (y);
    return (x < y ? x : y);
};

template <typename T>
void   swap(T &x, T &y)
{
    T tmp = x;
    x = y;
    y = tmp;
};