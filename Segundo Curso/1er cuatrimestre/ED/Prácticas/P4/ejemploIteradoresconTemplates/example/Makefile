BIN = bin
SRC = src
INC = inc
OBJ = obj

$(BIN)/main: $(OBJ)/main.o
	echo Creando el ejecutable.
	g++ $< -o $@

$(OBJ)/main.o: $(SRC)/main.cpp $(SRC)/Collection.cpp $(INC)/Collection.h
	echo Creando main.o
	g++ -g -c -Wall -I./$(INC) -I./$(SRC) $< -o $@

clean:
	-rm $(OBJ)/* $(BIN)/*
