BIN = ./bin
OBJ = ./obj
SRC = ./src
INC = ./inc
LIB = ./lib

$(BIN)/pruebaPila_max : $(OBJ)/pruebaPila_max.o $(LIB)/libPila_max.a
	@echo Creando el ejecutable.
	g++ -o $@ $< -lPila_max -L$(LIB) 

$(OBJ)/pruebaPila_max.o : $(SRC)/pruebaPila_max.cpp $(INC)/Pila_max.h
	@echo Creando pruebaPila_max.o
	g++ -g -c $< -o $@ -I$(INC)

$(LIB)/libPila_max.a : $(OBJ)/Pila_max.o
	@echo Creando la biblioteca libPila_max.
	ar rvs $(LIB)/libPila_max.a $^

$(OBJ)/Pila_max.o : $(SRC)/Pila_max_VD.cpp $(SRC)/Pila_max_Cola.cpp $(INC)/Pila_max.h
	@echo Creando Pila_max.o
	g++ -g -c $< -o $@ -I$(INC) 

clean :
	@echo Limpiando.
	-rm $(OBJ)/* $(BIN)/*

rebuild : clean $(BIN)/main