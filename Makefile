# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 14:48:32 by jtomala           #+#    #+#              #
#    Updated: 2022/02/08 15:00:55 by jtomala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME = server
CLIENT_NAME = client
HEADER = minitalk.h
SRCS_SERVER = server.c
SRCS_CLIENT = client.c
OBJS_SERVER = ${SRCS_SERVER:.c=.o}
OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}
RM = rm -rf

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

all:	$(CLIENT_NAME) $(SERVER_NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(SERVER_NAME):	$(OBJS_SERVER)
	cd ft_printf && ${MAKE}
	$(CC) -o $(SERVER_NAME) $(CFLAGS) $(OBJS_SERVER) ./ft_printf/libftprintf.a

$(CLIENT_NAME):	$(OBJS_CLIENT)
	cd ft_printf && ${MAKE}
	$(CC) -o $(CLIENT_NAME) $(CFLAGS) $(OBJS_CLIENT) ./ft_printf/libftprintf.a

clean:
	cd ft_printf && ${MAKE} clean
	${RM} ${OBJS_SERVER} ${OBJS_CLIENT} ./ft_printf/libftprintf.a

fclean: clean
	${RM} $(CLIENT_NAME) $(SERVER_NAME)

re:	fclean all

.PHONY:
	all clean fclean re