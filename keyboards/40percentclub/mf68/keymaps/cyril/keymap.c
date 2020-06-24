#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _FN1 7
#define _MEDIA 8
#define _RESET 9

enum custom_keycodes {
    BSP_DEL = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_68_ansi(
    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  BSP_DEL,          KC_INS,  KC_HOME,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_DEL,  KC_END,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                   KC_RSFT,          KC_UP,
    KC_LCTL, KC_LGUI, LM(_FN1,MOD_LALT),                  LT(_MEDIA,KC_SPC),                  KC_RALT, MO(_MEDIA),KC_RCTL,        KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [_FN1] = LAYOUT_68_ansi(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,          _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, MO(_RESET),       _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,          _______,
    _______, _______, _______,                            _______,                            _______, _______, _______,          _______, _______, _______
  ),
  [_MEDIA] = LAYOUT_68_ansi(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,          KC_VOLU, KC_PGUP,
    KC_CAPS, KC_BTN3, _______, KC_UP,   _______, _______, _______, _______, _______, _______, KC_PSCR, _______, BL_STEP, _______,          KC_VOLD, KC_PGDN,
    _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______,          _______,
    KC_CAPS, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_HOME, KC_END,  _______,                   _______,          KC_MUTE,
    _______, _______, _______,                            _______,                            _______, _______, _______,          KC_MPRV, KC_MPLY, KC_MNXT
  ),
  [_RESET] = LAYOUT_68_ansi(
    RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,          _______,
    _______, _______, _______,                            _______,                            _______, _______, _______,          _______, _______, _______
  )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint8_t saved_mods   = 0;
    uint16_t       temp_keycode = keycode;

    // Filter out the actual keycode from MT and LT keys.
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        temp_keycode &= 0xFF;
    }

    switch (temp_keycode) {
        case BSP_DEL:
            if (record->event.pressed) {
                saved_mods = get_mods() & MOD_MASK_SHIFT;

                if (saved_mods == MOD_MASK_SHIFT) {  // Both shifts pressed
                    register_code(KC_DEL);
                } else if (saved_mods) {   // One shift pressed
                    del_mods(saved_mods);  // Remove any Shifts present
                    register_code(KC_DEL);
                    add_mods(saved_mods);  // Add shifts again
                } else {
                    register_code(KC_BSPC);
                }
            } else {
                unregister_code(KC_DEL);
                unregister_code(KC_BSPC);
            }
            return false;
#ifdef RGB_MATRIX_ENABLE
#endif
    }
    return true;
}
