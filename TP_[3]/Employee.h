#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
#include "Input.h"
typedef struct
{
    int id;
    char nombre[LEN_NOMBRE];
    int horasTrabajadas;
    int sueldo;
}Employee;

/// \fn Employee employee_new*()
/// \brief Reserva memoria dinamicamente y se la asigna a un puntero a Employee.
/// \return Un puntero a Employee.
Employee* employee_new();

/// \fn Employee employee_newParametros*(char*, char*, char*, char*)
/// \brief Crea un puntero a empleado y le asigna una direccion mediante la funcion "employee_new()" ,
/// 	   luego utiliza los setters y los casteos para cargar cada uno de sus campos.
/// \param idStr Char del id.
/// \param nombreStr Nombre del empleado.
/// \param horasTrabajadasStr Char de las horas trabajadas.
/// \param sueldoStr Char del sueldo.
/// \return Un puntero a Employee.
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

/// \fn void employee_delete(Employee*)
/// \brief Desasigna el puntero creado por malloc y devuelve la memoria al heap,
/// 	   luego apunta el puntero a Employee a NULL.
/// \param Puntero a Employee.
void employee_delete(Employee* auxEmpleado);

/// \fn int employee_setId(Employee*, int)
/// \brief Asigna un id al puntero a Employee que llega por parametro.
/// \param this Employee*
/// \param id Int del id.
/// \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
int employee_setId(Employee* this,int id);
/// \fn int employee_getId(Employee*, int*)
/// \brief Devuelve el Id por parametro del puntero a Employee.
/// \param this Employee*
/// \param id Puntero a Int del id.
/// \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
int employee_getId(Employee* this,int* id);

/// \fn int employee_setName(Employee*, char*)
/// \brief Asigna un nombre al puntero a Employee que llega por parametro.
/// \param this Employee*
/// \param nombre Puntero a char del nombre.
/// \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
int employee_setName(Employee* this,char* nombre);
/// \fn int employee_getName(Employee*, char*)
/// \brief Devuelve el nombre por parametro del puntero a Employee.
/// \param this Employee*.
/// \param nombre Puntero a char del nombre.
/// \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
int employee_getName(Employee* this,char* nombre);

/// \fn int employee_setWorkHours(Employee*, int)
/// \brief Asigna las horas trabajadas al puntero a Employee que llega por parametro.
/// \param this Employee*
/// \param horasTrabajadas Int Horas trabajadas.
/// \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
int employee_setWorkHours(Employee* this,int horasTrabajadas);
/// \fn int employee_getWorkHours(Employee*, int*)
/// \brief Devuelve las horas trabajadas por parametro del puntero a Employee.
/// \param this Employee*
/// \param horasTrabajadas Puntero a int de las horas trabajadas.
/// \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
int employee_getWorkHours(Employee* this,int* horasTrabajadas);

/// \fn int employee_setSalary(Employee*, int)
/// \brief Asigna el sueldo al puntero a Employee que llega por parametro.
/// \param this Employee*
/// \param sueldo Int Sueldo.
/// \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
int employee_setSalary(Employee* this,int sueldo);
/// \fn int employee_getSalary(Employee*, int*)
/// \brief Devuelve el sueldo por parametro del puntero a Employee.
/// \param this Employee*.
/// \param sueldo Puntero a int del sueldo.
/// \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
int employee_getSalary(Employee* this,int* sueldo);

/// \fn int employee_getInfo(char*, int*, int*)
/// \brief Pide al usuario los datos que se van a asignar a los campos del puntero a Employee.
/// \param nombreAux Puntero a char del nombre.
/// \param horasTrabajadasAux Puntero a int de las horas trabajadas.
/// \param sueldoAux Puntero a int del sueldo.
/// \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
int employee_getInfo(char* nombreAux, int* horasTrabajadasAux, int* sueldoAux);

/// \fn int employee_searchById(LinkedList*, int)
/// \brief Recorre la lista de empleados(LinkedList) y busca que coincida la id que llega por parametro con la id de alguno de los empleados.
/// \param this LinkedList* que es la lista de empleados.
/// \param id int Id a buscar.
/// \return ERROR(-1) si hubo algun error o no coincidio ningun id y si hubo una coincidencia devuelve la posicion(i) donde se ecneuntra el empleado en la lista.
int employee_searchById(LinkedList* this, int id);

/// \fn int employee_editByOption(Employee*, int, int)
/// \brief Modifica los distintos campos de datos de los empleados segun la opcion que haya elegido el usuario.
/// \param this Employee*.
/// \param respuesta int opcion que elijio el usuario.
/// \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
int employee_editByOption(Employee* this, int respuesta);

/// \fn int employee_printAEmployee(Employee*)
/// \brief Obtiene los campos de un empleado que llega por parametro y los muestra.
/// \param this Employee*.
/// \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
int employee_printAEmployee(Employee* this);

/// \fn int employee_compareByName(void*, void*)
/// \brief Obtiene los nombres de dos empleados y los compara.
/// \param empleadoUno void* donde viene un Employee.
/// \param empleadoDos void* donde viene un Employee.
/// \return 0 si son iguales, -1 si el primero es menor que el segundo alfabeticamente,1 si el primero es mayor.
int employee_compareByName(void* empleadoUno, void* empleadoDos);

/// \fn int employee_compareById(void*, void*)
/// \brief Obtiene los id de dos empleados y los compara.
/// \param empleadoUno void* donde viene un Employee.
/// \param empleadoDos void* donde viene un Employee.
/// \return 0 si son iguales, -1 si el primero es menor que el segundo,1 si el primero es mayor.
int employee_compareById(void* empleadoUno, void* empleadoDos);

/// \fn int employee_compareByWorkHours(void*, void*)
/// \brief Obtiene las horas trabajadas de dos empleados y las compara.
/// \param empleadoUno void* donde viene un Employee.
/// \param empleadoDos void* donde viene un Employee.
/// \return 0 si son iguales, -1 si el primero es menor que el segundo, 1 si el primero es mayor.
int employee_compareByWorkHours(void* empleadoUno, void* empleadoDos);

/// \fn int employee_compareBySalary(void*, void*)
/// \brief Obtiene los salarios de dos empleados y los compara.
/// \param empleadoUno void* donde viene un Employee.
/// \param empleadoDos void* donde viene un Employee.
/// \return 0 si son iguales, -1 si el primero es menor que el segundo, 1 si el primero es mayor.
int employee_compareBySalary(void* empleadoUno, void* empleadoDos);

/// \fn int employee_getLastId(char*, int*)
/// \brief Lee el archivo "id.csv" donde esta guardado el ultimo id y los devuelve por parametro.
/// \param path puntero a char que es la Direccion donde esta el archivo.csv.
/// \param id puntero a int que es el id que leyo del archivo.csv.
/// \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
int employee_getLastId(char* path , int* id);

/// \fn int employee_SaveIdAsText(char*, int)
/// \brief Escribe en el archivo "id.csv" el id que le llega por parametro.
/// \param path char* que es la Direccion donde esta el archivo.csv.
/// \param auxId int que es el id que va a escribir.
/// \return ERROR(-1) si hubo algun error o FUNCIONO(0) si esta todo correcto.
int employee_SaveIdAsText(char* path , int auxId);

#endif // employee_H_INCLUDED
