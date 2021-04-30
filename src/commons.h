/*
 * commons.h
 *
 *  Created on: Apr 27, 2021
 *      Author: rodrigok
 */

#ifndef COMMONS_H_
#define COMMONS_H_

/** \brief funcion que obtiene un entero
 *
 * \param pResultado int*
 * \param mensaje char* mensaje para pedir numero entero
 * \param mensajeError char* mensaje de error
 * \param minimo int limite minimo del numero entero
 * \param maximo int limite maximo del numero entero
 * \param reintentos int reintentos para ingresar el numero entero
 * \return int 1 ok / 0 error
 *
 */
int getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/** \brief funcion que obtiene un flotante
 *
 * \param pResultado float*
 * \param mensaje char* mensaje para pedir numero flotante
 * \param mensajeError char* mensaje de error
 * \param minimo int limite minimo del numero flotante
 * \param maximo int limite maximo del numero flotante
 * \param reintentos int reintentos para ingresar el numero flotante
 * \return int 1 ok / 0 error
 *
 */
int getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

/** \brief funcion que obtiene un caracter
 *
 * \param pResultado char*
 * \param mensaje char* mensaje para pedir el caracter
 * \param mensajeError char* mensaje de error
 * \param minimo int limite minimo del caracter
 * \param maximo int limite maximo del caracter
 * \param reintentos int reintentos para ingresar el caracter
 * \return int 1 ok / 0 error
 *
 */
int getChar(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);

/** \brief funcion que obtiene un string
 *
 * \param pStringResult char*
 * \param mensaje char* mensaje para pedir el string
 * \param mensajeError char* mensaje de error
 * \param minimo int limite minimo del string
 * \param maximo int limite maximo del string
 * \param reintentos int reintentos para ingresar el string
 * \return int 1 ok / 0 error
 *
 */
int getString(char* pStringResult, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


#endif /* COMMONS_H_ */
