#include "yeet30.h"


#ifdef RGB_MATRIX_ENABLE


#define RGBLIGHT_LED_MAP { 3, 2, 1, 0 }

//https://docs.qmk.fm/#/feature_rgb_matrix?id=common-configuration

led_config_t g_led_config = { {
    { 17, 18, 52, 53, 83, 72 }
}, {
    { 0,   0 }, { 15,   0 }, { 30,   0 }, { 45,   0 }, { 60,   0 }, { 75,   0 }
}, {
    1, 1, 1, 1, 1, 1
} };
#endif
