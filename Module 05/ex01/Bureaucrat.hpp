/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:07:49 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/13 15:45:29 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Bureaucrat;

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include <string>
# include "Form.hpp"

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const & src);
		Bureaucrat & operator=(Bureaucrat const & rhs);
		~Bureaucrat();

		//////////////////////////////////////////////

		std::string		getName() const;
		int				getGrade() const;

		//////////////////////////////////////////////

		void	promoteBureaucrat();
		void	demoteBureaucrat();
		void	signForm(Form &f);

		//////////////////////////////////////////////

		class GradeTooHighException:
			public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException:
			public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		//////////////////////////////////////////////

	private:
		std::string	const	_name;
		int					_grade;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif
