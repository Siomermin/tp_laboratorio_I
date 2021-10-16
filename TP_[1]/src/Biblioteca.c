/*
 * Biblioteca.c
 *
 *  Created on: 20 sept 2021
 *      Author: Mermin
 */

#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"

// Biblioteca.c de funciones matematicas.

int SumaOperandos(int operando1, int operando2)
{
	int suma;

	suma = operando1 + operando2;

	return suma;
}

int RestaOperandos(int operando1, int operando2)
{
	int resta;

	resta = operando1 - operando2;

	return resta;
}

int DivisionOperandos(int operando1, int operando2, float* refDivision)
{
	float division;
	int casoError = 1;

	if(operando2 != 0)
	{
		division = (float)operando1 / operando2;
		casoError = 0;
	}

	*refDivision = division;

	return casoError;
}

int MultiplicacionOperandos(int operando1, int operando2)
{
	int multiplicacion;

	multiplicacion = operando1 * operando2;

	return multiplicacion;
}

int CalcularFactorial(int operando)
{
	int resultado;

	if(operando < 0)
	{
		resultado = 0;
	}
	else
	{
		if(operando == 0)
		{
			resultado = 1;
		}
		else
		{
			resultado = operando * CalcularFactorial(operando - 1);
		}
	}

	return resultado;
}


