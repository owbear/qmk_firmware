// vi: colorcolumn=0
#include QMK_KEYBOARD_H
#include QMK_KEYMAP_CONFIG_H

enum layers
{
    _US,  // Default ASCII
    //_SE,  // ASCII with SE
    _SYM, // Symbols
    _NAV, // Navigational
    _SYS, // Random stuff
    _PAD  // Not used
};

#define ____ KC_TRNS
#define _____ KC_TRNS
#define ______ KC_TRNS
#define _______ KC_TRNS
#define ________ KC_TRNS
#define _________ KC_TRNS
#define __________ KC_TRNS
#define ____________ KC_TRNS
#define vvvvv
#define RaltHome RALT_T(KC_HOME)

/* _US: plain Qwerty without layer switching
 *         ,---------------. ,---------------. ,---------------.
 *         |F13|F14|F15|F16| |F17|F18|F19|F20| |F21|F22|F23|F24|
 * ,---.   |---------------| |---------------| |---------------| ,-----------. ,---------------. ,-------.
 * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau| |VDn|VUp|Mut|Pwr| | Help  |
 * `---'   `---------------' `---------------' `---------------' `-----------' `---------------' `-------'
 * ,-----------------------------------------------------------. ,-----------. ,---------------. ,-------.
 * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|JPY|Bsp| |Ins|Hom|PgU| |NmL|  /|  *|  -| |Stp|Agn|
 * |-----------------------------------------------------------| |-----------| |---------------| |-------|
 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | |Del|End|PgD| |  7|  8|  9|  +| |Mnu|Und|
 * |-----------------------------------------------------------| `-----------' |---------------| |-------|
 * |CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  :|  #|Retn|               |  4|  5|  6|KP,| |Sel|Cpy|
 * |-----------------------------------------------------------|     ,---.     |---------------| |-------|
 * |Shft|  <|  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /| RO|Shift |     |Up |     |  1|  2|  3|KP=| |Exe|Pst|
 * |-----------------------------------------------------------| ,-----------. |---------------| |-------|
 * |Ctl|Gui|Alt|MHEN|HNJ| Space  |H/E|HENK|KANA|Alt|Gui|App|Ctl| |Lef|Dow|Rig| |  0    |  .|Ent| |Fnd|Cut|
 * `-----------------------------------------------------------' `-----------' `---------------' `-------'
 */

/* ,---.   ,---------------. ,---------------. ,---------------. ,-----------.
 * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau|
 * `---'   `---------------' `---------------' `---------------' `-----------'
 * ,-----------------------------------------------------------. ,-----------. ,---------------.
 * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|    Bsp| |Ins|Hom|PgU| |NmL|  /|  *|  -|
 * |-----------------------------------------------------------| |-----------| |---------------|
 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | |Del|End|PgD| |  7|  8|  9|  +|
 * |-----------------------------------------------------------| `-----------' |-----------|   |
 * |CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  Return|               |  4|  5|  6|  +|
 * |-----------------------------------------------------------|     ,---.     |---------------|
 * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /|Shift     |     |Up |     |  1|  2|  3|   |
 * |-----------------------------------------------------------| ,-----------. |-----------|   |
 * |Ctl|Gui|Alt|           Space               |Alt|Gui|App|Ctl| |Lef|Dow|Rig| |      0|  .|Ent|
 * `-----------------------------------------------------------' `-----------' `---------------'
 */

/* Original:
    LAYOUT_ansi(
    KC_ESC,           KC_F1,   KC_F2,  KC_F3,    KC_F4,  KC_F5,  KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,    KC_F12,        KC_PSCR, KC_SLCK, KC_PAUS,
    KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,     KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,    KC_BSPC,       KC_INS,  KC_HOME, KC_PGUP,      KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
    KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,     KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,   KC_BSLS,       KC_DEL,  KC_END,  KC_PGDN,      KC_P7,   KC_P8,   KC_P9,
    KC_CAPS, KC_A,    KC_S,    KC_D,   KC_F,     KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,            KC_ENT,                                        KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
    KC_LSFT,          KC_Z,    KC_X,   KC_C,     KC_V,   KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,            KC_RSFT,                  KC_UP,               KC_P1,   KC_P2,   KC_P3,
    KC_LCTL, KC_LGUI, KC_LALT,          KC_SPC,                                            KC_RALT, KC_RGUI, KC_APP,    KC_RCTL,       KC_LEFT, KC_DOWN, KC_RGHT,      KC_P0,   KC_PDOT, KC_PENT
    ),
*/

// Tap Dance Declarations
 enum {
   TD_X_CUT = 0,
   TD_C_COPY = 1,
   TD_V_PASTE = 2,
 };

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_X_CUT]   = ACTION_TAP_DANCE_DOUBLE(KC_X, LSFT(KC_DEL)),
    [TD_C_COPY]  = ACTION_TAP_DANCE_DOUBLE(KC_C, LCTL(KC_INS)),
    [TD_V_PASTE] = ACTION_TAP_DANCE_DOUBLE(KC_V, LSFT(KC_INS)),
};

// Build: make converter/usb_usb:owbear_kinesis_advantage && cp .build/converter_usb_usb_hasu_owbear_kinesis_advantage.hex /mnt/tmp/qmk/
// Burn: timeout 3 && \bin\qmk_flash.bat converter_usb_usb_hasu_owbear_kinesis_advantage.hex

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_US] = LAYOUT_ansi(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,        KC_F4,          KC_F5,  KC_F6,  KC_F7,        KC_F8,         KC_F9,   KC_F10,   KC_F11,          KC_F12,                                                  KC_PSCR, KC_SLCK, KC_PAUS,
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,        KC_F4,          KC_F5,  KC_F6,  KC_F7,        KC_F8,         KC_F9,   KC_F10,   KC_NO,           KC_ESC,    KC_BSPC,       KC_INS,  RaltHome, KC_PGUP,    KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
    KC_TAB,  KC_Q,    KC_W,    KC_E,         KC_R,           KC_T,   KC_Y,   KC_U,         KC_I,          KC_O,    KC_P,     KC_LBRC,         KC_RBRC,   KC_NO,         KC_DEL,  KC_END,  KC_PGDN,     KC_P7,   KC_P8,   KC_P9,
    KC_LGUI, KC_A, LSFT_T(KC_S), LALT_T(KC_D), LCTL_T(KC_F),   KC_G,   KC_H,   RCTL_T(KC_J), LALT_T(KC_K), RSFT_T(KC_L), RGUI_T(KC_SCLN),  KC_QUOT, KC_ENT,                                            KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
    KC_LSFT, KC_Z,  TD(TD_X_CUT), TD(TD_C_COPY), TD(TD_V_PASTE), KC_B, KC_N,   KC_M,         KC_COMM,       KC_DOT,  KC_SLSH,  RSFT_T(KC_BSLS),                                   KC_DOWN,             KC_P1,   KC_P2,   KC_P3,
    TT(_SYM), KC_LGUI, KC_LALT,                      KC_SPC,                                               KC_RALT, KC_RGUI, KC_APP,          TT(_SYM),                KC_LEFT, KC_UP, KC_RGHT,        KC_P0,   KC_PDOT, KC_PENT
    ),

    [_SYM] = LAYOUT_ansi(
    ______,  _____,   _____,   _____,        _____,          _____,    _____,  _____,        _____,         _____,   ______,   ______,          ______,                                                  _______, _______, ________,
    ______,  _____,   _____,   _____,        _____,          _____,    _____,  _____,        _____,         _____,   ______,   _______,         ______,    _______,       ______,  KC_APP, _______,    _______, _______, _______, ________,
    ______,  KC_EXLM,  KC_AT,   KC_LBRC,     KC_RBRC,        KC_EQL,   KC_PSLS,   KC_7,      KC_8,          KC_9,    KC_PAST,     ____,         ____,   RALT(KC_W),       ______,  ______,  _______,     _____,   _____,   ______,
    _______, KC_HASH,  KC_DLR,    KC_LPRN,   KC_RPRN,        KC_AMPR,  KC_MINS,   KC_4,      KC_5,          KC_6,    RALT(KC_P),  RALT(KC_Q),  ______,                                                  _____,   _____,   _____,   ________,
    KC_CAPS, KC_PERC,   KC_CIRC,   KC_LCBR,  KC_RCBR,        KC_TILD,  KC_PPLS,   KC_1,      KC_2,          KC_3,    KC_UNDS,  ________,                                         _______,               _____,   _____,   ______,
    ________, _______, _______,                      KC_0,                                                _______, _______, ______,          ________,                _______, _____, _______,        _____,   _______, _______
    )

};
