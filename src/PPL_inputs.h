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
#ifndef EXTRAS_H_
#define EXTRAS_H_
void menu();
void limpiar();
int validarLetra(char num[]);
int cargarUnEntero(char* mensaje, char* mensajeError,int rangoMin, int rangoMax, int intentos);
float cargarUnFloat(char* mensaje, char* mensajeError,int rangoMin, int rangoMax, int intentos);
int getUsuario(char *guardar, char *mensaje, char *mensajeError, int rangoMin, int rangoMax, int intentos);
int getString(char *guardar, char *mensaje, char *mensajeError, int rangoMin, int rangoMax, int intentos);

#endif /* EXTRAS_H_ */
