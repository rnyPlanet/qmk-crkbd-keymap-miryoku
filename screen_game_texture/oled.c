#pragma once

#include "progmem.h"
#include "animation.c"

extern uint8_t is_master;

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

void matrix_init_user(void) {
#ifdef OLED_DRIVER_ENABLE
    oled_clear();
#endif
}
void oled_task_user(void) {
    // oled_write_raw_P(games_texture, sizeof games_texture);

    oled_write_raw_P(screen_texture, sizeof screen_texture);
    oled_scroll_left();
}

// TODO: Only the primary MCU seems to be aware of this function: the secondary
// MCU continues animating throughout USB suspend. Maybe there's a way to sync
// state from the primary MCU to the secondary MCU, to work around this
// limitation.
void suspend_power_down_user(void) { oled_off(); }

void suspend_wakeup_init_user(void) { oled_on(); }
