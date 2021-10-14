/*
 * PPL_nexo.c
 *
 *  Created on: 12 oct. 2021
 *      Author: Compumar
 */
#include "PPL_informes.h"

/** \brief Muestra todos los Pedidos pendientes cargados
 *
 * \param ePedido pedido[] = Estructura de Pedido
 * \param lenPedido = Tamaño de estructura Pedido.
 * \param eClient cliente[] = Estructura de Clientes
 * \param lenCliente = Tamaño de estructura Clientes.
 * \param eEstado estado[] = Estructura de Estado
 * \param lenEstado = Tamaño de estructura Estado.
 */
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

/** \brief Muestra un Pedido pendiente
 *
 * \param eClient Cliente = Estructura de Cliente a imprimir
 * \param eEstado Estado = Estructura de Estado a imprimir
 * \param ePedido Pedido = Estructura de Pedido a imprimir

 */
void printPedidoPendiente(ePedido list, eEstado estado[], int lenEstado, eClient cliente[], int lenCliente)
{
	int i;
	int j;
	j = findClientById(cliente, lenCliente, list.idEmpresa);
	for (i = 0; i < lenEstado; ++i) {
		if(list.estado == PENDIENTE){
			if(list.estado == estado[i].estado){
						printf("---------------------------------------------------------------------------------------------------------------------\n");
						printf("   %6d  |  %11d  | %20s |   %6d   | %20s |      %6d     | %10s \n", list.idPedido ,cliente[j].cuit, cliente[j].direccion.street, cliente[j].direccion.altitude, cliente[j].location.localidad, list.kilos.kilosTotales, estado[i].descripcion);
						printf("---------------------------------------------------------------------------------------------------------------------\n");
						break;
			}
		}
	}
}

/** \brief Muestra todos los Pedidos Procesados cargados
 *
 * \param ePedido pedido[] = Estructura de Pedido
 * \param lenPedido = Tamaño de estructura Pedido.
 * \param eClient cliente[] = Estructura de Clientes
 * \param lenCliente = Tamaño de estructura Clientes.
 * \param eEstado estado[] = Estructura de Estado
 * \param lenEstado = Tamaño de estructura Estado.
 */
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

/** \brief Muestra un Pedido Procesado
 *
 * \param eClient Cliente[] = Estructura de Cliente a imprimir
 * \param int lenCliente = Tamaño de estructura Cliente
 * \param eEstado Estado[] = Estructura de Estado a imprimir
 * \param int lenEstado = Tamaño de estructura Estado
 * \param ePedido Pedido = Estructura de Pedido a imprimir

 */
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
					printf("   %6d  |  %11d  | %20s |   %6d   | %20s |    %6d    |    %6d    |   %6d   |    %6d     | %10s\n", list.idPedido ,cliente[j].cuit, cliente[j].direccion.street, cliente[j].direccion.altitude, cliente[j].location.localidad, list.kilos.kilosHDPE, list.kilos.kilosLPDE, list.kilos.kilosPP ,list.kilos.kilosTotalesProcesados, estado[i].descripcion);
					printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
					break;
			}
		}

	}
}

/** \brief Obtiene la cantidad de pedidos segun la localidad recibida
 *
 * \param ePedido Pedido[] = Estructura de Pedido
 * \param int lenPedido = Tamaño de estructura Pedido
 * \param eClient cliente[] = Estructura de Estado
 * \param int lenCliente = Tamaño de estructura Estado
 * \param char localidad[] = localidad recibida para comparar
 *
 * \return Retorna la cantidad de pedidos por localidad
 */
int cantPedidosPorLocalidad(ePedido pedido[], int lenPedido, eClient cliente[], int lenCliente, char localidad[])
{
	int contador;
	int i;
	int j;
	contador=0;

		for (i = 0; i < lenPedido; ++i) {
			if(pedido[i].estado == PENDIENTE){
				j = findClientById(cliente, lenCliente, pedido[i].idEmpresa);
					if(strcmp(cliente[j].location.localidad, localidad)==0){
						contador++;
					}
			}
		}
	return contador;
}

/** \brief Obtiene el promedio de kilos de Polipropileno por cliente
 *
 * \param ePedido Pedido[] = Estructura de Pedido
 * \param int lenPedido = Tamaño de estructura Pedido
 * \param eClient cliente[] = Estructura de Cliente
 * \param int lenCliente = Tamaño de estructura Cliente
 * \param eEstado estado[] = Estructura de Estado
 * \param int lenEstado = Tamaño de estructura Estado
 *
 * \return Retorna el promedio de kilos de Polipropileno por cliente
 */
int cantPoliReciPromPorCliente(ePedido pedido[], int lenPedido, eClient cliente[], int lenCliente, eEstado estado[], int lenEstado)
{
	int cantClientes;
	int cantKilos;
	float prom;

	if(pedido != NULL && cliente != NULL && estado != NULL)
	{
		cantClientes= cantidadClientes(cliente, lenCliente);
		cantKilos = cantidadKilos(pedido, lenPedido);
		prom = promedio(cantKilos, cantClientes);
	}
	return prom;
}

/** \brief Obtiene la cantidad de clientes cargados en la estructura
 *
 * \param eClient cliente[] = Estructura de Cliente
 * \param int lenCliente = Tamaño de estructura Cliente
 *
 * \return Retorna la cantidad de clientes cargados
 */
int cantidadClientes(eClient cliente[], int lenCliente){
	int contClientes;
	int i;
	contClientes=0;
	if(cliente != NULL)
	{
		for (i = 0; i < lenCliente; ++i) {
			if(cliente[i].isEmpty == OCUPADO){
				contClientes++;
			}
		}
	}
	return contClientes;
}

/** \brief Obtiene la cantidad de kilos de Polipropileno
 *  de todos los pedidos procesados
 *
 * \param ePedido pedido[] = Estructura de Pedidos
 * \param int lenPedido = Tamaño de estructura Pedidos
 *
 * \return Retorna la cantidad de kilos de Polipropileno de todos los pedidos procesados
 */
int cantidadKilos(ePedido pedido[], int lenPedido)
{
	int acumKilos;
	int i;
	acumKilos=0;
	if(pedido != NULL)
	{
		for (i = 0; i < lenPedido; ++i) {
			if(pedido[i].isEmpty == OCUPADO && pedido[i].estado == PROCESADO){
				acumKilos = acumKilos + pedido[i].kilos.kilosPP;
			}
		}
	}
	return acumKilos;
}

void clienteConMasPedidos(ePedido pedido[], int lenPedido, eClient cliente[], int lenCliente)
{
	int i;
	int j;
	int arrayCont[lenCliente];
	int numMayor;
	initCont(arrayCont, lenCliente);
	if(pedido != NULL && cliente != NULL)
	{
		for (i = 0; i < lenPedido; ++i) {
			if(pedido[i].isEmpty==OCUPADO)
			{
				for (j = 0; j < lenCliente; ++j) {
					if(pedido[i].idEmpresa==cliente[j].idCompany)
					{
						arrayCont[j]++;
					}
				}
			}
		}
		numMayor = numeroMayor(arrayCont, lenCliente);
		for (i = 0; i < lenCliente; ++i) {
			if(arrayCont[i] == numMayor)
			{
				printf("El cliente con mas pedidos tiene %d pedidos y es:\n", numMayor);
				printClient(cliente[i]);
			}
		}
	}
}


void clienteConMasPedidosEstado(ePedido pedido[], int lenPedido, eClient cliente[], int lenCliente, eEstado estado[], int lenEstado, int criterio)
{
	int i;
	int j;
	int arrayCont[lenCliente];
	int numMayor;
	initCont(arrayCont, lenCliente);
	if(pedido != NULL && cliente != NULL && estado != NULL)
	{

		if(pedido != NULL && cliente != NULL)
		{
			for (i = 0; i < lenPedido; ++i) {
				if(pedido[i].isEmpty==OCUPADO && pedido[i].estado == criterio)
				{
					for (j = 0; j < lenCliente; ++j) {
						if(pedido[i].idEmpresa==cliente[j].idCompany)
						{
							arrayCont[j]++;
						}
					}
				}
			}

			numMayor = numeroMayor(arrayCont, lenCliente);

			for (i = 0; i < lenCliente; ++i) {
				if(arrayCont[i] == numMayor)
				{
					for (j = 0; j < lenEstado; ++j) {
						if(criterio == estado[j].estado)
						printf("El cliente con mas pedidos %s tiene %d pedidos  y es:\n", estado[j].descripcion, numMayor);
						printClient(cliente[i]);
					}

				}
			}
		}
	}
}
