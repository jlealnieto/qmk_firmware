// Copyright 2026 Sebastian Leal (@jlealnieto)
// SPDX-License-Identifier: GPL-2.0-or-later
//
// Corne (crkbd/rev1) — QWERTY para macOS con layout "U.S. International - PC".
// Capas: BASE, WM (AeroSpace), NUM, SYM, ADJ (NUM+SYM). CAPS es una capa vacía que solo
// sirve para sincronizar Caps Word con la mitad derecha (el estado de capas sí se sincroniza).

#include QMK_KEYBOARD_H
#include "eva01_logo.h"

enum layers { _BASE, _WM, _NUM, _SYM, _ADJ, _CAPS };

enum custom_keycodes {
    // Teclas muertas de US International: envían el símbolo + espacio para que salga literal
    DK_QUOT = SAFE_RANGE,
    DK_DQUO,
    DK_GRV,
    DK_TILD,
    DK_CIRC,
    // Prende/apaga el tema EVA-01 de la capa base (apagado = efecto normal de RGB Matrix)
    EVA_TOG,
};

#define SPC_NUM LT(_NUM, KC_SPC)
#define ENT_SYM LT(_SYM, KC_ENT)
#define WM MO(_WM)

// AeroSpace (~/.aerospace.toml): todo es alt-<tecla>. Con Shift/Ctrl físicos se vuelve alt-shift / alt-ctrl
#define WS(n) A(n)
#define WS_BACK A(KC_TAB)
#define WM_RSZ A(KC_R)
#define WM_TILE A(KC_SLSH)
#define WM_ACCO A(KC_COMM)
#define WM_FLT A(S(KC_SPC))
#define WM_LEFT A(KC_H)
#define WM_DOWN A(KC_J)
#define WM_UP A(KC_K)
#define WM_RGHT A(KC_L)
#define WM_SHRK A(KC_MINS)
#define WM_GROW A(KC_EQL)
#define WM_TERM A(S(KC_ENT))

// Inicio/fin de línea en macOS (Home/End no lo hacen en la mayoría de apps)
#define LN_HOME G(KC_LEFT)
#define LN_END G(KC_RGHT)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ESC,
                                   KC_LGUI, WM,      SPC_NUM,      ENT_SYM, KC_LALT, KC_BSPC
    ),
    [_WM] = LAYOUT_split_3x6_3(
        WS_BACK, WM_RSZ,  WM_TILE, WM_UP,   WM_ACCO, XXXXXXX,      XXXXXXX, WS(KC_7),WS(KC_8),WS(KC_9),WS(KC_0),XXXXXXX,
        KC_LCTL, XXXXXXX, WM_LEFT, WM_DOWN, WM_RGHT, WM_FLT,       XXXXXXX, WS(KC_4),WS(KC_5),WS(KC_6),XXXXXXX, XXXXXXX,
        KC_LSFT, WM_SHRK, WM_GROW, XXXXXXX, XXXXXXX, WM_TERM,      XXXXXXX, WS(KC_1),WS(KC_2),WS(KC_3),XXXXXXX, XXXXXXX,
                                   XXXXXXX, _______, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_NUM] = LAYOUT_split_3x6_3(
        XXXXXXX, XXXXXXX, LN_HOME, KC_UP,   LN_END,  KC_PGUP,      KC_PLUS, KC_7,    KC_8,    KC_9,    KC_ASTR, KC_BSPC,
        KC_LCTL, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,      KC_MINS, KC_4,    KC_5,    KC_6,    KC_SLSH, XXXXXXX,
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      KC_0,    KC_1,    KC_2,    KC_3,    KC_DOT,  XXXXXXX,
                                   _______, _______, _______,      _______, _______, _______
    ),
    [_SYM] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      DK_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL,  KC_BSPC,
        KC_LCTL, KC_LT,   KC_LCBR, KC_LBRC, KC_LPRN, DK_DQUO,      DK_QUOT, KC_RPRN, KC_RBRC, KC_RCBR, KC_GT,   XXXXXXX,
        KC_LSFT, DK_GRV,  DK_TILD, KC_BSLS, KC_PIPE, KC_SCLN,      KC_COLN, KC_UNDS, KC_PLUS, KC_QUES, KC_SLSH, XXXXXXX,
                                   _______, _______, _______,      _______, _______, _______
    ),
    [_ADJ] = LAYOUT_split_3x6_3(
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX,      RM_TOGG, RM_NEXT, RM_HUEU, RM_SATU, RM_VALU, QK_BOOT,
        XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX,      KC_CAPS, RM_PREV, RM_HUED, RM_SATD, RM_VALD, XXXXXXX,
        XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,      EVA_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   _______, _______, _______,      _______, _______, _______
    ),
    [_CAPS] = LAYOUT_split_3x6_3(
        _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______,      _______, _______, _______
    ),
};
// clang-format on

static bool eva_theme = true;

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NUM, _SYM, _ADJ);
}

void caps_word_set_user(bool active) {
    if (active) {
        layer_on(_CAPS);
    } else {
        layer_off(_CAPS);
    }
}

static uint8_t current_layer(void) {
    return get_highest_layer(layer_state & ~((layer_state_t)1 << _CAPS));
}

static bool caps_active(void) {
    return layer_state_is(_CAPS) || host_keyboard_led_state().caps_lock;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }
    switch (keycode) {
        case DK_QUOT: tap_code16(KC_QUOT); tap_code(KC_SPC); return false;
        case DK_DQUO: tap_code16(KC_DQUO); tap_code(KC_SPC); return false;
        case DK_GRV:  tap_code16(KC_GRV);  tap_code(KC_SPC); return false;
        case DK_TILD: tap_code16(KC_TILD); tap_code(KC_SPC); return false;
        case DK_CIRC: tap_code16(KC_CIRC); tap_code(KC_SPC); return false;
        case EVA_TOG: eva_theme = !eva_theme; return false;
    }
    return true;
}

// ---------------------------------------------------------------- RGB ---

// Hue en escala QMK (0-255)
#define HUE_EVA_GREEN 80
#define HUE_EVA_MAGENTA 213
#define HUE_EVA_PURPLE 191
#define HUE_RED 0
#define HUE_ORANGE 16
#define HUE_YELLOW 40
#define HUE_CYAN 128
#define HUE_AZURE 150
#define HUE_BLUE 170

static void set_led_hsv(uint8_t index, uint8_t hue, uint8_t sat, uint8_t val) {
    rgb_t rgb = hsv_to_rgb((hsv_t){hue, sat, val});
    rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
}

static uint8_t layer_hue(uint8_t layer) {
    switch (layer) {
        case _WM:  return HUE_BLUE;
        case _NUM: return HUE_ORANGE;
        case _SYM: return HUE_CYAN;
        default:   return HUE_EVA_PURPLE;
    }
}

static bool is_bracket(uint16_t kc) {
    switch (kc) {
        case KC_LPRN: case KC_RPRN: case KC_LBRC: case KC_RBRC:
        case KC_LCBR: case KC_RCBR: case KC_LT:   case KC_GT:
            return true;
    }
    return false;
}

// Devuelve false si la tecla va apagada en esta capa
static bool key_color(uint8_t layer, uint16_t kc, uint8_t led_flags, uint8_t *hue, uint8_t *sat) {
    *sat = 255;
    if (layer == _BASE) {
        *hue = HAS_FLAGS(led_flags, LED_FLAG_MODIFIER) ? HUE_EVA_MAGENTA : HUE_EVA_GREEN;
        return true;
    }
    if (kc == KC_NO) {
        return false;
    }
    if (IS_MODIFIER_KEYCODE(kc)) {
        *hue = HUE_EVA_MAGENTA;
        return true;
    }
    switch (layer) {
        case _WM:
            // Workspaces en azul, acciones (foco, layout, tamaño) en celeste
            *hue = (kc >= WS(KC_1) && kc <= WS(KC_0)) ? HUE_BLUE : HUE_AZURE;
            return true;
        case _NUM:
            *hue = (kc >= KC_1 && kc <= KC_0) ? HUE_ORANGE : HUE_YELLOW;
            return true;
        case _SYM:
            // Pares de apertura/cierre en cian, comillas y acentos en amarillo, el resto en celeste
            if (is_bracket(kc)) {
                *hue = HUE_CYAN;
            } else if (kc >= DK_QUOT && kc <= DK_CIRC) {
                *hue = HUE_YELLOW;
            } else {
                *hue = HUE_AZURE;
            }
            return true;
        case _ADJ:
            if (kc == QK_BOOT) {
                *hue = HUE_RED;
            } else if (kc >= KC_F1 && kc <= KC_F12) {
                *hue = 0;
                *sat = 0;
            } else {
                *hue = HUE_YELLOW;
            }
            return true;
    }
    return false;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = current_layer();
    bool    caps  = caps_active();

    if (layer == _BASE && !eva_theme && !caps) {
        return false;
    }

    uint8_t val = rgb_matrix_get_val();

    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            uint8_t index = g_led_config.matrix_co[row][col];
            if (index == NO_LED || index < led_min || index >= led_max) {
                continue;
            }
            if (caps) {
                set_led_hsv(index, HUE_RED, 255, val);
                continue;
            }
            uint16_t kc = keymap_key_to_keycode(layer, (keypos_t){.row = row, .col = col});
            uint8_t  hue, sat;
            if (kc == KC_TRNS) {
                // Pulgares que siguen funcionando igual que en base: magenta tenue
                set_led_hsv(index, HUE_EVA_MAGENTA, 255, val / 4);
            } else if (key_color(layer, kc, g_led_config.flags[index], &hue, &sat)) {
                set_led_hsv(index, hue, sat, val);
            } else {
                rgb_matrix_set_color(index, 0, 0, 0);
            }
        }
    }

    // Underglow: color de la capa (o rojo con Caps), a media intensidad
    for (uint8_t i = led_min; i < led_max; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
            set_led_hsv(i, caps ? HUE_RED : layer_hue(layer), layer == _ADJ && !caps ? 0 : 255, val / 2);
        }
    }
    return false;
}

// --------------------------------------------------------------- OLED ---

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

static void render_line(uint8_t line, const char *text, bool inverted) {
    oled_set_cursor(0, line);
    oled_write_P(text, inverted);
}

// Mitad izquierda: capa, mods, Caps y WPM (5 caracteres por línea con la OLED vertical)
static void render_status(void) {
    uint8_t layer = current_layer();
    uint8_t mods  = get_mods();

    render_line(0, PSTR("CORNE"), false);
    render_line(1, PSTR("-----"), false);
    switch (layer) {
        case _WM:  render_line(3, PSTR(" WM  "), true); break;
        case _NUM: render_line(3, PSTR(" NUM "), true); break;
        case _SYM: render_line(3, PSTR(" SYM "), true); break;
        case _ADJ: render_line(3, PSTR(" ADJ "), true); break;
        default:   render_line(3, PSTR("BASE "), false); break;
    }

    render_line(6, PSTR(" CMD "), mods & MOD_MASK_GUI);
    render_line(7, PSTR(" OPT "), mods & MOD_MASK_ALT);
    render_line(8, PSTR(" SFT "), mods & MOD_MASK_SHIFT);
    render_line(9, PSTR(" CTL "), mods & MOD_MASK_CTRL);

    render_line(11, PSTR("CAPS "), caps_active());

    render_line(13, PSTR(" WPM "), false);
    oled_set_cursor(1, 14);
    oled_write(get_u8_str(get_current_wpm(), ' '), false);
}

// Mitad derecha: logo EVA-01
static void render_logo(void) {
    oled_write_raw_P(eva01_logo, sizeof(eva01_logo));
    render_line(7, PSTR(" EVA "), false);
    render_line(8, PSTR(" -01 "), false);
    render_line(10, PSTR("-----"), false);
    render_line(12, PSTR("NERV "), false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();
    } else {
        render_logo();
    }
    // false: evita que crkbd.c dibuje su pantalla por defecto encima
    return false;
}
