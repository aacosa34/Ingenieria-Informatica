BIN = ./bin
OBJ = ./obj
SRC = ./src
INC = ./inc
LIB = ./lib

$(BIN)/pruebaImagen : $(OBJ)/pruebaImagen.o $(LIB)/libImagen.a
	@echo Creando el ejecutable.
	g++ -o $@ $< -lImagen -L$(LIB) 

$(OBJ)/pruebaImagen.o : $(SRC)/pruebaImagen.cpp $(INC)/imagen.h $(INC)/imagenES.h
	@echo Creando pruebaImagen.o
	g++ -g -c $< -o $@ -I$(INC)

$(LIB)/libImagen.a : $(OBJ)/imagen.o $(OBJ)/imagenES.o
	@echo Creando la biblioteca libImagen.
	ar rvs $(LIB)/libImagen.a $^

$(OBJ)/imagen.o : $(SRC)/imagen.cpp $(INC)/imagen.h $(INC)/imagenES.h
	@echo Creando imagen.o
	g++ -g -c $< -o $@ -I$(INC)

$(OBJ)/imagenES.o : $(SRC)/imagenES.cpp $(INC)/imagenES.h
	@echo Creando imagenES.o
	g++ -g -c $< -o $@ -I$(INC) 

clean :
	@echo Limpiando.
	-rm $(OBJ)/* $(BIN)/*

rebuild : clean $(BIN)/main
