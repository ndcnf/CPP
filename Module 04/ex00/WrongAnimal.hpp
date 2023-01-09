/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:09:11 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/09 13:12:31 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const & src);
		~WrongAnimal();

		WrongAnimal		&operator=(WrongAnimal const & rhs);

		virtual void	makeSound() const;
		std::string		getType() const;

	protected:
		std::string		_type;
};

#endif
