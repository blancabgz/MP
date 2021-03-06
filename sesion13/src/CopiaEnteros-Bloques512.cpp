/*************************************************************/
/**                                                         **/
/**  Autor : Antonio David Villegas Yeguas                  **/
/**  1GII - Universidad de Granada                          **/
/**  Metodologia de la Programacion 2017/18                 **/
/**  Sesion 13 - Ejercicio 2 - CopiaEnteros                 **/
/**                                                         **/
/*************************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
#include "Util.h"

using namespace std;

int main(int argc, char * argv[]){

	if (argc != 3){
		cerr << "ERROR: Numero de argumentos erroneo" << endl
			  << "Uso: " << argv[0] << " <fichero_original> <fichero_destino> "
		     << endl;
		exit(1);
	}

	if (!ExisteFichero(argv[1])){
		cerr << "ERROR: No se puede leer " << argv[1] << endl;
		exit (1);
	}

	if (ExisteFichero(argv[2])){
		char confirmacion;

		cout << "ATENCION: Se borrara el contenido de " << argv[2]
		     << " ¿desea continuar? [S/N] ";
		cin >> confirmacion;

		if (confirmacion != 'S')
			exit(1);
	}

	const int TAM_ENTERO = sizeof(int);
	const int TAM_BLOQUE = 512;

	const int TAM_BUFFER = TAM_BLOQUE / TAM_ENTERO;

	int buffer [TAM_BUFFER];
	int leidos = 0;;


	ifstream fi;
	ofstream fo;

	fi.open (argv[1]);
	fo.open (argv[2], ios::binary);

	while ( !fi.eof() ){
		fi >> buffer[leidos];

		leidos++;

		if(leidos == TAM_BUFFER){
			fo.write ( (char *) buffer, TAM_BLOQUE );

			leidos = 0;
		}
	}

	fo.write ( (char *) buffer, leidos * TAM_ENTERO );
	
	
	fi.close();
	fo.close();

	return 0;
}