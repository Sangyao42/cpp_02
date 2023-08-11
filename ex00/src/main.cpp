/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:22:09 by sawang            #+#    #+#             */
/*   Updated: 2023/08/11 22:30:40 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

int	main( void )
{
	Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;
	std::cout << a.getRawBits() << std::endl; std::cout << b.getRawBits() << std::endl; std::cout << c.getRawBits() << std::endl;

	return 0;
}
