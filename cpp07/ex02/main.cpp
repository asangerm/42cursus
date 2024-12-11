/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:47:20 by asangerm          #+#    #+#             */
/*   Updated: 2024/12/11 23:40:08 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
    Array<int> array1(10);

    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        array1[i] = rand();
    }

    try
    {
        array1[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

	for (int i = 0; i < 10; i++)
	{
		std::cout << "index: " << i << "; value: " << array1[i] << std::endl;
	}

    return 0;
}