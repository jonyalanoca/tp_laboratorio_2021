/*
 ============================================================================
*Programa   :TP 1
*
*Objetivo   :Realizar una cacluladora con las operaciones:
			 Sumar, restar, multiplicar dividir y el factorial

*Version    : 0.1 23/09/21
*Autor      : Alanoca Aduviri Jonathan Gerardo (Div A)
*
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void) {
	setbuf(stdout, NULL);
	int num1=0;
	int num1Validado=0;
	int num2=0;
	int num2Validado=0;
	int suma;
	int resta;
	int multiplicacion;
	float division;
	long factorial1=0;
	long factorial2=0;
	int continuar=1;
	char confirmar;
	int calculoExitoso=0;
	do{
		switch(menu(num1Validado, num2Validado, num1, num2)){
			case 1:
				if (ingresarNumero(&num1)){
					calculoExitoso=0;
					num1Validado=1;
				}
				else{
					printf("No se pudo cargar el 1er operando.\n");
				}
				break;
			case 2:
				if (ingresarNumero(&num2)){
					calculoExitoso=0;
					num2Validado=1;
				}
				else{
					printf("No se pudo cargar el 2do operando.\n");
				}
				break;
			case 3:
				if(!num1Validado || !num2Validado){
					printf("Antes de calcular, por favor cargar los valores de los operandos.\n");
				}
				else{

					printf("Se han calculado las operaciones al %d %%.\n",calcularOperaciones(num1,num2, &suma, &resta, &multiplicacion, &division, &factorial1, &factorial2));
					calculoExitoso=1;
				}
				break;
			case 4:
				if(calculoExitoso){
					resultados(suma, resta, multiplicacion, division, factorial1, factorial2, num1, num2);
				}
				else{
					printf("Antes tenemos que calcular las operaciones\n");
				}

				break;
			case 5:
				printf("¿Esta seguro que desea salir?.\nPresione s para confirmar: ");
				fflush(stdin);
				scanf("%c", &confirmar);
				if(confirmar=='s'){
					continuar=0;
				}
				break;
			default:
				printf("Por favor intente nuevamente.\n");
		}
		system("pause");
	}while(continuar);
	return EXIT_SUCCESS;
}
