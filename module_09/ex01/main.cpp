/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshana <sshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:09:20 by sshana            #+#    #+#             */
/*   Updated: 2023/03/26 20:49:04 by sshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)  {
        std::cout << "Wrong argument." << std::endl;
        return 1;
    }
    RPN     rpn;
    std::string  s = argv[1];
    std::string  delimiter = " ";

    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        //std::cout << token << std::endl;
        rpn.CheckToken(token);
        s.erase(0, pos + delimiter.length());
    }
    //std::cout << s << std::endl;
    if (s.length() > 0)
        rpn.CheckToken(s);
    rpn.PrintStack();
    return 0;
}