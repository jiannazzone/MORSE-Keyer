# MORSE Keyer

A DIY iambic paddle keyer for the [MORSE game](https://morse.withgoogle.com/learn/), built with a Pro Micro and QMK firmware.

## Features

- Iambic paddle input (dot/dash paddles)
- Fire button for sending characters
- Plug-and-play USB HID keyboard (no drivers needed)
- Works on Windows, Mac, and Linux

## Bill of Materials

| Component | Quantity | Notes |
|-----------|----------|-------|
| Pro Micro (ATmega32U4) | 1 | 5V/16MHz version |
| Low-profile keyboard switches | 3 | For dot, dash, and fire |
| Enclosure | 1 | 3D printed (see below) |
| USB data cable | 1 | For connection to computer |

## Wiring

| Switch | Pin | Function |
|--------|-----|----------|
| Left paddle | D4 | Dot (sends Ctrl) |
| Right paddle | C6 | Dash (sends Space) |
| Fire button | D7 | Fire (sends Enter) |

Each switch connects between the pin and GND.

## 3D Printed Enclosure

<!-- TODO: Add enclosure documentation -->

*This section is under construction.*


## Assembly Guide

<!-- TODO: Add enclosure documentation -->

*This section is under construction.*

## Firmware

The keyer uses [QMK Firmware](https://qmk.fm/) to act as a USB keyboard.

### Option 1: Flash Pre-compiled Firmware (Recommended)

Download the latest `morse_keyer_default.hex` from the [Releases](../../releases) page.

#### Windows / Mac

1. Download and install [QMK Toolbox](https://github.com/qmk/qmk_toolbox/releases)
2. Open QMK Toolbox
3. Select the `.hex` file you downloaded
4. Set MCU to `atmega32u4`
5. Connect your Pro Micro and short the RST pin to GND twice quickly (within 1 second) to enter bootloader mode. I use some fine-tipped tweezers for this.
6. Click "Flash"

#### Linux
Let's be honest, you're used to this crap.

Install `avrdude` using your distro package manager and run:

```bash
# Enter bootloader mode first (short RST to GND twice quickly)
avrdude -p atmega32u4 -c avr109 -P /dev/ttyACM0 -U flash:w:morse_keyer_default.hex:i
```

> **Note:** The port may vary. Check `dmesg` after connecting to find the correct device.

### Option 2: Build from Source

If you want to customize the firmware:

1. [Set up QMK](https://docs.qmk.fm/#/newbs_getting_started)
2. Copy the `firmware` folder to your QMK keyboards directory:
   ```bash
   cp -r firmware ~/qmk_firmware/keyboards/morse_keyer
   ```
3. Compile and flash:
   ```bash
   qmk flash -kb morse_keyer -km default
   ```

### Entering Bootloader Mode

The Pro Micro uses the Caterina bootloader. To enter bootloader mode:

1. Connect the Pro Micro via USB
2. Short the RST pin to GND **twice quickly** (within ~1 second)
3. The bootloader will be active for about 8 seconds
4. Flash immediately when the device appears

> **Tip:** If you're having trouble, try shorting RST to GND once, wait a second, then short again.

### Customizing the Keymap

Edit `firmware/keymaps/default/keymap.c` to change the key assignments:

```c
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_LCTL,  // Dot (left paddle)
        KC_SPC,   // Dash (right paddle)
        KC_ENT    // Fire
    )
};
```

See the [QMK Keycodes documentation](https://docs.qmk.fm/#/keycodes) for available key options.

---

## License

MIT License
