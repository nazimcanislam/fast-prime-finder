CC = gcc

BIN_FOLDER=bin
SOURCE_FOLDER=src
INCLUDE_FOLDER=include
PROGRAM_NAME=fastprimefinder

all: debug release

debug: clean
	$(CC) -Wall -g -o $(BIN_FOLDER)/$(PROGRAM_NAME) $(SOURCE_FOLDER)/*.c -I $(INCLUDE_FOLDER) -lm

release: clean
	$(CC) -w -o3 -o $(BIN_FOLDER)/$(PROGRAM_NAME) $(SOURCE_FOLDER)/*.c -I $(INCLUDE_FOLDER) -lm

clean:
	rm -rf $(BIN_FOLDER)
	mkdir $(BIN_FOLDER)
