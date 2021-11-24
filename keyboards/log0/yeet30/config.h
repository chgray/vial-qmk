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

#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_TYPING_HEATMAP

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
#define DRIVER_LED_TOTAL 98


#define DEBOUNCE 5
#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

//https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
#if 1

#define DISABLE_RGB_MATRIX_ALPHAS_MODS
#define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#define DISABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#define DISABLE_RGB_MATRIX_BREATHING
#define DISABLE_RGB_MATRIX_BAND_SAT
#define DISABLE_RGB_MATRIX_BAND_VAL
#define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#define DISABLE_RGB_MATRIX_CYCLE_ALL
#define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT

#define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
#define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#define DISABLE_RGB_MATRIX_CYCLE_OUT_IN
#define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL
#define DISABLE_RGB_MATRIX_CYCLE_SPIRAL
#define DISABLE_RGB_MATRIX_DUAL_BEACON
#define DISABLE_RGB_MATRIX_RAINBOW_BEACON
#define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#define DISABLE_RGB_MATRIX_RAINDROPS
#define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS

#define DISABLE_RGB_MATRIX_HUE_BREATHING
#define DISABLE_RGB_MATRIX_HUE_PENDULUM
#define DISABLE_RGB_MATRIX_HUE_WAVE

//#define DISABLE_RGB_MATRIX_TYPING_HEATMAP
#define DISABLE_RGB_MATRIX_DIGITAL_RAIN
//#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE

#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#define DISABLE_RGB_MATRIX_SPLASH
#define DISABLE_RGB_MATRIX_MULTISPLASH
#define DISABLE_RGB_MATRIX_SOLID_SPLASH
#define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH


#endif



#endif
