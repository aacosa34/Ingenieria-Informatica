BIN = ./bin
OBJ = ./obj
SRC = ./src
INC = ./inc
LIB = ./lib

$(BIN)/pruebaPila_max : $(OBJ)/pruebaPila_max.o
	@echo Creando el ejecutable.
	g++ -o $@ $<  

$(OBJ)/pruebaPila_max.o : $(SRC)/pruebaPila_max.cpp $(INC)/Pila_max.h
	@echo Creando pruebaPila_max.o
	g++ -g -c $< -o $@ -I$(INC)

clean :
	@echo Limpiando.
	-rm $(OBJ)/* $(BIN)/*

rebuild : clean $(BIN)/main