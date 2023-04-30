BIN_FOLDER=bin
SOURCE_FOLDER=src
INCLUDE_FOLDER=include
PROGRAM_NAME=fastprimefinder

compile:
	rm -rf $(BIN_FOLDER)
	mkdir $(BIN_FOLDER)
	gcc -w -o3 -o $(BIN_FOLDER)/$(PROGRAM_NAME) $(SOURCE_FOLDER)/*.c -I $(INCLUDE_FOLDER) -lm
