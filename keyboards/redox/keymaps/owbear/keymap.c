#include QMK_KEYBOARD_H
#include QMK_KEYMAP_CONFIG_H

/* Redox layout
 *
 * k00, k01, k02, k03, k04, k05,                          k08, k09, k10, k11, k12, k13
 * k14, k15, k16, k17, k18, k19, k06,                k07, k22, k23, k24, k25, k26, k27
 * k28, k29, k30, k31, k32, k33, k20,                k21, k36, k37, k38, k39, k40, k41
 * k42, k43, k44, k45, k46, k47, k34, k48,      k49, k35, k50, k51, k52, k53, k54, k55
 * k56, k57, k58, k59,    k60,   k61, k62,      k63, k64,   k65,    k66, k67, k68, k69
 *
 */

enum layers
{
    _US,  // Default ASCII
    _SE,  // ASCII with SE
    _SYM, // Symbols
    _SYM_SE, // Symbols except for SE keys
    _NAV, // Navigational
    _SYS  // Random stuff
};

#define _______ KC_TRNS
#define vvvvv /* spacer for non-existant keys */
#define RaltHome RALT_T(KC_HOME)

// Plans/ideas:
// - Remove LALT_T arrow as pressing and holding arrows to scroll seems natural and I never use those Alt
// - Add åäö on ['; on _SYM layer as AltGr on home is a bit difficult to reach
// -- Collorary, make [': available on _SE layer?
// - Hold XCV for cut,copy and paste?
//
// Formatted using :?\[_US\]?,/\<END\>/!column -t
//
// Build: make redox/rev1:owbear && cp .build/redox_rev1_owbear.hex /mnt/tmp/qmk/
// Burn: timeout 3 && \bin\qmk_flash.bat redox_rev1_owbear.hex

const            uint16_t  PROGMEM        keymaps[]         [ MATRIX_ROWS ]  [ MATRIX_COLS ]  =
{
[_US]             =         LAYOUT(
LT(_NAV,KC_GRV),  KC_F1,    KC_F2,         KC_F3,         KC_F4,         KC_F5,        vvvvv      vvvvv     vvvvv   vvvvv     vvvvv              KC_F8,        KC_F9,         KC_F10,        KC_MINS,  KC_EQL,      TT(_NAV),
KC_TAB,           KC_Q,     KC_W,          KC_E,          KC_R,          KC_T,         KC_F6,     vvvvv     vvvvv   vvvvv     KC_F7,             KC_Y,         KC_U,          KC_I,          KC_O,     KC_P,        KC_LBRC,
KC_LGUI,          KC_A,     KC_S,          LALT_T(KC_D),  LCTL_T(KC_F),  KC_G,         KC_LBRC,   vvvvv     vvvvv   vvvvv     KC_RBRC,           KC_H,         RCTL_T(KC_J),  LALT_T(KC_K),  KC_L,     KC_SCLN,     RGUI_T(KC_QUOT),
KC_LSFT,          KC_Z,     KC_X,          KC_C,          KC_V,          KC_B,         RaltHome,  KC_END,   vvvvv   KC_PGUP,  LT(_NAV,KC_PGDN),  KC_N,         KC_M,          KC_COMM,       KC_DOT,   KC_SLSH,     RSFT_T(KC_BSLS),
LCTL_T(KC_ESC),   KC_LCTL,  KC_LEFT,       KC_RGHT,       vvvvv          TT(_SYM),     KC_BSPC,   KC_DEL,   vvvvv   KC_ENT,   KC_SPC,            MO(_SYM),     vvvvv          KC_DOWN,       KC_UP,    KC_RCTL,     RCTL_T(KC_ENT)
)
,
[_SE]             =         LAYOUT(
_______,          _______,  _______,       _______,       _______,       _______,      vvvvv      vvvvv     vvvvv   vvvvv     vvvvv              _______,      _______,       _______,       _______,  _______,     _______,
_______,          _______,  _______,       _______,       _______,       _______,      _______,   vvvvv     vvvvv   vvvvv     _______,           _______,      _______,       _______,       _______,  _______,     RALT(KC_W),
_______,          _______,  _______,       _______,       _______,       _______,      _______,   vvvvv     vvvvv   vvvvv     _______,           _______,      _______,       _______,       _______,  RALT(KC_P),  RALT(KC_Q),       //Want__RGUI_T(RALT(KC_Q))
_______,          _______,  _______,       _______,       _______,       _______,      _______,   _______,  vvvvv   _______,  _______,           _______,      _______,       _______,       _______,  _______,     _______,
_______,          _______,  _______,       _______,       vvvvv          MO(_SYM_SE),  _______,   _______,  vvvvv   _______,  _______,           MO(_SYM_SE),  vvvvv          _______,       _______,  _______,     _______
)
,
[_SYM]            =         LAYOUT(
MO(_SYS),         _______,  _______,       _______,       _______,       _______,      vvvvv      vvvvv     vvvvv   vvvvv     vvvvv              _______,      _______,       _______,       KC_F11,   KC_F12,      MO(_SYS),
_______,          KC_EXLM,  KC_AT,         KC_LBRC,       KC_RBRC,       KC_PIPE,      _______,   vvvvv     vvvvv   vvvvv     _______,           KC_PSLS,      KC_7,          KC_8,          KC_9,     KC_PAST,     RALT(KC_W),
_______,          KC_HASH,  KC_DLR,        KC_LPRN,       KC_RPRN,       KC_AMPR,      _______,   vvvvv     vvvvv   vvvvv     _______,           KC_PMNS,      KC_4,          KC_5,          KC_6,     RALT(KC_P),  RALT(KC_Q),
_______,          KC_PERC,  KC_CIRC,       KC_LCBR,       KC_RCBR,       KC_TILD,      TG(_SE),   _______,  vvvvv   _______,  _______,           KC_PPLS,      KC_1,          KC_2,          KC_3,     KC_PENT,     KC_NO,
_______,          _______,  _______,       _______,       vvvvv          _______,      _______,   _______,  vvvvv   _______,  _______,           KC_0,         vvvvv          _______,       KC_PDOT,  KC_PENT,     KC_APP
)
,
[_SYM_SE]         =         LAYOUT(
_______,          _______,  _______,       _______,       _______,       _______,      vvvvv      vvvvv     vvvvv   vvvvv     vvvvv              _______,      _______,       _______,       _______,  _______,     _______,
_______,          _______,  _______,       _______,       _______,       _______,      _______,   vvvvv     vvvvv   vvvvv     _______,           _______,      _______,       _______,       _______,  _______,     KC_LBRC,
_______,          _______,  _______,       _______,       _______,       _______,      _______,   vvvvv     vvvvv   vvvvv     _______,           _______,      _______,       _______,       _______,  KC_SCLN,     RGUI_T(KC_QUOT),
_______,          _______,  _______,       _______,       _______,       _______,      _______,   _______,  vvvvv   _______,  _______,           _______,      _______,       _______,       _______,  _______,     _______,
_______,          _______,  _______,       _______,       vvvvv          _______,      _______,   _______,  vvvvv   _______,  _______,           _______,      vvvvv          _______,       _______,  _______,     _______
)
,
[_NAV]            =         LAYOUT(
_______,          _______,  _______,       _______,       _______,       _______,      vvvvv      vvvvv     vvvvv   vvvvv     vvvvv              _______,      _______,       _______,       _______,  _______,     _______,
KC_NO,            RESET,    KC_MS_U,       KC_NO,         KC_WH_U,       KC_NO,        _______,   vvvvv     vvvvv   vvvvv     _______,           KC_NO,        KC_NO,         KC_NO,         KC_NO,    KC_NO,       KC_NO,
KC_NO,            KC_MS_L,  KC_MS_D,       KC_MS_R,       KC_WH_D,       KC_NO,        _______,   vvvvv     vvvvv   vvvvv     _______,           KC_LEFT,      KC_DOWN,       KC_UP,         KC_RGHT,  KC_NO,       KC_NO,
KC_NO,            KC_NO,    LSFT(KC_DEL),  LCTL(KC_INS),  LSFT(KC_INS),  KC_NO,        _______,   _______,  vvvvv   _______,  KC_NO,             KC_NO,        KC_NO,         KC_NO,         KC_NO,    KC_NO,       KC_NO,
KC_NO,            KC_NO,    KC_NO,         KC_NO,         vvvvv          KC_BTN1,      KC_BTN2,   _______,  vvvvv   _______,  _______,           KC_NO,        vvvvv          KC_NO,         KC_NO,    KC_NO,       KC_NO
)
,
[_SYS]            =         LAYOUT(
KC_NO,            KC_NO,    KC_NO,         KC_NO,         KC_NO,         KC_NO,        KC_NO,     KC_NO,    KC_NO,  KC_NO,    KC_NO,             KC_NO,        KC_NO,         RESET,         RGB_M_P,  RGB_TOG,     RGB_MOD,          RGB_HUD,  KC_NO,  KC_NO,  RGB_SAI,            RGB_VAD,  RGB_VAI,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_TRNS,  KC_NO,  KC_NO,  KC_TRNS,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO
)
};
/*END*/
