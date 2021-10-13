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
ePedido addPedidoNew(int idNuevoPedido, int idCliente)
{
	printf("\nINGRESE EL NUEVO PEDIDO\n");
	printf("------------------------------------\n");
	ePedido nuevoPedido;
	nuevoPedido.idEmpresa = idCliente;
	nuevoPedido.idPedido = idNuevoPedido;
	printf("\nHDPE: Polietileno de alta densidad (Envases para lacteos, perfumes, detergentes liquidos, etc.)\n");
	nuevoPedido.kilosHDPE = cargarUnEntero("\nCantidad de Kg HDPE: Kg", "\nError, ingrese un peso valido (entre 0 Kg y 500 Kg): ", 0, 500, 4);
	printf("\nLDPE: Polietileno de baja densidad (Bolsas de congelacion de alimentos, tapas flexibles o bolsas de basura.)\n");
	nuevoPedido.kilosLPDE = cargarUnEntero("\nCantidad de Kg LDPE: Kg", "\nError, ingrese un peso valido (entre 0 Kg y 500 Kg): ", 0, 500, 4);
	printf("\nPP: Polipropileno (Plasticos utilizados en la industria automovilística y en la construccion.)\n");
	nuevoPedido.kilosPP = cargarUnEntero("\nCantidad de Kg PP: Kg", "\nError, ingrese un altura valido (entre 0 Kg y 500 Kg): ", 0, 500, 4);
	nuevoPedido.kilosNoReciclabes = cargarUnEntero("\nCantidad de KG No reciclables: Kg ", "\nError, ingrese un altura valida (entre 0 y 27300): ", 0, 500, 4);
	nuevoPedido.kilosTotales = nuevoPedido.kilosHDPE + nuevoPedido.kilosLPDE + nuevoPedido.kilosPP + nuevoPedido.kilosNoReciclabes;
	printf("------------------------------------\n");
    return nuevoPedido;
}

int addPedido(ePedido list[], int len, int idEmpresa, int idPedido, int kilosHDPE, int kilosLPDE, int kilosPP, int kilosNoReciclabes, int kilosTotales)
{
	int error;
	int i;
	error = -1;
	if(list != NULL)
	{
		i = buscarLibrePedido(list, len);
		if(i != -1){
			error=0;
			list[i].idEmpresa=idEmpresa;
			list[i].idPedido=idPedido;
			list[i].kilosHDPE=kilosHDPE;
			list[i].kilosLPDE=kilosLPDE;
			list[i].kilosPP = kilosPP;
			list[i].kilosNoReciclabes=kilosNoReciclabes;
			list[i].kilosTotales=kilosTotales;
			list[i].estado=PENDIENTE;
			list[i].isEmpty=OCUPADO;
		}
	}
	return error;
}

/** \brief Muestra el contenido en la estructura de empleados
 *
 * \param Employee list[] = estructura de empleados
 * \param len = tamaño de estructura empleados.

 */
void printPedidos(ePedido list[], int len)
{
    int i;
    printf("\n__________________________________________________________________________________________________________________\n");
    printf("                                               LISTADO DE PEDIDOS                                                 |");
    printf("\n__________________________________________________________________________________________________________________\n");
    printf("  ID EMPRESA  |   ID PEDIDO  |  KILOS HDPE  |  KILOS LDPE  |  KILOS PP  |  KILOS NR  |  TOTAL KILOS  |  ESTADO    |\n");
    printf("______________|______________|______________|______________|____________|____________|_______________|____________|\n");
    for(i=0; i<len; i++)
    {
    	if(list[i].isEmpty == OCUPADO)
    	{
    		printPedido(list[i]);
    	}
    }
}
/** \brief Muestra el contenido de un empleado
 *
 * \param Employee list[] = estructura de empleados

 */
void printPedido(ePedido list)
{
    printf("-------------------------------------------------------------------------------------------------------------------\n");
    printf("     %4d     |     %4d     |     %4d     |     %4d     |    %4d    |    %4d    |      %4d     |   %4d     | \n", list.idEmpresa, list.idPedido, list.kilosHDPE, list.kilosLPDE, list.kilosPP, list.kilosNoReciclabes, list.kilosTotales, list.estado);
    printf("-------------------------------------------------------------------------------------------------------------------\n");
}
