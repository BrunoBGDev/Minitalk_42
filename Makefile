# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/01 11:13:14 by bbraga            #+#    #+#              #
#    Updated: 2022/08/01 11:42:23 by bbraga           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = server.c client.c

OBJS = $(SRCS:.c=.o)
 
CC = cc
 
CC_FLAGS = -Wall -Wextra -Werror

%.o: %.c
		$(CC) -c $(CFLAGS) $?

all: server client

client: client.o libft
		$(CC) -o $@ $< -Llibft -lft 

server: server.o libft
		$(CC) -o $@ $< -Llibft -lft

libft:
	make -C libft

clean:
	rm -rf $(OBJS)
	make -C libft clean
fclean: clean
		rm -f server client libft/libft.a

re: fclean all

.PHONY: all libft clean fclean re
