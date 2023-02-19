# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elisa <elisa@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/11 17:30:55 by elisa             #+#    #+#              #
#    Updated: 2023/02/18 14:23:18 by elisa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server
NAME_CLIENT_BONUS = client_bonus
NAME_SERVER_BONUS = server_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS_CLIENT = client.c
SRCS_SERVER = server.c
SRCS = utils.c 

SRCS_CLIENT_BONUS = bonus/client.c
SRCS_SERVER_BONUS = bonus/server.c
SRCS_BONUS = bonus/utils.c 

OBJS = $(SRCS:.c=.o)
OBJS_C = $(SRCS_CLIENT:.c=.o)
OBJS_S = $(SRCS_SERVER:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)
OBJS_C_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)
OBJS_S_BONUS = $(SRCS_SERVER_BONUS:.c=.o)

#rules
	
all: client server

client: ${OBJS_C} ${OBJS}
		${CC} ${CFLAGS} ${OBJS_C} ${OBJS} -o ${NAME_CLIENT}

server: ${OBJS_S} ${OBJS}
		${CC} ${CFLAGS} ${OBJS_S} ${OBJS} -o ${NAME_SERVER}

bonus : client_bonus server_bonus

client_bonus: ${OBJS_C_BONUS} ${OBJS_BONUS}
		${CC} ${CFLAGS} ${OBJS_C_BONUS} ${OBJS_BONUS} -o ${NAME_CLIENT_BONUS}

server_bonus: ${OBJS_S_BONUS} ${OBJS_BONUS}
		${CC} ${CFLAGS} ${OBJS_S_BONUS} ${OBJS_BONUS} -o ${NAME_SERVER_BONUS}

clean:
		${RM} ${OBJS} ${OBJS_C} ${OBJS_S}

fclean: clean
		${RM} ${NAME_CLIENT} ${NAME_SERVER}
