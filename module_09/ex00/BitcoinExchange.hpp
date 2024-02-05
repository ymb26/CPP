/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshana <sshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:24:41 by sshana            #+#    #+#             */
/*   Updated: 2023/03/21 15:24:41 by sshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <fstream>
# include <string>
# include <vector>
# include <sstream>
# include <map>

#include <stdexcept>
#include <cstdlib>
#include <cstdio>
#include <regex>




class BitcoinConerter
{
    public:
        BitcoinConerter();
        ~BitcoinConerter();
        BitcoinConerter(BitcoinConerter const &copy);
        BitcoinConerter &operator=(BitcoinConerter const &assign);
        
        int    MakeDatebase();
        int    GetBase();

        void    ReadInput(char *str);
    private:
        std::map<std::string, std::string>  _database;

        void    GetFormatNumbers(std::string  line);
        bool    CheckDate(std::string data);
        void    ExportValue(std::string line, double number);

};

#endif