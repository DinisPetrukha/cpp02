/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrukh <dpetrukh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:19:23 by dpetrukh          #+#    #+#             */
/*   Updated: 2025/01/23 16:19:23 by dpetrukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_fixed_point = value << frac_bits; // Multiplica por 2^_fractionalBits
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_fixed_point = roundf(value * (1 << frac_bits)); // Multiplica e arredonda
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_fixed_point = other.getRawBits();
	}
	return (*this);
}

int	Fixed::getRawBits( void ) const
{
	return (_fixed_point);
}

void Fixed::setRawBits( int const raw )
{
	_fixed_point = raw;
}

// Converte para float
float Fixed::toFloat(void) const {
	return (float)_fixed_point / (1 << frac_bits); // Divide por 2^_fractionalBits
}

// Converte para inteiro
int Fixed::toInt(void) const {
	return _fixed_point >> frac_bits; // Eleva por 2^_fractionalBits
}

// Operador de inserção
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat(); // Imprime o valor como float
	return out;
}

bool Fixed::operator>(const Fixed& other) const {
	return this->_fixed_point > other._fixed_point;
}

bool Fixed::operator<(const Fixed& other) const {
	return this->_fixed_point < other._fixed_point;
}

bool Fixed::operator>=(const Fixed& other) const {
	return this->_fixed_point >= other._fixed_point;
}

bool Fixed::operator<=(const Fixed& other) const {
	return this->_fixed_point <= other._fixed_point;
}

bool Fixed::operator==(const Fixed& other) const {
	return this->_fixed_point == other._fixed_point;
}

bool Fixed::operator!=(const Fixed& other) const {
	return this->_fixed_point != other._fixed_point;
}

Fixed Fixed::operator+(const Fixed& other) const {
	Fixed result;
	result.setRawBits(this->_fixed_point + other._fixed_point);
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed result;
	result.setRawBits(this->_fixed_point - other._fixed_point);
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
	Fixed result;
	result.setRawBits((this->_fixed_point * other._fixed_point) >> frac_bits);
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
	Fixed result;
	result.setRawBits((this->_fixed_point / other._fixed_point) >> frac_bits);
	return result;
}

// Pre Incremento
Fixed& Fixed::operator++() {
    this->_fixed_point++;
    return *this;
}

// Pos Incremento
Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    this->_fixed_point++;
    return temp;
}

// Pre Decremento
Fixed& Fixed::operator--() {
    this->_fixed_point--;
    return *this;
}

// Pos Decremento
Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    this->_fixed_point--;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}
