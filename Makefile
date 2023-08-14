# Compiler for C files
CC = clang

# Compiler for C++ files
CXX = clang++

# Compiler flags
CFLAGS = -Wall -Wextra

# C++ flags
CXXFLAGS = -Wall -Wextra

# Linker flags
LDFLAGS = -lstdc++

# Source and build directories
SRC_DIR = src
BUILD_DIR = build

# Find all C and C++ source files
C_SRC = $(wildcard $(SRC_DIR)/*.c)
CPP_SRC = $(wildcard $(SRC_DIR)/*.cpp)

# Create object file names from source file names
C_OBJ = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(C_SRC))
CPP_OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(CPP_SRC))

# Output executable
TARGET = $(BUILD_DIR)/shellb

# Make sure the build directory exists
$(shell mkdir -p $(BUILD_DIR))

# Compile C source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile C++ source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build the final executable
$(TARGET): $(C_OBJ) $(CPP_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

.PHONY: clean run

clean:
	rm -rf $(BUILD_DIR)

run: $(TARGET)
	./$(TARGET)
