/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.Contact.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:45:30 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/21 13:12:30 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CLASS_CONTACT_H
# define CLASS_CONTACT_H

# include <iostream>

class Contact
{
	public:
	Contact(void);
	~Contact(void);

	std::string	getFirstName(void) const;
	std::string	getLastName(void) const;
	std::string	getNickname(void) const;
	std::string	getTelephoneNum(void) const;
	std::string	getDarkestSecret(void) const;

	void	setFirstName(std::string s);
	void	setLastName(std::string s);
	void	setNickname(std::string s);
	void	setTelephoneNum(std::string s);
	void	setDarkestSecret(std::string s);

	private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_telephoneNum;
	std::string	_darkestSecret;
};

#endif
