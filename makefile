CC := gcc
CFLAGS := -Wall -Wextra -Isrc/ -g
BIN := bin

BUILD_DIR := build
SRC_DIR := src

SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o,$(SRC))

.PHONY: all clean

all: $(BUILD_DIR) $(OBJ) $(BUILD_DIR)/$(BIN)

$(BUILD_DIR)/$(BIN): $(OBJ)
				$(CC) -o $(BUILD_DIR)/$(BIN) $(CFLAGS) $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
				$(CC) -o $@ $(CFLAGS) -c $<

$(BUILD_DIR):
				mkdir -p $(BUILD_DIR)

clean:
				rm -rf build
