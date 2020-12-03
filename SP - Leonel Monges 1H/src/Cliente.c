/*
 * Cliente.c
 *
 *  Created on: 1 dic. 2020
 *      Author: leo
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "Cliente.h"
#include "validaciones.h"
#include "utn.h"
#define SIZE_AUX 30

static int isValidId(int id);
static int isValidNombre(char* nombre);
static int isValidApellido(char* apellido);
static int isValidCuit(char* cuit);

/** \brief isValidId(): Valida el atributo id de la entidad Cliente.
 * @param int id: campo id de la entidad Cliente a validar.
 * @return (1) OK || (0) Error
 */
static int isValidId(int id)
{
	int retorno = 0;
	char auxId[SIZE_AUX];
	if(id > 0)
	{
		snprintf(auxId, SIZE_AUX, "%d", id);
		if(esNumerica(auxId) == 1)
		{
			retorno = 1;
		}
	}
	return retorno;
}

/** \brief isValidNombre(): Valida el atributo nombre de la entidad Cliente.
 * @param char* nombre: campo nombre de la entidad Cliente a validar.
 * @return (1) OK || (0) Error
 */
static int isValidNombre(char* nombre)
{
	int retorno = 0;
	if(nombre != NULL)
	{
		if(esNombreValido(nombre, SIZE_AUX) == 1)
		{
			retorno = 1;
		}
	}
	return retorno;
}

/** \brief isValidApellido(): Valida el atributo apellido de la entidad Cliente.
 * @param char* apellido: campo apellido de la entidad Cliente a validar.
 * @return (1) OK || (0) Error
 */
static int isValidApellido(char* apellido)
{
	int retorno = 0;
	if(apellido != NULL)
	{
		if(esNombreValido(apellido, SIZE_AUX) == 1)
		{
			retorno = 1;
		}
	}
	return retorno;
}

/** \brief isValidCuit(): Valida el atributo cuit de la entidad Cliente.
 * @param char* cuit: campo cuit de la entidad Cliente a validar.
 * @return (1) OK || (0) Error
 */
static int isValidCuit(char* cuit)
{
	int retorno = 0;
	if(cuit != NULL)
	{
		if(esCuit(cuit) == 1)
		{
			retorno = 1;
		}
	}
	return retorno;
}

// ***************************************************************************************************************************************************//
// Contructor & Destructor

/** \brief cli_new(): Reserva memoria dinámica para un elemento de la entidad Cliente.
 * @return el puntero de la entidad Cliente que se construyo.
 */
Cliente* cli_new(void)
{
	return (Cliente*) malloc (sizeof(Cliente));
}

/** \brief cli_newParam(): Reserva memoria dinámica para un elemento de la entidad Cliente y
 *        dando valores iniciales a los campos de dicha entidad.
 * @param int id: campo id de la entidad Cliente.
 * @param char* nombre: campo nombre de la entidad Cliente.
 * @param char* apellido: campo apellido de la entidad Cliente.
 * @param char* cuit: campo cuit de la entidad Cliente.
 * @return el puntero de la entidad Cliente que se construyo || NULL en caso de no realizarlo.
 */
Cliente* cli_newParam(int id, char* nombre, char* apellido, char* cuit)
{
	Cliente* this = cli_new();
	if(this != NULL)
	{
		if(
				!(cli_setId(this, id)) &&
				!(cli_setNombre(this, nombre)) &&
				!(cli_setApellido(this, apellido)) &&
				!(cli_setCuit(this, cuit))
		)
		{
			return this;
		}
	}
	return NULL;
}

/** \brief cli_newParamTxt(): Reserva memoria dinámica para un elemento de la entidad Cliente y
 *        dando valores iniciales a los campos de dicha entidad (mejor acceso a archivos de texto).
 * @param char* id: campo id de la entidad Cliente.
 * @param char* nombre: campo nombre de la entidad Cliente.
 * @param char* apellido: campo horasTrabajadas de la entidad Cliente.
 * @param char* cuit: campo sueldo de la entidad Cliente.
 * @return el puntero de la entidad Cliente que se construyo || NULL en caso de no realizarlo.
 */
Cliente* cli_newParamTxt(char* id, char* nombre, char* apellido, char* cuit)
{
	//return employee_newParam(atoi(id), nombre, atoi(horasTrabajadas), atoi(sueldo));
	Cliente* this = cli_new();

	if(this != NULL && id != NULL && nombre != NULL && apellido != NULL && cuit != NULL)
	{
		if(
				cli_setIdTxt(this, id) == -1 ||
				cli_setNombre(this, nombre) == -1 ||
				cli_setApellido(this, apellido) == -1 ||
				cli_setCuit(this, cuit) == -1
		)
		{
			cli_delete(this);
			this = NULL;
		}
	}
	return this;
}

/** \brief cli_delete(): Libera la memoria previamente reservada.
 */
void cli_delete(Cliente* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

// ***************************************************************************************************************************************************//
// Set & Get del atributo: id

/** \brief cli_setIdTxt(): Permite asignar un valor validado al campo id de la entidad Cliente (mejor acceso a archivos de texto).
 * @param Cliente* this: El puntero al elemento de la entidad Cliente al que se le desea setear el atributo id.
 * @param char* id: Es el valor del atributo id (como cadena de carateres) que se desea setear.
 * @return (0) OK / (-1) Error
 */
int cli_setIdTxt(Cliente* this, char* id)
{
	int retorno = -1;
	if(this != NULL  && id != NULL)
	{
		if(esNumerica(id))
		{
			this->id = atoi(id);
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief cli_getIdTxt(): Permite obtener/acceder al valor del atributo id de la entidad Cliente (mejor acceso a archivos de texto).
 * @param Cliente* this: El puntero al elemento de la entidad Employee al que se le desea leer el atributo id.
 * @param char* id: Es el puntero a ser utilizado para retornar el valor del atributo id.
 * @return (0) OK / (-1) Error
 */
int cli_getIdTxt(Cliente* this, char* id)
{
	int retorno = -1;
	if(this != NULL  && id != NULL)
	{
		retorno = 0;
		snprintf(id,(int)sizeof(this->id),"%d",this->id);
	}
	return retorno;
}

/** \brief cli_setId(): Permite asignar un valor validado a un campo de la entidad Cliente.
 * @param Cliente* this: El puntero al elemento de la entidad Cliente al que se le desea setear el atributo id.
 * @param int id: Es el valor del atributo id que se desea setear.
 * @return (0) OK / (-1) Error
 */
int cli_setId(Cliente* this, int id)
{
	int retorno = -1;
	if(this != NULL  && id > 0)
	{
		if(isValidId(id))
		{
			this->id = id;
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief cli_getId(): Permite obtener/acceder al valor del atributo id de la entidad Cliente.
 * @param Cliente* this: El puntero al elemento de la entidad Cliente al que se le desea leer el atributo id.
 * @param int id: Es el puntero a ser utilizado para retornar el valor del atributo id.
 * @return (0) OK / (-1) Error
 */
int cli_getId(Cliente* this, int* id)
{
	int retorno = -1;
	if(this != NULL  && id != NULL)
	{
		retorno = 0;
		*id = this->id;
	}
	return retorno;
}

// ***************************************************************************************************************************************************//
// Set & Get del atributo: nombre

/** \brief cli_setNombre(): Permite asignar un valor validado a un campo de la entidad Cliente.
 * @param Cliente* this: El puntero al elemento de la entidad Cliente al que se le desea setear el atributo nombre.
 * @param char* nombre: Es el valor del atributo nombre que se desea setear.
 * @return (0) OK / (-1) Error
 */
int cli_setNombre(Cliente* this, char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		if(isValidNombre(nombre))
		{
			strncpy(this->nombre, nombre, (int)sizeof(this->nombre));
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief cli_getNombre(): Permite obtener/acceder al valor del atributo nombre de la entidad Cliente.
 * @param Cliente* this: El puntero al elemento de la entidad Cliente al que se le desea leer el atributo nombre.
 * @param char* nombre: Es el puntero a ser utilizado para retornar el valor del atributo nombre.
 * @return (0) OK / (-1) Error
 */
int cli_getNombre(Cliente* this, char* nombre)
{
	int retorno = -1;
	if(this != NULL  && nombre != NULL)
	{
		retorno = 0;
		strncpy(nombre, this->nombre, (int)sizeof(this->nombre));
	}
	return retorno;
}

// ***************************************************************************************************************************************************//
// Set & Get del atributo: apellido

/** \brief cli_setApellido(): Permite asignar un valor validado a un campo de la entidad Cliente.
 * @param Cliente* this: El puntero al elemento de la entidad Cliente al que se le desea setear el atributo apellido.
 * @param char* apellido: Es el valor del atributo apellido que se desea setear.
 * @return (0) OK / (-1) Error
 */
int cli_setApellido(Cliente* this, char* apellido)
{
	int retorno = -1;
	if(this != NULL && apellido != NULL)
	{
		if(isValidApellido(apellido))
		{
			strncpy(this->apellido, apellido, (int)sizeof(this->apellido));
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief cli_getNombre(): Permite obtener/acceder al valor del atributo nombre de la entidad Cliente.
 * @param Cliente* this: El puntero al elemento de la entidad Cliente al que se le desea leer el atributo apellido.
 * @param char* apellido: Es el puntero a ser utilizado para retornar el valor del atributo apellido.
 * @return (0) OK / (-1) Error
 */
int cli_getApellido(Cliente* this, char* apellido)
{
	int retorno = -1;
	if(this != NULL  && apellido != NULL)
	{
		retorno = 0;
		strncpy(apellido, this->apellido, (int)sizeof(this->apellido));
	}
	return retorno;
}

// ***************************************************************************************************************************************************//
// Set & Get del atributo: cuit

/** \brief cli_setCuit(): Permite asignar un valor validado a un campo de la entidad Cliente.
 * @param Cliente* this: El puntero al elemento de la entidad Cliente al que se le desea setear el atributo cuit.
 * @param char* cuit: Es el valor del atributo cuit que se desea setear.
 * @return (0) OK / (-1) Error
 */
int cli_setCuit(Cliente* this, char* cuit)
{
	int retorno = -1;
	if(this != NULL && cuit != NULL)
	{
		if(isValidCuit(cuit))
		{
			strncpy(this->cuit, cuit, (int)sizeof(this->cuit));
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief cli_getCuit(): Permite obtener/acceder al valor del atributo nombre de la entidad Cliente.
 * @param Cliente* this: El puntero al elemento de la entidad Cliente al que se le desea leer el atributo cuit.
 * @param char* cuit: Es el puntero a ser utilizado para retornar el valor del atributo cuit.
 * @return (0) OK / (-1) Error
 */
int cli_getCuit(Cliente* this, char* cuit)
{
	int retorno = -1;
	if(this != NULL  && cuit != NULL)
	{
		retorno = 0;
		strncpy(cuit, this->cuit, (int)sizeof(this->cuit));
	}
	return retorno;
}

// ***************************************************************************************************************************************************//
// Funciones de la Entidad Cliente

/** \brief cli_searchLastId(): Cabezal de la lista de Clientes.
 */
void cli_printCabezal(void)
{
	printf("\n |  ID |      NOMBRE     |     APELLIDO    |      CUIT     |\n");
	printf(" |-----|-----------------|-----------------|---------------| \n");
}

/** \brief cli_newId(): Genera un nuevo id.
 * @param LinkedList* pArrayListCliente: Puntero a la lista.
 * @return (Valor de id) OK || (-1) Error
 */
int cli_newId(LinkedList* pArrayListCliente)
{
	int retorno = -1;
	int aux;

	aux = ll_mapAndReturnerInt(pArrayListCliente, cli_searchLastId);
	if(aux > -1)
	{
		retorno = aux;
	}

	return retorno;
}

/** \brief cli_searchLastId(): Funcion criterio para buscar el ultimo id y retornarlo.
 * @param void* pElemento: Puntero al elemento.
 * @return (Valor encontrado de id) OK || (-1) Error
 */
int cli_searchLastId(void* pElemento)
{
	int retorno = -1;
	int auxId;
	int maxId = 0;

	Cliente* pCliente;
	pCliente = (Cliente*) pElemento;

	if(pCliente != NULL)
	{
		cli_getId(pCliente, &auxId);

		if (auxId == 0 || auxId > maxId)
		{
			maxId = auxId;
			retorno = maxId + 1;
		}
	}

	return retorno;
}

/** \brief cli_printCliente(): Funcion crierio para imprimir los clientes.
 * @param void* pElemento: Puntero al elemento.
 * @return 0 OK || -1 ERROR
 */
int cli_printCliente(void* pElemento)
{
	int retorno = -1;

	Cliente* pCliente;
	pCliente = (Cliente*) pElemento;

	//int auxId;
	//char auxNombre[20];
	//char auxApellido[20];
	//char auxCuit[13];

	if(pCliente != NULL)
	{
		printf(" | %3d | %15s | %15s | %13s |\n",
				pCliente->id,
				pCliente->nombre,
				pCliente->apellido,
				pCliente->cuit);
		retorno = 0;

		/*if(		cli_getId(pCliente,&auxId) == 0 &&
				cli_getNombre(pCliente,auxNombre) == 0 &&
				cli_getApellido(pCliente,auxApellido) == 0 &&
				cli_getCuit(pCliente,auxCuit) == 0)
		{
			printf(" | %3d | %15s | %15s | %13s |\n",
					auxId,
					auxNombre,
					auxApellido,
					auxCuit);
			retorno = 0;
		}*/
	}

	return retorno;
}

/** \brief cli_addCliente(): Controla la carga del cliente para devolverlo directamente cargado en un puntero Cliente*
 *
 * @param LinkedList* pArrayListCliente: Puntero a la lista.
 * @return Puntero Cliente* || -1 ERROR
 */
Cliente* cli_addCliente(LinkedList* pArrayListCliente)
{
	Cliente* retorno = NULL;
	Cliente* pCliente = NULL;
	Cliente auxCliente;
	int opcion;

	if(pArrayListCliente != NULL)
	{
		pCliente = cli_new();

		if(utn_getCuilOrCuit(auxCliente.cuit, 2) == 0 &&
				utn_getNombre("\n . Ingrese Nombre: "," [!] Error!\n", auxCliente.nombre, 2, sizeof(auxCliente.nombre)) == 0 &&
				utn_getNombre("\n . Ingrese Apellido: "," [!] Error!\n", auxCliente.apellido, 2, sizeof(auxCliente.apellido)) == 0)
		{
			auxCliente.id = cli_newId(pArrayListCliente);
			cli_printCabezal();
			printf(" | %3d | %15s | %15s | %13s |\n",auxCliente.id, auxCliente.nombre,auxCliente.apellido,auxCliente.cuit);

			if(utn_getInt("\n . Desea agregar estos datos del nuevo usuario?\n\n"
					" . 1 - Si\n"
					" . 2 - No\n\n"
					" > Ingrese su opcion: ", "Error che!", &opcion, 2, 1, 2) == 0)
			{
				if(opcion == 1)
				{
					if(cli_setNombre(pCliente, auxCliente.nombre) == 0 &&
							cli_setApellido(pCliente, auxCliente.apellido) == 0 &&
							cli_setCuit(pCliente, auxCliente.cuit) == 0 &&
							cli_setId(pCliente, auxCliente.id) == 0)
					{
						retorno = pCliente;
					}
				}
				else
				{
					printf(" . OK, no se han guardado los datos...");
					cli_delete(pCliente);
				}
			}
		}

	}

	return retorno;
}


