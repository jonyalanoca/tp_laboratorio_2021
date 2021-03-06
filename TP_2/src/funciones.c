/*
 * funciones.c
 *
 *  Created on: 16 oct. 2021
 *      Author: Alanoca Aduviri Jonathan Gerardo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "funciones.h"

int initEmployees(Employee* list,int len){
	int todoOk=-1;
	if(list!=NULL && len>0){
		for(int i=0; i<len;i++){
			list[i].isEmpty=1;
		}
		todoOk=0;
	}
	return todoOk;
}
int findFreeAddEmployee(Employee* list, int len,int lenStr,int* idAuto){
	int todoOk=-1;
	if (list !=NULL && len>0 && lenStr>0){
		int id;
		char name[lenStr];
		char lastName[lenStr];
		float salary;
		int sector;
		char auxNum[10];

		if(findFreeEmployee(list, len)!=-1){
			printf("............Alta de Usuario...........\n\n");
			id=*idAuto;
			(*idAuto)++;
			printf("Ingrese el nombre del empleado: ");
			fflush(stdin);
			gets(name);
			while(!esSoloLetras(name)){
				printf("Valores invalidos. Ingrese el nombre del empleado: ");
				fflush(stdin);
				gets(name);
			}
			printf("Ingrese el apellido del empleado: ");
			fflush(stdin);
			gets(lastName);
			while(!esSoloLetras(lastName)){
				printf("Valores invalidos. Ingrese el apellido del empleado: ");
				fflush(stdin);
				gets(lastName);
			}
			printf("Ingrese el salario del empleado: ");
			fflush(stdin);
			gets(auxNum);
			while(!esPositivoFlotante(auxNum)){
				printf("Ingrese el salario del empleado: ");
				fflush(stdin);
				gets(auxNum);
			}
			salary=atof(auxNum);
			printf("Ingrese el sector del empleado (numerico): ");
			fflush(stdin);
			gets(auxNum);
			while(!esNumerico(auxNum)){
				printf("Valores invalidos. Ingrese el sector del empleado: ");
				fflush(stdin);
				gets(auxNum);
			}
			sector=atoi(auxNum);

			if(addEmployee(list, len, id,name, lastName, salary, sector)==-1){
				printf("No se pudieron cargar los valores.\n");
			}
		}
		else{
			printf("No hay espacio disponible.\n");
		}
		todoOk=0;
	}

	return todoOk;
}
int findFreeEmployee(Employee* list, int len){
	int indexLibre=-1;
	if (list !=NULL && len>0){
			for(int i =0; i<len; i++){
				if(list[i].isEmpty==1){
					indexLibre=i;
					break;
				}
			}
		}
	return indexLibre;
}

int addEmployee(Employee* list, int len, int id, char name[], char lastName[],float salary, int sector){
	int todoOk=-1;
	int indexLibre;

	if (list !=NULL && len>0){
		indexLibre=findFreeEmployee(list, len);
		if(indexLibre>-1){
			list[indexLibre].id=id;
			strlwr(name);
			strlwr(lastName);
			name[0]=name[0]-32;
			lastName[0]=lastName[0]-32;
			strcpy(list[indexLibre].name,name);
			strcpy(list[indexLibre].lastName,lastName);
			list[indexLibre].sector=sector;
			list[indexLibre].salary=salary;
			list[indexLibre].isEmpty=0;
			todoOk=0;
		}
	}
	return todoOk;
}
int findRemoveEmployee(Employee* list, int len){
	int todoOk=0;
	int indexInt;
	int indexLocalizado;
	char auxNumero[10];
	if(list!=NULL && len>0){
		if(printEmployees(list, len)==-1){
			printf("No su pudo mostrar la lista de empleados.\n");
		}
		printf("............Baja de Usuario...........\n\n");
		printf("Ingrese el id: ");
		fflush(stdin);
		gets(auxNumero);
		while(!esNumerico(auxNumero)){
			printf("Vuelva a intentarlo. Ingrese el id: ");
			fflush(stdin);
			gets(auxNumero);
		}
		indexInt=atoi(auxNumero);
		indexLocalizado=findEmployeeById(list, len,indexInt);
		if(indexLocalizado==-1){
			printf("No se hallo el id seleccioado,\n");
		}
		if(removeEmployee(list, len,indexLocalizado)==-1){
			printf("No se puedo borrar al usuario seleccionado.\n");
		}
		else{
			printf("Se ha borrado con exito.\n");
		}
	}
	return todoOk;
}
int findEmployeeById(Employee* list, int len,int id){
	int index=-1;
	if(list!=NULL && len>0 && id>=1000){
		for(int i=0;i<len;i++){
			if(list[i].id==id){
				index=i;
			}
		}
	}
	return index;
}
int removeEmployee(Employee* list, int len, int id)
{
	char confirmar;
	int todoOk=-1;
	if(list!=NULL && len>0 && id>-1){
		printf("Confirmar si que desea borrar el siguiente empleado(SI = s)\n");
		printf("ID\t    NOMBRE\t   APELLIDO\t SALARIO	SECCION\n");
		printEmployee(list[id]);
		printf("Confirme con una (s): ");
		fflush(stdin);
		scanf("%c", &confirmar);
		if (confirmar=='s'){
			list[id].isEmpty=1;
			todoOk=0;
		}
	}
	return todoOk;
}
int sortEmployees(Employee* list, int len, int order)
{
	int todoOk=0;
	Employee auxEmpleado;
	if(list!=NULL && len>0 && (order==1 || order==0)){
		for(int i=0; i<len-1;i++){
			for(int u=0; u<len-1;u++){
				if(order==1){
					if(strcmp(list[i].lastName,list[u].lastName)==-1){
						auxEmpleado=list[i];
						list[i]=list[u];
						list[u]=auxEmpleado;
					}
					else if(strcmp(list[i].lastName,list[u].lastName)==0){
						if(list[i].sector<list[u].sector){
							auxEmpleado=list[i];
							list[i]=list[u];
							list[u]=auxEmpleado;
						}
					}
				}
				if(order==0){
					if(strcmp(list[i].lastName,list[u].lastName)==1){
						auxEmpleado=list[i];
						list[i]=list[u];
						list[u]=auxEmpleado;
					}
					else if(strcmp(list[i].lastName,list[u].lastName)==0){
						if(list[i].sector>list[u].sector){
							auxEmpleado=list[i];
							list[i]=list[u];
							list[u]=auxEmpleado;
						}
					}
				}
			}
		}
	}
	return todoOk;
}
int findmodifyEmployee(Employee* list, int len, int lenStr){
	int todoOk=0;
	int indexInt;
	int indexLocalizado;
	char auxNumero[10];
	if(list!=NULL && len>0){
		if(printEmployees(list, len)==-1){
			printf("No su pudo mostrar la lista de empleados.\n");
		}
		printf("............Modificar de Usuario...........\n\n");
		do{
			printf("Ingrese el id: ");
			fflush(stdin);
			gets(auxNumero);
			while(!esNumerico(auxNumero)){
				printf("Vuelva a intentarlo. Ingrese el id: ");
				fflush(stdin);
				gets(auxNumero);
			}
			indexInt=atoi(auxNumero);
			indexLocalizado=findEmployeeById(list, len,indexInt);
		}while(findEmployeeById(list, len,indexInt)==-1);
		if(modifyEmployee(list, len,indexLocalizado,lenStr)==-1){
			printf("No se puedo modificar al usuario seleccionado.\n");
		}
		else{
			printf("Se ha Modificado con exito.\n");
		}
	}
	return todoOk;
}
int modifyEmployee(Employee* list, int len, int idLoc,int lenStr){
	int todoOk=-1;
	if (list!=NULL && len>0){
		char name[lenStr];
		char lastName[lenStr];
		float salary;
		int sector;
		char auxNum[10];
		printf("Ingrese el nombre del empleado: ");
		fflush(stdin);
		gets(name);
		while(!esSoloLetras(name)){
			printf("Valores invalidos. Ingrese el nombre del empleado: ");
			fflush(stdin);
			gets(name);
		}
		printf("Ingrese el apellido del empleado: ");
		fflush(stdin);
		gets(lastName);
		while(!esSoloLetras(lastName)){
			printf("Valores invalidos. Ingrese el apellido del empleado: ");
			fflush(stdin);
			gets(lastName);
		}
		printf("Ingrese el salario del empleado: ");
		fflush(stdin);
		gets(auxNum);
		while(!esPositivoFlotante(auxNum)){
			printf("Ingrese el salario del empleado: ");
			fflush(stdin);
			gets(auxNum);
		}
		salary=atof(auxNum);
		printf("Ingrese el sector del empleado(numerico): ");
		fflush(stdin);
		gets(auxNum);
		while(!esNumerico(auxNum)){
			printf("Valores invalidos. Ingrese el sector del empleado(numerico): ");
			fflush(stdin);
			gets(auxNum);
		}
		sector=atoi(auxNum);
		strlwr(name);
		strlwr(lastName);
		name[0]=name[0]-32;
		lastName[0]=lastName[0]-32;
		strcpy(list[idLoc].name,name);
		strcpy(list[idLoc].lastName,lastName);
		list[idLoc].salary=salary;
		list[idLoc].sector=sector;
		todoOk=0;
	}
	return todoOk;
}

void printEmployee(Employee list)
{
	printf("%d\t%10s\t%10s\t$ %8.2f\t   %d\n",list.id,list.name,list.lastName,list.salary,list.sector);
}
int printEmployees(Employee* list, int length)
{
	int todoOk=-1;
	if(list!=NULL && length>0){
		printf("ID\t    NOMBRE\t   APELLIDO\t SALARIO	SECCION\n");
		printf("---------------------------------------------------------------\n");
		for(int i=0;i<length;i++){
			if(list[i].isEmpty==0){
				printEmployee(list[i]);
			}

		}
		todoOk=0;
	}


 return todoOk;
}
int menu(){
	int opcion;
	printf("1- Alta de empleado.\n");
	printf("2- Modificar empleado.\n");
	printf("3- Baja de empleado.\n");
	printf("4- Informar.\n");
	printf("5- Salir.\n");
	printf("_______________________\n");
	printf("Elija una opcion: ");
	scanf("%d", &opcion);
	system("pause");
	system("cls");
	return opcion;
}
