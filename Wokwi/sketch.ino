#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// === Definiri pini/ Macrouri ===
#define POT_PIN     A0
#define MAX_LED     8
#define LEVEL1_LED  4
#define LEVEL2_LED  5
#define LEVEL3_LED  6
#define LEVEL4_LED  7

// LCD I2C: adresa uzuala 0x27, 16 coloane, 2 randuri
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Praguri si LED-uri corespunzatoare
const int thresholds[4] = {25, 50, 75, 100};
const int levelLEDs[4] = {LEVEL1_LED, LEVEL2_LED, LEVEL3_LED, LEVEL4_LED};

void setup() {
  lcd.init();        // Initializare LCD
  lcd.backlight();   // Aprindere lumina de fundal

  // LED-uri ca iesiri
  for (int i = 0; i < 4; i++) {
    pinMode(levelLEDs[i], OUTPUT);
  }
  pinMode(MAX_LED, OUTPUT);
}

void loop() {
  // Citește potentiometrul si mapeaza la procent
  int potValue = analogRead(POT_PIN);
  int volume = map(potValue, 0, 1023, 0, 100);

  // Afișează volumul pe LCD
  lcd.setCursor(0, 0);
  lcd.print("Volum: ");
  lcd.print(volume);
  lcd.print("%   "); // spatiu extra pentru a sterge caractere vechi

  // Control LED-uri de nivel
  for (int i = 0; i < 4; i++) {
    if (volume >= thresholds[i]) {
      digitalWrite(levelLEDs[i], HIGH);
    } else {
      digitalWrite(levelLEDs[i], LOW);
    }
  }

  // LED de maxim (daca si numai daca volumul este exact 100%)
  if (volume == 100) {
    digitalWrite(MAX_LED, HIGH);
  } else {
    digitalWrite(MAX_LED, LOW);
  }

  delay(100);
}
