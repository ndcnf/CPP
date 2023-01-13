/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:07:49 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/13 12:44:48 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include <string>

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

	protected:
		std::string	_name;
		int			_grade;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif
