/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:36:21 by yrabby            #+#    #+#             */
/*   Updated: 2023/09/20 11:05:50 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <bitset>

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

void printFloatBits(float value) {
    uint32_t intValue;
    std::memcpy(&intValue, &value, sizeof(float));

    std::bitset<sizeof(float) * 8> bits(intValue);

	std::cout << "float\t==\t" << value << "\t->\t" << bits << std::endl;
}

void printIntBits(int value) {
    std::bitset<sizeof(int) * 8> bits(value);
	std::cout << "int\t==\t" << value << "\t->\t" << bits << std::endl;
}

void explain_int_to_int(void)
{
	int i = 5;
	std::cout << "int i(5)" << std::endl;
	printIntBits(i);

	std::cout << "int fix_value(i << 8)" << std::endl;
	int fix_value(i << 8);
	printIntBits(fix_value);

	std::cout << "int back_to_int(fix_value >> 8)" << std::endl;
	int back_to_int(fix_value >> 8);
	printIntBits(back_to_int);
}

void explain_int_to_float(void)
{
	int i = 5;
	std::cout << "int i(5);" << std::endl;
	printIntBits(i);

	std::cout << "int fix_value(i << 8);" << std::endl;
	int fix_value(i << 8);
	printIntBits(fix_value);

	std::cout << "float turn_to_float((float)fix_value);" << std::endl;
	float turn_to_float((float)fix_value);
	printFloatBits(turn_to_float);

	std::cout << "float divide(turn_to_float / (1 << 8));" << std::endl;
	float divide(turn_to_float/ (1 << 8));
	printFloatBits(divide);
}


void explain_float_to_float(void)
{
	std::cout << "float f = 5.1;" << std::endl;
	float f = 255;
	printFloatBits(f);

	std::cout << "float fix_value_pre_round(f * (1 << 8));" << std::endl;
	float fix_value_pre_round(f * (1 << 8));
	printFloatBits(fix_value_pre_round);

	std::cout << "float rounded(roundf(fix_value_pre_round));" << std::endl;
	float rounded(roundf(fix_value_pre_round));
	printFloatBits(rounded);

	std::cout << "int cast_to_int((int)rounded);" << std::endl;
	int cast_to_int((int)rounded);
	printIntBits(cast_to_int);

	std::cout << "float cast_to_float((float)cast_to_int);" << std::endl;
	float cast_to_float((float)cast_to_int);
	printFloatBits(cast_to_float);

	std::cout << "float divide(cast_to_float / (1 << 8));" << std::endl;
	float divide(cast_to_float / (1 << 8));
	printFloatBits(divide);
}

int main( void )
{
	test_subject();
	// test_inc_dec();
	// test_basic_math();
	// test_compare();
	// test_min_max();
	// explain_int_to_int();
	// explain_int_to_float();
	// explain_float_to_float();

	return 0;
}
