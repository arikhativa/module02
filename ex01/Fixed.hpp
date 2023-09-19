/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:36:10 by yrabby            #+#    #+#             */
/*   Updated: 2023/09/19 15:36:10 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{

	public:

		Fixed(void);
		Fixed(Fixed const &src);
		explicit Fixed(const int i);
		explicit Fixed(const float f);
		~Fixed(void);

		Fixed &		operator=( Fixed const & rhs );
		int			getRawBits(void) const;
		void		setRawBits(int const raw);
		float		toFloat(void) const;
		int			toInt(void) const;

	private:
		static const int	_FRACTIONAL_BITS = 8;

		int					_value;
};

std::ostream	&operator<<( std::ostream & o, Fixed const & i );


#endif /* *********************************************************** FIXED_H */
