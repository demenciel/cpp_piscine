/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouture <acouture@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:35:09 by acouture          #+#    #+#             */
/*   Updated: 2023/11/07 14:17:44 by acouture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>

template <typename T>
class Array
{
public:
    class OutOfBoundsException : public std::exception
    {
        virtual const char *what() const throw()
        {
            return ("Out of bounds");
        }
    };
    // default constructor
    Array() : _array(new T[0]), _size(0) {}
    // constructor with size
    Array(unsigned int n) : _array(new T[n]), _size(n) {}
    // copy constructor
    Array(const Array &src) : _array(new T[src._size]), _size(src._size)
    {
        for (std::size_t i = 0; i < _size; ++i)
            _array[i] = src._array[i];
    }
    // operator=
    Array &operator=(Array const &rhs)
    {
        if (this != &rhs)
        {
            delete[] _array;

            _size = rhs._size;
            _array = new int[_size];

            for (std::size_t i = 0; i < _size; ++i)
                _array[i] = rhs._array[i];
        }
        return *this;
    }
    // destructor
    ~Array() { delete[] _array; }
    uint size() const { return _size; }
    T &operator[](unsigned int i) const
    {
        if (i >= _size)
            throw std::exception();
        return _array[i];
    }

private:
    T *_array;
    unsigned int _size;
};
