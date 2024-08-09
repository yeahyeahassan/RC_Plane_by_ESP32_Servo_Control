# 🚀 RC Plane by ESP32 Servo Control

## 📚 Setup and Initialization

In our setup, we're initializing four Servo objects:
1. **ESC** - This controls the Electronic Speed Controller (ESC) for our BLDC motor.
2. **Servo 2** - Controls one of the key servos for flight.
3. **Servo 3** - Another essential servo for maneuvering.
4. **Servo 4** - Yet another servo for balance and control.

We define specific pins for each servo to ensure they are properly connected:

- `servo2pin = 14` - Servo 2 starts at a 90-degree angle.
- `servo3pin = 27` - Servo 3 also starts at a 90-degree angle.
- `servo4pin = 32` - Servo 4 begins at a 90-degree angle too.

The communication with the ESP32 is handled through serial communication at a baud rate of `115200`. 🎛️
---

## ⚙️ Main Functions

🔄 **Main Loop**: The main loop constantly checks for serial input to perform different actions:
- **'x'**: Activates the BLDC motor with a smooth ramp-up and ramp-down sequence. 
- **'s'**: Stops the BLDC motor.
- **'A'**: Initiates the flying mode by setting all servos to 0 degrees.
- **'B'**: Triggers landing mode by setting all servos to 180 degrees.
- **'R'**: Turns the vehicle to the right by adjusting the servos.
- **'L'**: Turns the vehicle to the left with appropriate servo adjustments.

---

## 🛠️ Detailed Functions

1. **BLDC Control** 🌀:
   - Gradually increases the motor's speed from 0 to 130 and back down, with a short delay for smooth transitions.
   - Prints "Bldc on" when activated.

2. **Flying** ✈️:
   - Sets all servos to 0 degrees to prepare the vehicle for flight and displays "Flying" in the serial monitor.

3. **Turning Right** 🔄:
   - Adjusts servos to create a right-turning motion, then shows "RightTurning" in the serial monitor.

4. **Turning Left** 🔁:
   - Adjusts servos to create a left-turning motion and prints "LeftTurning" to the serial monitor.

5. **Landing** 🛬:
   - Positions all servos at 180 degrees for a smooth landing and displays "Landing".

6. **Speed Adjustment** ⚡:
   - Prompts the user to enter a speed value between 0 and 130.
   - Adjusts the BLDC motor speed based on the user's input, with a feedback message showing the adjusted speed or an error message if the input is out of range.

---

With this setup, you've got a fully functional code to control a flying vehicle with your ESP32! 🚁 Remember, the proper hardware setup and connections are crucial to make this work seamlessly. Happy flying! 🛫🌟

![Thank You](https://img.shields.io/badge/Thank%20You!-blue?style=flat-square&logo=smile)

<!-- Graphical GIF Animation -->
<div class="gif-container" style="text-align: center; margin-bottom: 20px;">
  <img src="https://i.giphy.com/media/v1.Y2lkPTc5MGI3NjExYzdob2I4cHdsdWhnbmtmYTBxbnk4cnl2YjZ1bGw5ZGZvMXBwdWc4bSZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/00n6TSoGffGTLXSMPO/giphy.gif" alt="Working on it GIF" />
</div>

