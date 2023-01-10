/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:09:11 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/10 11:20:31 by nchennaf         ###   ########.fr       */
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
		virtual ~Animal();

		Animal			&operator=(Animal const & rhs);

		virtual void	makeSound() const;
		std::string		getType() const;

	protected:
		std::string		_type;
};

#endif
