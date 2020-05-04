/*
    spi_daisy_4axis.h
    Part of Grbl_ESP32

    Pin assignments for a 4-axis machine using Triaminic drivers
    in daisy-chained SPI mode.
    https://github.com/bdring/4_Axis_SPI_CNC

    2019    - Bart Dring
    2020    - Mitch Bradley

    Grbl_ESP32 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Grbl is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Grbl_ESP32.  If not, see <http://www.gnu.org/licenses/>.
*/

#define MACHINE_NAME "SPI_DAISY_4X XYZA"

#ifdef N_AXIS
        #undef N_AXIS
#endif
#define N_AXIS 4 // can be 3 or 4. (if 3 install bypass jumper next to the A driver)

#define USE_TRINAMIC
#define TRINAMIC_DAISY_CHAIN

// Use SPI enable instead of the enable pin
// The hardware enable pin is tied to ground
#define USE_TRINAMIC_ENABLE

#define X_DRIVER_TMC2130        // Which Driver Type?
#define X_RSENSE                TMC2130_RSENSE_DEFAULT
#define X_STEP_PIN              GPIO_NUM_12
#define X_DIRECTION_PIN         GPIO_NUM_14
#define X_TRINAMIC              // using SPI control
#define X_CS_PIN                GPIO_NUM_17  // Daisy Chain, all share same CS pin

#define Y_DRIVER_TMC2130        // Which Driver Type?
#define Y_RSENSE                TMC2130_RSENSE_DEFAULT
#define Y_STEP_PIN              GPIO_NUM_27
#define Y_DIRECTION_PIN         GPIO_NUM_26
#define Y_TRINAMIC              // using SPI control
#define Y_CS_PIN                X_CS_PIN  // Daisy Chain, all share same CS pin

#define Z_DRIVER_TMC2130        // Which Driver Type?
#define Z_RSENSE                TMC2130_RSENSE_DEFAULT
#define Z_STEP_PIN              GPIO_NUM_15
#define Z_DIRECTION_PIN         GPIO_NUM_2
#define Z_TRINAMIC              // using SPI control
#define Z_CS_PIN                X_CS_PIN  // Daisy Chain, all share same CS pin


#define A_DRIVER_TMC2130        // Which Driver Type?
#define A_RSENSE        TMC2130_RSENSE_DEFAULT
#define A_STEP_PIN      GPIO_NUM_33
#define A_DIRECTION_PIN GPIO_NUM_32
#define A_TRINAMIC      // using SPI control
#define A_CS_PIN        X_CS_PIN  // Daisy Chain, all share same CS pin

// Mist is a 3.3V output
// Turn on with M7 and off with M9
#define COOLANT_MIST_PIN        GPIO_NUM_21

#define SPINDLE_PWM_PIN         GPIO_NUM_25
#define SPINDLE_ENABLE_PIN      GPIO_NUM_4

// Relay operation
// Install Jumper near relay
// For spindle Use max RPM of 1
// For PWM remove jumper and set MAX RPM to something higher ($30 setting)
// Interlock jumper along top edge needs to be installed for both versions
#define DEFAULT_SPINDLE_RPM_MAX     1 // Should be 1 for relay operation

#define PROBE_PIN               GPIO_NUM_22

#define X_LIMIT_PIN             GPIO_NUM_36
#define Y_LIMIT_PIN             GPIO_NUM_39
#define Z_LIMIT_PIN             GPIO_NUM_34
#define A_LIMIT_PIN     GPIO_NUM_35
#define LIMIT_MASK      B1111
