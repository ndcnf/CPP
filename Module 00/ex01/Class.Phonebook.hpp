/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.Phonebook.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:45:30 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/19 13:07:34 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CLASS_PHONEBOOK_H
# define CLASS_PHONEBOOK_H

# include "Class.Contact.hpp"

# define ROW_SEPA		"*----------*----------*----------*----------*"
# define ROW_TITLE		"|    INDEX |     NAME |  SURNAME | NICKNAME |"
# define EMPTY			"|          |          |          |          |"
# define TITLE			"*-------------------------------------------*"

# define MAX_CONTACT	8

class Phonebook
{
	public:
	Phonebook(void);
	~Phonebook(void);

	// void fonction();
	void	addContact(void);
	int		getNbContact(void);

	int		index;

	private:
	Contact	contact[MAX_CONTACT];
	int		_nbContact;
};

#endif
