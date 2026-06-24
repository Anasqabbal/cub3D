# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 18:28:40 by anqabbal          #+#    #+#              #
#    Updated: 2024/11/01 11:13:43 by anqabbal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

FLAGS = -Wall -Wextra -Werror 

FILES = ft_isalpha.c ft_isdigit.c \
		ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_strlen.c \
		ft_memset.c ft_bzero.c \
		ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c \
		ft_toupper.c ft_tolower.c \
		ft_strchr.c ft_strrchr.c \
		ft_strncmp.c ft_memchr.c \
		ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c \
		ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c \
		ft_split.c ft_itoa.c ft_split1.c\
		ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c\
		ft_lstnew_bonus.c ft_lstsize_bonus.c \
		ft_lstlast_bonus.c ft_lstadd_front_bonus.c \
		ft_lstadd_back_bonus.c  ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c\
		get_next_line_bonus.c get_next_line_utils_bonus.c garbege.c

OBJF  = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJF)
	@ar rc $@ $^

%.o: %.c libft.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJF) $(OBJB)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean