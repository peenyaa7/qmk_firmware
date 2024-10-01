

// Override #1: Reemplaza CTRL+Z a KC_UNDO
const key_override_t ctrl_z_override = ko_make_basic(MOD_MASK_CTRL, KC_Z, KC_UNDO);

// Override #1: Reemplaza CTRL+X a KC_CUT
const key_override_t ctrl_x_override = ko_make_basic(MOD_MASK_CTRL, KC_X, KC_CUT);

// Override #2: Reemplaza CTRL+C a KC_COPY
const key_override_t ctrl_c_override = ko_make_basic(MOD_MASK_CTRL, KC_C, KC_COPY);

// Override #1: Reemplaza CTRL+V a KC_PASTE
const key_override_t ctrl_v_override = ko_make_basic(MOD_MASK_CTRL, KC_V, KC_PASTE);


// -----------------------------------------------------------------------------

// Lista de Key Overrides
const key_override_t **key_overrides = (const key_override_t *[]){
    &ctrl_z_override,
    &ctrl_x_override,
    &ctrl_c_override,
    &ctrl_v_override,
    NULL  // Termina la lista
};