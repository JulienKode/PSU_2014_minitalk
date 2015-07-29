##
## Makefile for  in /home/karst_j/Epitech/2014-2015/SysUnix/PSU_2014_minitalk
##
## Made by Julien Karst
## Login   <karst_j@epitech.net>
##
## Started on  Wed Feb 25 09:27:46 2015 Julien Karst
## Last update Sun Mar 22 11:58:53 2015 Julien Karst
##

CC		= gcc

RM		= rm -f

CLIENT		= client/client

SERVER		= server/server

CFLAGS		= -I./include -g

LDFLAGS		= -L./lib -lmy

SRCC	=	src/client.c \
		src/client2.c

SRCS	=	src/server.c \
		src/server2.c \

OBJC	=	$(SRCC:.c=.o)

OBJS	=	$(SRCS:.c=.o)

all:		$(CLIENT) $(SERVER)

$(CLIENT):	$(OBJC)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJC) $(LDFLAGS)

$(SERVER):	$(OBJS)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJC) $(OBJS)

fclean:	clean
	$(RM) $(CLIENT) $(SERVER)

re:	fclean all

.PHONY: all clean fclean re
