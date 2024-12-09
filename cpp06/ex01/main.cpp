/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:39:12 by asangerm          #+#    #+#             */
/*   Updated: 2024/12/09 17:10:05 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	uintptr_t serialized;
	Data *data = new Data();
	Data *newData;

	data->str = "sentence";
	data->integer = 389;

	std::cout << "Init:" << std::endl;
	std::cout << "str: " << data->str << std::endl;
	std::cout << "integer: " << data->integer << std::endl;
	std::cout << std::endl;

	serialized = Serializer::serialize(data);
	std::cout << "Post serialize:" << std::endl;
	std::cout << "address: " << serialized << std::endl;
	std::cout << std::endl;
	
	newData = Serializer::deserialize(serialized);
	std::cout << "Post deserialize:" << std::endl;
	std::cout << "sentence: " << newData->str << std::endl;
	std::cout << "integer: " << newData->integer << std::endl;
	std::cout << std::endl;

	serialized = Serializer::serialize(data);
	std::cout << "Post serialize:" << std::endl;
	std::cout << "address: " << serialized << std::endl;
	delete data;
}