SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g -I$(INC) -c


#***************************** RUTAS_AEREAS *************************

$(BIN)/rutas_aereas : $(OBJ)/rutas_aereas.o $(OBJ)/imagen.o $(OBJ)/almacen_rutas.o \
						 $(OBJ)/Ruta.o $(OBJ)/Punto.o $(OBJ)/imagenES.o
	@echo Creando el ejecutable
	$(CXX) $^ -o $@  

$(OBJ)/rutas_aereas.o : $(SRC)/rutas_aereas.cpp 
	@echo Creando rutas_aereas.o
	$(CXX) $(CPPFLAGS) $< -o $@ -I$(INC)

#******************************* IMAGEN *****************************

$(OBJ)/imagen.o : $(SRC)/imagen.cpp $(OBJ)/imagenES.o  
	@echo Creando imagen.o
	$(CXX) $(CPPFLAGS) $< -o $@ -I$(INC)

$(OBJ)/imagenES.o : $(SRC)/imagenES.cpp 
	@echo Creando imagenES.o
	$(CXX) $(CPPFLAGS) $< -o $@ -I$(INC)	

	
#******************************* RUTA ********************************

$(OBJ)/Ruta.o : $(SRC)/Ruta.cpp $(OBJ)/Punto.o  
	@echo Creando Ruta.o
	$(CXX) $(CPPFLAGS) $< -o $@ -I$(INC)

$(OBJ)/almacen_rutas.o : $(SRC)/almacen_rutas.cpp $(OBJ)/Ruta.o 
	@echo Creando almacen_rutas.o
	$(CXX) $(CPPFLAGS) $< -o $@ -I$(INC)

#******************************* PUNTO *******************************
	
$(OBJ)/Punto.o : $(SRC)/Punto.cpp
	@echo Creando Punto.o
	$(CXX) $(CPPFLAGS) $< -o $@ -I$(INC)


# ****************** Generación de documentación *********************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
