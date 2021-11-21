#include "yeet30.h"

void matrix_init_kb(void) {
    uprintf("Welcome to Logan Keyboard v3.0!!!!");

#if 0
#ifdef BACKLIGHT_ENABLE
    backlight_enable();
    backlight_level(5);
#endif
#ifdef RGBLIGHT_ENABLE
    rgblight_enable();
    rgblight_sethsv(0, 255, 255);

//#ifdef RGBLIGHT_ANIMATIONS

    rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 2);
//#endif
#endif
#endif
}
