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

		// Operadores de comparação
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator >=(const Fixed& other) const;
		bool operator <=(const Fixed& other) const;
		bool operator ==(const Fixed& other) const;
		bool operator !=(const Fixed& other) const;

		// Operadores Aritmeticos
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

		// Operadores de incremento/decremento
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		// Funções estáticas
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);

		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

# endif