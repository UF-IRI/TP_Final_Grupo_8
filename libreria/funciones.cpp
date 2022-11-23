#include "funciones.h"
#pragma once

//funciones de agregar a un archivo
void agregar_pacientes(Pacientes*& lista_pac, Pacientes paciente, int* tamactual) {
	*tamactual = *tamactual + 1;
	int i = 0;
	Pacientes* aux = new Pacientes[*tamactual];
	while (i < *tamactual - 1 && *tamactual - 1 != 0) {
		aux[i] = lista_pac[i];
		i++;
	}
	aux[i] = paciente;

	delete[] lista_pac;
	lista_pac = aux;

	return;
}

void agregar_medicos(Medicos*& lista_med, Medicos medico, int* tamactual) {
	*tamactual = *tamactual + 1;
	int i = 0;
	Medicos* aux = new Medicos[*tamactual];
	while (i < *tamactual - 1 && *tamactual - 1 != 0) {
		aux[i] = lista_med[i];
		i++;
	}
	aux[i] = medico;

	delete[] lista_med;
	lista_med = aux;

	return;
}

void agregar_consultas(Consultas*& lista_cons, Consultas consulta, int* tamactual) {
	*tamactual = *tamactual + 1;
	int i = 0;
	Consultas* aux = new Consultas[*tamactual];
	while (i < *tamactual - 1 && *tamactual - 1 != 0) {
		aux[i] = lista_cons[i];
		i++;
	}
	aux[i] = consulta;

	delete[] lista_cons;
	lista_cons = aux;

	return;
}

void agregar_contactos(Contactos*& lista_cont, Contactos contacto, int* tamactual) {
	*tamactual = *tamactual + 1;
	int i = 0;
	Contactos* aux = new Contactos[*tamactual];
	while (i < *tamactual - 1 && *tamactual - 1 != 0) {
		aux[i] = lista_cont[i];
		i++;
	}
	aux[i] = contacto;

	delete[] lista_cont;
	lista_cont = aux;

	return;
}


//funciones para leer archivos
Pacientes* read_archivo_pacientes(string a1, int* contador) {
	Pacientes* l_pac = new Pacientes[0];
	Pacientes aux;
	fstream fr;
	string dummy;
	char coma;
	int tamact = 0;

	fr.open(a1, ios::in);
	//fr.open(a1, ios::in | ios::app);
	if (!fr.is_open())
		cout << "Error al leer archivo";
	else {
		fr >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy;
		while (fr) {
			fr >> aux.dni >> coma >> aux.apellido >> coma >> aux.nombre >> coma >> aux.sexo >> coma >> aux.natalicio >> coma >> aux.estado >> coma >> aux.id_os;
			//cout << aux.nombre << '\n';
			agregar_pacientes(l_pac, aux, &tamact);
			*contador = *contador + 1;
		}


	}


	return l_pac;
}

Medicos* read_archivo_medicos(string a1, int* contador) {
	Medicos* l_med = new Medicos[0];
	Medicos aux;
	fstream fr;
	string dummy;
	char coma;
	int tamact = 0;

	fr.open(a1, ios::in);
	//fr.open(a1, ios::in | ios::app);
	if (!fr.is_open())
		cout << "Error al leer archivo";
	else {
		fr >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy;
		while (fr) {
			fr >> aux.matricula >> coma >> aux.nombre >> coma >> aux.apellido >> coma >> aux.telefono >> coma >> aux.especialidad >> coma >> aux.activo;
			//cout << aux.nombre << '\n';
			agregar_medicos(l_med, aux, &tamact);
			*contador = *contador + 1;
		}

	}


	return l_med;
}

Consultas* read_archivo_consultas(string a1, int* contador2) {
	Consultas* l_cons = new Consultas[0];
	Consultas aux;
	fstream fr;
	string dummy;
	char coma;
	int tamact = 0;

	fr.open(a1, ios::in);
	//fr.open(a1, ios::in | ios::app);
	if (!fr.is_open())
		cout << "Error al leer archivo";
	else {
		fr >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy;
		while (fr) {
			//dni_pac , fecha_solicitado , fecha_turno , presento , matricula_med

			//cout << aux.nombre << '\n';
			agregar_consultas(l_cons, aux, &tamact);
			*contador2 = *contador2 + 1;
		}

	}


	return l_cons;
}

Contactos* read_archivo_contactos(string a1, int* contador4) {
	Contactos* l_cont = new Contactos[0];
	Contactos aux;
	fstream fr;
	string dummy;
	char coma;
	int tamact = 0;

	fr.open(a1, ios::in);
	//fr.open(a1, ios::in | ios::app);
	if (!fr.is_open())
		cout << "Error al leer archivo";
	else {
		fr >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy;
		while (fr) {
			fr >> aux.dni_pac >> coma >> aux.telefono >> coma >> aux.celular >> coma >> aux.direccion >> coma >> aux.mail;
			//cout << aux.nombre << '\n';
			agregar_contactos(l_cont, aux, &tamact);
			*contador4 = *contador4 + 1;
		}


	}


	return l_cont;
}


//funciones que tienen que ver con crear, leer y agregar datos a un archivo
void agregar_pacientes_archivados(Pacientes*& lista_pac, Pacientes paciente, int* tamactual) {
	*tamactual = *tamactual + 1;
	int i = 0;
	Pacientes* aux = new Pacientes[*tamactual];
	while (i < *tamactual - 1 && *tamactual - 1 != 0) {
		aux[i] = lista_pac[i];
		i++;
	}
	aux[i] = paciente;

	delete[] lista_pac;
	lista_pac = aux;

	return;
}

void crear_archivo_pacientes_archivados(string nombre_a1, Pacientes*& lista_pac_archivados, int* tamactual) {
	fstream archi, archi2;

	archi.open(nombre_a1, ios::out);
	//archi2.open(nombre_a2, ios::out);
	int i = 0;

	//&& archi2.is_open()
	if (archi.is_open()) {
		archi << "dni , nombre , apellido , sexo , natalicio , estado , obra_social" << endl;
		while (i < *tamactual) {
			//dni , nombre , apellido , sexo , natalicio , estado , obra_social

			archi << lista_pac_archivados[i].dni << " , " << lista_pac_archivados[i].nombre << " , " << lista_pac_archivados[i].apellido << " , " << lista_pac_archivados[i].sexo << " , " << lista_pac_archivados[i].natalicio << " , " << lista_pac_archivados[i].estado << " , " << lista_pac_archivados[i].id_os << "\n";
			//archi << 10932 << " , " << 6 << " , " << 8 << endl;
			//archi2 << "dni , apellido , nombre" << endl;
			//archi2 << 10932 << " , Maradona , Diego" << endl;
			//archi2 << 1000 << " , Messi , Lionel" << endl;
			i++;
		}

	}

	archi.close();
	//archi2.close();

	return;
}

Pacientes* archivar_pacientes(Pacientes*& lista_pac_a_archivar, int* contador5) {
	Pacientes* l_pac = new Pacientes[0];
	int tamactual = 0;
	for (int i = 0; i <= 100; i++) {
		if (lista_pac_a_archivar[i].estado == "fallecido") {
			agregar_pacientes_archivados(l_pac, lista_pac_a_archivar[i], &tamactual);
		}
	}
	*contador5 = tamactual;
	return l_pac;
}

Pacientes* read_archivo_pacientes_archivados(string a1) {
	Pacientes* l_pac = new Pacientes[0];
	Pacientes aux;
	fstream fr;
	string dummy;
	char coma;
	int tamact = 0;

	fr.open(a1, ios::in);
	//fr.open(a1, ios::in | ios::app);
	if (!fr.is_open())
		cout << "Error al leer archivo";
	else {
		fr >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy;
		while (fr) {
			fr >> aux.dni >> coma >> aux.apellido >> coma >> aux.nombre >> coma >> aux.sexo >> coma >> aux.natalicio >> coma >> aux.estado >> coma >> aux.id_os;
			//cout << aux.nombre << '\n';
			agregar_pacientes(l_pac, aux, &tamact);
		}


	}


	return l_pac;
}


//funciones del programa
Medicos* Buscar_Medico_Nuevo(Medicos* Lista_Medicos, Pacientes paciente, int tam) {

	Medicos aux;
	for (int i = 0; i < tam; i++) {
		int respuesta_agenda_llena = rand() % 2;
		if (paciente.consulta.matricula_med != Lista_Medicos[i].matricula && Lista_Medicos[i].activo == true && respuesta_agenda_llena==false) { //chequeamos solo si encuentra ==matricula, hay que ver del boolean agenda_llena
			//le asigna el primer medico activo y que no sea el que lo haya atendido antes, tambien que sea de la especialidad que busca
			aux = Lista_Medicos[i];
		}//habria que ver porque deberia fijarse si el medico tiene agenda llena o algo asi, entonces recorre la lista y se fija de asignar turno con el primer medico que encuentre

	}
	return aux;//retornamos el medico
}

Medicos* Buscar_Medico_Viejo(Medicos* Lista_Medicos, Pacientes paciente, int tam) {

	Medicos aux;
	for (int i = 0; i < tam; i++) {
		if (paciente.consulta.matricula_med == Lista_Medicos[i].matricula && Lista_Medicos[i].activo == true) { //chequeamos solo si encuentra ==matricula, hay que ver del boolean agenda_llena
			//si encuentra al medico que lo habia atendido antes y este se encuentra disponible, misma especialidad???
			aux = Lista_Medicos[i]; //encontramos al medico
		}
	}
	return aux;//retornamos el struct del medico, significa que se puede asignar turno con el medico 
}

bool Asignar_Turno(Medicos* Lista_Medicos, Pacientes paciente_a_asignar_turno) {
	cout << "El paciente desea asignar un turno con el medico que lo atendió en su ultima consulta?" << endl;
	int respuesta1 = rand() % 2;
	if (respuesta1 == 1) {//true
		cout << "El paciente quiere programar un turno con su antiguo medico. Procedemos a buscar al medico en la lista y verificar disponibilidad");
		Medicos *aux1;
		aux1 = Buscar_Medico_Viejo(Lista_Medicos, paciente_a_asignar_turno, 100);
		if (aux1 != NULL) {//distinto de null, o sea encontro el struct del medico
			cout << "Se ha encontrado al medico, cuyos datos son: " << endl;
			cout << (*aux1).nombre << "," << (*aux1).apellido << "," << (*aux1).especialidad << endl;
			//una vez que hay match, habria que guardar al paciente en la lista de pacientes_agenda asi se informa que tiene turno
			//no se si habrian que modificar los datos de la consulta ya que se modifican tecnicamente
			return true;
		}
		else { //igual a null, o sea no encontro el struct del medico
			cout << "No se ha encontrado al medico, desea asignar un turno con un nuevo medico?: " << endl;
			int respuesta2 = rand() % 2;

			if (respuesta2 == 1) {//true

				cout << "El paciente desea programar un turno con un nuevo médico. Procedemos a buscar al medico en la lista y verificar disponibilidad");

				Medicos* aux2;
				aux2 = Buscar_Medico_Nuevo(Lista_Medicos, paciente_a_asignar_turno, 100);

				if (aux2 != NULL) {
					cout << "Se ha encontrado un medico con disponibilidad, cuyos datos son: " << endl;
					cout << (*aux2).nombre << "," << (*aux2).apellido << "," << (*aux2).especialidad << endl;
					//una vez que hay match, habria que guardar al paciente en la lista de pacientes_agenda asi se informa que tiene turno
					//no se si habrian que modificar los datos de la consulta ya que se modifican tecnicamente
					return true;//turno asignado con exito
				}
				else {//no se encontro a ningun medico disponible
					cout << "No hay medicos disponibles para la especialidad que desea." << endl;
					//en este caso procedemos a dejar en standby y llamar en un tiempo, ofrecer otra cosa o archivamos directamente
					return false;//turno no asignado
				}
			}
		}

	}
	else { //==0 o sea false
		cout << "El paciente desea asignar turno con un nuevo medico. Procedemos a buscar en la lista de medicos y verificar disponibilidad." << endl;
		Medicos* aux3;
		aux3 = Buscar_Medico_Nuevo(Lista_Medicos, paciente_a_asignar_turno, 100);

		if (aux3 != NULL) {
			cout << "Se ha encontrado un medico con disponibilidad, cuyos datos son: " << endl;
			cout << (*aux3).nombre << "," << (*aux3).apellido << "," << (*aux3).especialidad << endl;
			//una vez que hay match, habria que guardar al paciente en la lista de pacientes_agenda asi se informa que tiene turno
			//no se si habrian que modificar los datos de la consulta ya que se modifican tecnicamente
			return true;//turno asignado con exito
		}
		else {//no se encontro a ningun medico disponible
			cout << "No hay medicos disponibles para la especialidad que desea." << endl;
			//en este caso procedemos a dejar en standby y llamar en un tiempo, ofrecer otra cosa o archivamos directamente
			return false;//turno no asignado
		}
	}

}