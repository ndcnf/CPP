/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:45:11 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/13 15:48:06 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Form;

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>
# include <string>
# include "Bureaucrat.hpp"

class Form
{
	public:
		Form();
		Form(Form const & src);
		Form(std::string name, int signGrade, int execGrade);
		~Form();
		Form	&operator=(Form const & rhs);

		//////////////////////////////////////////////

		void	beSigned(Bureaucrat &b);

		//////////////////////////////////////////////

		std::string		getName() const;
		int				getFormSigned() const;
		int				getSignGrade() const;
		int				getExecGrade() const;

		//////////////////////////////////////////////

	private:
		std::string const	_name;
		bool				_signed;
		int const			_signGrade;
		int const			_execGrade;
};

std::ostream	&operator<<(std::ostream & o, Form const & rhs);

#endif
