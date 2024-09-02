/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 23:26:21 by asangerm          #+#    #+#             */
/*   Updated: 2024/09/02 03:26:14 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->index = 0;
	std::cout << "Vous venez d'entrer dans le répertoire de votre Nokia 3310:" << std::endl;
	std::cout << "- Tapez \x1B[32mADD\033[0m pour ajouter un contact." << std::endl;
	std::cout << "- Tapez \x1B[32mSEARCH\033[0m pour chercher un contact." << std::endl;
	std::cout << "- Tapez \x1B[32mEXIT\033[0m pour quitter le répertoire." << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Merci d'avoir utilisé votre répertoire Nokia 3310." << std::endl;
	std::cout << "Fermeture en cours ..." << std::endl;
}

void	PhoneBook::add(void)
{
	std::string	str;

	if (this->index > 7)
		std::cout << "\x1B[31mAttention\033[0m: Vous écrasez les données de: \x1B[34m" << this->contacts[this->index % 8].get_first_name() << " " << this->contacts[this->index % 8].get_last_name() << " dit " << this->contacts[this->index % 8].get_nick_name() << "\033[0m" <<std::endl;
	str = "";
	while (str == "")
	{
		std::cout << "Entrez un prénom: ";
		if (std::getline(std::cin, str) && str != "")
			this->contacts[this->index % 8].set_first_name(str);
	}
	str = "";
	while (str == "")
	{
		std::cout << "Entrez un nom: ";
		if (std::getline(std::cin, str) && str != "")
			this->contacts[this->index % 8].set_last_name(str);
	}
	str = "";
	while (str == "")
	{
		std::cout << "Entrez un surnom: ";
		if (std::getline(std::cin, str) && str != "")
			this->contacts[this->index % 8].set_nick_name(str);
	}
	str = "";
	while (str == "")
	{
		std::cout << "Entrez un numero de téléphone: ";
		if (std::getline(std::cin, str) && str != "")
			this->contacts[this->index % 8].set_phone_number(str);
	}
	str = "";
	while (str == "")
	{
		std::cout << "Entrez un secret inavouable: ";
		if (std::getline(std::cin, str) && str != "")
			this->contacts[this->index % 8].set_darkest_secret(str);
	}
	std::cout << "\x1B[32mContact ajouté avec succés!\033[0m" << std::endl;
	this->index++;
}

void	PhoneBook::search(void)
{
	int			i;
	std::string	str;

	if (!this->contacts[0].get_first_name().size())
	{
		std::cout << "Répertoire vide." << std::endl;
		return ;
	}
	std::cout << "Entrez l'index correspondant au contact recherché:" << std::endl;
	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|     Index|    Prénom|       Nom|    Surnom|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	i = 0;
	str = "";
	while (i < 8)
	{
		if (this->contacts[i].get_first_name().size())
		{
			std::cout << "|" << std::setw(10) << i + 1 << '|';
			if (this->contacts[i].get_first_name().size() > 10)
				str = (this->contacts[i].get_first_name()).substr(0, 9) + '.';
			else
				str = this->contacts[i].get_first_name();
			std::cout << std::setw(10) << str << '|';
			if (this->contacts[i].get_last_name().size() > 10)
				str = (this->contacts[i].get_last_name()).substr(0, 9) + '.';
			else
				str = this->contacts[i].get_last_name();
			std::cout << std::setw(10) << str << '|';
			if (this->contacts[i].get_nick_name().size() > 10)
				str = (this->contacts[i].get_nick_name()).substr(0, 9) + '.';
			else
				str = this->contacts[i].get_nick_name();
			std::cout << std::setw(10) << str << '|' << std::endl;
		}
		i++;
	}
	std::cout << "|-------------------------------------------|" << std::endl;
	str = "";
	while (str == "")
	{
		if (std::getline(std::cin, str) && str != "")
		{
			if (str.size() > 1)
				break ;
			i = std::stoi(str);
			if (i > 8)
			{
				str = "";
				break;
			}
			this->print(this->contacts[i - 1]);
		}
	}
}

void	PhoneBook::print(Contact contact)
{
	if (!contact.get_first_name().size())
	{
		std::cout << "\x1B[31mContact inexistant.\033[0m" << std::endl;
		return ;
	}
	std::cout << "Prénom: " << contact.get_first_name() << std::endl;
	std::cout << "Nom: " << contact.get_last_name() << std::endl;
	std::cout << "Surnom: " << contact.get_nick_name() << std::endl;
	std::cout << "Numéro de téléphone: " << contact.get_phone_number() << std::endl;
	std::cout << "Secret inavouable: " << contact.get_darkest_secret() << std::endl;
}
