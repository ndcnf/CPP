/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:39:28 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/24 17:34:59 by nchennaf         ###   ########.fr       */
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

void	identify(Base *p)
{
	A *a = dynamic_cast<A *>(p);
	B *b = dynamic_cast<B *>(p);
	C *c = dynamic_cast<C *>(p);

	if(a != NULL)
		std::cout << "* A." << std::endl;
	else if (b != NULL)
		std::cout << "* B." << std::endl;
	else if (c != NULL)
		std::cout << "* C." << std::endl;
	else
		std::cout << "Error" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "& A." << std::endl;
	}
	catch(const std::exception& e)
	{

	}

	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "& B." << std::endl;
	}
	catch(const std::exception& e)
	{

	}

	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "& C." << std::endl;
	}
	catch(const std::exception& e)
	{

	}
}

int	main()
{
	Base	*ptr;

	ptr = generate();

	Base &ref = *ptr;

	identify(ptr);
	identify(ref);

	delete(ptr);

	return (0);
}
