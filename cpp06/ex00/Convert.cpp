/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asangerm <asangerm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:13:39 by asangerm          #+#    #+#             */
/*   Updated: 2024/12/09 00:50:49 by asangerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

// Constructors
	Convert::Convert()
	{

	}

	Convert::Convert(const Convert &src)
	{
		(void)src;
	}

// Destructors
	Convert::~Convert() 
	{

	}

// Operator overload
	Convert& Convert::operator = (const Convert &src)
	{
		(void)src;
		return (*this);
	}

// Main function
	void	Convert::convert(const std::string &input)
	{
		if (isChar(input))
			convertChar(input);
		else if (isInt(input))
			convertInt(input);
		else if (isFloat(input))
			convertFloat(input);
		else if (isDouble(input))
			convertDouble(input);
		else if (isSpecial(input))
			convertSpecial(input);
		else
		{
			std::cout
			<< "Invalid input: {char, int, float, double}"
			<< std::endl;
		}
	}

// Testers
	bool Convert::isChar(const std::string &input)
	{
		if (input.empty())
			return false;
		if (input.size() == 1 && !std::isdigit(input[0]))
			return true;
		return false;
	}

	bool Convert::isInt(const std::string &input)
	{
		int	i;
		long long int	test;

		i = 0;
		if (input.empty())
			return false;
		for ( ; i < input.size() && std::isspace(input[i]); i++);
		if (i == input.size())
			return false;
		if (input[i] == '+' || input[i] == '-')
			i++;
		if (i == input.size() || !std::isdigit(input[i]))
			return false;
		for ( ; i < input.size(); i++)
		{
			if (!std::isdigit(input[i]))
				return false;
		}
		test = std::stoll(input);
		if (test < INT_MIN || test > INT_MAX)
			return false;
		return true;
	}

	bool Convert::isFloat(const std::string &input)
	{
		int	i;
		long long int	test;

		i = 0;
		if (input.empty())
			return false;
		for ( ; i < input.size() && std::isspace(input[i]); i++);
		if (i == input.size())
			return false;
		if (input[i] == '+' || input[i] == '-')
			i++;
		if (i == input.size() || !std::isdigit(input[i]))
			return false;
		for ( ; i < input.size() && std::isdigit(input[i]); i++);
		if (i == input.size() || input[i] != '.')
			return false;
		i++;
		if (i == input.size() || !std::isdigit(input[i]))
			return false;
		for ( ; i < input.size() && std::isdigit(input[i]); i++);
		if (i == input.size())
			return false;
		if (i == input.size() - 1 && (input[i] == 'F' || input[i] == 'f'))
			return true; 
		return false;
	}

	bool Convert::isDouble(const std::string &input)
	{
		int	i;
		long long int	test;

		i = 0;
		if (input.empty())
			return false;
		for ( ; i < input.size() && std::isspace(input[i]); i++);
		if (i == input.size())
			return false;
		if (input[i] == '+' || input[i] == '-')
			i++;
		if (i == input.size() || !std::isdigit(input[i]))
			return false;
		for ( ; i < input.size() && std::isdigit(input[i]); i++);
		if (i == input.size() || input[i] != '.')
			return false;
		i++;
		if (i == input.size() || !std::isdigit(input[i]))
			return false;
		for ( ; i < input.size() && std::isdigit(input[i]); i++);
		if (i == input.size())
			return true;
		return false;
	}

	bool Convert::isSpecial(const std::string &input)
	{
		std::string	specials[] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

		for (int i = 0; i < 6; i++)
		{
			if (input == specials[i])
				return (true);
		}
		return (false);
	}


// Converters
	void	Convert::convertChar(const std::string &input)
	{
		char	c = input[0];
		int		i = static_cast<int>(c);
		float	f = static_cast<float>(c);
		double	d = static_cast<double>(c);

		if (isprint(c))
		{
			std::cout
			<< "char: '"
			<< c
			<< "'"
			<< std::endl;
		}
		else
		{
			std::cout
			<<"char: "
			<< "non displayable"
			<< std::endl;
		}
		std::cout
		<< "int: "
		<< i
		<< std::endl;

		std::cout
		<< "float: "
		<< std::fixed
		<< std::setprecision(1)
		<< f
		<< "f"
		<< std::endl;

		std::cout
		<< "double: "
		<< d
		<< std::endl;
	}

	void	Convert::convertInt(const std::string &input)
	{
		char	c;
		int		i = std::stoi(input);
		float	f;
		double	d;

		if (i >= std::numeric_limits<char>::min() && i <= std::numeric_limits<char>::max())
		{
			c = static_cast<char>(i);
			if (isprint(c))
			{
				std::cout
				<< "char: '"
				<< c
				<< "'"
				<< std::endl;
			}
			else
			{
				std::cout
				<< "char: non displayable" 
				<< std::endl;
			}
		}
		else
		{
			std::cout
			<< "char: impossible"
			<< std::endl;
		}

		std::cout
		<< "int: "
		<< i
		<< std::endl;
	
		f = static_cast<float>(i);
		std::cout
		<< "float: " 
		<< std::fixed
		<< std::setprecision(1)
		<< f
		<< "f"
		<< std::endl;

		d = static_cast<double>(i);
		std::cout
		<< "double: "
		<< d
		<< std::endl;
	}

	void	Convert::convertFloat(const std::string &input)
	{
		char	c;
		int		i;
		float	f = stof(input);
		double	d;

		if (f >= std::numeric_limits<char>::min() && f <= std::numeric_limits<char>::max())
		{
			c = static_cast<char>(i);
			if (isprint(c))
			{
				std::cout
				<< "char: '"
				<< c
				<< "'"
				<< std::endl;
			}
			else
			{
				std::cout
				<< "char: non displayable" 
				<< std::endl;
			}
		}
		else
		{
			std::cout
			<< "char: impossible"
			<< std::endl;
		}
		
		if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max())
		{
			i = static_cast<int>(f);
			std::cout
			<< "int: "
			<< i
			<< std::endl;
		}
		else
		{
			std::cout
			<< "int: impossible"
			<< std::endl;
		}
		
		std::cout
		<< "float: "
		<< std::fixed
		<< std::setprecision(1)
		<< f
		<< "f"
		<< std::endl;

		d = static_cast<double>(f);
		std::cout
		<< "double: "
		<< d
		<< std::endl;
	}

	void	Convert::convertDouble(const std::string &input)
	{
		char	c;
		int		i;
		float	f;
		double	d = stod(input);

		if (d >= std::numeric_limits<char>::min() && d <= std::numeric_limits<char>::max())
		{
			c = static_cast<char>(i);
			if (isprint(c))
			{
				std::cout
				<< "char: '"
				<< c
				<< "'"
				<< std::endl;
			}
			else
			{
				std::cout
				<< "char: non displayable" 
				<< std::endl;
			}
		}
		else
		{
			std::cout
			<< "char: impossible"
			<< std::endl;
		}
		
		if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
		{
			i = static_cast<int>(d);
			std::cout
			<< "int: "
			<< i
			<< std::endl;
		}
		else
		{
			std::cout
			<< "int: impossible"
			<< std::endl;
		}
		
		f = static_cast<float>(d);
		std::cout
		<< "float: "
		<< std::fixed
		<< std::setprecision(1)
		<< f
		<< "f"
		<< std::endl;

		std::cout
		<< "double: "
		<< d
		<< std::endl;
	}

	void	Convert::convertSpecial(const std::string &input)
	{
		std::cout
		<< "char: impossible"
		<< std::endl;

		std::cout
		<< "int: impossible"
		<< std::endl;

		if (input == "-inff" || input == "+inff" || input == "nanf")
		{
			std::cout
			<< "float: "
			<< input
			<< std::endl;

			std::string inputFixed = input.substr(0, input.size() - 1);
			std::cout
			<< "double: "
			<< inputFixed
			<< std::endl;
		}
		else
		{
			std::cout
			<< "float: "
			<< input
			<< "f"
			<< std::endl;

			std::cout
			<< "double: "
			<< input
			<< std::endl;
		}
	}
