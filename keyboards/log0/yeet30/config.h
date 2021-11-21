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

#define RGB_DI_PIN E6
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 98   // Number of LEDs
#define DEBOUNCE 5
#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

#endif
