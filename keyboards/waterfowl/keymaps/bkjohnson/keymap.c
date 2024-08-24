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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _NAV,
    _MOUSE,
    _MEDIA,
    _BUTTON,
    _NUM,
    _SYM,
    _FUNC,
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
	KC_NO,				LT(3,KC_ESC),		LT(1,KC_SPC),		LT(2, KC_TAB),		KC_NO,  		KC_NUM,	LT(6, KC_ENT),		LT(5, KC_BSPC),		LT(7,KC_DEL),		KC_NO
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
	KC_NO,      KC_NO,		KC_NO,		KC_NO,	    KC_NO,		C(KC_Y),C(KC_V),C(KC_C),C(KC_X),	C(KC_Z),
	KC_LGUI,	KC_LALT,	KC_LCTL,	KC_LSFT,	KC_NO,		CW_TOGG,KC_LEFT,KC_DOWN,KC_UP,		KC_RIGHT,
	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_INS,	KC_HOME,KC_PGUP,KC_PGDN,	KC_END,
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
	KC_NO,      KC_NO,		KC_NO,		KC_NO,	    KC_NO,		KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
	KC_LGUI,	KC_LALT,	KC_LCTL,	KC_LSFT,	KC_NO,		KC_NO,		KC_MS_LEFT, KC_MS_DOWN,	KC_MS_UP,	KC_MS_RIGHT,
	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_WH_L,	KC_WH_D,	KC_WH_U,	KC_WH_R,
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
 	KC_NO,      KC_NO,		KC_NO,		KC_NO,	    KC_NO,		RGB_TOG,	RGB_MOD,	RGB_HUI,	RGB_SAI,	RGB_VAI,
 	KC_LGUI,	KC_LALT,	KC_LCTL,	KC_LSFT,	KC_NO,		KC_NO,		KC_MPRV,    KC_VOLD,	KC_VOLU,	KC_MNXT,
 	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,	    KC_NO,		KC_NO,		KC_NO,
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
 	KC_LBRC,	KC_7,	KC_8,	KC_9,	    KC_RBRC,		KC_NO,	    KC_NO,	    KC_NO,		KC_NO,		KC_NO,
 	KC_SCLN,	KC_4,	KC_5,	KC_6,	    KC_EQUAL,		KC_NO,		KC_RSFT,    KC_RCTL,	KC_RALT,	KC_RGUI,
 	KC_GRAVE,	KC_1,	KC_2,	KC_3,		KC_BSLS,		KC_NO,		KC_NO,	    KC_NO,		KC_NO,		KC_NO,
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
 	KC_LCBR,	KC_AMPR,	KC_ASTR,	KC_LPRN,	KC_RCBR,	KC_NO,	    KC_NO,	    KC_NO,		KC_NO,		KC_NO,
 	KC_COLN,	KC_DLR,	    KC_PERC,	KC_CIRC,	KC_PLUS,	KC_NO,		KC_RSFT,    KC_RCTL,	KC_RALT,	KC_RGUI,
 	KC_TILD,	KC_EXLM,	KC_AT,		KC_HASH,	KC_PIPE,	KC_NO,		KC_NO,	    KC_NO,		KC_NO,		KC_NO,
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
 	KC_F12,		KC_F7,		KC_F8,		KC_F9,	    KC_PSCR,	KC_NO,	    KC_NO,	    KC_NO,		KC_NO,		KC_NO,
 	KC_F11,	    KC_F4,	    KC_F5,	    KC_F6,	    KC_SCRL,	KC_NO,		KC_RSFT,    KC_RCTL,	KC_RALT,	KC_RGUI,
 	KC_F10,		KC_F1,		KC_F2,		KC_F3,		KC_PAUS,	KC_NO,		KC_NO,	    KC_NO,		KC_NO,		KC_NO,
 	KC_NO,		KC_APP,     KC_SPC,     KC_TAB,		KC_NO,	    KC_NO,		KC_NO,	    KC_NO,	    KC_NO,      KC_NO
 ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [1] = { ENCODER_CCW_CW(UG_HUED, UG_HUEU),           ENCODER_CCW_CW(UG_SATD, UG_SATU)  },
    [2] = { ENCODER_CCW_CW(UG_VALD, UG_VALU),           ENCODER_CCW_CW(UG_SPDD, UG_SPDU)  },
    [3] = { ENCODER_CCW_CW(UG_PREV, UG_NEXT),           ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
    [4] = { ENCODER_CCW_CW(UG_PREV, UG_NEXT),           ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
    [5] = { ENCODER_CCW_CW(UG_PREV, UG_NEXT),           ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
    [6] = { ENCODER_CCW_CW(UG_PREV, UG_NEXT),           ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
    [7] = { ENCODER_CCW_CW(UG_PREV, UG_NEXT),           ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
};
#endif
