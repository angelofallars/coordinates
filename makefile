PROG   = coordinate
CC     = gcc
CFLAGS = -Wall -Werror

all: $(PROG)

$(PROG): $(PROG).c
	$(CC) $(CFLAGS) $< -o $(PROG)

clean:
	rm -rf $(PROG)
