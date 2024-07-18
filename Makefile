CNAME = client
SNAME = server
BCNAME = client_bonus
BSNAME = server_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS = client.c \
       server.c
BONUS_SRC = client_bonus.c \
            server_bonus.c
OBJS = $(SRCS:.c=.o)
BOBJS = $(BONUS_SRC:.c=.o)

all: $(CNAME) $(SNAME)

$(CNAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(CNAME) client.o

$(SNAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(SNAME) server.o

$(BCNAME): $(BOBJS)
	$(CC) $(CFLAGS) -o $(BCNAME) client_bonus.o

$(BSNAME): $(BOBJS)
	$(CC) $(CFLAGS) -o $(BSNAME) server_bonus.o

bonus: $(BCNAME) $(BSNAME)

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(CNAME) $(SNAME) $(BCNAME) $(BSNAME)

re: fclean all
