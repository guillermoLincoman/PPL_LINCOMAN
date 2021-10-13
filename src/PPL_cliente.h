/*
 * ArrayEmployees.h
 *
 *  Created on: 6 oct. 2021
 *      Author: Compumar
 */
#include "PPL_inputs.h"

struct
{
 int idCompany;
 char name[51];
 int cuit;
 char street[51];
 int altitude;
 char city[51];
 char province[51];
 char country[51];
 int isEmpty;
}typedef eClient;


#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

int initClient(eClient list[], int len);
int BuscarLibre(eClient list[], int len);
int addClient(eClient list[], int len, int id, char name[], int cuit, char street[], int altitude, char city[], char province[], char country[]);
eClient addClientNew(int idNuevoCliente);
int findClientById(eClient list[], int len,int id);
void printClients(eClient list[], int len);
void printClient(eClient list);
int removeClient(eClient list[], int len, int ultimoId);
int modificarCliente(eClient list[], int len, int ultimoId);

#endif /* ARRAYEMPLOYEES_H_ */
