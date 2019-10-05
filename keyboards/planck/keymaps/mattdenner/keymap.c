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
	_SYMBOLS_MOST,
	_SYMBOLS_LEAST,
  _ADJUST,
	_MOVEMENT,
	_MOUSE,

};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,

	TMUX_CREATE,
	TMUX_SPLIT,
	TMUX_VSPLIT,
	TMUX_MOVE,
	TMUX_RENAME,

	TMUX_LEFT,
	TMUX_RIGHT,
	TMUX_UP,
	TMUX_DOWN,
	TMUX_1,
	TMUX_2,
	TMUX_3,
	TMUX_4,
};


// Some custom keys
#define KC_UK_HASH ALGR(KC_3)

#define LAYER_SYMBOLS_LEAST MO(_SYMBOLS_LEAST)
#define LAYER_SYMBOLS_MOST  MO(_SYMBOLS_MOST)
#define LAYER_MOVEMENT      TG(_MOVEMENT)
#define LAYER_MOUSE         TG(_MOUSE)

#define DESKTOP_LEFT       LCTL(KC_LEFT)
#define DESKTOP_RIGHT      LCTL(KC_RIGHT)
#define DESKTOP_FULL       LSFT(LCTL(RALT(KC_F)))
#define DESKTOP_TALL       LSFT(LCTL(RALT(KC_T)))
#define DESKTOP_CYCLE      LSFT(LCTL(RALT(KC_SPC)))
#define WINDOW_FOCUS_LEFT  LCTL(RALT(KC_J))
#define WINDOW_FOCUS_RIGHT LCTL(RALT(KC_K))
#define WINDOW_MOVE_LEFT   LSFT(LCTL(RALT(KC_J)))
#define WINDOW_MOVE_RIGHT  LSFT(LCTL(RALT(KC_K)))

#define KC_FOR_SHIFT(normal,shifted) normal
#define KS_3_UK_HASH								 KC_FOR_SHIFT(KC_3,    KC_UK_HASH)
#define KS_UNDS_MINS  							 KC_FOR_SHIFT(KC_UNDS, KC_MINS)
#define KS_TILD_GRV   							 KC_FOR_SHIFT(KC_TILD, KC_GRV)

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
    KC_ESC,         KC_Q,    KC_W,    KC_E,    KC_R,                KC_T,    KC_Y,    KC_U,               KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,         KC_A,    KC_S,    KC_D,    KC_F,                KC_G,    KC_H,    KC_J,               KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,                KC_B,    KC_N,    KC_M,               KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
    LAYER_MOVEMENT, KC_LCTL, KC_LALT, KC_LGUI, LAYER_SYMBOLS_LEAST, KC_SPC,  KC_SPC,  LAYER_SYMBOLS_MOST, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Symbols (most used, most used + shift, least used)
 * ,-----------------------------------------------------------------------------------.
 * | ~`   | 1!   | 2@   | 3#   | 4$   | 5%   | 6^   | 7&   | 8*   | 9(   | 0)   |------|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | _-   | =+   | [{(  | ]})  | \|/  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |------|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOLS_MOST] = LAYOUT_planck_grid(
    KC_TILD, KC_1,    KC_2,    KS_3_UK_HASH, KC_4,    KC_5,    KC_6,    KC_7,         KC_8,    KC_9,    KC_0,    _______,  
    KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,   KC_NO,   KC_NO,   KS_UNDS_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_NO,   KC_NO,   KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,  
    KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO
),
[_SYMBOLS_LEAST] = LAYOUT_planck_grid(
    KC_GRV,  KC_NO,   KC_NO,   KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,   KC_NO,   KC_NO,   _______,  
		KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,   KC_LPRN, KC_RPRN, KC_SLSH,
		_______, KC_NO,   KC_NO,   KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,  
    KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO
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
    LAYER_MOVEMENT, TMUX_1,      TMUX_2,     TMUX_3,      TMUX_RENAME,  DESKTOP_TALL,  WINDOW_MOVE_LEFT, WINDOW_FOCUS_LEFT, WINDOW_FOCUS_RIGHT, WINDOW_MOVE_RIGHT, KC_NO,      KC_NO,  
    KC_NO,          KC_NO,       TMUX_SPLIT, KC_NO,       DESKTOP_FULL, KC_NO,         TMUX_LEFT,        TMUX_DOWN,         TMUX_UP,            TMUX_RIGHT,        KC_NO,      KC_NO,  
    KC_LSFT,        KC_NO,       KC_NO,      TMUX_CREATE, TMUX_VSPLIT,  KC_NO,         KC_NO,            TMUX_MOVE,         KC_NO,              KC_NO,             KC_NO,      KC_NO,  
    _______,        LAYER_MOUSE, KC_NO,      KC_NO,       KC_NO,        DESKTOP_CYCLE, DESKTOP_CYCLE,    KC_NO,             DESKTOP_LEFT,       KC_NO,             KC_NO,      DESKTOP_RIGHT
),

/* Mouse
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
[_MOUSE] = LAYOUT_planck_grid(
    KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO,      KC_NO,      KC_NO,    KC_NO,       KC_NO,      KC_NO,  
    KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_MS_BTN1, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, KC_MS_BTN2, KC_NO,  
    KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO,      KC_NO,      KC_NO,    KC_NO,       KC_NO,      KC_NO,  
    KC_NO, _______, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO,      KC_NO,      KC_NO,    KC_NO,       KC_NO,      KC_NO
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
    KC_NO,   RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    KC_NO,   KC_NO,   MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,  
    KC_NO,   MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, KC_NO,   KC_NO,   KC_NO,  
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO
)

};

#define ___                {0x00,0x00,0x00}
#define __SPACE__          ___
#define RGB_SYMBOLS_LEAST  {0x88,0x00,0x00}
#define RGB_SYMBOLS_MOST   {0x00,0x88,0x00}
#define RGB_MOVE           {0x00,0x88,0x88}

#define RGB_WINDOW  {0x00,0x88,0x88}
#define RGB_MOUSE   {0xFF,0x44,0x00}
#define RGB_TMUX    {0x88,0x88,0x00}

const uint8_t PROGMEM keymaps_colors[][DRIVER_LED_TOTAL][3] = {
	[_QWERTY] = {
		___,      ___, ___, ___, ___,               ___,  ___, ___,              ___, ___, ___, ___,
		___,      ___, ___, ___, ___,               ___,  ___, ___,              ___, ___, ___, ___,
		___,      ___, ___, ___, ___,               ___,  ___, ___,              ___, ___, ___, ___,
		RGB_MOVE, ___, ___, ___, RGB_SYMBOLS_LEAST, __SPACE__, RGB_SYMBOLS_MOST, ___, ___, ___, ___ 
	},

	[_SYMBOLS_LEAST] = {
		___, ___, ___, ___, ___,               ___,  ___, ___, ___, ___, ___, ___,
		___, ___, ___, ___, ___,               ___,  ___, ___, ___, ___, ___, ___,
		___, ___, ___, ___, ___,               ___,  ___, ___, ___, ___, ___, ___,
		___, ___, ___, ___, RGB_SYMBOLS_LEAST, __SPACE__, ___, ___, ___, ___, ___ 
	},

	[_SYMBOLS_MOST] = {
		___, ___, ___, ___, ___, ___,  ___, ___,              ___, ___, ___, ___,
		___, ___, ___, ___, ___, ___,  ___, ___,              ___, ___, ___, ___,
		___, ___, ___, ___, ___, ___,  ___, ___,              ___, ___, ___, ___,
		___, ___, ___, ___, ___, __SPACE__, RGB_SYMBOLS_MOST, ___, ___, ___, ___ 
	},

	[_ADJUST] = {
		___, ___, ___, ___, ___, ___,  ___, ___, ___, ___, ___, ___,
		___, ___, ___, ___, ___, ___,  ___, ___, ___, ___, ___, ___,
		___, ___, ___, ___, ___, ___,  ___, ___, ___, ___, ___, ___,
		___, ___, ___, ___, ___, __SPACE__, ___, ___, ___, ___, ___ 
	},

	[_MOVEMENT] = {
		RGB_MOVE, RGB_TMUX,  RGB_TMUX, RGB_TMUX, RGB_TMUX,   RGB_WINDOW, RGB_WINDOW, RGB_WINDOW, RGB_WINDOW, RGB_WINDOW, ___,       ___,
		___,      ___,       RGB_TMUX, ___,      RGB_WINDOW, ___,        RGB_TMUX,   RGB_TMUX,   RGB_TMUX,   RGB_TMUX,   ___,       ___,
		RGB_TMUX, ___,       ___,      RGB_TMUX, RGB_TMUX,   ___,        ___,        RGB_TMUX,   ___,        ___,        ___,       ___,
		RGB_MOVE, RGB_MOUSE, ___,      ___,      ___,        RGB_WINDOW, ___,        RGB_WINDOW, ___,        ___,       RGB_WINDOW 
	},

	[_MOUSE] = {
		___, ___,       ___, ___, ___, ___,       ___,       ___,       ___,       ___,       ___,       ___,
		___, ___,       ___, ___, ___, RGB_MOUSE, RGB_MOUSE, RGB_MOUSE, RGB_MOUSE, RGB_MOUSE, RGB_MOUSE, ___,
		___, ___,       ___, ___, ___, ___,       ___,       ___,       ___,       ___,       ___,       ___,
		___, RGB_MOUSE, ___, ___, ___, __SPACE__,            ___,       ___,       ___,       ___,       ___ 
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
	if ((active_layer < _QWERTY) || (active_layer > _MOUSE)) {
		return;
	}

	for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
		const uint8_t *color = keymaps_colors[active_layer][i];
		rgb_matrix_set_color(i, color[0], color[1], color[2]);
	}
#endif
}

#define TMUX_PREFIX SS_LCTRL("a")
#define tmux_toggle(t) if(t){layer_off(_MOVEMENT);}
#define tmux_command(c,t)   if(record->event.pressed) {SEND_STRING(TMUX_PREFIX c); tmux_toggle(t); return false;}
#define tmux_command_with_shift(c,C,t) if(record->event.pressed) {SEND_STRING( (((get_mods() & MOD_BIT(KC_LSFT)) ? (TMUX_PREFIX C) : (TMUX_PREFIX c))) ); tmux_toggle(t); return false;}

bool process_record_user_in_movement(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
		case TMUX_CREATE: tmux_command("c",TRUE); break;
		case TMUX_SPLIT:  tmux_command("-",TRUE); break;
		case TMUX_VSPLIT: tmux_command("v",TRUE); break;
		case TMUX_1:      tmux_command("1",TRUE); break;
		case TMUX_2:      tmux_command("2",TRUE); break;
		case TMUX_3:      tmux_command("3",TRUE); break;
		case TMUX_RENAME: tmux_command_with_shift("4",":rename-window ",TRUE); break;
		case TMUX_MOVE:   tmux_command(":move-window\n",TRUE); break;
		case TMUX_LEFT:   tmux_command_with_shift("h","H",FALSE); break;
		case TMUX_RIGHT:  tmux_command_with_shift("l","L",FALSE); break;
		case TMUX_UP:     tmux_command_with_shift("k","K",FALSE); break;
		case TMUX_DOWN:   tmux_command_with_shift("j","J",FALSE); break;
  }
	return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (get_highest_layer(layer_state)) {
		case _MOVEMENT: return process_record_user_in_movement(keycode, record); break;
		default:        return true;
	}
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _SYMBOLS_LEAST, _SYMBOLS_MOST, _ADJUST);
}
