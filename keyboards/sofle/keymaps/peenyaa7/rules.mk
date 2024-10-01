
# OLED
OLED_ENABLE = yes
OLED_DRIVER = SSD1306

# Encoder
ENCODER_ENABLE = yes
#ENCODER_MAP_ENABLE = yes

CONSOLE_ENABLE = no
EXTRAKEY_ENABLE = yes

# RGB Light
RGBLIGHT_ENABLE = yes
RGBLIGHT_DRIVER = WS2812

# RGB Matrix
RGB_MATRIX_ENABLE = no
#RGB_MATRIX_DRIVER = WS2812
# RGB_MATRIX_CUSTOM_USER = yes

# Key Override
KEY_OVERRIDE_ENABLE = yes

# Reduce firmware size
AUDIO_ENABLE = no
BLUETOOTH_ENABLE = no
MIDI_ENABLE = no
FAUXCLICKY_ENABLE = no
HD44780_ENABLE = no
EXTRAFLAGS += -flto
EXTRAKEY_ENABLE = no
