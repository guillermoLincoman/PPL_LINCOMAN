/*
 * ArrayEmployees.c
 *
 *  Created on: 6 oct. 2021
 *      Author: Compumar
 */
#include "PPL_cliente.h"


/** \brief Inicializa todas las posiciones de una estructura en VACIO(-1)
 *
 * \param eClient list[] = estructura de clientes.
 * \param int len = tamaño de la estructura.
 *
 * \return Retorna 0 si la operacion es exitosa y -1 en caso de error.
 */
int initClient(eClient list[], int len)
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
 * \param eClient list[] = estructura de clientes.
 * \param int len = tamaño de la estructura.
 *
 * \return Retorna el indice donde se encuentra el lugar libre o -1 en caso de error.
 */
int BuscarLibre(eClient list[], int len)
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

/** \brief Pide la funcion buscarLibre para encontrar un lugar vacio
 * y la funcion addEmployeeNew para agregar un nuevo empleado.
 * \param eEmpleado empleado[]
 * \param tamaño de empleados[], tEmpleado.
 * \param int idNuevoEmpleado id del nuevo empleado a cargar
 * \return Devuelve -1 si hay un error y 0 si se cargo el empleado
*/

/** \brief Asigna valores ingresados por el usuario a la estructura en un lugar libre
 * Utiliza la funcion Buscar libre para encontrar un lugar en la estrucutra
 *
 * \param eClient list[] = estructura de clientes.
 * \param int len = Tamaño de la estructura.
 * \param int id = Id del cliente.
 * \param char name[] = Nombre de la empresa del cliente
 * \param int cuit = Cuit de la empresa
 * \param char street[] = Calle de cliente
 * \param int altitude = Altura de direccion del cliente
 * \param char localidad[] = Localidad del cliente
 *
 * \return Retorna 0 si la operacion es exitosa y -1 en caso de error.
 */
int addClient(eClient list[], int len, int id, char name[], int cuit, char street[], int altitude, char localidad[])
{
	int error;
	int index;
	error= -1;
	if(list != NULL)
	{
		index= BuscarLibre(list, len);
		if(index!=-1){
			error=0;
			list[index].idCompany=id;
			strncpy(list[index].name, name, 51);
			list[index].cuit=cuit;
			strncpy(list[index].direccion.street, street, 51);
			list[index].direccion.altitude=altitude;
			strncpy(list[index].localidad, localidad, 51);
			list[index].isEmpty=OCUPADO;
		}
	}
	return error;
}

/** \brief Carga una estrucutura auxiliar con datos cargados por el usuario
 *
 * \param int idNuevoCliente = id del nuevo empleado a cargar
 *
 * \return Retorna  una estructura cargada con los datos ingresados por el usuario
*/
eClient addClientNew(int idNuevoCliente)
{
	printf("\nINGRESE LOS DATOS DEL NUEVO CLIENTE\n");
	printf("------------------------------------\n");
	eClient clienteNuevo;
	clienteNuevo.idCompany = idNuevoCliente;
	getUsuario(clienteNuevo.name, "\nNombre de la empresa: ", "\nError, ingrese un nombre valido (max 51 caracteres): ", 1, 51, 4);
	clienteNuevo.cuit = cargarUnEntero("\nIngrese el CUIT:", "\nError, ingrese un CUIT valido(ingresar sin guion  30-XXXX-X ): ", 3000000 , 3099999, 4);
	printf("------------------------------------\n");
	printf("\nINGRESAR DIRECCION\n");
	printf("------------------------------------\n");
	getUsuario(clienteNuevo.direccion.street, "\nCalle: ", "\nError, ingrese una calle valida (max 40 caracteres): ", 1, 40, 4);
    clienteNuevo.direccion.altitude = cargarUnEntero("\nAltura: ", "\nError, ingrese un altura valida (entre 0 y 27300): ", 0, 27300, 4);
    getUsuario(clienteNuevo.localidad, "\nLocalidad: ", "\nError, ingrese una localidad valida (max 51 caracteres): ", 1, 51, 4);
	printf("------------------------------------\n");

    return clienteNuevo;
}

/** \brief Busca un cliente por Id
 *
 * \param eClient list[] = estructura de clientes
 * \param len = tamaño de la estructura clientes
 * \param id = id del cliente buscado
 *
 * \return Retorna la posicion del cliente que coincide con el id buscado, en caso de error devuelve -1
 */
int findClientById(eClient list[], int len,int id)
{
	int i;
 	int index;
 	index=-1;
 	if(list != NULL)
 	{
 		for (i = 0; i < len; ++i) {
			if(list[i].isEmpty == OCUPADO){
				if(list[i].idCompany == id){
					index = i;
					break;
				}
			}
		}
 	}
 	return index;
}

/** \brief Elimina un cliente segun el ID
 *
 * \param eClient list[] = estructura de clientes
 * \param int len = tamaño de la estructura clientes
 * \param int ultimoId = ultimo id ingresado para validar el maximo de id que se puede ingresar
 *
 * \return Retorna -1 si hay un error y 0 si se elimino el cliente
 */
int removeClient(eClient list[], int len, int ultimoId)
{
	int error;
	int i;
	int idIngresado;
	int confirmacion;
	error= -1;
	if(list != NULL)
	{
		printClients(list, len);
		idIngresado= cargarUnEntero("Ingrese el id a eliminar: ", "Error, ingrese un id valido: ", 1000, ultimoId-1, 4);
		i = findClientById(list, len, idIngresado);
		limpiar();
		printf("\nEsta seguro que desea borrar al cliente? \n");
		printClient(list[i]);
		confirmacion = cargarUnEntero("\nConfirmar modificacion (1.Si 2.No): ", "\nError (1.Si 2.No): ", 1, 2, 4);
		if(i != -1 ){
			if(confirmacion == 1)
			{
				strncpy(list[i].name, " ", 51);
				list[i].cuit = 0;
				strncpy(list[i].direccion.street, " ", 51);
				list[i].direccion.altitude=0;
				strncpy(list[i].localidad, " ", 51);
				list[i].isEmpty=VACIO;
		        printf("\nEl CLIENTE fue borrado con exito....\n\n");
				error=0;
			}else{
		        printf("\nEl Cliente no fue borrado....\n\n");
			}

		}
	}
	return error;
}

/** \brief Modifica un cliente segun el ID
 *
 * \param eClient list[] = estructura de clientes
 * \param int len = tamaño de la estructura clientes
 * \param int ultimoId = ultimo id ingresado para validar el maximo de id que se puede ingresar
 *
 * \return Retorna -1 si hay un error y 0 si se modifico el cliente
 */
int modificarCliente(eClient list[], int len, int ultimoId)
{
    int auxId;
    int opcion;
    int index;
    int error;
    int auxNum;
    int confirmacion;
    char auxCadena[51];
    error=-1;
    if(list != NULL)
    {
        printClients(list, len);
        printf("--------------------------------------------------------------------------\n");
        auxId=cargarUnEntero("Ingrese el ID del CLIENTE que quiere modificar: ", "\nError, ingrese un id entre 1000 y 2000 ", 1000,ultimoId-1, 4);
        index= findClientById(list, len, auxId);
        if(index!=-1)
        {
        do{
        	limpiar();
            printf("\n________________________________________________________________________________________________________________\n");
            printf("   ID EMPRESA  |    NOMBRE EMPRESA    |     CUIT     |          CALLE       |   ALTURA   |       LOCALIDAD      |\n");
            printf("----------------------------------------------------------------------------------------------------------------\n");
            printClient(list[index]);
            printf("________________________\n");
            printf("| Que desea modificar? |\n");
            printf("| 1. CALLE             |\n");
            printf("| 2. ALTURA            |\n");
            printf("| 3. LOCALIDAD         |\n");
            printf("| 0. VOLVER AL MENU    |\n");
            printf("|______________________|\n");
            opcion=cargarUnEntero("\nElija una opcion: ", "\nError, elija una opcion valida: ", 0, 3, 4);

            switch(opcion)
            {
            	case 1:
            		getUsuario(auxCadena, "Ingrese la nueva CALLE: \n", "\nError, ingrese una calle valida (max 40 caracteres): ", 1, 40, 4);
        			printf("\nLa nueva calle es: %s\n", auxCadena);
        			confirmacion = cargarUnEntero("\nConfirmar modificacion (1.Si 2.No): ", "\nError (1.Si 2.No): ", 1, 2, 4);
        			if(confirmacion==1){
        				strncpy(list[index].direccion.street, auxCadena, 51);
        				printf("\n La Calle fue modificada con exito...\n");
        	            error=0;
        			}else{
        				printf("\n La Calle NO fue modificada...\n");
        			}
                    break;
                case 2:
                	auxNum=cargarUnEntero("Ingrese la nueva Altura: \n","Error, ingrese una altura (entre 0 y 27300): \n",0, 27300, 4);
        			printf("\nLa nueva Altura es: %d\n", auxNum);
        			confirmacion = cargarUnEntero("\nConfirmar modificacion (1.Si 2.No): ", "\nError (1.Si 2.No): ", 1, 2, 4);
        			if(confirmacion==1){
                    	list[index].direccion.altitude = auxNum;
                    	printf("\n La Altura fue modificada con exito...\n");
                        error=0;
        			}else{
        				printf("\n La Altura NO fue modificada...\n");
        			}
                    break;
                case 3:
            		getUsuario(auxCadena, "Ingrese la nueva Localidad: \n", "\nError, ingrese una CIUDAD valida valido (max 58 caracteres): ", 1, 58, 4);
        			printf("\nLa nueva Localidad es: %s\n", auxCadena);
        			confirmacion = cargarUnEntero("\nConfirmar modificacion (1.Si 2.No): ", "\nError (1.Si 2.No): ", 1, 2, 4);
        			if(confirmacion==1){
                		strncpy(list[index].localidad, auxCadena, 51);
                		printf("\n La Localidad fue modificada con exito...\n");
                        error=0;
        			}else{
        				printf("\n La Localidad NO fue modificada...\n");
        			}
                    break;

            }
        }while(opcion!=0);
        }
    }
    return error;
}

/** \brief Muestra todos los clientes cargados
 *
 * \param eClient list[] = Estructura de Clientes
 * \param len = Tamaño de estructura Clientes.

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

/** \brief Muestra un cliente
 *
 * \param eClient list = Estructura de Cliente a imprimir

 */
void printClient(eClient list)
{
    printf("----------------------------------------------------------------------------------------------------------------\n");
    printf("     %4d      | %20s | %11d  | %20s |   %6d   | %20s  \n", list.idCompany, list.name, list.cuit, list.direccion.street, list.direccion.altitude, list.localidad);
    printf("----------------------------------------------------------------------------------------------------------------\n");
}
