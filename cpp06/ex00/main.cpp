/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:24:40 by asangerm          #+#    #+#             */
/*   Updated: 2024/12/09 00:01:02 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int main(void)
{
	Convert::convert("s");
	Convert::convert("14");
	Convert::convert("-148.32f");
	Convert::convert("-148.32");
	Convert::convert("-inf");
}