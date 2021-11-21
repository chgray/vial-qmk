#include QMK_KEYBOARD_H

    // 18, 17, 17, 16, 15, 11

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
      KC_0, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_B, KC_C, KC_D, KC_E, KC_F, KC_G, KC_H, \
      KC_0, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_1, KC_B, KC_C, KC_D, KC_E, KC_F, KC_G, \
      KC_0, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_2, KC_B, KC_C, KC_D, KC_E, KC_F, KC_G, \
      KC_0, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_3, KC_B, KC_C, KC_D, KC_E, KC_F, \
      KC_0, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_4, KC_B, KC_C, KC_D, KC_E, \
      KC_0, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_5 \
  )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
//#ifdef CONSOLE_ENABLE

#if VIA_ENABLE
    uprintf("VIA - KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
//#endif
  return true;
}
