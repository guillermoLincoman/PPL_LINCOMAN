/*
 * funcionesMenu.h
 *
 *  Created on: 6 oct. 2021
 *      Author: Compumar
 */
#include "PPL_cliente.h"
#include "PPL_pedidos.h"
#ifndef FUNCIONESMENU_H_
#define FUNCIONESMENU_H_

int iniciar(eClient list[], int len, ePedido pedido[], int lenPedido);
int agregarCliente(eClient list[], int len, int proxId);
void modifiCliente(eClient list[], int len, int ultimoId);
void eliminarCliente(eClient list[], int len, int ultimoId);
int agregarPedido(eClient clientes[], int lenCliente, ePedido pedido[], int lenPedido, int idPedido, int ultimoIdCliente);
#endif /* FUNCIONESMENU_H_ */
