/* Copyright 2024 Manuel Galle
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H
#include "mgallecom.h"
#include "os_detection.h"

tap_dance_action_t tap_dance_actions[] = {
    [TD_CURLIES] = ACTION_TAP_DANCE_DOUBLE( KC_LCBR , KC_RCBR ),
    [TD_BRACKS] = ACTION_TAP_DANCE_DOUBLE( KC_LBRC , KC_RBRC ),
    [TD_BRACKS_NORMAL] = ACTION_TAP_DANCE_DOUBLE( KC_LPRN , KC_RPRN ),
    [TD_ALFRED_PASTE] = ACTION_TAP_DANCE_DOUBLE( C(KC_V) , C(A(KC_V)) ),
};

const uint32_t unicode_map[] PROGMEM = {

};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BASE] = LAYOUT_mgallecom_planck_mit(
		                        ___5BASE_1_L___,    MG_WIN,    KC_NO,  ___5BASE_1_R___,
                                ___5BASE_2_L___,    KC_NO,      KC_NO,  ___5BASE_2_R___,
		                        ___5BASE_3_L___,    KC_NO,      KC_NO,  ___5BASE_3_R___,
		MG_SCAP,  KC_NO,  ___BASE_THUMB_L___,   A(KC_SPACE),     ___BASE_THUMB_R___,  XXXXXXX, XXXXXXX
	),

	[_MED] = LAYOUT_mgallecom_planck_mit(
		                    ___5MED_1_L___,   KC_NO,    KC_NO,     ___5MED_1_R___,
		                    ___5MED_2_L___,   KC_NO,    KC_NO,     ___5MED_2_R___,
		                    ___5MED_3_L___,   KC_NO,    KC_NO,     ___5MED_3_R___,
		KC_NO,    KC_NO,    ___MED_THUMB_L___,        KC_NO,         ___MED_THUMB_R___,  KC_NO,    KC_NO
	),

	[_NAV] = LAYOUT_mgallecom_planck_mit(
		                    ___5NAV_1_L___,   KC_NO,    KC_NO,     ___5NAV_1_R___,
		                    ___5NAV_2_L___,   KC_NO,    KC_NO,     ___5NAV_2_R___,
		                    ___5NAV_3_L___,   KC_NO,    KC_NO,     ___5NAV_3_R___,
		KC_NO,    KC_NO,    ___NAV_THUMB_L___,        KC_NO,         ___NAV_THUMB_R___,  KC_NO,    KC_NO
	),

	[_SYM] = LAYOUT_mgallecom_planck_mit(
		                    ___5SYM_1_L___,   KC_NO,    KC_NO,     ___5SYM_1_R___,
		                    ___5SYM_2_L___,   KC_NO,    KC_NO,     ___5SYM_2_R___,
		                    ___5SYM_3_L___,   KC_NO,    KC_NO,     ___5SYM_3_R___,
		KC_NO,    KC_NO,    ___SYM_THUMB_L___,        KC_NO,         ___SYM_THUMB_R___,  KC_NO,    KC_NO
	),

	[_NUM] = LAYOUT_mgallecom_planck_mit(
		                    ___5NUM_1_L___,   KC_NO,    KC_NO,     ___5NUM_1_R___,
		                    ___5NUM_2_L___,   KC_NO,    KC_NO,     ___5NUM_2_R___,
		                    ___5NUM_3_L___,   KC_NO,    KC_NO,     ___5NUM_3_R___,
		KC_NO,    KC_NO,    ___NUM_THUMB_L___,        KC_NO,         ___NUM_THUMB_R___,  KC_NO,    KC_NO
	),

	[_FUN] = LAYOUT_mgallecom_planck_mit(
		                    ___5FUN_1_L___,   KC_NO,    KC_NO,     ___5FUN_1_R___,
		                    ___5FUN_2_L___,   KC_NO,    KC_NO,     ___5FUN_2_R___,
		                    ___5FUN_3_L___,   KC_NO,    KC_NO,     ___5FUN_3_R___,
		KC_NO,    KC_NO,    ___FUN_THUMB_L___,        KC_NO,         ___FUN_THUMB_R___,  KC_NO,    KC_NO
	)

    bool process_record_user(uint16_t keycode, keyrecord_t *record) {

       return mgallecom_process_record_user(keycode, record);

    }

};

