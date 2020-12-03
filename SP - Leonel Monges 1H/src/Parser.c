/*
 * Parser.c
 *
 *  Created on: 1 dic. 2020
 *      Author: leo
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Cliente.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_clienteFromText(FILE* pFile , LinkedList* pArrayListCliente)
{
	int retorno = -1;
	int lectura;

	Cliente* pCliente;
	char auxId[256];
	char auxNombre[256];
	char auxApellido[256];
	char auxCuit[256];

	if(pFile != NULL && pArrayListCliente != NULL)
	{
		do
		{
			lectura = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",
					auxId,
					auxNombre,
					auxApellido,
					auxCuit);

			if(lectura == 4)
			{
				pCliente = cli_newParamTxt(auxId,
						auxNombre,
						auxApellido,
						auxCuit);

				if(pCliente != NULL)
				{
					ll_add(pArrayListCliente, pCliente);
					retorno = 0;
				}
			}
			else
			{
				break;
			}
		}while(!feof(pFile));
	}

	return retorno;
}
