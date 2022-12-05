#include "funciones.h"
#pragma once
using namespace std;


string Obras_SocialesToString(eObras_Sociales obras) {

	switch (obras) {
	case eObras_Sociales::Medicus:
		return "Medicus";
		break;
	case eObras_Sociales::OSDE:
		return "OSDE";
		break;
	case eObras_Sociales::Italiano:
		return "Italiano";
		break;
	case eObras_Sociales::Espanyol:
		return "Espanyol";
		break;
	case eObras_Sociales::Aleman:
		return "Aleman";
		break;
	case eObras_Sociales::IOSFA:
		return "IOSFA";
		break;
	}

}


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

void agregar_consultas_extra(Consultas consulta, string a1, int* contador) {
	fstream archi;

	archi.open(a1, ios::app); 

	if (archi.is_open()) {
		//dni_pac , fecha_solicitado , fecha_turno , presento , matricula_med
		archi << consulta.dni_pac << " , " << consulta.fecha_solicitado << " , " << consulta.fecha_turno << " , " << consulta.presento << " , " << consulta.matricula_med << endl;
		*contador = *contador + 1;
	}
	else
		cout << "Archivo no encontrado. " << endl;
	archi.close();
}

Pacientes* read_archivo_pacientes(string a1, int* contador) {
	Pacientes* l_pac = new Pacientes[0];
	Pacientes aux;
	fstream fr;
	string dummy;
	char coma;
	int tamact = 0;

	fr.open(a1, ios::in);
	if (!fr.is_open())
		cout << "Error al leer archivo";
	else {
		fr >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy;
		while (fr) {
			fr >> aux.dni >> coma >> aux.nombre >> coma >> aux.apellido >> coma >> aux.sexo >> coma >> aux.natalicio >> coma >> aux.estado >> coma >> aux.id_os;
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
	if (!fr.is_open())
		cout << "Error al leer archivo";
	else {
		fr >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy;
		while (fr) {
			fr >> aux.matricula >> coma >> aux.nombre >> coma >> aux.apellido >> coma >> aux.telefono >> coma >> aux.especialidad >> coma >> aux.activo;
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
	if (!fr.is_open())
		cout << "Error al leer archivo";
	else {
		fr >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy;
		while (fr) {
			//dni_pac , fecha_solicitado , fecha_turno , presento , matricula_med
			fr >> aux.dni_pac >> coma >> aux.fecha_solicitado >> coma >> aux.fecha_turno >> coma >> aux.presento >> coma >> aux.matricula_med;
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
	if (!fr.is_open())
		cout << "Error al leer archivo";
	else {
		fr >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy;
		while (fr) {
			fr >> aux.dni_pac >> coma >> aux.telefono >> coma >> aux.celular >> coma;
			getline(fr, aux.direccion, ',');
			fr >> aux.mail;
			agregar_contactos(l_cont, aux, &tamact);
			*contador4 = *contador4 + 1;
		}


	}


	return l_cont;
}

void agregar_pacientes_archivados(Pacientes*& lista_pac, Pacientes paciente, int* tamactual) {
	*tamactual = *tamactual + 1;
	int i = 0;
	Pacientes* aux = new Pacientes[*tamactual];
	while (i < *tamactual - 1 && *tamactual - 1 != 0) {
		aux[i] = lista_pac[i];
		i++;
	}
	aux[i] = paciente;

	if (&lista_pac[0] != NULL) {
		delete[] lista_pac;
	}

	lista_pac = aux;

	return;
}

void crear_archivo_pacientes_archivados(string nombre_a1, Pacientes*& lista_pac_archivados, int* tamactual) {
	fstream archi;

	archi.open(nombre_a1, ios::out);
	int i = 0;

	//&& archi2.is_open()
	if (archi.is_open()) {
		archi << "dni , nombre , apellido , sexo , natalicio , estado , obra_social" << endl;
		while (i < *tamactual) {
			//dni , nombre , apellido , sexo , natalicio , estado , obra_social
			archi << lista_pac_archivados[i].dni << " , " << lista_pac_archivados[i].nombre << " , " << lista_pac_archivados[i].apellido << " , " << lista_pac_archivados[i].sexo << " , " << lista_pac_archivados[i].natalicio << " , " << lista_pac_archivados[i].estado << " , " << lista_pac_archivados[i].id_os << "\n";
			i++;
		}

	}

	archi.close();

	return;
}

void crear_archivo_lista_pacientes_nueva(string nombre_a1, Pacientes*& lista_pac, int* tamactual) {
	fstream archi;

	archi.open(nombre_a1, ios::out);
	int i = 0;


	if (archi.is_open()) {
		archi << "dni , nombre , apellido , sexo , natalicio , estado , obra_social , archivado" << endl;
		while (i < *tamactual - 1) {
			//dni , nombre , apellido , sexo , natalicio , estado , obra_social

			archi << lista_pac[i].dni << " , " << lista_pac[i].nombre << " , " << lista_pac[i].apellido << " , " << lista_pac[i].sexo << " , " << lista_pac[i].natalicio << " , " << lista_pac[i].estado << " , " << lista_pac[i].id_os << " , " << lista_pac[i].archivado << "\n";
			i++;
		}

	}

	archi.close();

	return;
}

Pacientes* read_archivo_pacientes_archivados(string a1) {
	Pacientes* l_pac = new Pacientes[0];
	Pacientes aux;
	fstream fr;
	string dummy;
	char coma;
	int tamact = 0;

	fr.open(a1, ios::in);
	if (!fr.is_open())
		cout << "Error al leer archivo";
	else {
		fr >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy;
		while (fr) {
			fr >> aux.dni >> coma >> aux.apellido >> coma >> aux.nombre >> coma >> aux.sexo >> coma >> aux.natalicio >> coma >> aux.estado >> coma >> aux.id_os;
			agregar_pacientes(l_pac, aux, &tamact);

		}


	}


	return l_pac;
}

Pacientes* read_archivo_lista_pacientes_nueva(string a1) {
	Pacientes* l_pac = new Pacientes[0];
	Pacientes aux;
	fstream fr;
	string dummy;
	char coma;
	int tamact = 0;

	fr.open(a1, ios::in);
	if (!fr.is_open())
		cout << "Error al leer archivo";
	else {
		fr >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy;
		while (fr) {
			fr >> aux.dni >> coma >> aux.apellido >> coma >> aux.nombre >> coma >> aux.sexo >> coma >> aux.natalicio >> coma >> aux.estado >> coma >> aux.id_os >> coma >> aux.archivado;
			agregar_pacientes(l_pac, aux, &tamact);
		}


	}


	return l_pac;
}

tm* toInt(string cadena) {
	time_t t = time(0);   // get time now
	tm* ltm = (tm*)malloc(sizeof(tm));

	int i = 0;
	int j = 0;
	string dia, mes, anio = "";
	while (i < cadena.length()) {
		char aux = cadena[i];
		if (aux != '/') {
			if (j == 0)
				dia = dia + aux;
			if (j == 1)
				mes = mes + aux;
			if (j == 2)
				anio = anio + aux;
		}
		else {
			j++;
		}
		i++;


	}

	ltm->tm_year = stoi(anio);
	ltm->tm_mday = stoi(dia);
	ltm->tm_mon = stoi(mes);

	return ltm;

}

Consultas* filtrar_lista_por_dni(Consultas* lista_consultas, Pacientes pac, int* tamactual, int* tam) {
	Consultas* l_cons = new Consultas[0];
	int tamact = 0;

	for (int i = 0; i < *tamactual; i++) {
		if (pac.dni == lista_consultas[i].dni_pac) {
			agregar_consultas(l_cons, lista_consultas[i], &tamact);
			*tam = *tam + 1;
		}
	}
	return l_cons;

}

tm* Encontrar_Consulta_Fecha(Consultas* lista_consultas_filtradas, int* tamactual) {
	Consultas* l_cons = new Consultas[*tamactual];
	tm* aux1 = 0;
	tm* aux2 = 0;

	aux1 = toInt(lista_consultas_filtradas[0].fecha_turno);

	for (int i = 0; i < *tamactual; i++) {

		aux2 = toInt(lista_consultas_filtradas[i].fecha_turno);

		if (aux1->tm_year < aux2->tm_year)
			aux1 = aux2;
		else if (aux1->tm_year < aux2->tm_year && aux1->tm_mon < aux2->tm_mon)
			aux1 = aux2;
		else if (aux1->tm_year < aux2->tm_year && aux1->tm_mon < aux2->tm_mon && aux1->tm_mday < aux2->tm_mday)
			aux1 = aux2;
	}

	return aux1;
}

Consultas* encontrar_ultima_consulta(Consultas* lista_consultas_filtradas, int* tamactual) {
	Consultas* aux = NULL;
	tm* aux1;
	tm* aux2;

	aux1 = toInt(lista_consultas_filtradas[0].fecha_turno);

	for (int i = 0; i < *tamactual; i++) {


		aux2 = toInt(lista_consultas_filtradas[i].fecha_turno);

		if (aux1->tm_year < aux2->tm_year) {
			aux1 = aux2;
			aux = &lista_consultas_filtradas[i];
		}
		else if (aux1->tm_year < aux2->tm_year && aux1->tm_mon < aux2->tm_mon) {
			aux1 = aux2;
			aux = &lista_consultas_filtradas[i];
		}
		else if (aux1->tm_year < aux2->tm_year && aux1->tm_mon < aux2->tm_mon && aux1->tm_mday < aux2->tm_mday) {
			aux1 = aux2;
			aux = &lista_consultas_filtradas[i];
		}
		else if (aux1->tm_year == aux2->tm_year && aux1->tm_mon == aux2->tm_mon && aux1->tm_mday == aux2->tm_mday)
			aux = &lista_consultas_filtradas[i];
	}

	return aux;

}

Medicos* Buscar_Medico_Viejo(Medicos* Lista_Medicos, Consultas* lista_consultas, int* contador6, int* tam) {

	Consultas* ultima_consulta = encontrar_ultima_consulta(lista_consultas, contador6);
	Medicos* aux = NULL;

	for (int i = 0; i < *tam; i++) {
		if (ultima_consulta->matricula_med == Lista_Medicos[i].matricula && Lista_Medicos[i].activo == true) { //chequeamos solo si encuentra ==matricula, hay que ver del boolean agenda_llena
			//si encuentra al medico que lo habia atendido antes y este se encuentra disponible, misma especialidad???
			aux = &Lista_Medicos[i]; //encontramos al medico
			return aux;
		}
	}
	return aux;//retornamos el struct del medico, significa que se puede asignar turno con el medico 
}

Medicos* Buscar_Medico_Nuevo(Medicos* Lista_Medicos, Consultas* lista_consultas, int* contador6, int* tam) {

	Consultas* ultima_consulta = encontrar_ultima_consulta(lista_consultas, contador6);
	Medicos* aux = NULL;

	Medicos* medico_ultima_consulta = Buscar_Medico_Viejo(Lista_Medicos, lista_consultas, contador6, tam);
	for (int i = 0; i < *tam; i++) {
		int respuesta_agenda_llena = rand() % 2;
		if (medico_ultima_consulta != NULL) {
			if (ultima_consulta->matricula_med != Lista_Medicos[i].matricula && Lista_Medicos[i].activo == true && medico_ultima_consulta->especialidad == Lista_Medicos[i].especialidad) { //chequeamos solo si encuentra ==matricula, hay que ver del boolean agenda_llena
				//si encuentra al medico que lo habia atendido antes y este se encuentra disponible, misma especialidad???
				aux = &Lista_Medicos[i]; //encontramos al medico
				return aux;
			}
		}
		else
			if (ultima_consulta->matricula_med != Lista_Medicos[i].matricula && Lista_Medicos[i].activo == true && respuesta_agenda_llena == 0) { //chequeamos solo si encuentra ==matricula, hay que ver del boolean agenda_llena
				//si encuentra al medico que lo habia atendido antes y este se encuentra disponible, misma especialidad???
				aux = &Lista_Medicos[i]; //encontramos al medico
				return aux;
			}

	}
	return aux;//retornamos el struct del medico, significa que se puede asignar turno con el medico 
}

Pacientes* Buscar_Pacientes_Archivados(Pacientes* lista_pac, Pacientes pac_archivado_a_buscar, int* tam) {

	Pacientes* aux = NULL;
	for (int i = 0; i < *tam; i++) {
		if (lista_pac[i].dni == pac_archivado_a_buscar.dni) {
			aux = &lista_pac[i];
			return aux;
		}

	}
	return aux;
}

int Verificar_Anio_Ultima_Consulta(tm* fecha_ultima_consulta) {

	char s[100];
	int rc;
	time_t temp;
	struct tm* timeptr;

	temp = time(NULL);
	timeptr = localtime(&temp);

	rc = strftime(s, sizeof(s), "%d/%m/%Y", timeptr);
	tm* aux2 = toInt(s);

	time_t t = time(0);
	tm* nuevo = localtime(&t);
	nuevo->tm_year = (aux2->tm_year) - (fecha_ultima_consulta->tm_year);

	cout << "Diferencia de años: " << nuevo->tm_year << endl;

	if (nuevo->tm_year < 10 && nuevo->tm_year>0) {
		return 1;
		//ok, la diferencia de año es menor a 10 o sea es un paciente recuperable, podemos llamar
	}
	else if (nuevo->tm_year == 10) { //la diferencia de año es 10, está al limite
		if (fecha_ultima_consulta->tm_mon > aux2->tm_mon) { //vemos si el mes de la ultima consulta es mayor
			return 1;
			//ok, el mes de la consulta es mayor, ej 11/2022-12/2012, significa que todavia no llegaron a ser 10 años 
			//justos de su ultima consulta, por eso es un paciente recuperable, podemos llamarlo
		}
		else if (fecha_ultima_consulta->tm_mon == aux2->tm_mon) { //el mes es igua, está al limit
			if (fecha_ultima_consulta->tm_mday >= aux2->tm_mday) {
				return 1;
				//todavia no se cumplieron los 10 años o se cumplieron los 10 años justo ese dia
				//pero es un paciente recuperable, podemos llamarlo
			}
			else//el dia de la ultima consulta es mas chico, se supero el limite
				return 0;
			//ya se cumplieron los 10 años, es un paciente irrecuperable, procedemos a archivarlo

		}
		else if (fecha_ultima_consulta->tm_mon < aux2->tm_mon) {////el mes de ultima consulta es mas chico, supero limite
			//ya se cumplieron los 10 años, es un paciente irrecuperable, procedemos a archivarlo
			return 0;
		}
	}
	else if (nuevo->tm_year > 10)//la diferencia de años es mayor a los 10, se supero el limite
		return 0;//ya se cumplieron los 10 años, es un paciente irrecuperable, procedemos a archivarlo
	else if (nuevo->tm_year < 0)
		return 2; //paciente tiene turno actual
	else if (nuevo->tm_year == 0) {
		if (fecha_ultima_consulta->tm_mon > aux2->tm_mon)
			return 2;
		else if (fecha_ultima_consulta->tm_mon == aux2->tm_mon) {
			if (fecha_ultima_consulta->tm_mday >= aux2->tm_mday) {
				return 2;
				//todavia no se cumplieron los 10 años o se cumplieron los 10 años justo ese dia
				//pero es un paciente recuperable, podemos llamarlo
			}
			else//el dia de la ultima consulta es mas chico, se supero el limite
				return 1;
		}
		else if (fecha_ultima_consulta->tm_mon < aux2->tm_mon)
			return 1;
	}

}

string Verificar_Datos_Paciente(Pacientes paciente_datos_verificar) {
	int respuesta1 = rand() % 2;

	cout << "El paciente ha cambiado sus datos de obra social? " << endl;
	if (respuesta1 == 1) {
		cout << "El paciente ha cambiado de obra social, preguntamos por cual y modificamos sus datos en el archivo. " << endl;

		if (paciente_datos_verificar.id_os == Obras_SocialesToString(eObras_Sociales::Medicus)) {
			int respuesta2 = rand() % 5 + 1;
			//Medicus, OSDE, Italiano, Espanyol, Aleman, IOSFA
			if (respuesta2 == 1) {
				cout << "El paciente se cambio a Osde, guardamos nueva obra social." << endl;
				eObras_Sociales nuevo = eObras_Sociales::OSDE;
				paciente_datos_verificar.id_os = Obras_SocialesToString(nuevo);
			}
			else if (respuesta2 == 2) {
				cout << "El paciente se cambio a Italiano, guardamos nueva obra social." << endl;
				eObras_Sociales nuevo = eObras_Sociales::Italiano;
				paciente_datos_verificar.id_os = Obras_SocialesToString(nuevo);
			}
			else if (respuesta2 == 3) {
				cout << "El paciente se cambio a Espanyol, guardamos nueva obra social." << endl;
				eObras_Sociales nuevo = eObras_Sociales::Espanyol;
				paciente_datos_verificar.id_os = Obras_SocialesToString(nuevo);
			}
			if (respuesta2 == 4) {
				cout << "El paciente se cambio a Aleman, guardamos nueva obra social." << endl;
				eObras_Sociales nuevo = eObras_Sociales::Aleman;
				paciente_datos_verificar.id_os = Obras_SocialesToString(nuevo);
			}
			if (respuesta2 == 5) {
				cout << "El paciente se cambio a IOSFA, guardamos nueva obra social." << endl;
				eObras_Sociales nuevo = eObras_Sociales::IOSFA;
				paciente_datos_verificar.id_os = Obras_SocialesToString(nuevo);
			}

		}
		else if (paciente_datos_verificar.id_os == Obras_SocialesToString(eObras_Sociales::OSDE)) {
			int respuesta2 = rand() % 5 + 1;

			//Medicus, OSDE, Italiano, Espanyol, Aleman, IOSFA
			if (respuesta2 == 1) {
				cout << "El paciente se cambio a Medicus, guardamos nueva obra social." << endl;
				eObras_Sociales nuevo = eObras_Sociales::Medicus;
				paciente_datos_verificar.id_os = Obras_SocialesToString(nuevo);
			}
			else if (respuesta2 == 2) {
				cout << "El paciente se cambio a Italiano, guardamos nueva obra social." << endl;
				eObras_Sociales nuevo = eObras_Sociales::Italiano;
				paciente_datos_verificar.id_os = Obras_SocialesToString(nuevo);
			}
			else if (respuesta2 == 3) {
				cout << "El paciente se cambio a Espanyol, guardamos nueva obra social." << endl;
				eObras_Sociales nuevo = eObras_Sociales::Espanyol;
				paciente_datos_verificar.id_os = Obras_SocialesToString(nuevo);
			}
			if (respuesta2 == 4) {
				cout << "El paciente se cambio a Aleman, guardamos nueva obra social." << endl;
				eObras_Sociales nuevo = eObras_Sociales::Aleman;
				paciente_datos_verificar.id_os = Obras_SocialesToString(nuevo);
			}
			if (respuesta2 == 5) {
				cout << "El paciente se cambio a IOSFA, guardamos nueva obra social." << endl;
				eObras_Sociales nuevo = eObras_Sociales::IOSFA;
				paciente_datos_verificar.id_os = Obras_SocialesToString(nuevo);
			}

		}
		else if (paciente_datos_verificar.id_os == Obras_SocialesToString(eObras_Sociales::Italiano)) {
			int respuesta2 = rand() % 5 + 1;

			//Medicus, OSDE, Italiano, Espanyol, Aleman, IOSFA
			if (respuesta2 == 1) {
				cout << "El paciente se cambio a Medicus, guardamos nueva obra social." << endl;
				eObras_Sociales nuevo = eObras_Sociales::Medicus;
				paciente_datos_verificar.id_os = Obras_SocialesToString(nuevo);
			}
			else if (respuesta2 == 2) {
				cout << "El paciente se cambio a OSDE, guardamos nueva obra social." << endl;
				eObras_Sociales nuevo = eObras_Sociales::OSDE;
				paciente_datos_verificar.id_os = Obras_SocialesToString(nuevo);
			}
			else if (respuesta2 == 3) {
				cout << "El paciente se cambio a Espanyol, guardamos nueva obra social." << endl;
				eObras_Sociales nuevo = eObras_Sociales::Espanyol;
				paciente_datos_verificar.id_os = Obras_SocialesToString(nuevo);
			}
			if (respuesta2 == 4) {
				cout << "El paciente se cambio a Aleman, guardamos nueva obra social." << endl;
				eObras_Sociales nuevo = eObras_Sociales::Aleman;
				paciente_datos_verificar.id_os = Obras_SocialesToString(nuevo);
			}
			if (respuesta2 == 5) {
				cout << "El paciente se cambio a IOSFA, guardamos nueva obra social." << endl;
				eObras_Sociales nuevo = eObras_Sociales::IOSFA;
				paciente_datos_verificar.id_os = Obras_SocialesToString(nuevo);
			}

		}
		else if (paciente_datos_verificar.id_os == Obras_SocialesToString(eObras_Sociales::Espanyol)) {
			int respuesta2 = rand() % 5 + 1;

			//Medicus, OSDE, Italiano, Espanyol, Aleman, IOSFA
			if (respuesta2 == 1) {
				cout << "El paciente se cambio a Medicus, guardamos nueva obra social." << endl;
				eObras_Sociales nuevo = eObras_Sociales::Medicus;
				paciente_datos_verificar.id_os = Obras_SocialesToString(nuevo);
			}
			else if (respuesta2 == 2) {
				cout << "El paciente se cambio a Italiano, guardamos nueva obra social." << endl;
				eObras_Sociales nuevo = eObras_Sociales::Italiano;
				paciente_datos_verificar.id_os = Obras_SocialesToString(nuevo);
			}
			else if (respuesta2 == 3) {
				cout << "El paciente se cambio a OSDE, guardamos nueva obra social." << endl;
				eObras_Sociales nuevo = eObras_Sociales::OSDE;
				paciente_datos_verificar.id_os = Obras_SocialesToString(nuevo);
			}
			if (respuesta2 == 4) {
				cout << "El paciente se cambio a Aleman, guardamos nueva obra social." << endl;
				eObras_Sociales nuevo = eObras_Sociales::Aleman;
				paciente_datos_verificar.id_os = Obras_SocialesToString(nuevo);
			}
			if (respuesta2 == 5) {
				cout << "El paciente se cambio a IOSFA, guardamos nueva obra social." << endl;
				eObras_Sociales nuevo = eObras_Sociales::IOSFA;
				paciente_datos_verificar.id_os = Obras_SocialesToString(nuevo);
			}

		}
		else if (paciente_datos_verificar.id_os == Obras_SocialesToString(eObras_Sociales::Aleman)) {
			int respuesta2 = rand() % 5 + 1;

			//Medicus, OSDE, Italiano, Espanyol, Aleman, IOSFA
			if (respuesta2 == 1) {
				cout << "El paciente se cambio a Medicus, guardamos nueva obra social." << endl;
				eObras_Sociales nuevo = eObras_Sociales::Medicus;
				paciente_datos_verificar.id_os = Obras_SocialesToString(nuevo);
			}
			else if (respuesta2 == 2) {
				cout << "El paciente se cambio a Italiano, guardamos nueva obra social." << endl;
				eObras_Sociales nuevo = eObras_Sociales::Italiano;
				paciente_datos_verificar.id_os = Obras_SocialesToString(nuevo);
			}
			else if (respuesta2 == 3) {
				cout << "El paciente se cambio a Espanyol, guardamos nueva obra social." << endl;
				eObras_Sociales nuevo = eObras_Sociales::Espanyol;
				paciente_datos_verificar.id_os = Obras_SocialesToString(nuevo);
			}
			if (respuesta2 == 4) {
				cout << "El paciente se cambio a OSDE, guardamos nueva obra social." << endl;
				eObras_Sociales nuevo = eObras_Sociales::OSDE;
				paciente_datos_verificar.id_os = Obras_SocialesToString(nuevo);
			}
			if (respuesta2 == 5) {
				cout << "El paciente se cambio a IOSFA, guardamos nueva obra social." << endl;
				eObras_Sociales nuevo = eObras_Sociales::IOSFA;
				paciente_datos_verificar.id_os = Obras_SocialesToString(nuevo);
			}

		}
		else {
			//if (paciente_datos_verificar.id_os == Obras_SocialesToString(eObras_Sociales::IOSFA)) 
			int respuesta2 = rand() % 5 + 1;

			//Medicus, OSDE, Italiano, Espanyol, Aleman, IOSFA
			if (respuesta2 == 1) {
				cout << "El paciente se cambio a Medicus, guardamos nueva obra social." << endl;
				eObras_Sociales nuevo = eObras_Sociales::Medicus;
				paciente_datos_verificar.id_os = Obras_SocialesToString(nuevo);
			}
			else if (respuesta2 == 2) {
				cout << "El paciente se cambio a Italiano, guardamos nueva obra social." << endl;
				eObras_Sociales nuevo = eObras_Sociales::Italiano;
				paciente_datos_verificar.id_os = Obras_SocialesToString(nuevo);
			}
			else if (respuesta2 == 3) {
				cout << "El paciente se cambio a Espanyol, guardamos nueva obra social." << endl;
				eObras_Sociales nuevo = eObras_Sociales::Espanyol;
				paciente_datos_verificar.id_os = Obras_SocialesToString(nuevo);
			}
			if (respuesta2 == 4) {
				cout << "El paciente se cambio a Aleman, guardamos nueva obra social." << endl;
				eObras_Sociales nuevo = eObras_Sociales::Aleman;
				paciente_datos_verificar.id_os = Obras_SocialesToString(nuevo);
			}
			if (respuesta2 == 5) {
				cout << "El paciente se cambio a OSDE, guardamos nueva obra social." << endl;
				eObras_Sociales nuevo = eObras_Sociales::OSDE;
				paciente_datos_verificar.id_os = Obras_SocialesToString(nuevo);
			}

		}

	}
	else
		cout << "El paciente no se cambio de obra social." << endl;

	return paciente_datos_verificar.id_os;
}

int verificar_estado_paciente(Pacientes paciente_a_verificar) {
	if (paciente_a_verificar.estado == "fallecido")
		return 0;
	else if (paciente_a_verificar.estado == "internado")
		return 1;
	else if (paciente_a_verificar.estado == "n/c")
		return 2;
}

tm* fecha_nuevo_turno_random() {
	time_t t = time(0);   // get time now
	tm* ltm = (tm*)malloc(sizeof(tm));

	ltm->tm_year = 2023;
	ltm->tm_mon = rand() % 11 + 1;
	ltm->tm_mday = 0;


	if (ltm->tm_mon == 4 || ltm->tm_mon == 6 || ltm->tm_mon == 9 || ltm->tm_mon == 11)
		ltm->tm_mday = rand() % 30 + 1; //abril, junio, septiembre y noviembre
	else if (ltm->tm_mon == 1 || ltm->tm_mon == 3 || ltm->tm_mon == 5 || ltm->tm_mon == 7 || ltm->tm_mon == 8 || ltm->tm_mon == 10 || ltm->tm_mon == 12)
		ltm->tm_mday = rand() % 31 + 1; //enero, marzo, mayo, julio, agosto, octubre y diciembre
	else if (ltm->tm_mon == 2)//febrero
		ltm->tm_mday = rand() % 28 + 1;

	int A = (14 - ltm->tm_mon) / 12;
	int Y = ltm->tm_year - A;
	int M = ltm->tm_mon + (12 * A) - 2;
	int diaSemana;

	if (ltm->tm_year >= 1582)       /// Inicio del calendario Gregoriano
		diaSemana = (ltm->tm_mday + Y + Y / 4 - Y / 100 + Y / 400 + (31 * M) / 12) % 7;

	else        /// calendario Juliano
		diaSemana = (5 + ltm->tm_mday + Y + Y / 4 + (31 * M) / 12) % 7;

	if (diaSemana > 0)
		diaSemana--;
	else
		diaSemana = 6;

	ltm->tm_wday = diaSemana;
	return ltm;
}

void Agregar_Archivado(Pacientes* lista_pac_antigua, Pacientes* lista_archivados, int* tam_ant, int* tam_arch) {

	for (int i = 0; i < *tam_ant; i++) {
		Pacientes* paciente_encontrado = Buscar_Pacientes_Archivados(lista_archivados, lista_pac_antigua[i], tam_arch);

		if (paciente_encontrado != NULL) { //lo encontro en la lista de archivados
			lista_pac_antigua[i].archivado = "Archivado";
		}
		else { //no lo encontro en la lista de archivados
			lista_pac_antigua[i].archivado = "No_Archivado";
		}
	}
}

Medicos* Asignar_Medico(Medicos* Lista_Medicos, Consultas* lista_cons, int* contador6, int* contador3) {

	Medicos* medico_nueva_consulta = NULL;
	Medicos* medico_nueva_consulta_nuevo = NULL;

	cout << "Desea un turno con el medico de su ultima consulta?" << endl;
	int respuesta1 = rand() % 2;
	if (respuesta1 == 1) {
		medico_nueva_consulta = Buscar_Medico_Viejo(Lista_Medicos, lista_cons, contador6, contador3);

		if (medico_nueva_consulta != NULL) {
			cout << "Encontramos al medico de su ultima consulta, sus datos son: " << endl;
			cout << "Matricula: " << medico_nueva_consulta->matricula << " Apellido: " << medico_nueva_consulta->apellido << " Nombre: " << medico_nueva_consulta->nombre << " Especialidad: " << medico_nueva_consulta->especialidad << endl;
			return medico_nueva_consulta;// se asignó con exito
		}
		else {
			cout << "No se ha encontrado al medico de su ultima consulta en el hospital." << endl;
			cout << "Desea buscar otro medico? " << endl;

			int respuesta2 = rand() % 2;

			if (respuesta2 == 1) {
				cout << "Ha decidido buscar otro medico: " << endl;
				medico_nueva_consulta_nuevo = Buscar_Medico_Nuevo(Lista_Medicos, lista_cons, contador6, contador3);

				if (medico_nueva_consulta_nuevo != NULL) {
					cout << "Encontramos un nuevo medico, sus datos son: " << endl;
					cout << "Matricula: " << medico_nueva_consulta_nuevo->matricula << " Apellido: " << medico_nueva_consulta_nuevo->apellido << " Nombre: " << medico_nueva_consulta_nuevo->nombre << " Especialidad: " << medico_nueva_consulta_nuevo->especialidad << endl;
					return medico_nueva_consulta_nuevo;
				}
				else {
					cout << "No se ha encontrado un medico nuevo disponible. Archivamos al paciente." << endl;
					return medico_nueva_consulta_nuevo;
				}

			}
			else {
				cout << "El paciente ha decidido no buscar otro medico. Archivamos al paciente." << endl;
				return medico_nueva_consulta;
			}

		}
	}
	else {
		cout << "Ha decidido no asignar turno con su ultimo medico, procedemos a buscar un nuevo. " << endl;

		medico_nueva_consulta_nuevo = Buscar_Medico_Nuevo(Lista_Medicos, lista_cons, contador6, contador3);

		if (medico_nueva_consulta_nuevo != NULL) {
			cout << "Encontramos un nuevo medico, sus datos son: " << endl;
			cout << "Matricula: " << medico_nueva_consulta_nuevo->matricula << " Apellido: " << medico_nueva_consulta_nuevo->apellido << " Nombre: " << medico_nueva_consulta_nuevo->nombre << " Especialidad: " << medico_nueva_consulta_nuevo->especialidad << endl;
			return medico_nueva_consulta_nuevo;
		}
		else {
			cout << "No se ha encontrado al medico nuevo. Archivamos al paciente." << endl;
			return medico_nueva_consulta_nuevo;
		}

	}
}

//nueva, revisar porque asi corre bien pero no me deja agregar datos de nueva consulta a lista, se rompe
//se rompe con el tema de la funcion toint, recibe vacio a partir del paciente 3, creo arrastra basura
//ver el tema de 2023, sino lo pongo fijo imprime 3000 y pico, lo del mes creo que es 0 a 11 y 0 es enero, etc

Contactos* buscar_contacto_emergencia(Contactos* lista_contactos, int* tam_contactos, Pacientes pac_a_llamar, Contactos* contacto_pac) {
	Contactos* contacto_aux1 = NULL;
	for (int i = 0; i < *tam_contactos; i++) {
		if (lista_contactos[i].dni_pac == pac_a_llamar.dni && lista_contactos[i].telefono != contacto_pac->telefono) {
			contacto_aux1 = &lista_contactos[i];
			return contacto_aux1;
		}
	}
	return contacto_aux1;
}

Contactos* buscar_contacto_pac(Contactos* lista_contactos, int* tam_contactos, Pacientes pac_a_llamar) {
	Contactos* contacto_aux = NULL;

	for (int i = 0; i < *tam_contactos; i++) {
		if (lista_contactos[i].dni_pac == pac_a_llamar.dni) {
			contacto_aux = &lista_contactos[i];
			return contacto_aux;
		}
	}
	return contacto_aux;
}

void crear_archivo_nuevo_lista_verificados(string nombre_a1, Pacientes*& lista_pac, Consultas*& lista_cons, Contactos*& lista_contactos, int* tamactual, int* tam_consultas, int* tam_contactos) {
	fstream archi;
	int tam_lista_filtrada_consultas = 0;

	archi.open(nombre_a1, ios::out);
	int i = 0;

	if (archi.is_open()) {
		archi << "dni , nombre , apellido , sexo , natalicio , estado , obra_social , fecha_ultima_consulta_solicitado , fecha_turno_ultima_consulta , ultima_consulta_presento, ultima_consulta_matricula_medico , telefono_paciente , celular_paciente , direccion_paciente , mail_paciente , telefono_emergencia , celular_emergencia , direccion_emergencia , mail_emergencia" << endl;
		while (i < *tamactual) {
			//dni , nombre , apellido , sexo , natalicio , estado , obra_social
			Consultas* lista_cons_filtradas = filtrar_lista_por_dni(lista_cons, lista_pac[i], tam_consultas, &tam_lista_filtrada_consultas);
			Consultas* aux_consultas = encontrar_ultima_consulta(lista_cons_filtradas, &tam_lista_filtrada_consultas);

			Contactos* contacto_paciente_a_llamar = buscar_contacto_pac(lista_contactos, tam_contactos, lista_pac[i]);
			Contactos* contacto_paciente_a_llamar_emergencia = NULL;
			if (contacto_paciente_a_llamar != NULL) {
				contacto_paciente_a_llamar_emergencia = buscar_contacto_emergencia(lista_contactos, tam_contactos, lista_pac[i], contacto_paciente_a_llamar);
				if (contacto_paciente_a_llamar_emergencia == NULL) {
					archi << lista_pac[i].dni << " , " << lista_pac[i].nombre << " , " << lista_pac[i].apellido << " , " << lista_pac[i].sexo << " , " << lista_pac[i].natalicio << " , " << lista_pac[i].estado << " , " << lista_pac[i].id_os << " , " << aux_consultas->fecha_solicitado << " , " << aux_consultas->fecha_turno << " , " << aux_consultas->presento << " , " << aux_consultas->matricula_med << " , " << contacto_paciente_a_llamar->telefono << " , " << contacto_paciente_a_llamar->celular << " , " << contacto_paciente_a_llamar->direccion << " , " << contacto_paciente_a_llamar->mail << "\n";
					//archi << lista_pac[i].dni << " , " << lista_pac[i].nombre << " , " << lista_pac[i].apellido << " , " << lista_pac[i].sexo << " , " << lista_pac[i].natalicio << " , " << lista_pac[i].estado << " , " << lista_pac[i].id_os << " , " << aux_consultas->fecha_solicitado << " , " << aux_consultas->fecha_turno << " , " << aux_consultas->presento << " , " << aux_consultas->matricula_med << " , " << contacto_paciente_a_llamar->telefono << " , " << contacto_paciente_a_llamar->celular << " , " << contacto_paciente_a_llamar->direccion << " , " << contacto_paciente_a_llamar->mail << " , " << "SIN INFORMACION TELEFONO EMERGENCIA" << " , " << "SIN INFORMACION CELULAR EMERGENCIA" << " , " << "SIN INFORMACION DIRECCION EMERGENCIA" << " , " << "SIN INFORMACION MAIL EMERGENCIA" << "\n";

				}
				else
					archi << lista_pac[i].dni << " , " << lista_pac[i].nombre << " , " << lista_pac[i].apellido << " , " << lista_pac[i].sexo << " , " << lista_pac[i].natalicio << " , " << lista_pac[i].estado << " , " << lista_pac[i].id_os << " , " << aux_consultas->fecha_solicitado << " , " << aux_consultas->fecha_turno << " , " << aux_consultas->presento << " , " << aux_consultas->matricula_med << " , " << contacto_paciente_a_llamar->telefono << " , " << contacto_paciente_a_llamar->celular << " , " << contacto_paciente_a_llamar->direccion << " , " << contacto_paciente_a_llamar->mail << " , " << contacto_paciente_a_llamar_emergencia->telefono << " , " << contacto_paciente_a_llamar_emergencia->celular << " , " << contacto_paciente_a_llamar_emergencia->direccion << " , " << contacto_paciente_a_llamar_emergencia->mail << "\n";
			}
			else {
				contacto_paciente_a_llamar_emergencia = buscar_contacto_emergencia(lista_contactos, tam_contactos, lista_pac[i], contacto_paciente_a_llamar);

				if (contacto_paciente_a_llamar_emergencia == NULL) {
					//archi << lista_pac[i].dni << " , " << lista_pac[i].nombre << " , " << lista_pac[i].apellido << " , " << lista_pac[i].sexo << " , " << lista_pac[i].natalicio << " , " << lista_pac[i].estado << " , " << lista_pac[i].id_os << " , " << aux_consultas->fecha_solicitado << " , " << aux_consultas->fecha_turno << " , " << aux_consultas->presento << " , " << aux_consultas->matricula_med << " , " << "SIN INFORMACION TELEFONO PACIENTE" << " , " << "SIN INFORMACION CELULAR PACIENTE" << " , " << "SIN INFORMACION DIRECCION PACIENTE" << " , " << "SIN INFORMACION MAIL PACIENTE" << " , " << "SIN INFORMACION TELEFONO EMERGENCIA" << " , " << "SIN INFORMACION CELULAR EMERGENCIA" << " , " << "SIN INFORMACION DIRECCION EMERGENCIA" << " , " << "SIN INFORMACION MAIL EMERGENCIA" << "\n";
					archi << lista_pac[i].dni << " , " << lista_pac[i].nombre << " , " << lista_pac[i].apellido << " , " << lista_pac[i].sexo << " , " << lista_pac[i].natalicio << " , " << lista_pac[i].estado << " , " << lista_pac[i].id_os << " , " << aux_consultas->fecha_solicitado << " , " << aux_consultas->fecha_turno << " , " << aux_consultas->presento << " , " << aux_consultas->matricula_med << "\n";
				}

			}
			i++;
			tam_lista_filtrada_consultas = 0;
		}

	}

	archi.close();

	return;
}

int verificar_anio_2(tm* fecha_ultima_consulta) {
	char s[100];
	int rc;
	time_t temp;
	struct tm* timeptr;

	temp = time(NULL);
	timeptr = localtime(&temp);

	rc = strftime(s, sizeof(s), "%d/%m/%Y", timeptr);

	tm* aux2 = toInt(s);


	time_t t = time(0);
	tm* nuevo = localtime(&t);
	nuevo->tm_year = (aux2->tm_year) - (fecha_ultima_consulta->tm_year);

	cout << "Diferencia de años: " << nuevo->tm_year << endl;

	if (nuevo->tm_year <= 10 && nuevo->tm_year > 0) {
		if (nuevo->tm_year <= 10 && nuevo->tm_year > 5)
			return 1;//llamamos porque paso mucho tiempo desde su ultima actividad
		else if (nuevo->tm_year == 5) {//justo esta al borde
			if (fecha_ultima_consulta->tm_mon < aux2->tm_mon)
				return 1; //llamamos
			else if (fecha_ultima_consulta->tm_mon == aux2->tm_mon) {
				if (fecha_ultima_consulta->tm_mday <= aux2->tm_mday) {
					return 1;
					//ya se cumplieron mas de 5 años de ultima actividad
					//pero es un paciente recuperable, podemos llamarlo
				}
				else//el dia de la ultima consulta es mas chico, se supero el limite
					return 0; //no recperable
			}
			else if (fecha_ultima_consulta->tm_mon > aux2->tm_mon) {////el mes de ultima consulta es mas chico, supero limite
				//no se cumplieron los 5, paciente dentro de todo activo
				return 0; //no hace falta llamar
			}
		}
		else if (nuevo->tm_year < 5)
			return 0; //no hace falta llamar, pacientr activo
	}
	else
		return 2;//ocurrio algo raro, 2 significa que no esta en  ningun rango. Es raro porque significa que es mayor a 10 o menor a o y ya habia
	//pasado la primera verificacion

}

bool cambio_obra_social() {
	int respuesta1 = rand() % 2;

	cout << "El paciente ha cambiado sus datos de obra social? " << endl;
	if (respuesta1 == 1) {
		cout << "El paciente ha cambiado de obra social, preguntamos por cual y modificamos sus datos en el archivo. " << endl;
		return true;
	}
	else {
		cout << "El paciente no se cambio de obra social." << endl;
		return false;
	}


}

string fecha_de_hoy() {
	time_t curr_time;
	tm* curr_tm;
	char date_string1[100];


	time(&curr_time);
	curr_tm = localtime(&curr_time);

	strftime(date_string1, 50, "%d/%m/%Y", curr_tm);
	return date_string1;
}

string fecha_turno(tm* fecha_turno) {
	time_t curr_time2;
	tm* curr_tm2;
	time(&curr_time2);
	curr_tm2 = localtime(&curr_time2);

	char date_string2[100];

	curr_tm2->tm_year = 2023;
	curr_tm2->tm_mon = fecha_turno->tm_mon;
	curr_tm2->tm_mday = fecha_turno->tm_mday;

	strftime(date_string2, 50, "%d/%m/2023", curr_tm2); //ver
	return date_string2;
}

void Imprimir_Datos_Consulta(Consultas nueva_consulta, Pacientes lista_pac, int* contador) {
	if (cambio_obra_social() == true) {
		string nueva_obra = Verificar_Datos_Paciente(lista_pac);
		cout << "Datos de la nueva consulta: " << endl;
		cout << "DNI del paciente: " << nueva_consulta.dni_pac << endl;
		cout << "Fecha en la cual se solicito el turno: " << nueva_consulta.fecha_solicitado << endl;
		cout << "Fecha del turno: " << nueva_consulta.fecha_turno << endl;
		cout << "Matricula del medico del proximo turno: " << nueva_consulta.matricula_med << endl;
		cout << "Se presento el paciente?: " << nueva_consulta.presento << endl;
		cout << "Obra social nueva: " << nueva_obra << endl;
	}
	else {
		cout << "Datos de la nueva consulta: " << endl;
		cout << "DNI del paciente: " << nueva_consulta.dni_pac << endl;
		cout << "Fecha en la cual se solicito el turno: " << nueva_consulta.fecha_solicitado << endl;
		cout << "Fecha del turno: " << nueva_consulta.fecha_turno << endl;
		cout << "Matricula del medico del proximo turno: " << nueva_consulta.matricula_med << endl;
		cout << "Se presento el paciente?: " << nueva_consulta.presento << endl;
		cout << "Obra social:" << lista_pac.id_os << endl;
	}
}

void LLamado_Secretaria(Pacientes* lista_pac, int* tam_pacientes, Pacientes* lista_nueva_verificados, Consultas* lista_consultas, Contactos* lista_contactos, Medicos* lista_medicos, int* tam_pacientes_verificados, int* tam_consultas, int* tam_contactos, int* tam_medicos, Pacientes*& lista_pac_archivados, int* tam_lista_archivados) {

	int tam_lista_filtrada_consultas = 0;
	Consultas* lista_cons;
	Medicos* medico_nueva_consulta = NULL;
	Medicos* medico_nueva_consulta_nuevo = NULL;
	Consultas nueva_consulta;
	Contactos* contacto_paciente_a_llamar = NULL;
	Contactos* contacto_paciente_a_llamar_emergencia = NULL;
	tm* fecha_nuevo_turno;

	Consultas* nueva_lista_auxiliar_consultas = NULL;
	int tam_lista_consultas_auxiliar = 0;



	for (int i = 0; i < *tam_pacientes_verificados - 1; i++) { //recorre lista pacientes-1
		cout << "Paciente nro: " << i + 1 << endl;
		cout << "Dni: " << lista_nueva_verificados[i].dni << ", " << "Nombre: " << lista_nueva_verificados[i].nombre << ", " << "Apellido: " << lista_nueva_verificados[i].apellido << ", "
			<< "Sexo: " << lista_nueva_verificados[i].sexo << ", " << "Fecha de nacimiento: " << lista_nueva_verificados[i].natalicio << ", " << "Estado paciente: " << lista_nueva_verificados[i].estado
			<< ", " << "Obra social: " << lista_nueva_verificados[i].id_os << endl;

		lista_cons = filtrar_lista_por_dni(lista_consultas, lista_nueva_verificados[i], tam_consultas, &tam_lista_filtrada_consultas);
		cout << "Imprimiendo consultas del paciente: " << endl;
		for (int j = 0; j < tam_lista_filtrada_consultas; j++) {
			cout << "Dni: " << lista_cons[j].dni_pac << endl;
			cout << "Fecha solicitado del turno: " << lista_cons[j].fecha_solicitado << endl;
			cout << "Fecha del turno: " << lista_cons[j].fecha_turno << endl;
			cout << "Matricula del medico: " << lista_cons[j].matricula_med << endl;
			if (lista_cons[j].presento == true) {
				cout << "Presento:" << "Se presento al ultimo turno." << endl;
			}
			else
				cout << "Presento:" << "No se presento al ultimo turno." << endl;
		}

		int verificacion_estado_paciente = verificar_estado_paciente(lista_nueva_verificados[i]);

		if (verificacion_estado_paciente == 2) {//paciente vivo segun historial
			tm* aux3 = Encontrar_Consulta_Fecha(lista_cons, &tam_lista_filtrada_consultas);
			Consultas* aux_ult_consulta = encontrar_ultima_consulta(lista_cons, &tam_lista_filtrada_consultas);

			int verificacion_anio_ultima_consulta = Verificar_Anio_Ultima_Consulta(aux3);


			if (aux_ult_consulta->presento == false) {
				cout << "Datos ultima consulta del paciente: " << endl;
				cout << "Dni: " << aux_ult_consulta->dni_pac << endl;
				cout << "Fecha solicitado del turno: " << aux_ult_consulta->fecha_solicitado << endl;
				cout << "Fecha del turno: " << aux_ult_consulta->fecha_turno << endl;
				cout << "Matricula del medico: " << aux_ult_consulta->matricula_med << endl;
				if (aux_ult_consulta->presento == true) {
					cout << "Presento:" << "Se presento al ultimo turno." << endl;
				}
				else
					cout << "Presento:" << "No se presento al ultimo turno." << endl;

				cout << "Paciente recuperable, procedemos a buscar algun contacto telefonico y llamar. " << endl;

				contacto_paciente_a_llamar = buscar_contacto_pac(lista_contactos, tam_contactos, lista_nueva_verificados[i]);

				if (contacto_paciente_a_llamar != NULL) {
					cout << "Encontramos contacto del paciente, los datos son los siguientes: " << endl;

					cout << "Dni del paciente: " << contacto_paciente_a_llamar->dni_pac << ", " << "Telefono: " << contacto_paciente_a_llamar->telefono << ", "
						<< "Celular: " << contacto_paciente_a_llamar->celular << ", " << "Direccion: " << contacto_paciente_a_llamar->direccion
						<< ", " << "E-Mail: " << contacto_paciente_a_llamar->mail << endl;

					cout << "Llamando al paciente.." << endl;

					int respuesta_llamado_paciente = rand() % 2;

					if (respuesta_llamado_paciente) {
						cout << "El paciente ha respondido al llamado. Procedemos a consultar sobre la posibilidad de tener un nuevo turno en nuestro centro medico" << endl;

						int respuesta_pac_nuevo_turno = rand() % 2;

						if (respuesta_pac_nuevo_turno) {
							cout << "El paciente quiere un nuevo turno en nuestro centro medico." << endl;
							medico_nueva_consulta = Asignar_Medico(lista_medicos, lista_cons, &tam_lista_filtrada_consultas, tam_medicos);

							if (medico_nueva_consulta != NULL) {
								cout << "Ya asignamos con exito al medico de su proxima consulta, procedemos a dar una fecha del turno. " << endl;
								fecha_nuevo_turno = fecha_nuevo_turno_random();

								string date_string1 = fecha_de_hoy();
								string date_string2 = fecha_turno(fecha_nuevo_turno);
								
								nueva_consulta.fecha_solicitado = date_string1;
								nueva_consulta.fecha_turno = date_string2;
								nueva_consulta.matricula_med = medico_nueva_consulta->matricula;
								nueva_consulta.dni_pac = lista_nueva_verificados[i].dni;
								nueva_consulta.presento = false;

								Imprimir_Datos_Consulta(nueva_consulta, lista_nueva_verificados[i], tam_pacientes_verificados);

								agregar_consultas_extra(nueva_consulta, "Consultas.csv", tam_consultas);
							}
							//else
								//cout << "Hubo problemas para asignar un medico con disponibilidad, volveremos a llamar al paciente en unos dias. " << endl;
						}
						else {
							cout << "El paciente no está interesado en obtener un nuevo turno en nuestro centro medico, archivamos su historial. " << endl;
							agregar_pacientes_archivados(*&lista_pac_archivados, lista_nueva_verificados[i], tam_lista_archivados);
							//aca habria que llamar a la funcion de archivar
						}

					}
					else {
						cout << "El paciente no ha respondido al llamado, procedemos a llamar a su contacto de emergencia con el fin de dar con el paciente. " << endl;
						contacto_paciente_a_llamar_emergencia = buscar_contacto_emergencia(lista_contactos, tam_contactos, lista_nueva_verificados[i], contacto_paciente_a_llamar);

						if (contacto_paciente_a_llamar_emergencia != NULL) {
							cout << "Encontramos al contacto de emergencia, sus datos son: " << endl;

							cout << "Dni del paciente: " << contacto_paciente_a_llamar_emergencia->dni_pac << ", " << "Telefono del contacto: " << contacto_paciente_a_llamar_emergencia->telefono << ", "
								<< "Celular del contacto: " << contacto_paciente_a_llamar->celular << ", " << "Direccion del contacto: " << contacto_paciente_a_llamar->direccion
								<< ", " << "E-Mail del contacto: " << contacto_paciente_a_llamar->mail << endl;

							cout << "Llamando al contacto de emergencia.. " << endl;

							int respuesta_contacto_emergencia = rand() % 2;
							if (respuesta_contacto_emergencia) {
								cout << "El contacto ha respondido al llamado, procedemos a consultar sobre como se encuentra el paciente y porque no atendio, con el fin de asignar un nuevo turno" << endl;

								int respuesta_estado_pac = rand() % 3;//0 esta vivo, no atendio porque estaba ocupado, procedemos a llamarlo y ya directo asignar turnp
								//1 fallecio, procedemos a archivar y modificar su estado a fallecido
								//2 internado, procedemos a dejar en standby y llamar cuando se encuentre mejor, modificamos estado

								if (respuesta_estado_pac == 0) {
									cout << "El paciente se encuentra bien, procedemos a llamarlo y ver la posibilidad de que agende un nuevo turno. " << endl;
									int respuesta_pac_nuevo_turno2 = rand() % 2;

									if (respuesta_pac_nuevo_turno2) {
										cout << "El paciente quiere un nuevo turno en nuestro centro medico." << endl;
										medico_nueva_consulta = Asignar_Medico(lista_medicos, lista_cons, &tam_lista_filtrada_consultas, tam_medicos);

										if (medico_nueva_consulta != NULL) {
											cout << "Ya asignamos con exito al medico de su proxima consulta, procedemos a dar una fecha del turno. " << endl;
											fecha_nuevo_turno = fecha_nuevo_turno_random();

											string date_string1 = fecha_de_hoy();
											string date_string2 = fecha_turno(fecha_nuevo_turno);
											
											nueva_consulta.fecha_solicitado = date_string1;
											nueva_consulta.fecha_turno = date_string2;
											nueva_consulta.matricula_med = medico_nueva_consulta->matricula;
											nueva_consulta.dni_pac = lista_nueva_verificados[i].dni;
											nueva_consulta.presento = false;

											Imprimir_Datos_Consulta(nueva_consulta, lista_nueva_verificados[i], tam_pacientes_verificados);

											agregar_consultas_extra(nueva_consulta, "Consultas.csv", tam_consultas);
										}
										//else
										//	cout << "Hubo problemas para asignar un medico con disponibilidad, volveremos a llamar al paciente en unos dias. " << endl;
									}
									else {
										cout << "El paciente no está interesado en obtener un nuevo turno en nuestro centro medico, archivamos su historial. " << endl;
										agregar_pacientes_archivados(*&lista_pac_archivados, lista_nueva_verificados[i], tam_lista_archivados);
										//aca habria que llamar a la funcion de archivar
									}
								}
								else if (respuesta_estado_pac == 1) {
									lista_nueva_verificados[i].estado = "fallecido";
									cout << "El contacto nos informa que el paciente ha fallecido, archivamos su historial." << endl;
									agregar_pacientes_archivados(*&lista_pac_archivados, lista_nueva_verificados[i], tam_lista_archivados);
									//funcion de archivar

								}
								else {
									cout << "El contacto nos informa que el paciente se encuentra internado, modificamos el archivo y procedemos a llamar mas adelante" << endl;
									lista_nueva_verificados[i].estado = "internado";
								}

							}
							else {
								cout << "El contacto de emergencia no ha respondido al llamado. Enviamos un email a ambos contactos con el fin de recibir respuesta, de igual forma en unos dias llamamos al paciente otra vez. " << endl;
								//dejamos en standby
								cout << "Enviando email al paciente,  su correo es:" << contacto_paciente_a_llamar->mail << endl;
								cout << "Enviando email al contacto de emergencia, su correo es: " << contacto_paciente_a_llamar_emergencia->mail << endl;
							}
						}
						else {
							cout << "No se encontró un contacto de emergencia, procedemos a enviar un email al paciente e intentar llamar en unos dias otra vez. " << endl;
							cout << "Enviando email al paciente,  su correo es:" << contacto_paciente_a_llamar->mail << endl;
							//dejamos en standby

						}
					}

				}
				else {
					cout << "Ha ocurrido un error y no se ha podido encontrar información de contacto del paciente. Archivamos por falta de informacion. " << endl;
					agregar_pacientes_archivados(*&lista_pac_archivados, lista_nueva_verificados[i], tam_lista_archivados);
				}

			}
			else {
				int aux_anio2 = verificar_anio_2(aux3);

				if (aux_anio2 == 1) {
					cout << "Aunque el paciente asistio hace menos de 10 anios a su ultimo, la ultima actividad de este fue hace mas de 5 anios" << endl;
					cout << "Paciente recuperable, procedemos a buscar algun contacto telefonico y llamar. " << endl;

					contacto_paciente_a_llamar = buscar_contacto_pac(lista_contactos, tam_contactos, lista_nueva_verificados[i]);

					if (contacto_paciente_a_llamar != NULL) {
						cout << "Encontramos contacto del paciente, los datos son los siguientes: " << endl;

						cout << "Dni del paciente: " << contacto_paciente_a_llamar->dni_pac << ", " << "Telefono: " << contacto_paciente_a_llamar->telefono << ", "
							<< "Celular: " << contacto_paciente_a_llamar->celular << ", " << "Direccion: " << contacto_paciente_a_llamar->direccion
							<< ", " << "E-Mail: " << contacto_paciente_a_llamar->mail << endl;

						cout << "Llamando al paciente.." << endl;

						int respuesta_llamado_paciente = rand() % 2;

						if (respuesta_llamado_paciente) {
							cout << "El paciente ha respondido al llamado. Procedemos a consultar sobre la posibilidad de tener un nuevo turno en nuestro centro medico" << endl;

							int respuesta_pac_nuevo_turno = rand() % 2;

							if (respuesta_pac_nuevo_turno) {
								cout << "El paciente quiere un nuevo turno en nuestro centro medico." << endl;
								medico_nueva_consulta = Asignar_Medico(lista_medicos, lista_cons, &tam_lista_filtrada_consultas, tam_medicos);

								if (medico_nueva_consulta != NULL) {
									cout << "Ya asignamos con exito al medico de su proxima consulta, procedemos a dar una fecha del turno. " << endl;
									fecha_nuevo_turno = fecha_nuevo_turno_random();

									string date_string1 = fecha_de_hoy();
									string date_string2 = fecha_turno(fecha_nuevo_turno);
									
									nueva_consulta.fecha_solicitado = date_string1;
									nueva_consulta.fecha_turno = date_string2;
									nueva_consulta.matricula_med = medico_nueva_consulta->matricula;
									nueva_consulta.dni_pac = lista_nueva_verificados[i].dni;
									nueva_consulta.presento = false;

									Imprimir_Datos_Consulta(nueva_consulta, lista_nueva_verificados[i], tam_pacientes_verificados);

									agregar_consultas_extra(nueva_consulta, "Consultas.csv", tam_consultas);
								}
								//else
									//cout << "Hubo problemas para asignar un medico con disponibilidad, volveremos a llamar al paciente en unos dias. " << endl;
							}
							else {
								cout << "El paciente no está interesado en obtener un nuevo turno en nuestro centro medico, archivamos su historial. " << endl;
								agregar_pacientes_archivados(*&lista_pac_archivados, lista_nueva_verificados[i], tam_lista_archivados);
								//aca habria que llamar a la funcion de archivar
							}

						}
						else {
							cout << "El paciente no ha respondido al llamado, procedemos a llamar a su contacto de emergencia con el fin de dar con el paciente. " << endl;
							contacto_paciente_a_llamar_emergencia = buscar_contacto_emergencia(lista_contactos, tam_contactos, lista_nueva_verificados[i], contacto_paciente_a_llamar);

							if (contacto_paciente_a_llamar_emergencia != NULL) {
								cout << "Encontramos al contacto de emergencia, sus datos son: " << endl;

								cout << "Dni del paciente: " << contacto_paciente_a_llamar_emergencia->dni_pac << ", " << "Telefono del contacto: " << contacto_paciente_a_llamar_emergencia->telefono << ", "
									<< "Celular del contacto: " << contacto_paciente_a_llamar->celular << ", " << "Direccion del contacto: " << contacto_paciente_a_llamar->direccion
									<< ", " << "E-Mail del contacto: " << contacto_paciente_a_llamar->mail << endl;

								cout << "Llamando al contacto de emergencia.. " << endl;

								int respuesta_contacto_emergencia = rand() % 2;
								if (respuesta_contacto_emergencia) {
									cout << "El contacto ha respondido al llamado, procedemos a consultar sobre como se encuentra el paciente y porque no atendio, con el fin de asignar un nuevo turno" << endl;

									int respuesta_estado_pac = rand() % 3;//0 esta vivo, no atendio porque estaba ocupado, procedemos a llamarlo y ya directo asignar turnp
									//1 fallecio, procedemos a archivar y modificar su estado a fallecido
									//2 internado, procedemos a dejar en standby y llamar cuando se encuentre mejor, modificamos estado

									if (respuesta_estado_pac == 0) {
										cout << "El paciente se encuentra bien, procedemos a llamarlo y ver la posibilidad de que agende un nuevo turno. " << endl;
										int respuesta_pac_nuevo_turno2 = rand() % 2;

										if (respuesta_pac_nuevo_turno2) {
											cout << "El paciente quiere un nuevo turno en nuestro centro medico." << endl;
											medico_nueva_consulta = Asignar_Medico(lista_medicos, lista_cons, &tam_lista_filtrada_consultas, tam_medicos);

											if (medico_nueva_consulta != NULL) {
												cout << "Ya asignamos con exito al medico de su proxima consulta, procedemos a dar una fecha del turno. " << endl;
												fecha_nuevo_turno = fecha_nuevo_turno_random();

												string date_string1 = fecha_de_hoy();
												string date_string2 = fecha_turno(fecha_nuevo_turno);
												
												nueva_consulta.fecha_solicitado = date_string1;
												nueva_consulta.fecha_turno = date_string2;
												nueva_consulta.matricula_med = medico_nueva_consulta->matricula;
												nueva_consulta.dni_pac = lista_nueva_verificados[i].dni;
												nueva_consulta.presento = false;

												Imprimir_Datos_Consulta(nueva_consulta, lista_nueva_verificados[i], tam_pacientes_verificados);

												agregar_consultas_extra(nueva_consulta, "Consultas.csv", tam_consultas);
											}
											//else
											//	cout << "Hubo problemas para asignar un medico con disponibilidad, volveremos a llamar al paciente en unos dias. " << endl;
										}
										else {
											cout << "El paciente no está interesado en obtener un nuevo turno en nuestro centro medico, archivamos su historial. " << endl;
											agregar_pacientes_archivados(*&lista_pac_archivados, lista_nueva_verificados[i], tam_lista_archivados);
											//aca habria que llamar a la funcion de archivar
										}
									}
									else if (respuesta_estado_pac == 1) {
										lista_nueva_verificados[i].estado = "fallecido";
										cout << "El contacto nos informa que el paciente ha fallecido, archivamos su historial." << endl;
										agregar_pacientes_archivados(*&lista_pac_archivados, lista_nueva_verificados[i], tam_lista_archivados);
										//funcion de archivar

									}
									else {
										cout << "El contacto nos informa que el paciente se encuentra internado, modificamos el archivo y procedemos a llamar mas adelante" << endl;
										lista_nueva_verificados[i].estado = "internado";
									}

								}
								else {
									cout << "El contacto de emergencia no ha respondido al llamado. Enviamos un email a ambos contactos con el fin de recibir respuesta, de igual forma en unos dias llamamos al paciente otra vez. " << endl;
									//dejamos en standby
									cout << "Enviando email al paciente,  su correo es:" << contacto_paciente_a_llamar->mail << endl;
									cout << "Enviando email al contacto de emergencia, su correo es: " << contacto_paciente_a_llamar_emergencia->mail << endl;
								}
							}
							else {
								cout << "No se encontró un contacto de emergencia, procedemos a enviar un email al paciente e intentar llamar en unos dias otra vez. " << endl;
								cout << "Enviando email al paciente,  su correo es:" << contacto_paciente_a_llamar->mail << endl;
								//dejamos en standby

							}
						}

					}
					else {
						cout << "Ha ocurrido un error y no se ha podido encontrar información de contacto del paciente. Archivamos por falta de informacion. " << endl;
						agregar_pacientes_archivados(*&lista_pac_archivados, lista_nueva_verificados[i], tam_lista_archivados);
					}


				}
				else if (aux_anio2 == 0) {
					cout << "El paciente se presento a su ultimo turno, el cual fue hace menos de 10 años." << endl;

					if (verificar_anio_2)
						cout << "Datos ultima consulta del paciente: " << endl;
					cout << "Dni: " << aux_ult_consulta->dni_pac << endl;
					cout << "Fecha solicitado del turno: " << aux_ult_consulta->fecha_solicitado << endl;
					cout << "Fecha del turno: " << aux_ult_consulta->fecha_turno << endl;
					cout << "Matricula del medico: " << aux_ult_consulta->matricula_med << endl;
					if (aux_ult_consulta->presento == true) {
						cout << "Presento:" << "Se presento al ultimo turno." << endl;
					}
					else
						cout << "Presento:" << "No se presento al ultimo turno." << endl;
				}
			}

		}
		else if (verificacion_estado_paciente == 1) {//paciente internado segun historial
			cout << "El paciente se encuentra fallecido, archivamos su historial. " << endl;
			agregar_pacientes_archivados(*&lista_pac_archivados, lista_nueva_verificados[i], tam_lista_archivados);
			//archivamos, cambiamos estado del paciente
		}
		else if (verificacion_estado_paciente == 0) {//paciente fallecido segun historial
			//cambiamos estado del paciente
			cout << "El paciente se encuentra internado en nuestro centro medico, llamamos mas adelante. " << endl;
		}


		tam_lista_filtrada_consultas = 0;
		cout << "\n" << endl;
	}


	crear_archivo_pacientes_archivados("Pacientes_Archivados.csv", lista_pac_archivados, tam_lista_archivados);

	Pacientes* lista_archivados;
	lista_archivados = read_archivo_pacientes_archivados("Pacientes_Archivados.csv");

	cout << "Leyendo pacientes archivados:" << endl;
	for (int i = 0; i < *tam_lista_archivados; i++) {
		cout << lista_archivados[i].dni << "," << lista_archivados[i].nombre << "," << lista_archivados[i].apellido << "," << lista_archivados[i].sexo << "," << lista_archivados[i].natalicio << "," << lista_archivados[i].estado << "," << lista_archivados[i].id_os << endl;
	}

	Agregar_Archivado(lista_pac, lista_archivados, tam_pacientes, tam_lista_archivados);

	crear_archivo_lista_pacientes_nueva("Pacientes_Nueva_Lista.csv", lista_pac, tam_pacientes);

	Pacientes* lista_nueva_pac1;
	lista_nueva_pac1 = read_archivo_lista_pacientes_nueva("Pacientes_Nueva_Lista.csv");

	cout << "Imprimiendo nueva lista con columna de archivado. " << endl;
	for (int i = 0; i < *tam_pacientes - 1; i++) {
		cout << lista_nueva_pac1[i].dni << "," << lista_nueva_pac1[i].nombre << "," << lista_nueva_pac1[i].apellido << " , " << lista_nueva_pac1[i].sexo << " , " << lista_nueva_pac1[i].natalicio << " , " << lista_nueva_pac1[i].estado << " , " << lista_nueva_pac1[i].id_os << " , " << lista_nueva_pac1[i].archivado << endl;
	}
}


Pacientes* filtrar_verificacion_pacientes(Pacientes* lista_pac, int* tam_pacientes, Consultas* lista_consultas, int* tam_consultas, Contactos* lista_contactos, int* tam_contactos, int* tam_lista_nueva_pacientes, Pacientes*& lista_pac_archivados, int* tam_lista_archivados) {

	Pacientes* l_pac = new Pacientes[0];
	int tam_lista_filtrada_consultas = 0;
	Consultas* lista_cons = NULL;
	Contactos* contacto_paciente_a_llamar = NULL;
	Contactos* contacto_paciente_a_llamar_emergencia = NULL;

	for (int i = 0; i < *tam_pacientes - 1; i++) { //recorre lista pacientes-1

		cout << "Paciente nro: " << i + 1 << endl;
		cout << "Dni: " << lista_pac[i].dni << ", " << "Nombre: " << lista_pac[i].nombre << ", " << "Apellido: " << lista_pac[i].apellido << ", "
			<< "Sexo: " << lista_pac[i].sexo << ", " << "Fecha de nacimiento: " << lista_pac[i].natalicio << ", " << "Estado paciente: " << lista_pac[i].estado
			<< ", " << "Obra social: " << lista_pac[i].id_os << endl;

		lista_cons = filtrar_lista_por_dni(lista_consultas, lista_pac[i], tam_consultas, &tam_lista_filtrada_consultas);
		tm* aux3 = Encontrar_Consulta_Fecha(lista_cons, &tam_lista_filtrada_consultas);
		Consultas* aux_ult_consulta = encontrar_ultima_consulta(lista_cons, &tam_lista_filtrada_consultas);

		int verificacion_anio_ultima_consulta = Verificar_Anio_Ultima_Consulta(aux3);

		if (verificacion_anio_ultima_consulta == 1) { //paciente relativamente nuevo, puede retornar

			if (aux_ult_consulta->presento == false) {//no se presento a su ultimo turno, y segun historial esta vivo
				agregar_pacientes(l_pac, lista_pac[i], tam_lista_nueva_pacientes);
			}
			else if (aux_ult_consulta->presento == true) {
				cout << "El paciente se presento a su ultimo turno, el cual fue hace menos de 10 años." << endl;

				int segunda_verificacion = verificar_anio_2(aux3); //habria que ver si es menor a 5 años de actividad
				if (segunda_verificacion == 1)//podemos llamar
				{
					agregar_pacientes(l_pac, lista_pac[i], tam_lista_nueva_pacientes);
				}

			}

		}
		else if (verificacion_anio_ultima_consulta == 0) {
			cout << "El paciente se atendio hace mas de 10 años, es un paciente irrecuperable. Archivamos su historial. " << endl;
			agregar_pacientes_archivados(*&lista_pac_archivados, lista_pac[i], tam_lista_archivados);
			//archivamos
		}
		else if (verificacion_anio_ultima_consulta == 2) {
			cout << "El paciente ya tiene un turno proximo. " << endl;
			//no agrego nada
		}
		tam_lista_filtrada_consultas = 0;

	}
	return l_pac;

}


