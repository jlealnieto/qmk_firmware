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

#define KC_LT2 LT(2,KC_ENTER)
#define KC_LT1 LT(1,KC_SPC)

enum layer_number {
  _BASE = 0,
  _NUMBERS,
  _SYMBOLS,
  _FUNCTIONS
};

//tap dance declarations
enum
{
	TD_ESC_TAB,
	TD_SF_MAY
};

//tap dance definitions
tap_dance_action_t tap_dance_actions[] = {

		[TD_ESC_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_ESC),
		[TD_SF_MAY]  = ACTION_TAP_DANCE_DOUBLE(KC_LSFT,KC_CAPS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     TD(TD_ESC_TAB),KC_Q,KC_W,  KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     TD(TD_SF_MAY), KC_A, KC_S, KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LCTL,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_GRAVE,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+---------+--------+--------+--------+--------+--------|
                                          KC_LGUI, KC_LALT, KC_LT1,     KC_LT2,  KC_RALT, KC_RGUI
                                      //`--------------------------'  `---------------------------'

  ),

    [_NUMBERS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_MPLY,  KC_1,    KC_2,     KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     TD(TD_SF_MAY), KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,XXXXXXX, KC_DELETE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LCTL, KC_MPRV, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,                      XXXXXXX, KC_END,  KC_HOME, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+----------+--------+--------+-------+--------+--------|
                                         KC_LGUI, KC_LALT,  _______,    MO(3),  KC_RALT,  KC_RALT
                                      //`--------+--------+--------'  `--------+----------+--------'
  ),

    [_SYMBOLS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_TAB,  KC_EXLM,  KC_AT,  KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                		  KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_UNDS,  KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, MO(3),  KC_SPC,      _______, KC_RALT, KC_RGUI
                                      //`--------------------------'  `--------------------------'
  ),

    [_FUNCTIONS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______, KC_SPC,     _______, KC_RALT, KC_RGUI
                                      //`--------------------------'  `--------------------------'
  )
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

      for (uint8_t i = led_min; i < led_max; i++) {

         if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {

         switch(get_highest_layer(layer_state)) {
               case _NUMBERS:
                  rgb_matrix_set_color(i, RGB_PINK);
                  break;
               case _SYMBOLS:
                  rgb_matrix_set_color(i, RGB_BLUE);
                  break;
                  case  _FUNCTIONS:
                     rgb_matrix_set_color(i, RGB_CYAN);
                     break;
                  default:

                     if (host_keyboard_led_state().caps_lock) {

                        rgb_matrix_set_color(i, RGB_RED);
                  }
                  break;
         }
       }
      }

    return false;
}

#ifdef OLED_ENABLE

//  Rotate OLED
	oled_rotation_t oled_init_user(oled_rotation_t rotation) {


			return OLED_ROTATION_180;
	}

	bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("BASE\n"), false);
            break;
        case _NUMBERS:
            oled_write_P(PSTR("NUMBERS\n"), false);
            break;
        case _SYMBOLS:
            oled_write_P(PSTR("SYMBOLS\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    return false;
}
#endif
