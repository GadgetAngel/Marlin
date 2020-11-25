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

#ifdef SKR_HAS_LPC1769
  #if NOT_TARGET(MCU_LPC1769)
    #error "Oops! Make sure you have the LPC1769 environment selected in your IDE."
  #endif
#elif NOT_TARGET(MCU_LPC1768)
  #error "Oops! Make sure you have the LPC1768 environment selected in your IDE."
#endif

// Ignore temp readings during development.
//#define BOGUS_TEMPERATURE_GRACE_PERIOD    2000

//
// Steppers
//
#ifndef E1_STEP_PIN
  #define E1_STEP_PIN                      P0_01
#endif
#ifndef E1_DIR_PIN
  #define E1_DIR_PIN                       P0_00
#endif
#ifndef E1_ENABLE_PIN
  #define E1_ENABLE_PIN                    P0_10
#endif

//
// Temperature Sensors
//  3.3V max when defined as an analog input
//
// GADGETANGEL --------SET the TEMP_0_PIN to the E0 Temperature sensor CS line
// GADGETANGEL --------SET the TEMP_1_PIN to the E1 Temperature sensor CS line
#ifndef TEMP_0_PIN
  #define TEMP_0_PIN                    P1_15  // A1 (T1) - (68) - TEMP_0_PIN  //orginally P0_24_A1
#endif
#ifndef TEMP_1_PIN
  #define TEMP_1_PIN                    P0_25_A2  // A2 (T2) - (69) - TEMP_1_PIN  //orginally P0_25_A2   // set in pins_BTT_SKR_V1_4.h file P0_23_A0
#endif
#ifndef TEMP_BED_PIN
  #define TEMP_BED_PIN                  P0_23_A0  // A0 (T0) - (67) - TEMP_BED_PIN  //orginally P0_23_A0  // set in pins_BTT_SKR_V1_4.h file P0_25_A2
#endif

#if HOTENDS == 1
  #if TEMP_SENSOR_PROBE
    #define TEMP_PROBE_PIN            TEMP_1_PIN
  #elif TEMP_SENSOR_CHAMBER
    #define TEMP_CHAMBER_PIN          TEMP_1_PIN
  #endif
#endif


// GADGETANGEL --------SET the TEMP_0_PIN to the E0 Temperature sensor CS line
// GADGETANGEL --------SET the TEMP_1_PIN to the E1 Temperature sensor CS line
//#define TEMP_0_PIN                    P1_15     // A1 (T1) - (68) - TEMP_0_PIN  //orginally P0_24_A1            //E1 driver socket and E1-CLS (EN,STEP,DIR) or (P1_16,P1_15,P1_14)
//#define TEMP_1_PIN                    P0_23_A0  // set in pins_BTT_SKR_V1_4.h file P0_23_A0  // A0 (T0) - (67)  //E1 driver socket and E1-CLS (EN,STEP,DIR) or (P1_16,P1_15,P1_14)
//#define TEMP_BED_PIN                  P0_25_A2  // set in pins_BTT_SKR_V1_4.h file P0_25_A2  // A2 (T2) - (69)

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
      #define THERMO_SCK_PIN            P0_04           //E1 - SCK PIN  //can not be set as the default Hardware SPI SCK PIN (SCK_PIN=P0_15)
      #define THERMO_DO_PIN             P0_05           //E1 - MISO PIN //can not be set as the default Hardware SPI MISO PIN (MISO_PIN=P0_17) 
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
        //set TEMP_0_PIN above E1 driver socket and E1-CLS (EN,STEP,DIR) or (P1_16,P1_15,P1_14) OR (P0_24_A1 for TH0, P0_23_A0 for TH1) 
        //set TEMP_1_PIN above E1 driver socket and E1-CLS (EN,STEP,DIR) or (P1_16,P1_15,P1_14) OR (P0_24_A1 for TH0, P0_23_A0 for TH1)
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
  #define myMAX31865_SW // uncomment myMAX31865_SW for Software SPI, comment out myMAX31865_SW for Hardware SPI 
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
      #define PT100_CS_PIN                      TEMP_0_PIN  //use unused PIN on E1 driver socket and E1-CLS (EN,STEP,DIR) or (P1_16,P1_15,P1_14)
      #define PT100_CS2_PIN                     TEMP_1_PIN  //use unused PIN on E1 driver socket and E1-CLS (EN,STEP,DIR) or (P1_16,P1_15,P1_14)
      // Define the MAX31865 board's PINS
      // Ensure you set the jumper on SKR V1.4 board to ensure the SPI PINS are connected 
      // to the MCU on E1 driver socket (set the four jumers on the two red column of PINS only for E1 driver socket)
      #define UNUSED_PIN                        P1_25  //must be an unused PIN on the board - this PIN is on E1DET-1 connector  overrides the following definitions: E1_DIAG_PIN,Y_MAX_PIN,Y_MIN_PIN,FIL_RUNOUT2_PIN OR //PWRDET PIN = P1_00
      #define PT100_MISO_PIN                    P0_05  //E1 - MISO PIN //can not be set as the default Hardware SPI MISO PIN (MISO_PIN=P0_17)
      #define PT100_SCK_PIN                     P0_04  //E1 - SCK PIN  //can not be set as the default Hardware SPI SCK PIN (SCK_PIN=P0_15)
      #define PT100_MOSI_PIN                    P1_17  //can NOT be set as the default Hardware SPI MOSI PIN (MOSI_PIN=P0_18)

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
        //#define MAX31865_CS2_PIN                  PT100_CS2_PIN
        //#define MAX6675_SS2_PIN                   UNUSED_PIN   //forces Software SPI mode
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
    //ensure TEMP_SENSOR_0 is set to 20 if using 3.3VDC to power the PT100 amplifier on SKR V1.4 board (MCU with ADC ref voltage of 3.3VDC)
    //ensure TEMP_SENSOR_0 is set to 21 if using 5V to power the PT100 amplifier on SKR SKR V1.4 board (MCU with ADC ref voltage of 3.3VDC)
    //ENSURE you setup TEMP_0_PIN to the Signal out on the PT100 amplifier board
    #ifndef MAX6675_SS_PIN
      //set TEMP_0_PIN above E1 driver socket and E1-CLS (EN,STEP,DIR) or (P1_16,P1_15,P1_14) OR (P0_24_A1 for TH0, P0_23_A0 for TH1) 
      //set TEMP_1_PIN above E1 driver socket and E1-CLS (EN,STEP,DIR) or (P1_16,P1_15,P1_14) OR (P0_24_A1 for TH0, P0_23_A0 for TH1)
    #endif
    //------------------------------------------------end of PT100 with PT100AMP (ANALOG) Section
  #endif
#endif


//
// Heaters / Fans
//
#ifndef HEATER_0_PIN
  #define HEATER_0_PIN                     P2_07
#endif
#if HOTENDS == 1
  #ifndef FAN1_PIN
    #define FAN1_PIN                       P2_04
  #endif
#else
  #ifndef HEATER_1_PIN
    #define HEATER_1_PIN                   P2_04
  #endif
#endif
#ifndef FAN_PIN
  #define FAN_PIN                          P2_03
#endif
#ifndef HEATER_BED_PIN
  #define HEATER_BED_PIN                   P2_05
#endif

//
// LCD / Controller
//
#if HAS_WIRED_LCD && DISABLED(LCD_USE_I2C_BUZZER)
  #define BEEPER_PIN                       P1_30  // (37) not 5V tolerant
#endif

//
// SD Support
//
#define ONBOARD_SD_CS_PIN                  P0_06  // Chip select for "System" SD card

#if SD_CONNECTION_IS(LCD)
  #define SCK_PIN                          P0_15
  #define MISO_PIN                         P0_17
  #define MOSI_PIN                         P0_18
#elif SD_CONNECTION_IS(ONBOARD)
  #undef SD_DETECT_PIN
  #define SD_DETECT_PIN                    P0_27
  #define SCK_PIN                          P0_07
  #define MISO_PIN                         P0_08
  #define MOSI_PIN                         P0_09
  #define SS_PIN               ONBOARD_SD_CS_PIN
#elif SD_CONNECTION_IS(CUSTOM_CABLE)
  #error "No custom SD drive cable defined for this board."
#endif
