/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:36:03 by yrabby            #+#    #+#             */
/*   Updated: 2023/09/19 16:13:48 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "Fixed.hpp"

static void setRawBits(void)
{
	Fixed a;

	a.setRawBits(15);
	Fixed b( a );
	Fixed c;
	
	c = b;
	
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	
	c.setRawBits(11);
	std::cout << c.getRawBits() << std::endl;
	b = c;
	std::cout << b.getRawBits() << std::endl;
}

static void main_test(void)
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
}

int main( void )
{
	main_test();
	setRawBits();
	return 0;
}
