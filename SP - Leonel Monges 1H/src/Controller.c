/*
 * Controller.c
 *
 *  Created on: 1 dic. 2020
 *      Author: leo
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "LinkedList.h"
#include "Parser.h"
#include "Controller.h"
#include "Cliente.h"
#include "utn.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListCliente)
{
	int retorno = -1;
	FILE* pFile;

	if(path != NULL && pArrayListCliente != NULL)
	{
		pFile = fopen(path,"r");
		if(pFile != NULL)
		{
			parser_clienteFromText(pFile, pArrayListCliente);
			fclose(pFile);
			retorno = 0;
		}
		else
		{
			retorno = -2;
		}
	}
	return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addClienteToList(LinkedList* pArrayListCliente)
{
	int retorno = -1;
	Cliente* pCliente;

	if (pArrayListCliente != NULL)
	{
		pCliente = cli_addCliente(pArrayListCliente);
		if(pCliente != NULL)
		{
			if(ll_add(pArrayListCliente, pCliente) == 0)
			{
				retorno = 0;
			}
		}
	}

	return retorno;
}

/** \brief: Imprime la lista de clientes.
 * @param LinkedList* pArrayListCliente: Puntero a la lista.
 * @return 0 OK || -1 ERROR
 */
int controller_printListClientes(LinkedList* pArrayListCliente)
{
	int retorno = -1;

	cli_printCabezal();
	if(ll_map(pArrayListCliente, cli_printCliente) == 0)
	{
		retorno = 0;
	}

	return retorno;
}

/** \brief: Imprime la lista de clientes.
 * @param LinkedList* pArrayListCliente: Puntero a la lista.
 * @return 0 OK || -1 ERROR
 */
int controller_printCliente(LinkedList* pArrayListCliente, int id)
{
	int retorno = -1;
	int auxId;
	Cliente* pCliente;

	return retorno;
}



