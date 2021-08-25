#pragma once

#include "progmem.h"
#include "animation.c"

extern uint8_t is_master;

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }
    return rotation;
}

// Used to draw on to the oled screen
void oled_task_user(void) {
    render_anim();  // renders pixelart

    oled_set_cursor(0, 0);                            // sets cursor to (row, column) using charactar spacing (5 rows on 128x32 screen, anything more will overflow back to the top)
    sprintf(wpm_str, "WPM:%03d", get_current_wpm());  // edit the string to change wwhat shows up, edit %03d to change how many digits show up
    oled_write(wpm_str, false);                       // writes wpm on top left corner of string

    led_t led_state = host_keyboard_led_state();  // caps lock stuff, prints CAPS on new line if caps led is on
    oled_set_cursor(0, 1);
    oled_write_P(led_state.caps_lock ? PSTR("CAPS") : PSTR("       "), false);
}
