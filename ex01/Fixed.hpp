/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:49:06 by dpetrukh          #+#    #+#             */
/*   Updated: 2025/01/23 15:49:06 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	_fixed_point;
		static const int frac_bits = 8;
	public:
		Fixed();
		Fixed(const int);
		Fixed(const float value);
		Fixed(const Fixed& other);

		Fixed&	operator=(Fixed const &other);

		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;

		friend std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
};

# endif