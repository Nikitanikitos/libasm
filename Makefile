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
TEST		= test

SRCS        = $(shell find . -type f -name 'ft_*.s' -not -name 'ft_*bonus.s')
SRCS_BONUS  = $(shell find . -type f -name 'ft_*_bonus.s')

OBJS        = $(SRCS:.s=.o)
OBJS_BONUS  = $(SRCS_BONUS:.s=.o)

.PHONY: all clean bonus fclean test

all:        $(NAME)

$(NAME):    $(OBJS)
	ar rcs $(NAME) ${OBJS}

bonus:      $(NAME) $(OBJS_BONUS)
	ar -rc $(NAME) $(OBJS_BONUS)

%.o:        %.s
	nasm -f macho64 $<

clean:
	rm -f *.o

fclean:     clean
	rm -f $(NAME)

re:         fclean all
