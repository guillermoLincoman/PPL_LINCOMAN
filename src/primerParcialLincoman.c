/*
 ============================================================================
 Name        : TP_2_Lincoman.c
 Author      : Guillermo Lincoman
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "PPL_funcionesMenu.h"

int main()
{
    setbuf(stdout, NULL);
    int idProxTrabajo=1000;
    int aux;
    int opcion;

    eClient client[TC];
    aux= iniciar(client, TC);
    if(aux!=0){
    	printf("Error, no es posible iniciar el programa....");
    	return 0;
    }else{
        printf("Inicializando programa...\n");
        limpiar();
    }
    aux=-1;
    do
    {
    	menu();
        opcion=cargarUnEntero("Elija una opcion: ","Elija una opcion entre 0 y 4: ", 0, 4, 4);
        switch(opcion)
        {
            case 1:
            	if(idProxTrabajo<2000)
            	{
                    aux= agregarCliente(client, TC, idProxTrabajo);
                    idProxTrabajo++;
            	}else{
            		printf("\nNo hay mas lugar disponible....\n");
            	}
            	limpiar();
                break;
            case 2:
                if(aux==0)
                {
                	modifiCliente(client, TC, idProxTrabajo);
                }else{
                    printf("\nNo puede modificar empleados sin antes cargar uno...\n");
                }
                limpiar();
                break;
            case 3:
                if(aux==0)
                {
                	eliminarCliente(client, TC, idProxTrabajo);
                }else{
                    printf("\nNo puede eliminar empleados sin antes cargar uno...\n");
                }
                limpiar();
                break;
            case 4:
            	printClients(client, TC);
                limpiar();
                break;
        }
    }while(opcion!=0);

    return 0;
}
