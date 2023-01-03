/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:17:40 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/03 13:06:03 by nchennaf         ###   ########.fr       */
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
		Fixed();																//NOTE - Default constructor. If not needed, put it in private
		Fixed(int const i);														//NOTE - Constructor by int
		Fixed(float const f);													//NOTE - Constructor by float
		Fixed(Fixed const & src);												//NOTE - Copy constructor
		~Fixed();																//NOTE - Destructor

		Fixed &		operator=(Fixed const & rhs);								//NOTE - Assignment operator

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

		Fixed		operator++(int);											//NOTE - Overload postfix ++ operator
		Fixed &		operator++();												//NOTE - Overload prefix ++ operator
		Fixed		operator--(int);											//NOTE - Overload postfix ++ operator
		Fixed &		operator--();												//NOTE - Overload prefix ++ operator

		int			getRawBits() const;
		void		setRawBits(int const raw);
		float		toFloat() const;
		int			toInt() const;

		static const Fixed &	min(const Fixed & n1, const Fixed & n2);
		static Fixed &			min(Fixed & n1, Fixed & n2);
		static const Fixed &	max(const Fixed & n1, const Fixed & n2);
		static Fixed &			max(Fixed & n1, Fixed & n2);

	private:
		int					_value;
		static int const	_bitsNb = 8;
};

std::ostream &		operator<<(std::ostream & o, Fixed const & i);				// NOTE - Operator overload '<<'

#endif
