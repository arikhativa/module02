#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
	public:

		Fixed(void);
		Fixed( Fixed const & src );
		~Fixed(void);

		Fixed &		operator=( Fixed const & rhs );
		int			getRawBits(void) const;
		void		setRawBits(int const raw);

	private:
		static const int	_FRACTIONAL_BITS = 8;

		int					_value;
};

#endif /* *********************************************************** FIXED_H */
