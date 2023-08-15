/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:31:40 by sawang            #+#    #+#             */
/*   Updated: 2023/08/15 17:33:41 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = value << this->_fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = (int)roundf(value * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" <<std::endl;
	*this = src; //copy assignment called
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	return (this->_fixedPointValue);
};

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_fixedPointValue / (float)(1 << this->_fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> this->_fractionalBits);
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return (o);
}

/**
 * comparison operators
*/
bool Fixed::operator>(const Fixed &rhs) const
{
	return (this->_fixedPointValue > rhs.getRawBits());
}

bool Fixed::operator<(const Fixed &rhs)	const
{
	return (this->_fixedPointValue < rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return (this->_fixedPointValue >= rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return (this->_fixedPointValue <= rhs.getRawBits());
}

bool Fixed::operator==(const Fixed &rhs) const
{
	return (this->_fixedPointValue == rhs.getRawBits());
}

/**
 * arithmetic operators
*/
Fixed Fixed::operator+(const Fixed &rhs) const
{
	Fixed sum;

	sum.setRawBits(this->_fixedPointValue + rhs.getRawBits());
	return (sum);
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	Fixed substraction;

	substraction.setRawBits(this->_fixedPointValue - rhs.getRawBits());
	return (substraction);
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	Fixed multiplication;

	multiplication.setRawBits((int)((long)(this->_fixedPointValue * rhs.getRawBits()) >> this->_fractionalBits));
	return (multiplication);
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	Fixed division;

	division.setRawBits((int)((long)(this->_fixedPointValue << this->_fractionalBits) / rhs.getRawBits()));
	return (division);
}

/**
 * increment and decrement operators
*/

//prefix increment
Fixed &Fixed::operator++(void)
{
	std::cout << "prefix increment called" << std::endl;
	this->_fixedPointValue++;
	return(*this);
}

//postfix increment
Fixed Fixed::operator++(int)
{
	Fixed temp;

	temp = *this;
	++*this;
	return(temp);
}

//prefix decrement
Fixed &Fixed::operator--(void)
{
	std::cout << "prefix decrement called" << std::endl;
	this->_fixedPointValue--;
	return(*this);
}

// postfix decrement
Fixed Fixed::operator--(int)
{
	Fixed temp;

	temp = *this;
	--*this;
	return(temp);
}

/**
 * min and max
*/
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}
