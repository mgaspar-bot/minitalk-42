# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/14 11:31:51 by mgaspar-          #+#    #+#              #
#    Updated: 2023/09/09 19:03:44 by mgaspar-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -MMD
SRC_s = server.c
SRC_c = client.c
SRC_u = utils.c
SERVERNAME = server
CLIENTNAME = client
OBJS_s = ${SRC_s:.c=.o}
OBJS_c = ${SRC_c:.c=.o}
OBJS_u = ${SRC_u:.c=.o}
DEPS_s = ${SRC_s:.c=.d}
DEPS_c = ${SRC_c:.c=.d}
DEPS_u = ${SRC_u:.c=.d}

%.o : %.c
	${CC} -g ${CFLAGS} -c $< -o $@

all : ${SERVERNAME} ${CLIENTNAME}

-include ${DEPS_s} ${DEPS_u}
${SERVERNAME}: ${OBJS_s} ${OBJS_u}
	${CC} ${CFLAGS} -g ${OBJS_s} ${OBJS_u} -o $@

-include ${DEPS_c} ${DEPS_u}
${CLIENTNAME} : ${OBJS_c} ${OBJS_u}
	${CC} ${CFLAGS} -g ${OBJS_c} ${OBJS_u} -o $@

clean :
	${RM} ${OBJS_s} ${OBJS_c} ${OBJS_u} ${DEPS_s} ${DEPS_c} ${DEPS_u}

fclean : clean
	${RM} ${SERVERNAME} ${CLIENTNAME}

re : fclean all

.PHONY: all clean fclean
