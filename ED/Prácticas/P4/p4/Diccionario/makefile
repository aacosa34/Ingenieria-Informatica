BIN = bin
SRC = src
INC = include
OBJ = obj



$(BIN)/main: $(SRC)/pruebas_diccionario.cpp $(SRC)/Diccionario.cpp $(INC)/Diccionario.h
	echo Creando main.o
	g++ --std=c++11 -I./$(INC) -I./$(SRC)  $(SRC)/pruebas_diccionario.cpp $(SRC)/Diccionario.cpp $(INC)/Diccionario.h -o $@

clean:
	-rm $(OBJ)/* $(BIN)/*
