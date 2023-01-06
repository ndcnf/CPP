/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 09:42:03 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/06 13:30:03 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap const & src);
		~FragTrap();

		FragTrap	&operator=(FragTrap const & rhs);

		void	highFivesGuys(void);
		bool	getHighFiveAcknoledged();

	private:
		bool	_highFiveAcknowledged;
};


#endif
