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
			strncpy(list[index].street, street, 51);
			list[index].altitude=altitude;
			strncpy(list[index].localidad, localidad, 51);
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
    getString(clienteNuevo.localidad, "\nLocalidad: ", "\nError, ingrese una localidad valida (max 51 caracteres): ", 1, 51, 4);
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
			strncpy(list[i].localidad, " ", 51);
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
            error=0;
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
        				strncpy(list[index].street, auxCadena, 51);
        				printf("\n La Calle fue modificada con exito...\n");
        			}else{
        				printf("\n La Calle NO fue modificada...\n");
        			}
                    break;
                case 2:
                	auxNum=cargarUnEntero("Ingrese la nueva Altura: \n","Error, ingrese una altura (entre 0 y 27300): \n",0, 27300, 4);
        			printf("\nLa nueva Altura es: %d\n", auxNum);
        			confirmacion = cargarUnEntero("\nConfirmar modificacion (1.Si 2.No): ", "\nError (1.Si 2.No): ", 1, 2, 4);
        			if(confirmacion==1){
                    	list[index].altitude = auxNum;
                    	printf("\n La Altura fue modificada con exito...\n");
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
