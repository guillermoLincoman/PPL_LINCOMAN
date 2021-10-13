/*
 * PPL_pedidos.c
 *
 *  Created on: 12 oct. 2021
 *      Author: Compumar
 */
#include "PPL_pedidos.h"


/** \brief Indica que todas las posiciones de la estructura estan vacias,
 * Inicializa isEmpty en VACIO (-1)
 * en todas las posiciones de la estructura.
 * \param estructura eEmpleado.
 * \param tamaño de la estructura eEmpleado.
 * \return Devuelve -1 si hay un error y 0 si no hay errores.
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

/** \brief Busca un lugar libre en la estructura,
 * Busca dentro de la estructura un indice
 * en cual la variable isEmpty se igual a VACIO
 * \param list = estructura Employee.
 * \param len = tamaño de la estructura Employee.
 * \return devuelve un indice vacio, en caso de error devuelve -1
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


/** \brief Agrega a un estructura auxiliar los valores ingresados por el usuario
 * \param int idNuevoEmpleado id del nuevo empleado a cargar
 * \return Devuelve  una estructura cargada con los datos ingresados por el usuario
*/
ePedido addPedidoNew(int idNuevoPedido, int idCliente, int cuit)
{
	printf("\nINGRESE EL NUEVO PEDIDO\n");
	printf("------------------------------------\n");
	ePedido nuevoPedido;
	nuevoPedido.idEmpresa = idCliente;
	nuevoPedido.idPedido = idNuevoPedido;
	nuevoPedido.cuitCliente = cuit;
	nuevoPedido.kilosTotales = cargarUnEntero("\nCantidad de kilos a recolectar: Kg ", "\nError, ingrese una cantidad de kilos valido (maximo 1000 Kg por pedido): ", 0, 1000, 4);
	nuevoPedido.estado = PENDIENTE;
	printf("------------------------------------\n");
    return nuevoPedido;
}

int addPedido(ePedido list[], int len, int idPedido, int cuitCliente, int idEmpresa, int kilosTotales)
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
			list[i].cuitCliente = cuitCliente;
			list[i].kilosTotales=kilosTotales;
			list[i].estado=PENDIENTE;
			list[i].isEmpty=OCUPADO;
		}
	}
	return error;
}

/** \brief Busca un empleado por Id e indica en que posicion se encuentra
 *
 * \param Employee list[] = estructura de empleados
 * \param len = tamaño de empleados[], tEmpleado.
 * \param id = id del empleado buscado
 * \return devuelve la posicion en la que se encuentra el empleado buscado
 * \en caso de error devuelve -1
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
