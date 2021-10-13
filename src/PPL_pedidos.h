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
 int cuitCliente;
 int kilosHDPE;
 int kilosLPDE;
 int kilosPP;
 int kilosTotales;
 int kilosTotalesProcesados;
 int estado;
 int isEmpty;
}typedef ePedido;

struct
{
 int estado;
 char descripcion[20];
}typedef eEstado;

#ifndef PPL_PEDIDOS_H_
#define PPL_PEDIDOS_H_
int initPedidos(ePedido list[], int len);
int buscarLibrePedido(ePedido list[], int len);
ePedido addPedidoNew(int idNuevoPedido, int idCliente, int cuit);
int addPedido(ePedido list[], int len, int idPedido, int cuitCliente, int idEmpresa, int kilosTotales);
int findPedidoById(ePedido list[], int len,int id);




#endif /* PPL_PEDIDOS_H_ */
