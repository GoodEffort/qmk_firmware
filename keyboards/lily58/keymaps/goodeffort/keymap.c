#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |Bspace|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LSHFT |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  Home |    |  Mute |------+------+------+------+------+------|
 * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | CAPS | LAlt |LOWER | /Space  /       \Enter \  |RAISE |Delete| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

/* [_QWERTY] = LAYOUT( \
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV, \
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_LSFT, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LCTRL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_HOME,  KC_MUTE,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, \
                             KC_CAPS, KC_LALT,LOWER, KC_SPC,        KC_ENT,   RAISE,   KC_DEL, KC_RGUI \
),*/
 [_QWERTY] = LAYOUT( \
  KC_GRV,   KC_0,   KC_9,    KC_8,    KC_7,    KC_6,                     KC_5,    KC_4,    KC_3,    KC_2,    KC_1,    KC_ESC, \
  KC_BSPC,   KC_P,   KC_O,    KC_I,    KC_U,    KC_Y,                     KC_T,    KC_R,    KC_E,    KC_W,    KC_Q,    KC_TAB, \
  KC_QUOT, KC_SCLN,   KC_L,    KC_K,    KC_J,    KC_H,                     KC_G,    KC_F,    KC_D,    KC_S,    KC_A, KC_LSFT, \
  KC_RSFT,  KC_SLSH, KC_DOT,    KC_COMM,    KC_M,  KC_N,  KC_MUTE, KC_HOME,    KC_B,    KC_V,    KC_C,   KC_X,  KC_Z,KC_LCTRL, \
                             KC_RGUI, KC_DEL, RAISE, KC_ENT,             KC_SPC,LOWER, KC_LALT,KC_CAPS \
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |      |      |      |      |      |                    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |      |  Up  |      |      | PgUp |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LSHFT | Left | Down |Right |      | PgDn |-------.    ,-------|      |   _  |   +  |   {  |   }  |   |  |
 * |------+------+------+------+------+------|   End |    | calc  |------+------+------+------+------+------|
 * |LCTRL |      |      |      |      |      |-------|    |-------|      |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | CAPS | LAlt |LOWER | /Space  /       \Enter \  |RAISE |Delete| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
/*[_LOWER] = LAYOUT( \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,\
  _______, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX, KC_PGUP,                        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, KC_PGDN,                        XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_END, KC_CALCULATOR, XXXXXXX, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
                             _______, _______, _______, _______,      _______,  _______, _______, _______\
),*/
[_LOWER] = LAYOUT( \
  KC_F6,   KC_F5,   KC_F4,   KC_F3,   KC_F2,                        KC_F1, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,_______,\
  KC_F12,  KC_F11,   KC_F10,   KC_F9,   KC_F8,                        KC_F7, KC_PGUP, XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX,_______, \
  KC_PIPE, KC_RCBR, KC_LCBR, KC_PLUS, KC_UNDS,                        XXXXXXX, KC_PGDN, XXXXXXX, KC_RGHT, KC_DOWN, KC_LEFT,_______, \
  KC_BSLS, KC_RBRC,  KC_LBRC, KC_EQL, KC_MINS, XXXXXXX, KC_CALCULATOR, KC_END, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,_______, \
                             _______, _______,  _______,      _______, _______, _______, _______,_______\
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |      |      |      |      |      |                    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |      |  Up  |      |      | PgUp |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LSHFT | Left | Down |Right |      | PgDn |-------.    ,-------|      |   _  |   +  |   {  |   }  |   |  |
 * |------+------+------+------+------+------|   End |    |  calc |------+------+------+------+------+------|
 * |LCTRL |      |      |      |      |      |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | CAPS | LAlt |LOWER | /Space  /       \Enter \  |RAISE |Delete| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

/*[_RAISE] = LAYOUT( \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,\
  _______, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX, KC_PGUP,                        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, KC_PGDN,                        XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_END, KC_CALCULATOR, XXXXXXX, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
                             _______, _______, _______, _______,      _______,  _______, _______, _______\
),*/
[_RAISE] = LAYOUT( \
  KC_F6,   KC_F5,   KC_F4,   KC_F3,   KC_F2,                        KC_F1, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,_______,\
  KC_F12,  KC_F11,   KC_F10,   KC_F9,   KC_F8,                        KC_F7, KC_PGUP, XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX,_______, \
  KC_PIPE, KC_RCBR, KC_LCBR, KC_PLUS, KC_UNDS,                        XXXXXXX, KC_PGDN, XXXXXXX, KC_RGHT, KC_DOWN, KC_LEFT,_______, \
  KC_BSLS, KC_RBRC,  KC_LBRC, KC_EQL, KC_MINS, XXXXXXX, KC_CALCULATOR, KC_END, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,_______, \
                             _______, _______,  _______,      _______, _______, _______, _______,_______\
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |Delete| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  /*[_ADJUST] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,\
                             _______, _______, _______, _______, _______,  _______, _______, _______ \
  )*/
  [_ADJUST] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  RGB_VAI, RGB_SAI, RGB_HUI, RGB_TOG, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, \
  RGB_VAD, RGB_SAD, RGB_HUD, RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,\
                             _______, _______, _______, _______, _______,  _______, _______, _______ \
  )
};

int RGB_current_mode;

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
}

void encoder_update_user(uint8_t index, bool clockwise) { if (index == 0) { if (clockwise) { tap_code(KC_VOLD); } else { tap_code(KC_VOLU); } } }

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
//const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);



static void render_logo(void) {
    static const char PROGMEM my_logo[] = {
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c,
      0x42, 0xfd, 0x05, 0x05, 0x05, 0x06, 0x04, 0x04, 0x04, 0x04, 0x3c, 0xfc, 0x84, 0x04, 0x64, 0xe4,
      0xc4, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x06, 0x05, 0x05, 0x05, 0xfd, 0x82, 0x7c,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
      0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
      0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0xff, 0x00, 0x70, 0x30, 0x38, 0x18, 0x1f, 0x7e, 0xf8, 0x18, 0x1f, 0xff, 0xcc, 0x04, 0x07,
      0x3f, 0xfe, 0x06, 0x86, 0xc6, 0xc6, 0x06, 0x06, 0x06, 0x26, 0x36, 0x1c, 0x00, 0xff, 0x00, 0x00,
      0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
      0x80, 0x80, 0x40, 0x40, 0x40, 0x40, 0x40, 0xf0, 0xfc, 0xe0, 0x40, 0x40, 0x40, 0x40, 0xc0, 0x40,
      0x40, 0x40, 0xc0, 0x40, 0x40, 0x40, 0xc0, 0x40, 0x20, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x02, 0x04, 0x04, 0x08, 0x08,
      0x10, 0x10, 0x14, 0x10, 0x12, 0x12, 0x12, 0x12, 0x10, 0x10, 0x10, 0x20, 0x20, 0x20, 0x24, 0x20,
      0x24, 0x24, 0x20, 0x24, 0x20, 0x21, 0x41, 0x41, 0x41, 0x49, 0x51, 0x51, 0x49, 0x41, 0x51, 0x51,
      0x00, 0xff, 0x00, 0x00, 0x70, 0x70, 0xf0, 0xe0, 0xe0, 0xc1, 0x80, 0x80, 0xc7, 0xcf, 0xc0, 0xc0,
      0xc0, 0xc7, 0xc0, 0xc3, 0xc1, 0xc0, 0xc0, 0xc0, 0xe0, 0xe0, 0xc0, 0x00, 0x00, 0xff, 0x00, 0x51,
      0x49, 0x48, 0x48, 0x40, 0x20, 0x20, 0x24, 0x24, 0x28, 0x24, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
      0x24, 0x24, 0x28, 0x20, 0x24, 0x10, 0x10, 0x7f, 0xff, 0x1f, 0x10, 0x10, 0x10, 0x1c, 0x13, 0x10,
      0x10, 0x1c, 0x13, 0x10, 0x10, 0x1c, 0x13, 0x10, 0x18, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e,
      0x42, 0xbf, 0xa0, 0xa0, 0xa0, 0x60, 0x20, 0x20, 0x20, 0x21, 0x21, 0x23, 0x27, 0x26, 0x2c, 0x28,
      0x28, 0x20, 0x20, 0x20, 0x21, 0x21, 0x21, 0x21, 0x21, 0x61, 0xa1, 0xa0, 0xa0, 0xbf, 0x42, 0x3c,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    oled_write_raw_P(my_logo, sizeof(my_logo));
}

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    //oled_write(read_logo(), false);
    render_logo();
  }
}
#endif // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
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
