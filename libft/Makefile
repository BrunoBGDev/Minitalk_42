# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbraga <bruno.braga.design@gmail.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 08:46:58 by bbraga            #+#    #+#              #
#    Updated: 2022/08/02 10:18:21 by bbraga           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_utils.c ft_utils2.c \
	   ft_isalnum.c ft_isalpha.c ft_isascii.c ft_ptr.c \
	   ft_isdigit.c ft_isprint.c ft_itoa.c ft_unsigned.c \
	   ft_memchr.c ft_memcmp.c ft_memcpy.c ft_split.c \
	   ft_memmove.c ft_memset.c ft_putchar_fd.c ft_printf.c  \
	   ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_itoa_printf.c \
	   ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
	   ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
	   ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_hex_format.c \
	   ft_substr.c ft_tolower.c ft_toupper.c ft_strtrim.c\

SRC_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \

NAME = libft.a
OBJS_DIR = ./

OBJS = $(SRCS:.c=.o)
 
BONUS = $(SRC_BONUS:.c=.o)

CC = cc
 
CC_FLAGS = -Wall -Wextra -Werror
 
$(OBJS_DIR)%.o : %.c libft.h ft_printf.h
	@cc $(CC_FLAGS) -c $< -o $@
	@echo "Compiling (all .c to .o)"
$(NAME): $(OBJS)
	@echo "Creating lib..."
	@ar r $(NAME) $(OBJS)
all: $(NAME)

clean:
	@rm -rf $(OBJS) $(BONUS)
	@echo "Deleting (.o)"
fclean: clean
	@rm -f $(NAME)
	@echo "Deleting (.o and .a)"
re: fclean all

bonus: $(BONUS)
	ar r $(NAME) $(BONUS)

.PHONY: all clean fclean re
