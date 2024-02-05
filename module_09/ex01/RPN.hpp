/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshana <sshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:15:53 by sshana            #+#    #+#             */
/*   Updated: 2023/03/26 20:49:01 by sshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <string>

class RPN
{
    private:
        std::stack <int>  _RPNStack;

    public:
        RPN();
        ~RPN();
        RPN(RPN const &copy);
        RPN &operator=(RPN const &assign);

        void    CheckToken(std::string token);
        void    PrintStack();
        void    Calculate(std::string token);
};



#endif