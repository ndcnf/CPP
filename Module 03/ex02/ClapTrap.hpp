/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:59:42 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/05 15:09:52 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

# define HP 10
# define EP 10
# define AD 0

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & src);
		~ClapTrap();

		ClapTrap 	&operator=(ClapTrap const & rhs);

		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

	protected:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
};

#endif
