# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imicah <imicah@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/27 12:05:48 by imicah            #+#    #+#              #
#    Updated: 2020/08/28 11:11:04 by imicah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libasm.a

SRCS    = $(shell find . -type f -name 'ft_*.s')

OBJS    = $(SRCS:.s=.o)


all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) ${OBJS}

test: $(NAME)
	gcc -Wall -Wextra -Werror -no-pie main.c -I. -L. -lasm -o test

%.o:%.s
	nasm -felf64 $<

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
