#include QMK_KEYBOARD_H

#define ESCTL CTL_T(KC_ESC)
#define SHINS LSFT(KC_INS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_all(
     KC_TAB,    KC_Q,    KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
      ESCTL,    KC_A,    KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,    KC_QUOT, LT(2,KC_ENT),
    KC_LSFT,    KC_Z,    KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
      MO(3), KC_LALT, KC_LGUI, KC_BSPC,   KC_NO,       LT(1, KC_SPC), KC_RGUI, KC_RALT
  ),
  [1] = LAYOUT_all(
    KC_GRV,  KC_1,        KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL,
    KC_TRNS, KC_LPRN,  KC_RPRN,  KC_DOT, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_SCLN, KC_TRNS,
    KC_TRNS, RGB_TOG, RGB_SMOD, KC_TRNS, KC_PAUSE,KC_TRNS,   SHINS, KC_COLN, KC_MINS, KC_EQL, KC_BSLS, KC_TRNS,
    KC_TRNS, KC_TRNS,  KC_TRNS,  KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [2] = LAYOUT_all(
    KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS,
    KC_TRNS, RGB_SAI, RGB_SAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, KC_COLN, KC_TRNS,
    KC_TRNS, RGB_HUI, RGB_HUD, RGB_VAI, RGB_VAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_UNDS, KC_PLUS, KC_PIPE, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS
  ),
  [3] = LAYOUT_all(
    KC_PSCR,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_F11, KC_F12,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS,
    KC_TRNS, BL_TOGG, KC_TRNS,  BL_INC,  BL_DEC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET
  ),
};

uint32_t layer_state_set_kb(uint32_t state) {
	uint32_t layer = 0, led_pins = 0;

	for (uint8_t i = 0; i < 8; i++) {
		if (state & (1<<i)) {
			layer = i;
		}
	}

	switch (layer) {
#if defined(LAYER_LED_STACK)
		case 3:
			led_pins |= (1<<PD6);
		case 2:
			led_pins |= (1<<PD1);
		case 1:
			led_pins |= (1<<PD0);
#elif defined(LAYER_LED_SYMMETRIC)
		case 3:
		case 2:
			led_pins |= (1<<PD0 | 1<<PD6);
			if (layer == 2) break;
		case 1:
			led_pins |= (1<<PD1);
#endif
	}

	PORTD &= ~(1<<PD0 | 1<<PD1 | 1<<PD6);
	PORTD |= led_pins;

	return state;
}
