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
                                KC_LGUI, LT(1, KC_ESC), LT(2, KC_SPC),     KC_ENT, LT(3, KC_BSPC),  LT(4, KC_DEL)
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
    ,

    [4] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RU_YO,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   RU_HA,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, RU_HARD, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            _______, _______, _______,    _______, _______, _______
                                        //`--------------------------'  `--------------------------'
    )
};

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

bool wpm_keycode_user(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX) || (keycode >= QK_MODS && keycode <= QK_MODS_MAX)) {
        keycode = keycode & 0xFF;
    } else if (keycode > 0xFF) {
        keycode = 0;
    }
    if (keycode >= KC_A && keycode <= KC_0) {
        return true;
    }

    return false;
}
