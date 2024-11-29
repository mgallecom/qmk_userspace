/*
Copyright 2024 Manuel Galle

Derived from the default lily58 keymap, which has no copyright header
and no license or author information.

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

// is_mac() - returns true if keeb is configure for mac use
//
// if ctl and gui are swapped, mac, else windows
// magic is already storing this in the EEPROM
//
bool is_mac(void) {
  return keymap_config.swap_lctl_lgui;
}

// sets up the keeb to talk to windows
//   unicode mode => wincompose
//   don't swap ctl and gui (dizave keebs default to GACS home row mods
//
void mgallecom_set_win_mode(void) {

  // toggle ctrl and gui
  keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = false;

  // toggle unicode mode
  set_unicode_input_mode(UNICODE_MODE_WINCOMPOSE);

}

void mgallecom_set_mac_mode(void) {
  keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = true;
  set_unicode_input_mode(UNICODE_MODE_MACOS);
 }

bool mgalle_process_record_user(uint16_t keycode, keyrecord_t *record)
{
  switch(keycode) {

    case MG_WIN:
      if (record->event.pressed) {
        if (is_mac()) {
            mgallecom_set_win_mode();
        } else {
            mgallecom_set_mac_mode();
        }
        // save mode into eeprom
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;


    // mac - command shift 4
    // win - gui shift S
    case MG_SCAP:
      if (is_mac()) {
        SEND_STRING(SS_LGUI("$"));
      } else {
        SEND_STRING(SS_LSFT(SS_LGUI("s")));
      }
      return false;

      case WLEFT:
      if (record->event.pressed) {
        if (is_mac()) {
          SEND_STRING(SS_LALT(SS_TAP(X_LEFT)));
        } else {
          SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)));
        }
      }
      return false;

      case WRIGHT:
      if (record->event.pressed) {
        if (is_mac()) {
          SEND_STRING(SS_LALT(SS_TAP(X_RIGHT)));
        } else {
          SEND_STRING(SS_LCTL(SS_TAP(X_RIGHT)));
        }
      }
      return false;

      case WBSPC:
      if (record->event.pressed) {
        if (is_mac()) {
          SEND_STRING(SS_LALT(SS_TAP(X_BSPC)));
        } else {
          SEND_STRING(SS_LCTL(SS_TAP(X_BSPC)));
        }
      }
      return false;

      case WDEL:
      if (record->event.pressed) {
        if (is_mac()) {
          SEND_STRING(SS_LGUI(SS_TAP(X_DEL)));
        } else {
          SEND_STRING(SS_LCTL(SS_TAP(X_DEL)));
        }
      }
      return false;

  }  // switch


  return true;
}
