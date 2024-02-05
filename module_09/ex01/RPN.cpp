/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshana <sshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:13:12 by sshana            #+#    #+#             */
/*   Updated: 2023/03/26 21:16:20 by sshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()  {}

RPN::~RPN() {}

RPN::RPN(RPN const &copy)
{
    *this = copy;
}

RPN &RPN::operator=(RPN const &assign)
{
    (void)assign;
    return (*this);
}

void    RPN::Calculate(std::string token)
{
    if (_RPNStack.size() < 2)
    {
        std::cout << "Error: wrong expression. Check sign - \"" << token << "\"" << std::endl;
        exit(1);
    }
    int num1 = _RPNStack.top();
    _RPNStack.pop();
    int num2 = _RPNStack.top();
    _RPNStack.pop();
    if (token == "+")
        _RPNStack.push(num2 + num1);
    else if (token == "-")
        _RPNStack.push(num2 - num1);
    else if (token == "*")
        _RPNStack.push(num2 * num1);
    else if (token == "/")
        _RPNStack.push(num2 / num1);
}

void    RPN::CheckToken(std::string token)
{
    if (token.length() > 1)    {
        std::cout << "Wrong in expression." << std::endl;
        exit(1);    //clear stack
    }
    if (token == "+" || token == "-" || token == "*" || token == "/")   {
        Calculate(token);
        //std::cout << token << " - is sing." << std::endl;    ///
    }
    else if (token == "")
        return;
    else if ((int)token[0] < 58 && (int)token[0] > 47)  {
        _RPNStack.push(std::stoi(token));
        //std::cout << token << " - is number." << std::endl;  ///
    }
    else    {
        std::cout << "Wrong in numbers - " << token << std::endl;
        exit(1);
    }
}


void    RPN::PrintStack()
{
    if (_RPNStack.empty())
        std::cout << "Stack is empty." << std::endl;
    else
    {
        while (_RPNStack.empty() == false)  {
            std::cout << _RPNStack.top() << std::endl;
            _RPNStack.pop();
        }
    }
}

