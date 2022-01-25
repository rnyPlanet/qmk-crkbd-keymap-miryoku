#pragma once

#define MASTER_LEFT

#define USE_SERIAL_PD2

// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 200

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD

#define OLED_TIMEOUT 3000000

#define OLED_FONT_H "keyboards/crkbd/keymaps/soundmonster/glcdfont.c"

#define SPLIT_MODS_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_OLED_ENABLE
