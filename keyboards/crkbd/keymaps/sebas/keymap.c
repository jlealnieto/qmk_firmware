/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#ifdef RGB_MATRIX_ENABLE
    #define ___off___	{0,0,0}
    #define MG__WHITE	{255,255,255}
    #define	MG____RED	{255,0,0}
    #define MG__GREEN	{32,159,33}
    #define MG___BLUE	{0,181,213}
    #define MG_YELLOW	{255,208,0}
    #define MG_ORANGE	{255,85,0}
    #define MG___PINK	{208,0,255}
    #define MG_PURPLE	{50,0,232}
#endif

enum my_layers {
    _BASE,
    _NAV,
    _NUM,
    _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSHIFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTRL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(1),  KC_SPC,     KC_ENT,   MO(2), LT(3,KC_RALT)
                                      //`--------------------------'  `--------------------------'

  ),

    [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT,   MO(3), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       XXXXXXX, KC_KP_7,   KC_KP_8, KC_KP_9,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_KP_4, KC_KP_5, KC_KP_6, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(3),  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef RGB_MATRIX_ENABLE

const uint8_t PROGMEM ledmap[][42][3] = {
/* Starts at layer 1; we don't apply lights to Base (layer 0). */
[_NAV] = {
MG_ORANGE, MG____RED, ___off___, ___off___, ___off___, ___off___, 				MG_ORANGE, MG___PINK, MG__WHITE, MG___PINK, MG____RED, MG_ORANGE,
MG_ORANGE, MG___BLUE, MG___BLUE, MG___BLUE, MG___BLUE, MG___BLUE, 				MG_ORANGE, MG__WHITE, MG__WHITE, MG__WHITE, ___off___, MG_ORANGE,
MG_ORANGE, MG___PINK, ___off___, MG__GREEN, ___off___, ___off___, 				___off___, MG_YELLOW, ___off___, ___off___, MG___BLUE, MG_ORANGE,
								 ___off___, ___off___, ___off___, 				___off___, MG_ORANGE, ___off___
			},
[_NUM] = {
MG__GREEN, MG_ORANGE, MG_ORANGE, MG_YELLOW, MG_YELLOW, MG___PINK, 				MG___PINK, MG__GREEN, MG__GREEN, MG__GREEN, ___off___, MG__GREEN,
MG__GREEN, MG___BLUE, MG___BLUE, MG___BLUE, MG___BLUE, MG___BLUE, 				___off___, MG__GREEN, MG__GREEN, MG__GREEN, ___off___, MG__GREEN,
MG__GREEN, ___off___, ___off___, MG_ORANGE, MG_ORANGE, MG_PURPLE, 				MG__GREEN, MG__GREEN, MG__GREEN, MG__GREEN, ___off___, MG__GREEN,
						   		 ___off___, MG__GREEN, ___off___, 				___off___, ___off___, ___off___
			},
[_ADJUST] = {
MG_PURPLE, ___off___, MG_PURPLE, MG____RED, MG_PURPLE, ___off___, 				MG_ORANGE, MG___BLUE, MG__WHITE, MG___BLUE, MG____RED, MG_PURPLE,
MG_PURPLE, MG___BLUE, MG___BLUE, MG___BLUE, MG___BLUE, MG___BLUE, 				MG_ORANGE, MG__WHITE, MG__WHITE, MG__WHITE, ___off___, MG_PURPLE,
MG_PURPLE, ___off___, MG_YELLOW, MG_YELLOW, MG_YELLOW, ___off___, 				___off___, ___off___, ___off___, ___off___, ___off___, MG_PURPLE,
						   		 ___off___, MG_PURPLE, ___off___, 				___off___, MG_PURPLE, ___off___
			},
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
    rgb_matrix_sethsv_noeeprom(0, 0, 0); // (180, 255, 231) is purple
    rgb_matrix_mode_noeeprom(1);
}

// ====================================================
// RGB matrix
// ====================================================

uint8_t ledIndexForKeymapIndex(uint8_t keyIndex) {
	// Turn keyIndex into a row and column within g_led_config.
	// Reference: https://github.com/qmk/qmk_firmware/blob/master/keyboards/crkbd/r2g/r2g.c
	uint8_t row = 0;
	uint8_t col = 0;
	uint8_t keysPerRow = 12; // Specific to crkdb!
	uint8_t keysPerHalf = keysPerRow / 2; // Assumes equal split!

	row = keyIndex / keysPerRow;
	col = keyIndex % keysPerRow;
	if (row == 3) { // Specific to crkbd!
		col += 3; // Compensate for leading three NO_LED entries in g_led_config.
	}

	bool mirror = (col >= keysPerHalf);
	if (mirror) {
		// Normalise row and col per g_led_config structure.
		row += 4;
		col -= keysPerHalf;
		// Mirror column position.
		col = (keysPerHalf - 1) - col;
	}

	return g_led_config.matrix_co[row][col];
}

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

    uint8_t layerNum = get_highest_layer(layer_state);
    if (layerNum == 0) {
        rgb_matrix_set_color_all(0, 0, 0);
        return;
    }

    // Per-key indicators
    uint8_t ledIndex = 0;
    uint8_t r, g, b;
    for (uint8_t keyIndex = 0; keyIndex < 42; keyIndex++) { // 0 to 42
        ledIndex = ledIndexForKeymapIndex(keyIndex);

        if (ledIndex >= led_min && ledIndex <= led_max) {
            r = pgm_read_byte(&ledmap[layerNum][keyIndex][0]);
            g = pgm_read_byte(&ledmap[layerNum][keyIndex][1]);
            b = pgm_read_byte(&ledmap[layerNum][keyIndex][2]);

            if (!r && !g && !b) {
                RGB_MATRIX_INDICATOR_SET_COLOR(ledIndex, 0, 0, 0);
            } else {
                RGB_MATRIX_INDICATOR_SET_COLOR(ledIndex, r, g, b);
            }
        }
    }
    /*
    // Underglow layer indicators
    uint8_t keyIndex = 36; // layer-switch key
    r = pgm_read_byte(&ledmap[layerNum][keyIndex][0]);
    g = pgm_read_byte(&ledmap[layerNum][keyIndex][1]);
    b = pgm_read_byte(&ledmap[layerNum][keyIndex][2]);
    for (uint8_t  i = 0; i < 12; i++) {
        ledIndex = (i < 6) ? i : i + 21;
        RGB_MATRIX_INDICATOR_SET_COLOR(ledIndex, r, g, b);
    }
    */
}

#endif