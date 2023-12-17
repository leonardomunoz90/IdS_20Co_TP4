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

/** @file
 ** @brief  Implementación de capa abstraccion de GPIO.
 **/

/* === Headers files inclusions =============================================================== */

#include "gpio.h"
#include <stdint.h>
#include <stdbool.h>

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

//! Estructura con los atributos de un puerto digital
struct gpio_h {
    uint8_t port; //!< Número de puerto del gpio
    uint8_t pin;  //!< Número del pin del gpio
    bool state;   //!< Estado actual del puerto
    bool output;  //!< Indica si el pin es salida
};

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================== */

gpio_t Gpio_create(uint8_t port, uint8_t bit) {
    gpio_t self = malloc(sizeof(struct gpio_h));
    if (self) {
        self->port = port;
        self->pin = bit;
    }
    return self;
}

void Gpio_set_direction(gpio_t self, bool output) {
    self->output = output;
}

bool Gpio_get_direction(gpio_t self) {
    return self->output;
}

void Gpio_set_state(gpio_t self, bool state) {
    if (self->output)
        self->state = state;
}

bool Gpio_get_state(gpio_t self) {
    return self->state;
}

/* === End of documentation ==================================================================== */
