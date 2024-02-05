/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshana <sshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:25:19 by sshana            #+#    #+#             */
/*   Updated: 2023/03/21 15:25:19 by sshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

time_t dateToTimeT(std::string month, std::string day, std::string year) {
  // january 5, 2000 is passed as (1, 5, 2000)
  tm tmp = tm();
  tmp.tm_mday = atoi(day.c_str());
  tmp.tm_mon = atoi(month.c_str()) - 1;
  tmp.tm_year = atoi(year.c_str()) - 1900;
  return mktime(&tmp);
}

std::string ltrim(const std::string &s) {
    return std::regex_replace(s, std::regex("^\\s+"), std::string(""));
}

std::string rtrim(const std::string &s) {
    return std::regex_replace(s, std::regex("\\s+$"), std::string(""));
}

std::string trim(const std::string &s)  {
    return ltrim(rtrim(s));
}

BitcoinConerter::BitcoinConerter() {}

BitcoinConerter::~BitcoinConerter() {}

BitcoinConerter::BitcoinConerter(BitcoinConerter const &copy)
{
    *this = copy;
}

BitcoinConerter &BitcoinConerter::operator=(BitcoinConerter const &assign)
{
    (void)assign;
    return (*this);
}

int    BitcoinConerter::MakeDatebase()
{
    std::string  line;

    std::ifstream in("data2.csv");
    if (in.is_open())
    {
        while (getline(in, line))
        {
            if (!line.find("date"))
                continue;
            //(_database).insert({line.substr(0, line.find(',')), line.substr(line.find(',') + 1, line.length())});
            _database.insert(std::pair<std::string, std::string>(trim(line.substr(0, line.find(','))), line.substr(line.find(',') + 1, line.length())));
        }
    }
    else    {
        std::cout << "Error: could not open datebase." << std::endl;
        return 1;
    }
    in.close();
    return 0;
}

int    BitcoinConerter::GetBase()
{
    if (_database.size() == 0)   {
        std::cout << "Database is empty." << std::endl;
        return 1;
    }

    std::map <std::string, std::string>::iterator it = _database.begin();
    for (int i = 0; it != _database.end(); it++, i++) {
        std::cout << i << ") Key " << it->first << ", value " << it->second << std::endl;
    }
    return 0;
}

void    BitcoinConerter::ExportValue(std::string line, double number)
{
    std::map<std::string, std::string>::iterator it;
    it = _database.find(trim(line.substr(0, line.find('|') )));
    double value;

    if (it != _database.end())
        value = stod(_database.at(trim(line.substr(0, line.find('|') ))));
    else    
    {
        std::map <std::string, std::string> :: const_iterator ds_Low, ds_Up;
        ds_Low = _database.lower_bound(line.substr(0,10));
        if(ds_Low != _database.begin())
            ds_Up = --ds_Low;  
        value = stod(_database.at(ds_Low->first));
    }
    std::cout << line.substr(0, line.find('|')) << "=> " << number << " = " << value * number << std::endl;
}

void    BitcoinConerter::GetFormatNumbers(std::string line)
{
    try
    {
        double number = std::stod(line.substr(line.find('|') + 1, line.size()));
        std::size_t found = line.find(".");
        //found!=std::string::npos
        if (found == std::string::npos)   {
            if (number < 0) {
                std::cout << "Error: not a positive integer number." << std::endl;
                return;
            }
            else if (number > 1000) {
                std::cout << "Error: too large a number." << std::endl;
                return;
            }
        }
        if (CheckDate(line.substr(0, line.find('|'))))  {
            //std::cout << line.substr(0, line.find('|')) << "=> " << number << " = " << std::endl;
            ExportValue(line, number);
        }
        else
            std::cout << "Error: bad format of date - " << line.substr(0, line.find('|')) << std::endl;

    }
    catch(const std::exception& e)
    {
        (void)e;
        std::cout << "Error: Input Not A Number" << std::endl;
    }
    
}

bool BitcoinConerter::CheckDate(std::string data)
{ 
    std::tm t = {};
    std::istringstream ss(data);
    ss.imbue(std::locale("de_DE.utf-8"));
    ss >> std::get_time(&t, "%Y-%m-%d");
 
    if (ss.fail())  {
        //std::cout << "Parse failed\n";
        return false;
    }
    else    {
        //std::cout << std::put_time(&t, "%c") << '\n';
        return true;
    }
}



void    BitcoinConerter::ReadInput(char *str)
{
    std::string  line;
    std::size_t found;

    std::ifstream in(str);
    if (in.is_open())
    {
        while (getline(in, line))
        {
            found = line.find('|');
            if (line.size() < 5)
                std::cout << "Error: bad line." << std::endl;
            else if (!line.find("date"))
                std::cout << "date | value" << std::endl;
            else if (found==std::string::npos)
                std::cout << "Error: bad format => without - \'|\'." << std::endl;
            else if (line.substr(0, line.find('|')).size() > 11)   //date check
                std::cout << "Error: bad input => " << line.substr(0, line.find('|'))  << std::endl;
            else
                GetFormatNumbers(line);
                //std::cout << std::stod(line.substr(line.find('|') + 1, line.size())) << std::endl;
            //std::cout << line.substr(0, line.find('|')) << " " << line.substr(0, line.find('|')).size() << std::endl;
        }
    }
    else
        std::cout << "Error: could not open input file." << std::endl;
    in.close();
}
