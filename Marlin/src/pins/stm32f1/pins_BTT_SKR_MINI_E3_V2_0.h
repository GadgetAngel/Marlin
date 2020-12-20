/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

#define SKR_MINI_E3_V2

// Onboard I2C EEPROM
#if NO_EEPROM_SELECTED
  #define I2C_EEPROM
  #define MARLIN_EEPROM_SIZE 0x1000                 // 4KB
  #undef NO_EEPROM_SELECTED
#endif

#include "pins_BTT_SKR_MINI_E3_common.h"

#ifndef BOARD_INFO_NAME
  #define BOARD_INFO_NAME "BTT SKR Mini E3 V2.0"
#endif

// Release PA13/PA14 (led, usb control) from SWD pins
#define DISABLE_DEBUG

//#define NEOPIXEL_PIN                       PA8   // LED driving pin

//#define PS_ON_PIN                          PC13  // Power Supply Control

#define FAN1_PIN                           PC7

#ifndef CONTROLLER_FAN_PIN
  #define CONTROLLER_FAN_PIN               FAN1_PIN
#endif

#if HAS_TMC_UART
  /**
   * TMC220x stepper drivers
   * Hardware serial communication ports
   */
  #define X_HARDWARE_SERIAL  MSerial4
  #define Y_HARDWARE_SERIAL  MSerial4
  #define Z_HARDWARE_SERIAL  MSerial4
  #define E0_HARDWARE_SERIAL MSerial4

  // Default TMC slave addresses
  #ifndef X_SLAVE_ADDRESS
    #define X_SLAVE_ADDRESS  0
  #endif
  #ifndef Y_SLAVE_ADDRESS
    #define Y_SLAVE_ADDRESS  2
  #endif
  #ifndef Z_SLAVE_ADDRESS
    #define Z_SLAVE_ADDRESS  1
  #endif
  #ifndef E0_SLAVE_ADDRESS
    #define E0_SLAVE_ADDRESS 3
  #endif
#endif

//ga
// GADGETANGEL SECTION Begins ==============================================>>
//
// SET ONLY ONE of theses variables or NONE
//#define TEMP_0_PIN          PA1    //SW PI10  //HW PD8
//#define TEMP_SENSOR_0_PIN   PH13
#define ECHO_TEMP 1
#define ECHO_MAX31865_RESITANCE 0
//#define TEMP_SENSOR_1_PIN   P0_03
//
//#define MAX31865_SW_SPI   //-5
//#define MAX31865_HW_SPI   //-5
//#define MAX31855_SW_SPI     //-3
#define MAX31855_HW_SPI   //-3
//#define MAX6675_SW_SPI    //-2
//#define MAX6675_HW_SPI    //-2

#ifndef MAX6675_SS_PIN
  #ifdef MAX31865_SW_SPI
    // GTR SW SPI
    //#define THERMO_SCK_PIN                      PI1   // SCK
    //#define THERMO_DO_PIN                       PI2   // MISO
    //#define THERMO_CS1_PIN                      PH9   // CS1
    //#define THERMO_CS2_PIN                      PH2   // CS2

    //#define MAX6675_SS_PIN            THERMO_CS1_PIN
    //#define MAX6675_SS2_PIN           THERMO_CS2_PIN
    //#define MAX6675_SCK_PIN           THERMO_SCK_PIN
    //#define MAX6675_DO_PIN             THERMO_DO_PIN
    ///*
    //#define MAX6675_DO_PIN                    PD1
    #define MAX31865_MISO_PIN                 PI2
    //#define MAX6675_SCK_PIN                   PC12
    #define MAX31865_SCK_PIN                  PI1
    //
    #define MAX31865_MOSI_PIN                 PI10
    //
    //#define MAX31865_CS_PIN                   PH13
    #define MAX6675_SS_PIN                    PH13
    // enable the below two lines if you have a second Adafruit MAX31865 in software SPI mode
    //#define MAX31865_CS2_PIN                  TEMP_1_PIN
    //#define MAX6675_SS2_PIN                   TEMP_1_PIN
    //*/
  #endif

  #ifdef MAX31865_HW_SPI
    // SKR V1.4 or SKR V1.4 Turbo or SKR v1.3
    // if SD_CONNECTION_IS(LCD)
    // SCK_PIN                          P0_15
    // MISO_PIN                         P0_17
    // MOSI_PIN                         P0_18
    // if SD_CONNECTION_IS(ONBOARD)
    // SCK_PIN                          P0_07
    // MISO_PIN                         P0_08
    // MOSI_PIN                         P0_09
    //
    // For SKR PRO V1.1 board
    // if SD_CONNECTION_IS(LCD)
    //#define PIN_SPI_MISO            PB14
    //#define PIN_SPI_SCK             PB13
    //#define PIN_SPI_MOSI            PB15
    //
    // For GTR V1.0 board
    //#define SDCARD_CONNECTION ONBOARD by default
    //
    // ONBOARD //SPI1
    //  #define SCK_PIN                PA5  //SPI1
    //  #define MISO_PIN               PA6
    //  #define MOSI_PIN               PA7
    //
    // LCD    //SPI2  <--- this is enbled----YES as long as SD SUPPORT in configuation.h is disabled
    //#define PIN_SPI_MOSI            PB15
    //#define PIN_SPI_MISO            PB14
    //#define PIN_SPI_SCK             PB13
    //#define PIN_SPI_SS              PB12
    //
    //#define CUSTOM_SPI_PINS
    //#define MISO_PIN                PB14
    //#define SCK_PIN                 PB13
    //#define MOSI_PIN                PB15
    #define MAX6675_SS_PIN                    TEMP_0_PIN
    // below forces hardware spi
    ////#define MAX31865_CS_PIN                   MAX6675_SS_PIN  //forces Hardware SPI
    //#define MAX31865_CS_PIN                   TEMP_0_PIN
    //enable the below two lines if you have a second Adafruit MAX31865 board on hardware SPI
    //#define MAX6675_SS2_PIN                   TEMP_1_PIN      //P1_00 - PWRDET
    ////#define MAX31865_CS2_PIN                  MAX6675_SS2_PIN //forces Hardware SPI for the second MAX31865 board
    //#define MAX31865_CS2_PIN                  TEMP_1_PIN
  #endif

  //MAX31855 board configuration for Software SPI
  #ifdef MAX31855_SW_SPI
    #define THERMO_SCK_PIN                      PC12   // SCK
    #define THERMO_DO_PIN                       PC14   // MISO
    #define THERMO_CS1_PIN                      PA1   // CS1
    //#define THERMO_CS2_PIN                      PH9   // CS2
    //#define THERMO_CS1_PIN                      PH9   // CS1
    //#define THERMO_CS2_PIN                      PH2   // CS2
    /*
    #define MAX6675_SS_PIN            THERMO_CS1_PIN
    //#define MAX6675_SS2_PIN           THERMO_CS2_PIN
    #define MAX6675_DO_PIN             THERMO_DO_PIN
    #define MAX6675_SCK_PIN           THERMO_SCK_PIN
    */
    ///*
    //#define MAX6675_DO_PIN                    THERMO_DO_PIN
    #define MAX31855_MISO_PIN               THERMO_DO_PIN
    //#define MAX6675_SCK_PIN                   THERMO_SCK_PIN
    #define MAX31855_SCK_PIN                THERMO_SCK_PIN  //PG12
    //#define TEMP_0_PIN                        PF7
    //#define MAX6675_SS_PIN                    TEMP_0_PIN
    //#define MAX6675_CS_PIN                    TEMP_0_PIN
    //#define MAX6675_CS_PIN                    THERMO_CS1_PIN
    #define MAX31855_CS_PIN                 THERMO_CS1_PIN
    //#define MAX31855_CS_PIN                 TEMP_SENSOR_0_PIN
    //enable the next lines below if you have two MAX31855 boards
    //#define MAX6675_SS2_PIN                   TEMP_1_PIN
    //#define MAX31855_CS2_PIN                  THERMO_CS2_PIN
    //*/
    //
  #endif

  //MAX31855 board configuration for Hardware SPI
  #ifdef MAX31855_HW_SPI
    // SKR V1.4 or SKR V1.4 Turbo or SKR v1.3
    // if SD_CONNECTION_IS(LCD)
    // SCK_PIN                          P0_15
    // MISO_PIN                         P0_17
    // MOSI_PIN                         P0_18
    // if SD_CONNECTION_IS(ONBOARD)
    // SCK_PIN                          P0_07
    // MISO_PIN                         P0_08
    // MOSI_PIN                         P0_09
    //
    // For SKR PRO V1.1 board
    // if SD_CONNECTION_IS(LCD)
    //#define PIN_SPI_MISO            PB14
    //#define PIN_SPI_SCK             PB13
    //#define PIN_SPI_MOSI            PB15
    //
    // For GTR V1.0 board
    //#define SDCARD_CONNECTION ONBOARD by default
    //
    // ONBOARD //SPI1
    //  #define SCK_PIN                PA5  //SPI1
    //  #define MISO_PIN               PA6
    //  #define MOSI_PIN               PA7
    //
    // LCD    //SPI2
    //#define PIN_SPI_MOSI            PB15
    //#define PIN_SPI_MISO            PB14
    //#define PIN_SPI_SCK             PB13
    //#define PIN_SPI_SS              PB12
    //
    //uncomment the below line if you want MAX6675 Hardware SPI to be used
    //#define MAX6675_SS_PIN                    TEMP_SENSOR_0_PIN
    //#define MAX6675_SS_PIN                  TEMP_0_PIN
    //#define MAX6675_SS_PIN                  PD8
    //uncomment the below line if you want Adafruit MAX31855 Hardware SPI to be used
    //#define MAX31855_CS_PIN                   TEMP_SENSOR_0_PIN
    #define MAX31855_CS_PIN                   PC13
    //
    //enable the next lines below if you have two MAX31855 boards
    //
    //uncomment the below line if you want MAX6675 Hardware SPI to be used
    //#define MAX6675_SS2_PIN                   TEMP_1_PIN
    //uncomment the below line if you want Adafruit MAX31855 Hardware SPI to be used
    //#define MAX31855_CS2_PIN                  TEMP_1_PIN
  #endif

  //MAX6675 board configuration for Software SPI
  #ifdef MAX6675_SW_SPI
    #define THERMO_SCK_PIN                      PI1   // SCK
    #define THERMO_DO_PIN                       PI2   // MISO  //PI2
    //#define THERMO_CS1_PIN                      PH9   // CS1
    //#define THERMO_CS2_PIN                      PH2   // CS2
    #define THERMO_CS1_PIN                      PH13   // CS1
    //#define THERMO_CS2_PIN                      PH9   // CS2

    #define MAX6675_SS_PIN            THERMO_CS1_PIN
    //#define MAX6675_SS2_PIN           THERMO_CS2_PIN
    #define MAX6675_SCK_PIN           THERMO_SCK_PIN
    #define MAX6675_DO_PIN             THERMO_DO_PIN
    //
    /*
    #define MAX6675_DO_PIN                    PD1
    //#define MAX6675_MISO_PIN                  THERMO_DO_PIN
    #define MAX6675_SCK_PIN                   PC12
    //#define MAX6675_SS_PIN                    PD0
    #define MAX6675_CS_PIN                    TEMP_0_PIN
    //enable the next lines below if you have two MAX6675 boards
    //#define MAX6675_SS2_PIN                   TEMP_1_PIN
    //#define MAX6675_CS2_PIN                   TEMP_1_PIN
    */
  #endif

  //MAX6675 board configuration for Hardware SPI
  #ifdef MAX6675_HW_SPI
    // SKR V1.4 or SKR V1.4 Turbo or SKR v1.3
    // if SD_CONNECTION_IS(LCD)
    // SCK_PIN                          P0_15
    // MISO_PIN                         P0_17
    // MOSI_PIN                         P0_18
    // if SD_CONNECTION_IS(ONBOARD)
    // SCK_PIN                          P0_07
    // MISO_PIN                         P0_08
    // MOSI_PIN                         P0_09
    //
    // For SKR PRO V1.1 board
    // if SD_CONNECTION_IS(LCD)
    //#define PIN_SPI_MISO            PB14
    //#define PIN_SPI_SCK             PB13
    //#define PIN_SPI_MOSI            PB15
    //
    // For GTR V1.0 board
    //#define SDCARD_CONNECTION ONBOARD by default
    //
    // ONBOARD //SPI1
    //  #define SCK_PIN                PA5  //SPI1
    //  #define MISO_PIN               PA6
    //  #define MOSI_PIN               PA7
    //
    // LCD    //SPI2
    //#define PIN_SPI_MOSI            PB15
    //#define PIN_SPI_MISO            PB14
    //#define PIN_SPI_SCK             PB13
    //#define PIN_SPI_SS              PB12
    //
    #define MAX6675_SS_PIN                    TEMP_0_PIN
    //#define MAX6675_CS_PIN                    PD9
    //enable the next lines below if you have two MAX6675 boards
    //uncomment the below line if you want MAX6675 Hardware SPI to be used
    //#define MAX6675_SS2_PIN                   TEMP_1_PIN
    //#define MAX6675_CS2_PIN                   TEMP_1_PIN
  #endif

#endif

//GADGETANGEL SECTION Ends ==============================================>>
