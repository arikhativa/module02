#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{

	public:

		Fixed();
		Fixed(Fixed const &src);
		explicit Fixed(const int i);
		explicit Fixed(const float f);
		~Fixed();

		Fixed &		operator=( Fixed const & rhs );
		int			getRawBits(void) const;
		void		setRawBits(int const raw);
		float		toFloat(void) const;
		int			toInt(void) const;

	private:
		int					_value;
		static const int	_FRACTIONAL_BITS = 8;

};

std::ostream	&operator<<( std::ostream & o, Fixed const & i );


#endif /* *********************************************************** FIXED_H */
