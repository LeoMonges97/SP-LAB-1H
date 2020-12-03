/*
 * Controller.h
 *
 *  Created on: 1 dic. 2020
 *      Author: leo
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

	int controller_loadFromText(char* path , LinkedList* pArrayListCliente);
	int controller_addClienteToList(LinkedList* pArrayListCliente);
	int controller_printListClientes(LinkedList* pArrayListCliente);
	int controller_printCliente(LinkedList* pArrayListCliente, int index);

#endif /* CONTROLLER_H_ */
