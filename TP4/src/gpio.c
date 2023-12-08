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

/* === Headers files inclusions =============================================================== */

#include "gpio.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

/* === Macros definitions ====================================================================== */

#ifndef GPIO_MAX_INSTANCES
#define GPIO_MAX_INSTANCES 10
#endif

/* === Private data type declarations ========================================================== */
//! @brief GPIO handler
struct gpio_h
{
  uint8_t port;//!< Port of the GPIO
  uint8_t bit;//!< Bit of the GPIO
  bool output;//!< Output state of the GPIO
  bool used;//!< Flag that indicates if the GPIO is used
};
/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/**
 * @brief Allocate a GPIO instance.
 *
 * @details This function allocates a GPIO instance. The GPIO instance is
 *          allocated on the heap or stack depending on the compilation flags.
 *
 * @return gpio_t Pointer to the GPIO instance.
 */
static gpio_t allocateInstance()
{
  static struct gpio_h instances[GPIO_MAX_INSTANCES] = { 0 };

  gpio_t result = NULL;
  for (int index = 0; index < GPIO_MAX_INSTANCES; index++) {
    if (!instances[index].used) {
      result = &instances[index];
      result->used = true;
      break;
    }
  }
  return result;
}

/* === Public function implementation ========================================================== */

gpio_t gpioCreate(uint8_t port, uint8_t bit)
{
#ifdef USE_DYNAMIC_MEM
  gpio_t self = malloc(sizeof(struct gpio_h));
#else
  gpio_t self = allocateInstance();
#endif
  if (self) {
    self->port = port;
    self->bit = bit;
    self->output = false;
  }
  return self;
}

void gpioSetOutput(gpio_t self, bool output) { self->output = output; }

void gpioSetState(gpio_t self, bool state) { self->output = state; }

bool gpioGetState(gpio_t self) { return self->output; }
/* === End of documentation ==================================================================== */
