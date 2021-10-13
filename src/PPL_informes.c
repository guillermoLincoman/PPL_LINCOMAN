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
    printf("     %4d     | %20s |  %11d  | %20s |   %6d   | %20s  \n", list.idCompany, list.name, list.cuit, list.street, list.altitude, list.localidad);
    printf("----------------------------------------------------------------------------------------------------------------\n");
}

void printPedidosPendientes(ePedido pedido[], int lenPedido, eClient cliente[], int lenCliente, eEstado estado[], int lenEstado)
{
    int i;
    printf("____________________________________________________________________________________________________________________\n");
    printf("                                           LISTADO DE PEDIDOS PENDIENTES                                            |\n");
    printf("____________________________________________________________________________________________________________________|\n");
    printf(" ID PEDIDO |  CUIT CLIENTE |          CALLE       |   ALTURA   |       LOCALIDAD      |   TOTAL KILOS   |   ESTADO  |\n");
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
						printf("--------------------------------------------------------------------------------------------------------------------\n");
						printf("   %6d  |  %11d  | %20s |   %6d   | %20s |      %6d     | %10s|\n", list.idPedido ,list.cuitCliente, cliente[j].street, cliente[j].altitude, cliente[j].localidad, list.kilosTotales, estado[i].descripcion);
						printf("--------------------------------------------------------------------------------------------------------------------\n");
						break;
					}
				}
			}
		}
	}
}


/** \brief Agrega a un estructura auxiliar los valores ingresados por el usuario
 * \param int idNuevoEmpleado id del nuevo empleado a cargar
 * \return Devuelve  una estructura cargada con los datos ingresados por el usuario
*/
ePedido addPedidoNewProcesado()
{
	printf("\nINGRESE EL NUEVO PEDIDO\n");
	printf("------------------------------------\n");
	ePedido nuevoPedido;
	nuevoPedido.kilosHDPE = cargarUnEntero("\nCantidad de kilos HDPE recolectado: Kg ", "\nError, ingrese una cantidad de kilos valida (maximo 1000 Kg): ", 0, 1000, 4);
	nuevoPedido.kilosLPDE = cargarUnEntero("\nCantidad de kilos LPDE recolectado: Kg ", "\nError, ingrese una cantidad de kilos valida (maximo 1000 Kg): ", 0, 1000, 4);
	nuevoPedido.kilosPP = cargarUnEntero("\nCantidad de kilos PP recolectado: Kg ", "\nError, ingrese una cantidad de kilos valida (maximo 1000 Kg ): ", 0, 1000, 4);
	nuevoPedido.estado = PROCESADO;
	printf("------------------------------------\n");
    return nuevoPedido;
}

int addPedidoProcesado(ePedido list[], int id, int len,int kilosHDPE, int kilosLPDE, int kilosPP)
{
	int i;

	i = findPedidoById(list, len, id);
	if(i != -1)
	{
		list[i].kilosHDPE = kilosHDPE;
		list[i].kilosLPDE = kilosLPDE;
		list[i].kilosPP = kilosPP;
		list[i].kilosTotalesProcesados=kilosHDPE + kilosLPDE + kilosPP;
		list[i].estado=PROCESADO;
	}else{
		printf("nose encontro");
	}


	return i;
}


void printPedidosProcesados(ePedido pedido[], int lenPedido,eClient cliente[], int lenCliente, eEstado estado[], int lenEstado)
{
    int i;
	printf("\n_____________________________________________________________________________________________________________________________________________________________\n");
    printf("                                                                     LISTADO DE PEDIDOS PROCESADOS                                                           |\n");
    printf("_____________________________________________________________________________________________________________________________________________________________|\n");
    printf(" ID PEDIDO |  CUIT CLIENTE |          CALLE       |   ALTURA   |       LOCALIDAD      |  KILOS HDPE  |  KILOS LDPE  |  KILOS PP  |  TOTAL KILOS  |   ESTADO  |\n");
    printf("___________|_______________|______________________|____________|______________________|______________|______________|____________|_______________|___________|\n");
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
						printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
						printf("   %6d  |  %11d  | %20s |   %6d   | %20s |    %6d    |    %6d    |   %6d   |    %6d     | %10s|\n", list.idPedido ,list.cuitCliente, cliente[j].street, cliente[j].altitude, cliente[j].localidad, list.kilosHDPE, list.kilosLPDE, list.kilosPP ,list.kilosTotalesProcesados, estado[i].descripcion);
						printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
						break;
					}
				}
			}
		}

	}
}
