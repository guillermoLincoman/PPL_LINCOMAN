/*
 * funcionesMenu.c
 *
 *  Created on: 6 oct. 2021
 *      Author: Compumar
 */
#include "PPL_funcionesMenu.h"

int iniciar(eClient list[], int len, ePedido pedido[], int lenPedido)
{
    int aux;
    int auxDos;
    int error;
    error=-1;
    aux=initClient(list, len);
    auxDos=initPedidos(pedido, lenPedido);
    if(aux==0 && auxDos == 0){
        error=0;
    }
    return error;
}

int agregarCliente(eClient list[], int len, int proxId)
{
    int aux;
    aux=-1;
    eClient auxCliente;
    if(list != NULL)
    {
    	auxCliente = addClientNew(proxId);
        aux=addClient(list, len, auxCliente.idCompany, auxCliente.name, auxCliente.cuit ,auxCliente.street, auxCliente.altitude, auxCliente.city, auxCliente.province, auxCliente.country);
        if(aux==0){
        	printf("\nCliente registrado con exito...\n");
            printf("\n________________________________________________________________________________________________________________________________________________________________\n");
            printf("  ID EMPRESA  |   NOMBRE EMPRESA  |     CUIT      |          CALLE         |   ALTURA   |         CIUDAD         |        PROVINCIA       |        PAIS         |\n");
            printf("______________|___________________|_______________|________________________|____________|________________________|________________________|_____________________|\n");
        	printClient(auxCliente);
        }else{
			printf("\nNo hay lugar disponible....\n\n");
        }
    }
    return aux;
}

int agregarPedido(eClient clientes[], int lenCliente, ePedido pedido[], int lenPedido, int idPedido, int ultimoIdCliente)
{
	int aux;
	int idCliente;
	aux=-1;

	if(clientes != NULL && pedido != NULL)
	{
		ePedido auxPedido;
		printClients(clientes, lenCliente);
		idCliente = cargarUnEntero("Ingrese el id del cliente: ", "Error, ingrese un id de cliente valido: ", 1000, ultimoIdCliente-1, 4);
		auxPedido = addPedidoNew(idPedido, idCliente);
		aux = addPedido(pedido, lenPedido, auxPedido.idEmpresa, auxPedido.idPedido, auxPedido.kilosHDPE, auxPedido.kilosLPDE, auxPedido.kilosPP, auxPedido.kilosNoReciclabes, auxPedido.kilosTotales);
		if(aux==0)
		{
        	printf("\nPedido registrado con exito...\n");
            printf("\n__________________________________________________________________________________________________________________\n");
            printf("  ID EMPRESA  |   ID PEDIDO  |  KILOS HDPE  |  KILOS LDPE  |  KILOS PP  |  KILOS NR  |  TOTAL KILOS  |   ESTADO   |\n");
            printf("______________|______________|______________|______________|____________|____________|_______________|____________|\n");
            printPedido(auxPedido);
		}
	}

	return aux;
}

void modifiCliente(eClient list[], int len, int ultimoId)
{
    int aux;
    if(list != NULL)
    {
    	aux = modificarCliente(list, len, ultimoId);
    	if(aux==-1){
    		printf("\nError, al modificar Cliente...\n");
    	}
    }
}

void eliminarCliente(eClient list[], int len, int ultimoId)
{
    int aux;
    if(list != NULL)
    {
    	aux = removeClient(list, len, ultimoId);
    	if(aux==-1){
    		printf("\nError, al eliminar Cliente...\n");
    	}
    }
}
