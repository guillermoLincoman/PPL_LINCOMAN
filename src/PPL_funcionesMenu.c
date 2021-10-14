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
        aux=addClient(list, len, auxCliente.idCompany, auxCliente.name, auxCliente.cuit ,auxCliente.direccion.street, auxCliente.direccion.altitude, auxCliente.localidad);
        if(aux==0){
        	printf("\nCliente registrado con exito...\n");
            printf("________________________________________________________________________________________________________________\n");
            printf("   ID EMPRESA  |    NOMBRE EMPRESA    |     CUIT     |          CALLE       |   ALTURA   |       LOCALIDAD      |\n");
            printf("_______________|______________________|______________|______________________|____________|______________________|\n");
            printClient(auxCliente);
        }else{
			printf("\nNo hay lugar disponible....\n\n");
        }
    }
    return aux;
}

int agregarPedido(eClient clientes[], int lenCliente, ePedido pedido[], int lenPedido, eEstado estado[], int lenEstado, int idPedido, int ultimoIdCliente)
{
	int aux;
	int idCliente;
	aux=-1;

	if(clientes != NULL && pedido != NULL && estado != NULL)
	{
		printf("\nAGREGAR PEDIDO\n");
		printf("-------------------\n");

		ePedido auxPedido;
		printClients(clientes, lenCliente);
		idCliente = cargarUnEntero("Ingrese el id del cliente: ", "Error, ingrese un id de cliente valido: ", 1000, ultimoIdCliente-1, 4);
		auxPedido = addPedidoNew(idPedido, idCliente);
		aux = addPedido(pedido, lenPedido, auxPedido.idPedido, auxPedido.idEmpresa,auxPedido.kilos.kilosTotales);
		if(aux==0)
		{
        	printf("\nPedido registrado con exito...\n");
            printf("____________________________________________________________________________________________________________________\n");
            printf(" ID PEDIDO |  CUIT CLIENTE |          CALLE       |   ALTURA   |       LOCALIDAD      |   TOTAL KILOS   |   ESTADO  |\n");
            printf("___________|_______________|______________________|____________|______________________|_________________|___________|\n");
            printPedidoPendiente(auxPedido, estado, lenEstado, clientes, lenCliente);
		}
	}

	return aux;
}

int procesarPedido(eClient clientes[], int lenCliente, ePedido pedido[], int lenPedido, eEstado estado[], int lenEstado, int idPedido)
{
	int aux;
	int id;
	int i;
	aux = -1;

	if(clientes != NULL && pedido != NULL && estado != NULL)
	{
		printf("\nPROCESAR PEDIDO\n");
		printf("-----------------------\n");
		aux = 0;
		//1. muestro los pedidos pendienes
		printPedidosPendientes(pedido, lenPedido, clientes, lenCliente, estado, lenEstado);
		//2. Cargo el id del pedido que quiero modificar
		id = cargarUnEntero("Ingrese el id del pedido: ", "Error, ingrese un id de cliente valido: ", 1, idPedido-1, 4);
		ePedido auxPedido;
		auxPedido = addPedidoNewProcesado();
		i = addPedidoProcesado(pedido, id, lenPedido, auxPedido.kilos.kilosHDPE, auxPedido.kilos.kilosLPDE, auxPedido.kilos.kilosPP);
		printf("______________________________________________________________________________________________________________________________________________________________\n");
		printf(" ID PEDIDO |  CUIT CLIENTE |          CALLE       |   ALTURA   |       LOCALIDAD      |  KILOS HDPE  |  KILOS LDPE  |  KILOS PP  |  TOTAL KILOS  |   ESTADO   |\n");
		printf("___________|_______________|______________________|____________|______________________|______________|______________|____________|_______________|____________|\n");
		printPedidoProcesado(pedido[i], estado, lenEstado, clientes, lenCliente);

	}

	return aux;
}

void modifiCliente(eClient list[], int len, int ultimoId)
{
    int aux;
    if(list != NULL)
    {
		printf("\nMODIFICAR CLIENTE\n");
		printf("-----------------------\n");
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
		printf("\nELIMINAR CLIENTES\n");
		printf("-----------------------\n");
    	aux = removeClient(list, len, ultimoId);
    	if(aux==-1){
    		printf("\nError, al eliminar Cliente...\n");
    	}
    }
}


int informes(eClient clientes[], int lenCliente, ePedido pedido[], int lenPedido, eEstado estado[], int lenEstado, int idPedido, int ultimoIdCliente, int contPedidosPendientes, int contPedidosProcesados)
{

	int aux;
	float promedio;
	int opcion;
	char auxLocalidad[51];
	aux=-1;
	if(clientes != NULL && pedido != NULL && estado != NULL)
	{
		do{
			menuInformes();
	        opcion=cargarUnEntero("Elija una opcion: ", "Elija una opcion entre 0 y 2: ", 0, 2, 4);

	        switch(opcion)
	        {
	        	case 1:
	        		if(contPedidosPendientes>0)
	        		{
		    			printPedidosPendientes(pedido, lenPedido, clientes, lenCliente, estado, lenEstado);
		    			getUsuario(auxLocalidad, "Ingrese una localidad: ", "Error, ingrese una localidad valida(maximo 51 caracteres): ", 1, 51, 4);
		    			aux = cantPedidosPorLocalidad(pedido, lenPedido, clientes, lenCliente, auxLocalidad);
		    			if(aux > 0)
		    			{
			    			printf("\nLa localidad %s tiene %d pedidos pendientes\n", auxLocalidad, aux);
		    			}else{
			    			printf("\nLa localidad %s no existe o no tiene pedidos pendientes....\n", auxLocalidad);
		    			}
	        		}else{
	                    printf("\nNo hay pedidos pendientes...\n");
	        		}

	        		limpiar();
	    			break;
	        	case 2:
	        		if(contPedidosProcesados>0)
	        		{

	        			promedio = cantPoliReciPromPorCliente(pedido, lenPedido, clientes, lenCliente, estado, lenEstado);
		    			printf("\n El promedio de kilos de polipropileno reciclado por cliente es  %.2f \n", promedio);

	        		}else{
	                    printf("\nAun no hay pedidos procesados...\n");
	        		}
	        		limpiar();
	    			break;
	        }

		}while(opcion != 0);


	}

	return aux;
}
