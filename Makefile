CC = clang
CXX = clang++
CFLAGS = -Wall -Wextra -pedantic-errors -Werror
CXXFLAGS = -Wall -Wextra -pedantic-errors -Werror
LDFLAGS = -lstdc++

SRC_DIR = src
OUTPUT_DIR = build
CREATE_FILE_DIR = $(OUTPUT_DIR)/create_file

C_SRCS = $(wildcard $(SRC_DIR)/*.c)
C_OBJS = $(patsubst $(SRC_DIR)/%.c,$(OUTPUT_DIR)/%.o,$(C_SRCS))

CPP_SRCS = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/create_file/*.cpp)
CPP_OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OUTPUT_DIR)/%.o,$(CPP_SRCS))

HEADERS = $(wildcard $(SRC_DIR)/*.h) $(wildcard $(SRC_DIR)/create_file/*.h) $(wildcard $(SRC_DIR)/*.hpp) $(wildcard $(SRC_DIR)/create_file/*.hpp)

all: $(OUTPUT_DIR)/shellb

$(OUTPUT_DIR)/shellb: $(C_OBJS) $(CPP_OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

$(OUTPUT_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(OUTPUT_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(shell mkdir -p $(OUTPUT_DIR) $(CREATE_FILE_DIR))

$(CREATE_FILE_DIR)/%.o: $(SRC_DIR)/create_file/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OUTPUT_DIR)/main $(OUTPUT_DIR)/*.o $(CREATE_FILE_DIR)/*.o

run: $(OUTPUT_DIR)/shellb
	./$(OUTPUT_DIR)/shellb
