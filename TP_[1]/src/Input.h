/*
 * Input.h
 *
 *  Created on: 24 sept 2021
 *      Author: Mermin
 */

#ifndef INPUT_H_
#define INPUT_H_

/// \fn int menu(int, int, int, int)
/// \brief Muestra el menú para que usuario pueda elegir alguna de las opciones, ademas reemplaza los valores "A" y "B" del mensaje por el operador que se ingreso.
/// \param operando1 Es el operando de la opcion 1 que ingresó el usuario.
/// \param operando2 Es el operando de la opcion 2 que ingresó el usuario.
/// \param flagOperando1 Indica si el usuario ya utilizó la opcion 1 del menú. (Ingresar el primer operando).
/// \param flagOperando2 Indica si el usuario ya utilizó la opcion 2 del menú. (Ingresar el segundo operando).
/// \return El número de opcion que se eligió.
int menu(int operando1, int operando2, int flagOperando1, int flagOperando2);

/// \fn void menuOperaciones(int, int)
/// \brief Muestra que operaciones se realizaron al elegir la opcion 3 del menú.
/// \param operando1 Es el operando de la opcion 1 que ingresó el usuario.
/// \param operando2 Es el operando de la opcion 2 que ingresó el usuario.
void menuOperaciones(int operando1, int operando2);

/// \fn int IngresarNumero(char[])
/// \brief permite ingresar un número entero y lo guarda en su respectiva variable.
/// \param mensaje Mensaje que le indica que tipo de dato tiene que introducir.
/// \return El número que el usuario ingresó.
int IngresarNumero(char mensaje[]);


#endif /* INPUT_H_ */
