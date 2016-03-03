SRC = $(wildcard src/*.c)
LIB = $(wildcard lib/*.c)

OBJ = $(patsubst %.c,%.o,$(notdir $(SRC) $(LIB)))

TARGET = my_ls

CC = gcc
CFLAGS = -g -Wall -Werror -std=c89
INC = -Ilib

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) -lm

$(OBJ): $(SRC) $(LIB)
	$(CC) $(INC) $(CFLAGS) -c $(SRC) $(LIB)

clean:
	-rm $(OBJ)

fclean: clean
	-rm $(TARGET)

re: fclean all

test: $(TARGET)
	./$(TARGET)
