#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

// set k00 [Esc] as dfu-escape key
#define QMK_ESC_INPUT B6 // usually ROW
#define QMK_ESC_OUTPUT D3 // usually COL

// set k14 [Backspace] as reset key
#define BOOTMAGIC_LITE_ROW 1
#define BOOTMAGIC_LITE_COLUMN 4

#define QMK_LED B0
