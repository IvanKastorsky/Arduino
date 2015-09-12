/*
  SmartRegua
 */

#include <IRremote.h>

const int IR_PIN = 2;
IRrecv irrecv(IR_PIN);
decode_results results;

const int Rele_1 =  8;
const int Rele_2 =  9;
const int Rele_3 =  10;
const int Rele_4 =  11;

int FirstBlood = 0;
int Status1 = 0;
int Status2 = 0;
int Status3 = 0;
int Status4 = 0;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();

  pinMode(Rele_1, OUTPUT);
  pinMode(Rele_2, OUTPUT);
  pinMode(Rele_3, OUTPUT);
  pinMode(Rele_4, OUTPUT);
  pinMode(IR_PIN, INPUT);
}

void loop() {
  if (FirstBlood == 0) {
    delay(5000);
    digitalWrite(Rele_1, HIGH);
    Status1 = 1;
    digitalWrite(Rele_2, HIGH);
    Status2 = 1;
    digitalWrite(Rele_3, HIGH);
    Status3 = 1;
    digitalWrite(Rele_4, HIGH);
    Status4 = 1;
    FirstBlood = 1;
  }

  if (irrecv.decode(&results)) {
    if (results.value == 16 && Status1 == 1) {
      digitalWrite(Rele_1, LOW);
      delay(30);
    }
    else if (results.value == 16 && Status1 == 0) {
      digitalWrite(Rele_1, HIGH);
      delay(30);
    }



    Serial.println(results.value);
    irrecv.resume();
  }


}

