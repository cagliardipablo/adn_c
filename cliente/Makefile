SRCS = client.c

DEBUG = -g

CC = cc

all: cliente
	@echo "Ejecute: ./client servidor puerto"

cliente: $(SRCS)
	$(CC) -o client $(SRCS)

debug: $(SRCS)
	$(CC) $(DEBUG) -o client $(SRCS)

clean:
	rm -f client
