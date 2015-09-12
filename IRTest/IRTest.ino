
// Program remote:
//   Press Setup until red LED on top stays on
//   Enter code 605

#include <IRremote.h>        // Must be located in sketchbook
//  libraries folder

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;
int fadeValue = 0;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();        // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    if (results.value == 1168 && fadeValue < 255) {
      fadeValue++;
      analogWrite(9, fadeValue);
      delay(30);
      Serial.println(fadeValue);
    }
    else {
      if (results.value == 3216 && fadeValue > 0) {
        fadeValue--;
        analogWrite(9, fadeValue);
        delay(30);
        Serial.println(fadeValue);
      }
    }
    Serial.println(results.value);
    irrecv.resume();          // Receive the next value
  }
}

