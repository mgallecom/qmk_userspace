/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2021 Arda Kilicdagi <GH: @ardakilic, TW: @ardadev>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "mgallecom.h"
#include "os_detection.h"
// animation vars

#define ANIM_INVERT false
#define ANIM_RENDER_WPM true
#define FAST_TYPE_WPM 60 //Switch to fast animation when over words per minute


#include "combos.h"

const uint32_t unicode_map[] PROGMEM = {

};

tap_dance_action_t tap_dance_actions[] = {
    [TD_ALFRED_PASTE] = ACTION_TAP_DANCE_DOUBLE( G(KC_V) , C(G(A(KC_V))) ),
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// Layers share the 5-column core defined in users/mgallecom/mgallecom.h; diagrams are in KEYMAPS.md.
// The outer columns and thumb keys below are Corne-specific.
  [_BASE] = LAYOUT_mgallecom_split_3x6_3(
    XXXXXXX,       ___5BASE_1_L___,           ___5BASE_1_R___, XXXXXXX,
    XXXXXXX,       ___5BASE_2_L___,           ___5BASE_2_R___, XXXXXXX,
    MG_SCAP,       ___5BASE_3_L___,           ___5BASE_3_R___, XXXXXXX, /*KC_ENT*/
                ___BASE_THUMB_L___,           ___BASE_THUMB_R___

  ),

// Media layer (Esc/MED). Outer keys: bootloader (left), OS mode toggle (right).
  [_MED] = LAYOUT_mgallecom_split_3x6_3(
    QK_BOOT,       ___5MED_1_L___,           ___5MED_1_R___, MG_WIN,
    XXXXXXX,       ___5MED_2_L___,           ___5MED_2_R___, XXXXXXX,
    XXXXXXX,       ___5MED_3_L___,           ___5MED_3_R___, XXXXXXX, /*KC_ENT*/
                ___MED_THUMB_L___,           ___MED_THUMB_R___
  ),

// Navigation layer (Spc/NAV).
  [_NAV] = LAYOUT_mgallecom_split_3x6_3(
    XXXXXXX,       ___5NAV_1_L___,           ___5NAV_1_R___, XXXXXXX,
    XXXXXXX,       ___5NAV_2_L___,           ___5NAV_2_R___, XXXXXXX,
    XXXXXXX,       ___5NAV_3_L___,           ___5NAV_3_R___, XXXXXXX, /*KC_ENT*/
                ___NAV_THUMB_L___,           ___NAV_THUMB_R___
  ),

// Symbol layer (SYM thumb). Outer key: backspace (right).
  [_SYM] = LAYOUT_mgallecom_split_3x6_3(
    XXXXXXX,       ___5SYM_1_L___,           ___5SYM_1_R___, KC_BSPC,
    XXXXXXX,       ___5SYM_2_L___,           ___5SYM_2_R___, XXXXXXX,
    XXXXXXX,       ___5SYM_3_L___,           ___5SYM_3_R___, XXXXXXX, /*KC_ENT*/
                ___SYM_THUMB_L___,           ___SYM_THUMB_R___
  ),


// Number layer (BS/NUM). Outer key: backspace (right).
  [_NUM] = LAYOUT_mgallecom_split_3x6_3(
    XXXXXXX,       ___5NUM_1_L___,           ___5NUM_1_R___, KC_BSPC,
    XXXXXXX,       ___5NUM_2_L___,           ___5NUM_2_R___, XXXXXXX,
    XXXXXXX,       ___5NUM_3_L___,           ___5NUM_3_R___, XXXXXXX, /*KC_ENT*/
                ___NUM_THUMB_L___,           ___NUM_THUMB_R___
  ),



// Function layer (Del/FUN). Outer key: bootloader (right).
  [_FUN] = LAYOUT_mgallecom_split_3x6_3(
    XXXXXXX,       ___5FUN_1_L___,           ___5FUN_1_R___, QK_BOOT,
    XXXXXXX,       ___5FUN_2_L___,           ___5FUN_2_R___, XXXXXXX,
    XXXXXXX,       ___5FUN_3_L___,           ___5FUN_3_R___, XXXXXXX, /*KC_ENT*/
                ___FUN_THUMB_L___,           ___FUN_THUMB_R___
  )
};


#ifdef OLED_ENABLE

#include "mario.c"

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}


void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case _MED:
            oled_write_ln_P(PSTR("Media"), false);
            break;
        case _NAV:
            oled_write_ln_P(PSTR("Nav"), false);
            break;
        case _NUM:
            oled_write_ln_P(PSTR("Num"), false);
            break;
        case _SYM:
            oled_write_ln_P(PSTR("Sym"), false);
            break;
        case _FUN:
        // case _ADJUST|_LOWER:
        // case _ADJUST|_RAISE:
        // case _ADJUST|_LOWER|_RAISE:
        // case _ADJUST|_LOWER|_RAISE|_SPACE:
        // case _ADJUST|_LOWER|_RAISE|_SPACE|_NUMPAD|_SODA:
            oled_write_ln_P(PSTR("Fun"), false);
            break;
        default:
            oled_write_ln_P(PSTR("?????"), false);
    }
}


void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}



bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
    } else {
        oled_render_anim();

    }
    return false;
}
#endif // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    return mgallecom_process_record_user(keycode, record);

}

bool process_detected_host_os_user(os_variant_t os) {
  if (os==OS_MACOS || os==OS_IOS) {
    mgallecom_set_mac_mode();
  } else {
    mgallecom_set_win_mode();
  }
  return true;
}
