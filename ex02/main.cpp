/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:36:21 by yrabby            #+#    #+#             */
/*   Updated: 2023/09/19 16:39:29 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "Fixed.hpp"

void test_min_max(void)
{
	std::cout << std::endl << " -- Tests test_min_max --" << std::endl << std::endl;
	Fixed a(15);
	Fixed b(2.5f);
	
	std::cout << "a: 15, b: 2.5" << std::endl;
	std::cout << "expect 2.5\t->\t" << Fixed::min(a, b) << std::endl;
	std::cout << "expect 15\t->\t" << Fixed::max(a, b) << std::endl;

	const Fixed c(99.9f);
	const Fixed d(99.8f);
	std::cout << "c: 99.9, d: 99.8" << std::endl;
	std::cout << "expect 99.8\t->\t" << Fixed::min(c, d) << std::endl;
	std::cout << "expect 99.9\t->\t" << Fixed::max(c, d) << std::endl;
	std::cout << std::endl << " -- Tests test_min_max -- (END)" << std::endl;
}

void test_compare(void)
{
	std::cout << std::endl << " -- Tests test_compare --" << std::endl << std::endl;
	Fixed a(15);
	Fixed b(2.5f);
	
	std::cout << "a: 15, b: 2.5" << std::endl;
	std::cout << "expect 1\t->\t" << (a != b) << std::endl;
	std::cout << "expect 0\t->\t" << (a == b) << std::endl;
	std::cout << "expect 1\t->\t" << (a > b) << std::endl;
	std::cout << "expect 0\t->\t" << (a < b) << std::endl;
	std::cout << "expect 0\t->\t" << (a <= b) << std::endl;
	std::cout << "expect 1\t->\t" << (a >= b) << std::endl;

	b = Fixed(14.9999999999f);
	std::cout << "a: 15, b: 14.9999999999" << std::endl;
	std::cout << "expect 0\t->\t" << (a != b) << std::endl;
	std::cout << "expect 1\t->\t" << (a == b) << std::endl;
	std::cout << "expect 0\t->\t" << (a > b) << std::endl;
	std::cout << "expect 0\t->\t" << (a < b) << std::endl;
	
	std::cout << "expect 1\t->\t" << (a <= b) << std::endl;
	std::cout << "expect 1\t->\t" << (a >= b) << std::endl;
	std::cout << std::endl << " -- Tests test_compare -- (END)" << std::endl;
}

void test_basic_math(void)
{
	std::cout << std::endl << " -- Tests test_basic_math --" << std::endl << std::endl;
	Fixed a(15);
	Fixed b(2.5f);
	
	std::cout << "expect 17.5\t->\t" << a + b << std::endl;
	std::cout << "expect 12.5\t->\t" << a - b << std::endl;
	std::cout << "expect 6\t->\t" << a / b << std::endl;
	std::cout << "expect 37.5\t->\t" << a * b << std::endl;

	a = b;
	
	std::cout << "expect 5\t->\t" << a + b << std::endl;
	std::cout << "expect 0\t->\t" << a - b << std::endl;
	std::cout << "expect 1\t->\t" << a / b << std::endl;
	std::cout << "expect 6.25\t->\t" << a * b << std::endl;
	std::cout << std::endl << " -- Tests test_basic_math -- (END)" << std::endl;
}

void test_inc_dec(void)
{
	std::cout << std::endl << " -- Tests test_inc_dec --" << std::endl << std::endl;
	Fixed a;
	
	std::cout << "a should be 0: " << a++ << std::endl;
	std::cout << "a should be 0.00390625: " << a << std::endl;

	std::cout << "a should be 0.00390625: " << a-- << std::endl;
	std::cout << "a should be 0: " << a << std::endl;

	std::cout << "a should be -0.00390625: " << --a << std::endl;
	std::cout << "a should be 0: " << ++a << std::endl;
	std::cout << std::endl << " -- Tests test_inc_dec -- (END)" << std::endl;
}

void test_subject(void)
{
	std::cout << std::endl << " -- Tests From Subject --" << std::endl << std::endl;
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << std::endl << " -- Tests From Subject -- (END)" << std::endl;

}

int main( void )
{
	test_subject();
	test_inc_dec();
	test_basic_math();
	test_compare();
	test_min_max();

	return 0;
}
