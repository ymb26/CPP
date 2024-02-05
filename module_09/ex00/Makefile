# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshana <sshana@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 22:29:46 by sshana            #+#    #+#              #
#    Updated: 2023/04/06 22:29:48 by sshana           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp BitcoinExchange.cpp

OBJ = $(SRC:.cpp=.o)

CC = c++

RM = rm -f

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = btc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(HEADER) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
