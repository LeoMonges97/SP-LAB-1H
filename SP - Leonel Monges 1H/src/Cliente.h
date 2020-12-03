/*
 * Cliente.h
 *
 *  Created on: 1 dic. 2020
 *      Author: leo
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#define LEN_NAME 20
#define LEN_CUIT 13
#include "LinkedList.h"

	typedef struct
	{
		int id;
		char nombre[LEN_NAME];
		char apellido[LEN_NAME];
		char cuit[LEN_CUIT];
	}Cliente;

	Cliente* cli_new();
	Cliente* cli_newParam(int id, char* nombre, char* apellido, char* cuit);
	Cliente* cli_newParamTxt(char* id, char* nombre, char* apellido, char* cuit);
	void cli_delete();
	int cli_setIdTxt(Cliente* this, char* id);
	int cli_getIdTxt(Cliente* this, char* id);
	int cli_setId(Cliente* this, int id);
	int cli_getId(Cliente* this, int* id);
	int cli_setNombre(Cliente* this, char* nombre);
	int cli_getNombre(Cliente* this, char* nombre);
	int cli_setApellido(Cliente* this, char* apellido);
	int cli_getApellido(Cliente* this, char* apellido);
	int cli_setCuit(Cliente* this, char* cuit);
	int cli_getCuit(Cliente* this, char* cuit);

	int cli_printCliente(void* pElemento);
	Cliente* cli_addCliente(LinkedList* pArrayListCliente);
	int cli_searchLastId(void* pElemento);
	int cli_newId(LinkedList* pArrayListCliente);
	Cliente cli_testCargaCliente(void);
	void cli_printCabezal(void);

#endif /* CLIENTE_H_ */
