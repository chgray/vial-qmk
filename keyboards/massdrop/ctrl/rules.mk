# project specific files
SRC += config_led.c

#For platform and packs
ARM_ATSAM = SAMD51J18A
MCU = cortex-m4

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no      # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE = no        # Mouse keys(+4700)
EXTRAKEY_ENABLE = no        # Audio control and System control(+450)
CONSOLE_ENABLE = yes        # Console for debug(+400)
COMMAND_ENABLE = no          # Commands for debug and configuration
NKRO_ENABLE = yes           # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
MIDI_ENABLE = no            # MIDI controls
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no           # Audio output

# RGBLIGHT_ENABLE = yes

RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = custom
#RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow


#SWAP_HANDS_ENABLE= no  # Allow swapping hands of keyboard

#EXTRAFLAGS += -flto -save-temps
