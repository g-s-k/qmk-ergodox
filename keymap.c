#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define FNCS 1 // F-keys and numpad
#define SCUT 2 // shortcuts
#define LGHT 3 // RGB control keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  GO_ERRSEQ,
  JS_ARROW,
  REACT_PROPS,
  JS_RETOBJ,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_ergodox(  // layer 0: default
/*-----------------------------------------------------------------------------------------------------.
 |*/KC_EQL, /*      |*/KC_1,/*         |*/KC_2,/*   |*/KC_3,/*   |*/KC_4,/*   |*/KC_5,/*|*/TT(SCUT),/* |
 |*/KC_DELT,/*      |*/KC_Q,/*         |*/KC_W,/*   |*/KC_E,/*   |*/KC_R,/*   |*/KC_T,/*|*/TT(FNCS),/* |
 |*/LCTL(KC_LSFT),/*|*/KC_A,/*         |*/KC_S,/*   |*/KC_D,/*   |*/KC_F,/*   |*/KC_G,/*|--------------|
 |*/KC_LCTL,/*      |*/KC_Z,/*         |*/KC_X,/*   |*/KC_C,/*   |*/KC_V,/*   |*/KC_B,/*|*/GO_ERRSEQ,/*|
 |*/KC_GRV,/*       |*/LCTL(KC_LALT),/*|*/KC_LSFT,/*|*/KC_LEFT,/*|*/KC_RGHT,/*|------------------------'
 `----------------------------------------------------------------------------'*/
/*           ,-------------------------.
             |*/KC_APP, /*|*/KC_LGUI,/*|
 ,-----------+------------|*/KC_HOME,/*|
 |*/KC_SPC,/*|*/KC_BSPC,/*|*/KC_END, /*|
 `-------------------------------------'*/
/*-----------------------------------------------------------------------------------------.
 |*/TT(LGHT),/*|*/KC_6,/*|*/KC_7,/* |*/KC_8,/*   |*/KC_9,/*   |*/KC_0,/*   |*/KC_MINS,/*   |
 |*/TT(FNCS),/*|*/KC_Y,/*|*/KC_U,/* |*/KC_I,/*   |*/KC_O,/*   |*/KC_P,/*   |*/KC_BSLS,/*   |
 |-------------|*/KC_H,/*|*/KC_J,/* |*/KC_K,/*   |*/KC_L,/*   |*/KC_SCLN,/*|*/KC_QUOT,/*   |
 |*/KC_TAB,/*  |*/KC_N,/*|*/KC_M,/* |*/KC_COMM,/*|*/KC_DOT,/* |*/KC_SLSH,/*|*/KC_LALT,/*   |
 `-----------------------|*/KC_UP,/*|*/KC_DOWN,/*|*/KC_LBRC,/*|*/KC_RBRC,/*|*/LCTL(KC_Z),/*|
                         `-----------------------------------------------------------------'*/
/*------------------------------.
 |*/LALT(KC_SPC),/*|*/KC_ESC,/* |
 |*/KC_PGUP,/*     |------------+----------.
 |*/KC_PGDN,/*     |*/KC_LSFT,/*|*/KC_ENT/*|
 `----------------------------------------'*/
    ),

[FNCS] = LAYOUT_ergodox( // layer 1: F-keys and numpad
/*------------------------------------------------------------------------------------------.
 |*/VRSN,/*   |*/KC_F1,/*  |*/KC_F2,/*  |*/KC_F3,/*  |*/KC_F4,/*  |*/KC_F5,/*  |*/_______,/*|
 |*/_______,/*|*/KC_F6,/*  |*/KC_F7,/*  |*/KC_F8,/*  |*/KC_F9,/*  |*/KC_F10,/* |*/_______,/*|
 |*/_______,/*|*/KC_F11,/* |*/KC_F12,/* |*/KC_LALT,/*|*/KC_ENT,/* |*/XXXXXXX,/*|------------|
 |*/_______,/*|*/XXXXXXX,/*|*/XXXXXXX,/*|*/XXXXXXX,/*|*/XXXXXXX,/*|*/XXXXXXX,/*|*/_______,/*|
 |*/EPRM,/*   |*/_______,/*|*/_______,/*|*/_______,/*|*/_______,/*|-------------------------'
 `----------------------------------------------------------------'*/
/*            ,-------------------------.
              |*/_______,/*|*/_______,/*|
 ,------------+------------|*/_______,/*|
 |*/_______,/*|*/_______,/*|*/_______,/*|
 `--------------------------------------'*/
/*-------------------------------------------------------------------------------------------.
 |*/_______,/*|*/XXXXXXX,/*|*/KC_7,/*   |*/KC_8,/*   |*/KC_9,/*   |*/KC_PERC,/*|*/_______,/* |
 |*/_______,/*|*/KC_RGHT,/*|*/KC_4,/*   |*/KC_5,/*   |*/KC_6,/*   |*/KC_ASTR,/*|*/_______,/* |
 |------------|*/KC_LEFT,/*|*/KC_1,/*   |*/KC_2,/*   |*/KC_3,/*   |*/_______,/*|*/KC_EQUAL,/*|
 |*/_______,/*|*/XXXXXXX,/*|*/KC_0,/*   |*/_______,/*|*/_______,/*|*/_______,/*|*/KC_PLUS,/* |
 `-------------------------|*/_______,/*|*/_______,/*|*/_______,/*|*/_______,/*|*/_______,/* |
                           `-----------------------------------------------------------------'*/
/*-------------------------.
 |*/_______,/*|*/_______,/*|
 |*/_______,/*|------------+-----------.
 |*/_______,/*|*/_______,/*|*/_______/*|
 `--------------------------------------'*/
),

[SCUT] = LAYOUT_ergodox(
       _______, _______, _______, _______, LCTL(KC_C), LCTL(KC_V), _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______,  _______,  _______,     _______,   _______, _______, _______,
       _______,  _______,  _______,     _______,   _______, _______, _______,
                 JS_ARROW, REACT_PROPS, JS_RETOBJ, _______, _______, _______,
       _______,  _______,  _______,     _______,   _______, _______, _______,
                           _______,     _______,   _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),

[LGHT] = LAYOUT_ergodox( // layer 3: RGB controls
                        _______, _______, _______, _______, _______, _______, _______,
                        _______, _______, _______, _______, _______, _______, _______,
                        _______, _______, _______, _______, _______, _______,
                        _______, _______, _______, _______, _______, _______, _______,
                        _______, _______, _______, _______, _______,

                        RGB_MOD, _______,
                        _______,
                        RGB_VAD,RGB_VAI,_______,

                        _______, _______, _______, _______, _______, _______, _______,
                        _______, _______, _______, _______, _______, _______, _______,
                        _______, _______, _______, _______, _______, _______,
                        _______, _______, _______, _______, _______, _______, _______,
                        _______, _______, _______, _______, _______,

                        RGB_TOG, RGB_SLD,
                                          _______,
                        _______, RGB_HUD, RGB_HUI
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(FNCS)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
    case GO_ERRSEQ:
      if (record->event.pressed) {
        SEND_STRING ("if err != nil {\n");
      }
      return false;
      break;
    case JS_ARROW:
      if (record->event.pressed) {
        SEND_STRING ("() => {\n");
      }
      return false;
      break;
    case REACT_PROPS:
      if (record->event.pressed) {
        SEND_STRING ("{...this.props}");
      }
      return false;
      break;
    case JS_RETOBJ:
      if (record->event.pressed) {
        SEND_STRING ("return {\nkey: i," SS_TAP(X_DOWN) ";" SS_TAP(X_UP)
                     SS_TAP(X_END) "\n");
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};
