#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x4c47
#define PRODUCT_ID      0x4347
#define DEVICE_VER      0x0001
#define MANUFACTURER    LG
#define PRODUCT         YEET3

/* key matrix size */
#define MATRIX_ROWS 7
#define MATRIX_COLS 14

#define MATRIX_ROW_PINS { B1, B0, F7, F6, F5, F4, C7}
#define MATRIX_COL_PINS { D7, D6, D5, D4, D3, D2, D1, D0, B7, B6, B5, B4, B3, B2}


#define UNUSED_PINS
#define DIODE_DIRECTION COL2ROW

//#define RGB_DI_PIN E6
//#define RGBLIGHT_ANIMATIONS
//#define RGBLED_NUM 98   // Number of LEDs

//#define DRIVER_LED_TOTAL 98


/* RGB LEDs */
#define RGB_DI_PIN E6
#define RGB_DISABLE_AFTER_TIMEOUT 0 // number of ticks to wait until disabling effects
#define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_LED_PROCESS_LIMIT 4
#define RGB_MATRIX_LED_FLUSH_LIMIT 26
#define DRIVER_LED_TOTAL 1


#define DEBOUNCE 5
#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

#endif
