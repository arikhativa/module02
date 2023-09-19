/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:36:12 by yrabby            #+#    #+#             */
/*   Updated: 2023/09/19 16:21:26 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "Fixed.hpp"


static void test_setRawBits(void)
{
	Fixed a;

	a.setRawBits(15 << 8);

	std::cout << "a is " << a << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
}

static void test_toFloat(void)
{
	Fixed a;

	a.setRawBits(15 << 8);

	std::cout << "a is " << a.toFloat() << " as float" << std::endl;

	a = Fixed(-19.999f);
	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
}

static void main_test(void)
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
}

int main( void )
{
	main_test();
	test_setRawBits();
	test_toFloat();

	return 0;
}
