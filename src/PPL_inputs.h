/*
 * extras.h
 *
 *  Created on: 6 oct. 2021
 *      Author: Compumar
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <unistd.h>
#define OCUPADO 0
#define VACIO -1
#define PROCESADO 0
#define PENDIENTE -1
#define TC 100
#define TP 1000
#define TE 2

#ifndef EXTRAS_H_
#define EXTRAS_H_
void menu();
void menuInformes();
void limpiar();
int validarLetra(char num[]);
int cargarUnEntero(char* mensaje, char* mensajeError,int rangoMin, int rangoMax, int intentos);
float cargarUnFloat(char* mensaje, char* mensajeError,int rangoMin, int rangoMax, int intentos);
int getUsuario(char *guardar, char *mensaje, char *mensajeError, int rangoMin, int rangoMax, int intentos);
int getString(char *guardar, char *mensaje, char *mensajeError, int rangoMin, int rangoMax, int intentos);
float promedio(int numUno, int  numDos);

#endif /* EXTRAS_H_ */
