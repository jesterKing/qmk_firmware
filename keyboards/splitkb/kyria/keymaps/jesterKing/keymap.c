/* Copyright 2021 Nathan Letwory <jesterking@letwory.net>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#include "keymap_steno.h"

/*
 * This keymap is set up for QWERTY ISO layout, specifically the Finnish layout.
 *
 * Take a good look at the layout, as it tries to fit the ISO based layout, but
 * clearly some concessions had to be made. The F-key and the Z-key most notably
 * in the default layout.
 */

#include "keymap_finnish.h"

#define ALTDEL  MT(MOD_LALT, KC_DEL)
#define RLTBSP  MT(MOD_RALT, KC_BSPC)
#define LO_SPC  LT(_LOWER, KC_SPC)
#define LO_TAB  LT(_LOWER, KC_TAB)
#define HI_SPC  LT(_RAISE, KC_SPC)
#define HI_ESC  LT(_RAISE, KC_ESC)
#define CT_BSP  MT(MOD_LCTL, KC_BSPC)
#define KGUI    KC_LGUI
#define KDEL    KC_DEL
#define KENT    KC_ENT
#define KSPC    KC_SPC
#define KBSP    KC_BSPC

enum jk_unicode_names {
    DEG,
    PI
};

enum my_keycodes { DAS = SAFE_RANGE, QWRT, PLVR };

enum layers {
    _QWERTY = 0,
    _DAS,
    _PLOVER,
    _LOWER,
    _RAISE,
    _ADJUST
};

// Tap Dance declarations
enum {
    TD_LPRN_RPRN,
    TD_LCBR_RCBR,
    TD_LBRC_RBRC,
    TD_PLUS_MIN,
    TD_DIV_MULT,
    TD_Q_Z,
    TD_EQL_AMPR
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LPRN_RPRN] = ACTION_TAP_DANCE_DOUBLE(FI_LPRN, FI_RPRN),
    [TD_LCBR_RCBR] = ACTION_TAP_DANCE_DOUBLE(FI_LCBR, FI_RCBR),
    [TD_LBRC_RBRC] = ACTION_TAP_DANCE_DOUBLE(FI_LBRC, FI_RBRC),
    [TD_PLUS_MIN]  = ACTION_TAP_DANCE_DOUBLE(FI_PLUS, FI_MINS),
    [TD_DIV_MULT]  = ACTION_TAP_DANCE_DOUBLE(FI_SLSH, FI_ASTR),
    [TD_Q_Z]       = ACTION_TAP_DANCE_DOUBLE(FI_Q, FI_Z),
    [TD_EQL_AMPR]  = ACTION_TAP_DANCE_DOUBLE(FI_EQL, FI_AMPR),
};

// Add tap dance item to your keymap in place of a keycode

const uint32_t PROGMEM unicode_map[] = {
    [DEG] = 0x0000b0,  // °
    [PI]  = 0x01d70b   // 𝜋
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Base Layer: QWERTY ISO
     *
     * Changes:
     *  . LSHIFT -> KC_NUBS
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * |RAIS/ESC|   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Å     |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |  <>    |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  |  Ö   |  Ä     |
     * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
     * |Ctrl/BS |   Z  |   X  |   C  |   V  |  B   |LShift|Leader|  |RShift|   ¨  |   N  |   M  |   ,  |   .  |  -   |   '    |
     * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
     *                        | GUI  | Enter| Del  | Space| Esc  |  | Tab  | Space| Bksp | Enter| Alt  |
     *                        |      |      | Alt  | Lower| Raise|  | Lower| Raise| RAlt |      |      |
     *                        `----------------------------------'  `----------------------------------'
     */
    [_QWERTY] = LAYOUT(
        HI_ESC,  FI_Q, FI_W, FI_E, FI_R, FI_T,                                         FI_Y,   FI_U, FI_I,    FI_O,   FI_P,    FI_ARNG,
        KC_NUBS, FI_A, FI_S, FI_D, FI_F, FI_G,                                         FI_H,   FI_J, FI_K,    FI_L,   FI_ODIA, FI_ADIA,
        CT_BSP,  FI_Z, FI_X, FI_C, FI_V, FI_B,   KC_LSFT, KC_LEAD,   KC_RSFT, FI_DIAE, FI_N,   FI_M, FI_COMM, FI_DOT, FI_MINS, FI_QUOT,
                             KGUI, KENT, ALTDEL, LO_SPC,  HI_ESC,    LO_TAB,  HI_SPC,  RLTBSP, KENT, KC_LALT),

/*
 * Layer template
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |RAIS/ESC|   P  |   H  |   R  |  K   |  <>  |                              |  '*  |  W   |  U   |  Y   |  B   |   QZ   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   F    |  S   |   L  |   N  |  T   |  V   |                              |  G   |  A   |  I   |  O   |  E   |   C    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | Ctrl/BS|  X   |   D  |   M  |  J   |  Å   |LShift|Leader|  |RShift|  ?   |  Ö   |  Ä   |  ,;  |  .:  |  -_  |   Z    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | GUI  | Enter| Del  | Space| Esc  |  | Tab  | Space| Bksp | Enter| Alt  |
 *                        |      |      | Alt  | Lower| Raise|  | Lower| Raise| RAlt |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_DAS] = LAYOUT(
        HI_ESC, FI_P, FI_H, FI_R, FI_K, KC_NUBS,                                       FI_QUOT, FI_W,    FI_U,    FI_Y,   FI_B,    TD(TD_Q_Z),
        FI_F,   FI_S, FI_L, FI_N, FI_T, FI_V,                                          FI_G,    FI_A,    FI_I,    FI_O,   FI_E,    FI_C,
        CT_BSP, FI_X, FI_D, FI_M, FI_J, FI_ARNG, KC_LSFT, KC_LEAD,   KC_RSFT, FI_QUES, FI_ODIA, FI_ADIA, FI_COMM, FI_DOT, FI_MINS, FI_Z,
                             KGUI, KENT, ALTDEL, LO_SPC,  HI_ESC,    LO_TAB,  HI_SPC,  RLTBSP, KENT, KC_LALT),

/*
* Plover / Steno
*
* ,-------------------------------------------.                              ,-------------------------------------------.
* |   #1   |  #2  |  #3  |  #4  |  #5  |  #6  |                              |  #7  |  #8  |  #9  |  #A  |  #B  |   #C   |
* |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
* |   Fn   |  S-  |  T-  |  P-  |  H-  |   *  |                              |  *   |  -F  |  -P  |  -L  |  -T  |   -D   |
* |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
* |        |  S-  |  K-  |  W-  |  R-  |   *  |      |      |  |      |      |  *   |  -R  |  -B  |  -G  |  -S  |   -Z   |
* `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
*                        |      |      |  A   |   O  |      |  |      |   E  |   U  |      |      |
*                        |      |      |      |      |      |  |      |      |      |      |      |
*                        `----------------------------------'  `----------------------------------'
*/
   [_PLOVER] = LAYOUT(
     STN_N1,  STN_N2, STN_N3, STN_N4,  STN_N5,  STN_N6,                                      STN_N7,  STN_N8,  STN_N9, STN_NA, STN_NB, STN_NC,
     STN_FN,  STN_S1, STN_TL, STN_PL,  STN_HL,  STN_ST1,                                     STN_ST3, STN_FR,  STN_PR, STN_LR, STN_TR, STN_DR,
     XXXXXXX, STN_S2, STN_KL, STN_WL,  STN_RL,  STN_ST2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, STN_ST4, STN_RR,  STN_BR, STN_GR, STN_SR, STN_ZR,
                              XXXXXXX, XXXXXXX, STN_A,   STN_O,   _______, _______, STN_E,   STN_U,   XXXXXXX, XXXXXXX
   ),

/*
 * Lower Layer: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   \    |  !   |  "   |  @   |  €   |  %   |                              |  []  |  7   |  8   |  9   |  |   |   £    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   §    |  #   |  $   |  =&  |  ¨   |  `   |                              |  ()  |  4   |  5   |  6   |  +-  |  / *   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |   µ    |  ½   |  ¤   |  °   |  ^   |  ~   |      |      |  |      | LAlt |  {}  |  1   |  2   |  3   |  ?   |   𝜋    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |  ;   |  ?   |  |  ;   |      |  0   | Bksp |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_LOWER] = LAYOUT(
      FI_BSLS, FI_EXLM, FI_DQUO, FI_AT,   FI_EURO, FI_PERC,                                     TD(TD_LBRC_RBRC), KC_7, KC_8, KC_9, FI_PIPE,         FI_PND,
      FI_SECT, FI_HASH, FI_DLR,  TD(TD_EQL_AMPR),  FI_DIAE, FI_GRV,                             TD(TD_LPRN_RPRN), KC_4, KC_5, KC_6, TD(TD_PLUS_MIN), TD(TD_DIV_MULT),
      FI_MICR, FI_HALF, FI_CURR, X(DEG),  FI_CIRC, FI_TILD, _______, _______, _______, KC_LALT, TD(TD_LCBR_RCBR), KC_1, KC_2, KC_3, FI_QUES,         X(PI),
                                 _______, _______, _______, FI_SCLN, FI_QUES, FI_SCLN, _______, KC_0, KBSP, _______
    ),
/*
 * Raise Layer: Number keys, media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   1  |  2   |  3   |  4   |  5   |                              |  6   |  7   |  8   |  9   |  0   |  MWUp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      | Prev | Play | Next | VolUp|                              | MUp  | Left | Up   | Right|      |  MMB   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      | Mute | VolDn| LAlt |      |  | LMB  | RMB  | Mdown|MLeft | Down |MRight|      |  MWDn  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_RAISE] = LAYOUT(
      _______, KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,                                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_WH_U,
      _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,                                     KC_MS_U, KC_LEFT, KC_UP,   KC_RGHT, _______, KC_BTN3,
      _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_LALT, _______, KC_BTN1, KC_BTN2, KC_MS_D, KC_MS_L, KC_DOWN, KC_MS_R, _______, KC_WH_D,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Adjust Layer: Function keys, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |UC_M_WC | F1   |  F2  | F3   | F4   | F5   |                              | F6   | F7   |  F8  | F9   | F10  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |UC_M_MA |      |      |      |      |      |                              | DAS  | PLVR | QWRT | F11  | F12  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |UC_M_LN |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      UC_M_WC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  _______,
      UC_M_MA, _______, _______, _______, _______, _______,                                     DAS,     PLVR,     QWRT,    KC_F11,  KC_F12,  _______,
      UC_M_LN, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______
    ),
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


bool process_record_user(uintptr_t keycode, keyrecord_t *record)
{
    bool is_mac = get_unicode_input_mode() == UC_MAC;

    switch (keycode)
    {
    case DAS:
        if(record->event.pressed)
        {
            set_single_persistent_default_layer(_DAS);
        }
        return false;
    case QWRT:
        if(record->event.pressed)
        {
            set_single_persistent_default_layer(_QWERTY);
        }
        return false;
    case PLVR:
        if(record->event.pressed)
        {
            set_single_persistent_default_layer(_PLOVER);
        }
        return false;
    case FI_LBRC:
        if(record->event.pressed && is_mac)
        {
            tap_code16(RALT(FI_8));
            return false;
        }
        return true;
    case FI_RBRC:
        if(record->event.pressed && is_mac)
        {
            tap_code16(RALT(FI_9));
            return false;
        }
        return true;
    case FI_LCBR:
        if(record->event.pressed && is_mac)
        {
            tap_code16(RALT(S(FI_8)));
            return false;
        }
        return true;
    case FI_RCBR:
        if(record->event.pressed && is_mac)
        {
            tap_code16(RALT(S(FI_9)));
            return false;
        }
        return true;
    case FI_PIPE:
        if(record->event.pressed && is_mac)
        {
            tap_code16(RALT(S(FI_7)));
            return false;
        }
        return true;
    case FI_EURO:
        if(record->event.pressed && is_mac)
        {
            tap_code16(S(FI_4));
            return false;
        }
        return true;

    default:
        return true;
    }
}

LEADER_EXTERNS();

void matrix_init_user(void) {
    steno_set_mode(STENO_MODE_GEMINI);
}

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(FI_C) { // Inline Code
            tap_code16(FI_GRV);
            tap_code16(FI_GRV);
            tap_code16(FI_GRV);
            tap_code16(KC_SPC);
        }
        SEQ_ONE_KEY(FI_S) { // Windows screenshot
            SEND_STRING(SS_LGUI("\nS"));
        }
        SEQ_ONE_KEY(FI_W) { // Save: ctrl+s
            tap_code16(LCTL(KC_S));
        }
        SEQ_ONE_KEY(FI_R) { // Initiate recursive search cli: ctrl+r
            tap_code16(LCTL(KC_R));
        }
        SEQ_TWO_KEYS(FI_M, FI_C) {
            SEND_STRING("TestMooCow\n");
        }
    }
}


#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}
/*
static void render_jesterKing_logo(void) {
    static const char PROGMEM jesterKing_logo[] = {
        // 'kyria_jk_etsu_inv', 128x64px
        // 1164 bytes
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80,
        0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40,
        0x40, 0x40, 0x40, 0x80, 0x80, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0x1f, 0x00, 0xe0, 0xf8, 0xfe, 0xfc, 0xfc, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xfc, 0x6f, 0x74, 0x12,
        0x1a, 0x12, 0x12, 0x22, 0x42, 0x05, 0x45, 0x89, 0x9a, 0x33, 0xc7, 0x0a, 0x76, 0xfc, 0xf0, 0x80,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x7e, 0x7e, 0x7e, 0x7e, 0x3c, 0x3c, 0x7f, 0x7f, 0xff, 0xe3,
        0xf0, 0xf8, 0xbe, 0xdf, 0xdf, 0xdf, 0xef, 0xf7, 0xf7, 0xfb, 0xf8, 0xf0, 0xc0, 0x80, 0x80, 0x80,
        0x80, 0xc0, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0x60, 0x30, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfd, 0xff, 0x66, 0xb4, 0x16, 0xf6,
        0x96, 0x00, 0xc0, 0x36, 0xf6, 0x16, 0x36, 0xd4, 0x21, 0xc3, 0xff, 0xfe, 0x04, 0x07, 0xf8, 0x3f,
        0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
        0x03, 0x07, 0x1f, 0x03, 0x18, 0x30, 0x7b, 0x5f, 0xdf, 0xdf, 0xb3, 0x7b, 0xfb, 0xfb, 0xfb, 0xff,
        0xff, 0xfd, 0xfc, 0x7c, 0x3c, 0x1e, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xdc, 0x73, 0x00, 0x07, 0x1a, 0x2c, 0x09, 0x89,
        0x68, 0x47, 0x4b, 0x48, 0x49, 0x2b, 0x0b, 0x89, 0x49, 0x3c, 0x07, 0x0f, 0x04, 0x04, 0x03, 0xce,
        0x71, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x0e, 0x0d, 0x0b, 0x03,
        0x0f, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x73, 0x4c, 0x40, 0x40, 0x40, 0x40, 0x40, 0xc0, 0x60,
        0xa3, 0x1e, 0x02, 0x02, 0x01, 0x01, 0x01, 0x0f, 0xb0, 0xe0, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
        0x7b, 0x8c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x80, 0x78, 0x06, 0x01, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
        0x05, 0x0b, 0x0a, 0x02, 0x04, 0x02, 0x06, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0xe0, 0x30, 0x08,
        0x00, 0x00, 0x03, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x01, 0x02, 0x0e, 0x0c, 0x14, 0x14, 0x14, 0x17, 0x10, 0x10, 0x10, 0x20, 0x20, 0x20,
        0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x30, 0x10, 0x10, 0x10, 0x10, 0x10, 0x17, 0x1c, 0x1c,
        0x0c, 0x0c, 0x0c, 0x0e, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    oled_write_raw_P(jesterKing_logo, sizeof(jesterKing_logo));
}*/

/*static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}*/

static void render_status(void) {
    // QMK Logo and version information
    //render_qmk_logo();
    oled_write_P(PSTR("LETWORY "), false);
    oled_write_P(PSTR("INTERACTIVE\n"), true);
    oled_write_P(PSTR("Kyria / jesterKing\n\n"), false);
    uint8_t current_default_layer = get_highest_layer(eeconfig_read_default_layer());

    oled_write_P(PSTR("DAS"), current_default_layer == _DAS);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("STENO"), current_default_layer == _PLOVER);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("n00b"), current_default_layer == _QWERTY);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR(" "), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("-\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("v\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("^\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("~\n"), false);
            break;
        default:
            oled_write_P(PSTR("?\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);

    uint8_t cur_unicode_mode = get_unicode_input_mode();
    switch(cur_unicode_mode)  {
        case UC_WINC:
            oled_write_P(PSTR("WinC\n"), false);
            break;
        case UC_MAC:
            oled_write_P(PSTR("Mac\n"), false);
            break;
        case UC_LNX:
            oled_write_P(PSTR("Linux\n"), false);
            break;
        default:
            oled_write_P(PSTR("----\n"), false);
            break;
    }
}

void oled_task_user(void) {
    render_status();
    /*if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_jesterKing_logo();
    }*/
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t layer = get_highest_layer(layer_state);
    if (index == 0) {
        if(layer==_QWERTY) {
            // Volume control
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        } else if(layer==_LOWER || layer==_RAISE) {
            if (clockwise) {
                rgblight_increase_val_noeeprom();
            } else {
                rgblight_decrease_val_noeeprom();
            }
        }
    }
    else if (index == 1) {
        if(layer==_QWERTY) {
            // Page up/Page down
            if (clockwise) {
                tap_code(KC_PGUP);
            } else {
                tap_code(KC_PGDN);
            }
        } else if(layer==_LOWER) {
            uint8_t speed = rgblight_get_speed();
            if (clockwise) {
                speed+=10;
                speed = speed > 220 ? 220 : speed;
            } else {
                speed-=10;
                speed = speed < 30 ? 30 : speed;
            }
            rgblight_set_speed(speed);
        } else if(layer==_RAISE) {
            if (clockwise) {
                rgblight_enable_noeeprom();
            } else {
                rgblight_disable_noeeprom();
            }
        }
    }
    return true;
}
#endif

void keyboard_post_init_user(void) {
    oled_set_brightness(1);
    //rgblight_mode_noeeprom(1);
    //rgblight_set_speed_noeeprom(100);
    //rgblight_sethsv_noeeprom(21, 250, 150);
    //rgblight_sethsv_noeeprom(100, 250, 150);
    //rgblight_sethsv_at(100, 250, 150, 1);
    //rgblight_sethsv_at(100, 250, 150, 2);
    LED_TYPE led;
    sethsv(HSV_WHITE, &led);
    rgblight_setrgb_at(led.r, led.g, led.b, 0);
}

void suspend_power_down_user(void) {
    if(rgblight_is_enabled()){
        rgblight_disable();
    }
}

void suspend_wakeup_init_user(void) {
    if(!rgblight_is_enabled()){
        rgblight_enable();
    }
}
