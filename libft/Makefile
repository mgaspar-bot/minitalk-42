# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 18:05:02 by mgaspar-          #+#    #+#              #
#    Updated: 2022/08/15 09:39:42 by mgaspar-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
 ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
 ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_strdup.c ft_substr.c ft_strjoin.c \
 ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRCSBONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
 ft_lstmap.c
OBJS = ${SRCS:.c=.o}
OBJSBONUS = ${SRCSBONUS:.c=.o}
NAME = libft.a
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -MMD
DEPS = ${SRCS:.c=.d}
DEPSBONUS = ${SRCBONUS:.c=.d}

%.o: %.c
	${CC} ${CFLAGS} -I ./ -c $< -o $@

all: 		${NAME} 
-include ${DEPS}
${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}
			ranlib ${NAME}
-include ${DEPSBONUS}
bonus:		${OBJS} ${OBJSBONUS}
			ar rcs ${NAME} ${OBJS} ${OBJSBONUS}
			ranlib ${NAME}
			touch $@
#el touch es per evitar el relink, 
clean: 		
			${RM} ${OBJS} ${OBJSBONUS} ${DEPS} ${DEPSBONUS}
			${RM} bonus
fclean: 	clean
			${RM} ${NAME}
re:			fclean 
			${MAKE}
.PHONY: all clean fclean re
