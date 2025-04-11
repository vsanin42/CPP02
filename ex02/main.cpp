/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:24:01 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/11 13:04:57 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	{
		std::cout << "Subject examples:" << std::endl;
		Fixed a;
		Fixed const b(Fixed(5.05f) * Fixed(2));

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;

		std::cout << Fixed::max(a, b) << std::endl;
		std::cout << "\n------------------------------------\n" << std::endl;
	}
	{
		std::cout << "Addition (int constructor):" << std::endl;
		Fixed a(10);
		Fixed b(5);
		
		Fixed c(a + b);
		std::cout << a << " + " << b << " = " << c << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "Addition (float constructor):" << std::endl;
		Fixed a(10.3f);
		Fixed b(5.4f);
		
		Fixed c = a + b;
		std::cout << a << " + " << b << " = " << c << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "Addition (int/float constructors):" << std::endl;
		Fixed a(10.3f);
		Fixed b(5);
		
		Fixed c = a + b;
		std::cout << a << " + " << b << " = " << c << std::endl;
		std::cout << "\n------------------------------------\n" << std::endl;
	}
	{
		std::cout << "Subtraction (int constructor):" << std::endl;
		Fixed a(0);
		Fixed b(5);
		
		Fixed c(a - b);
		std::cout << a << " - " << b << " = " << c << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "Subtraction (float constructor):" << std::endl;
		Fixed a(1.53f);
		Fixed b(1.22f);
		
		Fixed c = a - b;
		std::cout << a << " - " << b << " = " << c << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "Subtraction (int/float constructors):" << std::endl;
		Fixed a(10.3f);
		Fixed b(-5);
		
		Fixed c = a - b;
		std::cout << a << " - " << b << " = " << c << std::endl;
		std::cout << "\n------------------------------------\n" << std::endl;
	}
	{
		std::cout << "Multiplication (int constructor):" << std::endl;
		Fixed a(0);
		Fixed b(5);
		
		Fixed c(a * b);
		std::cout << a << " * " << b << " = " << c << std::endl;
		a = Fixed(1);
		c = a * b;
		std::cout << a << " * " << b << " = " << c << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "Multiplication (float constructor):" << std::endl;
		Fixed a(10.5f);
		Fixed b(0.5f);
		
		Fixed c = a * b;
		std::cout << a << " * " << b << " = " << c << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "Multiplication (int/float constructors):" << std::endl;
		Fixed a(10.3f);
		Fixed b(-5);
		
		Fixed c = a * b;
		std::cout << a << " * " << b << " = " << c << std::endl;
		std::cout << "\n------------------------------------\n" << std::endl;
	}
	{
		std::cout << "Division (int constructor):" << std::endl;
		Fixed a(0);
		Fixed b(5);
		
		Fixed c(a / b);
		std::cout << a << " / " << b << " = " << c << std::endl;
		a = Fixed(1);
		c = a / b;
		std::cout << a << " / " << b << " = " << c << std::endl;
		b = Fixed(0);
		std::cout << a << " / " << b << " = ";
		try
		{
			std::cout << (a / b) << std::endl;
		}
		catch (const std::domain_error& e)
		{
			std::cout << "Error occurred: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "Division (float constructor):" << std::endl;
		Fixed a(10.5f);
		Fixed b(0.5f);
		
		Fixed c = a / b;
		std::cout << a << " / " << b << " = " << c << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "Division (int/float constructors):" << std::endl;
		Fixed a(49);
		Fixed b(-0.7f);
		
		Fixed c = a / b;
		std::cout << a << " / " << b << " = " << c << std::endl;
		std::cout << "\n------------------------------------\n" << std::endl;
	}
	{
		std::cout << "Comparisons:" << std::endl;
		Fixed a(7);
		Fixed b(5);
		Fixed c(5);
		
		std::cout << a << " < " << b << "\t\t" << ((a < b) ? "True" : "False") << std::endl;
		std::cout << b << " < " << a << "\t\t" << ((b < a) ? "True" : "False") << std::endl;
		std::cout << b << " < " << c << "\t\t" << ((b < c) ? "True" : "False") << std::endl;
		std::cout << std::endl;
		std::cout << a << " > " << b << "\t\t" << ((a > b) ? "True" : "False") << std::endl;
		std::cout << b << " > " << a << "\t\t" << ((b > a) ? "True" : "False") << std::endl;
		std::cout << b << " > " << c << "\t\t" << ((b > c) ? "True" : "False") << std::endl;
		std::cout << std::endl;
		std::cout << a << " <= " << b << "\t\t" << ((a <= b) ? "True" : "False") << std::endl;
		std::cout << b << " <= " << a << "\t\t" << ((b <= a) ? "True" : "False") << std::endl;
		std::cout << b << " <= " << c << "\t\t" << ((b <= c) ? "True" : "False") << std::endl;
		std::cout << std::endl;
		std::cout << a << " >= " << b << "\t\t" << ((a >= b) ? "True" : "False") << std::endl;
		std::cout << b << " >= " << a << "\t\t" << ((b >= a) ? "True" : "False") << std::endl;
		std::cout << b << " >= " << c << "\t\t" << ((b >= c) ? "True" : "False") << std::endl;
		std::cout << std::endl;
		std::cout << a << " == " << b << "\t\t" << ((a == b) ? "True" : "False") << std::endl;
		std::cout << b << " == " << a << "\t\t" << ((b == a) ? "True" : "False") << std::endl;
		std::cout << b << " == " << c << "\t\t" << ((b == c) ? "True" : "False") << std::endl;
		std::cout << std::endl;
		std::cout << a << " != " << b << "\t\t" << ((a != b) ? "True" : "False") << std::endl;
		std::cout << b << " != " << a << "\t\t" << ((b != a) ? "True" : "False") << std::endl;
		std::cout << b << " != " << c << "\t\t" << ((b != c) ? "True" : "False") << std::endl;
		std::cout << "\n------------------------------------\n" << std::endl;
	}
	{
		std::cout << "Increments/decrements:" << std::endl;
		Fixed a(1);
		Fixed b(1.5f);
		Fixed c(0);
		
		std::cout << "a + b:" << std::endl;
		std::cout << a << " + " << b << " = " << a + b << std::endl;
		std::cout << "c: " << ++c << "\n" << std::endl;

		std::cout << "(++a) + b:" << std::endl;
		std::cout << a + c << " + " << b << " = " << (++a + b) << std::endl;
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << "\n" << std::endl;

		std::cout << "(--a): " << --a << std::endl;
		std::cout << "a: " << a << "\n" << std::endl;

		std::cout << "(a++) + b:" << std::endl;
		std::cout << a << " + " << b << " = " << (a++ + b) << std::endl;
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << "\n" << std::endl;

		std::cout << "(a--): " << a-- << std::endl;
		std::cout << "a: " << a << "\n" << std::endl;

		b = Fixed(1);
		std::cout << "b: " << b << "\n" << std::endl;
		std::cout << "++a == b:" << std::endl;
		std::cout << a + c << " == " << b << "\t" << ((++a == b) ? "True" : "False") << "\n" << std::endl;

		std::cout << "a--;" << "\n" << std::endl;
		a--;
		std::cout << "a++ == b:" << std::endl;
		std::cout << a << " == " << b << "\t\t" << ((a++ == b) ? "True" : "False") << std::endl;
		std::cout << "a: " << a << std::endl;
		std::cout << "\n------------------------------------\n" << std::endl;
	}
	{
		std::cout << "min/max:" << std::endl;
		Fixed a(-3);
		Fixed b(3.3f);
		Fixed c(-3);

		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "c: " << c << "\n" << std::endl;

		std::cout << "&a: " << &a << std::endl;
		std::cout << "&c: " << &c << "\n" << std::endl;

		std::cout << "min(a, b):" << std::endl;
		std::cout << "min(" << a << ", " << b << "):\t" << Fixed::min(a, b) << "\n" << std::endl;

		std::cout << "min(a, c):" << std::endl;
		std::cout << "min(" << a << ", " << c << "):\t\t" << Fixed::min(a, c)
				  << "\t" << "Object address: " << &(Fixed::min(a, c)) << "\n" << std::endl;

		std::cout << "max(a, b):" << std::endl;
		std::cout << "max(" << a << ", " << b << "):\t" << Fixed::max(a, b) << "\n" << std::endl;

		std::cout << "max(a, c):" << std::endl;
		std::cout << "max(" << a << ", " << c << "):\t\t" << Fixed::max(a, c)
				  << "\t" << "Object address: " << &(Fixed::max(a, c)) << std::endl;
	}
	return 0;
}
