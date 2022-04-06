#if !defined(SCANCODE_H)
#define SCANCODE_H


typedef enum
{
    K_SCANCODE_UNKNOWN = 0,

    /**
     *  \name Usage page 0x07
     *
     *  These values are from usage page 0x07 (USB keyboard page).
     */
    /* @{ */

    K_SCANCODE_A = 4,
    K_SCANCODE_B = 5,
    K_SCANCODE_C = 6,
    K_SCANCODE_D = 7,
    K_SCANCODE_E = 8,
    K_SCANCODE_F = 9,
    K_SCANCODE_G = 10,
    K_SCANCODE_H = 11,
    K_SCANCODE_I = 12,
    K_SCANCODE_J = 13,
    K_SCANCODE_K = 14,
    K_SCANCODE_L = 15,
    K_SCANCODE_M = 16,
    K_SCANCODE_N = 17,
    K_SCANCODE_O = 18,
    K_SCANCODE_P = 19,
    K_SCANCODE_Q = 20,
    K_SCANCODE_R = 21,
    K_SCANCODE_S = 22,
    K_SCANCODE_T = 23,
    K_SCANCODE_U = 24,
    K_SCANCODE_V = 25,
    K_SCANCODE_W = 26,
    K_SCANCODE_X = 27,
    K_SCANCODE_Y = 28,
    K_SCANCODE_Z = 29,

    K_SCANCODE_1 = 30,
    K_SCANCODE_2 = 31,
    K_SCANCODE_3 = 32,
    K_SCANCODE_4 = 33,
    K_SCANCODE_5 = 34,
    K_SCANCODE_6 = 35,
    K_SCANCODE_7 = 36,
    K_SCANCODE_8 = 37,
    K_SCANCODE_9 = 38,
    K_SCANCODE_0 = 39,

    K_SCANCODE_RETURN = 40,
    K_SCANCODE_ESCAPE = 41,
    K_SCANCODE_BACKSPACE = 42,
    K_SCANCODE_TAB = 43,
    K_SCANCODE_SPACE = 44,

    K_SCANCODE_MINUS = 45,
    K_SCANCODE_EQUALS = 46,
    K_SCANCODE_LEFTBRACKET = 47,
    K_SCANCODE_RIGHTBRACKET = 48,
    K_SCANCODE_BACKSLASH = 49, /**< Located at the lower left of the return
                                  *   key on ISO keyboards and at the right end
                                  *   of the QWERTY row on ANSI keyboards.
                                  *   Produces REVERSE SOLIDUS (backslash) and
                                  *   VERTICAL LINE in a US layout, REVERSE
                                  *   SOLIDUS and VERTICAL LINE in a UK Mac
                                  *   layout, NUMBER SIGN and TILDE in a UK
                                  *   Windows layout, DOLLAR SIGN and POUND SIGN
                                  *   in a Swiss German layout, NUMBER SIGN and
                                  *   APOSTROPHE in a German layout, GRAVE
                                  *   ACCENT and POUND SIGN in a French Mac
                                  *   layout, and ASTERISK and MICRO SIGN in a
                                  *   French Windows layout.
                                  */
    K_SCANCODE_NONUSHASH = 50, /**< ISO USB keyboards actually use this code
                                  *   instead of 49 for the same key, but all
                                  *   OSes I've seen treat the two codes
                                  *   identically. So, as an implementor, unless
                                  *   your keyboard generates both of those
                                  *   codes and your OS treats them differently,
                                  *   you should generate K_SCANCODE_BACKSLASH
                                  *   instead of this code. As a user, you
                                  *   should not rely on this code because K
                                  *   will never generate it with most (all?)
                                  *   keyboards.
                                  */
    K_SCANCODE_SEMICOLON = 51,
    K_SCANCODE_APOSTROPHE = 52,
    K_SCANCODE_GRAVE = 53, /**< Located in the top left corner (on both ANSI
                              *   and ISO keyboards). Produces GRAVE ACCENT and
                              *   TILDE in a US Windows layout and in US and UK
                              *   Mac layouts on ANSI keyboards, GRAVE ACCENT
                              *   and NOT SIGN in a UK Windows layout, SECTION
                              *   SIGN and PLUS-MINUS SIGN in US and UK Mac
                              *   layouts on ISO keyboards, SECTION SIGN and
                              *   DEGREE SIGN in a Swiss German layout (Mac:
                              *   only on ISO keyboards), CIRCUMFLEX ACCENT and
                              *   DEGREE SIGN in a German layout (Mac: only on
                              *   ISO keyboards), SUPERSCRIPT TWO and TILDE in a
                              *   French Windows layout, COMMERCIAL AT and
                              *   NUMBER SIGN in a French Mac layout on ISO
                              *   keyboards, and LESS-THAN SIGN and GREATER-THAN
                              *   SIGN in a Swiss German, German, or French Mac
                              *   layout on ANSI keyboards.
                              */
    K_SCANCODE_COMMA = 54,
    K_SCANCODE_PERIOD = 55,
    K_SCANCODE_SLASH = 56,

    K_SCANCODE_CAPSLOCK = 57,

    K_SCANCODE_F1 = 58,
    K_SCANCODE_F2 = 59,
    K_SCANCODE_F3 = 60,
    K_SCANCODE_F4 = 61,
    K_SCANCODE_F5 = 62,
    K_SCANCODE_F6 = 63,
    K_SCANCODE_F7 = 64,
    K_SCANCODE_F8 = 65,
    K_SCANCODE_F9 = 66,
    K_SCANCODE_F10 = 67,
    K_SCANCODE_F11 = 68,
    K_SCANCODE_F12 = 69,

    K_SCANCODE_PRINTSCREEN = 70,
    K_SCANCODE_SCROLLLOCK = 71,
    K_SCANCODE_PAUSE = 72,
    K_SCANCODE_INSERT = 73, /**< insert on PC, help on some Mac keyboards (but
                                   does send code 73, not 117) */
    K_SCANCODE_HOME = 74,
    K_SCANCODE_PAGEUP = 75,
    K_SCANCODE_DELETE = 76,
    K_SCANCODE_END = 77,
    K_SCANCODE_PAGEDOWN = 78,
    K_SCANCODE_RIGHT = 79,
    K_SCANCODE_LEFT = 80,
    K_SCANCODE_DOWN = 81,
    K_SCANCODE_UP = 82,

    K_SCANCODE_NUMLOCKCLEAR = 83, /**< num lock on PC, clear on Mac keyboards
                                     */
    K_SCANCODE_KP_DIVIDE = 84,
    K_SCANCODE_KP_MULTIPLY = 85,
    K_SCANCODE_KP_MINUS = 86,
    K_SCANCODE_KP_PLUS = 87,
    K_SCANCODE_KP_ENTER = 88,
    K_SCANCODE_KP_1 = 89,
    K_SCANCODE_KP_2 = 90,
    K_SCANCODE_KP_3 = 91,
    K_SCANCODE_KP_4 = 92,
    K_SCANCODE_KP_5 = 93,
    K_SCANCODE_KP_6 = 94,
    K_SCANCODE_KP_7 = 95,
    K_SCANCODE_KP_8 = 96,
    K_SCANCODE_KP_9 = 97,
    K_SCANCODE_KP_0 = 98,
    K_SCANCODE_KP_PERIOD = 99,

    K_SCANCODE_NONUSBACKSLASH = 100, /**< This is the additional key that ISO
                                        *   keyboards have over ANSI ones,
                                        *   located between left shift and Y.
                                        *   Produces GRAVE ACCENT and TILDE in a
                                        *   US or UK Mac layout, REVERSE SOLIDUS
                                        *   (backslash) and VERTICAL LINE in a
                                        *   US or UK Windows layout, and
                                        *   LESS-THAN SIGN and GREATER-THAN SIGN
                                        *   in a Swiss German, German, or French
                                        *   layout. */
    K_SCANCODE_APPLICATION = 101, /**< windows contextual menu, compose */
    K_SCANCODE_POWER = 102, /**< The USB document says this is a status flag,
                               *   not a physical key - but some Mac keyboards
                               *   do have a power key. */
    K_SCANCODE_KP_EQUALS = 103,
    K_SCANCODE_F13 = 104,
    K_SCANCODE_F14 = 105,
    K_SCANCODE_F15 = 106,
    K_SCANCODE_F16 = 107,
    K_SCANCODE_F17 = 108,
    K_SCANCODE_F18 = 109,
    K_SCANCODE_F19 = 110,
    K_SCANCODE_F20 = 111,
    K_SCANCODE_F21 = 112,
    K_SCANCODE_F22 = 113,
    K_SCANCODE_F23 = 114,
    K_SCANCODE_F24 = 115,
    K_SCANCODE_EXECUTE = 116,
    K_SCANCODE_HELP = 117,
    K_SCANCODE_MENU = 118,
    K_SCANCODE_SELECT = 119,
    K_SCANCODE_STOP = 120,
    K_SCANCODE_AGAIN = 121,   /**< redo */
    K_SCANCODE_UNDO = 122,
    K_SCANCODE_CUT = 123,
    K_SCANCODE_COPY = 124,
    K_SCANCODE_PASTE = 125,
    K_SCANCODE_FIND = 126,
    K_SCANCODE_MUTE = 127,
    K_SCANCODE_VOLUMEUP = 128,
    K_SCANCODE_VOLUMEDOWN = 129,
/* not sure whether there's a reason to enable these */
/*     K_SCANCODE_LOCKINGCAPSLOCK = 130,  */
/*     K_SCANCODE_LOCKINGNUMLOCK = 131, */
/*     K_SCANCODE_LOCKINGSCROLLLOCK = 132, */
    K_SCANCODE_KP_COMMA = 133,
    K_SCANCODE_KP_EQUALSAS400 = 134,

    K_SCANCODE_INTERNATIONAL1 = 135, /**< used on Asian keyboards, see
                                            footnotes in USB doc */
    K_SCANCODE_INTERNATIONAL2 = 136,
    K_SCANCODE_INTERNATIONAL3 = 137, /**< Yen */
    K_SCANCODE_INTERNATIONAL4 = 138,
    K_SCANCODE_INTERNATIONAL5 = 139,
    K_SCANCODE_INTERNATIONAL6 = 140,
    K_SCANCODE_INTERNATIONAL7 = 141,
    K_SCANCODE_INTERNATIONAL8 = 142,
    K_SCANCODE_INTERNATIONAL9 = 143,
    K_SCANCODE_LANG1 = 144, /**< Hangul/English toggle */
    K_SCANCODE_LANG2 = 145, /**< Hanja conversion */
    K_SCANCODE_LANG3 = 146, /**< Katakana */
    K_SCANCODE_LANG4 = 147, /**< Hiragana */
    K_SCANCODE_LANG5 = 148, /**< Zenkaku/Hankaku */
    K_SCANCODE_LANG6 = 149, /**< reserved */
    K_SCANCODE_LANG7 = 150, /**< reserved */
    K_SCANCODE_LANG8 = 151, /**< reserved */
    K_SCANCODE_LANG9 = 152, /**< reserved */

    K_SCANCODE_ALTERASE = 153, /**< Erase-Eaze */
    K_SCANCODE_SYSREQ = 154,
    K_SCANCODE_CANCEL = 155,
    K_SCANCODE_CLEAR = 156,
    K_SCANCODE_PRIOR = 157,
    K_SCANCODE_RETURN2 = 158,
    K_SCANCODE_SEPARATOR = 159,
    K_SCANCODE_OUT = 160,
    K_SCANCODE_OPER = 161,
    K_SCANCODE_CLEARAGAIN = 162,
    K_SCANCODE_CRSEL = 163,
    K_SCANCODE_EXSEL = 164,

    K_SCANCODE_KP_00 = 176,
    K_SCANCODE_KP_000 = 177,
    K_SCANCODE_THOUSANDSSEPARATOR = 178,
    K_SCANCODE_DECIMALSEPARATOR = 179,
    K_SCANCODE_CURRENCYUNIT = 180,
    K_SCANCODE_CURRENCYSUBUNIT = 181,
    K_SCANCODE_KP_LEFTPAREN = 182,
    K_SCANCODE_KP_RIGHTPAREN = 183,
    K_SCANCODE_KP_LEFTBRACE = 184,
    K_SCANCODE_KP_RIGHTBRACE = 185,
    K_SCANCODE_KP_TAB = 186,
    K_SCANCODE_KP_BACKSPACE = 187,
    K_SCANCODE_KP_A = 188,
    K_SCANCODE_KP_B = 189,
    K_SCANCODE_KP_C = 190,
    K_SCANCODE_KP_D = 191,
    K_SCANCODE_KP_E = 192,
    K_SCANCODE_KP_F = 193,
    K_SCANCODE_KP_XOR = 194,
    K_SCANCODE_KP_POWER = 195,
    K_SCANCODE_KP_PERCENT = 196,
    K_SCANCODE_KP_LESS = 197,
    K_SCANCODE_KP_GREATER = 198,
    K_SCANCODE_KP_AMPERSAND = 199,
    K_SCANCODE_KP_DBLAMPERSAND = 200,
    K_SCANCODE_KP_VERTICALBAR = 201,
    K_SCANCODE_KP_DBLVERTICALBAR = 202,
    K_SCANCODE_KP_COLON = 203,
    K_SCANCODE_KP_HASH = 204,
    K_SCANCODE_KP_SPACE = 205,
    K_SCANCODE_KP_AT = 206,
    K_SCANCODE_KP_EXCLAM = 207,
    K_SCANCODE_KP_MEMSTORE = 208,
    K_SCANCODE_KP_MEMRECALL = 209,
    K_SCANCODE_KP_MEMCLEAR = 210,
    K_SCANCODE_KP_MEMADD = 211,
    K_SCANCODE_KP_MEMSUBTRACT = 212,
    K_SCANCODE_KP_MEMMULTIPLY = 213,
    K_SCANCODE_KP_MEMDIVIDE = 214,
    K_SCANCODE_KP_PLUSMINUS = 215,
    K_SCANCODE_KP_CLEAR = 216,
    K_SCANCODE_KP_CLEARENTRY = 217,
    K_SCANCODE_KP_BINARY = 218,
    K_SCANCODE_KP_OCTAL = 219,
    K_SCANCODE_KP_DECIMAL = 220,
    K_SCANCODE_KP_HEXADECIMAL = 221,

    K_SCANCODE_LCTRL = 224,
    K_SCANCODE_LSHIFT = 225,
    K_SCANCODE_LALT = 226, /**< alt, option */
    K_SCANCODE_LGUI = 227, /**< windows, command (apple), meta */
    K_SCANCODE_RCTRL = 228,
    K_SCANCODE_RSHIFT = 229,
    K_SCANCODE_RALT = 230, /**< alt gr, option */
    K_SCANCODE_RGUI = 231, /**< windows, command (apple), meta */

    K_SCANCODE_MODE = 257,    /**< I'm not sure if this is really not covered
                                 *   by any of the above, but since there's a
                                 *   special KMOD_MODE for it I'm adding it here
                                 */

    /* @} *//* Usage page 0x07 */

    /**
     *  \name Usage page 0x0C
     *
     *  These values are mapped from usage page 0x0C (USB consumer page).
     */
    /* @{ */

    K_SCANCODE_AUDIONEXT = 258,
    K_SCANCODE_AUDIOPREV = 259,
    K_SCANCODE_AUDIOSTOP = 260,
    K_SCANCODE_AUDIOPLAY = 261,
    K_SCANCODE_AUDIOMUTE = 262,
    K_SCANCODE_MEDIASELECT = 263,
    K_SCANCODE_WWW = 264,
    K_SCANCODE_MAIL = 265,
    K_SCANCODE_CALCULATOR = 266,
    K_SCANCODE_COMPUTER = 267,
    K_SCANCODE_AC_SEARCH = 268,
    K_SCANCODE_AC_HOME = 269,
    K_SCANCODE_AC_BACK = 270,
    K_SCANCODE_AC_FORWARD = 271,
    K_SCANCODE_AC_STOP = 272,
    K_SCANCODE_AC_REFRESH = 273,
    K_SCANCODE_AC_BOOKMARKS = 274,

    /* @} *//* Usage page 0x0C */

    /**
     *  \name Walther keys
     *
     *  These are values that Christian Walther added (for mac keyboard?).
     */
    /* @{ */

    K_SCANCODE_BRIGHTNESSDOWN = 275,
    K_SCANCODE_BRIGHTNESSUP = 276,
    K_SCANCODE_DISPLAYSWITCH = 277, /**< display mirroring/dual display
                                           switch, video mode switch */
    K_SCANCODE_KBDILLUMTOGGLE = 278,
    K_SCANCODE_KBDILLUMDOWN = 279,
    K_SCANCODE_KBDILLUMUP = 280,
    K_SCANCODE_EJECT = 281,
    K_SCANCODE_SLEEP = 282,

    K_SCANCODE_APP1 = 283,
    K_SCANCODE_APP2 = 284,

    /* @} *//* Walther keys */

    /**
     *  \name Usage page 0x0C (additional media keys)
     *
     *  These values are mapped from usage page 0x0C (USB consumer page).
     */
    /* @{ */

    K_SCANCODE_AUDIOREWIND = 285,
    K_SCANCODE_AUDIOFASTFORWARD = 286,

    /* @} *//* Usage page 0x0C (additional media keys) */

    /* Add any other keys here. */

    K_NUM_SCANCODES = 512 /**< not a key, just marks the number of scancodes
                                 for array bounds */
} KeyScancode;


#endif // SCANCODE_H
