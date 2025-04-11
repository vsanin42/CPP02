/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:24:01 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/11 11:12:33 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main(void)
{
	{
		Point a(0.0f, 0.0f);
		Point b(0.0f, 5.5f);
		Point c(5.5f, 0.0f);
		Point p(1.1f, 1.1f);
		
		std::cout << "Case 1: Right triangle (point inside)." << std::endl;
		std::cout << "Result: " << (bsp(a, b, c, p) ? "True" : "False") << "\n" << std::endl;
	}
	{
		Point a(0.0f, 0.0f);
		Point b(0.0f, 5.5f);
		Point c(5.5f, 0.0f);
		Point p(1.1f, 10.1f);
		
		std::cout << "Case 2: Right triangle (point outside)." << std::endl;
		std::cout << "Result: " << (bsp(a, b, c, p) ? "True" : "False") << "\n" << std::endl;
	}
	{
		Point a(1.0f, 1.0f);
		Point b(3.0f, 1.0f);
		Point c(2.0f, 4.0f);
		Point p(2.0f, 2.0f);
		
		std::cout << "Case 3: Non-right triangle (point inside)." << std::endl;
		std::cout << "Result: " << (bsp(a, b, c, p) ? "True" : "False") << "\n" << std::endl;
	}
	{
		Point a(1.0f, 1.0f);
		Point b(3.0f, 1.0f);
		Point c(2.0f, 4.0f);
		Point p(0.0f, 0.0f);
		
		std::cout << "Case 4: Non-right triangle (point outside)." << std::endl;
		std::cout << "Result: " << (bsp(a, b, c, p) ? "True" : "False") << "\n" << std::endl;
	}
	{
		Point a(0.0f, 0.0f);
		Point b(0.0f, 5.5f);
		Point c(5.5f, 0.0f);
		Point p(0.0f, 2.75f);
		
		std::cout << "Case 5: Point on edge (is not considered to be inside)." << std::endl;
		std::cout << "Result: " << (bsp(a, b, c, p) ? "True" : "False") << "\n" << std::endl;
	}
	{
		Point a(0.0f, 0.0f);
		Point b(0.0f, 5.5f);
		Point c(5.5f, 0.0f);
		Point p(0.0f, 0.0f);
		
		std::cout << "Case 6: Point on vertex (is not considered to be inside)." << std::endl;
		std::cout << "Result: " << (bsp(a, b, c, p) ? "True" : "False") << "\n" << std::endl;
	}
	{
		Point a(0.0f, 0.0f);
		Point b(0.0f, 5.5f);
		Point c(5.5f, 0.0f);
		Point p(5.5f, 0.0039f);
		
		std::cout << "Case 7: Point slightly outside (~epsilon - still representable difference)." << std::endl;
		std::cout << "Result: " << (bsp(a, b, c, p) ? "True" : "False") << "\n" << std::endl;
	}
	{
		Point a(0.0f, 0.0f);
		Point b(0.0f, 5.5f);
		Point c(5.5f, 0.0f);
		Point p(5.5f, 0.001f);
		
		std::cout << "Case 8: Point slightly outside (less than epsilon - rounded to zero)." << std::endl;
		std::cout << "Result: " << (bsp(a, b, c, p) ? "True" : "False") << "\n" << std::endl;
	}
	{
		Point a(0.0f, 0.0f);
		Point b(0.0f, 5.5f);
		Point c(5.5f, 0.0f);
		Point p(0.0039f, 0.0039f);
		
		std::cout << "Case 9: Point barely inside (~epsilon - still representable difference)." << std::endl;
		std::cout << "Result: " << (bsp(a, b, c, p) ? "True" : "False") << "\n" << std::endl;
	}
	{
		Point a(0.0f, 0.0f);
		Point b(0.0f, 5.5f);
		Point c(5.5f, 0.0f);
		Point p(0.001f, 0.001f);
		
		std::cout << "Case 10: Point barely inside (less than epsilon - rounded to zero)." << std::endl;
		std::cout << "Result: " << (bsp(a, b, c, p) ? "True" : "False") << "\n" << std::endl;
	}
	{
		Point a(0.0f, 0.0f);
		Point b(5.0f, 0.0f);
		Point c(7.0f, 0.0f);
		Point p(4.0f, 0.0f);
	
		std::cout << "Case 11: Degenerate triangle (all vertices on the same axis)." << std::endl;
		std::cout << "Result: " << (bsp(a, b, c, p) ? "True" : "False") << "\n" << std::endl;
	}
	{
		Point a(-5.0f, -5.0f);
		Point b(-5.0f, 5.0f);
		Point c(5.0f, -5.0f);
		Point p(-3.0f, 0.0f);
		
		std::cout << "Case 12: Negative coordinates (point inside)." << std::endl;
		std::cout << "Result: " << (bsp(a, b, c, p) ? "True" : "False") << "\n" << std::endl;
	}
	{
		Point a(-5.0f, -5.0f);
		Point b(-5.0f, 5.0f);
		Point c(5.0f, -5.0f);
		Point p(-6.0f, 0.0f);
		
		std::cout << "Case 13: Negative coordinates (point outside)." << std::endl;
		std::cout << "Result: " << (bsp(a, b, c, p) ? "True" : "False") << "\n" << std::endl;
	}
	{
		Point a(1.0f, 1.0f);
		Point b(4.0f, 3.0f);
		Point c(2.0f, 5.0f);
		Point p(2.5f, 3.0f);
		
		std::cout << "Case 14: Rotated triangle (point inside)." << std::endl;
		std::cout << "Result: " << (bsp(a, b, c, p) ? "True" : "False") << "\n" << std::endl;
	}
	{
		Point a(1.0f, 1.0f);
		Point b(4.0f, 3.0f);
		Point c(2.0f, 5.0f);
		Point p(0.0f, 0.0f);
		
		std::cout << "Case 15: Rotated triangle (point outside)." << std::endl;
		std::cout << "Result: " << (bsp(a, b, c, p) ? "True" : "False") << "\n" << std::endl;
	}
	return 0;
}
