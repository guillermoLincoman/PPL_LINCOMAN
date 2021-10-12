/*
 * funcionesMenu.c
 *
 *  Created on: 6 oct. 2021
 *      Author: Compumar
 */
#include "PPL_funcionesMenu.h"

int iniciar(eClient list[], int len)
{
    int aux;
    int error;
    error=-1;
    aux=initClient(list, len);
    if(aux==0){
        error=0;
    }
    return error;
}

int agregarCliente(eClient list[], int len, int proxId)
{
    int aux;
    int error;
    error=-1;
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
            error=0;
        }
    }
    return error;
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
