/*GR-KURUMI Sketch Template Version: V2.02*/
#include <Arduino.h>

// Pin 22,23,24 are assigned to RGB LEDs.
#define LED_RED    22 // LOW active
#define LED_GREEN  23 // LOW active
#define LED_BLUE   24 // LOW active
int before=0;
int average=0;
int cnt;
int VR0[20];
// the setup routine runs once when you press reset:
void setup() {
  //setPowerManagementMode(PM_STOP_MODE, 0, 1023); //Set CPU STOP_MODE in delay()
  //setOperationClockMode(CLK_LOW_SPEED_MODE); //Set CPU clock from 32MHz to 32.768kHz

  // initialize the digital pin as an output.
  Serial.begin(9600);
  Serial2.begin(115200);
//  Serial.print("Temperature: ");
//  Serial.println(getTemperature(TEMP_MODE_CELSIUS)); //temperature from the sensor in MCU
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);

  pinMode(A0, INPUT);
  analogReference(DEFAULT);

  // turn the LEDs on, glow white.
  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_GREEN, HIGH);
//  digitalWrite(LED_BLUE, LOW);
}

// the loop routine runs over and over again forever:
void loop() {
//  Serial.println("Hello");
  char szBuf[256];
  int i;
  int sum,value;
  value = analogRead(A0);
  if (cnt == 10) {
  cnt = 0;
  }
  VR0[cnt] = value;
  cnt++;
  for (i = 0; i < 10;i++) {
    sum += VR0[i];
  }
  average = sum / 40;
  if (average != before){
    sprintf(szBuf, "A0 - %d", average);
    Serial2.println(szBuf);
    digitalWrite(LED_BLUE, LOW);   // turn the RED LED off, glow sky blue.
  } else {
    digitalWrite(LED_BLUE, HIGH);  // turn the BLUE LED off, glow yellow.
  }
  before = average;
  delay(50);                   // wait 200ms

//  digitalWrite(LED_RED, LOW);    // turn the RED LED on
//  digitalWrite(LED_BLUE, HIGH); // turn the GREEN LED off, glow pink.
//  delay(200);                   // wait 200ms

//  digitalWrite(LED_GREEN, LOW);  // turn the GREEN LED on
  
//  delay(200);                   // wait for a second

//  digitalWrite(LED_BLUE, LOW);   // turn the BLUE LED on
}
