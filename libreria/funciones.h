#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <time.h>

using namespace std;

typedef struct Pacientes {

	unsigned int dni;
	string nombre;
	string apellido;
	char sexo;
	string natalicio;
	string estado;
	string id_os;
	//Contactos contacto;//tendria que tener 2? uno de emergencia y otra dle mismo paciente
	//Contactos contacto_de_emergencia;
	//Consultas consulta;//consulta asociada, lee la del paciente

}Pacientes;

typedef struct Medicos {

	string matricula;
	string nombre;
	string apellido;
	string telefono;
	string especialidad;
	bool activo;
} Medicos;

typedef struct Consultas {

	unsigned int dni_pac;
	string fecha_solicitado;
	string fecha_turno;
	bool presento;
	string matricula_med;
	//Medicos medico_consulta;

} Consultas;

typedef struct Contactos {

	unsigned int dni_pac;
	string telefono;
	string celular;
	string direccion;
	string mail;

} Contactos;

//funciones principales

//funciona
Medicos* Buscar_Medico_Viejo(Medicos* Lista_Medicos, Consultas* lista_consultas, int* contador6, int* tam);
//la idea de esta funcion es levantar el archivo de 
// la idea de esta funcion es levantar el archivo de medicos, fijarse si el medico que 
// habia atendido al paciente sigue trabajando en el hospital y ver si tiene disponibilidad 
// para agendar un nuevo turno. Una vez hecho eso, se asigna turno
// Habria que ver si usamos esta funcion dentro de asignar turno o viceversa

//funciona
Medicos* Buscar_Medico_Nuevo(Medicos* Lista_Medicos, Consultas* lista_consultas, int* contador6, int* tam);
// La idea de esta funcion es que si no se pudo asignar turno con el nuevo medico, 
// se busque en la lista de medicos al primer medico que tenga disponibilidad en 
// su agenda para un nuevo turno.
// Habria que ver si usamos esta funcion dentro de asignar turno o viceversa.

//funciona
bool Asignar_Medico(Medicos* Lista_Medicos, Consultas* lista_cons, int* contador6, int* contador3);
// La idea de la funcion asignar_turno es que reciba al paciente que desea asignar turno, que busque 
// al medico viejo o nuevo que tenga disponibilidad para asignarle su nueva consulta, una vez hecho 
// eso, tendriamos que recorrer la lista de pacientes_agenda y guardar el turno.

//terminar
void Llamar_Paciente(Pacientes* lista_pacientes, Consultas* lista_consultas, Contactos* lista_contactos, Medicos* lista_medicos);
// Esta funcion deberia recorrer la lista de pacientes, llamar al paciente, hacerle la pregunta de 
// si quiere nuevo turno para eso, llama a la funcion de asignar turno. Una vez asignado turno, 
// deberiamos borrar al paciente de la lista general.

//funciona
void Verificar_Datos_Paciente(Pacientes paciente_datos_verificar);
// Esta funcion deberia hacer el cuestionario de preguntas para ver si hubo 
// cambios en datos de paciente, como numero de telefono, obra social, etc.

//ya existe, mas abajo
Pacientes* archivar_pacientes(Pacientes*& lista_pac_a_archivar, int* contador5);
// Esta funcion es para los pacientes que se encuentran fallecidos o que ya 
// no desean atenderse en nuetro centro medico. Eliminar de la anterior lista y agregar a la nueva de archivados?

//terminar
void Llamar_Contacto_Emergencia(Pacientes paciente_contacto); 
// Sino se pudo contactar con el contacto de emergencia, si atiende preguntamos por paciente, sino atiende
// dejamos en stadby y volvemos a llamar luego!! respuesta random true or false


//sino se pudo contactar con el contacto de emerfenciientes por fecha�? es mas que sea mas facil encontrar a los
//que asistieron hace mas de 10 a�os por ejemplo.
//tambien podriamos ordenar las listas de pacientes por apellido?? o las de medicos tambien.
//ver qur funciones necesitamos para que facilite el algoritmo de busqueda de medicos a la hora de 
//asignar un turno al paciente

//funciones para agregar datos de archivos leidos
void agregar_pacientes(Pacientes*& lista_pac, Pacientes paciente, int* tamactual);

void agregar_medicos(Medicos*& lista_med, Medicos medico, int* tamactual);

void agregar_consultas(Consultas*& lista_cons, Consultas consulta, int* tamactual);

void agregar_contactos(Contactos*& lista_cont, Contactos contacto, int* tamactual);


//funciones para leer los archivos csv
Pacientes* read_archivo_pacientes(string a1, int* contador);

Medicos* read_archivo_medicos(string a1, int* contador);

Consultas* read_archivo_consultas(string a1, int* contador2);

Contactos* read_archivo_contactos(string a1, int* contador4);


//funciones para crear archivos
void agregar_pacientes_archivados(Pacientes*& lista_pac, Pacientes paciente, int* tamactual);
//ver si hace falta porque es igual a la de agregar pacientes, capaz es innecesaria

void crear_archivo_pacientes_archivados(string nombre_a1, Pacientes*& lista_pac_archivados, int* tamactual);

Pacientes* archivar_pacientes(Pacientes*& lista_pac_a_archivar, int* contador5);

Pacientes* read_archivo_pacientes_archivados(string a1);

//funciones
tm* toInt(string cadena);

Consultas* filtrar_lista_por_dni(Consultas* lista_consultas, Pacientes pac, int* tamactual, int* tam);

tm* Encontrar_Consulta(Consultas* lista_consultas_filtradas, Pacientes pac, int* tamactual);

Consultas encontrar_ultima_consulta(Consultas* lista_consultas_filtradas, int* tamactual);

bool Verificar_Anio_Ultima_Consulta(tm* fecha_ultima_consulta);