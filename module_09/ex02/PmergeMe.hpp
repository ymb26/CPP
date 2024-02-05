/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshana <sshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 22:22:44 by sshana            #+#    #+#             */
/*   Updated: 2023/04/06 22:22:58 by sshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

# include <stdlib.h>
# include <iostream>
# include <string>
# include <cstdlib>
# include <time.h>
# include <iomanip>
# include <vector>
# include <deque>

# define TOKENS "0123456789 +"
# define STR_INT_MAX std::string("2147483647")

int	merge_insert_sort(std::deque<int> arg_array);

#endif
