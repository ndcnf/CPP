/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:09:11 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/06 16:32:59 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	public:
		Animal();
		Animal(Animal const & src);
		~Animal();

		Animal		&operator=(Animal const & rhs);

		void		makeSound();
		std::string	getType();

	protected:
		std::string	_type;
};

#endif
