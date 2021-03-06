/*
 ============================================================================
 Name        : TP_2.c
 Author      : Alanoca Aduviri Jonathan Gerardo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "funciones.h"
#define ELEMENTS 1000
#define LENTEXT 51


int menu();

int main(void) {
	setbuf(stdout, NULL);
	Employee arrayEmployes[ELEMENTS];
	int idAutomatico=1000;
	char seguir='n';
	int opcion;
	int cargaEmpleado=0;
	initEmployees(arrayEmployes,ELEMENTS);
	do{
		system("cls");
		switch(menu()){

			case 1:
				 if(!findFreeAddEmployee(arrayEmployes,ELEMENTS,LENTEXT, &idAutomatico)){
					 cargaEmpleado++;
					 printf("Se cagaro el usuario exitosamente.\n");
				 }

				break;
			case 2:
				if(cargaEmpleado>0){
					findmodifyEmployee(arrayEmployes,ELEMENTS,LENTEXT);
				}
				else{
					printf("Primero hay que cargar los usuarios.\n ");
				}

				break;
			case 3:
				if(cargaEmpleado>0){
					findRemoveEmployee(arrayEmployes,ELEMENTS);
				}
				else{
					printf("Primero hay que cargar los usuarios.\n ");
				}
				break;
			case 4:
				if(cargaEmpleado>0){
					printf("1-Modo ascendente.\n0- Modo descendente.\nIngrese una opcion(0/1): ");
					fflush(stdin);
					scanf("%d",&opcion);
					while(opcion!=1 && opcion!=0){
						printf("Vuelva a intentarlo. Ingrese una opcion: ");
						fflush(stdin);
						scanf("%d",&opcion);
					}
					sortEmployees(arrayEmployes,ELEMENTS,opcion);
					printEmployees(arrayEmployes,ELEMENTS);
				}
				else{
					printf("Primero hay que cargar los usuarios.\n ");
				}

				break;
			case 5:
				printf("Confirme para salir con una (s): ");
				fflush(stdin);
				scanf("%c", &seguir);
				break;
			default:
				break;
		}
		system("pause");
	}while(seguir!='s');


	return EXIT_SUCCESS;
}
