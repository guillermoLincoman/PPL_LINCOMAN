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
 int kilosTotales;
 int estado;
 int isEmpty;
}typedef ePedido;

#ifndef PPL_PEDIDOS_H_
#define PPL_PEDIDOS_H_
int initClient(eClient list[], int len);
int BuscarLibre(eClient list[], int len);
eClient addClientNew(int idNuevoCliente);



#endif /* PPL_PEDIDOS_H_ */
