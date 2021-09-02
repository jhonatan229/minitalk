SERVER = server
CLIENT = client
UTILS = ./utils.c
FILES_S = ./server.c
FILES_C = ./client.c

OBJ_UTILS = $(UTILS:.c=.o)
OBJ_SERVER = $(FILES_S:.c=.o)
OBJ_CLIENT = $(FILES_C:.c=.o)

all: $(SERVER) $(CLIENT)
bonus: all

CC = clang
CFLAGS = -Wall -Wextra -Werror

$(SERVER): $(OBJ_UTILS) $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_UTILS) $(OBJ_SERVER) -o $(SERVER)

$(CLIENT): $(OBJ_UTILS) $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_UTILS) $(OBJ_CLIENT) -o $(CLIENT)

clean:
	rm -rf $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_UTILS)

fclean: clean
	rm -rf $(SERVER) $(CLIENT)

re: fclean all