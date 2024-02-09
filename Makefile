CC = gcc

BIN_FOLDER=bin
SOURCE_FOLDER=src
INCLUDE_FOLDER=include
PROGRAM_NAME=fastprimefinder

ifeq ($(OS),Windows_NT)
	C_FLAGS = -lm -pthread
else
	C_FLAGS = -lm
endif

all: debug release

debug:
	$(CC) -Wall -g -o $(BIN_FOLDER)/$(PROGRAM_NAME) $(SOURCE_FOLDER)/*.c -I $(INCLUDE_FOLDER) $(C_FLAGS)

release:
	$(CC) -w -o3 -o $(BIN_FOLDER)/$(PROGRAM_NAME) $(SOURCE_FOLDER)/*.c -I $(INCLUDE_FOLDER) $(C_FLAGS)
