/*
 * PPL_pedidos.h
 *
 *  Created on: 12 oct. 2021
 *      Author: Compumar
 */
#include "PPL_inputs.h"

struct
{
 int estado;//PK
 char descripcion[20];
}typedef eEstado;

struct
{
 int kilosHDPE;
 int kilosLPDE;
 int kilosPP;
 int kilosTotales;
 int kilosTotalesProcesados;
}typedef eKilos;

struct
{
 int idEmpresa;
 int idPedido;
 eKilos kilos;
 int estado;//FK
 int isEmpty;
}typedef ePedido;

#ifndef PPL_PEDIDOS_H_
#define PPL_PEDIDOS_H_
int initPedidos(ePedido list[], int len);
int buscarLibrePedido(ePedido list[], int len);
ePedido addPedidoNew(int idNuevoPedido, int idCliente);
int addPedido(ePedido list[], int len, int idPedido, int idEmpresa, int kilosTotales);
int findPedidoById(ePedido list[], int len,int id);
int addPedidoProcesado(ePedido list[], int id, int len,int kilosHDPE, int kilosLPDE, int kilosPP);
ePedido addPedidoNewProcesado();



#endif /* PPL_PEDIDOS_H_ */
