/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:16:13 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/07 19:22:26 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed
{
	private:
		int value;
		static const int fraction_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed& ref);
		~Fixed();
		Fixed& operator=(const Fixed& ref);
		int getRawBits(void) const;
		void setRawBits(int const raw);

		Fixed(const int inum);
		Fixed(const float fnum);
		int toInt(void) const;
		float toFloat(void) const;

		bool operator>(const Fixed& ref) const;
		bool operator<(const Fixed& ref) const;
		bool operator==(const Fixed& ref) const;
		bool operator!=(const Fixed& ref) const;
		bool operator<=(const Fixed& ref) const;
		bool operator>=(const Fixed& ref) const;
		Fixed operator+(const Fixed& ref) const;
		Fixed operator-(const Fixed& ref) const;
		Fixed operator*(const Fixed& ref) const;
		Fixed operator/(const Fixed& ref) const;
		Fixed operator++(int);
		Fixed operator--(int);
		Fixed& operator++();
		Fixed& operator--();

		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
};
	
std::ostream& operator<<(std::ostream& stream, const Fixed& num);

#endif
