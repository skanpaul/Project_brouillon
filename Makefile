# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ski <ski@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 11:37:50 by ski               #+#    #+#              #
#    Updated: 2022/04/15 13:54:48 by ski              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1	= minishell
NAME2	= main

CC		= gcc
CFLAG	= -Wall -Wextra -Werror

RM		= rm -f

HD1		= main.h
SRC1	= 	minishell.c\
			initialisation.c\
			signal_handler.c\
			fork_utils.c
			
OBJ1	= $(SRC1:.c=.o)

HD2		= main.h
SRC2	= main.c
OBJ2	= $(SRC2:.c=.o)

# **************************************************************************** #
all: $(NAME1) $(NAME2)

$(NAME1): $(OBJ1) $(HD1)
	$(CC) $(CFLAG) $(OBJ1) -lreadline -o $(NAME1)

$(NAME2): $(OBJ2) $(HD2)
	$(CC) $(CFLAG2) $(OBJ2) -lreadline -o $(NAME2)

clean:
	$(RM) $(OBJ1)
	$(RM) $(OBJ2)
	
fclean: clean
	$(RM) $(NAME1)
	$(RM) $(NAME2)

re: fclean all

r:
	./$(NAME)

# **************************************************************************** #