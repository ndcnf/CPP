/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:28:25 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/12 09:48:56 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"

class Ice: AMateria
{
	public:
		Ice();
		Ice(Ice const & src);
		~Ice();

		Ice	&operator=(Ice const & rhs);

		AMateria*	clone() const;
		void		use(ICharacter& target);

	private:

};

#endif
