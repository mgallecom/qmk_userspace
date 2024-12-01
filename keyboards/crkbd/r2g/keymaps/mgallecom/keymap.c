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


enum combos {
    IO_DASH,
    KL_COLON,
    SD_ALF
};
const uint32_t unicode_map[] PROGMEM = {

};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {RCTL_T(KC_K), RALT_T(KC_L), COMBO_END};
const uint16_t PROGMEM sd_combo[] = {LALT_T(KC_S), LCTL_T(KC_D), COMBO_END};
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};

combo_t key_combos[] = {
[IO_DASH] = COMBO(io_combo, KC_MINUS),
[KL_COLON] = COMBO(kl_combo, KC_SEMICOLON),
[SD_ALF] = COMBO(sd_combo, A(KC_SPACE))
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_ALFRED_PASTE] = ACTION_TAP_DANCE_DOUBLE( G(KC_V) , C(G(A(KC_V))) ),
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * BASE LAYER
  [_QWERTY] = LAYOUT_wrapper( \
  //,-----------------------------------------------------.      ,----------------------------------------------------.
    |  hmrw  |   Q    |   W    |   E    |   R    |   T    |      |    Y   |   U    |   I    |   O    |   P    |  Alfr |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    | ------ |   A    |   S    |   D    |   F    |   G    |      |    H   |   J    |   K    |   L    |   '    |  ;    |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    | SftCaps|   Z    |   X    |   C    |   V    |   B    |      |    N   |   M    |   ,    |   .    |   /    | ----- |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
                                    ,-----------------------,  ,-----------------------.
                                    |Med/Esc|Nav/Spc|Til/Tab|  |Sym/Ent|Num/Bsp|Fun/Del|
                                   /|-------+-------+-------'  +-------+-------+-------|\
  ),
*/
  [_BASE] = LAYOUT_mgallecom_split_3x6_3(
    XXXXXXX,       ___5BASE_1_L___,           ___5BASE_1_R___, XXXXXXX,
    XXXXXXX,       ___5BASE_2_L___,           ___5BASE_2_R___, XXXXXXX,
    MG_SCAP,       ___5BASE_3_L___,           ___5BASE_3_R___, XXXXXXX, /*KC_ENT*/
                ___BASE_THUMB_L___,           ___BASE_THUMB_R___

  ),

/*
 * Media LAYER
  [_MEDIA] = LAYOUT_wrapper( \
  //,-----------------------------------------------------.      ,-----------------------------------------------------.
    |  BOOT  | ------ | ------ | ------ | ------ | ------ |      | ------ | RGBTOG | RGBMOD | RGBHUI | RGBSAI | RGBVAI |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+------- |
    | ------ |KC_LCTL |KC_LALT |KC_LGUI |KC_LSFT | ------ |      | ------ |KC_MPRV |KC_VOLD |KC_VOLU |KC_MNXT | ------ |
  //|------yy--+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------|
    | ------ |KC_ALGR | ------ | ------ | ------ | ------ |      | ------ | ------ | ------ |KC_BRMD |KC_BRMU | ------ |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+--------|
                                    ,-----------------------,  ,-----------------------.
                                    |       |       |       |  |KC_MSTP|KC_MPLY|KC_MUTE|
                                   /|-------+-------+-------'  +-------+-------+-------|\
  ),
*/
  [_MED] = LAYOUT_mgallecom_split_3x6_3(
    QK_BOOT,       ___5MED_1_L___,           ___5MED_1_R___, MG_WIN,
    XXXXXXX,       ___5MED_2_L___,           ___5MED_2_R___, XXXXXXX,
    XXXXXXX,       ___5MED_3_L___,           ___5MED_3_R___, XXXXXXX, /*KC_ENT*/
                ___MED_THUMB_L___,           ___MED_THUMB_R___
  ),

/*
 * NAVIGATION LAYER
  [_TPL] = LAYOUT_wrapper( \
  //,-----------------------------------------------------.      ,----------------------------------------------------.
    | ------ |  Save  |AlfPaste|  Copy  |  Cut   |  Undo  |      |  Save  |AlfPaste|  Copy  |  Cut   |  Undo  | ----- |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    | ------ |KC_LCTL |KC_LALT |KC_LGUI |KC_LSFT | ------ |      |KC_CAPS |KC_LEFT |KC_DOWN |  KC_UP |KC_RGHT | ----- |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    | ------ |KC_ALGR | ------ | ------ | ------ | ------ |      | KC_INS |KC_HOME |KC_PGDN |KC_PGUP | KC_END | ----- |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
                                    ,-----------------------,  ,-----------------------.
                                    |       |       |       |  | KC_ENT|KC_BSPC| KC_DEL|
                                   /|-------+-------+-------'  +-------+-------+-------|\
  ),
*/
  [_NAV] = LAYOUT_mgallecom_split_3x6_3(
    XXXXXXX,       ___5NAV_1_L___,           ___5NAV_1_R___, XXXXXXX,
    XXXXXXX,       ___5NAV_2_L___,           ___5NAV_2_R___, XXXXXXX,
    XXXXXXX,       ___5NAV_3_L___,           ___5NAV_3_R___, XXXXXXX, /*KC_ENT*/
                ___NAV_THUMB_L___,           ___NAV_THUMB_R___
  ),

/*
 * SYMBOL LAYER
 *
  [_SYM] = LAYOUT_wrapper( \
  //,-----------------------------------------------------.      ,----------------------------------------------------.
    |        |  PIPE  |   &    |   *    |   \    |   []   |      |        |        |        |        |        |  Bksp |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    |        |    :   |   $    |   %    |   ^    |   ()   |      |        |  SHIFT |   CMD  |   ALT  |  CTRL  |       |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    |        |   ~    |    !   |   @    |   #    |   {}   |      |        |        |        |        |        |       |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
                                    ,-----------------------,  ,-----------------------.
                                    |   ;   |   -   |   _   |  |       |       |       |
                                   /|-------+-------+-------'  +-------+-------+-------|\
  ),
*/
  [_SYM] = LAYOUT_mgallecom_split_3x6_3(
    XXXXXXX,       ___5SYM_1_L___,           ___5SYM_1_R___, KC_BSPC,
    XXXXXXX,       ___5SYM_2_L___,           ___5SYM_2_R___, XXXXXXX,
    XXXXXXX,       ___5SYM_3_L___,           ___5SYM_3_R___, XXXXXXX, /*KC_ENT*/
                ___SYM_THUMB_L___,           ___SYM_THUMB_R___
  ),


  /*
 * NUMBER LAYER
  [_TPL] = LAYOUT_wrapper( \
  //,-----------------------------------------------------.      ,----------------------------------------------------.
    |        |   =    |   7    |   8    |   9    |   *    |      |        |        |        |        |        |  Bksp |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    |        |   :    |   4    |   5    |   6    |   -    |      |        |  SHIFT |   CMD  |   ALT  |  CTRL  |       |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    |        |   /    |   1    |   2    |   3    |   +    |      |        |        |        |        |        |       |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
                                    ,-----------------------,  ,-----------------------.
                                    |   .   |   0   |   ,   |  |       |       |       |
                                   /|-------+-------+-------'  +-------+-------+-------|\
  ),
*/
  [_NUM] = LAYOUT_mgallecom_split_3x6_3(
    XXXXXXX,       ___5NUM_1_L___,           ___5NUM_1_R___, KC_BSPC,
    XXXXXXX,       ___5NUM_2_L___,           ___5NUM_2_R___, XXXXXXX,
    XXXXXXX,       ___5NUM_3_L___,           ___5NUM_3_R___, XXXXXXX, /*KC_ENT*/
                ___NUM_THUMB_L___,           ___NUM_THUMB_R___
  ),



/*
 * FUN LAYER
  [_TPL] = LAYOUT_wrapper( \
  //,-----------------------------------------------------.      ,----------------------------------------------------.
    |        |   F12  |   F7   |   F8   |   F9   |PRNTSCRN|      |        |        |        |        |        |QK_BOOT|
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    |        |   F11  |   F4   |   F5   |   F6   |        |      |        |  SHIFT |   CMD  |   ALT  |  CTRL  |       |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
    |        |   F10  |   F1   |   F2   |   F3   | PAUSE  |      |        |        |        |        |        |       |
  //|--------+--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------+-------|
                                    ,-----------------------,  ,-----------------------.
                                    |  ESC  | SPACE |  TAB  |  |       |       |       |
                                   /|-------+-------+-------'  +-------+-------+-------|\
  ),
*/
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
