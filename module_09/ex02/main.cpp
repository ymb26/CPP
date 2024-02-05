/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshana <sshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 22:20:59 by sshana            #+#    #+#             */
/*   Updated: 2023/04/06 22:25:03 by sshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Error" << std::endl;
		return EXIT_FAILURE;
	}
	std::deque<int>	arg_array;

	for (int i = 1; i < argc; ++i)
	{
		std::string	arg(argv[i]);
		if (!arg.size() || arg.find_first_not_of(TOKENS) != std::string::npos || arg.size() > 10 || (arg.size() == 10 && arg.compare(STR_INT_MAX) > 0))
		{
			std::cout << "Error" << std::endl;
			return EXIT_FAILURE;
		}
		arg_array.push_back(std::atoi(arg.c_str()));
	}

	return merge_insert_sort(arg_array);
}
