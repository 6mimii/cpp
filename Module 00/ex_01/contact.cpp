/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoudi-b <mdoudi-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:34:06 by mdoudi-b          #+#    #+#             */
/*   Updated: 2025/06/24 15:58:17 by mdoudi-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}


// Setters (declaramos las funciones para asignar valor a los atributos (variables))

void Contact::setFirstName(const std::string &firstName)
{
	_firstName = firstName;
}

void Contact::setLastName(const std::string &lastName)
{
	_lastName = lastName;
}

void Contact::setNickname(const std::string &nickName)
{
	_nickname = nickName;
}

void Contact::setPhoneNumber(const std::string &phoneNumber)
{
	_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string &darkestSecret)
{
	_darkestSecret = darkestSecret;
}


//Getters ()
 
std::string Contact::getFirstName() const
{
	return _firstName;
}

std::string Contact::getLastName() const
{
	return _lastName;
}

std::string Contact::getNickName () const
{
	return _nickname;
}

std::string Contact::getPhoneNumber () const
{
	return _phoneNumber;
}

std::string Contact:: getDarkestSecret () const
{
	return _darkestSecret;
}
