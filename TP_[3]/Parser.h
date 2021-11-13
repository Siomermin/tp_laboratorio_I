/*
 * Parser.h
 *
 *  Created on: 4 nov 2021
 *      Author: Mermin
 */

#ifndef PARSER_H_
#define PARSER_H_
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

/// \fn int parser_SaveEmployeeToText(FILE*, LinkedList*)
/// \brief Escribe los campos de los empleados en modo texto en el archivo "data.csv"
/// \param pFile FILE*
/// \param pArrayListEmployee LinkedList*
/// \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
int parser_SaveEmployeeToText(FILE* pFile , LinkedList* pArrayListEmployee);

/// \fn int parser_SaveEmployeeToBinary(FILE*, LinkedList*)
/// \brief  Escribe los campos de los empleados en modo binario en el archivo "data.bin"
/// \param pFile FILE*
/// \param pArrayListEmployee LinkedList*
/// \return  ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
int parser_SaveEmployeeToBinary(FILE* pFile , LinkedList* pArrayListEmployee);

#endif /* PARSER_H_ */
