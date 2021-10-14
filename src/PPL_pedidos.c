/*
 * PPL_pedidos.c
 *
 *  Created on: 12 oct. 2021
 *      Author: Compumar
 */
#include "PPL_pedidos.h"

/** \brief Inicializa todas las posiciones de una estructura en VACIO(-1)
 *
 * \param ePedido list[] = Estructura de Pedidos.
 * \param int len = Tamaño de la Estructura.
 *
 * \return Retorna 0 si la operacion es exitosa y -1 en caso de error.
 */
int initPedidos(ePedido list[], int len)
{
	int i;
	int error;
	error =-1;
	if(list!=NULL)
	{
		for (i = 0; i < len; ++i) {
			list[i].isEmpty = VACIO;
			error = 0;
		}
	}
 return error;
}

/** \brief Busca un lugar libre en la estructura
 *
 * \param eClient list[] = Estructura de Pedidos.
 * \param int len = tamaño de la estructura.
 *
 * \return Retorna el indice donde se encuentra el lugar libre o -1 en caso de error.
 */
int buscarLibrePedido(ePedido list[], int len)
{
	int i;
	int index;
	index = -1;
	if(list != NULL)
	{
		for(i=0;i<len; i++){
			if(list[i].isEmpty==VACIO){
				index = i;
				break;
			}
		}
	}
	return index;
}

/** \brief Carga una estrucutura auxiliar con datos cargados por el usuario
 *
 * \param int idNuevoPedido = id del nuevo pedido a cargar
 * \param int idCliente = id del cliente que realiza el pedido
 *
 * \return Retorna  una estructura cargada con los datos ingresados por el usuario
*/
ePedido addPedidoNew(int idNuevoPedido, int idCliente)
{
	printf("\nINGRESE EL NUEVO PEDIDO\n");
	printf("------------------------------------\n");
	ePedido nuevoPedido;
	nuevoPedido.idPedido = idNuevoPedido;
	nuevoPedido.idEmpresa = idCliente;
	nuevoPedido.kilos.kilosTotales = cargarUnEntero("\nCantidad de kilos a recolectar: Kg ", "\nError, ingrese una cantidad de kilos valido (maximo 1000 Kg por pedido): ", 0, 1000, 4);
	nuevoPedido.estado = PENDIENTE;
	printf("------------------------------------\n");
    return nuevoPedido;
}

/** \brief Asigna valores ingresados por el usuario a la estructura en un lugar libre
 * Utiliza la funcion BuscarlibrePedido para encontrar un lugar en la estrucutra
 *
 * \param ePedido list[] = Estructura de Pedido.
 * \param int len = Tamaño de la Estructura.
 * \param int idPedido = Id del Pedido.
 * \param int idEmpresa = Id de la Empresa.
 * \param int kilosTotales = Kilos totales del pedido.
 *
 * \return Retorna 0 si la operacion es exitosa y -1 en caso de error.
 */
int addPedido(ePedido list[], int len, int idPedido, int idEmpresa, int kilosTotales)
{
	int error;
	int i;
	error = -1;
	if(list != NULL)
	{
		i = buscarLibrePedido(list, len);
		if(i != -1){
			error=0;
			list[i].idPedido = idPedido;
			list[i].idEmpresa = idEmpresa;
			list[i].kilos.kilosTotales=kilosTotales;
			list[i].estado=PENDIENTE;
			list[i].isEmpty=OCUPADO;
		}
	}
	return error;
}

/** \brief Busca un pedido por Id
 *
 * \param ePedido list[] = Estructura de Pedidos
 * \param len = Tamaño de la estructura Pedidos
 * \param id = id del Pedido buscado
 *
 * \return Retorna la posicion del Pedido que coincide con el id buscado, en caso de error devuelve -1
 */
int findPedidoById(ePedido list[], int len,int id)
{
	int i;
 	int index;
 	index=-1;
 	if(list != NULL)
 	{
 		for (i = 0; i < len; ++i) {
			if(list[i].isEmpty == OCUPADO){
				if(list[i].idPedido == id){
					index = i;
					break;
				}
			}
		}
 	}
 	return index;
}


/** \brief Carga una estructura auxiliar con los valores del pedido procesado

 * \return Devuelve  una estructura cargada con los datos ingresados por el usuario
*/
ePedido addPedidoNewProcesado()
{
	printf("\nINGRESE LOS PESOS OBTENIDOS EN LE PROCESO\n");
	printf("------------------------------------\n");
	ePedido nuevoPedido;
	nuevoPedido.kilos.kilosHDPE = cargarUnEntero("\nCantidad de kilos HDPE recolectado: Kg ", "\nError, ingrese una cantidad de kilos valida (maximo 1000 Kg): ", 0, 1000, 4);
	nuevoPedido.kilos.kilosLPDE = cargarUnEntero("\nCantidad de kilos LPDE recolectado: Kg ", "\nError, ingrese una cantidad de kilos valida (maximo 1000 Kg): ", 0, 1000, 4);
	nuevoPedido.kilos.kilosPP = cargarUnEntero("\nCantidad de kilos PP recolectado: Kg ", "\nError, ingrese una cantidad de kilos valida (maximo 1000 Kg ): ", 0, 1000, 4);
	nuevoPedido.estado = PROCESADO;
	printf("------------------------------------\n");
    return nuevoPedido;
}

/** \brief Asigna valores ingresados por el usuario a la estructura en un lugar libre
 * Utiliza la funcion findPedidoById para encontrar la estructura con el pedido pendiente
 *
 * \param ePedido list[] = Estructura de Pedidos.
 * \param int len = Tamaño de la Estructura.
 * \param int id = Id del Pedido para encontrarlo y cargar los nuevos datos.
 * \param int kilosHDPE = Cantidad de kilos de Polietileno de alta densidad
 * \param int kilosLPDE = Cantidad de kilos de Polietileno de baja densidad.
 * \param int kilosPP = Cantidad de kilos de Polipropileno.
 *
 * \return Retorna 0 si la operacion es exitosa y -1 en caso de error.
 */
int addPedidoProcesado(ePedido list[], int id, int len,int kilosHDPE, int kilosLPDE, int kilosPP)
{
	int i;

	i = findPedidoById(list, len, id);
	if(i != -1)
	{
		list[i].kilos.kilosHDPE = kilosHDPE;
		list[i].kilos.kilosLPDE = kilosLPDE;
		list[i].kilos.kilosPP = kilosPP;
		list[i].kilos.kilosTotalesProcesados=kilosHDPE + kilosLPDE + kilosPP;
		list[i].estado=PROCESADO;
	}

	return i;
}
