CC = clang
CXX = clang++
CFLAGS = -Wall -Wextra -pedantic-errors -Werror
CXXFLAGS = -Wall -Wextra -pedantic-errors -Werror
LDFLAGS = -lstdc++

SRC_DIR = src
OUTPUT_DIR = build
SHELL_SCRIPT_DIR = $(OUTPUT_DIR)/shell_script

C_SRCS = $(wildcard $(SRC_DIR)/*.c)
C_OBJS = $(patsubst $(SRC_DIR)/%.c,$(OUTPUT_DIR)/%.o,$(C_SRCS))

CPP_SRCS = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/shell_script/*.cpp)
CPP_OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OUTPUT_DIR)/%.o,$(CPP_SRCS))

HEADERS = $(wildcard $(SRC_DIR)/*.h) $(wildcard $(SRC_DIR)/shell_script/*.h) $(wildcard $(SRC_DIR)/*.hpp) $(wildcard $(SRC_DIR)/shell_script/*.hpp)

all: $(OUTPUT_DIR)/main

$(OUTPUT_DIR)/main: $(C_OBJS) $(CPP_OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

$(OUTPUT_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(OUTPUT_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create the output directory and shell_script directory if they don't exist
$(shell mkdir -p $(OUTPUT_DIR) $(SHELL_SCRIPT_DIR))

$(SHELL_SCRIPT_DIR)/%.o: $(SRC_DIR)/shell_script/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OUTPUT_DIR)/main $(OUTPUT_DIR)/*.o $(SHELL_SCRIPT_DIR)/*.o

run: $(OUTPUT_DIR)/main
	./$(OUTPUT_DIR)/main
