#include QMK_KEYBOARD_H

// 18, 17, 17, 16, 15, 11
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
      KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F8, KC_F10, KC_F11, KC_F12, KC_NO, KC_NO, KC_PSCREEN, KC_SCROLLLOCK, KC_PAUSE, \
      KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINUS, KC_EQUAL, KC_BSLASH, KC_INSERT, KC_HOME, KC_PGUP, \
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRACKET, KC_RBRACKET, KC_BSLASH, KC_DEL, KC_END, KC_PGDOWN, \
      KC_CAPSLOCK, KC_B, KC_B, KC_B, KC_B, KC_B, KC_B, KC_B, KC_B, KC_B, KC_B, KC_B, KC_B, KC_B, KC_B, KC_B, \
      KC_B, KC_B, KC_B, KC_B, KC_B, KC_B, KC_B, KC_B, KC_B, KC_B, KC_B, KC_B, KC_B, KC_B, KC_B, \
      KC_B, KC_B, KC_B, KC_B, KC_B, KC_B, KC_B, KC_B, KC_B, KC_B, KC_B \
  )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#if VIA_ENABLE
    uprintf("VIA - KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
  return true;
}
