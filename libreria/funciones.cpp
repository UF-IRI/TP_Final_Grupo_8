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
			fr >> aux.dni_pac >> coma >> aux.fecha_solicitado >> coma >> aux.fecha_turno >> coma >> aux.presento >> coma >> aux.matricula_med;
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
			fr >> aux.dni_pac >> coma >> aux.telefono >> coma >> aux.celular >> coma;
			getline(fr, aux.direccion, ',');
			fr >> aux.mail;
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

	if (&lista_pac[0] != NULL) {
		delete[] lista_pac;
	}

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

void crear_archivo_lista_pacientes_nueva(string nombre_a1, Pacientes*& lista_pac, int* tamactual) {
	fstream archi, archi2;

	archi.open(nombre_a1, ios::out);
	//archi2.open(nombre_a2, ios::out);
	int i = 0;

	//&& archi2.is_open()
	if (archi.is_open()) {
		archi << "dni , nombre , apellido , sexo , natalicio , estado , obra_social, archivado" << endl;
		while (i < *tamactual) {
			//dni , nombre , apellido , sexo , natalicio , estado , obra_social

			archi << lista_pac[i].dni << " , " << lista_pac[i].nombre << " , " << lista_pac[i].apellido << " , " << lista_pac[i].sexo << " , " << lista_pac[i].natalicio << " , " << lista_pac[i].estado << " , " << lista_pac[i].id_os << " , " << lista_pac[i].archivado << "\n";
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

//ya visto, funciona
Pacientes* read_archivo_lista_pacientes_nueva(string a1) {
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
		fr >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy;
		while (fr) {
			fr >> aux.dni >> coma >> aux.apellido >> coma >> aux.nombre >> coma >> aux.sexo >> coma >> aux.natalicio >> coma >> aux.estado >> coma >> aux.id_os >> coma >> aux.archivado;
			//cout << aux.nombre << '\n';
			agregar_pacientes(l_pac, aux, &tamact);
		}


	}


	return l_pac;
}

//
Consultas encontrar_ultima_consulta(Consultas* lista_consultas_filtradas, int* tamactual) {
	Consultas aux;
	tm* aux1;
	tm* aux2;

	aux1 = toInt(lista_consultas_filtradas[0].fecha_solicitado);

	for (int i = 0; i < *tamactual; i++) {

		aux2 = toInt(lista_consultas_filtradas[i].fecha_solicitado);
		//aux1.año=1980 aux1.mes= 7 aux1.dia=20
		//aux2.año=1982 aux2.mes=8  aux1.dia=24

		if (aux1->tm_year < aux2->tm_year) {
			aux1 = aux2;
			aux = lista_consultas_filtradas[i];
		}
		else if (aux1->tm_year < aux2->tm_year && aux1->tm_mon < aux2->tm_mon) {
			aux1 = aux2;
			aux = lista_consultas_filtradas[i];
		}
		else if (aux1->tm_year < aux2->tm_year && aux1->tm_mon < aux2->tm_mon && aux1->tm_mday < aux2->tm_mday) {
			aux1 = aux2;
			aux = lista_consultas_filtradas[i];
		}
	}

	return aux;

}

tm* toInt(string cadena) {
	time_t t = time(0);   // get time now
	//tm* ltm = localtime(&t);;
	tm* ltm = (tm*)malloc(sizeof(tm));

	int i = 0;
	int j = 0;
	//int dia,mes,anio;
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
	//cout << "dia : " << ltm->tm_mday << endl;
	//cout << "mes : " << ltm->tm_mon << endl;
	//cout << "anio : " << ltm->tm_year << endl;

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

//retorna fecha ctime de ultima consulta
tm* Encontrar_Consulta_Fecha(Consultas* lista_consultas_filtradas, int* tamactual) {
	Consultas* l_cons = new Consultas[*tamactual];
	tm* aux1 = 0;
	tm* aux2 = 0;

	//l_cons = filtrar_lista_por_dni(lista_consultas, pac, tamactual);

	aux1 = toInt(lista_consultas_filtradas[0].fecha_turno);

	for (int i = 0; i < *tamactual; i++) {

		aux2 = toInt(lista_consultas_filtradas[i].fecha_turno);
		//aux1.año=1980 aux1.mes= 7 aux1.dia=20
		//aux2.año=1982 aux2.mes=8  aux1.dia=24

		if (aux1->tm_year < aux2->tm_year)
			aux1 = aux2;
		else if (aux1->tm_year < aux2->tm_year && aux1->tm_mon < aux2->tm_mon)
			aux1 = aux2;
		else if (aux1->tm_year < aux2->tm_year && aux1->tm_mon < aux2->tm_mon && aux1->tm_mday < aux2->tm_mday)
			aux1 = aux2;
	}

	return aux1;
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
//funciones del programa
Medicos* Buscar_Medico_Viejo(Medicos* Lista_Medicos, Consultas* lista_consultas, int* contador6, int* tam) {

	Consultas ultima_consulta = encontrar_ultima_consulta(lista_consultas, contador6);
	Medicos* aux = NULL;

	for (int i = 0; i < *tam; i++) {
		if (ultima_consulta.matricula_med == Lista_Medicos[i].matricula && Lista_Medicos[i].activo == true) { //chequeamos solo si encuentra ==matricula, hay que ver del boolean agenda_llena
			//si encuentra al medico que lo habia atendido antes y este se encuentra disponible, misma especialidad???
			aux = &Lista_Medicos[i]; //encontramos al medico
			return aux;
		}
	}
	return aux;//retornamos el struct del medico, significa que se puede asignar turno con el medico 
}

Medicos* Buscar_Medico_Nuevo(Medicos* Lista_Medicos, Consultas* lista_consultas, int* contador6, int* tam) {

	Consultas ultima_consulta = encontrar_ultima_consulta(lista_consultas, contador6);
	Medicos* aux = NULL;

	Medicos* medico_ultima_consulta = Buscar_Medico_Viejo(Lista_Medicos, lista_consultas, contador6, tam);
	for (int i = 0; i < *tam; i++) {
		int respuesta_agenda_llena = rand() % 2;
		if (medico_ultima_consulta != NULL) {
			if (ultima_consulta.matricula_med != Lista_Medicos[i].matricula && Lista_Medicos[i].activo == true && medico_ultima_consulta->especialidad == Lista_Medicos[i].especialidad) { //chequeamos solo si encuentra ==matricula, hay que ver del boolean agenda_llena
				//si encuentra al medico que lo habia atendido antes y este se encuentra disponible, misma especialidad???
				aux = &Lista_Medicos[i]; //encontramos al medico
				return aux;
			}
		}
		else
			if (ultima_consulta.matricula_med != Lista_Medicos[i].matricula && Lista_Medicos[i].activo == true && respuesta_agenda_llena == 0) { //chequeamos solo si encuentra ==matricula, hay que ver del boolean agenda_llena
				//si encuentra al medico que lo habia atendido antes y este se encuentra disponible, misma especialidad???
				aux = &Lista_Medicos[i]; //encontramos al medico
				return aux;
			}

	}
	return aux;//retornamos el struct del medico, significa que se puede asignar turno con el medico 
}

/*bool Asignar_Medico(Medicos* Lista_Medicos, Consultas* lista_cons, int* contador6, int* contador3) {

	Medicos* medico_nueva_consulta;
	Medicos* medico_nueva_consulta_nuevo;

	cout << "Desea un turno con el medico de su ultima consulta?" << endl;
	int respuesta1 = rand() % 2;
	if (respuesta1 == 1) {
		medico_nueva_consulta = Buscar_Medico_Viejo(Lista_Medicos, lista_cons, contador6, contador3);

		if (medico_nueva_consulta != NULL) {
			cout << "Encontramos al medico de su ultima consulta, sus datos son: " << endl;
			cout << "Matricula: " << medico_nueva_consulta->matricula << " Apellido: " << medico_nueva_consulta->apellido << " Nombre: " << medico_nueva_consulta->nombre << " Especialidad: " << medico_nueva_consulta->especialidad << endl;
		}
		else {
			cout << "No se ha encontrado al medico." << endl;
			cout << "Desea buscar otro medico? " << endl;

			int respuesta2 = rand() % 2;

			if (respuesta2 == 1) {
				cout << "Ha decidido buscar otro medico: " << endl;
				medico_nueva_consulta_nuevo = Buscar_Medico_Nuevo(Lista_Medicos, lista_cons, contador6, contador3);

				if (medico_nueva_consulta_nuevo != NULL) {
					cout << "Encontramos un nuevo medico, sus datos son: " << endl;
					cout << "Matricula: " << medico_nueva_consulta_nuevo->matricula << " Apellido: " << medico_nueva_consulta_nuevo->apellido << " Nombre: " << medico_nueva_consulta_nuevo->nombre << " Especialidad: " << medico_nueva_consulta_nuevo->especialidad << endl;
				}
				else
					cout << "No se ha encontrado al medico nuevo." << endl;
			}
			else
				cout << "El paciente ha decidido no buscar otro medido" << endl;
		}
	}
	else {
		cout << "Ha decidido no asignar turno con su ultimo medico, procedemos a buscar un nuevo. " << endl;

		medico_nueva_consulta_nuevo = Buscar_Medico_Nuevo(Lista_Medicos, lista_cons, contador6, contador3);

		if (medico_nueva_consulta_nuevo != NULL) {
			cout << "Encontramos un nuevo medico, sus datos son: " << endl;
			cout << "Matricula: " << medico_nueva_consulta_nuevo->matricula << " Apellido: " << medico_nueva_consulta_nuevo->apellido << " Nombre: " << medico_nueva_consulta_nuevo->nombre << " Especialidad: " << medico_nueva_consulta_nuevo->especialidad << endl;
		}
		else
			cout << "No se ha encontrado al medico nuevo." << endl;
	}
}
*/

int Verificar_Anio_Ultima_Consulta(tm* fecha_ultima_consulta) {

	char s[100];
	int rc;
	time_t temp;
	struct tm* timeptr;

	temp = time(NULL);
	timeptr = localtime(&temp);

	rc = strftime(s, sizeof(s), "%d/%m/%Y", timeptr);
	tm* aux2 = toInt(s);

	cout << aux2->tm_mday << ", " << aux2->tm_mon << ", " << aux2->tm_year << endl;

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
		return 2;
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

tm* fecha_nuevo_turno_random() {
	time_t t = time(0);   // get time now
	//tm* ltm = localtime(&t);;
	tm* ltm = (tm*)malloc(sizeof(tm));

	ltm->tm_year = 2023;
	ltm->tm_mon = rand() % 11 + 1;
	ltm->tm_mday = 0;

	//auto t = time(nullptr);
	//auto tm = *localtime(&t);

	//ostringstream oss;
	//cout << put_time(&tm, "%d-%m-%Y %H-%M-%S");
	//auto str = oss.str();

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
	/*cout << "La fecha de su nuevo turno es: " << endl;
	cout << dia_semana << endl;
	cout << "Dia: " << ltm->tm_mday << endl;
	cout << "Mes: " << ltm->tm_mon << endl;
	cout << "Anio: " << ltm->tm_year << endl;*/
	return ltm;
}

//ver
void crear_archivo_consultas_nuevas(string nombre_a1, Consultas*& lista_consultas_nuevas, int* tamactual) {
	fstream archi;

	archi.open(nombre_a1, ios::out);
	//archi2.open(nombre_a2, ios::out);
	int i = 0;

	//&& archi2.is_open()
	if (archi.is_open()) {
		//dni_pac , fecha_solicitado , fecha_turno , presento , matricula_med
		archi << "dni_pac , fecha_solicitado , fecha_turno , presento , matricula_med" << endl;
		while (i < *tamactual) {
			//dni , nombre , apellido , sexo , natalicio , estado , obra_social

			archi << lista_consultas_nuevas[i].dni_pac << " , " << lista_consultas_nuevas[i].fecha_solicitado << " , " << lista_consultas_nuevas[i].fecha_turno << " , " << lista_consultas_nuevas[i].presento << " , " << lista_consultas_nuevas[i].matricula_med << "\n";
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

//ver
Consultas* read_archivo_nuevas_consultas(string a1) {
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
			fr >> aux.dni_pac >> coma >> aux.fecha_solicitado >> coma >> aux.fecha_turno >> coma >> aux.presento >> coma >> aux.matricula_med;
			//cout << aux.nombre << '\n';
			agregar_consultas(l_cons, aux, &tamact);

		}


	}


	return l_cons;
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

void Secretaria(Pacientes* lista_pac, Consultas* lista_consultas, Contactos* lista_contactos, Medicos* lista_medicos, int* tam_pacientes, int* tam_consultas, int* tam_contactos, int* tam_medicos) {

	int tam_lista_filtrada_consultas = 0;
	Consultas* lista_cons;
	Medicos* medico_nueva_consulta;
	Medicos* medico_nueva_consulta_nuevo;
	Consultas nueva_consulta;
	Contactos* contacto_paciente_a_llamar = NULL;
	Contactos* contacto_paciente_a_llamar_emergencia = NULL;
	tm* fecha_nuevo_turno;

	Consultas* nueva_lista_auxiliar_consultas = NULL;
	int tam_lista_consultas_auxiliar;

	int tam_lista_archivados = 0;
	Pacientes* lista_pac_archivados = NULL;
	for (int i = 0; i < *tam_pacientes - 1; i++) { //recorre lista pacientes-1
		cout << "Paciente nro: " << i + 1 << endl;
		cout << "Dni: " << lista_pac[i].dni << ", " << "Nombre: " << lista_pac[i].nombre << ", " << "Apellido: " << lista_pac[i].apellido << ", "
			<< "Sexo: " << lista_pac[i].sexo << ", " << "Fecha de nacimiento: " << lista_pac[i].natalicio << ", " << "Estado paciente: " << lista_pac[i].estado
			<< ", " << "Obra social: " << lista_pac[i].id_os << endl;
		//int aux2 = string_a_int(lista[i]);
		//cout << "Es: " << aux2 << endl;

		lista_cons = filtrar_lista_por_dni(lista_consultas, lista_pac[i], tam_consultas, &tam_lista_filtrada_consultas);
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



			tm* aux8;
			aux8 = toInt(lista_cons[j].fecha_solicitado);
			//cout << "Dia: " << aux8->tm_mday << " Mes: " << aux8->tm_mon << " Anio: " << aux8->tm_year << endl;
		}
		tm* aux3 = Encontrar_Consulta_Fecha(lista_cons, &tam_lista_filtrada_consultas);
		cout << "La consulta mas actual es: " << aux3->tm_mday << ", " << aux3->tm_mon << ", " << aux3->tm_year << endl;
		Consultas aux_ult_consulta = encontrar_ultima_consulta(lista_cons, &tam_lista_filtrada_consultas);

		int verificacion = Verificar_Anio_Ultima_Consulta(aux3);
		//ultima_consulta = encontrar_ultima_consulta(lista_cons, &tam_lista_filtrada);

		if (verificacion == 1 && aux_ult_consulta.presento == false) { //paciente relativamente nuevo
			cout << "Paciente recuperable, procedemos a buscar algun contacto telefonico y llamar. " << endl;

			contacto_paciente_a_llamar = buscar_contacto_pac(lista_contactos, tam_contactos, lista_pac[i]);

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

							nueva_consulta.dni_pac = lista_pac[i].dni;
							time_t curr_time;
							tm* curr_tm;
							char date_string1[100];
							char date_string2[100];

							time(&curr_time);
							curr_tm = localtime(&curr_time);

							strftime(date_string1, 50, "%d/%m/%Y", curr_tm);
							nueva_consulta.fecha_solicitado = date_string1;

							time_t curr_time2;
							tm* curr_tm2;
							time(&curr_time2);
							curr_tm2 = localtime(&curr_time2);

							curr_tm2->tm_year = 2023;
							curr_tm2->tm_mon = fecha_nuevo_turno->tm_mon;
							curr_tm2->tm_mday = fecha_nuevo_turno->tm_mday;

							strftime(date_string2, 50, "%d/%m/2023", curr_tm2); //ver
							nueva_consulta.fecha_turno = date_string2;
							nueva_consulta.matricula_med = medico_nueva_consulta->matricula;
							nueva_consulta.presento = false;

							cout << "Datos de la nueva consulta: " << endl;
							cout << "DNI del paciente: " << nueva_consulta.dni_pac << endl;
							cout << "Fecha en la cual se solicito el turno: " << nueva_consulta.fecha_solicitado << endl;
							cout << "Fecha del turno: " << nueva_consulta.fecha_turno << endl;
							cout << "Matricula del medico del proximo turno: " << nueva_consulta.matricula_med << endl;
							cout << "Se presento el paciente?: " << nueva_consulta.presento << endl;
							string nueva_obra = Verificar_Datos_Paciente(lista_pac[i]);
							cout << "Obra social nueva: " << nueva_obra << endl;


						}
						//else
							//cout << "Hubo problemas para asignar un medico con disponibilidad, volveremos a llamar al paciente en unos dias. " << endl;
					}
					else {
						cout << "El paciente no está interesado en obtener un nuevo turno en nuestro centro medico, archivamos su historial. " << endl;
						agregar_pacientes_archivados(lista_pac_archivados, lista_pac[i], &tam_lista_archivados);
						//aca habria que llamar a la funcion de archivar
					}

				}
				else {
					cout << "El paciente no ha respondido al llamado, procedemos a llamar a su contacto de emergencia con el fin de dar con el paciente. " << endl;
					contacto_paciente_a_llamar_emergencia = buscar_contacto_emergencia(lista_contactos, tam_contactos, lista_pac[i], contacto_paciente_a_llamar);

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

										nueva_consulta.dni_pac = lista_pac[i].dni;
										time_t curr_time;
										tm* curr_tm;
										char date_string1[100];
										char date_string2[100];

										time(&curr_time);
										curr_tm = localtime(&curr_time);

										strftime(date_string1, 50, "%d/%m/%Y", curr_tm);
										nueva_consulta.fecha_solicitado = date_string1;

										time_t curr_time2;
										tm* curr_tm2;
										time(&curr_time2);
										curr_tm2 = localtime(&curr_time2);

										curr_tm2->tm_year = 2023;
										curr_tm2->tm_mon = fecha_nuevo_turno->tm_mon;
										curr_tm2->tm_mday = fecha_nuevo_turno->tm_mday;

										strftime(date_string2, 50, "%d/%m/2023", curr_tm2);//ver
										nueva_consulta.fecha_turno = date_string2;

										nueva_consulta.matricula_med = medico_nueva_consulta->matricula;
										nueva_consulta.presento = false;

										cout << "Datos de la nueva consulta: " << endl;
										cout << "DNI del paciente: " << nueva_consulta.dni_pac << endl;
										cout << "Fecha en la cual se solicito el turno: " << nueva_consulta.fecha_solicitado << endl;
										cout << "Fecha del turno: " << nueva_consulta.fecha_turno << endl;
										cout << "Matricula del medico del proximo turno: " << nueva_consulta.matricula_med << endl;
										cout << "Se presento el paciente?: " << nueva_consulta.presento << endl;
										//guardamos la info en la lista de consultas
										//VER
										Verificar_Datos_Paciente(lista_pac[i]);
										//agregar_consultas(nueva_lista_auxiliar_consultas, nueva_consulta, &tam_lista_consultas_auxiliar);
										cout << "Obra social nueva: " << lista_pac[i].id_os << endl;
									}
									//else
									//	cout << "Hubo problemas para asignar un medico con disponibilidad, volveremos a llamar al paciente en unos dias. " << endl;
								}
								else {
									cout << "El paciente no está interesado en obtener un nuevo turno en nuestro centro medico, archivamos su historial. " << endl;
									agregar_pacientes_archivados(lista_pac_archivados, lista_pac[i], &tam_lista_archivados);
									//aca habria que llamar a la funcion de archivar
								}
							}
							else if (respuesta_estado_pac == 1) {
								lista_pac[i].estado = "fallecido";
								cout << "El paciente ha fallecido, archivamos su historial." << endl;
								agregar_pacientes_archivados(lista_pac_archivados, lista_pac[i], &tam_lista_archivados);
								//funcion de archivar

							}
							else {
								cout << "El contacto nos informa que el paciente se encuentra internado, modificamos el archivo y procedemos a llamar mas adelante" << endl;
								lista_pac[i].estado = "internado";
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
			else
				cout << "Ha ocurrido un error y no se ha podido encontrar información de contacto del paciente. " << endl;
		}
		else if (verificacion == 0) {
			cout << "El paciente se atendio hace mas de 10 años, es un paciente irrecuperable. Archivamos su historial. " << endl;
			agregar_pacientes_archivados(lista_pac_archivados, lista_pac[i], &tam_lista_archivados);
			//archivamos
		}
		else if (verificacion == 2)
			cout << "El paciente ya tiene un turno proximo. No hace falta llamar." << endl;
		else if (lista_pac[i].estado == "fallecido") {
			cout << "El paciente se encuentra fallecido, archivamos su historial. " << endl;
			agregar_pacientes_archivados(lista_pac_archivados, lista_pac[i], &tam_lista_archivados);
			//archivamos
		}
		else if (lista_pac[i].estado == "internado") {
			cout << "El paciente se encuentra internado en nuestro centro medico, llamamos mas adelante. " << endl;
		}
		else if (aux_ult_consulta.presento == true) {
			cout << "El paciente se presento a su ultimo turno, el cual fue hace menos de 10 años. No hace falta llamarlo." << endl;
		}


		//Asignar_Turno(lista[i], verificacion, lista2, lista1, &contador2, &contador3);

		tam_lista_filtrada_consultas = 0;

		//int aux3 = Encontrar_Consulta(lista_cons, lista[i], &contador6);
		//cout << "La consulta mas actual es: " << aux3 << endl;
		//contador6 = 0;
	}


	//crear_archivo_consultas_nuevas("Consultas_Nuevas.csv", nueva_lista_auxiliar_consultas, &tam_lista_consultas_auxiliar);

	//Consultas* lista_aux_cons = NULL;
	//lista_aux_cons = read_archivo_nuevas_consultas("Consultas_Nuevas.csv");
	//cout << "Leyendo nuevas consultas. " << endl;
	//for (int i = 0; i < tam_lista_consultas_auxiliar-1; i++) {
		//cout << "Dni paciente: " << lista_aux_cons[i].dni_pac << endl;
		//cout << "Fecha en la cual se solicito el nuevo turno: " << lista_aux_cons[i].fecha_solicitado << endl;
		//cout << "Fecha del turno: " << lista_aux_cons[i].fecha_turno << endl;
		//cout << "Matricula del medico: " << lista_aux_cons[i].matricula_med << endl;
		//cout << "Presento: " << lista_aux_cons[i].presento << endl;
	//}

	crear_archivo_pacientes_archivados("Pacientes_Archivados.csv", lista_pac_archivados, &tam_lista_archivados);

	Pacientes* lista_archivados;
	lista_archivados = read_archivo_pacientes_archivados("Pacientes_Archivados.csv");

	cout << "Leyendo pacientes archivados:" << endl;
	for (int i = 0; i < tam_lista_archivados; i++) {
		cout << lista_archivados[i].dni << "," << lista_archivados[i].nombre << "," << lista_archivados[i].apellido << "," << lista_archivados[i].sexo << "," << lista_archivados[i].natalicio << "," << lista_archivados[i].estado << "," << lista_archivados[i].id_os << endl;
	}

	Agregar_Archivado(lista_pac, lista_archivados, tam_pacientes, &tam_lista_archivados);

	crear_archivo_lista_pacientes_nueva("Pacientes_Nueva_Lista.csv", lista_pac, tam_pacientes);

	Pacientes* lista_nueva_pac1;
	lista_nueva_pac1 = read_archivo_lista_pacientes_nueva("Pacientes_Nueva_Lista.csv");

	cout << "Imprimiendo nueva lista con columna de archivado. " << endl;
	for (int i = 0; i < *tam_pacientes - 1; i++) {
		cout << lista_nueva_pac1[i].dni << "," << lista_nueva_pac1[i].nombre << "," << lista_nueva_pac1[i].apellido << " , " << lista_nueva_pac1[i].sexo << " , " << lista_nueva_pac1[i].natalicio << " , " << lista_nueva_pac1[i].estado << " , " << lista_nueva_pac1[i].id_os << " , " << lista_nueva_pac1[i].archivado << endl;
	}
}


/*
* /*cout << "El paciente desea asignar un turno con el medico que lo atendió en su ultima consulta?" << endl;
	int respuesta1 = rand() % 2;
	if (respuesta1 == 1) {//true
		cout << "El paciente quiere programar un turno con su antiguo medico. Procedemos a buscar al medico en la lista y verificar disponibilidad" << endl;
		Medicos* aux1;
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

				cout << "El paciente desea programar un turno con un nuevo médico. Procedemos a buscar al medico en la lista y verificar disponibilidad" << endl;

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
	}*/
/*
	Medicos* Buscar_Medico_Nuevo(Medicos* Lista_Medicos, Pacientes paciente, int tam) {

		Medicos* aux=NULL;
		for (int i = 0; i < tam; i++) {
			int respuesta_agenda_llena = rand() % 2;
			if (paciente.consulta.matricula_med != Lista_Medicos[i].matricula && Lista_Medicos[i].activo == true && respuesta_agenda_llena == false) { //chequeamos solo si encuentra ==matricula, hay que ver del boolean agenda_llena
				//le asigna el primer medico activo y que no sea el que lo haya atendido antes, tambien que sea de la especialidad que busca
				*aux = Lista_Medicos[i];
			}//habria que ver porque deberia fijarse si el medico tiene agenda llena o algo asi, entonces recorre la lista y se fija de asignar turno con el primer medico que encuentre
			else
				return NULL;
		}
		return aux;//retornamos el medico
	}

	Medicos* Buscar_Medico_Viejo(Medicos* Lista_Medicos, Pacientes paciente, int tam) {

		Medicos* aux=NULL;
		for (int i = 0; i < tam; i++) {
			if (paciente.consulta.matricula_med == Lista_Medicos[i].matricula && Lista_Medicos[i].activo == true) { //chequeamos solo si encuentra ==matricula, hay que ver del boolean agenda_llena
				//si encuentra al medico que lo habia atendido antes y este se encuentra disponible, misma especialidad???
				*aux = Lista_Medicos[i]; //encontramos al medico
			}
			else
				return NULL;
		}
		return aux;//retornamos el struct del medico, significa que se puede asignar turno con el medico
	}*/