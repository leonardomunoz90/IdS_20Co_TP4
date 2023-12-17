/************************************************************************************************
Copyright (c) 2023, Leonardo Muñoz <leonardomunoz90@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

#ifndef GPIO_H
#define GPIO_H

/** @file
 ** @brief Capa de abstraccion de GPIO con programación orientada a objetos, adaptada a C
 **/

/* === Headers files inclusions ================================================================ */

#include <stdbool.h>
#include <stdint.h>

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */
#define OUTPUT 1
#define INPUT  0

#define LOW    0
#define HIGH   1

typedef struct gpio_h * gpio_t;

/* === Public data type declarations =========================================================== */

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */

/**
 * @brief Crea un objeto de GPIO
 * @param port Número de puerto del GPIO
 * @param bit Número de bit correspondiente al GPIO
 * @return Puntero a un nueo gpio
 */
gpio_t Gpio_create(uint8_t port, uint8_t bit);

/**
 * @brief Establece la dirección de un pin
 * @param gpio Objeto GPIO a modificar
 * @param output Verdadero si se quiere setear como salida
 */
void Gpio_set_direction(gpio_t gpio, bool output);

/**
 * @brief Obtiene la dirección del pin
 * @param gpio Objeto GPIO a leer
 * @return Verdadero si el pin está seteado como salida
 */
bool Gpio_get_direction(gpio_t gpio);

/**
 * @brief Establece el estado del pin, siempre que este esté sea una entrada
 * @param gpio Objeto de GPIO a modificar
 * @param state Estado a asignar al pin
 */
void Gpio_set_state(gpio_t gpio, bool state);

/**
 * @brief Obtiene el estado de un pin
 * @param gpio Objeto de GPIO a leer
 * @return Verdadero si se encuentra en alto
 */
bool Gpio_get_state(gpio_t gpio);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* GPIO_H */
