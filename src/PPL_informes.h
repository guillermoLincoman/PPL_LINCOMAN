/*
 * PPL_nexo.h
 *
 *  Created on: 12 oct. 2021
 *      Author: Compumar
 */
#include "PPL_cliente.h"
#include "PPL_pedidos.h"
#ifndef PPL_NEXO_H_
#define PPL_NEXO_H_


void printClients(eClient list[], int len);
void printClient(eClient list);
void printPedidosPendientes(ePedido pedido[], int lenPedido,eClient cliente[], int lenCliente, eEstado estado[], int lenEstado);
void printPedidoPendiente(ePedido list, eEstado estado[], int lenEstado, eClient cliente[], int lenCliente);
void printPedidosProcesados(ePedido pedido[], int lenPedido, eClient cliente[], int lenCliente, eEstado estado[], int lenEstado);
void printPedidoProcesado(ePedido list, eEstado estado[], int lenEstado, eClient cliente[], int lenCliente);
int cantPedidosPorLocalidad(ePedido pedido[], int lenPedido, char localidad[]);
#endif /* PPL_NEXO_H_ */
