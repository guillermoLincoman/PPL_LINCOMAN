/*
 * ArrayEmployees.c
 *
 *  Created on: 6 oct. 2021
 *      Author: Compumar
 */
#include "PPL_cliente.h"


/** \brief Indica que todas las posiciones de la estructura estan vacias,
 * Inicializa isEmpty en VACIO (-1)
 * en todas las posiciones de la estructura.
 * \param estructura eEmpleado.
 * \param tamaño de la estructura eEmpleado.
 * \return Devuelve -1 si hay un error y 0 si no hay errores.
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

/** \brief Busca un lugar libre en la estructura,
 * Busca dentro de la estructura un indice
 * en cual la variable isEmpty se igual a VACIO
 * \param list = estructura Employee.
 * \param len = tamaño de la estructura Employee.
 * \return devuelve un indice vacio, en caso de error devuelve -1
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
int addClient(eClient list[], int len, int id, char name[], int cuit, char street[], int altitude, char city[], char province[], char country[])
{
	int error;
	int index;
	error= -1;
	if(list != NULL)
	{
		index= BuscarLibre(list, len);
		error=0;
		if(index!=-1){
			list[index].idCompany=id;
			strncpy(list[index].name, name, 51);
			list[index].cuit=cuit;
			strncpy(list[index].street, street, 51);
			list[index].altitude=altitude;
			strncpy(list[index].city, city, 51);
			strncpy(list[index].province, province, 51);
			strncpy(list[index].country, country, 51);
			list[index].isEmpty=OCUPADO;
		}
	}
	return error;
}

/** \brief Agrega a un estructura auxiliar los valores ingresados por el usuario
 * \param int idNuevoEmpleado id del nuevo empleado a cargar
 * \return Devuelve  una estructura cargada con los datos ingresados por el usuario
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
    getString(clienteNuevo.street, "\nCalle: ", "\nError, ingrese una calle valida (max 40 caracteres): ", 1, 40, 4);
    clienteNuevo.altitude = cargarUnEntero("\nAltura: ", "\nError, ingrese un altura valida (entre 0 y 27300): ", 0, 27300, 4);
    getString(clienteNuevo.city, "\nCiudad: ", "\nError, ingrese una ciudad valida (max 51 caracteres): ", 1, 51, 4);
    getString(clienteNuevo.province, "\nProvincia: ", "\nError, ingrese una provincia valida (max 51 caracteres): ", 1, 51, 4);
    getString(clienteNuevo.country, "\nPais: ", "\nError, ingrese un pais valido (max 51 caracteres): ", 1, 51, 4);
	clienteNuevo.isEmpty = OCUPADO;
	printf("------------------------------------\n");

    return clienteNuevo;
}

/** \brief Busca un empleado por Id e indica en que posicion se encuentra
 *
 * \param Employee list[] = estructura de empleados
 * \param len = tamaño de empleados[], tEmpleado.
 * \param id = id del empleado buscado
 * \return devuelve la posicion en la que se encuentra el empleado buscado
 * \en caso de error devuelve -1
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
/** \brief Muestra el contenido en la estructura de empleados
 *
 * \param Employee list[] = estructura de empleados
 * \param len = tamaño de estructura empleados.

 */
void printClients(eClient list[], int len)
{
    int i;
    printf("\n________________________________________________________________________________________________________________________________________________________________\n");
    printf("                                                                       LISTADO DE CLIENTES                                                                      |");
    printf("\n________________________________________________________________________________________________________________________________________________________________\n");
    printf("  ID EMPRESA  |   NOMBRE EMPRESA  |     CUIT      |          CALLE         |   ALTURA   |         CIUDAD         |        PROVINCIA       |        PAIS         |\n");
    printf("______________|___________________|_______________|________________________|____________|________________________|________________________|_____________________|\n");
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
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("  %4d     |  %20s|  %11d  |  %20s  |   %6d   |  %20s  |  %20s  |  %20s  \n", list.idCompany, list.name, list.cuit, list.street, list.altitude, list.city, list.province, list.country);
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

/** \brief Elimina un empleado por ID
 *
 * \param Employee list[] = estructura de empleados
 * \param len = tamaño de estructura empleados.
 * \param ultimoId = ultimo id ingresado para validar el maximo de id que se puede ingresar
 *
 * \return Devuelve -1 si hay un error y 0 si se elimino el empleado
 */
int removeClient(eClient list[], int len, int ultimoId)
{
	int error;
	int i;
	int idIngresado;
	error= -1;
	if(list != NULL)
	{
		printClients(list, len);
		idIngresado= cargarUnEntero("Ingrese el id a eliminar: ", "Error, ingrese un id valido: ", 1000, ultimoId-1, 4);
		i = findClientById(list, len, idIngresado);
		if(i != -1){
			strncpy(list[i].name, " ", 51);
			list[i].cuit = 0;
			strncpy(list[i].street, " ", 51);
			list[i].altitude=0;
			strncpy(list[i].city, " ", 51);
			strncpy(list[i].province, " ", 51);
			strncpy(list[i].country, " ", 51);
			list[i].isEmpty=VACIO;
	        printf("\nEl CLIENTE fue borrado con exito....\n\n");
			error=0;
		}
	}
	return error;
}

int modificarCliente(eClient list[], int len, int ultimoId)
{
    int auxId;
    int opcion;
    int index;
    int error;
    int auxNum;
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
            error=0;
            printf("\n________________________________________________________________________________________________________________________________________________________________\n");
            printf("  ID EMPRESA  |   NOMBRE EMPRESA  |     CUIT      |          CALLE         |   ALTURA   |         CIUDAD         |        PROVINCIA       |        PAIS         |\n");
            printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
            printClient(list[index]);
            printf("________________________\n");
            printf("| Que desea modificar? |\n");
            printf("| 1. CALLE             |\n");
            printf("| 2. ALTURA            |\n");
            printf("| 3. CIUDAD            |\n");
            printf("| 4. PROVINCIA         |\n");
            printf("| 5. PAIS              |\n");
            printf("| 0. VOLVER AL MENU    |\n");
            printf("|______________________|\n");
            opcion=cargarUnEntero("\nElija una opcion: ", "\nError, elija una opcion valida: ", 0, 5, 4);

            switch(opcion)
            {
            	case 1:
            		getUsuario(auxCadena, "Ingrese la nueva CALLE: \n", "\nError, ingrese una calle valida (max 40 caracteres): ", 1, 40, 4);
        			strncpy(list[index].street, auxCadena, 51);
                    printf("\n La Calle fue modificada con exito...\n");
                    break;
                case 2:
                	auxNum=cargarUnEntero("Ingrese la nueva Altura: \n","Error, ingrese una altura (entre 0 y 27300): \n",0, 27300, 4);
                	list[index].altitude = auxNum;
                	printf("\n La Altura fue modificada con exito...\n");
                    error=0;
                    break;
                case 3:
            		getUsuario(auxCadena, "Ingrese la nueva CIUDAD: \n", "\nError, ingrese una CIUDAD valida valido (max 58 caracteres): ", 1, 58, 4);
            		strncpy(list[index].city, auxCadena, 51);
            		printf("\n La Ciudad fue modificada con exito...\n");
                    break;
                case 4:
            		getUsuario(auxCadena, "Ingrese la nueva PROVINCIA: \n", "\nError, ingrese una PROVINCIA valida valido (max 51 caracteres): ", 1, 51, 4);
            		strncpy(list[index].province, auxCadena, 51);
            		printf("\n La Provincia fue modificada con exito...\n");
                    break;
                case 5:
            		getUsuario(auxCadena, "Ingrese el nuevo PAIS: \n", "\nError, ingrese un PAIS valida valido (max 64 caracteres): ", 1, 64, 4);
            		strncpy(list[index].country, auxCadena, 51);
            		printf("\n El Pais fue modificada con exito...\n");
                    break;
            }
        }while(opcion!=0);
        }
    }
    return error;
}
