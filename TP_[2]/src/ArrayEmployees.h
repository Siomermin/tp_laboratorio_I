/*
 * ArrayEmployees.h
 *
 *  Created on: 4 oct 2021
 *      Author: Mermin
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#define TRUE 0
#define FALSE 1
#include "Input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Defines.h"

struct
{
int id;
char name[TAM_STRING];
char lastName[TAM_STRING];
float salary;
int sector;
int isEmpty;
}typedef Employee;

/// \fn int Menu(void)
/// \brief displays the menu.
/// \return the option that the user chosen.
int Menu(void);

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in AVAIBLE in all
* position of the array.
* \param list Employee* Pointer to array of employees.
* \param len int Array length.
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int InitEmployees(Employee* list, int len);

/// \fn int GetEmployee(int*, Employee*)
/// \brief Creates an employee.
/// \param refId self incremental id.
/// \param employee Pointer to array of employees.
/// \return ERROR(-1) if error or FUNCIONO(0) if Ok.
int GetEmployee(int* refId, Employee* employee);

/// \fn int IsEmpty(Employee*, int, int*)
/// \brief looks for an empty position on the array of employees.
/// \param list Pointer to array of employees.
/// \param len Array length.
/// \param refIndex pointer to the index that the function found.
/// \return ERROR(-1) if error or FUNCIONO(0) if Ok.
int IsEmpty(Employee* list, int len, int* refIndex);

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
int AddEmployee(Employee* list, int len, int id, char name[],char
lastName[],float salary,int sector);

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee* Pointer to array of employees.
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id);

/// \fn int ModifyEmployee(Employee*, int)
/// \brief Gets the employee id to modify and calls the function "ModifyEmployeeByOption" if the option that the user chose was ok.
/// \param list Pointer to array of employees.
/// \param len Array length.
/// \return ERROR(-1) if error or FUNCIONO(0) if Ok.
int ModifyEmployee(Employee* list, int len);

/// \fn int ModifyEmployeeByOption(Employee*, int, int, int)
/// \brief Modifies the employee information according to the option received by parameter.
/// \param list Pointer to array of employees.
/// \param len Array length.
/// \param auxIndex position of the employee array that contains the chosen employee to modify.
/// \param auxOption option that says what information must be modified.
/// \return ERROR(-1) if error or FUNCIONO(0) if Ok.
int ModifyEmployeeByOption(Employee* list, int len, int auxIndex, int auxOption);

/// \fn int GetIdToRemove(Employee*, int, int*)
/// \brief ask for the id of an employee to remove him.
/// \param list Pointer to array of employees.
/// \param len Array length.
/// \param refId Pointer to the id to remove.
/// \return ERROR(-1) if error or FUNCIONO(0) if Ok.
int GetIdToRemove(Employee* list, int len, int* refId);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int Array length.
* \param id int Id of the employee who is going to be removed.
* \return int Return ERROR(-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - FUNCIONO(0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee* Pointer to array of employees.
* \param len int Array length.
* \param order int INCREASING[1] indicate UP - DECREASING[0] indicate DOWN
* \return int Return ERROR(-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - FUNCIONO(0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order);

/** \brief print the content of employees array.
*
* \param list Employee* Pointer to array of employees.
* \param length int Array length.
* \return int
*
*/
int printEmployees(Employee* list, int length);

/// \fn int printAEmployee(Employee, int)
/// \brief prints the content of one employee.
/// \param employee Pointer to array of employees.
/// \param length Array length.
/// \return int Return ERROR(-1) if Error [Invalid length or NULL pointer or if can't
///find a employee] - FUNCIONO(0) if Ok
int printAEmployee(Employee employee, int length);

/// \fn int MenuCase4()
/// \brief Displays a sub menu for the case 4 for in main.
/// \return the option that the user chosen.
int MenuCase4();

/// \fn int TotalAndAverageSalary(Employee*, int)
/// \brief It calculates the total and the average of all salaries and displays them by console, then calls the "EmployeesAboveAvSalary" function.
/// \param list Pointer to array of employees.
/// \param len Array length.
/// \return int Return ERROR(-1) if Error [Invalid length or NULL pointer or if can't
///find a employee] - FUNCIONO(0) if Ok.
int TotalAndAverageSalary(Employee* list, int len);

/// \fn int EmployeesAboveAvSalary(Employee*, int, float)
/// \brief Calculates and displays employees who are above average salary.
/// \param list Pointer to array of employees
/// \param len Array length.
/// \param averageSalary The average salary.
/// \return int Return ERROR(-1) if Error [Invalid length or NULL pointer or if can't
///find a employee] - FUNCIONO(0) if Ok.
int EmployeesAboveAvSalary(Employee* list, int len, float averageSalary);

#endif /* ARRAYEMPLOYEES_H_ */
