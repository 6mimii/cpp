/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoudi-b <mdoudi-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:12:03 by mdoudi-b          #+#    #+#             */
/*   Updated: 2025/06/24 17:48:51 by mdoudi-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>
#include <iomanip>

Phonebook::Phonebook()
{
	nextIndex = 0;
	totalContacts = 0;
}

void Phonebook::addContact(const Contact &newContact)
{
	contacts[nextIndex] = newContact;
	nextIndex = (nextIndex + 1) % 8;

	if (totalContacts < 8)
		totalContacts++;
}

std::string formatField(const std::string &field)
{
	if (field.length() > 10)
		return field.substr(0, 9) + ".";
	else
		return field;
}

void Phonebook::displayContacts() const
{
	std::cout << "|     Index|First Name| Last Name| Nickname|" << std::endl;
	
	for (int i = 0; i < totalContacts; i++)
	{
		std::cout << "|" << std::setw(10) << i
				  << "|" << std::setw(10) << formatField(contacts[i].getFirstName())
				  << "|" << std::setw(10) << formatField(contacts[i].getLastName())
				  << "|" << std::setw(10) << formatField(contacts[i].getNickName())
				  << "|" << std::endl;				  
	}
}

void Phonebook::displayContact(int index) const
{
	if (index < 0 || index >= totalContacts)
	{
		std::cout << "Invalid contact index." << std::endl;
		return;
	}

	const Contact &c = contacts[index];
	
	std::cout << "First Name: " << c.getFirstName() << std::endl;
    std::cout << "Last Name: " << c.getLastName() << std::endl;
    std::cout << "Nickname: " << c.getNickName() << std::endl;
    std::cout << "Phone Number: " << c.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << c.getDarkestSecret() << std::endl;
}
