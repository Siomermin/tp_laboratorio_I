/*
 ============================================================================
 Name        : Calculadora TP.
 Author      : Fermin Gonzalez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"
#include "Input.h"

int main(void) {
	setbuf(stdout, NULL);

// Opcion que elige el usuario.
int opcion;

// Operandos.
int operando1;
int operando2;

// Resultados y casos de error.
int resultadoSuma;
int resultadoResta;
float resultadoDivision;
int casoErrorDivision;
int resultadoMultiplicacion;
int resultadoFactorial1;
int resultadoFactorial2;

// Validacion opciones menu.
int flagOperando1;
int flagOperando2;
int flagOperaciones;


	do
	{
		opcion = menu(operando1, operando2, flagOperando1, flagOperando2);

		switch(opcion)
		{
			case 1:
				operando1 = IngresarNumero("Ingrese su primer operando : ");
				flagOperando1 = 1;
			break;
			case 2:
				operando2 = IngresarNumero("Ingrese su segundo operando : ");
				flagOperando2 = 1;
			break;
			case 3:
				if(flagOperando1 == 1 && flagOperando2 == 1)
				{
					menuOperaciones(operando1, operando2);
					resultadoSuma = SumaOperandos(operando1, operando2);
					resultadoResta = RestaOperandos(operando1, operando2);
					casoErrorDivision = DivisionOperandos(operando1, operando2, &resultadoDivision);
					resultadoMultiplicacion = MultiplicacionOperandos(operando1, operando2);
					resultadoFactorial1 = CalcularFactorial(operando1);
					resultadoFactorial2 = CalcularFactorial(operando2);
					flagOperaciones = 1;
				}
				else
				{
					printf("Necesitas ingresar los dos operandos antes de realizar las operaciones.\n");
				}
			break;
			case 4:
				if(flagOperaciones == 1)
				{
					printf("\na) El resultado de %d + %d es : %d\n",operando1, operando2, resultadoSuma);
					printf("b) El resultado de %d - %d es : %d\n",operando1, operando2, resultadoResta);
					if(casoErrorDivision == 0)
					{
						printf("c) El resultado de %d / %d es : %.2f\n",operando1, operando2, resultadoDivision);
					}
					else
					{
						printf("c) No es posible dividir por 0\n");
					}
					printf("d) El resultado de %d * %d es : %d\n",operando1, operando2, resultadoMultiplicacion);

					if(resultadoFactorial1 == 0)
					{
						printf("e) No es posible calcular el factorial de %d\n",operando1);
					}
					else
					{
						printf("e) El factorial de %d es: %d\n",operando1,resultadoFactorial1);
					}

					if(resultadoFactorial2 == 0)
					{
						printf("e) No es posible calcular el factorial de %d\n",operando2);
					}
					else
					{
						printf("e) El factorial de %d es: %d\n",operando2,resultadoFactorial2);
					}
				}
				else
				{
					printf("Necesitas realizar las operaciones antes de mostrar los resultados.\n");
				}
			break;

			case 5:
			break;

			default:
				printf("Opcion invalida, porfavor intentelo otra vez.\n");
		}
	} while (opcion != 5);


	return EXIT_SUCCESS;
}
