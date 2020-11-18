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

#if NOT_TARGET(STM32F4)
  #error "Oops! Select an STM32F4 board in 'Tools > Board.'"
#endif

// BigTreeTech driver expansion module https://bit.ly/3ptRRoj
//#define BTT_MOTOR_EXPANSION

#if BOTH(HAS_WIRED_LCD, BTT_MOTOR_EXPANSION)
  #error "It's not possible to have both LCD and motor expansion module on EXP1/EXP2."
#endif

// Use one of these or SDCard-based Emulation will be used
#if NO_EEPROM_SELECTED
  //#define SRAM_EEPROM_EMULATION                 // Use BackSRAM-based EEPROM emulation
  #define FLASH_EEPROM_EMULATION                  // Use Flash-based EEPROM emulation
#endif

#if ENABLED(FLASH_EEPROM_EMULATION)
  // Decrease delays and flash wear by spreading writes across the
  // 128 kB sector allocated for EEPROM emulation.
  #define FLASH_EEPROM_LEVELING
#endif

//
// Servos
//
#define SERVO0_PIN                          PA1
#define SERVO1_PIN                          PC9

//
// Trinamic Stallguard pins
//
#define X_DIAG_PIN                          PB10  // X-
#define Y_DIAG_PIN                          PE12  // Y-
#define Z_DIAG_PIN                          PG8   // Z-
#define E0_DIAG_PIN                         PE15  // E0
#define E1_DIAG_PIN                         PE10  // E1
#define E2_DIAG_PIN                         PG5   // E2

//
// Limit Switches
//
#ifdef X_STALL_SENSITIVITY
  #define X_STOP_PIN                  X_DIAG_PIN
  #if X_HOME_DIR < 0
    #define X_MAX_PIN                       PE15  // E0
  #else
    #define X_MIN_PIN                       PE15  // E0
  #endif
#else
  #define X_MIN_PIN                         PB10  // X-
  #define X_MAX_PIN                         PE15  // E0
#endif

#ifdef Y_STALL_SENSITIVITY
  #define Y_STOP_PIN                  Y_DIAG_PIN
  #if Y_HOME_DIR < 0
    #define Y_MAX_PIN                       PE10  // E1
  #else
    #define Y_MIN_PIN                       PE10  // E1
  #endif
#else
  #define Y_MIN_PIN                         PE12  // Y-
  #define Y_MAX_PIN                         PE10  // E1
#endif

#ifdef Z_STALL_SENSITIVITY
  #define Z_STOP_PIN                  Z_DIAG_PIN
  #if Z_HOME_DIR < 0
    #define Z_MAX_PIN                       PG5   // E2
  #else
    #define Z_MIN_PIN                       PG5   // E2
  #endif
#else
  #define Z_MIN_PIN                         PG8   // Z-
  #define Z_MAX_PIN                         PG5   // E2
#endif

//
// Z Probe must be this pin
//
#ifndef Z_MIN_PROBE_PIN
  #define Z_MIN_PROBE_PIN                   PA2
#endif

//
// Filament Runout Sensor
//
#ifndef FIL_RUNOUT_PIN
  #define FIL_RUNOUT_PIN                    PE15
#endif
#ifndef FIL_RUNOUT2_PIN
  #define FIL_RUNOUT2_PIN                   PE10
#endif
#ifndef FIL_RUNOUT3_PIN
  #define FIL_RUNOUT3_PIN                   PG5
#endif

//
// Steppers
//
#define X_STEP_PIN                          PE9
#define X_DIR_PIN                           PF1
#define X_ENABLE_PIN                        PF2
#ifndef X_CS_PIN
  #define X_CS_PIN                          PA15
#endif

#define Y_STEP_PIN                          PE11
#define Y_DIR_PIN                           PE8
#define Y_ENABLE_PIN                        PD7
 #ifndef Y_CS_PIN
  #define Y_CS_PIN                          PB8
#endif

#define Z_STEP_PIN                          PE13
#define Z_DIR_PIN                           PC2
#define Z_ENABLE_PIN                        PC0
#ifndef Z_CS_PIN
  #define Z_CS_PIN                          PB9
#endif

#define E0_STEP_PIN                         PE14
#define E0_DIR_PIN                          PA0
#define E0_ENABLE_PIN                       PC3
#ifndef E0_CS_PIN
  #define E0_CS_PIN                         PB3
#endif

#define E1_STEP_PIN                         PD15
#define E1_DIR_PIN                          PE7
#define E1_ENABLE_PIN                       PA3
#ifndef E1_CS_PIN
  #define E1_CS_PIN                         PG15
#endif

#define E2_STEP_PIN                         PD13
#define E2_DIR_PIN                          PG9
#define E2_ENABLE_PIN                       PF0
#ifndef E2_CS_PIN
  #define E2_CS_PIN                         PG12
#endif

//
// Software SPI pins for TMC2130 stepper drivers
//
#if ENABLED(TMC_USE_SW_SPI)
  #ifndef TMC_SW_MOSI
    #define TMC_SW_MOSI                     PC12
  #endif
  #ifndef TMC_SW_MISO
    #define TMC_SW_MISO                     PC11
  #endif
  #ifndef TMC_SW_SCK
    #define TMC_SW_SCK                      PC10
  #endif
#endif

#if HAS_TMC_UART
  /**
   * TMC2208/TMC2209 stepper drivers
   *
   * Hardware serial communication ports.
   * If undefined software serial is used according to the pins below
   */
  //#define X_HARDWARE_SERIAL  Serial1
  //#define X2_HARDWARE_SERIAL Serial1
  //#define Y_HARDWARE_SERIAL  Serial1
  //#define Y2_HARDWARE_SERIAL Serial1
  //#define Z_HARDWARE_SERIAL  Serial1
  //#define Z2_HARDWARE_SERIAL Serial1
  //#define E0_HARDWARE_SERIAL Serial1
  //#define E1_HARDWARE_SERIAL Serial1
  //#define E2_HARDWARE_SERIAL Serial1
  //#define E3_HARDWARE_SERIAL Serial1
  //#define E4_HARDWARE_SERIAL Serial1

  //
  // Software serial
  //
  #define X_SERIAL_TX_PIN                   PC13
  #define X_SERIAL_RX_PIN                   PC13

  #define Y_SERIAL_TX_PIN                   PE3
  #define Y_SERIAL_RX_PIN                   PE3

  #define Z_SERIAL_TX_PIN                   PE1
  #define Z_SERIAL_RX_PIN                   PE1

  #define E0_SERIAL_TX_PIN                  PD4
  #define E0_SERIAL_RX_PIN                  PD4

  #define E1_SERIAL_TX_PIN                  PD1
  #define E1_SERIAL_RX_PIN                  PD1

  #define E2_SERIAL_TX_PIN                  PD6
  #define E2_SERIAL_RX_PIN                  PD6

  // Reduce baud rate to improve software serial reliability
  #define TMC_BAUD_RATE                    19200
#endif


//
// Temperature Sensors
//
// GADGETANGEL --------SET the TEMP_0_PIN to the E0 Temperature sensor CS line
// GADGETANGEL --------SET the TEMP_1_PIN to the E1 Temperature sensor CS line
#define TEMP_0_PIN                          PF7   // T1 <-> E0, //GADGETANGEL originally set PF4 //GADGETANGEL set for PE2 or PD0 or PE4 or PC1
#define TEMP_1_PIN                          PF8   // T2 <-> E1, //GADGETANGEL originally set PF5 //GADGETANGEL set for PF8, PE2 or PD0 or PE4 or PC1
#define TEMP_2_PIN                          PF6   // T3 <-> E2  //GADGETANGEL originally set PF6
#define TEMP_BED_PIN                        PF3   // T0 <-> Bed


//***********************************
//********************************** GADGETANGEL CHANGE THIS to match your configuration
//***********************************
//***********************************
//#define myThermocouple  //uncomment to use the Thermocouple SECTION, comment out otherwise
#define myPT100         //uncomment to use the PT100/PT1000 SECTION, comment out otherwise
// If both myThermocouple and myPT100 are uncommented then the Thermocouple section with MAX31855 SPI Section will be used!

//-------------------------------------------------THERMOCOUPLE SECTION----------------------------------------------------------
#if ENABLED(myThermocouple)
    #define myThermocouple_SPI   //for MAX31855    //uncomment to use the Thermocouple with MAX31855 SPI Section, 
                                                  //comment out to use the Thermocouple with Adafruit AD8495 Amplifier ANALOG Section
  #if ENABLED(myThermocouple_SPI)
    //
    // SOFTWARE SPI the board performs the SPI protocol handshake with software.
    // HARDWARE SPI the board performs the SPI protocol handshake with hardware interrupts.
    //
    //
    #define myMAX31855_SW  // uncomment myMAX31855_SW for Software SPI, comment out myMAX31855_SW for Hardware SPI

    #ifndef MAX6675_SS_PIN
      // GADGETANGEL notes:
      // if you want to use TWO thermocouples on the SKR PRO V1.x board than both MAX31855 board must use the same SCK_PIN and DO_PIN
      // If you have an existing MAX31855 on the MCU board, then you must use the SPI protocol that ONBOARD MAX31855 is using (Software SPI or Hardware SPI).
      // You can not have one MAX31855 use Software SPI and a second MAX31855 use Hardware SPI.  You can not mix SPI states between two MAX31855 boards.
      // The SKR PRO V1.x board does not have an ONBOARD MAX31855 but the GTR V1.0 board does have an ONBOARD MAX31855 chip.
      // END OF GADGETANGEL notes section
      //
      //
      //-------------------------------------------- THERMOCOUPLE  with MAX31855 SPI Section
      // Ensure that TEMP_1_PIN is set the PE2 or PD0 or PE4 or PC1
      // Ensure that TEMP_1_PIN is set the PE2 or PD0 or PE4 or PC1
      // in configuration.h ensure TEMP_SENSOR_0 is set for -3 and if using a second thermocouple ensure TEMP_SENSOR_1 is set for -3
      #define THERMO_SCK_PIN            PE0             // SCK    
      #define THERMO_DO_PIN             PD5             // MISO   
      #define THERMO_CS1_PIN            TEMP_0_PIN      // CS1 for first thermocouple, set for PE2 or PD0 or PE4 or PC1 
      #define THERMO_CS2_PIN            TEMP_1_PIN      //CS2 for secound thermocouple, set for PE2 or PD0 or PE4 or PC1

      #if ENABLED(myMAX31855_SW)
        //Software SPI with MAX6675_SEPARATE_SPI
        // First Thermocouple and secound Thermocouple uses Sofware 
        // SPI for Max6675 or Max31855 Thermocouple
        // Uses a separate SPI bus
        #define MAX6675_SS_PIN            THERMO_CS1_PIN   //for first Thermocouple
        #define MAX6675_SS2_PIN           THERMO_CS2_PIN   //for secound Thermocouple 
        #define MAX6675_SCK_PIN           THERMO_SCK_PIN   
        #define MAX6675_DO_PIN            THERMO_DO_PIN
      #else
        //Hardware SPI
        // the SPI MOSI, SPI MISO and SPI SCK lines must come from the default SPI Bus which for the SKR PRO V1.x board is 
        // SPI bus 2 which is the EXP2 connector.  Wire the MAX31855 MISO and SCK lines into the EXP2 connector's
        // SPI lines
        #ifndef MAX6675_SCK 
          #ifndef MAX6675_DO
            #define MAX6675_SS_PIN            THERMO_CS1_PIN
            #define MAX6675_SS2_PIN           THERMO_CS2_PIN  
          #endif
        #endif
        // end of HARDWARE SPI               
      #endif 
    #endif
    //------------------------------------------end of THERMOCOUPLE with MAX31865 SPI section
  #else
    //-------------------------------------------- THERMOCOUPLE with Adafruit AD8495 AMP (ANALOG) Section
    //GADGETANGEL for Adafruit AD8495 Amplifier board with a K-Type Thermocouple temperature sensor
    //ensure TEMP_SENSOR_0 is set to -4 
    //ensure TEMP_SENSOR_0 is set to -4 
    //ENSURE you setup TEMP_0_PIN to the Signal OUT on the Adafruit AD8495 amplifier board
    #ifndef MAX6675_SS_PIN
        //set TEMP_0_PIN above for PE2 or PD0 or PE4 or PC1, or (PF4 for T1,PF5 for T2, PF6 for T3) 
        //set TEMP_1_PIN  above for PE2 or PD0 or PE4 or PC1, or (PF4 for T1,PF5 for T2, PF6 for T3)
        //ENSURE in configuration_adv.h you set the following:
        //#define TEMP_SENSOR_AD8495_OFFSET -250.0   //the adafruit AD8495's offset is -250
        //#define TEMP_SENSOR_AD8495_GAIN   1.0
    #endif
    //------------------------------------------------end of THERMOCOUPLE with Adafruit AD8495AMP (ANALOG) Section
  #endif
#endif
//--------------------------------------------------------PT100/1000 Section----------------------------------------------------------
#if ENABLED(myPT100)
  #define myPT100_SPI  //for MAX31865 and PT100    //uncomment to use the PT100 with Adafruit MAX31865 SPI Section, 
                                                   //comment out to use to use the PT100 amplifier ANALOG Section 
  //#define myMAX31865_SW // uncomment myMAX31865_SW for Software SPI, comment out myMAX31865_SW for Hardware SPI 
  #if ENABLED(myPT100_SPI)
    //-------------------------------------------- PT100 with MAX31865 SPI Section
    // SOFTWARE SPI the board performs the SPI protocol handshake with software.
    // HARDWARE SPI the board performs the SPI protocol handshake with hardware interrupts.
    // If you want HARDWARE SPI for the MAX31865 board you need to ensure that MAX6675_SS_PIN is equal to MAX31865_CS_PIN
    // If you want SOFTWARE SPI for the MAX31865 board you need to ensure that MAX6675_SS_PIN is NOT equal to MAX31865_CS_PIN
    //GADGETANGEL for MAX31865 board
    //MAX31865 board for SPI communication with PT100 temperature sensor, ensure TEMP_SENSOR_0 is set to -5, 
    //and if using a second PT100 ensure TEMP_SENSOR_1 is set for -5
    // ENSURE you setup TEMP_0_PIN to the PT100_CS_PIN you desire
    #ifndef MAX6675_SS_PIN
      #define PT100_CS_PIN                      TEMP_0_PIN  
      #define PT100_CS2_PIN                     TEMP_1_PIN  
      // Define the MAX31865 board's PINS
      #define UNUSED_PIN                        PC1  //must be an unused PIN on the board - this PIN is on EXTENSION-1 header
      #define PT100_MISO_PIN                    PC9
      #define PT100_SCK_PIN                     PF9
      #define PT100_MOSI_PIN                    PC4   //can NOT be set as the default Hardware SPI MOSI PIN (MOSI_PIN=PB15)

      #if ENABLED(myMAX31865_SW)
        //Software SPI wanted
        // the SPI MOSI, SPI MISO and SPI SCK line must all be shared beween two MAX31865 board, if you want two PT100
        #define MAX6675_DO_PIN                    PT100_MISO_PIN 
        #define MAX6675_SCK_PIN                   PT100_SCK_PIN
        #define MAX31865_MOSI_PIN                 PT100_MOSI_PIN
        // for ONE MAX31865 board
        #define MAX31865_CS_PIN                   PT100_CS_PIN  
        //This must be UNUSED_PIN for 1 MAX31865 in software SPI and MAX6675_SEPARATE_SPI  
        #define MAX6675_SS_PIN                    UNUSED_PIN    //forces Software SPI mode
        //enable the below two lines if you have a second MAX31865 board in software spi mode    
        #define MAX31865_CS2_PIN                  PT100_CS2_PIN
        #define MAX6675_SS2_PIN                   UNUSED_PIN   //forces Software SPI mode
      #else
        //HARDWARE SPI wanted
        // the SPI MOSI, SPI MISO and SPI SCK lines must come from the default SPI Bus which for the SKR PRO V1.x board is 
        // SPI bus 2 which is the EXP2 connector.  Wire the MAX31865 MOSI, MISO and SCK lines into the EXP2 connector's
        // SPI lines
        #ifndef MAX6675_SCK 
          #ifndef MAX6675_DO
            #define MAX6675_SS_PIN                    PT100_CS_PIN   
            #define MAX31865_CS_PIN                   MAX6675_SS_PIN    //forces HARDWARE SPI for one or two MAX31865 boards
            // enable the below two lines if you have 2 Adafruit MAX31865 boards
            #define MAX6675_SS2_PIN                   PT100_CS2_PIN   
            //#define MAX31865_CS2_PIN                  MAX6675_SS2_PIN  //forces Hardware SPI for the second MAX31865 board
          #endif
        #endif
      #endif
    #endif
    //------------------------------------------------end of PT100 with MAX31865 SPI section
  #else
    //-------------------------------------------- PT100 with PT100AMP (ANALOG) Section
    //GADGETANGEL for E3D PT100 Amplifier board with a PT100 temperature sensor
    //ensure TEMP_SENSOR_0 is set to 20 if using 3.3VDC to power the PT100 amplifier on SKR PRO V1.2 board (MCU with ADC ref voltage of 3.3VDC)
    //ensure TEMP_SENSOR_0 is set to 21 if using 5V to power the PT100 amplifier on SKR PRO V1.2 board (MCU with ADC ref voltage of 3.3VDC)
    //ENSURE you setup TEMP_0_PIN to the Signal out on the PT100 amplifier board
    #ifndef MAX6675_SS_PIN
      //set TEMP_0_PIN above for PE2 or PD0 or PE4 or PC1, or (PF4 for T1,PF5 for T2, PF6 for T3) 
      //set TEMP_1_PIN  above for PE2 or PD0 or PE4 or PC1, or (PF4 for T1,PF5 for T2, PF6 for T3)
    #endif
    //------------------------------------------------end of PT100 with PT100AMP (ANALOG) Section
  #endif
#endif

//
// Heaters / Fans
//
#define HEATER_0_PIN                        PB1   // Heater0
#define HEATER_1_PIN                        PD14  // Heater1
#define HEATER_2_PIN                        PB0   // Heater1
#define HEATER_BED_PIN                      PD12  // Hotbed
#define FAN_PIN                             PC8   // Fan0
#define FAN1_PIN                            PE5   // Fan1
#define FAN2_PIN                            PE6

#ifndef E0_AUTO_FAN_PIN
  #define E0_AUTO_FAN_PIN               FAN1_PIN
#endif

//
// Misc. Functions
//

#ifndef SDCARD_CONNECTION
  #define SDCARD_CONNECTION                  LCD
#endif

/**
 *               -----                                             -----
 *           NC | 1 2 | GND                                    5V | 1 2 | GND
 *        RESET | 3 4 | PF12(SD_DETECT)             (LCD_D7)  PG7 | 3 4 | PG6  (LCD_D6)
 *   (MOSI)PB15 | 5 6   PF11(BTN_EN2)               (LCD_D5)  PG3 | 5 6   PG2  (LCD_D4)
 *  (SD_SS)PB12 | 7 8 | PG10(BTN_EN1)               (LCD_RS) PD10 | 7 8 | PD11 (LCD_EN)
 *    (SCK)PB13 | 9 10| PB14(MISO)                 (BTN_ENC)  PA8 | 9 10| PG4  (BEEPER)
 *               -----                                             -----
 *               EXP2                                              EXP1
 */

#define EXPA1_03_PIN                        PG7
#define EXPA1_04_PIN                        PG6
#define EXPA1_05_PIN                        PG3
#define EXPA1_06_PIN                        PG2
#define EXPA1_07_PIN                        PD10
#define EXPA1_08_PIN                        PD11
#define EXPA1_09_PIN                        PA8
#define EXPA1_10_PIN                        PG4

#define EXPA2_03_PIN                        -1
#define EXPA2_04_PIN                        PF12
#define EXPA2_05_PIN                        PB15
#define EXPA2_06_PIN                        PF11
#define EXPA2_07_PIN                        PB12
#define EXPA2_08_PIN                        PG10
#define EXPA2_09_PIN                        PB13
#define EXPA2_10_PIN                        PB14

//
// Onboard SD card
// Must use soft SPI because Marlin's default hardware SPI is tied to LCD's EXP2
//
#if SD_CONNECTION_IS(LCD)

  #define SD_DETECT_PIN             EXPA2_04_PIN
  #define SDSS                      EXPA2_07_PIN

#elif SD_CONNECTION_IS(ONBOARD)

  // The SKR Pro's ONBOARD SD interface is on SPI1.
  // Due to a pull resistor on the clock line, it needs to use SPI Data Mode 3 to
  // function with Hardware SPI. This is not currently configurable in the HAL,
  // so force Software SPI to work around this issue.
  #define SOFTWARE_SPI
  #define SDSS                              PA4
  #define SCK_PIN                           PA5
  #define MISO_PIN                          PA6
  #define MOSI_PIN                          PB5
  #define SD_DETECT_PIN                     PB11

#elif SD_CONNECTION_IS(CUSTOM_CABLE)
  #error "CUSTOM_CABLE is not a supported SDCARD_CONNECTION for this board"
#endif

#if ENABLED(BTT_MOTOR_EXPANSION)
  /**
   *               _____                                      _____
   *           NC | · · | GND                             NC | · · | GND
   *           NC | · · | PF12 (M1EN)            (M2EN)  PG7 | · · | PG6  (M3EN)
   * (M1STP) PB15 | · ·   PF11 (M1DIR)           (M1RX)  PG3 | · ·   PG2  (M1DIAG)
   * (M2DIR) PB12 | · · | PG10 (M2STP)           (M2RX) PD10 | · · | PD11 (M2DIAG)
   * (M3DIR) PB13 | · · | PB14 (M3STP)           (M3RX)  PA8 | · · | PG4  (M3DIAG)
   *               -----                                      -----
   *               EXP2                                       EXP1
   */

  // M1 on Driver Expansion Module
  #define E3_STEP_PIN               EXPA2_05_PIN
  #define E3_DIR_PIN                EXPA2_06_PIN
  #define E3_ENABLE_PIN             EXPA2_04_PIN
  #define E3_DIAG_PIN               EXPA1_06_PIN
  #define E3_CS_PIN                 EXPA1_05_PIN
  #if HAS_TMC_UART
    #define E3_SERIAL_TX_PIN        EXPA1_05_PIN
    #define E3_SERIAL_RX_PIN        EXPA1_05_PIN
  #endif

  // M2 on Driver Expansion Module
  #define E4_STEP_PIN               EXPA2_08_PIN
  #define E4_DIR_PIN                EXPA2_07_PIN
  #define E4_ENABLE_PIN             EXPA1_03_PIN
  #define E4_DIAG_PIN               EXPA1_08_PIN
  #define E4_CS_PIN                 EXPA1_07_PIN
  #if HAS_TMC_UART
    #define E4_SERIAL_TX_PIN        EXPA1_07_PIN
    #define E4_SERIAL_RX_PIN        EXPA1_07_PIN
  #endif

  // M3 on Driver Expansion Module
  #define E5_STEP_PIN               EXPA2_10_PIN
  #define E5_DIR_PIN                EXPA2_09_PIN
  #define E5_ENABLE_PIN             EXPA1_04_PIN
  #define E5_DIAG_PIN               EXPA1_10_PIN
  #define E5_CS_PIN                 EXPA1_09_PIN
  #if HAS_TMC_UART
    #define E5_SERIAL_TX_PIN        EXPA1_09_PIN
    #define E5_SERIAL_RX_PIN        EXPA1_09_PIN
  #endif

#endif // BTT_MOTOR_EXPANSION

//
// LCDs and Controllers
//
#if IS_TFTGLCD_PANEL

  #if ENABLED(TFTGLCD_PANEL_SPI)
    #define TFTGLCD_CS              EXPA2_08_PIN
  #endif

#elif HAS_WIRED_LCD

  #define BEEPER_PIN                EXPA1_10_PIN
  #define BTN_ENC                   EXPA1_09_PIN

  #if ENABLED(CR10_STOCKDISPLAY)

    #define LCD_PINS_RS             EXPA1_04_PIN

    #define BTN_EN1                 EXPA1_08_PIN
    #define BTN_EN2                 EXPA1_06_PIN

    #define LCD_PINS_ENABLE         EXPA1_03_PIN
    #define LCD_PINS_D4             EXPA1_05_PIN

    // CR10_STOCKDISPLAY default timing is too fast
    #undef BOARD_ST7920_DELAY_1
    #undef BOARD_ST7920_DELAY_2
    #undef BOARD_ST7920_DELAY_3

  #elif ENABLED(MKS_MINI_12864)

    #define DOGLCD_A0               EXPA1_04_PIN
    #define DOGLCD_CS               EXPA1_05_PIN
    #define BTN_EN1                 EXPA2_08_PIN
    #define BTN_EN2                 EXPA2_06_PIN

  #else

    #define LCD_PINS_RS             EXPA1_07_PIN

    #define BTN_EN1                 EXPA2_08_PIN
    #define BTN_EN2                 EXPA2_06_PIN

    #define LCD_PINS_ENABLE         EXPA1_08_PIN
    #define LCD_PINS_D4             EXPA1_06_PIN

    #if ENABLED(FYSETC_MINI_12864)
      #define DOGLCD_CS             EXPA1_08_PIN
      #define DOGLCD_A0             EXPA1_07_PIN
      //#define LCD_BACKLIGHT_PIN           -1
      #define LCD_RESET_PIN         EXPA1_06_PIN  // Must be high or open for LCD to operate normally.
      #if EITHER(FYSETC_MINI_12864_1_2, FYSETC_MINI_12864_2_0)
        #ifndef RGB_LED_R_PIN
          #define RGB_LED_R_PIN     EXPA1_05_PIN
        #endif
        #ifndef RGB_LED_G_PIN
          #define RGB_LED_G_PIN     EXPA1_04_PIN
        #endif
        #ifndef RGB_LED_B_PIN
          #define RGB_LED_B_PIN     EXPA1_03_PIN
        #endif
      #elif ENABLED(FYSETC_MINI_12864_2_1)
        #define NEOPIXEL_PIN        EXPA1_05_PIN
      #endif
    #endif // !FYSETC_MINI_12864

    #if IS_ULTIPANEL
      #define LCD_PINS_D5           EXPA1_05_PIN
      #define LCD_PINS_D6           EXPA1_04_PIN
      #define LCD_PINS_D7           EXPA1_03_PIN
    #endif

  #endif

#endif // HAS_WIRED_LCD

// Alter timing for graphical display
#if HAS_MARLINUI_U8GLIB
  #ifndef BOARD_ST7920_DELAY_1
    #define BOARD_ST7920_DELAY_1    DELAY_NS(96)
  #endif
  #ifndef BOARD_ST7920_DELAY_2
    #define BOARD_ST7920_DELAY_2    DELAY_NS(48)
  #endif
  #ifndef BOARD_ST7920_DELAY_3
    #define BOARD_ST7920_DELAY_3   DELAY_NS(600)
  #endif
#endif

//check to to see what SPI bus you are on
#if PIN_SPI_SS == PB12
 #define myVariable 1
#else
 #define myVariable 0
#endif


//
// WIFI
//

/**
 *          -----
 *      TX | 1 2 | GND      Enable PG1   // Must be high for module to run
 *  Enable | 3 4 | GPIO2    Reset  PG0   // active low, probably OK to leave floating
 *   Reset | 5 6 | GPIO0    GPIO2  PF15  // must be high (ESP3D software configures this with a pullup so OK to leave as floating)
 *    3.3V | 7 8 | RX       GPIO0  PF14  // Leave as unused (ESP3D software configures this with a pullup so OK to leave as floating)
 *          -----
 *            W1
 */
#define ESP_WIFI_MODULE_COM                    6  // Must also set either SERIAL_PORT or SERIAL_PORT_2 to this
#define ESP_WIFI_MODULE_BAUDRATE        BAUDRATE  // Must use same BAUDRATE as SERIAL_PORT & SERIAL_PORT_2
#define ESP_WIFI_MODULE_RESET_PIN           PG0
#define ESP_WIFI_MODULE_ENABLE_PIN          PG1
#define ESP_WIFI_MODULE_GPIO0_PIN           PF14
#define ESP_WIFI_MODULE_GPIO2_PIN           PF15
