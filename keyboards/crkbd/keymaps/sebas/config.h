// Copyright 2026 Sebastian Leal (@jlealnieto)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// El cable USB va a la mitad izquierda
#define MASTER_LEFT

// --- Tap-hold (Space = NUM, Enter = SYM) ---
#define TAPPING_TERM 200
// Si se presiona y suelta otra tecla mientras Space/Enter siguen abajo, cuenta como capa aunque no pasen 200 ms
#define PERMISSIVE_HOLD
// Sin auto-repeat al tap+hold: mantener siempre activa la capa
#define QUICK_TAP_TERM 0
// Escribiendo rápido (<150 ms desde la tecla anterior), Space siempre es espacio y nunca activa NUM
#define FLOW_TAP_TERM 150

// --- Caps Word: doble toque de Shift (solo hay un Shift en la capa base) ---
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

// --- Split: la mitad derecha necesita capa, LEDs del host y mods para pintar RGB/OLED ---
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_OLED_ENABLE

// --- RGB Matrix ---
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
#define RGB_MATRIX_DEFAULT_VAL 100
#define RGB_MATRIX_SLEEP
#define RGB_MATRIX_TIMEOUT 600000
// Efectos para cuando el tema EVA está apagado (pocos, para cuidar los 28 KB)
#define ENABLE_RGB_MATRIX_BREATHING
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON

// --- OLED ---
#define OLED_TIMEOUT 600000

// --- Ahorro de memoria ---
#define LAYER_STATE_8BIT
#define NO_ACTION_ONESHOT
#define NO_MUSIC_MODE
