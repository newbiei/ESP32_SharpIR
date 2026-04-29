#include <WERA_SharpIR.h>

WERASharpIR sensor1(35);

int mode = 1; // default mode (1 = power, 2 = inverse)

void setup() {
  Serial.begin(115200);
  Serial.println("=== MODE SENSOR IR ===");
  Serial.println("Ketik 1: Regresi Power");
  Serial.println("Ketik 2: Regresi Inverse");
}

void loop() {

  // 🔥 Baca input dari Serial
  if (Serial.available()) {
    char input = Serial.read();

    if (input == '1') {
      mode = 1;
      Serial.println("Mode: Regresi Power (readCM)");
    }
    else if (input == '2') {
      mode = 2;
      Serial.println("Mode: Regresi Inverse (readCMv2)");
    }
  }

  delay(500);

  unsigned long startTime = millis();

  float dis1;

  // 🔥 SWITCH MODE
  if (mode == 1) {
    dis1 = sensor1.readCM();
  } 
  else if (mode == 2) {
    dis1 = sensor1.readCMv2();
  }

  // 🔥 OUTPUT
  Serial.print("Jarak : "); Serial.print(dis1);

  unsigned long calcTime = millis() - startTime;

  Serial.print("\nTime taken (ms): ");
  Serial.println(calcTime);
  Serial.println("----------------------");
}