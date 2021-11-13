/*
 * Menu.h
 *
 *  Created on: 29 oct 2021
 *      Author: Mermin
 */
#include "Defines.h"
#include <stdio.h>
#include <stdlib.h>
#include "Input.h"

#ifndef MENU_H_
#define MENU_H_

/// \fn int Menu(void)
/// \brief El menu principal.
/// \return int la opcion que el usuario eligio si es correcto o ERROR(-1) si hubo un error.
int Menu(void);

/// \fn int MenuModify(void)
/// \brief El menu con las opciones para modificar.
/// \return int la opcion que el usuario eligio si es correcto o ERROR(-1) si hubo un error.
int MenuModify(void);

/// \fn int MenuSort(void)
/// \brief El menu con las opciones para ordenar.
/// \return int la opcion que el usuario eligio.
int MenuSort(void);

/// \fn int SubMenuOrder(void)
/// \brief El sub menu con las opciones para ordenar en ascendente o descendente.
/// \return int la opcion que el usuario eligio si es correcto o ERROR(-1) si hubo un error.
int SubMenuOrder(void);

/// \fn int SubMenuRemove(void)
/// \brief
/// \return int la opcion que el usuario eligio si es correcto o ERROR(-1) si hubo un error.
int SubMenuRemove(void);

#endif /* MENU_H_ */
