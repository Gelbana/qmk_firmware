/* Copyright 2020 foostan
 *
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
#include "features/caps_word.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT(
      KC_TAB,         KC_Q,         KC_W,       KC_F,         KC_P,         KC_B,         KC_J,         KC_L,    KC_U,     KC_Y, KC_SCLN, KC_BSPC,
      LCTL_T(KC_ESC), LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G, KC_M ,LSFT_T(KC_N), LCTL_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O), KC_QUOT,
     KC_LSPO,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,  KC_COMM,  KC_DOT, KC_SLSH, KC_RSPC,
     XXXXXXX, KC_LCTL, KC_LGUI, KC_LALT,   LT(1, KC_TAB),  KC_SPC,  LT(2, KC_ENT),   LT(3, KC_BSPC),  LT(4, KC_RALT), KC_RGUI, TG(5), XXXXXXX
  ),

[1] = LAYOUT(
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_CAPS, KC_BSPC,
     _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, LSFT(KC_RSFT),  KC_DEL,
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_INS, KC_CAPS,
     _______, _______, _______, _______,   MO(1), _______, _______,   MO(3), _______, _______, QK_BOOT, _______
  ),

[2] = LAYOUT(
     _______, XXXXXXX,  KC_7,      KC_8,    KC_9, KC_PERC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
     _______, KC_COLN,  KC_4,      KC_5,    KC_6, KC_PIPE, XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
     _______, KC_TILD,  KC_1,      KC_2,    KC_3, KC_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     _______, _______, _______,    KC_DOT,  KC_0, KC_MINUS, _______,   MO(2), _______, _______, _______, _______
  ),

[3] = LAYOUT(
     _______, XXXXXXX, KC_AMPR, KC_ASTR, KC_LPRN, XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
     _______, XXXXXXX,  KC_DLR, KC_PERC, KC_CIRC, XXXXXXX, KC_MINS,  KC_EQL, KC_LCBR, KC_RCBR, KC_PIPE,  KC_GRV,
     _______, KC_GRAVE, KC_EXLM,   KC_AT, KC_HASH, XXXXXXX, KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, KC_TILD,
     _______, _______, _______, _______,   MO(3), KC_UNDS, _______,   MO(3), _______, _______, _______, _______
  ),

[4] = LAYOUT(
     _______,  KC_F12,  KC_F7,   KC_F8,   KC_F9, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     _______,  KC_F11,  KC_F4,   KC_F5,   KC_F6, XXXXXXX, XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
     _______,  KC_F10,  KC_F1,   KC_F2,   KC_F3, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     _______, _______, _______, _______,   MO(3), _______, _______,   MO(3), _______, _______, _______, _______
  ),

[5] = LAYOUT(
      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,     KC_I,    KC_O,   KC_P,  KC_BSPC,
      KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,     KC_K,    KC_L, KC_SCLN, KC_QUOT,
     KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,  KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
     XXXXXXX, KC_LCTL, KC_LGUI, KC_LALT, KC_TAB,  KC_SPC,  KC_ENT, KC_BSPC,  KC_RALT, KC_RGUI, TG(5), XXXXXXX
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_caps_word(keycode, record)) { return false; }
  // Nothing
  return true;
}

void matrix_scan_user(void) {
  caps_word_task();
  // Nothing
}
