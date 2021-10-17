/*
 * funciones.h
 *
 *  Created on: 16 oct. 2021
 *      Author: Alanoca Aduviri Jonathan Gerardo
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

struct{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}typedef Employee;

#endif /* FUNCIONES_H_ */
/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list,int len);
/// @fn int findFreeAddEmployee(Employee*, int, int, int*)
/// @brief recorre la estructura hasta encontrar un lugar libre, pide los datos al usuario y los guarda en el index encontrado
///
/// @param list
/// @param len
/// @param lenStr
/// @param idAuto
/// @return
int findFreeAddEmployee(Employee* list, int len,int lenStr,int* idAuto);
/// @fn int findFreeEmployee(Employee*, int)
/// @brief busca dentro la estructura index libre
///
/// @param list
/// @param len
/// @return
int findFreeEmployee(Employee* list, int len);
/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int addEmployee(Employee* list, int len, int id, char name[], char lastName[],float salary, int sector);
/// @fn int findRemoveEmployee(Employee*, int)
/// @brief pide al usuario un id luego busca dentro de la estructura y elimina al usuario
///
/// @param list
/// @param len
/// @return
int findRemoveEmployee(Employee* list, int len);
/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */

int findEmployeeById(Employee* list, int len,int id);
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id);
/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order);
/// @fn int findmodifyEmployee(Employee*, int, int)
/// @brief pide una id al usuario luego busca dntro de la estructura, pide los nuevos datos del empleado y los modifica
///
/// @param list
/// @param len
/// @param lenStr
/// @return
int findmodifyEmployee(Employee* list, int len, int lenStr);
/// @fn int modifyEmployee(Employee*, int, int, int)
/// @brief carga los datos nuevos dentro de la estructura
///
/// @param list
/// @param len
/// @param id
/// @param lenStr
/// @return
int modifyEmployee(Employee* list, int len, int id,int lenStr);
/// @fn void printEmployee(Employee)
/// @brief muestra un array en forma ordena y en columnas
///
/// @param list
void printEmployee(Employee list);
/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee* list, int length);
