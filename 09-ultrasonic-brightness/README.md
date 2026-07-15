# arduino-practice
I'm working through Arduino tutorials to learn the basics of embedded systems. I plan to move on to an STM32 board soon.

## Wiring Diagram

To build this project, connect the components to your Arduino board as described in the table and details below. 

### Connection Table

| Component | Component Pin | Arduino Pin | Description |
| :--- | :--- | :--- | :--- |
| **HC-SR04 Sensor** | VCC | 5V | Power Supply (+5V) |
| **HC-SR04 Sensor** | GND | GND | Ground |
| **HC-SR04 Sensor** | Trig | Pin 9 | Trigger Signal (Output) |
| **HC-SR04 Sensor** | Echo | Pin 10 | Echo Signal (Input) |
| **LED** | Anode (+) | Pin 3 (PWM) | Light Output (Must be a PWM pin `~`) |
| **LED** | Cathode (-) | GND (via Resistor) | Ground (Connect through a 220Ω resistor) |

---

### Hardware Connection Details

1. **HC-SR04 Ultrasonic Distance Sensor:**
   * Connect the **VCC** pin of the sensor to the **5V** pin on the Arduino.
   * Connect the **GND** pin of the sensor to any **GND** pin on the Arduino.
   * Connect the **Trig (Trigger)** pin to **Digital Pin 9**. This pin triggers the ultrasonic sound waves.
   * Connect the **Echo** pin to **Digital Pin 10**. This pin measures the duration of the returning sound wave.

2. **LED Assembly (PWM Control):**
   * Connect the longer leg (Anode / positive) of the LED to **Digital Pin 3**. *Note: Pin 3 supports PWM (Pulse Width Modulation), which is crucial for fading the LED brightness smoothly.*
   * Connect the shorter leg (Cathode / negative) of the LED to a **220Ω resistor**.
   * Connect the other end of the resistor to any **GND** pin on the Arduino to complete the circuit and protect the LED from high current.
  
   * ## Notes

The original exercise called for using an LDR or potentiometer, but I didn't have either component on hand. Instead, I adapted the same "read an analog input, scale it to an output" logic using the HC-SR04 ultrasonic sensor — brightness increases as distance decreases.

I also added a simple weighted average (`y = y*0.5 + t*0.5`) to smooth out the raw sensor readings before writing them to the LED, since the distance measurements were noisy on their own.
