#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST
};


#define EISU LALT(KC_GRV)
#define ALFRED LALT(KC_SPC)
#define SCNSHT SGUI(KC_4)

#define HIGH LT(_RAISE, KC_LANG1)
#define LOW LT(_LOWER, KC_LANG2)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   -  |                    |   =  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |   [  |                    |   ]  |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |ALFRED|                    | EISU |   N  |   M  |   ,  |   .  |   /  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | ESC  |  Adj |      |  Alt |||||||| Lower|  GUI |Space |||||||| Enter|  BS  | Raise|||||||| Left | Down |  Up  | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MINS,                        KC_EQL , KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC,                        KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    ALFRED,                         EISU,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
  	KC_ESC,  ADJUST,  KC_LANG2,KC_LALT,          LOW,     KC_LGUI, KC_SPC,        KC_ENT, KC_BSPC, HIGH,             KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |   `  |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |   1  |   2  |   3  |   4  |   5  |   {  |                    |   }  |   -  |   =  |      |   [  |   ]  |   "  |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |   6  |   7  |   8  |   9  |   0  |  ESC |                    | EISU |  ESC |      |   <  |   >  |   ?  |  Alt |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      |||||||| Lower|      |      ||||||||      |  DEL | Raise|||||||| Home | End  |PageUp|PageDn|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    KC_GRV , KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_UNDS,                        KC_PLUS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LCBR,                        KC_RCBR, KC_MINS, KC_EQL,  KC_NO,   KC_LBRC, KC_RBRC, KC_DQT,  \
    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_ESC,                         EISU,    KC_ESC,  KC_NO,   KC_LT,   KC_GT,   KC_QUES, KC_RALT, \
    _______, _______, _______, _______,          LOWER,   _______, _______,      _______, KC_DEL,  RAISE,            KC_HOME, KC_END,  KC_PGUP, KC_PGDN  \
  ),

  /* Raise
  * ,----------------------------------------------------------------------------------------------------------------------.
  * |   ~  |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
  * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
  * |      |   F1 |   F2 |   F3 |   F4 |   F5 |  F6  |                    |      |   _  |   +  |  Up  |      |      |      |
  * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
  * |      |   F7 |   F8 |   F9 |  F10 |  F11 |  F12 |                    |      |      | Left | Down | Right|  ESC |  Alt |
  * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
  * |      |      |      |      |||||||| Lower|      |      ||||||||      |  DEL | Raise|||||||| Home | End  |PageUp|PageDn|
  * ,----------------------------------------------------------------------------------------------------------------------.
  */
  [_RAISE] = LAYOUT(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_UNDS,                        KC_PLUS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                          _______, KC_UNDS, KC_PLUS, KC_UP  , _______, _______, _______, \
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11 , KC_F12,                         _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_ESC,  KC_RALT, \
    _______, _______, _______, _______,          LOWER,   _______, _______,      _______, KC_DEL,  RAISE,            KC_HOME, KC_END,  KC_PGUP, KC_PGDN  \
    ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, RESET  , _______, _______, _______, _______, _______,                        _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, \
    _______, _______, _______, _______, SCNSHT,  _______, _______,                        _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_MUTE, KC_MPLY, KC_VOLD, KC_VOLU, _______, _______,                        _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______, _______, KC_SLEP,      _______, _______, _______,          _______, _______, _______, _______  \
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
