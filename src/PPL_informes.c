/*
 * PPL_nexo.c
 *
 *  Created on: 12 oct. 2021
 *      Author: Compumar
 */
#include "PPL_informes.h"


void printPedidosPendientes(ePedido pedido[], int lenPedido, eClient cliente[], int lenCliente, eEstado estado[], int lenEstado)
{
    int i;
    printf("____________________________________________________________________________________________________________________\n");
    printf("                                           LISTADO DE PEDIDOS PENDIENTES                                            |\n");
    printf("____________________________________________________________________________________________________________________|\n");
    printf(" ID PEDIDO |  CUIT CLIENTE |        CALLE         |   ALTURA   |       LOCALIDAD      |   TOTAL KILOS   |   ESTADO  |\n");
    printf("___________|_______________|______________________|____________|______________________|_________________|___________|\n");
    for(i=0; i<lenPedido; i++)
    {
    	if(pedido[i].isEmpty == OCUPADO)
    	{
    		printPedidoPendiente(pedido[i], estado, lenEstado, cliente, lenCliente);
    	}
    }
}

void printPedidoPendiente(ePedido list, eEstado estado[], int lenEstado, eClient cliente[], int lenCliente)
{
	int i;
	int j;
	j = findClientById(cliente, lenCliente, list.idEmpresa);
	for (i = 0; i < lenEstado; ++i) {
		if(list.estado == PENDIENTE){
			if(list.estado == estado[i].estado){
						printf("---------------------------------------------------------------------------------------------------------------------\n");
						printf("   %6d  |  %11d  | %20s |   %6d   | %20s |      %6d     | %10s \n", list.idPedido ,cliente[j].cuit, cliente[j].direccion.street, cliente[j].direccion.altitude, cliente[j].localidad, list.kilos.kilosTotales, estado[i].descripcion);
						printf("---------------------------------------------------------------------------------------------------------------------\n");
						break;
			}
		}
	}
}




void printPedidosProcesados(ePedido pedido[], int lenPedido,eClient cliente[], int lenCliente, eEstado estado[], int lenEstado)
{
    int i;
	printf("\n______________________________________________________________________________________________________________________________________________________________\n");
    printf("                                                                     LISTADO DE PEDIDOS PROCESADOS                                                            |\n");
    printf("______________________________________________________________________________________________________________________________________________________________|\n");
    printf(" ID PEDIDO |  CUIT CLIENTE |          CALLE       |   ALTURA   |       LOCALIDAD      |  KILOS HDPE  |  KILOS LDPE  |  KILOS PP  |  TOTAL KILOS  |   ESTADO   |\n");
    printf("___________|_______________|______________________|____________|______________________|______________|______________|____________|_______________|____________|\n");
    for(i=0; i<lenPedido; i++)
    {
    	if(pedido[i].isEmpty == OCUPADO)
    	{
    		printPedidoProcesado(pedido[i], estado, lenEstado, cliente, lenCliente);
    	}
    }
}

void printPedidoProcesado(ePedido list, eEstado estado[], int lenEstado, eClient cliente[], int lenCliente)
{
	int i;
	int j;
	j = findClientById(cliente, lenCliente, list.idEmpresa);
	for (i = 0; i < lenEstado; ++i) {
		if(list.estado == PROCESADO)
		{
			if(list.estado == estado[i].estado){
					printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
					printf("   %6d  |  %11d  | %20s |   %6d   | %20s |    %6d    |    %6d    |   %6d   |    %6d     | %10s\n", list.idPedido ,cliente[j].cuit, cliente[j].direccion.street, cliente[j].direccion.altitude, cliente[j].localidad, list.kilos.kilosHDPE, list.kilos.kilosLPDE, list.kilos.kilosPP ,list.kilos.kilosTotalesProcesados, estado[i].descripcion);
					printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
					break;
			}
		}

	}
}

int cantPedidosPorLocalidad(ePedido pedido[], int lenPedido, eClient cliente[], int lenCliente, char localidad[])
{
	int contador;
	int i;
	int j;
	contador=0;

		for (i = 0; i < lenPedido; ++i) {
			if(pedido[i].estado == PENDIENTE){
				j = findClientById(cliente, lenCliente, pedido[i].idEmpresa);
					if(strcmp(cliente[j].localidad, localidad)==0){
						contador++;
					}
			}
		}
	return contador;
}

