/*
 * PPL_nexo.c
 *
 *  Created on: 12 oct. 2021
 *      Author: Compumar
 */
#include "PPL_informes.h"

/** \brief Muestra el contenido en la estructura de empleados
 *
 * \param Employee list[] = estructura de empleados
 * \param len = tamaño de estructura empleados.

 */
void printClients(eClient list[], int len)
{
    int i;
    printf("________________________________________________________________________________________________________________\n");
    printf("                                               LISTADO DE CLIENTES                                              |\n");
    printf("________________________________________________________________________________________________________________|\n");
    printf("   ID EMPRESA  |    NOMBRE EMPRESA    |     CUIT     |          CALLE       |   ALTURA   |       LOCALIDAD      |\n");
    printf("_______________|______________________|______________|______________________|____________|______________________|\n");
    for(i=0; i<len; i++)
    {
    	if(list[i].isEmpty == OCUPADO)
    	{
    		printClient(list[i]);
    	}
    }
}
/** \brief Muestra el contenido de un empleado
 *
 * \param Employee list[] = estructura de empleados

 */
void printClient(eClient list)
{
    printf("----------------------------------------------------------------------------------------------------------------\n");
    printf("     %4d      | %20s | %11d  | %20s |   %6d   | %20s  \n", list.idCompany, list.name, list.cuit, list.street, list.altitude, list.localidad);
    printf("----------------------------------------------------------------------------------------------------------------\n");
}

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
	for (i = 0; i < lenEstado; ++i) {
		if(list.estado == PENDIENTE)
		{
			if(list.estado == estado[i].estado){
				for (j = 0; j < lenCliente; ++j) {
					if(list.cuitCliente == cliente[j].cuit){
						printf("---------------------------------------------------------------------------------------------------------------------\n");
						printf("   %6d  |  %11d  | %20s |   %6d   | %20s |      %6d     | %10s \n", list.idPedido ,list.cuitCliente, cliente[j].street, cliente[j].altitude, cliente[j].localidad, list.kilosTotales, estado[i].descripcion);
						printf("---------------------------------------------------------------------------------------------------------------------\n");
						break;
					}
				}
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
	for (i = 0; i < lenEstado; ++i) {
		if(list.estado == PROCESADO)
		{
			if(list.estado == estado[i].estado){
				for (j = 0; j < lenCliente; ++j) {
					if(list.cuitCliente == cliente[j].cuit){
						printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
						printf("   %6d  |  %11d  | %20s |   %6d   | %20s |    %6d    |    %6d    |   %6d   |    %6d     | %10s\n", list.idPedido ,list.cuitCliente, cliente[j].street, cliente[j].altitude, cliente[j].localidad, list.kilosHDPE, list.kilosLPDE, list.kilosPP ,list.kilosTotalesProcesados, estado[i].descripcion);
						printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
						break;
					}
				}
			}
		}

	}
}

int cantPedidosPorLocalidad(ePedido pedido[], int lenPedido, char localidad[])
{
	int contador;
	int i;
	contador=0;
		for (i = 0; i < lenPedido; ++i) {
			if(pedido[i].estado == PENDIENTE){
					if(strcmp(pedido[i].localidad, localidad)==0){
						contador++;
					}
			}
		}
	return contador;
}
