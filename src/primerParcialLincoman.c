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
    int idProxPedido=1;
    int aux;
    int opcion;
    int contClientes;
    int contPedidosPendientes;
    int contPedidosProcesados;

    contPedidosProcesados = 0;
    contClientes = 0;
    contPedidosPendientes = 0;
    eClient client[TC];
    ePedido pedidos[TP];
    eEstado estado[TE]={{-1,"PENDIENTE"},{0,"PROCESADO"}};

    aux= iniciar(client, TC, pedidos, TP);
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
        opcion=cargarUnEntero("Elija una opcion: ", "Elija una opcion entre 0 y 9: ", 0, 9, 4);
        switch(opcion)
        {
            case 1:
                aux= agregarCliente(client, TC, idProxTrabajo);
                if(aux != -1){
                	contClientes++;
                    idProxTrabajo++;
                }
            	limpiar();
                break;

            case 2:
                if(contClientes>0){
                	modifiCliente(client, TC, idProxTrabajo);
                }else{
                    printf("\nNo puede modificar clientes sin antes cargar uno...\n");
                }
                limpiar();
                break;

            case 3:
                if(contClientes>0){
                	eliminarCliente(client, TC, idProxTrabajo);
                	contClientes--;
                }else{
                    printf("\nNo puede eliminar clientes sin antes cargar uno...\n");
                }
                limpiar();
                break;

            case 4:
                if(contClientes>0){
                	agregarPedido(client, TC, pedidos, TP, estado, TE, idProxPedido, idProxTrabajo);
                	contPedidosPendientes++;
                	idProxPedido++;
                }else{
                    printf("\nNo puede crear pedidos sin antes cargar un cliente...\n");
                }
                limpiar();
                break;

            case 5:
                if(contPedidosPendientes>0){
                	aux = procesarPedido(client, TC, pedidos, TP, estado, TE, idProxPedido);
                	if(aux==0)
                	{
                    	contPedidosPendientes--;
                    	contPedidosProcesados++;
                	}
                }else{
                    printf("\nNo hay pedidos pendientes...\n");
                }
                limpiar();
                break;
            case 6:
                if(contClientes>0){
                	printClients(client, TC);
                }else{
                    printf("\nNo hay clientes cargados...\n");
                }
                limpiar();
                break;
            case 7:
                if(contPedidosPendientes>0){
                	printPedidosPendientes(pedidos, TP, client, TC, estado, TE);
                }else{
                    printf("\nNo hay pedidos pendientes...\n");
                }
                limpiar();
                break;
            case 8:
                if(contPedidosProcesados>0){
                	printPedidosProcesados(pedidos, TP, client, TC, estado, TE);
                }else{
                    printf("\nAun no hay pedidos procesados...\n");
                }
                limpiar();
                break;
            case 9:
                informes(client, TC, pedidos, TP, estado, TE, idProxPedido, idProxTrabajo, contPedidosPendientes, contPedidosProcesados);
                limpiar();
                break;
        }
    }while(opcion!=0);

    return 0;
}
