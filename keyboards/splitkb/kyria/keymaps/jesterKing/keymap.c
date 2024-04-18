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
    _DAS = 0,
    _QWERTY,
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
tap_dance_action_t tap_dance_actions[] = {
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

// Add key combos
const uint16_t PROGMEM cmb_lprn[]  = {FI_W, FI_A, COMBO_END};
const uint16_t PROGMEM cmb_rprn[]  = {FI_Y, FI_O, COMBO_END};
const uint16_t PROGMEM cmb_lcbr[]  = {FI_A, FI_ADIA, COMBO_END};
const uint16_t PROGMEM cmb_rcbr[]  = {FI_O, FI_DOT, COMBO_END};
const uint16_t PROGMEM cmb_lbrc[]  = {FI_H, FI_L, COMBO_END};
const uint16_t PROGMEM cmb_rbrc[]  = {FI_K, FI_T, COMBO_END};
const uint16_t PROGMEM cmb_labk[]  = {FI_L, FI_D, COMBO_END};
const uint16_t PROGMEM cmb_rabk[]  = {FI_T, FI_J, COMBO_END};
const uint16_t PROGMEM cmb_bksp1[] = {FI_U, FI_Y, FI_B, COMBO_END};
const uint16_t PROGMEM cmb_del1[]  = {FI_W, FI_U, FI_Y, COMBO_END};
const uint16_t PROGMEM cmb_ent1[]  = {FI_A, FI_O, COMBO_END};
const uint16_t PROGMEM cmb_fwsl[]  = {FI_U, FI_I, COMBO_END};
const uint16_t PROGMEM cmb_bksl[]  = {FI_R, FI_N, COMBO_END};
const uint16_t PROGMEM cmb_star[]  = {FI_I, FI_COMM, COMBO_END};

//const uint16_t PROGMEM cmb_ent2[]  = {FI_R, FI_H, FI_P, COMBO_END};

combo_t key_combos[] = {
    COMBO(cmb_lprn,  FI_LPRN),
    COMBO(cmb_rprn,  FI_RPRN),
    COMBO(cmb_lcbr,  FI_LCBR),
    COMBO(cmb_rcbr,  FI_RCBR),
    COMBO(cmb_lbrc,  FI_LBRC),
    COMBO(cmb_rbrc,  FI_RBRC),
    COMBO(cmb_labk,  FI_LABK),
    COMBO(cmb_rabk,  FI_RABK),
    COMBO(cmb_bksp1, KC_BSPC),
    COMBO(cmb_del1,  KC_DEL),
    COMBO(cmb_ent1,  KENT),
    COMBO(cmb_fwsl,  FI_SLSH),
    COMBO(cmb_bksl,  FI_BSLS),
    COMBO(cmb_star,  FI_ASTR),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Base layer: DAS
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
        CT_BSP, FI_X, FI_D, FI_M, FI_J, FI_ARNG, KC_LSFT, QK_LEAD,   KC_RSFT, FI_QUES, FI_ODIA, FI_ADIA, FI_COMM, FI_DOT, FI_MINS, FI_Z,
                             KGUI, KC_BRID, KC_LALT, LO_SPC,  HI_ESC,    LO_TAB,  HI_SPC,  KC_RALT, KC_BRIU, KC_CAPS
    ),

    /*
     * Layer: QWERTY ISO, used on finnish key layout:
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
        CT_BSP,  FI_Z, FI_X, FI_C, FI_V, FI_B,   KC_LSFT, QK_LEAD,   KC_RSFT, FI_DIAE, FI_N,   FI_M, FI_COMM, FI_DOT, FI_MINS, FI_QUOT,
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
 * |        |   1  |  2   |  3   |  4   |  5   |                              |  6   |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      | Prev | Play | Next | VolUp|                              | PgUp | Left | Up   | Right|      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      | Mute | VolDn| LAlt |      |  |      |      | PgDn | Home | Down | End  |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_RAISE] = LAYOUT(
      _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
      RGB_MOD,  _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,                                     KC_PGUP, KC_LEFT, KC_UP,   KC_RGHT, _______, _______,
      RGB_RMOD, _______, _______, _______, KC_MUTE, KC_VOLD, KC_LALT, _______, _______, _______, KC_PGDN, KC_HOME, KC_DOWN, KC_END,  _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Adjust Layer: Function keys, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |UC_WINC | F1   |  F2  | F3   | F4   | F5   |                              | F6   | F7   |  F8  | F9   | F10  | F11    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |UC_MAC |      |      | DAS  | PLVR | QWRT |                              | MWup | MLft | MUp  | MRgt |      | F12    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |UC_LINX |      |      |      |      |      |      |      |  |      |      | MWdn | LMB  | MDn  | RMB  |      | QK_BOOT|
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      | MMB  |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      UC_WINC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,   KC_F11,
      UC_MAC, _______, _______, DAS  ,    PLVR,      QWRT,                                     KC_WH_U, KC_MS_L,  KC_MS_U, KC_MS_R, _______,  KC_F12,
      UC_LINX, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_WH_D, KC_BTN1,  KC_MS_D, KC_BTN2, _______, QK_BOOT,
                                 _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN3,  _______
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

static uint8_t get_send_delay(void) {
    uint8_t cur_unicode_mode = get_unicode_input_mode();
    switch(cur_unicode_mode)  {
        case UNICODE_MODE_WINDOWS:
        case UNICODE_MODE_WINCOMPOSE:
        case UNICODE_MODE_LINUX:
            return 0;
            break;
        case UNICODE_MODE_MACOS:
        default:
            return 25;
            break;
    }
    return 25;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    bool is_mac = get_unicode_input_mode() == UNICODE_MODE_MACOS;
    bool is_linx = get_unicode_input_mode() == UNICODE_MODE_LINUX;

#ifdef CONSOLE_ENABLE
    dprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
    dprintf("\t0x%04X 0x%04X\n", FI_LCBR, FI_RCBR);
#endif

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
            dprintf("hit LCBR on mac\n");
            tap_code16(LSA(KC_8));
            return false;
        }
        return true;
    case FI_RCBR:
        if(record->event.pressed && is_mac)
        {
            dprintf("hit RCBR on mac\n");
            tap_code16(LSA(KC_9));
            return false;
        }
        return true;
    case FI_BSLS:
        if(record->event.pressed && is_mac)
        {
            tap_code16(RALT(S(FI_7)));
            return false;
        }
        return true;
    case FI_PIPE:
        if(record->event.pressed && is_mac)
        {
            tap_code16(RALT(FI_7));
            return false;
        }
        return true;
    case FI_EURO:
        if(record->event.pressed && is_mac)
        {
            tap_code16(S(FI_4));
            return false;
        }
        if(record->event.pressed && is_linx)
        {
            tap_code16(RALT(FI_E));
            return false;
        }
        return true;

    default:
        return true;
    }
}

void matrix_init_user(void) {
    steno_set_mode(STENO_MODE_GEMINI);
}

void leader_end_user(void) {
    uint8_t delay = get_send_delay();
    if (leader_sequence_one_key(FI_C)) { // Inline Code
        tap_code16(FI_GRV);
        tap_code16(KC_SPC);
        tap_code16(FI_GRV);
        tap_code16(KC_SPC);
        tap_code16(FI_GRV);
        tap_code16(KC_SPC);
    }
    if(leader_sequence_one_key(FI_S)) { // Windows screenshot
        SEND_STRING(SS_LGUI("\nS"));
    }
    if(leader_sequence_one_key(FI_W)) { // Save: ctrl+s
        tap_code16(LCTL(KC_S));
    }
    if(leader_sequence_one_key(FI_R)) { // Initiate recursive search cli: ctrl+r
        tap_code16(LCTL(KC_R));
    }
    // Rhino commands
    if(leader_sequence_three_keys(FI_R, FI_M, FI_C)) {
        SEND_STRING("TestMooCow\n");
    }
    if(leader_sequence_three_keys(FI_R, FI_S, FI_I)) {
        SEND_STRING(SS_LSFT("/") "SystemInfo\n");
    }
    if(leader_sequence_three_keys(FI_R, FI_R, FI_A)) {
        SEND_STRING_DELAY("/" SS_LSFT("/") "SetDisplayMode " SS_LSFT("/") "M " SS_LSFT("/")"Raytraced\n", delay);
    }
    if(leader_sequence_three_keys(FI_R, FI_R, FI_E)) {
        SEND_STRING_DELAY("/" SS_LSFT("/") "SetDisplayMode " SS_LSFT("/") "M " SS_LSFT("/")"Rendered\n", delay);
    }
    if(leader_sequence_three_keys(FI_R, FI_D, FI_M)) {
        SEND_STRING_DELAY("/" SS_LSFT("/") "SetDisplayMode " SS_LSFT("/") "M " SS_LSFT("/"), delay);
    }
    if(leader_sequence_three_keys(FI_R, FI_A, FI_U)) {
        SEND_STRING(SS_LSFT("/") "Audit3dmFile\n");
    }

    // Git key combos
    if(leader_sequence_two_keys(FI_G, FI_D)) {
        SEND_STRING("git diff\n");
    }
    if(leader_sequence_three_keys(FI_G, FI_D, FI_H)) {
        SEND_STRING("git diff HEAD" SS_RALT("]") " 1\n");
    }
    if(leader_sequence_two_keys(FI_G, FI_F)) {
        SEND_STRING("git fetch\n");
    }
    if(leader_sequence_two_keys(FI_G, FI_S)) {
        SEND_STRING("git status\n");
    }
    if(leader_sequence_two_keys(FI_G, FI_G)) {
        SEND_STRING("git gui\n");
    }
    if(leader_sequence_two_keys(FI_G, FI_K)) {
        SEND_STRING("gitk\n");
    }
    if(leader_sequence_two_keys(FI_G, FI_L)) {
        SEND_STRING("git log\n");
    }
    if(leader_sequence_two_keys(FI_G, FI_P)) {
        SEND_STRING("git pull //ff/only\n");
    }
    if(leader_sequence_three_keys(FI_G, FI_S, FI_U)) {
        SEND_STRING("git submodule update //init //recursive\n");
    }
    // Rhino discourse keycombos
    if(leader_sequence_four_keys(FI_D, FI_R, FI_S, FI_I)) {
        SEND_STRING("Please run the Rhino command ");
        tap_code16(FI_GRV);
        tap_code16(FI_UNDS);
        SEND_STRING("SystemInfo");
        tap_code16(FI_GRV);
        tap_code16(KC_SPC);
        SEND_STRING(" and post the result in a reply.");
    }
    // QMK commands, using K for keyboard instead of Q of QMK
    // because Q is already a tapdance participant.
    if(leader_sequence_two_keys(FI_K, FI_C)) {
        SEND_STRING("qmk compile /kb splitkb");
        tap_code16(FI_SLSH);
        SEND_STRING("kyria");
        tap_code16(FI_SLSH);
        SEND_STRING("rev3 /km jesterKing\n");
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

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
}

static void render_status(void) {
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
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);

    uint8_t cur_unicode_mode = get_unicode_input_mode();
    switch(cur_unicode_mode)  {
        case UNICODE_MODE_WINDOWS:
        case UNICODE_MODE_WINCOMPOSE:
            oled_write_P(PSTR("WinC\n"), false);
            break;
        case UNICODE_MODE_MACOS:
            oled_write_P(PSTR("Mac\n"), false);
            break;
        case UNICODE_MODE_LINUX:
            oled_write_P(PSTR("Linux\n"), false);
            break;
        default:
            oled_write_P(PSTR("----\n"), false);
            break;
    }
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    }
    else {
        render_jesterKing_logo();
    }
    return false;
}

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
    //rgblight_enable_noeeprom();                          // enables Rgb, without saving settings
    rgblight_set_speed(80);
    //rgblight_sethsv_noeeprom(255, 128, 64);             // sets the color to teal/cyan without saving
    //rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL + 2); // sets mode to Fast breathing without saving
#ifdef CONSOLE_ENABLE
    debug_enable = true;
    debug_matrix = false;
    debug_keyboard = true;
#endif
}

void suspend_power_down_user(void) {
    rgblight_suspend();
}

void suspend_wakeup_init_user(void) {
    rgblight_wakeup();
}
