#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//include fstream for file oprations
#include <fstream>
#include <string>
#include <ctime>
#include <time.h>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <chrono>
#include <iomanip>
using namespace std;

enum class eObras_Sociales { Medicus, OSDE, Italiano, Espanyol, Aleman, IOSFA };

string Obras_SocialesToString(eObras_Sociales obras);

typedef struct Medicos {

	string matricula;
	string nombre;
	string apellido;
	string telefono;
	string especialidad;
	bool activo;

} Medicos;

typedef struct Consultas {

	int dni_pac;
	string fecha_solicitado;
	string fecha_turno;
	bool presento;
	string matricula_med;

} Consultas;

typedef struct Contactos {

	int dni_pac;
	string telefono;
	string celular;
	string direccion;
	string mail;

} Contactos;

typedef struct Pacientes {

	unsigned int dni;
	string nombre;
	string apellido;
	char sexo;
	string natalicio;
	string estado;
	string id_os;
	string archivado;

}Pacientes;


void agregar_pacientes(Pacientes*& lista_pac, Pacientes paciente, int* tamactual);
void agregar_medicos(Medicos*& lista_med, Medicos medico, int* tamactual);

void agregar_consultas(Consultas*& lista_cons, Consultas consulta, int* tamactual);

void agregar_contactos(Contactos*& lista_cont, Contactos contacto, int* tamactual);

void agregar_consultas_extra(Consultas consulta, string a1, int* contador);
void agregar_pacientes_archivados(Pacientes*& lista_pac, Pacientes paciente, int* tamactual);

Pacientes* read_archivo_pacientes(string a1, int* contador);

Medicos* read_archivo_medicos(string a1, int* contador);

Consultas* read_archivo_consultas(string a1, int* contador2);

Contactos* read_archivo_contactos(string a1, int* contador4);

Pacientes* read_archivo_pacientes_archivados(string a1);

Pacientes* read_archivo_lista_pacientes_nueva(string a1);
//funciones para crear archivos
void crear_archivo_consultas_nuevas(string nombre_a1, Consultas*& lista_consultas_nuevas, int* tamactual);

void crear_archivo_nuevo_lista_verificados(string nombre_a1, Pacientes*& lista_pac, Consultas*& lista_cons, Contactos*& lista_contactos, int* tamactual, int* tam_consultas, int* tam_contactos);

void crear_archivo_lista_pacientes_nueva(string nombre_a1, Pacientes*& lista_pac, int* tamactual);

void crear_archivo_pacientes_archivados(string nombre_a1, Pacientes*& lista_pac_archivados, int* tamactual);


tm* toInt(string cadena);

Consultas* filtrar_lista_por_dni(Consultas* lista_consultas, Pacientes pac, int* tamactual, int* tam);

tm* Encontrar_Consulta_Fecha(Consultas* lista_consultas_filtradas, int* tamactual);

Consultas* encontrar_ultima_consulta(Consultas* lista_consultas_filtradas, int* tamactual);

Medicos* Buscar_Medico_Viejo(Medicos* Lista_Medicos, Consultas* lista_consultas, int* contador6, int* tam);

Medicos* Buscar_Medico_Nuevo(Medicos* Lista_Medicos, Consultas* lista_consultas, int* contador6, int* tam);

Pacientes* Buscar_Pacientes_Archivados(Pacientes* lista_pac, Pacientes pac_archivado_a_buscar, int* tam);

int Verificar_Anio_Ultima_Consulta(tm* fecha_ultima_consulta);

string Verificar_Datos_Paciente(Pacientes paciente_datos_verificar);

int verificar_estado_paciente(Pacientes paciente_a_verificar);

tm* fecha_nuevo_turno_random();

//funciones de verificacion

void Agregar_Archivado(Pacientes* lista_pac_antigua, Pacientes* lista_archivados, int* tam_ant, int* tam_arch);

Medicos* Asignar_Medico(Medicos* Lista_Medicos, Consultas* lista_cons, int* contador6, int* contador3);

Contactos* buscar_contacto_pac(Contactos* lista_contactos, int* tam_contactos, Pacientes pac_a_llamar);

Contactos* buscar_contacto_emergencia(Contactos* lista_contactos, int* tam_contactos, Pacientes pac_a_llamar, Contactos* contacto_pac);

void crear_archivo_nuevo_lista_verificados(string nombre_a1, Pacientes*& lista_pac, Consultas*& lista_cons, Contactos*& lista_contactos, int* tamactual, int* tam_consultas, int* tam_contactos);

int verificar_estado_paciente(Pacientes paciente_a_verificar);

int verificar_anio_2(tm* fecha_ultima_consulta);

//mas funciones
bool cambio_obra_social();

string fecha_de_hoy();

string fecha_turno(tm* fecha_turno);

string modificar_obra_social_paciente(Pacientes* lista_pac, Pacientes lista_pac_verificados, int* tam_pacientes);

void Imprimir_Datos_Consulta_Nueva(Consultas nueva_consulta, Pacientes* pac_a_modificar, int* contador, Pacientes* lista_pac);

void Imprimir_Datos_Consulta(Consultas consulta);

void Imprimir_Datos_Contacto(Contactos contacto);

void cambiar_estado_paciente(Pacientes* lista_pac, Pacientes lista_pac_verificados, int* tam_pacientes, string estado);

void Imprimir_Datos_Paciente(Pacientes paciente, int i);

void LLamado_Secretaria(Pacientes* lista_pac, int* tam_pacientes, Pacientes* lista_nueva_verificados, Consultas* lista_consultas, Contactos* lista_contactos, Medicos* lista_medicos, int* tam_pacientes_verificados, int* tam_consultas, int* tam_contactos, int* tam_medicos, Pacientes*& lista_pac_archivados, int* tam_lista_archivados);
//funcion de secretaria
Pacientes* filtrar_verificacion_pacientes(Pacientes* lista_pac, int* tam_pacientes, Consultas* lista_consultas, int* tam_consultas, Contactos* lista_contactos, int* tam_contactos, int* tam_lista_nueva_pacientes, Pacientes*& lista_pac_archivados, int* tam_lista_archivados);
//funciones principales

//funciona

//la idea de esta funcion es levantar el archivo de 
// la idea de esta funcion es levantar el archivo de medicos, fijarse si el medico que 
// habia atendido al paciente sigue trabajando en el hospital y ver si tiene disponibilidad 
// para agendar un nuevo turno. Una vez hecho eso, se asigna turno
// Habria que ver si usamos esta funcion dentro de asignar turno o viceversa

//funciona

// La idea de esta funcion es que si no se pudo asignar turno con el nuevo medico, 
// se busque en la lista de medicos al primer medico que tenga disponibilidad en 
// su agenda para un nuevo turno.
// Habria que ver si usamos esta funcion dentro de asignar turno o viceversa.

//funciona

// La idea de la funcion asignar_turno es que reciba al paciente que desea asignar turno, que busque 
// al medico viejo o nuevo que tenga disponibilidad para asignarle su nueva consulta, una vez hecho 
// eso, tendriamos que recorrer la lista de pacientes_agenda y guardar el turno.

//terminar
//void Llamar_Paciente(Pacientes* lista_pacientes, Consultas* lista_consultas, Contactos* lista_contactos, Medicos* lista_medicos);
// Esta funcion deberia recorrer la lista de pacientes, llamar al paciente, hacerle la pregunta de 
// si quiere nuevo turno para eso, llama a la funcion de asignar turno. Una vez asignado turno, 
// deberiamos borrar al paciente de la lista general.

//funciona
//const char*

//void Verificar_Datos_Paciente(Pacientes paciente_datos_verificar);
// Esta funcion deberia hacer el cuestionario de preguntas para ver si hubo 
// cambios en datos de paciente, como numero de telefono, obra social, etc.

//ya existe, mas abajo
//Pacientes* archivar_pacientes(Pacientes*& lista_pac_a_archivar, int* contador5);
// Esta funcion es para los pacientes que se encuentran fallecidos o que ya 
// no desean atenderse en nuetro centro medico. Eliminar de la anterior lista y agregar a la nueva de archivados?

// Sino se pudo contactar con el contacto de emergencia, si atiende preguntamos por paciente, sino atiende
// dejamos en stadby y volvemos a llamar luego!! respuesta random true or false


//sino se pudo contactar con el contacto de emerfenciientes por fecha�? es mas que sea mas facil encontrar a los
//que asistieron hace mas de 10 a�os por ejemplo.
//tambien podriamos ordenar las listas de pacientes por apellido?? o las de medicos tambien.
//ver qur funciones necesitamos para que facilite el algoritmo de busqueda de medicos a la hora de 
//asignar un turno al paciente

//funciones para agregar datos de archivos leidos


//funciones para leer los archivos csv



//funciones para crear archivos

//ver si hace falta porque es igual a la de agregar pacientes, capaz es innecesaria

//void crear_archivo_pacientes_archivados(string nombre_a1, Pacientes*& lista_pac_archivados, int* tamactual);


//Pacientes* archivar_pacientes(Pacientes*& lista_pac_a_archivar, int* contador5);


//funciones
