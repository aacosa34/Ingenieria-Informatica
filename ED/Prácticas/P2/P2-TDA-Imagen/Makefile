BIN = ./bin
OBJ = ./obj
SRC = ./src
INC = ./inc

$(BIN)/pruebaimagen : $(OBJ)/pruebaimagen.o $(OBJ)/imagen.o $(OBJ)/imagenES.o
	@echo Creando el ejecutable.
	g++ $^ -o $@

$(OBJ)/pruebaimagen.o : $(SRC)/pruebaimagen.cpp
	@echo Creando pruebaimagen.o
	g++ -g -c -I$(INC) $< -o $@

$(OBJ)/imagen.o : $(SRC)/imagen.cpp $(INC)/imagen.h $(OBJ)/imagenES.o
	@echo Creando imagen.o
	g++ -g -c -I$(INC) $< -o $@

$(OBJ)/imagenES.o : $(SRC)/imagenES.cpp $(INC)/imagenES.h
	@echo Creando imagenES.o
	g++ -g -c -I$(INC) $< -o $@

clean :
	@echo Limpiando.
	-rm $(OBJ)/* $(BIN)/*

rebuild : clean $(BIN)/main
