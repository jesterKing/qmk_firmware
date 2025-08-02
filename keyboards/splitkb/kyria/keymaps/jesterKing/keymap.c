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

//#include "keymap_finnish.h"
#include "print.h"

#define FI_ADIA ALGR(KC_Q)
#define FI_ARNG ALGR(KC_W)
#define FI_ODIA ALGR(KC_P)
#define FI_MICR ALGR(KC_M)
#define FI_CURR ALGR(KC_4)
#define FI_SECT S(ALGR(KC_S))
#define FI_DIAE S(KC_QUOT)
#define FI_DQUO S(ALGR(KC_QUOT))

#define LCS(kc) (QK_LCTL | QK_LSFT | (kc))

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

enum my_keycodes {
    // layer switchers
    DAS = SAFE_RANGE,
    QWRT,
    PLVR,
    BLND,
    GAME,
    RHNO,
    BAR,

    // own codes to handle special cases like semicolon-colon
    JK_SCLN, // semicolon
    JK_CLN,  // colon

    // layer specific keycodes

    // Blender keys
    B_ADD,  // shift+a

    B_UNDO, // ctrl or cmd Z
    B_REDO, // ctrl or cmd shift Z

    B_GRB,    // Grab
    B_GRB_X,  // Grab, move in X
    B_GRB_XX, // Grab, move in local X
    B_GRB_NX, // Grab, move in YZ
    B_GRB_Y,  // Grab, move in Y
    B_GRB_YY, // Grab, move in local Y
    B_GRB_NY, // Grab, move in XZ
    B_GRB_Z,  // Grab, move in Z
    B_GRB_ZZ, // Grab, move in localZ
    B_GRB_NZ, // Grab, move in XY
    B_SCL,    // Scale
    B_SCL_X,  // Scale, in X
    B_SCL_XX, // Scale, in local X
    B_SCL_NX, // Scale, in YZ
    B_SCL_YY, // Scale, in local Y
    B_SCL_NY, // Scale, in XZ
    B_SCL_ZZ, // Scale, in local Z
    B_SCL_NZ, // Scale, in XY
    B_ROT,    // Rotate
    B_ROT_X,  // Rotate, around X
    B_ROT_XX, // Rotate, around local X
    B_ROT_NX, // Rotate, around YZ
    B_ROT_Y,  // Rotate, around Y
    B_ROT_YY, // Rotate, around local Y
    B_ROT_NY, // Rotate, around XZ
    B_ROT_Z,  // Rotate, around Z
    B_ROT_ZZ, // Rotate, around local Z
    B_ROT_NZ, // Rotate, around XY

    B_P_MOD, // Mode pie
    B_P_EDIT, // Editor pie


    };

enum layers {
    _DAS = 0,
    _QWERTY,
    _PLOVER,
    _BLENDER,
    _GAMER,
    _RHINO,
    _BAR, // beyond all reason
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
    TD_EQL_AMPR,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_LPRN_RPRN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    [TD_LCBR_RCBR] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
    [TD_LBRC_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
    [TD_PLUS_MIN]  = ACTION_TAP_DANCE_DOUBLE(KC_PLUS, KC_MINS),
    [TD_DIV_MULT]  = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_ASTR),
    [TD_Q_Z]       = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_Z),
    [TD_EQL_AMPR]  = ACTION_TAP_DANCE_DOUBLE(KC_EQL, KC_AMPR),
};

// Add tap dance item to your keymap in place of a keycode

const uint32_t PROGMEM unicode_map[] = {
    [DEG] = 0x0000b0,  // °
    [PI]  = 0x01d70b   // 𝜋
};

// Add key combos
const uint16_t PROGMEM cmb_lprn[]  = {KC_W, KC_A, COMBO_END};
const uint16_t PROGMEM cmb_rprn[]  = {KC_Y, KC_O, COMBO_END};
const uint16_t PROGMEM cmb_lcbr[]  = {KC_A, FI_ADIA, COMBO_END};
const uint16_t PROGMEM cmb_rcbr[]  = {KC_O, KC_DOT, COMBO_END};
const uint16_t PROGMEM cmb_lbrc[]  = {KC_H, KC_L, COMBO_END};
const uint16_t PROGMEM cmb_rbrc[]  = {KC_K, KC_T, COMBO_END};
const uint16_t PROGMEM cmb_labk[]  = {KC_L, KC_D, COMBO_END};
const uint16_t PROGMEM cmb_rabk[]  = {KC_T, KC_J, COMBO_END};
const uint16_t PROGMEM cmb_bksp1[] = {KC_U, KC_Y, KC_B, COMBO_END};
const uint16_t PROGMEM cmb_del1[]  = {KC_W, KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM cmb_ent1[]  = {KC_A,KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM cmb_fwsl[]  = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM cmb_bksl[]  = {KC_R, KC_N, COMBO_END};
const uint16_t PROGMEM cmb_star[]  = {KC_I, KC_COMM, COMBO_END};

// Blender-specific combos
const uint16_t PROGMEM cmb_grbnx[]  = {B_GRB, KC_X, COMBO_END};
const uint16_t PROGMEM cmb_rotnx[]  = {B_ROT, KC_X, COMBO_END};
const uint16_t PROGMEM cmb_sclnx[]  = {B_SCL, KC_X, COMBO_END};

const uint16_t PROGMEM cmb_grbny[]  = {B_GRB, KC_Y, COMBO_END};
const uint16_t PROGMEM cmb_rotny[]  = {B_ROT, KC_Y, COMBO_END};
const uint16_t PROGMEM cmb_sclny[]  = {B_SCL, KC_Y, COMBO_END};

const uint16_t PROGMEM cmb_grbnz[]  = {B_GRB, KC_Z, COMBO_END};
const uint16_t PROGMEM cmb_rotnz[]  = {B_ROT, KC_Z, COMBO_END};
const uint16_t PROGMEM cmb_sclnz[]  = {B_SCL, KC_Z, COMBO_END};

const uint16_t PROGMEM cmb_pie_editor[]  = {B_ADD, B_P_MOD, COMBO_END};

//const uint16_t PROGMEM cmb_ent2[]  = {KC_R, KC_H, KC_P, COMBO_END};

combo_t key_combos[] = {
    COMBO(cmb_lprn,  S(KC_9)),
    COMBO(cmb_rprn,  S(KC_0)),
    COMBO(cmb_lcbr,  S(KC_LBRC)),
    COMBO(cmb_rcbr,  S(KC_RBRC)),
    COMBO(cmb_lbrc,  KC_LBRC),
    COMBO(cmb_rbrc,  KC_RBRC),
    COMBO(cmb_labk,  S(KC_COMM)),
    COMBO(cmb_rabk,  S(KC_DOT)),
    COMBO(cmb_bksp1, KC_BSPC),
    COMBO(cmb_del1,  KC_DEL),
    COMBO(cmb_ent1,  KENT),
    COMBO(cmb_fwsl,  KC_SLSH),
    COMBO(cmb_bksl,  KC_BSLS),
    COMBO(cmb_star,  KC_ASTR),

    // Blender combos

    COMBO(cmb_pie_editor, B_P_EDIT),

    COMBO(cmb_grbnx,  B_GRB_NX),
    COMBO(cmb_rotnx,  B_ROT_NX),
    COMBO(cmb_sclnx,  B_SCL_NX),

    COMBO(cmb_grbny,  B_GRB_NY),
    COMBO(cmb_rotny,  B_ROT_NY),
    COMBO(cmb_sclny,  B_SCL_NY),

    COMBO(cmb_grbnz,  B_GRB_NZ),
    COMBO(cmb_rotnz,  B_ROT_NZ),
    COMBO(cmb_sclnz,  B_SCL_NZ),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Base layer: DAS
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * |RAIS/ESC|   P  |   H  |   R  |  K   |  <>  |                              |  '"  |  W   |  U   |  Y   |  B   |   Q    |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |   F    |  S   |   L  |   N  |  T   |  V   |                              |  G   |  A   |  I   |  O   |  E   |   C    |
     * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
     * | Ctrl/BS|  X   |   D  |   M  |  J   |  \|  |LShift|Leader|  |RShift|  ?   |  Ö   |  Ä   |  ,;  |  .:  |  -_  |   Z    |
     * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
     *                        | GUI  | Enter| Alt  | Space| Esc  |  | Tab  | Space|      | LEAD | CAPS |
     *                        |      |      |      | Lower| Raise|  | Lower| Raise| RAlt |      |      |
     *                        `----------------------------------'  `----------------------------------'
     */
    [_DAS] = LAYOUT(
        KC_ESC, KC_P, KC_H, KC_R, KC_K, KC_NUBS,                                       ALGR(KC_QUOT), KC_W,    KC_U,    KC_Y,   KC_B,    KC_Q,
        KC_F,   KC_S, KC_L, KC_N, KC_T, KC_V,                                          KC_G,    KC_A,    KC_I,    KC_O,   KC_E,    KC_C,
        CT_BSP, KC_X, KC_D, KC_M, KC_J, KC_BSLS, KC_LSFT, QK_LEAD,   KC_RSFT, KC_QUES, FI_ODIA, FI_ADIA, KC_COMM, KC_DOT, KC_MINS, KC_Z,
                             KGUI, QK_LEAD, KC_LALT, LO_SPC,  HI_ESC,    LO_TAB,  HI_SPC,  KC_RALT, QK_LEAD, KC_CAPS
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
        HI_ESC,  KC_Q, KC_W, KC_E, KC_R, KC_T,                                         KC_Y,   KC_U, KC_I,    KC_O,   KC_P,    FI_ARNG,
        KC_NUBS, KC_A, KC_S, KC_D, KC_F, KC_G,                                         KC_H,   KC_J, KC_K,    KC_L,   FI_ODIA, FI_ADIA,
        CT_BSP,  KC_Z, KC_X, KC_C, KC_V, KC_B,   KC_LSFT, QK_LEAD,   KC_RSFT, FI_DIAE, KC_N,   KC_M, KC_COMM, KC_DOT, KC_MINS, KC_QUOT,
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
* Blender layer. Letft-hand centric setup for use with
* drawing surface.
*
* ,-------------------------------------------.                              ,-------------------------------------------.
* |        |      |      |      |      |      |                              |      |      |      |      |      |        |
* |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
* |        |      |      |      |      |      |                              |      |      |      |      |      |        |
* |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
* |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
* `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
*                        |      |      |      |      |      |  |      |      |      |      |      |
*                        |      |      |      |      |      |  |      |      |      |      |      |
*                        `----------------------------------'  `----------------------------------'
*/
   [_BLENDER] = LAYOUT(
     XXXXXXX, XXXXXXX,    KC_Z,    KC_Y,    KC_X, B_P_MOD,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     DAS,
     XXXXXXX, XXXXXXX,   B_SCL,   B_ROT,   B_GRB,   B_ADD,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     KC_LCTL, KC_LSFT, KC_LALT,   KC_T,    KC_N,  XXXXXXX,  B_REDO, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                XXXXXXX, XXXXXXX, XXXXXXX,  B_UNDO,  KC_ESC,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
   ),

/*
 * WASD gaming layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    1   |  TAB |   Q  |   X  |   E  |   R  |                              |   Y  |   7  |   8  |   9  |  F1  |   DAS  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |    2   | SHFT |   A  |   W  |   D  |   F  |                              |      |   4  |   5  |   6  |  F2  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |    3   | CTRL |   Z  |   S  |   C  |   V  |   T  |  ESC |  |      |      |      |   1  |   2  |   3  |  F3  |   F4   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |   B  |  SPC |   M  |  |      |      |   0  |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_GAMER] = LAYOUT(
         KC_1,  KC_TAB,    KC_Q,    KC_X,    KC_E,    KC_R,                                        KC_Y,    KC_7,    KC_8,    KC_9,   KC_F1,     DAS,
         KC_2, KC_LSFT,    KC_A,    KC_W,    KC_D,    KC_F,                                     XXXXXXX,    KC_4,    KC_5,    KC_6,   KC_F2, XXXXXXX,
         KC_3, KC_LCTL,    KC_Z,    KC_S,    KC_C,    KC_V,    KC_T,  KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX,    KC_1,    KC_2,    KC_3,   KC_F3,   KC_F4,
                                 XXXXXXX, XXXXXXX,    KC_B,    KSPC,   KC_M, XXXXXXX, XXXXXXX,     KC_0, XXXXXXX, XXXXXXX
    ),

/*
 * Beyond All Reason gaming layer
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    1   |  TAB |   Q  |   X  |   E  |   R  |                              |   Y  |   7  |   8  |   9  |  F1  |   DAS  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |    2   | SHFT |   A  |   W  |   D  |   F  |                              |      |   4  |   5  |   6  |  F2  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |    3   | CTRL |   Z  |   S  |   C  |   V  |   T  |  ESC |  |      |      |      |   1  |   2  |   3  |  F3  |   F4   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |   B  |  SPC |   M  |  |      |      |   0  |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_GAMER] = LAYOUT(
         KC_1,  KC_TAB,    KC_Q,    KC_X,    KC_E,    KC_R,                                        KC_Y,    KC_7,    KC_8,    KC_9,   KC_F1,     DAS,
         KC_2, KC_LSFT,    KC_A,    KC_W,    KC_D,    KC_F,                                     XXXXXXX,    KC_4,    KC_5,    KC_6,   KC_F2, XXXXXXX,
         KC_3, KC_LCTL,    KC_Z,    KC_S,    KC_C,    KC_V,    KC_T,  KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX,    KC_1,    KC_2,    KC_3,   KC_F3,   KC_F4,
                                 XXXXXXX, XXXXXXX,    KC_B,    KSPC,   KC_M, XXXXXXX, XXXXXXX,     KC_0, XXXXXXX, XXXXXXX
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
      KC_BSLS, KC_EXLM,    FI_DQUO, S(KC_2),          ALGR(KC_5), KC_PERC,                              TD(TD_LBRC_RBRC), KC_7, KC_8, KC_9, S(KC_BSLS),      S(ALGR(KC_4)),
      FI_SECT, S(KC_3),    S(KC_4), TD(TD_EQL_AMPR),  FI_DIAE,    KC_GRV,                               TD(TD_LPRN_RPRN), KC_4, KC_5, KC_6, TD(TD_PLUS_MIN), TD(TD_DIV_MULT),
      FI_MICR, ALGR(KC_7), FI_CURR, UM(DEG), KC_CIRC, S(KC_GRV), _______, KC_QUOT,    _______, KC_LALT, TD(TD_LCBR_RCBR), KC_1, KC_2, KC_3, KC_QUES,         UM(PI),
                                    _______, _______, _______, KC_SCLN, KC_QUES,      KC_SCLN, _______, KC_0,             KBSP, _______
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
 * |UC_MAC  |      |      | DAS  | PLVR | QWRT |                              | MWup | MLft | MUp  | MRgt |      | F12    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |UC_LINX |      |      | BLND | RHNO | GAME |      |      |  |      |      | MWdn | LMB  | MDn  | RMB  |      | QK_BOOT|
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |QK_RBT|      |      |      |  |      |      |      | MMB  |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      UC_WINC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_F7,    KC_F8,   KC_F9,  KC_F10,  KC_F11,
      UC_MAC,  _______, _______, DAS  ,    PLVR,    QWRT,                                     KC_WH_U, KC_MS_L,  KC_MS_U, KC_MS_R, _______,  KC_F12,
      UC_LINX, _______, _______, BLND ,    RHNO,    GAME, _______, _______, _______, _______, KC_WH_D, KC_BTN1,  KC_MS_D, KC_BTN2, _______, QK_BOOT,
                                 _______, QK_RBT, _______, _______, _______, _______, _______, _______, KC_BTN3,  _______
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
    return 0;
    /*uint8_t cur_unicode_mode = get_unicode_input_mode();
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
    */
}



bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    bool is_mac = get_unicode_input_mode() == UNICODE_MODE_MACOS;
    //bool is_linx = get_unicode_input_mode() == UNICODE_MODE_LINUX;
    static bool lshift = false;
    static bool rshift = false;
    static bool shift  = false;

    if(keycode == KC_LSFT) {
        lshift = record->event.pressed;
    } else if(keycode == KC_RSFT) {
        rshift = record->event.pressed;
    }

    shift = lshift || rshift;

#ifdef CONSOLE_ENABLE
    dprintf("KL: kc: 0x%04X, col: %2u, ", keycode, record->event.key.col);
    dprintf("row: %2u, pressed: %u, ",    record->event.key.row, record->event.pressed);
    dprintf("time: %5u, int: %u, ",       record->event.time, record->tap.interrupted);
    dprintf("count: %u\n",                record->tap.count);
    uprintf("\t -> %s\n", get_keycode_string(keycode));
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
    case BLND:
        if(record->event.pressed)
        {
            set_single_persistent_default_layer(_BLENDER);
        }
        return false;
    case GAME:
        if(record->event.pressed)
        {
            set_single_persistent_default_layer(_GAMER);
        }
        return false;
    case B_ADD:
        if(record->event.pressed)
        {
            tap_code16(LSFT(KC_A));
            //SEND_STRING("Pie Edit");
        }
        return false;
    case B_UNDO:
        if(record->event.pressed)
        {
            if(is_mac)
            {
                tap_code16(LCMD(KC_Z));
            }
            else
            {
                tap_code16(LCTL(KC_Z));
            }
        }
        return false;
    case B_REDO:
        if(record->event.pressed)
        {
            if(is_mac)
            {
                tap_code16(SCMD(KC_Z));
            }
            else
            {
                tap_code16(LCS(KC_Z));
            }
        }
        return false;
    case B_P_EDIT:
        if(record->event.pressed)
        {
            tap_code16(LCA(KC_S));
            //SEND_STRING("Pie Edit");
        }
        return false;
    case B_P_MOD:
        if(record->event.pressed)
        {
            tap_code16(LCTL(KC_TAB));
            //SEND_STRING("Pie Mode");
        }
        return false;
    case B_GRB:
        if(record->event.pressed)
        {
            tap_code16(KC_G);
        }
        return false;
    case B_GRB_X:
        if(record->event.pressed)
        {
            tap_code16(KC_G);
            tap_code16(KC_X);
        }
        return false;
    case B_GRB_XX:
        if(record->event.pressed)
        {
            tap_code16(KC_G);
            tap_code16(KC_X);
            tap_code16(KC_X);
        }
        return false;
    case B_GRB_NX:
        if(record->event.pressed)
        {
            tap_code16(KC_G);
            tap_code16(LSFT(KC_X));
        }
        return false;
    case B_GRB_NY:
        if(record->event.pressed)
        {
            tap_code16(KC_G);
            tap_code16(LSFT(KC_Y));
        }
        return false;
    case B_GRB_NZ:
        if(record->event.pressed)
        {
            tap_code16(KC_G);
            tap_code16(LSFT(KC_Z));
        }
        return false;
    case B_ROT:
        if(record->event.pressed)
        {
            tap_code16(KC_R);
        }
        return false;
    case B_ROT_X:
        if(record->event.pressed)
        {
            tap_code16(KC_R);
            tap_code16(KC_X);
        }
        return false;
    case B_ROT_XX:
        if(record->event.pressed)
        {
            tap_code16(KC_R);
            tap_code16(KC_X);
            tap_code16(KC_X);
        }
        return false;
    case B_ROT_NX:
        if(record->event.pressed)
        {
            tap_code16(KC_R);
            tap_code16(LSFT(KC_X));
        }
        return false;
    case B_ROT_NY:
        if(record->event.pressed)
        {
            tap_code16(KC_R);
            tap_code16(LSFT(KC_Y));
        }
        return false;
    case B_ROT_NZ:
        if(record->event.pressed)
        {
            tap_code16(KC_R);
            tap_code16(LSFT(KC_Z));
        }
        return false;
    case B_SCL:
        if(record->event.pressed)
        {
            tap_code16(KC_S);
        }
        return false;
    case B_SCL_X:
        if(record->event.pressed)
        {
            tap_code16(KC_S);
            tap_code16(KC_X);
        }
        return false;
    case B_SCL_XX:
        if(record->event.pressed)
        {
            tap_code16(KC_S);
            tap_code16(KC_X);
            tap_code16(KC_X);
        }
        return false;
    case B_SCL_NX:
        if(record->event.pressed)
        {
            tap_code16(KC_S);
            tap_code16(LSFT(KC_X));
        }
        return false;
    case B_SCL_NY:
        if(record->event.pressed)
        {
            tap_code16(KC_S);
            tap_code16(LSFT(KC_Y));
        }
        return false;
    case B_SCL_NZ:
        if(record->event.pressed)
        {
            tap_code16(KC_S);
            tap_code16(LSFT(KC_Z));
        }
        return false;
    case KC_LBRC:
        if(record->event.pressed && is_mac)
        {
            tap_code16(RALT(KC_8));
            return false;
        }
        return true;
    case KC_RBRC:
        if(record->event.pressed && is_mac)
        {
            tap_code16(RALT(KC_9));
            return false;
        }
        return true;
    case KC_LCBR:
        if(record->event.pressed && is_mac)
        {
            //dprintf("hit LCBR on mac\n");
            tap_code16(LSA(KC_8));
            return false;
        }
        return true;
    case KC_RCBR:
        if(record->event.pressed && is_mac)
        {
            //dprintf("hit RCBR on mac\n");
            tap_code16(LSA(KC_9));
            return false;
        }
        return true;
    case KC_BSLS:
        if(record->event.pressed && is_mac)
        {
            tap_code16(RALT(S(KC_7)));
            return false;
        }
        return true;
    case KC_PIPE:
        if(record->event.pressed && is_mac)
        {
            tap_code16(RALT(KC_7));
            return false;
        }
        return true;
    case KC_DOT:
        if(record->event.pressed && shift)
        {
            dprintf("\t shift kc_dot\n");
            tap_code16(S(KC_SCLN));
            return false;
        }
        return true;
    case KC_COMM:
        if(record->event.pressed && shift)
        {
            dprintf("\t shift kc_comm\n");
            clear_mods();
            tap_code16(KC_SCLN);
            return false;
        }
        return true;
    case S(KC_5):
        if(record->event.pressed && is_mac)
        {
            tap_code16(S(KC_4));
            return false;
        }
        return true;
    case KC_NUBS:
        if(record->event.pressed)
        {
            uint16_t _kc = shift ? KC_DOT
                                 : KC_COMM;
                tap_code16(S(_kc));
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
    if (leader_sequence_one_key(KC_C)) { // Inline Code
        tap_code16(KC_GRV);
        tap_code16(KC_SPC);
        tap_code16(KC_GRV);
        tap_code16(KC_SPC);
        tap_code16(KC_GRV);
        tap_code16(KC_SPC);
    }
    if (leader_sequence_two_keys(KC_C, KC_C)) { // Inline Code begin and end code fence, up and space
        tap_code16(KC_GRV);
        tap_code16(KC_SPC);
        tap_code16(KC_GRV);
        tap_code16(KC_SPC);
        tap_code16(KC_GRV);
        tap_code16(KC_SPC);

        tap_code16(KC_ENT);

        tap_code16(KC_GRV);
        tap_code16(KC_SPC);
        tap_code16(KC_GRV);
        tap_code16(KC_SPC);
        tap_code16(KC_GRV);
        tap_code16(KC_SPC);

        tap_code16(KC_UP);
        tap_code16(KC_END);
        tap_code16(KC_SPC);
    }
    if(leader_sequence_one_key(KC_S)) { // Windows screenshot
        SEND_STRING(SS_LGUI("\nS"));
    }
    if(leader_sequence_one_key(KC_W)) { // Save: ctrl+s
        tap_code16(LCTL(KC_S));
    }
    if(leader_sequence_one_key(KC_R)) { // Initiate recursive search cli: ctrl+r
        tap_code16(LCTL(KC_R));
    }
    // Rhino commands
    if(leader_sequence_three_keys(KC_R, KC_M, KC_C)) {
        SEND_STRING("TestMooCow\n");
    }
    if(leader_sequence_three_keys(KC_R, KC_S, KC_I)) {
        SEND_STRING("_SystemInfo\n");
    }
    if(leader_sequence_three_keys(KC_R, KC_R, KC_A)) {
        SEND_STRING_DELAY("_SetDisplayMode _M _Raytraced\n", delay);
    }
    if(leader_sequence_three_keys(KC_R, KC_R, KC_E)) {
        SEND_STRING_DELAY("_SetDisplayMode _M _Rendered\n", delay);
    }
    if(leader_sequence_three_keys(KC_R, KC_D, KC_M)) {
        SEND_STRING_DELAY("_SetDisplayMode _M _", delay);
    }
    if(leader_sequence_three_keys(KC_R, KC_A, KC_U)) {
        SEND_STRING("_Audit3dmFile\n");
    }

    // Git key combos
    if(leader_sequence_two_keys(KC_G, KC_D)) {
        SEND_STRING("git diff\n");
    }
    if(leader_sequence_three_keys(KC_G, KC_D, KC_H)) {
        SEND_STRING("git diff HEAD~ 1\n");
    }
    if(leader_sequence_two_keys(KC_G, KC_F)) {
        SEND_STRING("git fetch\n");
    }
    if(leader_sequence_two_keys(KC_G, KC_S)) {
        SEND_STRING("git status\n");
    }
    if(leader_sequence_two_keys(KC_G, KC_G)) {
        SEND_STRING("git gui\n");
    }
    if(leader_sequence_two_keys(KC_G, KC_K)) {
        SEND_STRING("gitk\n");
    }
    if(leader_sequence_two_keys(KC_G, KC_L)) {
        SEND_STRING("git log\n");
    }
    if(leader_sequence_two_keys(KC_G, KC_P)) {
        SEND_STRING("git pull --ff-only\n");
    }
    if(leader_sequence_three_keys(KC_G, KC_S, KC_U)) {
        SEND_STRING("git submodule update --init --recursive\n");
    }
    // Rhino discourse keycombos
    if(leader_sequence_four_keys(KC_D, KC_R, KC_S, KC_I)) {
        SEND_STRING("Please run the Rhino command ` _SystemInfo`  and post the result in a reply.");
    }
    // QMK commands, using K for keyboard instead of Q of QMK
    // because Q is already a tapdance participant.
    if(leader_sequence_two_keys(KC_K, KC_C)) {
        SEND_STRING("qmk compile -kb splitkb/kyria/rev3 -km jesterKing\n");
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

    oled_write_P(PSTR("BL"), current_default_layer == _BLENDER);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("RH"), current_default_layer == _RHINO);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("GAME"), current_default_layer == _GAMER);
    oled_write_P(PSTR(" \n"), false);

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
#if RGB_MATRIX_ENABLE
            if (clockwise) {
                rgblight_increase_val_noeeprom();
            } else {
                rgblight_decrease_val_noeeprom();
            }
#endif //RGB_MATRIX_ENABLE
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
#if RGB_MATRIX_ENABLE
            uint8_t speed = rgblight_get_speed();
            if (clockwise) {
                speed+=10;
                speed = speed > 220 ? 220 : speed;
            } else {
                speed-=10;
                speed = speed < 30 ? 30 : speed;
            }
            rgblight_set_speed(speed);
#endif // RGB_MATRIX_ENABLE
        } else if(layer==_RAISE) {
#if RGB_MATRIX_ENABLE
            if (clockwise) {
                rgblight_enable_noeeprom();
            } else {
                rgblight_disable_noeeprom();
            }
#endif //RGB_MATRIX_ENABLE
        }
    }
    return true;
}

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();                          // enables Rgb, without saving settings
#if RGB_MATRIX_ENABLE
    rgblight_set_speed(80);
    while(rgblight_get_val() > 72)
    {
        rgblight_decrease_val();
    }
    rgb_matrix_set_speed(40);
#endif //RGB_MATRIX_ENABLE
    rgblight_sethsv_noeeprom(255, 128, 64);             // sets the color to teal/cyan without saving
    rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL + 2); // sets mode to Fast breathing without saving
#ifdef CONSOLE_ENABLE
    debug_enable = true;
    debug_matrix = true;
    debug_keyboard = true;
#endif
}

void suspend_power_down_user(void) {
    rgblight_suspend();
}

void suspend_wakeup_init_user(void) {
    rgblight_wakeup();
}
