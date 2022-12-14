/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.Phonebook.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:45:30 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/21 13:10:57 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CLASS_PHONEBOOK_H
# define CLASS_PHONEBOOK_H

# include "Class.Contact.hpp"

# define ROW_SEPA		"*----------*----------*----------*----------*"
# define ROW_TITLE		"|     INDEX|      NAME|   SURNAME|  NICKNAME|"
# define TITLE			"*-------------------------------------------*"
# define WORD_SEPA		"|"

# define MAX_CONTACT	8
# define MAX_LEN		10

class Phonebook
{
	public:
	Phonebook(void);
	~Phonebook(void);

	int				getNbContact(void) const;
	void			addContact(void);
	bool			searchContact(void);
	std::string		wordToPrint(std::string word);
	void			retrieveContact(int i);
	void			printAllContacts(void);

	private:
	Contact	contact[MAX_CONTACT];
	int		_nbContact;
	int		_entries;
};

#endif
