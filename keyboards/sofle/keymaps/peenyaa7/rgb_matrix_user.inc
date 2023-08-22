RGB_MATRIX_EFFECT(PEENYAA7)
RGB_MATRIX_EFFECT(RED)
RGB_MATRIX_EFFECT(GREEN)
RGB_MATRIX_EFFECT(BLUE)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static bool PEENYAA7(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    rgb_matrix_set_color_all(0x00, 0x00, 0xFF);

    return rgb_matrix_check_finished_leds(led_max);
}

static bool RED(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    rgb_matrix_set_color_all(0xFF, 0x00, 0x00);

    return rgb_matrix_check_finished_leds(led_max);
}

static bool GREEN(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    rgb_matrix_set_color_all(0x00, 0xFF, 0x00);

    return rgb_matrix_check_finished_leds(led_max);
}

static bool BLUE(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    rgb_matrix_set_color_all(0x00, 0x00, 0xFF);

    return rgb_matrix_check_finished_leds(led_max);
}

#endif