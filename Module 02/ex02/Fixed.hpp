/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:17:40 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/30 15:10:50 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>
# include <string>

class Fixed
{
	public:
		//NOTE - Default constructor. If not needed, put it in private
		Fixed();
		//NOTE - Constructor by int
		Fixed(int const i);
		//NOTE - Constructor by float
		Fixed(float const f);
		//NOTE - Copy constructor
		Fixed(Fixed const & src);
		//NOTE - Destructor
		~Fixed();

		//NOTE - Assignment operator
		Fixed &		operator=(Fixed const & rhs);

		bool		operator>(Fixed const & rhs) const;
		bool		operator<(Fixed const & rhs) const;
		bool		operator>=(Fixed const & rhs) const;
		bool		operator<=(Fixed const & rhs) const;
		bool		operator==(Fixed const & rhs) const;
		bool		operator!=(Fixed const & rhs) const;

		Fixed		operator+(Fixed const & rhs) const;
		Fixed		operator-(Fixed const & rhs) const;
		Fixed		operator*(Fixed const & rhs) const;
		Fixed		operator/(Fixed const & rhs) const;

		//NOTE - Overload postfix ++ operator
		Fixed		operator++(int);
		//NOTE - Overload prefix ++ operator
		Fixed &		operator++();
		//NOTE - Overload postfix ++ operator
		Fixed		operator--(int);
		//NOTE - Overload prefix ++ operator
		Fixed &		operator--();

		int			getRawBits() const;
		void		setRawBits(int const raw);
		float		toFloat() const;
		int			toInt() const;
		static float		min(Fixed & n1, Fixed & n2);
		static float		min(Fixed const & n1, Fixed const & n2);
		static float		max(Fixed & n1, Fixed & n2);
		static float		max(Fixed const & n1, Fixed const & n2);


	private:
		int					_value;
		static int const	_bitsNb = 8;
};

// NOTE - Operator overload '<<'
std::ostream &		operator<<(std::ostream & o, Fixed const & i);

#endif
