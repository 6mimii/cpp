/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoudi-b <mdoudi-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:12:06 by mdoudi-b          #+#    #+#             */
/*   Updated: 2025/06/24 15:35:20 by mdoudi-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

class Phonebook
{
	private:
		Contact contacts[8];
		int nextIndex;
		int totalContacts;

	public:
		Phonebook ();
		void addContact (const Contact &newContact);
		void displayContacts() const;
		void displayContact(int index) const;
};

#endif