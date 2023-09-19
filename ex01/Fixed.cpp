/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:36:08 by yrabby            #+#    #+#             */
/*   Updated: 2023/09/19 15:36:08 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int i) : _value(i << _FRACTIONAL_BITS)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : _value((int)roundf(f * (1 << _FRACTIONAL_BITS)))
{
	std::cout << "Float constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed	&Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &rhs )
		this->_value = rhs.getRawBits();
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

float	Fixed::toFloat(void) const
{
	return (float)_value / (1 << _FRACTIONAL_BITS);
}

int	Fixed::toInt(void) const
{
	return _value >> _FRACTIONAL_BITS;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int	Fixed::getRawBits(void) const
{
	return _value;
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

/* ************************************************************************** */
