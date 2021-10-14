/*
 * extras.c
 *
 *  Created on: 6 oct. 2021
 *      Author: Compumar
 */
#include "PPL_inputs.h"

void menu()
{
    printf("\n*************************************\n");
    printf("*RECOLECCION Y RECICLADO DE PLASTICO*\n");
    printf("*************************************\n");
    printf("| 1. Alta cliente:                  |\n");
    printf("| 2. Modificar datos de cliente	    |\n");
    printf("| 3. Baja de cliente                |\n");
    printf("| 4. Crear pedido de recoleccion    |\n");
    printf("| 5. Procesar residuos              |\n");
    printf("| 6. Imprimir Clientes              |\n");
    printf("| 7. Imprimir Pedidos pendientes    |\n");
    printf("| 8. Imprimir Pedidos procesados    |\n");
    printf("| 9. Informes                       |\n");
    printf("| 0. SALIR                          |\n");
    printf("*************************************\n");
}

void menuInformes()
{
    printf("\n*********************************************************************************************************************\n");
    printf("* INFORMES                                                                                                          *\n");
    printf("*********************************************************************************************************************\n");
    printf("| 1. Ingresar una localidad e indicar la cantidad de pedidos pendientes para dicha localidad.                       |\n");
    printf("| 2. Cantidad de kilos de polipropileno reciclado promedio por cliente. (kilos totales / cantidad de clientes)	    |\n");
    printf("| 0. SALIR                                                                                                          |\n");
    printf("*********************************************************************************************************************\n");
}

void limpiar()
{
	printf("\n");
    system("pause");
    system("cls");
}

int validarLetra(char num[])
{
   int i=0;
   //repite hasta llegar al final de la cadena
   while(num[i] != '\0')
   {
       if (i == 0 && num[i] == '-')
       {
           i++;
           continue;
       }
       if(num[i] < '0' || num[i] > '9')
       {
          return 0;
       }
       i++;
   }
   return 1;
}

/** \brief Pide, valida y devuelve un numero entero
 *
 * \param char* mensaje: Recibe el mensaje para pedir entero
 * \param char* mensajeError: Recibe el mensaje de error al pedir entero
 * \param int rangoMin: Numero menor que recibe la funcion
 * \param int rangoMax: Numero mayor que recibe la funcion
 * \param int intentos: Cantidad de intentos de error para cargar el numero
 *
 * \return retorna el entero
 *
 */
int cargarUnEntero(char* mensaje, char* mensajeError,int rangoMin, int rangoMax, int intentos)
{
	char* auxInt;
	int aux;
	int band;

	auxInt = malloc(sizeof(int));
	//muestro el mensaje
	printf("%s", mensaje);
	//guardo el valor ingresado en el puntero
	scanf("%s", auxInt);
	//valido que no sea una letra
	band = validarLetra(auxInt);
	aux = atoi(auxInt);
	if(band==0 ||aux<rangoMin||aux>rangoMax)
	{
		//realiza intentos hasta llegar a 0
		while(intentos>0)
		{
			printf("%s", mensajeError);
			scanf("%s", auxInt);
			band = validarLetra(auxInt);
			aux = atoi(auxInt);
			if(band==0 ||aux<rangoMin||aux>rangoMax)
			{
				intentos--;
				band=-1;
			}else{
				intentos = 0;
				aux = atoi(auxInt);
			}
		}
	}else
	{
		//utilizo la variable con la que valide para guardar el numero ingresado
		//convierto el el valor de auxInt en un entero y lo guardo en la var aux
		aux = atoi(auxInt);
	}
    return aux;
}


/** \brief Pide, valida y devuelve un numero Float
 *
 * \param char* mensaje: Recibe el mensaje para pedir Float
 * \param char* mensajeError: Recibe el mensaje de error al pedir Float
 * \param int rangoMin: Numero menor que recibe la funcion
 * \param int rangoMax: Numero mayor que recibe la funcion
 * \param int intentos: Cantidad de intentos de error para cargar el numero
 *
 * \return retorna el Float
 *
 */
float cargarUnFloat(char* mensaje, char* mensajeError,int rangoMin, int rangoMax, int intentos)
{
	char* auxInt;
	float aux;
	int band;

	auxInt = malloc(sizeof(float));
	//muestro el mensaje
	printf("%s", mensaje);
	//guardo el valor ingresado en el puntero
	scanf("%s", auxInt);
	//valido que no sea una letra
	band = validarLetra(auxInt);
	aux = atof(auxInt);
	if(band==0 ||aux<rangoMin||aux>rangoMax)
	{
		//realiza intentos hasta llegar a 0
		while(intentos>0)
		{
			printf("%s", mensajeError);
			scanf("%s", auxInt);
			band = validarLetra(auxInt);
			aux = atof(auxInt);
			if(band==0 ||aux<rangoMin||aux>rangoMax)
			{
				intentos--;
				band=-1;
			}else{
				intentos = 0;
				aux = atof(auxInt);
			}
		}
	}else
	{
		//utilizo la variable con la que valide para guardar el numero ingresado
		//convierto el el valor de auxInt en un entero y lo guardo en la var aux
		aux = atof(auxInt);
	}
    return aux;
}


/** \brief Pide, valida, devuelve y pone primer caracter Mayuscula a una cadena
 *
 * \param char* guardar: variable donde se va a guardar la cadena
 * \param char* mensaje: Recibe el mensaje para pedir Float
 * \param char* mensajeError: Recibe el mensaje de error al pedir Float
 * \param int rangoMin: Numero menor que recibe la funcion
 * \param int rangoMax: Numero mayor que recibe la funcion
 * \param int intentos: Cantidad de intentos de error para cargar el numero
 *
 * \return retorna 0 si se cargo la cadena, en caso de error retorna 1
 *
 */
int getUsuario(char *guardar, char *mensaje, char *mensajeError, int rangoMin, int rangoMax, int intentos)
{
	//1.limpio el buffer
	fflush(stdin);
    int error=1;
    //2.creo una cadena auxiliar con el tamaño maximo ingresado por el usuario
    char stringAux[rangoMax];
    char aux;
    int i;
    //3.imprimo el mensaje ingresado por el usuario
    printf("%s\n",mensaje);
    //4.guardo la variable ingresada | pido el tamaño de la cadena
    fgets(stringAux,sizeof(stringAux),stdin);
    //5.Al ultimo indice le asigno "\0"
    stringAux[strlen(stringAux)-1] = '\0';
    //6.si guardar no es nulo,
    //el tamaño de auxiliar es mayor o igual al minimo y menor o igual al maximo
   // y validar letra devuelve 0 (no hay numeros)
    if(guardar !=NULL && strlen(stringAux)>=rangoMin && strlen(stringAux)<=rangoMax && validarLetra(stringAux)==0)
    {
    	strlwr(stringAux);
    	aux = toupper(stringAux[0]);
    	stringAux[0] = aux;
    	for (i = 0; i < strlen(stringAux); ++i)
    	{
    		if(stringAux[i] == ' ')
    		{
    			aux = toupper(stringAux[i+1]);
    			stringAux[i+1] = aux;
    			break;
    		}
    		i++;
    	}
    	//7.guardo la cadena del auxiliar en el puntero guardar
    	strncpy(guardar, stringAux, rangoMax);
    	//8.Devuelvo 1 porque no hubo errores
    	error=0;
    }else{
    	//9.repito en caso de error
    	while(intentos>0)
    	{
    		printf("%s", mensajeError);
    		fgets(stringAux,sizeof(stringAux),stdin);
    		stringAux[strlen(stringAux)-1] = '\0';
    		if(guardar !=NULL && strlen(stringAux)>=rangoMin && strlen(stringAux)<=rangoMax && validarLetra(stringAux)==0)
    		{
    	    	strlwr(stringAux);
    	    	aux = toupper(stringAux[0]);
    	    	stringAux[0] = aux;
    	    	for (i = 0; i < strlen(stringAux); ++i)
    	    	{
    	    		if(stringAux[i] == ' ')
    	    		{
    	    			aux = toupper(stringAux[i+1]);
    	    			stringAux[i+1] = aux;
    	    			break;
    	    		}
    	    		i++;
    	    	}
    			strncpy(guardar, stringAux, rangoMax);
    			error = 0;
    			break;
    		}
    		intentos--;
    	  }
    }

    return error;
}


/** \brief Pide, valida y devuelve una cadena
 *
 * \param char* guardar: variable donde se va a guardar la cadena
 * \param char* mensaje: Recibe el mensaje para pedir Float
 * \param char* mensajeError: Recibe el mensaje de error al pedir Float
 * \param int rangoMin: Numero menor que recibe la funcion
 * \param int rangoMax: Numero mayor que recibe la funcion
 * \param int intentos: Cantidad de intentos de error para cargar el numero
 *
 * \return retorna 0 si se cargo la cadena, en caso de error retorna 1
 *
 */
int getString(char *guardar, char *mensaje, char *mensajeError, int rangoMin, int rangoMax, int intentos)
{
	//1.limpio el buffer
	fflush(stdin);
    int error=0;
    //2.creo una cadena auxiliar con el tamaño maximo ingresado por el usuario
    char stringAux[rangoMax];
    //3.imprimo el mensaje ingresado por el usuario
    printf("%s\n",mensaje);
    //4.guardo la variable ingresada | pido el tamaño de la cadena
    fgets(stringAux,sizeof(stringAux),stdin);
    //5.Al ultimo indice le asigno "\0"
    stringAux[strlen(stringAux)-1] = '\0';
    //6.si guardar no es nulo,
    //el tamaño de auxiliar es mayor o igual al minimo y menor o igual al maximo
   // y validar letra devuelve 0 (no hay numeros)
    if(guardar !=NULL && strlen(stringAux)>=rangoMin && strlen(stringAux)<=rangoMax && validarLetra(stringAux)==0)
    {
    	//7.guardo la cadena del auxiliar en el puntero guardar
    	strncpy(guardar, stringAux, rangoMax);
    	//8.Devuelvo 1 porque no hubo errores
    	error=1;
    }else{
    	//9.repito en caso de error
    	while(intentos>0)
    	{
    		printf("%s", mensajeError);
    		fgets(stringAux,sizeof(stringAux),stdin);
    		stringAux[strlen(stringAux)-1] = '\0';
    		if(guardar !=NULL && strlen(stringAux)>=rangoMin && strlen(stringAux)<=rangoMax && validarLetra(stringAux)==0)
    		{
    			strncpy(guardar, stringAux, rangoMax);
    			error = 1;
    			break;
    		}
    		intentos--;
    	  }
    }

    return error;
}


float promedio(int numUno, int  numDos)
{
	float promedio;

	promedio= (float) numUno / numDos;
	return promedio;
}
