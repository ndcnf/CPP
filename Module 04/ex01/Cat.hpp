/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:18:09 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/09 14:53:45 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
	public:
		Cat();
		Cat(Cat const & src);
		~Cat();

		Cat				&operator=(Cat const & rhs);

		virtual void	makeSound() const;

	private:
		Brain*			_brain;

};

#endif
