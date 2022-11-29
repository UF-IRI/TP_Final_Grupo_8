#include "iri.cpp"
#include <iostream>
#include "funciones.h"


int main() {

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

	Secretaria(lista, lista1, lista3, lista2, &contador, &contador2, &contador4, &contador3);

	cout << "Imprimiento lista de consultas. " << endl;
	for (int i = 0; i < contador2 - 1; i++) {
		cout << lista1[i].dni_pac << "," << lista1[i].fecha_solicitado << "," << lista1[i].fecha_turno << "," << lista1[i].presento << "," << lista1[i].matricula_med << endl;
	}
	cout << "\n" << endl;

	cout << "Imprimiendo lista de medicos. " << endl;
	for (int i = 0; i < contador3 - 1; i++) {
		cout << lista2[i].matricula << "," << lista2[i].nombre << "," << lista2[i].apellido << "," << lista2[i].telefono << "," << lista2[i].especialidad << "," << lista2[i].activo << endl;
	}
	cout << "\n" << endl;

	cout << "Imprimiendo lista de contactos. " << endl;
	for (int i = 0; i < contador4 - 1; i++) {
		cout << lista3[i].dni_pac << "," << lista3[i].telefono << "," << lista3[i].celular << "," << lista3[i].direccion << "," << lista3[i].mail << endl;
	}
	cout << "\n" << endl;

}
