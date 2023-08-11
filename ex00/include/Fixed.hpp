/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:23:29 by sawang            #+#    #+#             */
/*   Updated: 2023/08/11 22:29:49 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &src);
		Fixed &operator=(const Fixed &rhs);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int _fixedPointValue;
		static const int _fractionalBits = 8;
};

#endif
