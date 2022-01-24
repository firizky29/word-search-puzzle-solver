CC = g++

BIN_DIR := ./bin
SRC_DIR := ./src
TEST_DIR := ./test
TARGET := $(BIN_DIR)/WordSearchPuzzle

CFLAG = -Wall -std=c++14
BUILD_FLAG = -lm

SRCS := $(shell find src -name *.cpp ! -name "main.cpp" ! -name "driver_*.cpp")
OBJS := $(patsubst %.cpp,$(BIN_DIR)/%.o,$(SRCS))


$(BUILD_DIR)/src/%.o $(BIN_DIR)/%.o: ./src/%.cpp
	@mkdir -p $(dir $@)
	@$(CC) -g $(CFLAG) -c $< -o $@

$(TARGET): $(OBJS) $(BIN_DIR)/main.o
	@mkdir -p bin
	@$(CC) $^ -o $@ -O3

build: $(OBJS) $(BIN_DIR)/main.o
	@mkdir -p bin
	@$(CC) -g  $^ -o $(TARGET)

run: build
	@$(TARGET)

clear:
	@rm -rf bin/main.o

all : build clear

.PHONY : clear all build run