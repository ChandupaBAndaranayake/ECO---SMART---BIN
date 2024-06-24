#include <Servo.h>

const int trigPin = 7;
const int echoPin = 6;
const int servoPin = 9;
const int distanceThreshold = 50; // 100 cm
const int servoOpenPosition = 90; // Position to open the door
const int servoClosedPosition = 0; // Position to close the door
const int servoSpeed = 10; // Adjust speed of the servo (lower is slower)
const int initializationSpeed = 4; // Adjust speed for initialization

Servo myServo;

void setup() {
  Serial.begin(9600); // Start the Serial communication
  myServo.attach(servoPin); // Attach the servo on pin 9

  // Initialize the servo position to closed gradually
  for (int pos = 0; pos <= servoClosedPosition; pos++) {
    myServo.write(pos);
    delay(initializationSpeed);
  }

  pinMode(trigPin, OUTPUT); // Set the trigPin as an OUTPUT
  pinMode(echoPin, INPUT);  // Set the echoPin as an INPUT
}

void loop() {
  long duration;
  int distance;

  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Set the trigPin HIGH for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin, return the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (round trip)

  // Print the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <= distanceThreshold) {
    // If an object is within 100 cm, open the dustbin door (90 degrees)
    moveServo(servoOpenPosition);
  } else {
    // If no object is within 100 cm, close the dustbin door (0 degrees)
    moveServo(servoClosedPosition);
  }

  delay(500); // Wait for 500 milliseconds before the next loop
}

void moveServo(int targetPosition) {
  int currentPosition = myServo.read(); // Get the current position of the servo

  if (currentPosition < targetPosition) {
    for (int pos = currentPosition; pos <= targetPosition; pos++) {
      myServo.write(pos); // Move the servo to the current position
      delay(servoSpeed); // Adjust the speed of the servo
    }
  } else {
    for (int pos = currentPosition; pos >= targetPosition; pos--) {
      myServo.write(pos); // Move the servo to the current position
      delay(servoSpeed); // Adjust the speed of the servo
    }
  }
}
