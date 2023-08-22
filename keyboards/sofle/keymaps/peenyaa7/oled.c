#ifdef OLED_ENABLE
#include QMK_KEYBOARD_H

/**
 * Render the QMK logo on right hand side
*/
static void render_slave_oled(void) {
    // static const char PROGMEM qmk_logo[] = {
    //     0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    //     0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    //     0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    // };

    static const char PROGMEM lovebird[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 
        0xe0, 0xe0, 0xe0, 0x60, 0x70, 0x70, 0x70, 0x70, 0x70, 0x60, 0x60, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x70, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0x0f, 0x03, 
        0x01, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0xff, 0xfc, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf0, 0x3c, 0x1e, 0x0f, 0x07, 0x01, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0xc0, 0xf0, 0xfe, 0x1f, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0xfc, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x1f, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x01, 0x0f, 0x3f, 0xfc, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0f, 0x1e, 0x38, 0x70, 0xe0, 0xc0, 0x80, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 
        0x07, 0x0e, 0x1c, 0x38, 0xf0, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x80, 0xc0, 0xf0, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x38, 0x7c, 
        0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xf8, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x7f, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    oled_write_raw_P(lovebird, sizeof(lovebird));
}

void printCurrentMode(void) {

    static const char PROGMEM base[] = {
        0x80, 0x81, 0x81, 0x91, 0x82,
        0xA0, 0xAF, 0xB0, 0xB1, 0xA2,
        0xC0, 0xCF, 0xD0, 0xC1, 0xC2, 0};
    static const char PROGMEM symbols[] = {
        0x80, 0x8C, 0x8D, 0x8E, 0x82,
        0xA0, 0xAC, 0xAD, 0xAE, 0xA2,
        0xC0, 0xCC, 0xCD, 0xCE, 0xC2, 0};
    static const char PROGMEM nav[] = {
        0x80, 0x81, 0xAA, 0x81, 0x82,
        0xA0, 0xC9, 0xCA, 0xCB, 0xA2,
        0xC0, 0xC1, 0xAB, 0xC1, 0xC2, 0};
    static const char PROGMEM adjust[] = {
        0x80, 0x87, 0x88, 0x87, 0x82,
        0xA0, 0xA7, 0xA8, 0xA9, 0xA2,
        0xC0, 0xC7, 0xC8, 0xC8, 0xC2, 0};
    static const char PROGMEM gamer[] = {
        0x80, 0x83, 0x84, 0x83, 0x82,
        0xA3, 0xA4, 0xA5, 0xA6, 0xA3,
        0xC3, 0xC4, 0xC1, 0xC4, 0xC6, 0};
    
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(base, false);
            break;
        case _LOWER:
            oled_write_ln_P(symbols, false);
            break;
        case _RAISE:
            oled_write_ln_P(nav, false);
            break;
        case _ADJUST:
            oled_write_ln_P(adjust, false);
            break;
        case _GAMER:
            oled_write_ln_P(gamer, false);
            break;

        default:
            oled_write_ln_P(gamer, false);
            break;
    }
}

void printMayusStatus(void) {

    static const char PROGMEM mayusOff[] = {
        0x80, 0xB7, 0x81, 0xB9, 0x82,
        0xA0, 0xD7, 0xD8, 0xD9, 0xA2,
        0xC0, 0xC1, 0xC1, 0xC1, 0xC2, 0};
    static const char PROGMEM mayusOn[] = {
        0x80, 0xBA, 0x81, 0xBC, 0x82,
        0xA0, 0xDA, 0xDB, 0xDC, 0xA2,
        0xC0, 0xC1, 0xC1, 0xC1, 0xC2, 0};

    led_t led_usb_state = host_keyboard_led_state();
    if (led_usb_state.caps_lock) {
        oled_write_ln_P(mayusOn, false);
    } else {
        oled_write_ln_P(mayusOff, false);
    }
}

static void render_master_oled(void) {

    static const char PROGMEM myName[] = {
        0xB2, 0xB3, 0xB4, 0xB5, 0xB6,
        0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0};

    // Print current mode (3 lines)
    printCurrentMode();

    // Fill with spaces (1 lines)
    //oled_write_ln_P(PSTR("     "), false);

    // Print layer name (1 line)
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("PIUII"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("LOWER"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("RAISE"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("ADJST"), false);
            break;
        case _GAMER:
            oled_write_P(PSTR("GAMER"), false);
            break;

        default:
            oled_write_P(PSTR("GAMER"), false);
            break;
    }

    // Fill with spaces (5 lines)
    for (int i = 0; i < 5; i++) {
        oled_write_P(PSTR("     "), false);
    }

    // Print mayus status (3 lines)
    printMayusStatus();

    // Fill with spaces (1 lines)
    //oled_write_ln_P(PSTR("     "), false);

    // Print my name (2 line)
    oled_write_P(myName, false);

}

/**
 * Rotación de la pantalla OLED
*/
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    // if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    // }
    // return rotation;
}

/**
 * Main OLED task
 * This is called every time the OLED needs to be updated
 * 
 * - Right --> QMK logo
 * - Left --> Info
*/
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // Izquierda
        render_master_oled();
    } else {
        // Derecha
        render_slave_oled();
    }
    return false;
}

#endif