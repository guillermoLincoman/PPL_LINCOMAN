/*
 * funcionesMenu.h
 *
 *  Created on: 6 oct. 2021
 *      Author: Compumar
 */
#include "PPL_informes.h"
#ifndef FUNCIONESMENU_H_
#define FUNCIONESMENU_H_

int iniciar(eClient list[], int len, ePedido pedido[], int lenPedido);
int agregarCliente(eClient list[], int len, int proxId);
void modifiCliente(eClient list[], int len, int ultimoId);
void eliminarCliente(eClient list[], int len, int ultimoId);
int agregarPedido(eClient clientes[], int lenCliente, ePedido pedido[], int lenPedido, eEstado estado[], int lenEstado, int idPedido, int ultimoIdCliente);
int procesarPedido(eClient clientes[], int lenCliente, ePedido pedido[], int lenPedido, eEstado estado[], int lenEstado, int idPedido);

#endif /* FUNCIONESMENU_H_ */
