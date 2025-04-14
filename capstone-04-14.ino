#include <LiquidCrystal.h>
#include <Adafruit_MotorShield.h>

// pin list
// --------
// A0 - temp probe voltage
// A4 - enable motor A
// A5 - enable motor B
// 5V
// GND
// D4 - DB4
// D5 - DB5
// D6 - DB6
// D7 - DB7
// D11 - RS (LCD)
// D12 - E (LCD)
// D2 - power

int temp;
byte i;
int enA = A1, enB = A2; // enables forward motion w pins set to high
const int RS = 11, E = 12, D4 = 4, D5 = 5, D6 = 6, D7 = 7;

LiquidCrystal lcd(RS, E, D4, D5, D6, D7);

void setup() {

  lcd.begin(16, 2);
  Serial.begin(9600);

  pinMode(A0, INPUT);
  pinMode(enA, OUTPUT); // motor
  pinMode(enB, OUTPUT); // pump

  digitalWrite(enA, LOW); // motor off
  digitalWrite(enB, LOW); // pump off

  i = 0;
}


void loop() {
  temp = analogRead(A0);

  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);
  
  lcd.clear();
  lcd.setCursor(0,  0);
  lcd.print("Motors ON");
  Serial.println("ON");
  delay(2000);
  
  digitalWrite(enA, LOW);
  digitalWrite(enB, LOW);

  lcd.clear();
  lcd.setCursor(0,  0);
  lcd.print("Motors OFF");
  Serial.println("OFF");

  delay(2000);
}

