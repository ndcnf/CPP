/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitute.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:07:52 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/27 11:14:49 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "substitute.hpp"

std::string	getWord() const
{
	return (this->_word);
}

void		setWord(std::string word)
{
	this->_word = word;
}
