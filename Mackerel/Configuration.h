#ifndef CONFIGURATION_H
#define CONFIGURATION_H


/*Notes for to dos
* Basic motion control - complete
* Come up with right settings steps/mm, acceleration, and feed rate to get good behavior - complete
* Allow motion to be turned on/off via LCD - complete
* 
* Figure our why motors pulse - complete was resetting failure 
* Figure out why motors miss steps (add heating fins?) - complete
* 
* Calibrate the extruder in RPM - complete
* calibrate the puller in mm based on urethane wheel diameter - complete
* Add the control for two motors  - complete
* link the motor velocities so that the puller motor is a percentage of the extruder RPM - complete
* 
* Winder speed can't be changed while running - works for 'control' menu but not 'tuning' menu - complete
* Still getting Card Removed at turn on only. - complete
* 
* Display items
* Show more on the main display (length, rpm, diameter) - complete
* Trem went blank, but returned - check why this might be - occurs when not collecting stats (like when paused)
* Remove dmin and dmax since does not seem useful - complete
* Add one more digit to M2 RPM (0.00) - complete
* Would like to change the total mm while running. - you can do this already - moved to better menus - complete
* Need to clear the Tela time stat with the length stat - complete
* Figure out how to resent the display periodically so that it restarts after static elect. - complete
* display filament diameter every 5 seconds rather than 1 second
* 
* Temp control
* figure out the right thermister - complete
* seems to hit max or min temp - fixed
* tune the PID - complete
* add autotune to the menus - complete
* 
* Filament width
* Add input and code for filament width sensor - complete
* 
* add an input for turning the extruder motor on/off - complete
* get PID to work with the filament width to puller speed control and add LCD manual/automatic control - complete
* add filament dia max,min, avg, and some way to clear and freeze it - complete
* add winder on/off control with an input, screen way, and #define to enable/disable in code - complete
* make sure new configuration items are saved in flash - complete
* add new g-codes for manual/automatic control to allow it to be controlled via pronterface
* clean-up of LCD menus - complete
* 
* need to make filament pid not time based but mm based - complete
* change back to direct control, not incremental. - complete
* add menus to change PID parameters for Filament - complete
* 
* Clear Stats did not zero out the L (length). - complete
* Need to be able to adjust the M2 rpm same as M1. - complete
* Clean up the multiplication factors - complete
* Clean up the Tune menu to remove factors no longer needed - complete
* Change the feedmultiply to an absolute puller_feedrate - complete
* Info page does not show M2 rpm. - complete
* Need docs of each function in the menus. - complete
* 
* make PID autotune go back to the info screen after launching

* Remove endstop logic out of the stepper interrupt ISR(TIMER1_COMPA_vect)  to improve stepper speed and reliability - complete
* Rename to Mackerel from Marlin where referred to in code - complete

debug notes:
- Hardcoded the temperature reading of the extruder for testing - search for FMMDEBUGTEMP
- Change how milimeters is calculated in the planner - search for FMMDEBUGMMPLAN
15

*/


// SERIAL_PORT selects which serial port should be used for communication with the host.
// This allows the connection of wireless adapters (for instance) to non-default port pins.
// Serial port 0 is still used by the Arduino bootloader regardless of this setting.
#define SERIAL_PORT 0

// This determines the communication speed of the printer
// This determines the communication speed of the printer
#define BAUDRATE 250000

#ifndef MOTHERBOARD
#define MOTHERBOARD 34  //FMM only works for this motherboard currently
#endif

// The RepRapDiscount Smart Controller (white PCB)
// http://reprap.org/wiki/RepRapDiscount_Smart_Controller
#define REPRAP_DISCOUNT_SMART_CONTROLLER

#if defined (REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER)
 #define DOGLCD
 #define U8GLIB_ST7920
 #define REPRAP_DISCOUNT_SMART_CONTROLLER
#endif





#ifdef ULTIPANEL
//  #define NEWPANEL  //enable this if you have a click-encoder panel
 #define SDSUPPORT  
  #define ULTRA_LCD
  #ifdef DOGLCD // Change number of lines to match the DOG graphic display
    #define LCD_WIDTH 20
    #define LCD_HEIGHT 5
  #else
    #define LCD_WIDTH 20
    #define LCD_HEIGHT 4
  #endif
#else //no panel but just LCD
  #ifdef ULTRA_LCD
  #ifdef DOGLCD // Change number of lines to match the 128x64 graphics display
    #define LCD_WIDTH 20
    #define LCD_HEIGHT 5
  #else
    #define LCD_WIDTH 16
    #define LCD_HEIGHT 2
  #endif
  #endif
#endif

// default LCD contrast for dogm-like LCD displays
#ifdef DOGLCD
# ifndef DEFAULT_LCD_CONTRAST
#  define DEFAULT_LCD_CONTRAST 32
# endif
#endif

#include "Configuration_adv.h"

#endif //__CONFIGURATION_H

