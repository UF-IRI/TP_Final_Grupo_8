#include "iri.cpp"
#include <iostream>
#include "funciones.h"
#include "string"

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

	Pacientes* lista_archivados = NULL;
	int contador_archivados = 0;

	Pacientes* lista_nueva_verificados;
	lista_nueva_verificados = filtrar_verificacion_pacientes(lista, &contador, lista1, &contador2, lista3, &contador4, &contador5, lista_archivados, &contador_archivados);


	crear_archivo_nuevo_lista_verificados("Pacientes_Verificados_Secretaria.csv", lista_nueva_verificados, lista1, lista3, &contador5, &contador2, &contador4);

/*
	for (int i = 0; i < contador - 1; i++) {
		cout << "Paciente nro: " << i << endl;
		cout << lista[i].dni << "," << lista[i].nombre << "," << lista[i].apellido << "," << lista[i].sexo << "," << lista[i].natalicio << "," << lista[i].estado << "," << lista[i].id_os << endl;

	}*/

	LLamado_Secretaria(lista, &contador, lista_nueva_verificados, lista1, lista3, lista2, &contador5, &contador2, &contador4, &contador3, lista_archivados, &contador_archivados);

/*
	for (int i = 0; i < contador - 1; i++) {
		cout << "Paciente nro: " << i << endl;
		cout << lista[i].dni << "," << lista[i].nombre << "," << lista[i].apellido << "," << lista[i].sexo << "," << lista[i].natalicio << "," << lista[i].estado << "," << lista[i].id_os << endl;
	}

	for (int i = 0; i < contador3 - 1; i++) {
		cout << lista2[i].matricula << "," << lista2[i].nombre << "," << lista2[i].apellido << "," << lista2[i].telefono << "," << lista2[i].especialidad << "," << lista2[i].activo << endl;
	}

	for (int i = 0; i < contador4 - 1; i++) {
		cout << lista3[i].dni_pac << "," << lista3[i].telefono << "," << lista3[i].celular << "," << lista3[i].direccion << "," << lista3[i].mail << endl;
	}*/

}
