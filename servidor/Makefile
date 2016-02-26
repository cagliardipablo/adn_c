SRCS = server.c

DEBUG = -g

CC = gcc 

all: server
	@echo "Ejecute ./server puerto"

server: $(SRCS)
	$(CC) -o server $(SRCS)

debug: $(SRCS)
	$(CC) $(DEBUG) -o server $(SRCS)

clean:
	rm -f server
