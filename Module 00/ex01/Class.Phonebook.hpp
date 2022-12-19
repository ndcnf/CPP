/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.Phonebook.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:45:30 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/19 15:09:18 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CLASS_PHONEBOOK_H
# define CLASS_PHONEBOOK_H

# include "Class.Contact.hpp"

# define ROW_SEPA		"*----------*----------*----------*----------*"
# define ROW_TITLE		"|     INDEX|      NAME|   SURNAME|  NICKNAME|"
# define EMPTY			"|          |          |          |          |"
# define TITLE			"*-------------------------------------------*"
# define WORD_SEPA		"|"

# define MAX_CONTACT	8
# define MAX_LEN		10

class Phonebook
{
	public:
	Phonebook(void);
	~Phonebook(void);

	// void fonction();
	int				getNbContact(void) const;
	int				getIndex(void) const;
	void			setIndex(void);
	void			addContact(void);
	void			searchContact(void);
	std::string		wordToPrint(std::string word);

	private:
	Contact	contact[MAX_CONTACT];
	int		_nbContact;
	int		_entries;
	int		_index;
};

#endif
