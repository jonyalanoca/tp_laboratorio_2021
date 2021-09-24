/*
 * funciones.h
 *
 *  Created on: 23 sep. 2021
 *      Author: Alanoca Aduviri Jonathan Gerardo
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#endif /* FUNCIONES_H_ */
/// @fn void resultados(int, int, int, float, long int, long int, int, int)
/// @brief Esta funcion muestra los resultados obtenidos de suma, resta , multiplicacion, division y los factoriales
///
/// @param suma  			muestra la suma de numero1 y numero2
/// @param resta 			muestra  resta de numero1 y numero2
/// @param multiplicacion 	muestra la multiplicacion de numero1 y numero2
/// @param division			muestra la division de numero1 y numero2 (excepto si numero2 es cero).
/// @param factorial1		muestra el factorial del numero1 (excepto si es menor a cero o mayor a veinte.)
/// @param factorial2		muestra el factorial del numero2 (excepto si es menor a cero o mayor a veinte.)
/// @param numero1			es el numero para mostrar.
/// @param numero2			es el numero para mostrar
void resultados(int suma,int resta,int multiplicacion,float division,long int factorial1,long int factorial2, int numero1, int numero2);

/// @fn int calcularOperaciones(int, int, int*, int*, int*, float*, long int*, long int*)
/// @brief esta funcion calcula de las operaciones de los datos cargados previamente por el usuario. Hace: suma, resta, multiplicacion, division y factoriales.
///
/// @param num1				es el numero con el que vamos a operar
/// @param num2				es el numero con el que vamos a operar
/// @param suma				(puntero)suma el num1 y el num2.
/// @param pResta			(puntero) resta num1 menos num2
/// @param pMultiplicacion	(puntero) multiplica el num1 y num2
/// @param pDivisions		(puntero) divide num1 con num2, excepto si es cero
/// @param pFactorial1		(puntero) calcula el factorial de num1. excepto si es menor a cero y mayor a 20
/// @param pFactotial2		(puntero) calcula el factorial de num2. excepto si es menor a cero y mayor a 20
/// @return					devuelve el porcentaje de las operaciones que se han realizado con exito
int calcularOperaciones(int num1,int  num2,int* suma, int* pResta, int* pMultiplicacion, float* pDivisions, long int* pFactorial1, long int* pFactotial2);

/// @fn int ingresarNumero(int*)
/// @brief esta funcion valida y carga los valores numericos
///
/// @param numero 			(puntero) Aca se cargan los valores una vez validado el puntero
/// @return nos devuelve 0 si no se puedo cargar el valor numerico o devuelve 1 si se cargo correctamente un numero entero
int ingresarNumero(int* numero);

/// @fn int menu(int, int, int, int)
/// @brief Esta funcion nos muestra el menu de opcione, como: cargar numeros, calcular operaciones, mostrar resultados y salir. Tambien valida que no ingrese una opcion incorrecta
///
/// @param num1Validado		Valor que mostramos en pantalla junto al menu
/// @param num2Validado		Valor que mostramos en pantalla junto al menu
/// @param num1				Valor que mostramos en pantalla junto al menu
/// @param num2				Valor que mostramos en pantalla junto al menu
/// @return	Nos retorna el numero que el usuario ellijio del menu.
int menu(int num1Validado,int  num2Validado, int num1,int num2);
