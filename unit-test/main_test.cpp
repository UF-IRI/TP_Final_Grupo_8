#include "gmock/gmock.h"
#include "funciones.h"

namespace foobar::tests {

	TEST(ExampleTests, Example) {
		ASSERT_THAT(1, 1);
	}

	TEST(testfuncion, pruebaverficar_anio_ultima_consulta) {
		time_t t = time(0);
		tm* fecha = localtime(&t);
		fecha->tm_year = 2003;
		fecha->tm_mon = 3;
		fecha->tm_mday = 20;
		EXPECT_EQ(Verificar_Anio_Ultima_Consulta(fecha), 0);
	}

	TEST(testfuncion2, pruebaverficar_anio_ultima_consulta) {
		time_t t = time(0);
		tm* fecha = localtime(&t);
		fecha->tm_year = 2003;
		fecha->tm_mon = 3;
		fecha->tm_mday = 20;
		EXPECT_NE(Verificar_Anio_Ultima_Consulta(fecha), 1);
	}
	TEST(testfuncion3, pruebafecha_nuevo_turno_random) {
		time_t t = time(0);
		tm* fecha = localtime(&t);
		fecha->tm_year = 2003;
		fecha->tm_mon = 3;
		fecha->tm_mday = 20;
		EXPECT_NE(fecha_nuevo_turno_random(), fecha);
	}
	TEST(testfuncion4, pruebacrear_archivo_paciente_archivados) {
		int tamaño = 3;
		Pacientes* lista = new Pacientes[3];
		lista[0].apellido = "Almada";
		lista[0].archivado = "Archivado";
		lista[0].dni = 44798519;
		lista[0].estado = "n/c";
		lista[0].id_os = "Medicus";
		lista[0].natalicio = "16/04/2003";
		lista[0].nombre = "Melody";
		lista[0].sexo = 'F';

		lista[0].apellido = "Corso";
		lista[0].archivado = "Archivado";
		lista[0].dni = 44658478;
		lista[0].estado = "n/c";
		lista[0].id_os = "Osde";
		lista[0].natalicio = "20/03/2003";
		lista[0].nombre = "Pilar";
		lista[0].sexo = 'F';

		lista[0].apellido = "Lobos";
		lista[0].archivado = "Archivado";
		lista[0].dni = 446502451;
		lista[0].estado = "n/c";
		lista[0].id_os = "Medicus";
		lista[0].natalicio = "18/03/2003";
		lista[0].nombre = "Gonzalo";
		lista[0].sexo = 'M';

		EXPECT_TRUE(crear_archivo_pacientes_archivados("pacientes_archivados.csv", lista, &tamaño));
	}
	TEST(testfuncion5, pruebaVerificar_Datos_Paciente) {

		Pacientes paciente_datos_verificar;
		paciente_datos_verificar.id_os = Obras_SocialesToString(eObras_Sociales::Medicus);
		int respuesta1 = 1;
		int respuesta2 = 1;
		eObras_Sociales nuevo;

		if (respuesta1 == 1 && respuesta2 == 1 && paciente_datos_verificar.id_os == Obras_SocialesToString(eObras_Sociales::Medicus))
		{
			nuevo = eObras_Sociales::OSDE;
			paciente_datos_verificar.id_os = Obras_SocialesToString(nuevo);
		}
		EXPECT_THAT(Verificar_Datos_Paciente(paciente_datos_verificar), "IOSFA");
	}
	TEST(testfuncion6, pruebaObras_SocialesToString) {

		eObras_Sociales obras = eObras_Sociales::OSDE;
		EXPECT_THAT(Obras_SocialesToString(obras), "OSDE");
	}
	TEST(testfuncion7, pruebatoint) {
		string fecha = "11/11/2022";

		time_t t = time(0);
		tm* fecha2 = localtime(&t);

		fecha2->tm_year = 2022;
		fecha2->tm_mon = 11;
		fecha2->tm_mday = 11;

		EXPECT_THAT(toInt(fecha), fecha2);
	}
	TEST(testfuncion8, pruebamedico_viejo) {
		int tam = 5;
		int tam_med = 3;
		Medicos* Lista_Medicos = new Medicos[tam_med];

		Consultas* lista_consultas = new Consultas[tam];

		Lista_Medicos[0].activo = false;
		Lista_Medicos[0].apellido = "Gonzalez";
		Lista_Medicos[0].especialidad = "Nutricion";
		Lista_Medicos[0].telefono = "1145432455";
		Lista_Medicos[0].matricula = "2478547";
		Lista_Medicos[0].nombre = "Matias";

		Lista_Medicos[1].activo = true;
		Lista_Medicos[1].apellido = "Martinez";
		Lista_Medicos[1].especialidad = "Pediatria";
		Lista_Medicos[1].matricula = "2474514";
		Lista_Medicos[1].nombre = "Zahira";
		Lista_Medicos[1].telefono = "1145782202";

		Lista_Medicos[2].activo = true;
		Lista_Medicos[2].apellido = "Perez";
		Lista_Medicos[2].especialidad = "Ginecologia";
		Lista_Medicos[2].matricula = "2447102";
		Lista_Medicos[2].nombre = "Sol";
		Lista_Medicos[2].telefono = "1148754871";

		lista_consultas[0].dni_pac = 44798519;
		lista_consultas[0].fecha_solicitado = "22/11/2019";
		lista_consultas[0].fecha_turno = "12/1/2020";
		lista_consultas[0].matricula_med = "2447102";
		lista_consultas[0].presento = false;


		lista_consultas[0].dni_pac = 39410255;
		lista_consultas[0].fecha_solicitado = "1/9/2014";
		lista_consultas[0].fecha_turno = "12/11/2014";
		lista_consultas[0].matricula_med = "2478415";
		lista_consultas[0].presento = true;


		lista_consultas[0].dni_pac = 44798519;
		lista_consultas[0].fecha_solicitado = "9/3/2020";
		lista_consultas[0].fecha_turno = "15/5/2020";
		lista_consultas[0].matricula_med = "2478547";
		lista_consultas[0].presento = true;


		lista_consultas[0].dni_pac = 41454877;
		lista_consultas[0].fecha_solicitado = "10/4/2021";
		lista_consultas[0].fecha_turno = "8/8/2021";
		lista_consultas[0].matricula_med = "2478547";
		lista_consultas[0].presento = false;


		lista_consultas[0].dni_pac = 35898568;
		lista_consultas[0].fecha_solicitado = "10/12/2016";
		lista_consultas[0].fecha_turno = "17/1/2017";
		lista_consultas[0].matricula_med = "2474514";
		lista_consultas[0].presento = false;

		Medicos* medicoaux = new Medicos[1];
		medicoaux[0].activo = true;
		medicoaux[0].apellido = "Gonzalez";
		medicoaux[0].especialidad = "Nutricion";
		medicoaux[0].telefono = "1145432455";
		medicoaux[0].matricula = "2478547";
		medicoaux[0].nombre = "Matias";

		Medicos* aux = NULL;

		EXPECT_THAT(Buscar_Medico_Viejo(Lista_Medicos, lista_consultas, &tam_med, &tam), aux);
	}
}