/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:16:13 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/05 16:06:57 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

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
};

#endif
