/*
 ============================================================================
 Name        : SP.c
 Author      : Leonel Monges - 1H
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Cliente.h"
#include "utn.h"
#define OPCIONES_MENU 8
#define LEN_AFICHE 45
#define LEN_ZONA 20

/**
 * 	Una empresa de venta y colocación de afiches publicitarios en la vía pública requiere un sistema para
	administrar la venta de afiches. El mismo deberá tener un registro de clientes y de afiches vendidos y
	deberá ser capaz de resguardar su información en archivos de texto (clientes.txt y ventas.txt), por lo
	cual al iniciar, el programa se deberá crear una lista de clientes y una de ventas, leyendo los datos de
	los archivos para luego permitir realizar tanto la administración de los clientes como de las
	operaciones de ventas e informes. Contará con el siguiente menú:

	1) Agregar cliente: Se da de alta un cliente con nombre, apellido, y cuit. Se generará un ID único
	para este cliente que se imprimirá por pantalla si el alta es correcta. Se deberá dar un error si el
	cliente ya existe (cuit repetido)

	2) Vender afiches: Se pedirán los siguientes datos: ID de cliente, cantidad de afiches, nombre del
	archivo con la imagen del afiche y la zona donde se pegarán los afiches (CABA, ZONA SUR o ZONA
	OESTE). Se generará automáticamente un identificador numérico para la venta y se imprimirá en
	pantalla dicho ID en el caso de que los datos ingresados sean correctos. La venta quedará en un
	estado “a cobrar”. Mientras esté en este estado podrá ser modificada.

	3) Modificar venta: Se listarán todas las ventas en estado “a cobrar” (que son las que se pueden
	modificar) con todos sus campos. Se pedirá el ID de la venta y se imprimirá la información del cliente
	al que pertenece (nombre. Apellido y y cuit), luego se pedirá que se ingrese qué campo se quiere
	modificar y se deberá permitir modificarlo.

	4) Cobrar venta: Se listarán todas las ventas en estado “a cobrar” con todos sus campos. Se pedirá
	el ID de la venta y se imprimirá la información del cliente al que pertenece (nombre. Apellido y y cuit),
	luego se pedirá confirmación para cambiarse de estado y se cambiará al estado "Cobrada".

	5) Generar informe de cobros: Se generará un archivo ventas.txt con una lista de clientes con todos
	sus datos junto con la cantidad de ventas “cobradas” que posee.

	6) Generar informe de deudas: Se generará un archivo a_cobrar.txt con una lista de clientes con
	todos sus datos junto con la cantidad de ventas “a cobrar” que posee.

	7) Generar estadísticas: Se imprimirá por pantalla:
	. Cliente al que se le vendió mas afiches.
	. Cliente al que se le vendió menos afiches
	. Venta con mas afiches vendidos (indicar id de venta y cuit de cliente)
 * Calcular estos datos solo con las ventas “cobradas”
	Todos los cambios realizados (Altas, bajas y modificaciones) deben quedar guardados en los
	archivos correspondientes.
 *
 */

/*typedef struct
{
	int idCliente;
	int cantidadDeAfiches;
	char nombreArchivo[LEN_AFICHE];
	char zona[LEN_ZONA];
}Afiche;*/

int main(void)
{
	int opcion;
	int test;

	LinkedList* listaClientes = ll_newLinkedList(); // Creo la lista de clientes

	/****************************************************************************/
	// Zona de carga de archivo:

	test = controller_loadFromText("MOCK_DATA.txt", listaClientes);
	if(test == 0)
	{
		//flagArchivoCargado = 1;
		printf("\n . Archivo listo para cargar!");
	}
	else if(test == -1)
	{
		printf("\n [!] Error! No se pudo cargar el archivo!\n");
	}
	else
	{
		printf("\n [!] Error! El archivo no existe!\n");
	}

	/****************************************************************************/

	if(ll_isEmpty(listaClientes) == 0)
	{
		printf("\n . Contiene Informacion de Clientes.");
	}
	else
	{
		//flagVacio = 1;
		printf("\n . Listado vacio (sin clientes hasta el momento).");
	}

	do
	{
		utn_getInt("\n\n ********* SP - 1H (Leonel Monges) *********\n\n"
				" ~ Menu:\n\n"
				" 0. Imprimir lista.\n"
				" 1. Agregar cliente.\n"
				" 2. Vender afiches.\n"
				" 3. Modificar venta.\n"
				" 4. Cobrar venta.\n"
				" 5. Generar informe de cobros.\n"
				" 6. Generar informe de deudas.\n"
				" 7. Generar estadísticas.\n\n"
				" 8. Salir.\n\n"
				" ~ Ingrese la opcion a elegir: ","\n [!] Error!\n", &opcion, 2, 0, OPCIONES_MENU);
		switch(opcion)
		{
		case 0:
			if(controller_printListClientes(listaClientes) == 0)
			{
				printf("\n Clientes totales: %d", ll_len(listaClientes));
			}
			else
			{
				printf("\n [!] Error! No se pudo imprimir la lista!");
			}
			break;
		case 1:
			if(controller_addClienteToList(listaClientes) == 0)
			{
				printf("\n . Cliente añadido!");
			}
			else
			{
				printf("\n [!] Error! No se pudo guardar los datos!");
			}
			break;
		case 2:
			if(utn_getInt("\n . Ingrese el id a modificar: ", "\n [!] Error!\n", &test, 2, 1, 100) == 0)
			{
				controller_printCliente(listaClientes, test);
			}
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		}
	}while(opcion != OPCIONES_MENU);

	return EXIT_SUCCESS;
}
