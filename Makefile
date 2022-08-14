# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/14 11:31:51 by mgaspar-          #+#    #+#              #
#    Updated: 2022/08/14 16:47:56 by mgaspar-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -MMD
SRC_s = server.c
SRC_c = client.c
SERVERNAME = server
CLIENTNAME = client
OBJS_s = ${SRC_s:.c=.o}
OBJS_c = ${SRC_c:.c=.o}
INCLUDES = -I ./libft
LDPATH = -L libft
LDLIB = -lft
DEPS_s = ${SRC_s:.c=.d}
DEPS_c = ${SRC_c:.c=.d}

%.o : %.c
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

all : makelibs ${SERVERNAME}  ${CLIENTNAME}

-include ${DEPS_s}
${SERVERNAME}: ${OBJS_s} ./libft/libft.a
	${CC} ${CFLAGS} ${LDPATH} ${LDLIB} ${OBJS_s} -o $@

-include ${DEPS_c}
${CLIENTNAME} : ${OBJS_c} ./libft/libft.a
	${CC} ${CFLAGS} ${LDPATH} ${LDLIB} ${OBJS_c} -o $@
makelibs :
	${MAKE} -C ./libft
clean :
	${MAKE} clean -C ./libft
	${RM} ${OBJS_s} ${OBJS_c} ${DEPS_s} ${DEPS_c}
fclean : clean
	${MAKE} fclean -C ./libft
	${RM} ${SERVERNAME} ${CLIENTNAME}
re : fclean all
.PHONY: all clean fclean
