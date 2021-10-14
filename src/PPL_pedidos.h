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
 char localidad[51];
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
ePedido addPedidoNew(int idNuevoPedido, int idCliente, int cuit, char localidad[]);
int addPedido(ePedido list[], int len, int idPedido, int cuitCliente, int idEmpresa, int kilosTotales, char localidad[]);
int findPedidoById(ePedido list[], int len,int id);
int addPedidoProcesado(ePedido list[], int id, int len,int kilosHDPE, int kilosLPDE, int kilosPP);
ePedido addPedidoNewProcesado();



#endif /* PPL_PEDIDOS_H_ */
