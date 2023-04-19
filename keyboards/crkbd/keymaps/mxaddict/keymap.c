/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2023 mxaddict <mxaddict@codedmaster.com>

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
#include <stdio.h>

enum layers {
    _TXT,
    _HOT,
    _NUM,
    _FUN,
    _SYM,
    _NAV,
};

static const char* layer_names[] = {
    "TXT",
    "HOT",
    "NUM",
    "FUN",
    "SYM",
    "NAV",
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_TXT] = LAYOUT_split_3x5_3(
  //+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+
         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  //+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+
         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,
  //+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+
         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  //+--------+--------+--------+--------+--------+--------+  +--------+--------+--------+--------+--------+--------+
                  CTL_T(KC_ESC),   SFT_T(KC_CAPS),  KC_SPC,   KC_ENTER,   ALT_T(KC_BSPC), TO(_HOT)
  //+--------+--------+--------+--------+--------+--------+  +--------+--------+--------+--------+--------+--------+
  ),

  [_HOT] = LAYOUT_split_3x5_3(
  //+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+
      XXXXXXX, XXXXXXX,TO(_SYM),TO(_NUM), XXXXXXX,                      XXXXXXX,TO(_NAV),TO(_FUN), XXXXXXX, XXXXXXX,
  //+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+
      KC_LGUI, KC_LSFT, KC_LALT, KC_LCTL, XXXXXXX,                      XXXXXXX, KC_RCTL, KC_RALT, KC_RSFT, KC_RGUI,
  //+--------+--------+--------+--------+--------+--------+  +--------+--------+--------+--------+--------+--------+
                                TO(_TXT), _______,  KC_TAB,     KC_TAB, _______, _______
  //+--------+--------+--------+--------+--------+--------+  +--------+--------+--------+--------+--------+--------+
  ),

  [_NUM] = LAYOUT_split_3x5_3(
  //+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+
      XXXXXXX, XXXXXXX,  KC_DLR, KC_LPRN, XXXXXXX,                      XXXXXXX, KC_RPRN, KC_PERC, XXXXXXX, XXXXXXX,
  //+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+
         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  //+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+
      KC_EXLM, KC_ASTR, KC_MINS, KC_PLUS, XXXXXXX,                      XXXXXXX,  KC_EQL, KC_COMM,  KC_DOT, KC_SLSH,
  //+--------+--------+--------+--------+--------+--------+  +--------+--------+--------+--------+--------+--------+
                                TO(_TXT), _______, _______,    _______, _______, _______
  //+--------+--------+--------+--------+--------+--------+  +--------+--------+--------+--------+--------+--------+
  ),

  [_FUN] = LAYOUT_split_3x5_3(
  //+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+
        KC_F1,   KC_F2,   KC_F3,   KC_F4, XXXXXXX,                      XXXXXXX,   KC_F5,   KC_F6,   KC_F7,   KC_F8,
  //+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+
        KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX,                      XXXXXXX,  KC_F13,  KC_F14,  KC_F15,  KC_F16,
  //+--------+--------+--------+--------+--------+--------+  +--------+--------+--------+--------+--------+--------+
                                TO(_TXT), _______, _______,    _______, _______, _______
  //+--------+--------+--------+--------+--------+--------+  +--------+--------+--------+--------+--------+--------+
  ),

  [_SYM] = LAYOUT_split_3x5_3(
  //+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+
      KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, XXXXXXX,                      XXXXXXX, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR,
  //+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+
      KC_BSLS, KC_LBRC, KC_LCBR, KC_LPRN, XXXXXXX,                      XXXXXXX, KC_RPRN, KC_RBRC, KC_RCBR, KC_PIPE,
  //+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+
      XXXXXXX, XXXXXXX,  KC_EQL, KC_PLUS, XXXXXXX,                      XXXXXXX, KC_MINS, KC_UNDS, XXXXXXX, XXXXXXX,
  //+--------+--------+--------+--------+--------+--------+  +--------+--------+--------+--------+--------+--------+
                                TO(_TXT), _______, _______,    _______, _______, _______
  //+--------+--------+--------+--------+--------+--------+  +--------+--------+--------+--------+--------+--------+
  ),

  [_NAV] = LAYOUT_split_3x5_3(
  //+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+
      XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX,
  //+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+
      XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX,                      XXXXXXX, KC_MPRV, KC_MNXT, KC_MPLY, XXXXXXX,
  //+--------+--------+--------+--------+--------+--------+  +--------+--------+--------+--------+--------+--------+
                                TO(_TXT), _______, _______,    _______, _______, _______
  //+--------+--------+--------+--------+--------+--------+  +--------+--------+--------+--------+--------+--------+
  )
};

#ifdef OLED_ENABLE

#define LOGO_SIZE     128
#define LOGO_BIG_SIZE 512

static const char PROGMEM logo[LOGO_SIZE] = {
    0x00, 0x00, 0x80, 0xc0, 0x60, 0x30, 0x18, 0x0c, 0x0c, 0x06, 0x06, 0xc3, 0xe3, 0xf3, 0xfb, 0xfb,
    0xfb, 0xfb, 0xf3, 0xe3, 0xc3, 0x06, 0x06, 0x0c, 0x0c, 0x18, 0x30, 0x60, 0xc0, 0x80, 0x00, 0x00,
    0xf8, 0xfe, 0x07, 0xe1, 0xf0, 0xf8, 0xfc, 0xfc, 0xfc, 0xfc, 0xf8, 0xf3, 0xe7, 0x0f, 0x1f, 0xff,
    0xff, 0x1f, 0x0f, 0xe7, 0xf3, 0xf8, 0xfc, 0xfc, 0xfc, 0xfc, 0xf8, 0xf0, 0xe1, 0x07, 0xfe, 0xf8,
    0x1f, 0x7f, 0xe0, 0x81, 0x03, 0x07, 0x0f, 0x0f, 0x0f, 0x0f, 0x07, 0x0f, 0x1d, 0x38, 0x70, 0xff,
    0xff, 0x70, 0x38, 0x1d, 0x0f, 0x07, 0x0f, 0x0f, 0x0f, 0x0f, 0x07, 0x03, 0x81, 0xe0, 0x7f, 0x1f,
    0x00, 0x00, 0x01, 0x03, 0x06, 0x0c, 0x18, 0x30, 0x30, 0x60, 0x60, 0xc0, 0xc0, 0xc0, 0xc0, 0xdf,
    0xdf, 0xc0, 0xc0, 0xc0, 0xc0, 0x60, 0x60, 0x30, 0x30, 0x18, 0x0c, 0x06, 0x03, 0x01, 0x00, 0x00
};

static const char PROGMEM logo_big[LOGO_BIG_SIZE] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf0, 0xf8, 0x7c, 0x3e, 0x1f, 0x1f, 0x1f,
    0x1c, 0x1e, 0x1f, 0x1f, 0x1f, 0x9f, 0xdf, 0x9f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc3, 0x3f, 0xff, 0xff, 0xf8, 0xe0, 0xc0, 0xc0, 0xc0,
    0xc0, 0xc0, 0xe0, 0xf8, 0xff, 0xff, 0x3f, 0x87, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x7f, 0xfe, 0xf9, 0xf1, 0xc3, 0x83, 0x03, 0x03,
    0x03, 0x83, 0xc3, 0xf1, 0xf9, 0xfc, 0x3f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x78, 0x78, 0x7b, 0x7f, 0x7f, 0x7f, 0x7e, 0x7c,
    0x3e, 0x1f, 0x7f, 0x7f, 0x7b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf0, 0xf8, 0x7c, 0x3e, 0x1f, 0x1f, 0x1f,
    0x1c, 0x1e, 0x1f, 0x1f, 0x1f, 0x9f, 0xdf, 0x9f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x3f, 0xff, 0xff, 0xf8, 0xe0, 0xc0, 0xc0, 0xc0,
    0xc0, 0xc0, 0xe0, 0xf8, 0xff, 0xff, 0x3f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xe1, 0x01, 0x03, 0x03, 0x07, 0x07,
    0x87, 0xc3, 0xf3, 0xf9, 0xf9, 0xf8, 0xf8, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0xc0, 0xe0, 0xf8, 0xfc, 0xfe,
    0x3f, 0x1f, 0x07, 0x07, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x8f, 0xc3, 0xc1, 0xc0,
    0x00, 0x9e, 0xde, 0xde, 0xdf, 0xdf, 0xcf, 0xc7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf8, 0xfc, 0xfe, 0x1f, 0x0f, 0x07, 0x07, 0x07,
    0x07, 0x07, 0x07, 0x07, 0xc7, 0xe7, 0xf7, 0xe7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x3f, 0x7f, 0x7e, 0xf8, 0xf0, 0xf0, 0xf0,
    0xf0, 0xf0, 0xf8, 0x7e, 0x7f, 0x3f, 0x0f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf8, 0xf8, 0xfc, 0xfc, 0x3c, 0x3c, 0x01, 0x01,
    0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x80,
    0xc0, 0xf0, 0xf8, 0xfe, 0x7f, 0x1f, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x8f, 0xcf, 0xef, 0xef, 0xef,
    0x87, 0xc3, 0xef, 0xef, 0xef, 0xe0, 0xe0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0xfc, 0xfe, 0xff, 0x0f, 0x07, 0x03, 0x03, 0x03,
    0x03, 0x03, 0x03, 0x03, 0xe3, 0xf3, 0xfb, 0xf3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x1f, 0x3f, 0x3f, 0x7c, 0x78, 0xf8, 0xf8,
    0xf8, 0x78, 0x7c, 0x3f, 0x3f, 0x1f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

void oled_render_status(void) {
    if (!is_keyboard_master()) return;
    oled_set_cursor(0, 5);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR("--"), false);
    oled_write_ln(layer_names[get_highest_layer(layer_state)], false);
    oled_write_ln("", false);

    char wpm[4];
    sprintf(wpm, "%03d", get_current_wpm());
    oled_write_ln_P(PSTR("WPM"), false);
    oled_write_ln_P(PSTR("--"), false);
    oled_write_ln(wpm, false);
    oled_write_ln("", false);

    led_t led_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CAP"), false);
    oled_write_ln_P(PSTR("--"), false);
    oled_write_ln_P(led_state.caps_lock ? PSTR("YES") : PSTR("NO"), false);
}

uint16_t timer;
uint16_t timer_offset;
void oled_render_glitch(void) {
    // TODO: see if we can't get a better glitch effect
    oled_set_cursor(0, 0);

    uint16_t time = timer_elapsed(timer);

    if (time < (200 + timer_offset)) {
        char screen[OLED_MATRIX_SIZE];
        oled_buffer_reader_t reader;
        for (int i = 0; i < OLED_MATRIX_SIZE; ++i) {
            reader = oled_read_raw(i);
            screen[i] = *reader.current_element;
        }

        int shift = rand() % 9;
        while (shift--) {
            for (int i = OLED_MATRIX_SIZE-1; i > 0; i--) {
                screen[i] >>= 1;
                if (screen[i-1] & 0x01) {
                    screen[i] |= 0x80;
                }
            }
            screen[0] >>= 1;
        }

        oled_write_raw(screen, OLED_MATRIX_SIZE);
        return;
    }

    if (time >= (1500 + timer_offset)) {
        timer = timer_read();
        timer_offset = 300 + rand() % 500;
    }
}

void oled_render_logo(void) {
    if (is_keyboard_master()) {
        oled_write_raw_P(logo, LOGO_SIZE);
        return;
    }

    oled_write_raw_P(logo_big, LOGO_BIG_SIZE);
}

bool oled_task_user(void) {
    oled_clear();

    oled_render_logo();
    oled_render_status();
    oled_render_glitch();

    return false;
}

#endif // OLED_ENABLE
