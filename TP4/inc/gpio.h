/************************************************************************************************
Copyright (c) 2023, Iriarte Nicolas <NicolasIriarte95@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

#ifndef GPIO_H
#define GPIO_H

/* === Headers files inclusions ================================================================ */

#include <stdbool.h>
#include <stdint.h>

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

/* === Public data type declarations =========================================================== */

/**
 * @brief Opaque data type that represents a GPIO.
 *
 * @details This data type is used to represent a GPIO. It is an opaque data
 *          type, so the user can not access to the data directly.
 */
typedef struct gpio_h *gpio_t;

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */
/**
 * @brief Create a GPIO object.
 *
 * @details This function creates a GPIO object. The GPIO object is used to
 *          control a GPIO. The GPIO will be allocated on the heap or stack
 *          depending on the compilation flags.
 *
 * @param port The port of the GPIO.
 *
 * @param bit The bit of the GPIO.
 *
 * @return return A pointer to the GPIO object.
 */
gpio_t gpioCreate(uint8_t port, uint8_t bit);

/**
 * @brief Set the GPIO as input or output.
 *
 * @details This function sets the GPIO as input or output.
 *
 * @param gpio The GPIO object.
 *
 * @param output True if the GPIO is output, false if the GPIO is input.
 *
 */
void gpioSetOutput(gpio_t gpio, bool output);

/**
 * @brief Set the state of the GPIO.
 *
 * @details This function sets the state of the GPIO.
 *
 * @param gpio The GPIO object.
 *
 * @param state True if the GPIO is high, false if the GPIO is low.
 *
 */
void gpioSetState(gpio_t gpio, bool state);

/**
 * @brief Get the state of the GPIO.
 *
 * @details This function gets the state of the GPIO.
 *
 * @param gpio The GPIO object.
 *
 * @return True if the GPIO is high, false if the GPIO is low.
 *
 */
bool gpioGetState(gpio_t gpio);
/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* GPIO_H */
