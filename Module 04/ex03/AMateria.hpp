/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:14:41 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/11 16:25:53 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class AMateria
{
	public:
		AMateria();
		AMateria(std::string const & type);
		virtual ~AMateria();

		AMateria	&operator=(AMateria const & rhs);

		std::string const	& getType() const; //Returns the materia type
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);

	protected:
		std::string			_type;

		AMateria(AMateria const & src);
};

#endif
