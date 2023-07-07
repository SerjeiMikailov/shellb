CC = clang
CFLAGS = -Wall -Wextra -pedantic-errors -Werror
LDFLAGS =

SRC_DIR = src
OUTPUT_DIR = build

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OUTPUT_DIR)/%.o,$(SRCS))

all: $(OUTPUT_DIR)/main

$(OUTPUT_DIR)/main: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

$(OUTPUT_DIR)/%.o: $(SRC_DIR)/%.c $(SRC_DIR)/App.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OUTPUT_DIR)/main $(OUTPUT_DIR)/*.o

run: $(OUTPUT_DIR)/main
	./$(OUTPUT_DIR)/main
