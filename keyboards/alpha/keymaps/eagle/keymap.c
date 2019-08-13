#include QMK_KEYBOARD_H

/* DEFINES {{{ */

/* HOME layer */
#define ZCTL MT(MOD_LCTL, KC_Z)
#define XGUI MT(MOD_LGUI, KC_X)
#define CALT MT(MOD_LALT, KC_C)
#define VSYM LT(SYMBOL,   KC_V)
#define SSFT MT(MOD_LSFT, KC_SPC)
#define BNUM LT(NUMBER,   KC_B)
#define NCTL MT(MOD_RCTL, KC_N)
#define MALT MT(MOD_RALT, KC_M)

/* SYMBOL layer */
#define COM_NUM LT(NUMBER, KC_COMM)

/* control-alt-delete */
#define CAD LCTL(LALT(KC_DEL))
/* control-shift-esc */
#define CSE LCTL(LSFT(KC_ESC))

/* }}} */

enum my_layers {
    HOME,
    NUMBER,
    SYMBOL,
    FUNCTION,
};

/* LAYERS {{{ */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     [LAYER] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______,       _______,    _______, _______, _______
     ),
     */
     [HOME] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,   KC_U,     KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,   KC_J,     KC_K,    KC_L,    KC_ENT,
           ZCTL,    XGUI,    CALT,    VSYM,          SSFT,       BNUM,    NCTL,    MALT
     ),

     [NUMBER] = LAYOUT(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
           _______, _______, _______, _______,       _______,    _______, _______, _______
     ),

     [SYMBOL] = LAYOUT(
        KC_TAB, KC_GRV,  XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
        KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SCLN, KC_QUOT, KC_BSPC,
           _______, _______, _______, _______,       _______,    COM_NUM, KC_DOT,  KC_SLSH
     ),

     [FUNCTION] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        CSE,     XXXXXXX, CAD,     RESET,   KC_F6,   KC_F7,   XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,
           _______, _______, _______, _______,       _______,    _______, _______, _______
     ),

};

/* }}} */

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, NUMBER, SYMBOL, FUNCTION);
}
