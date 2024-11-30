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

#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

bool is_mac(void);
void mgallecom_set_win_mode(void);
void mgallecom_set_mac_mode(void);
bool mgallecom_process_record_user(uint16_t keycode, keyrecord_t *record);


enum layer_names {
  _BASE,
  _NAV,
  _SYM,
  _FUN,
  _NUM,
  _MED

};

enum custom_keycodes {
  MG_WIN = SAFE_RANGE, // macOS take screenshot to the clip board
  MG_SCAP,   // cross platform screen cap
  WLEFT,     // navigate one word left
  WRIGHT,    // navigate one word right
  WBSPC,     // backsepace one word
  WDEL,      // delete word to the right
  SELWORD,
};

// Tap Dance declarations
enum {
    TD_ALFRED_PASTE,
    TD_CURLIES,
    TD_BRACKS,
    TD_BRACKS_NORMAL
};


/* Aliases */
#define HOLD XXXXXXX //:(hold)
#define XXXXXXX KC_NO

/** Layer Keys **/
#define BS_NUM LT(_NUM, KC_BSPC) //:BS/NUM
#define ESC_MED LT(_MED, KC_ESC) //:Esc/MED
#define ENT_SYM LT(_SYM, KC_ENT) //:Ent/SYM
#define SPC_NAV LT(_NAV, KC_SPC) //:Spc/NAV
#define DEL_FUN LT(_FUN, KC_DEL) //:Del/FUN

/** Mod Tap Aliases **/
/*** Home Row Mods ***/
#define A_WIN LGUI_T(KC_A) //:A/WIN
#define S_ALT LALT_T(KC_S) //:S/Alt
#define D_CTL LCTL_T(KC_D) //:D/CTL
#define F_SFT LSFT_T(KC_F) //:F/Sft
#define J_SFT RSFT_T(KC_J) //:J/Sft
#define K_CTL RCTL_T(KC_K) //:K/CTL
#define L_ALT RALT_T(KC_L) //:L/Alt
#define SCLN_WIN RGUI_T(KC_QUOTE) //:;_:/WIN
#define HRM_L KC_LGUI, KC_LALT,KC_LCTL, KC_LSFT //:WIN||Opt||Ctl||Sft
#define HRM_R KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI  //:Sft||Ctl||Opt||WIN

/*** Others ***/
#define ENT_SFT RSFT_T(KC_ENT) //:Ent/Sft
#define SLS_HYPR HYPR_T(KC_SLSH) //:/_?/Hypr
#define Z_HYPR HYPR_T(KC_Z) //:Z/Hypr
#define B_MEH MEH_T(KC_B) //:B/Meh
#define N_MEH MEH_T(KC_N) //:N/Meh

/*** Thumb keys ***/
#define DEL_CTL LCTL_T(KC_DEL) //:Del/Cmd
#define SPC_MEH MEH_T(KC_SPC)

/*** Shortcuts Win***/
#define CUT LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PASTE TD(TD_ALFRED_PASTE)
#define SAVE LCTL(KC_S)
#define UNDO LCTL(KC_Z)
#define SAVE LCTL(KC_S)
#define CLIPBOARD_L SAVE, PASTE, COPY, CUT, UNDO //:Save||Cut||Copy||Paste||Undo
#define CLIPBOARD_R UNDO, CUT, COPY, PASTE, SAVE //:Save||Cut||Copy||Paste||Undo

#ifdef TAP_DANCE_ENABLE
// Tap Dances

#endif // TAP_DANCE_ENABLE

/* portable keymaps */
/** 10u **/

/*** base Win ***/
                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │  Q     │  W     │  E     │  R     │  T     │ */
#define ___5BASE_1_L___     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  A/Ctl │  S/Alt │  D/Cmd │  F/Sft │  G     │ */
#define ___5BASE_2_L___     A_WIN,   S_ALT,   D_CTL,   F_SFT,   KC_G
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │ Z/Hypr │  X     │  C     │  V     │  B/Meh │ */
#define ___5BASE_3_L___     Z_HYPR,   KC_X,    KC_C,    KC_V,   B_MEH
                        /* ╰────────┴────────┼────────┼────────┼────────┤ */
                        /*                   │ Tab/FUN│ BS/NUM │ Esc/MSE│ */
#define ___BASE_THUMB_L___                    ESC_MED, SPC_NAV,  KC_TAB
                        /*                   ╰────────┴────────┴────────╯ */

                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │  Y     │  U     │  I     │  O     │  P     │ */
#define ___5BASE_1_R___     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  H     │  J/Sft │  K/Cmd │  L/Alt │ ; :/Ctl│ */
#define ___5BASE_2_R___     KC_H,    J_SFT,   K_CTL,   L_ALT,   SCLN_WIN
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  N/Meh │  M     │  , <   │  . >   │/ ?/Hypr│ */
#define ___5BASE_3_R___     N_MEH,   KC_M,    KC_COMM, KC_DOT,  SLS_HYPR
                        /* ├────────┼────────┼────────┼────────┴────────╯ */
                        /* │Ent/MSE │Spc/NAV │ Del/MED│ */
#define ___BASE_THUMB_R___  ENT_SYM, BS_NUM, DEL_FUN
                        /* ╰────────┴────────┴────────╯ */

/*** number ***/
                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │    =   │    7   │    8   │  9     │    *   │ */
#define ___5NUM_1_L___      KC_EQL,  KC_7,   KC_8,    KC_9,  KC_PAST
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │    :   │    4   │    5   │    6   │   -    │ */
#define ___5NUM_2_L___      KC_COLN,  KC_4,   KC_5,    KC_6,  KC_PMNS
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  /     │    1   │    2   │    3   │   +    │ */
#define ___5NUM_3_L___      KC_SLSH,   KC_1,   KC_2,    KC_3,  KC_PPLS
                        /* ╰────────┴────────┼────────┼────────┼────────┤ */
                        /*                   │  Del   │ (hold) │  BS    │ */
#define ___NUM_THUMB_L___                     KC_DOT,  KC_0,  KC_COMM
                        /*                   ╰────────┴────────┴────────╯ */

                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │  ---   │  ---   │  ---   │  ---   │  BSP   │ */
#define ___5NUM_1_R___      KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_BSPC
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  = +   │  4     │  5     │  6     │  ' "   │ */
                            // TODO maybe try moving the quote hold to a different key?
#define ___5NUM_2_R___     XXXXXXX,                             HRM_R
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  \ |   │  1     │  2     │  3     │  ` ~   │ */
#define ___5NUM_3_R___      HOLD,      HOLD,    HOLD,   KC_ALGR, HOLD
                        /* ├────────┼────────┼────────┼────────┴────────╯ */
                        /* │  - _   │  0     │  .     │ */
#define ___NUM_THUMB_R___    HOLD,      HOLD,    HOLD
                        /* ╰────────┴────────┴────────╯ */

/*** symbol ***/
                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │  ---   │  ---   │  ---   │  ---   │  ---   │ */
#define ___5SYM_1_L___      KC_PIPE,  KC_AMPR,  KC_ASTR,  KC_BSLS,  TD(TD_BRACKS)
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │ Med <==│ Vol Dn │ Vol Up │ Med==> │RGB Spd+│ */
#define ___5SYM_2_L___      KC_COLN,  KC_DLR,   KC_PERC,  KC_CIRC,  TD(TD_BRACKS_NORMAL)
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │ RGB tog│RGB mod+│RGB hue+│RGB sat+│RGB brt+│ */
#define ___5SYM_3_L___      KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  TD(TD_CURLIES)
                        /* ╰────────┴────────┼────────┼────────┼────────┤ */
                        /*                   │  Mute  │Ply/Paus│  Stop  │ */
#define ___SYM_THUMB_L___                     KC_SCLN,  KC_PMNS,  KC_UNDS
                        /*                   ╰────────┴────────┴────────╯ */

                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │  {     │  &     │  *     │  )     │  }     │ */
#define ___5SYM_1_R___      KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_BSPC
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  +     │  $     │  %     │  ^     │  "     │ */
#define ___5SYM_2_R___     XXXXXXX,     HRM_R
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  |     │  !     │  @     │  #     │  ~     │ */
#define ___5SYM_3_R___      HOLD,      HOLD,    HOLD,   KC_ALGR, HOLD
                        /* ├────────┼────────┼────────┼────────┴────────╯ */
                        /* │  _     │  (     │ (hold) │ */
#define ___SYM_THUMB_R___   KC_UNDS, KC_PMNS, HOLD
                        /* ╰────────┴────────┴────────╯ */

/*** navigation ***/
                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │ Tab Lft│  Back  │ Forward│Tab Rght│  ../   │ */
#define ___5NAV_1_L___      CLIPBOARD_L
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  Ctl   │  Alt   │  Cmd   │  Shft  │  ---   │ */
#define ___5NAV_2_L___      HRM_L,                        XXXXXXX
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  ---   │  ---   │  ---   │  ---   │  ---   │ */
#define ___5NAV_3_L___      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                        /* ╰────────┴────────┼────────┼────────┼────────┤ */
                        /*                   │ Del/Cmd│  Bs    │  Ent   │ */
#define ___NAV_THUMB_L___                     HOLD,      HOLD,    HOLD
                        /*                   ╰────────┴────────┴────────╯ */

                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │  Redo  │  Paste │  Copy  │  Cut   │  Undo  │ */
#define ___5NAV_1_R___      XXXXXXX,  WLEFT,   XXXXXXX, XXXXXXX, WRIGHT
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  Left  │  Down  │  Up    │  Right │  Caps  │ */
#define ___5NAV_2_R___      KC_CAPS,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  Home  │  PgDn  │  PgUp  │  End   │ Ent    │ */
#define ___5NAV_3_R___      KC_INS,   KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END
                        /* ├────────┼────────┼────────┼────────┴────────╯ */
                        /* │  ---   │ (hold) │  ---   │ */
#define ___NAV_THUMB_R___   KC_ENT,   KC_BSPC,  KC_DEL
                        /* ╰────────┴────────┴────────╯ */

/*** function ***/
                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │ Log Out│  ---   │Scrn2Clp│ Scrn2Fl│  ---   │ */
#define ___5FUN_1_L___      KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  Ctl   │  Alt   │  Cmd   │  Shft  │ScrnBrt+│ */
#define ___5FUN_2_L___      KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_NO
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  ---   │  ---   │  ---   │  ---   │ScrnBrt-│ */
#define ___5FUN_3_L___      KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS
                        /* ╰────────┴────────┼────────┼────────┼────────┤ */
                        /*                   │ (hold) │  MSE   │  Tab   │ */
#define ___FUN_THUMB_L___                     KC_APP,  KC_SPC,  KC_TAB
                        /*                   ╰────────┴────────┴────────╯ */

                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │  ---   │  F7    │  F8    │  F9    │  F12   │ */
#define ___5FUN_1_R___       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  ---   │  F4    │  F5    │  F6    │  F11   │ */
#define ___5FUN_2_R___      XXXXXXX, HRM_R
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  ---   │  F1    │  F2    │  F3    │  F10   │ */
#define ___5FUN_3_R___      XXXXXXX, XXXXXXX, XXXXXXX, KC_ALGR, XXXXXXX
                        /* ├────────┼────────┼────────┼────────┴────────╯ */
                        /* │  ---   │  ADD   │  ---   │ */
#define ___FUN_THUMB_R___  XXXXXXX, XXXXXXX, XXXXXXX
                        /* ╰────────┴────────┴────────╯ */

/*** mouse ***/
                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │  Undo  │  Cut   │  Copy  │  Paste │  Redo  │ */
#define ___5MED_1_L___     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │Button 5│Button 3│Button 1│Button 2│ Wheel D│ */
#define ___5MED_2_L___      HRM_L,                              XXXXXXX // KC_WH_D
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │  Esc   │  Ctl   │  Alt   │  Cmd   │ Shft   │ */
#define ___5MED_3_L___      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX // TODO how much am I using wheel up/down? If I shifted HRM over to the right, I could put Esc on Z like the default layer
                        /* ╰────────┴────────┼────────┼────────┼────────┤ */
                        /*                   │  ---   │ (hold) │ (hold) │ */
#define ___MED_THUMB_L___                     XXXXXXX, HOLD, HOLD
                        /*                   ╰────────┴────────┴────────╯ */

                        /* ╭────────┬────────┬────────┬────────┬────────╮ */
                        /* │  ---   │MEDSpd 0│MEDSpd 1│MEDSpd 2│  ---   │ */
#define ___5MED_1_R___      RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_SAI,  RGB_VAI
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │ Mouse L│ Mouse D│ Mouse U│ Mouse R│  ---   │ */
#define ___5MED_2_R___      XXXXXXX, KC_MPRV,  KC_VOLD,  KC_VOLU,  KC_MNXT
                        /* ├────────┼────────┼────────┼────────┼────────┤ */
                        /* │ Wheel L│ Wheel U│ Wheel D│ Wheel R│  ---   │ */
// wheel up/down are swapped intentionally so the actual directions are synced
// relative to "natural scrolling"
#define ___5MED_3_R___      XXXXXXX, XXXXXXX, KC_BRMD,    KC_BRMU, XXXXXXX
                        /* ├────────┼────────┼────────┼────────┴────────╯ */
                        /* │ (hold) │ (hold) │  ---   │ */
#define ___MED_THUMB_R___   KC_MSTP,  KC_MPLY,  KC_MUTE
                        /* ╰────────┴────────┴────────╯ */
#define LAYOUT_mgallecom_planck_mit(...)  LAYOUT_planck_mit(__VA_ARGS__)
#endif
