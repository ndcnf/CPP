/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:17:40 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/29 14:44:22 by nchennaf         ###   ########.fr       */
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

		int			getRawBits() const;
		void		setRawBits(int const raw);
		float		toFloat() const;
		int			toInt() const;

	private:
		int					_value;
		static int const	_bitsNb = 8;
};

// NOTE - Operator overload '<<'
std::ostream &		operator<<(std::ostream & o, Fixed const & i);

#endif
