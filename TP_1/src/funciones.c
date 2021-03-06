/*
 * funciones.c
 *
 *  Created on: 23 sep. 2021
 *      Author: Alanoca Aduviri Jonathan Gerardo
 */
#include <stdio.h>
#include "funciones.h"

int menu(int num1Validado,int  num2Validado, int num1,int num2){
	int opcion;
	system("cls");
	if(num1Validado==0){
		printf("1- Ingresar el 1er operando (A).\n");
	}
	else{
		printf("1- Ingresar el 1er operando (A=%d).\n", num1);
	}
	if (num2Validado==0){
		printf("2- Ingresar el 2do operando (B).\n");
	}
	else{
		printf("2- Ingresar el 2do operando (B=%d).\n", num2);
	}
	if(num1Validado==0 || num2Validado==0){
		printf("3- Calcular todas las operaciones.\n");
	}
	else{
		printf("3- Calcular todas las operaciones.\n");
		printf("\t-La suma (%d + %d)\n", num1, num2);
		printf("\t-La resta (%d + %d)\n", num1, num2);
		printf("\t-La division (%d / %d)\n", num1, num2);
		printf("\t-La multiplicacion (%d * %d)\n", num1, num2);
		printf("\t-El factorial (%d!) y (%d!)\n", num1, num2);
	}
	printf("4- informar resultados.\n");
	printf("5- Salir.\n");
	printf("\n---------------------------------------\n");
	scanf("%d", &opcion);
	fflush(stdin);
	return opcion;
}

int ingresarNumero(int* numero){
	int todoOk=0;
	if (numero!=NULL){
		printf("Ingrese: ");
		todoOk=scanf("%d", numero);
		fflush(stdin);
	}
	return todoOk;
}

int calcularOperaciones(int numero1,int numero2,int* pSuma, int* pResta, int* pMultiplicacion, float* pDivision, long int* pFactorial1, long int* pFactorial2){
	int i;
	int porcentaje=0;
	if(pSuma!=NULL){
		*pSuma=numero1+numero2;
		*pFactorial1=0; //Reseteo el  factorial a 0 cuando midifico el valor del numero
		porcentaje++;
	}
	if (pResta!=NULL){
		*pResta=numero1-numero2;
		*pFactorial2=0;//Reseteo el  factorial a 0 cuando midifico el valor del numero
		porcentaje++;
	}
	if (pMultiplicacion!=NULL){
		*pMultiplicacion=numero1*numero2;
		porcentaje++;
	}

	if(pDivision!= NULL && numero2!=0){
		*pDivision=(float) numero1/numero2;
		porcentaje++;
	}
	if (pFactorial1!= NULL && numero1>=0 && numero1<=20){
		*pFactorial1=1;
		porcentaje++;
		for(i=1; i<=numero1;i++){
			*pFactorial1*=i;
		}
	}
	if (pFactorial2!=NULL && numero2>=0 && numero2<=20){
		*pFactorial2=1;
		porcentaje++;
		for(i=1; i<=numero2;i++){
			*pFactorial2*=i;
		}
	}
	return porcentaje*100/6;
}
void resultados(int suma,int resta,int multiplicacion,float division,long int factorial1,long int factorial2,int numero1,int numero2){
	printf("El resultado de %d+%d es: %d\n",numero1, numero2, suma);
	printf("El resultado de %d-%d es: %d\n",numero1, numero2, resta);

	if(multiplicacion==0 && resta==suma){// Lo que quiero verificar es si el 2do operado es cero
		printf("No existe la division por cero.\n");
	}else{
		printf("El resultado de %d/%d es: %.4f\n",numero1,numero2, division);
	}


	printf("El resultado de %d*%d es: %d\n",numero1,numero2, multiplicacion);

	if(factorial1==0){
		printf("El factorial de %d es: No podemos calcular un factorial menor a 0 o mayor a 20 ", numero1);
	}
	else{
		printf("El factorial de %d es: %ld ",numero1, factorial1);
	}
	if(factorial2==0){
		printf("y el factorial de %d es: No podemos calcular un factorial menor a 0 o mayor a 20.\n", numero2);
	}
	else{
		printf("y el factorial de %d es: %ld \n",numero2,  factorial2);
	}
}
