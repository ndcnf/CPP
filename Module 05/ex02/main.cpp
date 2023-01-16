/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:29:08 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/16 16:24:29 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	ShrubberyCreationForm	form("garden");
	Bureaucrat				dude("Julien", 1);

	form.execute(dude);
	// {
	// 	std::cout << "copy case" << std::endl;

	// 	Bureaucrat deegoh = Bureaucrat("Deegoh", 20);

	// 	ShrubberyCreationForm sf = ShrubberyCreationForm("Jardin");
	// 	std::cout << sf << std::endl;

	// 	deegoh.signForm(sf);

	// 	std::cout << sf << std::endl;

	// 	ShrubberyCreationForm cpy = ShrubberyCreationForm(sf);
	// 	std::cout << cpy << std::endl;

	// 	ShrubberyCreationForm cpy1;
	// 	cpy1 = ShrubberyCreationForm(sf);
	// 	std::cout << cpy1 << std::endl;

	// 	AForm *cpy2 = new ShrubberyCreationForm(sf);
	// 	std::cout << *cpy2 << std::endl;
	// 	delete cpy2;

	// 	AForm *cpy3;
	// 	cpy3 = new ShrubberyCreationForm(sf);
	// 	std::cout << *cpy3 << std::endl;
	// 	delete cpy3;
	// }
	// std::cout << std::endl;
	// {
	// 	std::cout << "exec ShrubberyForm" << std::endl;
	// 	Bureaucrat useless = Bureaucrat("Useless", 150);
	// 	Bureaucrat sign = Bureaucrat("Signer", 140);
	// 	Bureaucrat deegoh = Bureaucrat("Deegoh", 20);
	// 	AForm *scf = new ShrubberyCreationForm("Jardin");
	// 	deegoh.signForm(*scf);
	// 	scf->execute(deegoh);
	// 	delete scf;
	// }
	// std::cout << std::endl;
	// {
	// 	std::cout << "Exec Bureaucrat ShrubberyForm " << std::endl;
	// 	Bureaucrat useless = Bureaucrat("Useless", 150);
	// 	Bureaucrat sign = Bureaucrat("Signer", 140);
	// 	Bureaucrat deegoh = Bureaucrat("Deegoh", 20);
	// 	AForm *scf = new ShrubberyCreationForm("Jardin");
	// 	deegoh.signForm(*scf);
	// 	deegoh.executeForm(*scf);
	// 	delete scf;
	// }
	// std::cout << std::endl;
	// {
	// 	std::cout << "unvalid Exec Bureaucrat ShrubberyForm " << std::endl;
	// 	Bureaucrat useless = Bureaucrat("Useless", 150);
	// 	Bureaucrat sign = Bureaucrat("Signer", 140);
	// 	Bureaucrat deegoh = Bureaucrat("Deegoh", 20);
	// 	AForm *scf = new ShrubberyCreationForm("Jardin");
	// 	{
	// 		try
	// 		{
	// 			sign.executeForm(*scf);
	// 		}
	// 		catch (ShrubberyCreationForm::SignException &se)
	// 		{
	// 			std::cout << se.what() << std::endl;
	// 		}
	// 	}
	// 	{
	// 		try
	// 		{
	// 			sign.signForm(*scf);
	// 			useless.executeForm(*scf);
	// 		}
	// 		catch (ShrubberyCreationForm::GradeTooLowException &gtle)
	// 		{
	// 			std::cout << gtle.what() << std::endl;
	// 		}
	// 	}
	// 	delete scf;
	// }
// }





	// {
	// 	std::cout	<< "-------- Here is a form --------" << std::endl;

	// 	try
	// 	{
	// 		AForm	form("Jean-Charles", 6, 7);
	// 	}
	// 	catch (Bureaucrat::GradeTooHighException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// 	catch (Bureaucrat::GradeTooLowException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// }

	// std::cout << std::endl;

	// {
	// 	std::cout	<< "-------- Here is an anonymous form --------" << std::endl;

	// 	try
	// 	{
	// 		AForm	form;
	// 	}
	// 	catch (Bureaucrat::GradeTooHighException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// 	catch (Bureaucrat::GradeTooLowException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// }

	// std::cout << std::endl;

	// {
	// 	std::cout	<< "-------- This form is too exclusive to sign --------" << std::endl;

	// 	try
	// 	{
	// 		AForm	form("Universe Peace Treaty", 0, 7);
	// 	}
	// 	catch (Bureaucrat::GradeTooHighException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// 	catch (Bureaucrat::GradeTooLowException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// }

	// std::cout << std::endl;

	// {
	// 	std::cout	<< "-------- This form is too exclusive to execute --------" << std::endl;

	// 	try
	// 	{
	// 		AForm	form("Universe Peace Treaty", 12, 0);
	// 	}
	// 	catch (Bureaucrat::GradeTooHighException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// 	catch (Bureaucrat::GradeTooLowException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// }

	// std::cout << std::endl;

	// {
	// 	std::cout	<< "-------- This form can be signed by anyone in the world therefore shouldn\'nt --------" << std::endl;

	// 	try
	// 	{
	// 		AForm	form("A LIDL receipt", 300, 1);
	// 	}
	// 	catch (Bureaucrat::GradeTooHighException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// 	catch (Bureaucrat::GradeTooLowException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// }

	// std::cout << std::endl;

	// {
	// 	std::cout	<< "-------- This form can be executed by anyone in the world therefore shouldn\'nt --------" << std::endl;

	// 	try
	// 	{
	// 		AForm	form("A LIDL receipt", 1, 300);
	// 	}
	// 	catch (Bureaucrat::GradeTooHighException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// 	catch (Bureaucrat::GradeTooLowException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// }

	// std::cout << std::endl;

	// {
	// 	std::cout	<< "-------- This form is eligible --------" << std::endl;

	// 	try
	// 	{
	// 		Bureaucrat	jeltz("Prostetnic Vogon Jeltz", 10);
	// 		Bureaucrat	zarny("Zarniwoop", 20);
	// 		AForm		form("House Peace Treaty", 10, 20);

	// 		std::cout	<< form << std::endl;
	// 		jeltz.signForm(form);
	// 	}
	// 	catch (Bureaucrat::GradeTooHighException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// 	catch (Bureaucrat::GradeTooLowException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// }

	// std::cout << std::endl;


	// {
	// 	std::cout	<< "-------- This form is eligible, but too exlusive for you --------" << std::endl;

	// 	try
	// 	{
	// 		Bureaucrat	jeltz("Prostetnic Vogon Jeltz", 11);
	// 		Bureaucrat	zarny("Zarniwoop", 20);
	// 		AForm		form("World Peace Treaty", 10, 20);

	// 		std::cout	<< form << std::endl;
	// 		jeltz.signForm(form);
	// 	}
	// 	catch (Bureaucrat::GradeTooHighException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// 	catch (Bureaucrat::GradeTooLowException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// }

	// std::cout << std::endl;


	// {
	// 	std::cout	<< "-------- This form is eligible and even an intern could sign. You're more qualified than an intern. --------" << std::endl;

	// 	try
	// 	{
	// 		Bureaucrat	jeltz("Prostetnic Vogon Jeltz", 11);
	// 		Bureaucrat	zarny("Zarniwoop", 20);
	// 		AForm		form("Inner Peace Treaty", 150, 150);

	// 		std::cout	<< form << std::endl;
	// 		jeltz.signForm(form);
	// 	}
	// 	catch (Bureaucrat::GradeTooHighException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// 	catch (Bureaucrat::GradeTooLowException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// }

	// std::cout << std::endl;

	//////////////////////////////////////////////////////////////////////
	// EARLIER TESTS
	//////////////////////////////////////////////////////////////////////

	// {
	// 	std::cout	<< "-------- Three random vogons, grade 150, networking --------" << std::endl;

	// 	try
	// 	{
	// 		Bureaucrat	jeltz("Prostetnic Vogon Jeltz", 150);
	// 		Bureaucrat	vogon;
	// 		Bureaucrat	nobody = jeltz;

	// 		std::cout	<< jeltz << std::endl;
	// 		std::cout	<< vogon << std::endl;
	// 		std::cout	<< nobody << std::endl;
	// 	}
	// 	catch (Bureaucrat::GradeTooHighException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// 	catch (Bureaucrat::GradeTooLowException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// }

	// std::cout << std::endl;

	// {
	// 	std::cout	<< "-------- Two random vogons, grade 1, networking --------" << std::endl;

	// 	try
	// 	{
	// 		Bureaucrat	mown("Constant Mown", 1);
	// 		Bureaucrat	zarny("Zarniwoop", 1);

	// 		std::cout	<< mown << std::endl;
	// 		std::cout	<< zarny << std::endl;
	// 		// mown.signForm()
	// 	}
	// 	catch (Bureaucrat::GradeTooHighException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// 	catch (Bureaucrat::GradeTooLowException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// }

	// 	std::cout << std::endl;

	// {
	// 	std::cout	<< "-------- A random vogons made a mistake and is demoted. It ends badly. --------" << std::endl;

	// 	try
	// 	{
	// 		Bureaucrat	guard("Vogon Guard Corps", 150);

	// 		std::cout	<< guard << std::endl;

	// 		guard.demoteBureaucrat();
	// 	}
	// 	catch (Bureaucrat::GradeTooHighException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// 	catch (Bureaucrat::GradeTooLowException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// }

	// 	std::cout << std::endl;

	// {
	// 	std::cout	<< "-------- A random vogons made a mistake and is demoted. They're sad. --------" << std::endl;

	// 	try
	// 	{
	// 		Bureaucrat	kwaltz("Prostetnic Kwaltz", 1);

	// 		std::cout	<< kwaltz << std::endl;

	// 		kwaltz.demoteBureaucrat();
	// 	}
	// 	catch (Bureaucrat::GradeTooHighException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// 	catch (Bureaucrat::GradeTooLowException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// }

	// 	std::cout << std::endl;

	// {
	// 	std::cout	<< "-------- A random vogon made something kinda okay and is promoted. Already at the top --------" << std::endl;

	// 	try
	// 	{
	// 		Bureaucrat	kwaltz("Prostetnic Kwaltz", 1);

	// 		std::cout	<< kwaltz << std::endl;

	// 		kwaltz.promoteBureaucrat();
	// 	}
	// 	catch (Bureaucrat::GradeTooHighException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// 	catch (Bureaucrat::GradeTooLowException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// }

	// 	std::cout << std::endl;

	// {
	// 	std::cout	<< "-------- A random vogon made something kinda okay and is promoted. They are happy. --------" << std::endl;

	// 	try
	// 	{
	// 		Bureaucrat	guard("Vogon Guard Corps", 150);

	// 		std::cout	<< guard << std::endl;

	// 		guard.promoteBureaucrat();
	// 	}
	// 	catch (Bureaucrat::GradeTooHighException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// 	catch (Bureaucrat::GradeTooLowException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// }

	// 	std::cout << std::endl;

	// {
	// 	std::cout	<< "-------- A random made nothing, but is too low graded  --------" << std::endl;

	// 	try
	// 	{
	// 		Bureaucrat	guard("Vogon Guard Corps", 151);

	// 		std::cout	<< guard << std::endl;
	// 	}
	// 	catch (Bureaucrat::GradeTooHighException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// 	catch (Bureaucrat::GradeTooLowException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// }

	// 	std::cout << std::endl;

	// {
	// 	std::cout	<< "-------- A random made nothing, but is too high graded  --------" << std::endl;

	// 	try
	// 	{
	// 		Bureaucrat	kwaltz("Prostetnic Kwaltz", 0);

	// 		std::cout	<< kwaltz << std::endl;
	// 	}
	// 	catch (Bureaucrat::GradeTooHighException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// 	catch (Bureaucrat::GradeTooLowException &e)
	// 	{
	// 		std::cout	<< e.what() << std::endl;
	// 	}
	// }

	return (0);
}
