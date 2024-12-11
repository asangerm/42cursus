/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:08:52 by asangerm          #+#    #+#             */
/*   Updated: 2024/12/11 16:19:01 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
    int arrayInt[] = {1, 2, 3, 4, 5};
    size_t lenI = sizeof(arrayInt) / sizeof(arrayInt[0]);

    std::cout << "Integer array: ";
    iter(arrayInt, lenI, printer<int>);
    std::cout << std::endl;

    double arrayDouble[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t lenD = sizeof(arrayDouble) / sizeof(arrayDouble[0]);

    std::cout << "Double array: ";
    iter(arrayDouble, lenD, printer<double>);
    std::cout << std::endl;

    std::string arrayString[] = {"str", "string", "char *"};
    size_t lenS = sizeof(arrayString) / sizeof(arrayString[0]);

    std::cout << "String array: ";
    iter(arrayString, lenS, printer<std::string>);
    std::cout << std::endl;

    return 0;
}