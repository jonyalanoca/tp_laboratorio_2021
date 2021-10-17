/*
 * utn.c
 *
 *  Created on: 16 oct. 2021
 *      Author: Alanoca Aduviri Jonathan Gerardo
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "funciones.h"

int esNumerico (char str[]){
	int i=0;
	while(str[i]!='\0'){
		if(str[i]<'0'  || str[i]>'9'){
			return 0;
		}
		i++;
	}
	return 1;
}
int esSoloLetras (char str[]){
	int i=0;
	while(str[i]!='\0'){
		if((str[i]!=' ') &&(str[i]<'a' || str[i]>'z') &&(str[i]<'A' || str[i]>'Z')){
			return 0;
		}
		i++;
	}
	return 1;
}
int esPositivoFlotante(char str[]){
	int i=0;
	while(str[i]!='\0'){
		if((str[i]<'0'  || str[i]>'9') && str[i]!='.'){
			return 0;
		}
		i++;
	}
	return 1;
}
