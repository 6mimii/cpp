/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoudi-b <mdoudi-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:35:20 by mdoudi-b          #+#    #+#             */
/*   Updated: 2025/06/30 20:00:47 by mdoudi-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <iostream>
#include <string>
#include "contact.hpp"
#include "phonebook.hpp"

int main()
{
	Phonebook 	phonebook;
	std::string	command;	
	
	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);

		if (command == "EXIT")
		{
			std::cout << "Exiting..\n";	
			break;
		}
		else if (command == "ADD")
		{
			Contact c;
			std::string input;
			
			std::cout << "Enter first name: ";
			std::getline(std::cin, input);
			c.setFirstName(input);
		
			std::cout << "Enter last name: ";
			std::getline(std::cin, input);
			c.setLastName(input);
		
			std::cout << "Enter nickname: ";
			std::getline(std::cin, input);
			c.setNickname(input);
		
			std::cout << "Enter phone number: ";
			std::getline(std::cin, input);
			c.setPhoneNumber(input);
			
			std::cout << "Enter darkest secret: ";
			std::getline(std::cin, input);
			c.setDarkestSecret(input);
			
			phonebook.addContact(c);
		}
		else if (command == "SEARCH")
		{
			phonebook.displayContacts();
			std::string input;
			std::cout << "Enter index to view details: ";
			std::getline(std::cin, input);
			int index = -1;
			if (!input.empty() && input.find_first_not_of("0123456789") == std::string::npos)
			{
				std::istringstream iss(input);
				iss >> index;	
			}
			phonebook.displayContact(index);
		}
		else
		{
			std::cout << "Invalid command. Try again." <<std::endl;
		}
	}
	return 0;
}
