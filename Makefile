# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/01 11:13:14 by bbraga            #+#    #+#              #
#    Updated: 2022/08/24 10:33:39 by bbraga           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = server.c client.c

OBJS = $(SRCS:.c=.o)

NAME = minitalk

CLIENT = client

SERVER = server

LIBFT = libft/libft.a
 
CC = cc
 
CC_FLAGS = -Wall -Wextra -Werror

%.o: %.c
		$(CC) -c $(CFLAGS) $?

$(NAME): $(OBJS) $(SERVER) $(CLIENT)

all: $(NAME)

$(CLIENT): $(LIBFT)
		$(CC) -o client client.o -Llibft -lft 

$(SERVER): $(LIBFT)
		$(CC) -o server server.o -Llibft -lft

$(LIBFT):
	make -C libft

clean:
	rm -rf $(OBJS)
	make -C libft clean
fclean: clean
		rm -f server client libft/libft.a

re: fclean all

.PHONY: all libft clean fclean re
