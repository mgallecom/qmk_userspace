/*
Copyright 2024 Manuel Galle

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

#pragma once

#include "mgallecom.h"

// Included from keymap.c (not built separately) so QMK's keymap introspection sees key_combos.
//
// Every chord is two neighbouring base-layer keys that almost never occur together in German or
// English words. Shifted partners come from holding Shift while chording:
//   ; + Shift = :     Enter + Shift = Shift+Enter
//
//   Enter  ,  .   right ring+middle, bottom row
//   ;      Z  X   left pinky+ring, bottom row

enum mg_combos {
    MG_ENTER,
    MG_SCLN,
#ifdef MG_EXTRA_COMBOS
    MG_DASH,
    MG_ALFRED,
#endif
};

const uint16_t PROGMEM mg_enter_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM mg_scln_combo[]  = {Z_HYPR, KC_X, COMBO_END};
#ifdef MG_EXTRA_COMBOS
const uint16_t PROGMEM mg_dash_combo[]   = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM mg_alfred_combo[] = {S_ALT, D_CTL, COMBO_END};
#endif

combo_t key_combos[] = {
    [MG_ENTER] = COMBO(mg_enter_combo, KC_ENT),
    [MG_SCLN]  = COMBO(mg_scln_combo, KC_SCLN),
#ifdef MG_EXTRA_COMBOS
    [MG_DASH]   = COMBO(mg_dash_combo, KC_MINUS),
    [MG_ALFRED] = COMBO(mg_alfred_combo, A(KC_SPACE)),
#endif
};

#ifdef COMBO_MUST_TAP_PER_COMBO
// Chords containing a mod-tap fire on tap only, so holding Z still gives Hyper.
bool get_combo_must_tap(uint16_t combo_index, combo_t *combo) {
    uint16_t key;
    uint8_t  idx = 0;
    while ((key = pgm_read_word(&combo->keys[idx])) != COMBO_END) {
        switch (key) {
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
                return true;
        }
        idx += 1;
    }
    return false;
}
#endif
