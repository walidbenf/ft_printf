# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wben-far <wben-far@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/09 15:35:09 by wben-far          #+#    #+#              #
#    Updated: 2021/02/09 15:35:16 by wben-far         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCDIR	= ./
OBJDIR	= ./
SRC		= ${SRCDIR}aff_prec.c\
		${SRCDIR}print_number.c\
		${SRCDIR}pointer.c\
		${SRCDIR}ft_printf.c\
		${SRCDIR}flags.c\
		${SRCDIR}width_prec.c\
		${SRCDIR}check_num.c\
		${SRCDIR}utils.c\
		${SRCDIR}parser.c\
		${SRCDIR}affichage.c\
		${SRCDIR}null.c\
	
	
			


OBJ		= ${patsubst ${SRCDIR}%.c, ${OBJDIR}%.o, ${SRC}}
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

${OBJDIR}%.o: ${SRCDIR}%.c
	${CC} ${CFLAGS} -c $< -o $@

$(NAME): ${OBJ}
	ar rc $(NAME) ${OBJ}
	ranlib ${NAME}

all:  $(NAME)

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf $(NAME)

re: fclean all
