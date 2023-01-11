/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:28:25 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/11 16:21:13 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"

class Cure: AMateria
{
	public:
		Cure();
		Cure(Cure const & src);
		~Cure();

		Cure	&operator=(Cure const & rhs);

		AMateria*	clone() const;
		void		use(ICharacter& target);

	private:

};

#endif
