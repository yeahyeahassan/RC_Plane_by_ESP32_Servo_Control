#include <ESP32Servo.h>

// Initialize Servo objects for ESC and three additional servos
Servo ESC; 
Servo myservo2; 
Servo myservo3; 
Servo myservo4; 

// Define pin numbers for servos
const int servo2pin = 14; // Angle initiates from 90 degree
const int servo3pin = 27; // Angle initiates from 90 degree
const int servo4pin = 32; // Angle initiates from 90 degree

// Variable to store the received character from Serial communication
char receivedChar;

// Setup function, runs once when the program starts
void setup() {
  // Begin serial communication at 115200 baud
  Serial.begin(115200);

  // Attach ESC to pin 32
  ESC.attach(12);

  // Attach servos to their respective pins
  myservo2.attach(servo2pin);
  myservo3.attach(servo3pin);
  myservo4.attach(servo4pin);
}

// Loop function, runs repeatedly as long as the program is running
void loop() {
  // Check if there's data available in the Serial buffer
  if (Serial.available()) {
    // Read the received character
    receivedChar = Serial.read();

    // Perform common actions for 'x' and other characters
    if (receivedChar == 'x') {
      BLDC(); // Run the BLDC function
    } else if (receivedChar == 's') {
      ESC.write(0); // Set ESC servo to 0 position
    } else if (receivedChar == 'A') {
      FLY(); // Run the FLY function
    } else if (receivedChar == 'B') {
      LAND(); // Run the LAND function
    } else if (receivedChar == 'R') {
      RIGHT(); // Run the RIGHT function
    } else if (receivedChar == 'L') {
      LEFT(); // Run the LEFT function
    }
  }
}

// Function to control BLDC motor
void BLDC() {
  for (int i = 0; i <= 130; i++) {
    ESC.write(i);
    delay(20);
  }
  for (int i = 0; i >= 130; i--) {
    ESC.write(i);
    delay(20);
  }
  // Print message and set ESC servo to a high value
  Serial.println("Bldc on");
  delay(2000);
  ESC.write(2000);
}

// Function to set all three servos to 0 position for flying
void FLY() {
  myservo2.write(0);
  myservo3.write(0);
  myservo4.write(0);
  Serial.println("Flying");
}

// Function to turn right by adjusting servo angles
void RIGHT() {
  myservo2.write(0);
  myservo3.write(180);
  myservo4.write(90);
  Serial.println("RightTurning");
}

// Function to turn left by adjusting servo angles
void LEFT() {
  myservo2.write(180);
  myservo3.write(0);
  myservo4.write(90);
  Serial.println("LeftTurning");
}

// Function to set all three servos to 180 for landing
void LAND() {
  myservo2.write(180);
  myservo3.write(180);
  myservo4.write(180);
  Serial.println("Landing");
}


//For adjusting speed of the plane
 
void ADJUST_SPEED() {
  // Prompt the user to enter a speed value
  Serial.println("Enter speed value (0-130): ");
  
  // Wait for user input
  while (!Serial.available()) {
    delay(10);
  }

  // Read the entered speed value
  int speedValue = Serial.parseInt();

  // Validate the speed value to be within a reasonable range
  if (speedValue >= 0 && speedValue <= 130) {
    // Adjust the speed of the BLDC motor
    for (int i = 0; i <= speedValue; i++) {
      ESC.write(i);
      delay(20);
    }

    // Print a message indicating the speed adjustment
    Serial.print("Speed adjusted to: ");
    Serial.println(speedValue);
  } else {
    // Print an error message for an invalid speed value
    Serial.println("Invalid speed value. Please enter a value between 0 and 130.");
  }
}
