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
// #include "keymap_spanish.h"

enum layers {
    _DVORAK,
    _LOWER,
    _RAISE,
    _ADJUST,
    _FN,
    _GAMING,
};

// TAP DANCE NAME
enum {
    TD_SF_CAPS,
    TD_QUOT,
    TD_COMM,
    TD_DOT,
    TD_SLSH,
    TD_MINS,
    TD_SCLN,
    // TD_TAB_ESC
    TD_FIRST,
    TD_SECOND,
    TD_THIRD,
    TD_N,
    TD_A,
    TD_E,
    TD_I,
    TD_O,
    TD_U,
    TD_INDENT,
    TD_SPC_ENT,
    TD_BC_PIPE,
    TD_EQ_PLUS,
    TD_GRV,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DVORAK] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB,    TD(TD_QUOT),    TD(TD_COMM),    TD(TD_DOT),    KC_P,    KC_Y,                         KC_F,    KC_G,    KC_C,    KC_R,   KC_L,  KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        TD(TD_SF_CAPS),    TD(TD_A),    TD(TD_O),    TD(TD_E),    TD(TD_U),    TD(TD_I),                         KC_D,    KC_H,    KC_T,    TD(TD_N), KC_S, TD(TD_MINS),
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL,    TD(TD_SCLN),    KC_Q,    KC_J,    KC_K,    KC_X,                         KC_B,    KC_M, KC_W,  KC_V, KC_Z,  KC_RCTL,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_LALT,   MO(1),  TD(TD_SPC_ENT),     KC_ENT,   MO(2), KC_LGUI
                                        //`--------------------------'  `--------------------------'
    ),

    [_LOWER] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        TD(TD_SF_CAPS), LCTL(KC_S), LSFT(LALT(KC_DOWN)), LALT(KC_DOWN), LALT(KC_UP), TD(TD_INDENT),                     LSFT(LCTL(KC_P)), KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT, LCTL(KC_SLSH),
    //|--------+--------+-- ------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, LALT(KC_GRV), KC_F2, LCTL(KC_C), LCTL(KC_V), LCTL(KC_Z),                      LCTL(KC_GRV), LCTL(KC_LEFT), KC_HOME, KC_END, LCTL(KC_RIGHT), KC_RCTL,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_LALT, _______,  TD(TD_SPC_ENT),     KC_ENT,   MO(3), LCTL(LSFT(KC_BSLS))
                                        //`--------------------------'  `--------------------------'
    ),

    [_RAISE] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_ESC, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, TD(TD_BC_PIPE), TD(TD_GRV), KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        // TD(TD_SF_CAPS), XXXXXXX, XXXXXXX, LALT(KC_DOWN), LALT(KC_UP), XXXXXXX,              TD(TD_EQ_PLUS),  LCTL(KC_SLSH), XXXXXXX, KC_PGUP, KC_PGDN,  TD(TD_SLSH),
        TD(TD_SF_CAPS), XXXXXXX, TD(TD_FIRST), TD(TD_SECOND), TD(TD_THIRD), XXXXXXX,              KC_DEL, TD(TD_EQ_PLUS), TD(TD_SLSH), KC_APP, XXXXXXX, LCTL(KC_BSLS),
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, XXXXXXX, LALT(KC_F4), KC_F5, KC_F12, XXXXXXX,                     LCTL(LSFT(LALT(KC_UP))), LCTL(KC_1), LCTL(KC_2), LCTL(KC_W), LCTL(LSFT(LALT(KC_DOWN))), KC_RCTL,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_LALT,   MO(3),  TD(TD_SPC_ENT),     KC_ENT, _______, XXXXXXX
                                        //`--------------------------'  `--------------------------'
    ),

    [_ADJUST] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        TG(4), XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT, XXXXXXX,                      LSFT(LALT(KC_F)), LCTL(KC_UP), KC_PGUP, KC_PGDN, LCTL(KC_DOWN), XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, KC_VOLU, XXXXXXX,                      XXXXXXX,  LSFT(LALT(KC_LEFT)), XXXXXXX, XXXXXXX, LSFT(LALT(KC_RGHT)), XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, LCTL(LALT(KC_K)), LCTL(LALT(KC_L)), LCTL(LALT(KC_J)), KC_MPLY, XXXXXXX,                      XXXXXXX, LCTL(LSFT(KC_LBRC)),XXXXXXX, XXXXXXX, LCTL(LSFT(KC_RBRC)), KC_RCTL,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_LALT, _______,  TD(TD_SPC_ENT),     KC_ENT, _______, XXXXXXX
                                        //`--------------------------'  `--------------------------'
    ),

    [_FN] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        TG(4), KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                      KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, TG(5),
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_LALT, XXXXXXX,  XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX
                                        //`--------------------------'  `--------------------------'
    ),

    [_GAMING] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,  KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, TG(5),
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         XXXXXXX,    XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_ESC,   KC_SPC,  KC_ENT,     KC_LALT,   XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
    ),
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SF_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [TD_QUOT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, LSFT(KC_QUOT)),
    [TD_COMM] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, LSFT(KC_COMM)),
    [TD_DOT] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, LSFT(KC_DOT)),
    [TD_SLSH] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, LSFT(KC_SLSH)),
    [TD_MINS] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, LSFT(KC_MINS)),
    [TD_SCLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, LSFT(KC_SCLN)),
    [TD_FIRST] = ACTION_TAP_DANCE_DOUBLE(LSFT(KC_9), LSFT(KC_0)),
    [TD_SECOND] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
    [TD_THIRD] = ACTION_TAP_DANCE_DOUBLE(LSFT(KC_LBRC), LSFT(KC_RBRC)),
    // [TD_TAB_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_ESC),
    [TD_N] = ACTION_TAP_DANCE_DOUBLE(KC_N, ALGR(KC_N)),
    [TD_A] = ACTION_TAP_DANCE_DOUBLE(KC_A, ALGR(KC_A)),
    [TD_E] = ACTION_TAP_DANCE_DOUBLE(KC_E, ALGR(KC_E)),
    [TD_I] = ACTION_TAP_DANCE_DOUBLE(KC_I, ALGR(KC_I)),
    [TD_O] = ACTION_TAP_DANCE_DOUBLE(KC_O, ALGR(KC_O)),
    [TD_U] = ACTION_TAP_DANCE_DOUBLE(KC_U, ALGR(KC_U)),
    [TD_INDENT] = ACTION_TAP_DANCE_DOUBLE(LCTL(KC_RBRC), LCTL(KC_LBRC)),
    [TD_SPC_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_ENT),
    [TD_BC_PIPE] = ACTION_TAP_DANCE_DOUBLE(KC_BSLS, LSFT(KC_BSLS)),
    [TD_EQ_PLUS] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, LSFT(KC_EQL)),
    [TD_GRV] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, LSFT(KC_GRV)),
};

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom_white();
    // rgblight_sethsv_noeeprom_lm_d();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}
#endif

void update_led(void) {
    if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
        #ifdef KEYBOARD_SHARED_EP
        rgblight_sethsv_noeeprom_red();
        #endif
    } else {
        switch (biton32(layer_state)) {
            case _DVORAK:
                rgblight_sethsv_noeeprom_white();
                // rgblight_sethsv_noeeprom_lm_d();
                break;
            case _RAISE:
                rgblight_sethsv_noeeprom_teal();
                break;
            case _LOWER:
                rgblight_sethsv_noeeprom_yellow();
                break;
            case _ADJUST:
                rgblight_sethsv_noeeprom_blue();
                break;
            case _FN:
                rgblight_sethsv_noeeprom_purple();
                break;
            case _GAMING:
                rgblight_sethsv_noeeprom_turquoise();
                break;
        }
    }
}

uint32_t layer_state_set_user(uint32_t state) {
    update_led();
    return state;
}

void led_set_user(uint8_t usb_led) {
    update_led();
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_master) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }
    return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8
#define L_FN 16
#define L_GAMING 32

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Capa: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("DVORAK"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("lOWER"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("RAISE"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("FUSION"), false);
            break;
        case L_FN:
            oled_write_ln_P(PSTR("FN"), false);
            break;
        case L_GAMING:
            oled_write_ln_P(PSTR("GAMING"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
    char name = ' ';
        if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
            (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
    if (keycode < 60) {
        name = code_to_name[keycode];
    }

    // update keylog
    snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
            record->event.key.row, record->event.key.col,
            keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_master) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }
    // switch (keycode) {
    //     case KC_CAPS:
    //     if (record->event.pressed) {
    //         rgblight_sethsv_noeeprom_red();
    //     } else {
    //     }
    //     return true;
    // }

    return true;
}
#endif // OLED_DRIVER_ENABLE