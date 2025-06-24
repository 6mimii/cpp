/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoudi-b <mdoudi-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:47:40 by mdoudi-b          #+#    #+#             */
/*   Updated: 2025/06/24 15:15:42 by mdoudi-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
std::string _firstName;
std::string _lastName;
std::string _nickname;
std::string _phoneNumber;
std::string _darkestSecret;
public:
Contact();
~Contact();

// setters (reciben y asignan un valor, posiblemente validandolo)

void setFirstName (const std::string &firstName);
void setLastName (const std::string &lastName);
void setNickname (const std::string &nickname);
void setPhoneNumber (const std::string &phoneNumber);
void setDarkestSecret (const std::string &darkestSecret);

// getters (devuelve el valor de un atributo privado)

std::string getFirstName() const;
std::string getLastName() const;
std::string getNickName () const;
std::string getPhoneNumber() const;
std::string getDarkestSecret() const;

};

#endif