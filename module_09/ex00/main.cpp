/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshana <sshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:24:37 by sshana            #+#    #+#             */
/*   Updated: 2023/03/21 15:24:37 by sshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <ctime>
#include <chrono>

//using namespace std;

int main(int argc, char **argv)
{
    if (argc != 2)
        std::cout << "Error: could not open file." << std::endl;

    BitcoinConerter converter;

    if (converter.MakeDatebase())
        return 1;
    //if (converter.GetBase())
    //    return 1;
    
    converter.ReadInput(argv[1]);

    return 0;
}