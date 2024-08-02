#ifdef ENCODER_ENABLE
#    include QMK_KEYBOARD_H

#    define LEFT_ENCODER 0  // Left encoder index
#    define RIGHT_ENCODER 1 // Right encoder index

void register_alt_if_not_active(void) {
    if (!is_alt_tab_active) {
        is_alt_tab_active = true;
        register_code(KC_LALT);
    }
}

/**
 * Encoder
 * @param index Index of the encoder
 * @param clockwise Direction of the encoder
 */
bool encoder_update_user(uint8_t index, bool clockwise) {

    switch (biton32(layer_state)) {

        // --> LAYER: Qwerty, Gamer
        case _QWERTY:
        case _GAMER:
            if (index == LEFT_ENCODER) {
                // Volume control
                clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
            } else if (index == RIGHT_ENCODER) {
                // Mouse wheel
                clockwise ? tap_code(KC_WH_U) : tap_code(KC_WH_D);
            }
            break;


        // --> LAYER: Lower
        case _LOWER:
            if (index == LEFT_ENCODER) {
                // RGB mode control
                clockwise ? rgblight_step() : rgblight_step_reverse();
            } else if (index == RIGHT_ENCODER) {
                // HSV control (hue, saturation, value)
                switch (hsv_selected) {
                    case 0:
                        clockwise ? rgblight_increase_hue() : rgblight_decrease_hue();
                        break;
                    case 1:
                        clockwise ? rgblight_increase_sat() : rgblight_decrease_sat();
                        break;
                    case 2:
                        clockwise ? rgblight_increase_val() : rgblight_decrease_val();
                        break;
                }
            }
            break;

        // --> LAYER: Raise
        case _RAISE:
            if (index == LEFT_ENCODER) {

                // Window switcher
                register_alt_if_not_active();
                alt_tab_timer = timer_read();
                clockwise ? tap_code16(S(KC_TAB)) : tap_code16(KC_TAB);

            } else if (index == RIGHT_ENCODER) {

                // Tab switcher
                clockwise ? tap_code16(C(KC_TAB)) : tap_code16(S(C(KC_TAB)));

            }
            break;

        // --> LAYER: Adjust
        case _ADJUST:
            if (index == LEFT_ENCODER) {
                // Nothing...
            } else if (index == RIGHT_ENCODER) {
                // Nothing...
            }
            break;
    }
    return false; // To avoid default behaviour (volume up/down...)
}

void matrix_scan_user(void) {
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 1250) {
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
    }
}

#endif
