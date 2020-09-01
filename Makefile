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

NAME        = libasm.a

SRCS        = $(shell find . -type f -name 'ft_*.s')
SRCS_BONUS  = $(shell find . -type f -name 'ft_*_bonus.s')

OBJS        = $(SRCS:.s=.o)
OBJS_BONUS  = $(SRCS:.s=.o)

.PHONY: all clean bonus fclean test


all:        $(NAME)

$(NAME):    $(OBJS)
	ar rcs $(NAME) ${OBJS}

bonus:      $(OBJS_BONUS)
            ar -rc $(NAME) $(OBJS_BONUS)

test:       $(NAME)
	gcc -Wall -Wextra -Werror -L. -lasm main.c -o test

%.o:        %.s
	nasm -f macho64 $<

clean:
	rm -f *.o

fclean:     clean
	rm -f $(NAME)

re:         fclean all
