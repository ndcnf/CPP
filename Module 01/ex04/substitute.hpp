/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitute.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:20:30 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/27 11:15:00 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUBSTITUTE_HPP
# define SUBSTITUTE_HPP
# include <iostream>
# include <fstream>

class substitute
{
	public:
		substitute(/* args */);
		~substitute();

		std::string	getWord() const;
		void		setWord(std::string word);

	private:
		std::string	_word;
		std::string	_content;
};

substitute::substitute(/* args */)
{
}

substitute::~substitute()
{
}

#endif
