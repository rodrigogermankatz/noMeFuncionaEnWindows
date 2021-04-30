/*
 * commons.c
 *
 *  Created on: Apr 27, 2021
 *      Author: rodrigok
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){
    int toReturn = 0; //0 es ERROR
    int bufferInt;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0){

        do {
            printf("\t%s", mensaje);
            scanf("%d", &bufferInt);

            if(bufferInt >= minimo && bufferInt <= maximo){
                *pResultado = bufferInt;
                toReturn = 1; //salio todo bien
                break;
            } else {
                printf("\t%s\n", mensajeError);
                reintentos--;
            }
        } while (reintentos > 0);

    }

    return toReturn;
}


int getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos){
    int toReturn = 0; //0 es ERROR
    float bufferFloat;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0){

        do {
            printf("\t%s", mensaje);
            scanf("%f", &bufferFloat);

            if(bufferFloat >= minimo && bufferFloat <= maximo){
                *pResultado = bufferFloat;
                toReturn = 1; //salio todo bien
                break;
            } else {
                printf("\t%s\n", mensajeError);
                reintentos--;
            }
        } while (reintentos > 0);

    }

    return toReturn;
}

int getChar(char* pResult, char* message, char* errorMessage, char minimum, char maximum, int retry){
    int toReturn = 0; //0 es ERROR
    char bufferChar;

    if(pResult != NULL && message != NULL && errorMessage != NULL && minimum <= maximum && retry > 0){
        do {
            printf("\t%s", message);
            fflush(stdin);
            scanf("%c", &bufferChar);

            if(bufferChar >= minimum && bufferChar <= maximum){
                *pResult = bufferChar;
                toReturn = 1; //salio todo bien
                break;
            } else {
                printf("\t%s\n", errorMessage);
                retry--;
            }
        } while (retry > 0);

    }

    return toReturn;
}

int getString(char* pStringResult, char* message, char* errorMessage, int minimum, int maximum, int retry){
	int toReturn = 0; //0 es ERROR

	if(pStringResult != NULL && message != NULL && errorMessage != NULL && minimum > 0 && minimum < maximum){
		do {
			printf("\t%s", message);
            fflush(stdin);

			if(strlen(pStringResult) >= minimum && strlen(pStringResult) <= maximum && fgets(pStringResult, maximum, stdin)){
	            fflush(stdin);
				if(pStringResult[strlen(pStringResult) - 1] == '\n'){
					pStringResult[strlen(pStringResult) - 1] = '\0';
					toReturn = 1; //salio todo bien
					break;
				}
			} else {
				printf("\t%s\n", errorMessage);
				retry--;
			}

		} while (retry > 0);

	}
	return toReturn;
}
