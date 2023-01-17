/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:36:31 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/17 17:05:03 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():
	AForm("a request by the Knights who say Ni", LVL_SIGN_SHR, LVL_EXEC_SHR),
	_target("Ni")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	AForm("a request by the Knights who say Ni", LVL_SIGN_SHR, LVL_EXEC_SHR),
	_target(target)
{

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		_target = rhs._target;
	}
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src):
	AForm(src)
{
	*this = src;
	std::cout	<< "a carbone copy has been made."
				<< std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout	<< "Ni! (Bye)" << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::string		file = _target;
	std::string		fileContent = TOP;

	fileContent += MID;
	fileContent += LOW;
	fileContent += TRK;

	file += "_shrubbery";

	std::ofstream	ofs(file);

	ofs << fileContent;
	std::cout	<< "-> Your file "
				<< file
				<< " is ready."
				<< std::endl;
	ofs.close();
}
