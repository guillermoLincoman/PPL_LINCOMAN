/*
 * PPL_pedidos.h
 *
 *  Created on: 12 oct. 2021
 *      Author: Compumar
 */
#include "PPL_inputs.h"

struct
{
 int idEmpresa;
 int idPedido;
 int kilosHDPE;
 int kilosLPDE;
 int kilosPP;
 int kilosNoReciclabes;
 int kilosTotales;
 int estado;
 int isEmpty;
}typedef ePedido;

#ifndef PPL_PEDIDOS_H_
#define PPL_PEDIDOS_H_
int initPedidos(ePedido list[], int len);
int buscarLibrePedido(ePedido list[], int len);
ePedido addPedidoNew(int idNuevoPedido, int idCliente);
int addPedido(ePedido list[], int len, int idEmpresa, int idPedido, int kilosHDPE, int kilosLPDE, int kilosPP, int kilosNoReciclabes, int kilosTotales);
void printPedidos(ePedido list[], int len);
void printPedido(ePedido list);



#endif /* PPL_PEDIDOS_H_ */
