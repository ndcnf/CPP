/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 10:47:07 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/29 14:11:43 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

//NOTE - This class is in canonical form

class Fixed
{
	public:
		Fixed();													//NOTE - Default constructor. If not needed, put it in private
		// Fixed(int value);										//NOTE - Constructor by int
		Fixed(Fixed const & src);									//NOTE - Copy constructor
		~Fixed();													//NOTE - Destructor

		Fixed &		operator=(Fixed const & rhs);					//NOTE - Assignment operator

		int			getRawBits(void) const;
		void		setRawBits(int const raw);

	private:
		int			_value;
		static int	const _bitsNb = 8;
};

/*NOTE - Operator overload '<<' (not canonical, but good practice)
std::ostream &		operator<<(std::ostream & o, Fixed const & i);
*/

#endif
