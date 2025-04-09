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
const int pwr = 2;
int enA = A5, enB = A4; // enables forward motion w pins set to high
const int RS = 11, E = 12, D4 = 4, D5 = 5, D6 = 6, D7 = 7;

LiquidCrystal lcd(RS, E, D4, D5, D6, D7);

void setup() {

  lcd.begin(16, 2);
  Serial.begin(9600);

  pinMode(A0, INPUT);
  pinMode(enA, OUTPUT); // motor
  pinMode(enB, OUTPUT); // pump

  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);

  // power button funct. 1/2
  // pinMode( ? , OUTPUT); 
  // digitalWrite( ? , HIGH);

  // customa character
  byte flame[8] = {
    0b00100,
    0b01100,
    0b11000,
    0b11010,
    0b11001,
    0b11111,
    0b11111,
    0b01110
  };
  lcd.createChar(0, flame);

  i = 0;
}


void loop() {

  temp = analogRead(A0);

// test {

  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);
  
  lcd.setCursor(0,  1);
  lcd.print("Motors ON");
  
  delay(2000);
  
  digitalWrite(enA, LOW);
  digitalWrite(enB, LOW);

  lcd.setCursor(0,  1);
  lcd.print("Motors OFF");

  delay(2000);

// }

  // lcd temp display funct.
  lcd.clear();
  lcd.setCursor(0, 0);

  lcd.print("Temp: ");

  lcd.setCursor(6, 0);
  lcd.print(temp);
  
  lcd.setCursor(0,  1);
  lcd.print("Motors ON");


  // power button funct. 2/2
  // digitalWrite( ? , HIGH);

  // hot or not funct
  if (temp > 400) {

    lcd.setCursor(11, 1);
    lcd.print("HOT");
    lcd.setCursor(15, 1);
    lcd.write(byte(1));
  };

  Serial.println(temp);

  delay(1000);

  lcd.clear();
  lcd.setCursor(0, 0);
  i += 1;
}

