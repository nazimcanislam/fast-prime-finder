BIN_FOLDER=bin
SOURCE_FOLDER=src
INCLUDE_FOLDER=include
PROGRAM_NAME=fastprimefinder
MKDIR=mkdir $(BIN_FOLDER)

ifeq ($(OS),Windows_NT)
	CC = mingw32-gcc
	RM = del 
	C_FLAGS = -lm -pthread
	RMDIR=if exist $(BIN_FOLDER) rd /s /q $(BIN_FOLDER)
else
	CC = gcc
	C_FLAGS = -lm
	RM = rm -rf
	RMDIR=rm -rf $(BIN_FOLDER)
endif


debug:
	$(RMDIR)
	$(MKDIR)
	$(CC) -Wall -g -o $(BIN_FOLDER)/$(PROGRAM_NAME) $(SOURCE_FOLDER)/*.c -I $(INCLUDE_FOLDER) $(C_FLAGS)

release:
	$(RMDIR)
	$(MKDIR)
	$(CC) -w -o3 -o $(BIN_FOLDER)/$(PROGRAM_NAME) $(SOURCE_FOLDER)/*.c -I $(INCLUDE_FOLDER) $(C_FLAGS)
