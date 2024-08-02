#include QMK_KEYBOARD_H
#include "keymap_spanish.h"


enum sofle_layers {
    _QWERTY,
    _GAMER,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_GAMER,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE,
    KC_NXTHSV // Cambia entre Hue, Saturation y Value (para el encoder)
};

// Variables para el control de ventanas (encoder)
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

// Variables para el control de RGB (encoder)
uint8_t hsv_selected = 0; // 0: Hue, 1: Saturation, 2: Value

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* --------------------------------------------------------------------------------------------------------- */

/*
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |       Layer:       |   6  |   7  |   8  |   9  |   0  |  /   |
 * |------+------+------+------+------+------|       QWERTY       |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |BMyus |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   Ñ  |  ´   |
 * |/Shift|      |      |      |      |      | PLAY/ |    | PRINT |      |      |      |      |      |      |
 * |------+------+------+------+------+------| PAUSE |    | SCREE |------+------+------+------+------+------|
 * |LCtrl |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   -  |Enter |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | Win  | LAlt |  ?   |LOWER | / Space /       \ Space\  |RAISE |  ?   | RAlt | Menu |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `---------------------------'-------'           '------''---------------------------'
 */
[_QWERTY] = LAYOUT(
  KC_ESC        ,  ES_1,  ES_2,     ES_3,     ES_4,     ES_5,                  /**/             ES_6,        ES_7,     ES_8,     ES_9,    ES_0,     KC_PSLS,
  KC_TAB        ,  ES_Q,  ES_W,     ES_E,     ES_R,     ES_T,                  /**/             ES_Y,        ES_U,     ES_I,     ES_O,    ES_P,     KC_BSPC,
  SFT_T(KC_CAPS),  ES_A,  ES_S,     ES_D,     ES_F,     ES_G,                  /**/             ES_H,        ES_J,     ES_K,     ES_L,    ES_NTIL,  ES_ACUT,
  KC_LCTL       ,  ES_Z,  ES_X,     ES_C,     ES_V,     ES_B,        KC_MPLY,  /**/   KC_PSCR,  ES_N,        ES_M,     ES_COMM,  ES_DOT,  ES_MINS,  RCTL_T(KC_ENT),
                          KC_LGUI,  KC_LALT,  _______,  MO(_LOWER),  KC_SPC,   /**/   KC_SPC,   MO(_RAISE),  _______,  KC_RALT,  KC_APP
),


/* --------------------------------------------------------------------------------------------------------- */



/*
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |       Layer:       |   6  |   7  |   8  |   9  |   0  |  /   |
 * |------+------+------+------+------+------|       GAMER        |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |BMyus |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   Ñ  |  ´   |
 * |/Shift|      |      |      |      |      | PLAY/ |    | PRINT |      |      |      |      |      |      |
 * |------+------+------+------+------+------| PAUSE |    | SCREE |------+------+------+------+------+------|
 * |LCtrl |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   -  |Enter |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | RGB  | LAlt |  ?   |LOWER | / Space /       \ Space\  |RAISE |  ?   | RAlt | Menu |
 *            | Tog  |      |      |      |/       /         \      \ |      |      |      |      |
 *            `---------------------------'-------'           '------''---------------------------'
 */
[_GAMER] = LAYOUT(
  KC_ESC        ,  ES_1,  ES_2,     ES_3,     ES_4,     ES_5,                  /**/             ES_6,        ES_7,     ES_8,     ES_9,    ES_0,     KC_PSLS,
  KC_TAB        ,  ES_Q,  ES_W,     ES_E,     ES_R,     ES_T,                  /**/             ES_Y,        ES_U,     ES_I,     ES_O,    ES_P,     KC_BSPC,
  SFT_T(KC_CAPS),  ES_A,  ES_S,     ES_D,     ES_F,     ES_G,                  /**/             ES_H,        ES_J,     ES_K,     ES_L,    ES_NTIL,  ES_ACUT,
  KC_LCTL       ,  ES_Z,  ES_X,     ES_C,     ES_V,     ES_B,        KC_MPLY,  /**/   KC_PSCR,  ES_N,        ES_M,     ES_COMM,  ES_DOT,  ES_MINS,  RCTL_T(KC_ENT),
                          RGB_TOG,  KC_LALT,  _______,  MO(_LOWER),  KC_SPC,   /**/   KC_SPC,   MO(_RAISE),  _______,  KC_RALT,  KC_APP
),


/* --------------------------------------------------------------------------------------------------------- */


/*
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  º   |      |      |      |      |      |        Layer:      |      |      |      |      |   |  |  \   |
 * |------+------+------+------+------+------|        LOWER       |------+------+------+------+------+------|
 * |      |      |  €   |  #   |   '  |   "  |       (Symbols)    |   (  |   )  |   ¡  |  !   |   *  | Supr |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  @   |  $   |   &  |   %  |-------.    ,-------|   [  |   ]  |   ¿  |   ?   |   +  |  `   |
 * |------+------+------+------+------+------|RGB_TOG|    |NXTHSV |------+------+------+------+------+------|
 * |      |      |      |      |   <  |   >  |-------|    |-------|   {  |   }  |   ;  |  :  |  _   |  =   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |LOWER | /       /       \      \  |RAISE |      |      |      |
 *            |      |      |      |  👆  |/       /         \      \ |      |      |      |      |
 *            `---------------------------'-------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  MT(ES_FORD, ES_MORD),  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  ES_PIPE,  ES_BSLS,
  XXXXXXX             ,  XXXXXXX,  ES_EURO,  ES_HASH,  ES_QUOT,  ES_DQUO,                        ES_LPRN,  ES_RPRN,  ES_IEXL,  ES_EXLM,  ES_ASTR,  KC_DEL,
  XXXXXXX             ,  XXXXXXX,  ES_AT  ,  ES_DLR ,  ES_AMPR,  ES_PERC,                        ES_LBRC,  ES_RBRC,  ES_IQUE,  ES_QUES,  ES_PLUS,  ES_GRV,
  XXXXXXX             ,  XXXXXXX,  XXXXXXX,  XXXXXXX,  ES_LABK,  ES_RABK,  RGB_TOG,  KC_NXTHSV,  ES_LCBR,  ES_RCBR,  ES_SCLN,  ES_COLN,  ES_UNDS,  ES_EQL,
                                   XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  XXXXXXX,  XXXXXXX  ,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX
),


/* --------------------------------------------------------------------------------------------------------- */



/*
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | F1   |  F2  |  F3  |  F4  |  F5  |  F6  |       Layer:       |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|       RAISE        |------+------+------+------+------+------|
 * |  ?   |      |      |      |      |      |    (Navigation)    |Inicio|  ⏮  |  🔼  |  ⏭  |      | Supr |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  ?   |      |      |      |      |      |-------.    ,-------| Fin  |   ◀  |  🔽  |  ▶   |      | PGUP |
 * |------+------+------+------+------+------|   ?   |    |   ?   |------+------+------+------+------+------|
 * |  ?   | Undo |  Cut | Copy |Paste |      |-------|    |-------|      |      |      |      |      | PGDN |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |  ?   |  ?   |  ?   |LOWER | /   ?   /       \  ?   \  |RAISE |  ?   |  ?   |  ?   |
 *            |      |      |      |      |/       /         \      \ |  👆  |      |      |      |
 *            `---------------------------'-------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
  KC_F1  ,  KC_F2  ,  KC_F3  ,  KC_F4  ,  KC_F5   ,  KC_F6  ,                      KC_F7  ,  KC_F8   ,  KC_F9  ,  KC_F10  ,  KC_F11 ,  KC_F12,
  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX ,  XXXXXXX,                      KC_HOME,  KC_PRVWD,  KC_UP  ,  KC_NXTWD,  XXXXXXX,  KC_DEL,
  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX ,  XXXXXXX,                      KC_END ,  KC_LEFT ,  KC_DOWN,  KC_RGHT ,  XXXXXXX,  KC_PGUP,
  _______,  KC_UNDO,  KC_CUT ,  KC_COPY,  KC_PASTE,  XXXXXXX,  _______,  _______,  XXXXXXX,  XXXXXXX ,  XXXXXXX,  XXXXXXX ,  XXXXXXX,  KC_PGDN,
                      _______,  _______,  _______ ,  _______,  _______,  _______,  _______,  _______ ,  _______,  _______
),


/* --------------------------------------------------------------------------------------------------------- */



/*
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Reb. | Qwer |Gamer |      |      |      |       Layer:       |      |      |      |      |      |      |
 * |------+------+------+------+------+------|       ADJUST       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |  ?   |  ?   |  ?   |LOWER | /   ?   /       \  ?   \  |RAISE |  ?   |  ?   |  ?   |
 *            |      |      |      |  👆  |/       /         \      \ |  👆   |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_ADJUST] = LAYOUT(
  QK_RBT ,  KC_QWERTY,  KC_GAMER,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  XXXXXXX,  XXXXXXX  ,  XXXXXXX ,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  XXXXXXX,  XXXXXXX  ,  XXXXXXX ,  XXXXXXX,  XXXXXXX,  XXXXXXX,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  XXXXXXX,  XXXXXXX  ,  XXXXXXX ,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                        _______ ,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  )
};


/* --------------------------------------------------------------------------------------------------------- */


layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_GAMER:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAMER);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
        case KC_NXTHSV:
            hsv_selected++;
            if (hsv_selected > 2) {
                hsv_selected = 0;
            }
            break;
    }
    return true;
}


#include "encoder.c"
#include "oled.c"
