## LED CUBE
This project uses an Arduino to control a 3D LED Cube that cycles through a set of predefined images. Each image is displayed layer by layer using a set of LEDs.

## Components

- Arduino board (e.g., Arduino Uno)
- 27 LEDs
- 3 Transistors (to control the LED layers)
- 9 Resistors(150 Ohm)

## Pin Connections

The Arduino board is connected to the components as follows:

- **LED Pins:**
  - Pin 2 → LED 1
  - Pin 3 → LED 2
  - Pin 4 → LED 3
  - Pin 5 → LED 4
  - Pin 6 → LED 5 (middle LED)
  - Pin 7 → LED 6
  - Pin 8 → LED 7
  - Pin 9 → LED 8
  - Pin 10 → LED 9

- **Transistor Pins:**
  - Pin 18 → Transistor 1 (controls the first layer of LEDs)
  - Pin 19 → Transistor 2 (controls the second layer of LEDs)
  - Pin 20 → Transistor 3 (controls the third layer of LEDs)

## Code Overview

The code is designed to cycle through 26 different images, each represented as a 3D array. Each image is displayed by:

1. Selecting a layer using the transistors.
2. Setting the state of each LED according to the image data.
3. Delaying for a short period to allow the image to be visible.

### Functions

- **`setup()`**: Initializes all the pins as output pins.
- **`loop()`**: Cycles through all the images and displays each one for a set duration.
- **`displayImage(image)`**: Controls which LEDs are on or off for each layer of the given image.

### Image Format

Each image is defined as a 3D array with dimensions `[3][3][3]`, representing:
- Three layers of the display
- Each layer is a 3x3 grid of LEDs
- Values in the array (0 or 1) determine if an LED is off or on


