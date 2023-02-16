# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elisa <elisa@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/11 17:30:55 by elisa             #+#    #+#              #
#    Updated: 2023/02/16 16:53:57 by elisa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS_CLIENT = client.c
SRCS_SERVER = server.c
SRCS = utils.c 

OBJS = $(SRCS:.c=.o)
OBJS_C = $(SRCS_CLIENT:.c=.o)
OBJS_S = $(SRCS_SERVER:.c=.o)

#rules
	
all: client server

client: ${OBJS_C} ${OBJS}
		${CC} ${CFLAGS} ${OBJS_C} ${OBJS} -o ${NAME_CLIENT}

server: ${OBJS_S} ${OBJS}
		${CC} ${CFLAGS} ${OBJS_S} ${OBJS} -o ${NAME_SERVER}

clean:
		${RM} ${OBJS} ${OBJS_C} ${OBJS_S}

fclean: clean
		${RM} ${NAME_CLIENT} ${NAME_SERVER}
