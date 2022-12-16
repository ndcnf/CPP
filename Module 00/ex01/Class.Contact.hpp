/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.Contact.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:45:30 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/16 13:58:31 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CLASS_CONTACT_H
# define CLASS_CONTACT_H

class Contact
{
	public:
	char	*firstName;
	char	*lastName;
	char	*nickname;
	char	*telephoneNum;
	char	*darkestSecret;


	Contact(void);
	~Contact(void);
};

#endif
