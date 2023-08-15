/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:31:48 by sawang            #+#    #+#             */
/*   Updated: 2023/08/15 17:46:52 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

int	main(void)
{
	Fixed	a;
	Fixed	const b(Fixed(5.05f) * Fixed(2));

	//increment and decrement
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;

	std::cout << b << std::endl;

	//min and max
	std::cout << "max of a and b is " << Fixed::max(a, b) << std::endl;

	//arithmetic
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a - b = " << a - b << std::endl;
	std::cout << "a * b = " << a * b << std::endl;
	std::cout << "a / b = " << a / b << std::endl;

	Fixed const c(5.05f);
	std:: cout << "c = " << c << std::endl;
	std::cout << "min of b and c is " << Fixed::min(b, c) << std::endl;

	//comparision
	if (c * 2 == b)
		std::cout << "c equals to 1/2 of b" << std::endl;
	else
		std::cout << "c does not equal to 1/2 of b" << std::endl;

	return 0;
}
