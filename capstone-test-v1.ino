#include <LiquidCrystal.h>
#include <Adafruit_MotorShield.h>

const int RS = 3, EN = 4, D4 = 12, D5 = 11, D6 = 10, D7 = 9;
int val;
int delayT;
byte i;
byte spin;


LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup() {
  
  lcd.begin(16, 2);
  Serial.begin(9600);

  // pinMode(pwr, INPUT);
  pinMode(A0, INPUT);
  pinMode(2, INPUT);

  byte heart[8] = {
    0b00000,
    0b01010,
    0b11111,
    0b11111,
    0b11111,
    0b01110,
    0b00100,
    0b00000
  };
  lcd.createChar(0, heart);

  byte flame[8] = {
    0b00100,
    0b01100,
    0b11000,
    0b11010,
    0b11001,
    0b11111,
    0b01111,
    0b00110
    
  };
  lcd.createChar(1, flame);


  i = 0;

}

void loop() {
  if (digitalRead(2) == 1) {
    val = analogRead(A0);

    lcd.clear();  
    lcd.setCursor(0,0);

    lcd.print("Temp: ");

    lcd.setCursor(6,0);
    lcd.print(val);

    if (val > 320) {
      // if (i % 2) {
      // }
      // else  {
      lcd.setCursor(15,0);
      lcd.write(byte(1));
      lcd.setCursor(12,1);
      lcd.print("HOT!");

      // digitalWrite(6,HIGH);
      // digitalWrite(7,LOW);
      // delay(1000);

      // digitalWrite(7,HIGH);
      // digitalWrite(6,LOW);
      // delay(1000);
      };

  Serial.println(val);

  delay(1000);

  lcd.clear();
  lcd.setCursor(0,0);
  i += 1;
  };
}



