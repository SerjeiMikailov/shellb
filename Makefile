CC = clang
CFLAGS = -Wall -Wextra -pedantic-errors -Werror
LDFLAGS =

SRC_DIR = src
OUTPUT_DIR = build

all: $(OUTPUT_DIR)/main

$(OUTPUT_DIR)/main: $(OUTPUT_DIR)/main.o $(OUTPUT_DIR)/remove_dir.o
	$(CC) $(LDFLAGS) -o $@ $^

$(OUTPUT_DIR)/main.o: $(SRC_DIR)/main.c $(SRC_DIR)/App.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OUTPUT_DIR)/remove_dir.o: $(SRC_DIR)/remove_dir.c $(SRC_DIR)/App.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OUTPUT_DIR)/main $(OUTPUT_DIR)/*.o

run: $(OUTPUT_DIR)/main
	./$(OUTPUT_DIR)/main
