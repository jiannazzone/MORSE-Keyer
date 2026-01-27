#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_LCTL,  // Dot (left paddle)
        KC_SPC,   // Dash (right paddle)
        KC_ENT    // Fire
    )
};
