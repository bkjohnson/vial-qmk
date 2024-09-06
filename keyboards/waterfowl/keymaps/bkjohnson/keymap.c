/* Copyright 2022  CyanDuck
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
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
#include "features/layer_lock.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _EXTRA,
    _NAV,
    _MOUSE,
    _MEDIA,
    _BUTTON,
    _NUM,
    _SYM,
    _FUNC,
};

enum custom_keycodes {
  LLOCK = QK_KB_0,
  MACRO_SETUP_EDITOR,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |   Q  |   W  |   F  |   P  |   B  |                      |   J  |   L  |   U  |   Y  |   '  |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |   A  |   R  |   S  |   T  |   G  |                      |   M  |   N  |   E  |   I  |   O  |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |   Z  |   X  |   C  |   D  |   V  |  |     |    |     |  |   K  |   H  |   ,  |   .  |   /  |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
 *          |     |   | ESC | SPACE | TAB  |            |  ENTER  | BS | DEL |   |     |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_BASE] = LAYOUT(
	KC_Q,				KC_W,				KC_F,				KC_P,				KC_B,			KC_J,	KC_L,				KC_U,				KC_Y,				KC_QUOT,
	MT(MOD_LGUI, KC_A),	MT(MOD_LALT, KC_R),	MT(MOD_LCTL, KC_S),	MT(MOD_LSFT, KC_T),	KC_G,			KC_M,	MT(MOD_LSFT, KC_N),	MT(MOD_LCTL, KC_E),	MT(MOD_LALT, KC_I),	MT(MOD_LGUI, KC_O),
	KC_Z,				KC_X,				KC_C,				KC_D,				KC_V,			KC_K,	KC_H,				KC_COMM,			KC_DOT,				KC_SLSH,
	KC_NO,				LT(_MEDIA, KC_ESC),	LT(_NAV, KC_SPC),	LT(_MOUSE, KC_TAB),	KC_NO,  		KC_NUM,	LT(_SYM, KC_ENT),	LT(_NUM, KC_BSPC),	LT(_FUNC, KC_DEL),	KC_NO
),

/* EXTRA
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |                      |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |                      |   H  |   J  |   K  |   L  |   '  |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |  |     |    |     |  |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
 *          |     |   | ESC | SPACE | TAB  |            |  ENTER  | BS | DEL |   |     |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_EXTRA] = LAYOUT(
	KC_Q,				KC_W,				KC_E,				KC_R,				KC_T,			KC_Y,	KC_U,				KC_I,				KC_O,				KC_P,
	MT(MOD_LGUI, KC_A),	MT(MOD_LALT, KC_S),	MT(MOD_LCTL, KC_D),	MT(MOD_LSFT, KC_F),	KC_G,			KC_H,	MT(MOD_LSFT, KC_J),	MT(MOD_LCTL, KC_K),	MT(MOD_LALT, KC_L),	MT(MOD_LGUI, KC_QUOT),
	KC_Z,				KC_X,				KC_C,				KC_V,				KC_B,			KC_N,	KC_M,				KC_COMM,			KC_DOT,				KC_SLSH,
	KC_NO,				LT(_MEDIA, KC_ESC),	LT(_NAV, KC_SPC),	LT(_MOUSE, KC_TAB),	KC_NO,  		KC_NUM,	LT(_SYM, KC_ENT),	LT(_NUM, KC_BSPC),	LT(_FUNC, KC_DEL),	KC_NO
),



/* NAV
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |      |      |      |      |      |                      | REDO | PASTE| COPY | CUT  | UNDO |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * | SUPR | ALT  | CTRL | SHIFT|      |                      | CAPS | LEFT | DOWN |  UP  | RIGHT|
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |      |      |      |      |      |  |     |    |     |  |INSERT| HOME | PGUP | PGDN | END  |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
 *          |     |   |     | XXXXX |      |            |  ENTER  | BS | DEL |   |     |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_NAV] = LAYOUT(
	QK_BOOT,    KC_NO,		TD(2),		TD(3),	    KC_NO,		C(KC_Y),C(KC_V),C(KC_C),C(KC_X),	C(KC_Z),
	KC_LGUI,	KC_LALT,	KC_LCTL,	KC_LSFT,	KC_NO,		CW_TOGG,KC_LEFT,KC_DOWN,KC_UP,		KC_RIGHT,
	KC_NO,		KC_NO,		KC_NO,		TD(1),	KC_NO,		KC_INS,	KC_HOME,KC_PGUP,KC_PGDN,	KC_END,
	KC_NO,		KC_NO,      KC_NO,      KC_NO,		KC_NO,	    KC_NO,	KC_ENT,	KC_BSPC,KC_DEL,     KC_NO
),

/* MOUSE
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |      |      |      |      |      |                      |      |      |      |      |      |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * | SUPR | ALT  | CTRL | SHIFT|      |                      |      | M <- | M v  |  M ^ | M -> |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |      |      |      |      |      |  |     |    |     |  |      | W <- | W v  |  W ^ |W ->  |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
 *          |     |   |     |       | XXXX |            | RIGHT | LEFT | MID |   |     |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_MOUSE] = LAYOUT(
	QK_BOOT,    KC_NO,		TD(2),		TD(3),	    KC_NO,		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
	KC_LGUI,	KC_LALT,	KC_LCTL,	KC_LSFT,	KC_NO,		KC_NO,		KC_MS_LEFT, KC_MS_DOWN,	KC_MS_UP,	KC_MS_RIGHT,
	KC_NO,		KC_NO,		KC_NO,		TD(1),	KC_NO,		KC_NO,		KC_WH_L,	KC_WH_D,	KC_WH_U,	KC_WH_R,
	KC_NO,		KC_NO,      KC_NO,      KC_NO,		KC_NO,	    KC_NO,		KC_MS_BTN2,	KC_MS_BTN1,	KC_MS_BTN3, KC_NO
),

/* BUTTON
 *
 * ,----------------------------------.                      ,----------------------------------.
 * | UNDO |  CUT | COPY | PASTE| REDO |                      | REDO | PASTE| COPY | CUT  | UNDO |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * | SUPR | ALT  | CTRL | SHIFT|      |                      |      |SHIFT | CTRL | ALT  | SUPR |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * | Reset|      |      |      |      |  |     |    |     |  | REDO | PASTE| COPY | CUT  | UNDO |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
 *          |     |   | MID | LEFT | RIGHT |            | RIGHT | LEFT | MID |   |     |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_BUTTON] =  LAYOUT(
	C(KC_Z),C(KC_X),	C(KC_C),	C(KC_V),    C(KC_Y),	C(KC_Y),C(KC_V),    C(KC_C),    C(KC_X),    C(KC_Z),
	KC_LGUI,KC_LALT,	KC_LCTL,	KC_LSFT,    KC_NO,		KC_NO,	KC_RSFT,    KC_RCTL,	KC_RALT,	KC_RGUI,
	C(KC_Z),C(KC_X),	C(KC_C),	C(KC_V),    C(KC_Y),    C(KC_Y),C(KC_V),    C(KC_C),    C(KC_X),    C(KC_Z),
	KC_NO,  KC_MS_BTN3,	KC_MS_BTN1,	KC_MS_BTN2, KC_NO,	    KC_NO,	KC_MS_BTN2,	KC_MS_BTN1,	KC_MS_BTN3, KC_NO
),

 /* MEDIA
  *
  * ,----------------------------------.                      ,----------------------------------.
  * |      |      |      |      |      |                      | RGB T| RGB M| RGB H| RGB S| RGB V|
  * |------+------+------+------+------|                      |------+------+------+------+------|
  * | SUPR | ALT  | CTRL | SHIFT|      |                      |      | PREV | VOL v| VOL ^| NEXT |
  * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
  * |      |      |      |      |      |  |     |    |     |  |      |      |      |      |      |
  * `----------------------------------'  `-----'    `-----'  `----------------------------------'
  *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
  *          |     |   |  XXX |      |      |            | STOP | PLAY | MUTE |   |     |
  *          `-----'   `--------------------'            `--------------------'   `-----'
  */
 [_MEDIA] = LAYOUT(
 	QK_BOOT,    KC_NO,		TD(2),		TD(3),	    KC_NO,		RGB_TOG,	RGB_MOD,	RGB_HUI,	RGB_SAI,	RGB_VAI,
 	KC_LGUI,	KC_LALT,	KC_LCTL,	KC_LSFT,	KC_NO,		KC_NO,		KC_MPRV,    KC_VOLD,	KC_VOLU,	KC_MNXT,
 	KC_NO,		KC_NO,		KC_NO,		TD(1),	KC_NO,		KC_NO,		KC_NO,	    KC_NO,		KC_NO,		KC_NO,
 	KC_NO,		KC_NO,      KC_NO,      KC_NO,		KC_NO,	    KC_NO,		KC_MSTP,	KC_MPLY,	KC_MUTE,    KC_NO
 ),

 /* NUM
  *
  * ,----------------------------------.                      ,----------------------------------.
  * |  [   |   7  |  8   |   9  |   ]  |                      |      |      |      |      |      |
  * |------+------+------+------+------|                      |------+------+------+------+------|
  * |   ;  |   4  |  5   |   6  |   =  |                      |      |SHIFT | CTRL | ALT  | SUPR |
  * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
  * |  `   |   1  |  2   |   3  |   \  |  |     |    |     |  |      |      |      |      |      |
  * `----------------------------------'  `-----'    `-----'  `----------------------------------'
  *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
  *          |     |   |  .  |   0   |   -  |            |       | XXXX |     |   |     |
  *          `-----'   `--------------------'            `--------------------'   `-----'
  */
 [_NUM] = LAYOUT(
 	KC_LBRC,	KC_7,	KC_8,	KC_9,	    KC_RBRC,		KC_NO,	    TD(3),	    TD(2),		KC_NO,		QK_BOOT,
 	KC_SCLN,	KC_4,	KC_5,	KC_6,	    KC_EQUAL,		KC_NO,		KC_RSFT,    KC_RCTL,	KC_RALT,	KC_RGUI,
 	KC_GRAVE,	KC_1,	KC_2,	KC_3,		KC_BSLS,		KC_NO,		TD(1),	KC_NO,		KC_NO,		KC_NO,
 	KC_NO,		KC_DOT, KC_0,   KC_MINUS,	KC_NO,	        KC_NO,		KC_NO,	    KC_NO,	    KC_NO,      KC_NO
 ),

 /* SYM
  *
  * ,----------------------------------.                      ,----------------------------------.
  * |   {  |  &   |  *   |  (   |  }   |                      |      |      |      |      |      |
  * |------+------+------+------+------|                      |------+------+------+------+------|
  * |  :   |  $   |  %   |  ^   |  +   |                      |      | SHIFT| CTRL | ALT  | SUPR |
  * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
  * |  ~   |  !   |  @   |  #   |  |   |  |     |    |     |  |      |      |      |      |      |
  * `----------------------------------'  `-----'    `-----'  `----------------------------------'
  *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
  *          |     |   |  (  |  )    |  _   |            |  XXX  |     |      |   |     |
  *          `-----'   `--------------------'            `--------------------'   `-----'
  */
 [_SYM] = LAYOUT(
 	KC_LCBR,	KC_AMPR,	KC_ASTR,	KC_LPRN,	KC_RCBR,	KC_NO,	    TD(3),	    TD(2),		KC_NO,		QK_BOOT,
 	KC_COLN,	KC_DLR,	    KC_PERC,	KC_CIRC,	KC_PLUS,	KC_NO,		KC_RSFT,    KC_RCTL,	KC_RALT,	KC_RGUI,
 	KC_TILD,	KC_EXLM,	KC_AT,		KC_HASH,	KC_PIPE,	KC_NO,		TD(1),	KC_NO,		KC_NO,		KC_NO,
 	KC_NO,      KC_LPRN,    KC_RPRN,    KC_UNDS,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO
 ),

 /* FUNC
  *
  * ,----------------------------------.                      ,----------------------------------.
  * | F12  |  F7  |  F8  |  F9  | PRNT |                      |      |      |      |      |   -  |
  * |------+------+------+------+------|                      |------+------+------+------+------|
  * | F11  |  F4  |  F5  |  F6  |SCRLLK|                      |      | SHIFT| CTRL | ALT  | SUPR |
  * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
  * | F10  |  F1  |  F2  |  F3  | PAUSE|  |     |    |     |  |      |      |      |      |      |
  * `----------------------------------'  `-----'    `-----'  `----------------------------------'
  *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
  *          |     |   | APP | SPACE | TAB  |            |       |      | XXX |   |     |
  *          `-----'   `--------------------'            `--------------------'   `-----'
  */
 [_FUNC] = LAYOUT(
 	KC_F12,		KC_F7,		KC_F8,		KC_F9,	    KC_PSCR,	KC_NO,	    TD(3),	    TD(2),		KC_NO,		QK_BOOT,
 	KC_F11,	    KC_F4,	    KC_F5,	    KC_F6,	    KC_SCRL,	KC_NO,		KC_RSFT,    KC_RCTL,	KC_RALT,	KC_RGUI,
 	KC_F10,		KC_F1,		KC_F2,		KC_F3,		KC_PAUS,	KC_NO,		TD(1),	KC_NO,		KC_NO,		KC_NO,
 	KC_NO,		KC_APP,     KC_SPC,     KC_TAB,		KC_NO,	    KC_NO,		KC_NO,	    KC_NO,	    KC_NO,      KC_NO
 ),
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_layer_lock(keycode, record, LLOCK)) { return false; }
  // Your macros ...
  switch (keycode) {
    case MACRO_SETUP_EDITOR:
      if (record->event.pressed) {
        SEND_STRING("nvim .\n");
        SEND_STRING(":Lazy\n");
        SEND_STRING(":source Session.vim");
      }
      break;
  }

  return true;
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_NAV] =    { ENCODER_CCW_CW(UG_HUED, UG_HUEU),           ENCODER_CCW_CW(UG_SATD, UG_SATU)  },
    [_MOUSE] =  { ENCODER_CCW_CW(UG_VALD, UG_VALU),           ENCODER_CCW_CW(UG_SPDD, UG_SPDU)  },
    [_BUTTON] = { ENCODER_CCW_CW(UG_PREV, UG_NEXT),           ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
    [_MEDIA] =  { ENCODER_CCW_CW(UG_PREV, UG_NEXT),           ENCODER_CCW_CW(KC_RIGHT, KC_LEFT),    ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_NUM] =    { ENCODER_CCW_CW(UG_PREV, UG_NEXT),           ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
    [_SYM] =    { ENCODER_CCW_CW(UG_PREV, UG_NEXT),           ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
    [_FUNC] =   { ENCODER_CCW_CW(UG_PREV, UG_NEXT),           ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
};
#endif
