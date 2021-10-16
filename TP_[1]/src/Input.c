/*
 * Input.c
 *
 *  Created on: 24 sept 2021
 *      Author: Mermin
 */
#include <stdio.h>
#include <stdlib.h>
#include "Input.h"

int menu(int operando1, int operando2,int flagOperando1,int flagOperando2)
{
	int opcion;

	if(flagOperando1 == 1 && flagOperando2 == 1)
	{
		printf("\n1. Ingresar 1er operando (A=%d)\n",operando1);
		printf("2. Ingresar 2do operando (B=%d)\n",operando2);
	}
	else
	{
		if(flagOperando1 == 1)
		{
		printf("\n1. Ingresar 1er operando (A=%d)\n",operando1);
		printf("2. Ingresar 2do operando (B=y)\n");
		}
		else
		{
			if(flagOperando2 == 1)
			{
				printf("\n1. Ingresar 1er operando (A=x)\n");
				printf("2. Ingresar 2do operando (B=%d)\n",operando2);
			}
			else
			{
				printf("\n1. Ingresar 1er operando (A=x)\n");
				printf("2. Ingresar 2do operando (B=y)\n");
			}
		}
	}

	printf("3. Calcular todas las operaciones\n");
	printf("4. Informar resultados\n");
	printf("5. Salir\n");
	printf("Elija una opcion: ");
	scanf("%d", &opcion);

	return opcion;
}

void menuOperaciones(int operando1, int operando2)
{
	printf("\na) Calcular la suma (%d+%d)\n",operando1,operando2);
	printf("b) Calcular la resta (%d-%d)\n",operando1,operando2);
	printf("c) Calcular la division (%d/%d)\n",operando1,operando2);
	printf("d) Calcular la multiplicacion (%d*%d)\n",operando1,operando2);
	printf("e) Calcular el factorial (%d! y %d!)\n",operando1,operando2);
}

int IngresarNumero(char mensaje[])
{
	int numero;

		printf("%s", mensaje);
		scanf("%d",&numero);

	return numero;
}

