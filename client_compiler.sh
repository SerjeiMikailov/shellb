#!/bin/bash

# Compiler for C files
CC=clang

# Compiler for C++ files
CXX=clang++

# Compiler flags
CFLAGS="-Wall -Wextra"

# C++ flags
CXXFLAGS="-Wall -Wextra"

# Linker flags
LDFLAGS="-lstdc++"

# Source and build directories
SRC_DIR=src
CONFIG_DIR=config
BUILD_DIR=build

# Create the "build" directory if it doesn't exist
mkdir -p "$BUILD_DIR"

# Find all C and C++ source files
C_SRC=$(find "$SRC_DIR" -name "*.c")
CPP_SRC=$(find "$SRC_DIR" -name "*.cpp")

# Create object file names from source file names
C_OBJ=""
for src_file in $C_SRC; do
    obj_file="$BUILD_DIR/$(basename "$src_file" .c).o"
    C_OBJ="$C_OBJ $obj_file"
    $CC $CFLAGS -c "$src_file" -o "$obj_file"
done

CPP_OBJ=""
for src_file in $CPP_SRC; do
    obj_file="$BUILD_DIR/$(basename "$src_file" .cpp).o"
    CPP_OBJ="$CPP_OBJ $obj_file"
    $CXX $CXXFLAGS -c "$src_file" -o "$obj_file"
done

# Find all C source files in the "config" directory
CONFIG_C_SRC=$(find "$CONFIG_DIR" -name "*.c")

# Compile C source files in the "config" directory into object files
CONFIG_C_OBJ=""
for src_file in $CONFIG_C_SRC; do
    obj_file="$BUILD_DIR/$(basename "$src_file" .c).o"
    CONFIG_C_OBJ="$CONFIG_C_OBJ $obj_file"
    $CC $CFLAGS -c "$src_file" -o "$obj_file"
done

# Output executable
TARGET="$BUILD_DIR/shellb"

# Build the final executable
$CXX $CXXFLAGS $C_OBJ $CPP_OBJ $CONFIG_C_OBJ -o "$TARGET" $LDFLAGS
