/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:39:28 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/24 16:38:48 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	std::srand(std::time(0));
	int	randNbr = std::rand();

	if(!(randNbr % 3))
	{
		Base	*a = new A;
		return (a);
	}
	else if(randNbr % 3 == 1)
	{
		Base	*b = new B;
		return (b);
	}
	else
	{
		Base	*c = new C;
		return (c);
	}
}

// void	identify(Base *p)
// {

// }

// void	identify(Base &p)
// {

// }


int	main()
{
	// Base	*ptrBase;

	generate();

	return (0);
}
