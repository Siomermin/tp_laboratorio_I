/*
 * Biblioteca.h
 *
 *  Created on: 20 sept 2021
 *      Author: Mermin
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

// Biblioteca.h de funciones matematicas.

/// \fn int SumaOperandos(int, int)
/// \brief Calcula la suma de dos números enteros.
/// \param operando1 Es el operando de la opcion 1 que ingresó el usuario.
/// \param operando2 Es el operando de la opcion 2 que ingresó el usuario.
/// \return El resultado de la suma de los dos operandos.
int SumaOperandos(int operando1, int operando2);

/// \fn int RestaOperandos(int, int)
/// \brief Calcula la resta de dos números enteros.
/// \param operando1 Es el operando de la opcion 1 que ingresó el usuario.
/// \param operando2 Es el operando de la opcion 2 que ingresó el usuario.
/// \return El resultado de la resta de los dos operandos.
int RestaOperandos(int operando1, int operando2);

/// \fn int DivisionOperandos(int, int, float*)
/// \brief Calcula la división de dos números enteros y contempla que no se divida por 0, el resultado de la división se devuelve por referencia.
/// \param operando1 Es el operando de la opcion 1 que ingresó el usuario.
/// \param operando2 Es el operando de la opcion 2 que ingresó el usuario.
/// \param refDivision dirección de la variable donde se guarda el resultado de la división.
/// \return Retorna si hubo algun error a la hora de hacer la división.
int DivisionOperandos(int operando1, int operando2, float* refDivision);

/// \fn int MultiplicacionOperandos(int, int)
/// \brief Calcula la multiplicación de dos números enteros.
/// \param operando1 Es el operando de la opcion 1 que ingresó el usuario.
/// \param  operando2 Es el operando de la opcion 2 que ingresó el usuario.
/// \return El resultado de la multiplicación de los operandos.
int MultiplicacionOperandos(int operando1, int operando2);

/// \fn int CalcularFactorial(int)
/// \brief Calcula el factorial de un número entero, además contempla que el número ingresado no sea menor a cero.
/// \param operando Es uno de los operandos que ingresó el usuario.
/// \return El resultado del factorial. Si el resultado es igual a cero, significa que el factorial no pudo realizarse.
int CalcularFactorial(int operando);


#endif /* BIBLIOTECA_H_ */
