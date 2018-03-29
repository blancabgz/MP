/*************************************************************/
/**                                                         **/                                                         
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 6 - Ejercicio 4 - Vector dinámico de cadenas    **/
/**                                                         **/
/*************************************************************/

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

/*******************************************************************************/

char ** SepararCadena(string, int &);
int NumLineasVacias(char ** , int );
int NumParrafos (char ** , int );
bool LineaEnBlanco(char ** , int );

/*******************************************************************************/

int main(){
	string cadena;
	string cadena_completa = "";
	int num_lineas = 0;
	

	while (getline (cin,cadena)){
		cadena_completa = cadena_completa + cadena;
		cadena_completa.push_back('\n');
	}

	char ** v = SepararCadena(cadena_completa, num_lineas);
	
	
	cout << "El archivo tiene " << num_lineas
	     << " lineas de las cuales " << NumLineasVacias (v, num_lineas) 
	     << " estan vacias. " << endl << endl
		  << "El archivo esta compuesto por " << NumParrafos (v,num_lineas)
		  << " parrafos " << endl;


	delete [] v;

	return 0;
}

/*******************************************************************************/

char ** SepararCadena(string cadena, int & num_lineas){
	int tam_cadena_completa;
	int j = 0;

	tam_cadena_completa = cadena.size();

	for (int i = 0; i < tam_cadena_completa; i++){
		if (cadena[i] == '\n')	
			num_lineas++;
	}


	char ** cadenas = new char * [num_lineas];

	for (int i = 0; i < num_lineas; i++){
		string fila = "";

		while (cadena[j] != '\n'){
			fila = fila + cadena[j];
			j++;
		}
		j++;

		char * linea = new char [fila.size()];

		strcpy(linea, fila.c_str());

		cadenas[i] = linea;
	}

	return cadenas;
}

int NumLineasVacias(char ** documento, int num_lineas){
	int lineas_vacias;
	for (int i = 0; i < num_lineas;i++){
		if (documento[i][0] == '\0')
			lineas_vacias++;
	}
	return lineas_vacias;
}

int NumParrafos (char ** documento, int num_lineas){
	int num_parrafos = 0;
	bool mismo_parrafo = !LineaEnBlanco(documento, 0);

	for(int i = 0; i < num_lineas - 1 ; i++){
		if (mismo_parrafo){
			if ( LineaEnBlanco(documento, i + 1) ){
				num_parrafos++;
				mismo_parrafo = false;
			}
		}
		else{
			mismo_parrafo = !LineaEnBlanco(documento, i);
		}
	}
	return num_parrafos;
}

bool LineaEnBlanco(char ** documento, int num_linea){
	char * linea = documento[num_linea];

	bool linea_blanco = true;
	while ( *linea && linea_blanco){
		if ( !isspace ( *linea ) ){
			linea_blanco = false;
		}
		linea++;
	}

	return linea_blanco;
}