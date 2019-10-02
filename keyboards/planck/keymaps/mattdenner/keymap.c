/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
	_MOVEMENT,
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

// Some custom keys
#define KC_UK_HASH ALGR(KC_3)

#define MOVEMENT MO(_MOVEMENT)

#define DESKTOP_LEFT       LCTL(KC_LEFT)
#define DESKTOP_RIGHT      LCTL(KC_RIGHT)
#define DESKTOP_FULL       LSFT(LCTL(RALT(KC_F)))
#define DESKTOP_TALL       LSFT(LCTL(RALT(KC_T)))
#define WINDOW_FOCUS_LEFT  LCTL(RALT(KC_J))
#define WINDOW_FOCUS_RIGHT LCTL(RALT(KC_K))
#define WINDOW_MOVE_LEFT   LSFT(LCTL(RALT(KC_J)))
#define WINDOW_MOVE_RIGHT  LSFT(LCTL(RALT(KC_K)))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_ESC,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
    MOVEMENT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_UK_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    _______, _______, _______, _______,    _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Movement
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      | TALL |MOVEL |FOCUSL|FOCUSR|MOVER |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | FULL |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | BTN1 | LEFT | DOWN | UP   |RIGHT | BTN2 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |LEFTD |      |      |RIGHTD|
 * `-----------------------------------------------------------------------------------'
 */
[_MOVEMENT] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______,      DESKTOP_TALL, WINDOW_MOVE_LEFT, WINDOW_FOCUS_LEFT, WINDOW_FOCUS_RIGHT, WINDOW_MOVE_RIGHT, _______,    _______,
    _______, _______, _______, _______, DESKTOP_FULL, _______,      _______,          _______,           _______,            _______,           _______,    _______,
    _______, _______, _______, _______, _______,      KC_MS_BTN1,   KC_MS_LEFT,       KC_MS_DOWN,        KC_MS_UP,           KC_MS_RIGHT,       KC_MS_BTN2, _______,
    _______, _______, _______, _______, _______,      _______,      _______,          _______,           DESKTOP_LEFT,       KC_NO,             KC_NO,    DESKTOP_RIGHT
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, _______,  _______, _______, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

#define ___         {0x00,0x00,0x00}
#define RGB_LOWER   {0x88,0x00,0x00}
#define RGB_RAISE   {0x00,0x88,0x00}
#define RGB_MOVE    {0x00,0x00,0x88}

#define RGB_WINDOW  {0x00,0x00,0x88}
#define RGB_MOUSE   {0x88,0x88,0x00}

const uint8_t PROGMEM keymaps_colors[][DRIVER_LED_TOTAL][3] = {
	[_QWERTY] = {
		___,      ___, ___, ___, ___,       ___, ___, ___,       ___, ___, ___, ___,
		___,      ___, ___, ___, ___,       ___, ___, ___,       ___, ___, ___, ___,
		___,      ___, ___, ___, ___,       ___, ___, ___,       ___, ___, ___, ___,
		RGB_MOVE, ___, ___, ___, RGB_LOWER,    ___,   RGB_RAISE, ___, ___, ___, ___ 
	},
	[_LOWER] = {
		___, ___, ___, ___, ___,       ___, ___, ___, ___, ___, ___, ___,
		___, ___, ___, ___, ___,       ___, ___, ___, ___, ___, ___, ___,
		___, ___, ___, ___, ___,       ___, ___, ___, ___, ___, ___, ___,
		___, ___, ___, ___, RGB_LOWER,    ___,   ___, ___, ___, ___, ___ 
	},
	[_RAISE] = {
		___, ___, ___, ___, ___, ___, ___, ___,       ___, ___, ___, ___,
		___, ___, ___, ___, ___, ___, ___, ___,       ___, ___, ___, ___,
		___, ___, ___, ___, ___, ___, ___, ___,       ___, ___, ___, ___,
		___, ___, ___, ___, ___,    ___,   RGB_RAISE, ___, ___, ___, ___ 
	},
	[_ADJUST] = {
		___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
		___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
		___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
		___, ___, ___, ___, ___,    ___,   ___, ___, ___, ___, ___ 
	},
	[_MOVEMENT] = {
		___,      ___, ___, ___, ___,        RGB_WINDOW, RGB_WINDOW, RGB_WINDOW, RGB_WINDOW, RGB_WINDOW, ___,       ___,
		___,      ___, ___, ___, RGB_WINDOW, ___,        ___,        ___,        ___,        ___,        ___,       ___,
		___,      ___, ___, ___, ___,        RGB_MOUSE,  RGB_MOUSE,  RGB_MOUSE,  RGB_MOUSE,  RGB_MOUSE,  RGB_MOUSE, ___,
		RGB_MOVE, ___, ___, ___, ___,    ___,                        ___,        RGB_WINDOW, ___,        ___,       RGB_WINDOW 
	},
};

// Called during the firmware startup: hardware initialized, but features may not be yet.
void matrix_init_user() {
	rgblight_mode(1);
	rgblight_sethsv(0,0,0);
}

void rgb_matrix_indicators_user(void) {
#ifdef RGB_MATRIX_ENABLE
	int active_layer = biton32(layer_state);
	if ((active_layer < _QWERTY) || (active_layer > _MOVEMENT)) {
		return;
	}

	for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
		const uint8_t *color = keymaps_colors[active_layer][i];
		rgb_matrix_set_color(i, color[0], color[1], color[2]);
	}
#endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
		default:
			return true;
			break;
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
