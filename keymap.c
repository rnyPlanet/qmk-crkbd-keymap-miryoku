#include QMK_KEYBOARD_H
#include <stdio.h>
#include <keymap_russian.h>

#ifdef OLED_DRIVER_ENABLE
#    include "oled.c"
#endif

#define XXXXXXX KC_NO
#define _______ KC_TRNS

#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)
#define HOME_J LSFT_T(KC_J)
#define HOME_K LCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)

enum {
    TD_LSFT_CAPS,
};
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for shift, twice for Caps Lock
    [TD_LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};

#define TD_LSFT_CAPS TD(TD_LSFT_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    TD_LSFT_CAPS,   KC_A,  HOME_S,  HOME_D,  HOME_F,    KC_G,                         KC_H,  HOME_J,  HOME_K,  HOME_L, KC_SCLN, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                KC_LGUI, LT(1, KC_ESC), LT(2, KC_SPC),     KC_ENT, LT(3, KC_BSPC),  KC_DEL
                                        //`--------------------------'  `--------------------------'
    ),

    [1] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      KC_CAPS, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_INS, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, _______,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            _______, _______, _______,    _______, _______, _______
                                        //`--------------------------'  `--------------------------'
    ),

    [2] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        _______,  KC_GRV, XXXXXXX, XXXXXXX, KC_MINS, XXXXXXX,                      XXXXXXX,  KC_EQL, XXXXXXX, XXXXXXX, KC_BSLS, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, XXXXXXX,                      XXXXXXX, KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            _______, _______, _______,    _______, _______, _______
                                        //`--------------------------'  `--------------------------'
    ),

    [3] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        _______,  KC_F12,   KC_F7,   KC_F8,   KC_F9, KC_PSCR,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______,  KC_F11,   KC_F4,   KC_F5,   KC_F6, KC_SLCK,                      XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______,  KC_F10,   KC_F1,   KC_F2,   KC_F3, KC_PAUS,                      XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            _______, _______, _______,    _______, _______, _______
                                        //`--------------------------'  `--------------------------'
    )
};

// void oled_render_logo(void) {
//     static const char PROGMEM turkey_flag[] = {
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x80, 0x80, 0xc0, 0xc0, 0xe0, 0xe0, 0xe0,
//         0xf0, 0xf0, 0xf0, 0xf8, 0xf8, 0xf8, 0xf8,
//         0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfe,
//         0xfe, 0xfe, 0xfe, 0xfe, 0x7e, 0x7e, 0x7e,
//         0x3f, 0x3f, 0x3f, 0x3f, 0x1f, 0x1f, 0x1f,
//         0x1f, 0x1f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
//         0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x07,
//         0x07, 0x07, 0x07, 0x07, 0x07, 0x06, 0x06,
//         0x06, 0x06, 0x0e, 0x0e, 0x0e, 0x0e, 0x0c,
//         0x0c, 0x0c, 0x0c, 0x0c, 0x08, 0x18, 0x18,
//         0x18, 0x10, 0x10, 0x30, 0x20, 0x20, 0x20,
//         0x40, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xfc, 0xfe,
//         0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//         0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//         0xff, 0xff, 0xff, 0x3f, 0x0f, 0x07, 0x07,
//         0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
//         0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xfe, 0xfe,
//         0xfe, 0xfc, 0xfc, 0xfc, 0xf8, 0xf8, 0xf0,
//         0xf0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xf0,
//         0xf0, 0xf0, 0xf0, 0x70, 0x70, 0x30, 0x30,
//         0x10, 0x18, 0x08, 0x08, 0x03, 0x0f, 0x1f,
//         0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff,
//         0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//         0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf0,
//         0xe0, 0xe0, 0xc0, 0x80, 0x80, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
//         0x01, 0x01, 0x01, 0x01, 0x03, 0x03, 0x03,
//         0x7f, 0x7f, 0x7f, 0x3f, 0x3f, 0x1f, 0x1f,
//         0x1f, 0x0f, 0x0f, 0x07, 0x07, 0x07, 0x07,
//         0x07, 0x0f, 0x0f, 0x0f, 0x0f, 0x0e, 0x0e,
//         0x0c, 0x0c, 0x08, 0x18, 0x10, 0x10, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
//         0x01, 0x03, 0x03, 0x07, 0x07, 0x07, 0x0f,
//         0x0f, 0x0f, 0x0f, 0x1f, 0x1f, 0x1f, 0x3f,
//         0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x7f, 0x7f,
//         0x7f, 0x7f, 0x7f, 0x7e, 0x7e, 0x7e, 0xfc,
//         0xfc, 0xfc, 0xfc, 0xf8, 0xf8, 0xf8, 0xf8,
//         0xf8, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0,
//         0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xe0, 0xe0,
//         0xe0, 0xe0, 0xe0, 0xe0, 0x60, 0x60, 0x60,
//         0x60, 0x70, 0x70, 0x70, 0x70, 0x30, 0x30,
//         0x30, 0x30, 0x30, 0x10, 0x18, 0x18, 0x18,
//         0x08, 0x08, 0x0c, 0x04, 0x04, 0x04, 0x02,
//         0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00
//     };
//     oled_write_raw_P(turkey_flag, sizeof(turkey_flag));
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_ESC:
            // Detect the activation of only Left Alt
            if ((get_mods() & MOD_BIT(KC_LALT)) == MOD_BIT(KC_LALT)) {
                if (record->event.pressed) {
                    // No need to register KC_LALT because it's already active.
                    // The Alt modifier will apply on this KC_TAB.
                    register_code(KC_TAB);
                } else {
                    unregister_code(KC_TAB);
                }
                // Do not let QMK process the keycode further
                return false;
            }
            // Else, let QMK process the KC_ESC keycode as usual
            return true;
        case KC_T:
            if ((get_mods() & MOD_BIT(KC_LALT)) == MOD_BIT(KC_LALT)) {
                unregister_code(KC_LALT);
                if (record->event.pressed) {
                    register_code(RU_YO);
                }
                unregister_code(RU_YO);
                register_code(KC_LALT);
                return false;
            }
            // unregister_code(RU_YO);
            return true;
        case KC_M:
            if ((get_mods() & MOD_BIT(KC_LALT)) == MOD_BIT(KC_LALT)) {
                unregister_code(KC_LALT);
                if (record->event.pressed) {
                    register_code(RU_HARD);
                }
                unregister_code(RU_HARD);
                register_code(KC_LALT);
                return false;
            }
            return true;
        case KC_BSPC:
            if ((get_mods() & MOD_BIT(KC_LALT)) == MOD_BIT(KC_LALT)) {
                unregister_code(KC_LALT);
                if (record->event.pressed) {
                    register_code(RU_HA);
                }
                unregister_code(RU_HA);
                register_code(KC_LALT);
                return false;
            }
            return true;

         /* KEYBOARD PET STATUS START */

        case KC_LCTL:
        case KC_RCTL:
            if (record->event.pressed) {
                isSneaking = true;
            } else {
                isSneaking = false;
            }
            break;
        case KC_SPC:
            if (record->event.pressed) {
                isJumping = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
            break;

        /* KEYBOARD PET STATUS END */
    }

    return true;
}