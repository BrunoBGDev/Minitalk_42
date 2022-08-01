# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/01 11:13:14 by bbraga            #+#    #+#              #
#    Updated: 2022/08/01 11:17:56 by bbraga           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 

NAME = 
OBJS_DIR = 

OBJS = $(SRCS:.c=.o)
 
BONUS = $(SRC_BONUS:.c=.o)

CC = cc
 
CC_FLAGS = -Wall -Wextra -Werror
 
$(OBJS_DIR)%.o : %.c libft.h
	cc $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar r $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf $(OBJS) $(BONUS)
fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
