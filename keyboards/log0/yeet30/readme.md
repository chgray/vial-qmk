dfu-programmer.exe atmega32u4 erase --force

dfu-programmer.exe atmega32u4 flash c:\Temp\log0_yeet30_via.hex --debug 2


# Flashing bootloader
avrdude -c usbtiny -p atmega32u4 -U ./BootloaderDFU.elf
https://github.com/abcminiuser/lufa.git

make -C ../../LUFA/../Bootloaders/DFU/ clean elf ARCH=AVR8 MCU=atmega32u4 BOARD=NONE FLASH_SIZE_KB=32 BOOT_SECTION_SIZE_KB=4 F_USB=16000000 DEBUG_LEVEL=0

avrdude -c usbtiny -p atmega32u4

C:\Users\chgray\AppData\Local\QMK\QMK Toolbox\0.1.1
