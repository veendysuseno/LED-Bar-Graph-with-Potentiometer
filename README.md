# LED Bar Graph with Potentiometer

## Description

This project controls a bar graph of 10 LEDs using a potentiometer as an analog input. The potentiometer adjusts the number of LEDs that are turned on, depending on the position of the knob.

## Components

- Arduino (e.g., Arduino Uno)
- Potentiometer
- 10 LEDs
- Jumper Wires
- Resistors (330Ω for each LED)

## Pin Configuration

| Component     | Arduino Pin      |
| ------------- | ---------------- |
| Potentiometer | A0 (Analog Pin)  |
| LED 1         | 2 (Digital Pin)  |
| LED 2         | 3 (Digital Pin)  |
| LED 3         | 4 (Digital Pin)  |
| LED 4         | 5 (Digital Pin)  |
| LED 5         | 6 (Digital Pin)  |
| LED 6         | 7 (Digital Pin)  |
| LED 7         | 8 (Digital Pin)  |
| LED 8         | 9 (Digital Pin)  |
| LED 9         | 10 (Digital Pin) |
| LED 10        | 11 (Digital Pin) |

## Code

```cpp
const int analogPin = 0; // Pin for the potentiometer
const int ledCount = 10; // Number of LEDs in the bar graph
int ledPins[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 }; // LED pin array

void setup() {
  // Set all pins for LEDs as output
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    pinMode(ledPins[thisLed], OUTPUT);
  }
}

void loop() {
  // Read the potentiometer value (0 to 1023)
  int sensorReading = analogRead(analogPin);

  // Map the sensor reading to a range between 0 and the number of LEDs
  int ledLevel = map(sensorReading, 0, 1023, 0, ledCount);

  // Loop through the LED pins and control their state
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    // Turn on LEDs up to the level determined by the potentiometer
    if (thisLed < ledLevel) {
      digitalWrite(ledPins[thisLed], HIGH);
    } else {
      digitalWrite(ledPins[thisLed], LOW);
    }
  }
}
```

## How It Works

1. Initialization:

   - The setup() function configures the relay pin as an output and the button pins as inputs.
   - Pull-up resistors are enabled for the button pins to ensure they are read correctly.

2. Relay Control:
   - The loop() function continuously checks the state of the buttons.
   - If the "on" button is pressed (LOW), the relay is turned on (HIGH).
   - If the "off" button is pressed (LOW), the relay is turned off (LOW).

## Usage

1. Connect the relay module and buttons to the appropriate pins on the Arduino.
2. Upload the code to the Arduino board.
3. Press the "on" button to activate the relay and the "off" button to deactivate it.

## Notes

- Ensure that the relay module is rated for the voltage and current of the device you plan to control.
- Use pull-up resistors or enable the internal pull-ups to ensure reliable button readings.
