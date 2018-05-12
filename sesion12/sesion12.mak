###############################################################
###                                                         ###
###  Autor : Antonio David Villegas Yeguas                  ###
###  1GII - Universidad de Granada                          ###
###  Metodologia de la Programacion 2017/18                 ###
###  Makefile sesion 12                                     ###
###                                                         ###
###############################################################

HOME = .
SRC = $(HOME)/src
INCLUDE = $(HOME)/include
BIN = $(HOME)/bin
OBJ = $(HOME)/obj
LIB = $(HOME)/lib

all : inicio \
		$(BIN)/NumeraLineas \
		$(BIN)/MezclaFichero \
		$(BIN)/VI_Demo-Lista-ES \
		finalizado

################################################################################


$(BIN)/NumeraLineas : $(OBJ)/NumeraLineas.o $(OBJ)/Util.o
	g++ -o $(BIN)/NumeraLineas $(OBJ)/NumeraLineas.o $(OBJ)/Util.o

$(OBJ)/NumeraLineas.o : $(SRC)/NumeraLineas.cpp $(INCLUDE)/Util.h
	g++ -c -o $(OBJ)/NumeraLineas.o $(SRC)/NumeraLineas.cpp \
	       -I$(INCLUDE) -std=c++11

$(OBJ)/Util.o : $(SRC)/Util.cpp $(INCLUDE)/Util.h
	g++ -c -o $(OBJ)/Util.o $(SRC)/Util.cpp -I$(INCLUDE) -std=c++11



################################################################################

$(BIN)/MezclaFichero : $(OBJ)/MezclaFichero.o $(OBJ)/Util.o
	g++ -o $(BIN)/MezclaFichero $(OBJ)/MezclaFichero.o $(OBJ)/Util.o

$(OBJ)/MezclaFichero.o : $(SRC)/MezclaFichero.cpp $(INCLUDE)/Util.h
	g++ -c -o $(OBJ)/MezclaFichero.o $(SRC)/MezclaFichero.cpp \
	        -I$(INCLUDE) -std=c++11



################################################################################

$(BIN)/VI_Demo-Lista-ES : $(OBJ)/VI_Demo-Lista-ES.o $(OBJ)/Lista.o $(OBJ)/Util.o
	g++ -o $(BIN)/VI_Demo-Lista-ES $(OBJ)/VI_Demo-Lista-ES.o $(OBJ)/Lista.o \
	       $(OBJ)/Util.o

$(OBJ)/VI_Demo-Lista-ES.o : $(SRC)/VI_Demo-Lista-ES.cpp $(INCLUDE)/Lista.h
	g++ -c -o $(OBJ)/VI_Demo-Lista-ES.o $(SRC)/VI_Demo-Lista-ES.cpp \
	       -I$(INCLUDE) -std=c++11

$(OBJ)/Lista.o : $(SRC)/Lista.cpp $(INCLUDE)/Lista.h $(INCLUDE)/Util.h \
                 $(INCLUDE)/TipoBase.h
	g++ -c -o $(OBJ)/Lista.o $(SRC)/Lista.cpp -I$(INCLUDE) -std=c++11


################################################################################



inicio :
	@echo 
	@echo 	"/************************************************************/"
	@echo 	"/**                                                        **/"
	@echo 	"/**  Autor : Antonio David Villegas Yeguas                 **/"
	@echo 	"/**  1GII - Universidad de Granada                         **/"
	@echo 	"/**  Metodologia de la Programacion 2017/18                **/"
	@echo 	"/**  Makefile sesion 12                                    **/"
	@echo 	"/**                                                        **/"
	@echo 	"/************************************************************/"
	@echo 



finalizado :
	@echo 
	@echo  "/****************************************************************/"
	@echo  "/**                                                            **/"
	@echo  "/**     Todas las acciones se han realizado correctamente      **/"
	@echo  "/**                                                            **/"
	@echo  "/****************************************************************/"

################################################################################

clean :
	-rm $(OBJ)/*

mr.proper : clean
	-rm $(BIN)/*
	-rm $(LIB)/*