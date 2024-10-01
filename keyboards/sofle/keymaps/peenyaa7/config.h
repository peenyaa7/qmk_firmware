#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

// ##############################
// #          GLOBAL            #
// ##############################

#define MASTER_LEFT
#define OLED_FONT_H "keyboards/sofle/keymaps/peenyaa7/font.c"

#ifdef TAPPING_TERM
    #undef TAPPING_TERM
    #define TAPPING_TERM 200
#endif

// ##############################
// #            RGB             #
// ##############################

// LED: SK6812 Mini
#define RGB_DI_PIN D3 // Pin que conecta el LED
#define WS2812_DI_PIN D3 // El driver WS2812 soporta SK6812 Mini
#define RGBLED_NUM 70 // Número de LEDs
#define RGBLED_NUM_EACH_SIDE 35
// #define WS2812_BYTE_ORDER WS2812_BYTE_ORDER_GRB // SK6812 Mini

#ifdef RGBLIGHT_ENABLE

    #define DRIVER_LED_TOTAL RGBLED_NUM
    #define RGBLED_SPLIT { RGBLED_NUM_EACH_SIDE, RGBLED_NUM_EACH_SIDE }

    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 5
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17

    #define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */

    #define RGBLIGHT_ANIMATIONS
    
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_TWINKLE

    #undef RGBLIGHT_EFFECT_SNAKE
    #undef RGBLIGHT_EFFECT_STATIC_GRADIENT
    #undef RGBLIGHT_EFFECT_RGB_TEST
    #undef RGBLIGHT_EFFECT_ALTERNATING

#endif


// ##############################
// #         ENCODERS           #
// ##############################

#define ENCODER_DIRECTION_FLIP
#undef  ENCODER_RESOLUTION
#define ENCODER_RESOLUTION 1

// ##############################
// #          OTHERS            #
// ##############################


// Reduce size
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
