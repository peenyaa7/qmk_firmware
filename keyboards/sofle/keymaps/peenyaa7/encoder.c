#ifdef ENCODER_ENABLE
#include QMK_KEYBOARD_H

#define LEFT_ENCODER 0 // Left encoder index
#define RIGHT_ENCODER 1 // Right encoder index

/**
 * Encoder
 * @param index Index of the encoder
 * @param clockwise Direction of the encoder
*/
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == LEFT_ENCODER) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == RIGHT_ENCODER) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}

#endif
