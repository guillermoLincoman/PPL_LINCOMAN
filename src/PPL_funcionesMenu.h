/*
 * funcionesMenu.h
 *
 *  Created on: 6 oct. 2021
 *      Author: Compumar
 */
#include "PPL_cliente.h"
#ifndef FUNCIONESMENU_H_
#define FUNCIONESMENU_H_

int iniciar(eClient list[], int len);
int agregarCliente(eClient list[], int len, int proxId);
void modifiCliente(eClient list[], int len, int ultimoId);
void eliminarCliente(eClient list[], int len, int ultimoId);
#endif /* FUNCIONESMENU_H_ */
