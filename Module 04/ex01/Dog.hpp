/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:28:38 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/12 11:57:27 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
	public:
		Dog();
		Dog(Dog const & src);
		virtual ~Dog();

		Dog				&operator=(Dog const & rhs);

		virtual void	makeSound() const;
		virtual void	ideaSeeker(int i) const;

	private:
		Brain*			_brain;
};

#endif
