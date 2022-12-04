#include "iri.cpp"
#include <iostream>
#include "funciones.h"
#include "string"

int main() {
	fstream file; //object of fstream class

	//open file "test.txt" in out(write) mode
	// ios::out Open for output operations.
	file.open("test.txt", ios::out);

	int contador = 0;
	int* p = &contador;
	int contador2 = 0;
	int contador3 = 0;
	int contador4 = 0;
	int contador5 = 0;
	int contador6 = 0;
	int contador7 = 0;

	Pacientes* lista;
	lista = read_archivo_pacientes("Pacientes.csv", &contador);//con & transformo la variable en un puntero

	Consultas* lista1;
	lista1 = read_archivo_consultas("Consultas.csv", &contador2);

	Medicos* lista2;
	lista2 = read_archivo_medicos("Medicos.csv", &contador3);

	Contactos* lista3;
	lista3 = read_archivo_contactos("Contactos.csv", &contador4);

	Consultas* lista_cons;
	Contactos* lista_filtrada_contactos;
	Medicos* medico_nueva_consulta;
	Medicos* medico_nueva_consulta_nuevo;

	//los contador restan 1 porque sino imprime el ultimo 2 veces, ver si es solucion optima o no

	LLamado_Secretaria(lista, lista1, lista3, lista2, &contador, &contador2, &contador4, &contador3);

}
