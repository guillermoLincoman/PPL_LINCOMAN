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
//devuelve 0 si se cargo, -1 si no hay lugar
int agregarCliente(eClient list[], int len, int proxId)
{
    int aux;
    aux=-1;
    eClient auxCliente;
    if(list != NULL)
    {
    	//1.Cargo el cliente en una estructura auxiliar
    	auxCliente = addClientNew(proxId);
    	//2.Si hay lugar devuelve 0 en caso de no haber lugar devuelve -1 y entra al else
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
