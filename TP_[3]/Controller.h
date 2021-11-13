#include "Input.h"
#include "Menu.h"
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Parser.h"
#include "Employee.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


