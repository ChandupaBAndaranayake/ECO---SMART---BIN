#define BLYNK_TEMPLATE_ID "TMPL6ajCvEf5Y"
#define BLYNK_TEMPLATE_NAME "Dust bin"
#define BLYNK_FIRMWARE_VERSION "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_AUTH_TOKEN "DfYbYhXEV3WddioYkrQYftavtXdKec50"

char auth[] = BLYNK_AUTH_TOKEN; // Auth Token from the Blynk App
char ssid[] = "bruh"; // Your WiFi SSID
char pass[] = "bruh1124"; // Your WiFi password

#define Threshold 400
#define MQ2pin A0

// Sonar sensor pins
#define TRIG_PIN 5  // corresponds to D1 on ESP8266
#define ECHO_PIN 4  // corresponds to D2 on ESP8266

// Define sound velocity in cm/uS
#define SOUND_VELOCITY 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCm;
float distanceInch;

// Timer for Blynk
BlynkTimer timer;

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  Serial.println(auth);
  
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Set a timer to send sensor data every second
  timer.setInterval(1000L, sendSensorData);
}

void loop() {
  Blynk.run();
  timer.run();
}

void sendSensorData() {
  double alchlLevel = getAlcoholLevel();
  Serial.println(alchlLevel);
  Blynk.virtualWrite(V2, alchlLevel);

  double distance = getSonarDistance();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  Blynk.virtualWrite(V1, distance);
}

double getAlcoholLevel() {
  double sensorValue;
  sensorValue = analogRead(MQ2pin); // read analog input pin A0

  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);

  // Determine the status
  if (sensorValue > Threshold) {
    Serial.println(" | Smoke detected!");
  } else {
    Serial.println(" | Normal!");
  }
  return sensorValue;
}

double getSonarDistance() {
  // Clears the TRIG_PIN
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Sets the TRIG_PIN on HIGH state for 10 microseconds
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Reads the ECHO_PIN, returns the sound wave travel time in microseconds
  duration = pulseIn(ECHO_PIN, HIGH);

  // Calculating the distance
  distanceCm = duration * SOUND_VELOCITY / 2;

  // Convert to inches
  distanceInch = distanceCm * CM_TO_INCH;

  return distanceCm;
}
