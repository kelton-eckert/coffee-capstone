#include <LiquidCrystal.h>
#include <Adafruit_MotorShield.h>
#include <ezTime.h>
#include <WiFi.h>

void setup() {
	Serial.begin(115200);
	WiFi.begin("your-ssid", "your-password");

	waitForSync();

	Serial.println("UTC: " + UTC.dateTime());
	
	Timezone EasternUS;
	EasternUS.setLocation("New York");
	Serial.println("EST: " + EasternUS.dateTime());
}

void loop() { }

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
const byte i; j;
const int pwr = 2;
int enA = A5, enB = A4; // enables forward motion w pins set to high
const int RS = 11, E = 12, D4 = 4, D5 = 5, D6 = 6, D7 = 7;

LiquidCrystal lcd(RS, E, D4, D5, D6, D7);

void setup() {

  // setup pins and lcd
  lcd.begin(16, 2);

  pinMode(A0, INPUT);
  pinMode(enA, OUTPUT); // motor
  pinMode(enB, OUTPUT); // pump

  digitalWrite(enA, LOW); // start  off
  digitalWrite(enB, LOW); // start  off

  i = 0; j = 0;

  // wifi + time setup
  Serial.begin(115200);
  WiFi.begin("ssid", "pass");

	waitForSync();

	Serial.println("UTC: " + UTC.dateTime());
	
	Timezone EasternUS;
	EasternUS.setLocation("New York");
	Serial.println("EST: " + EasternUS.dateTime());

}

void loop() {

  temp = analogRead(A0);

  // lcd temp display funct.
  lcd.clear();
  lcd.setCursor(0, 0);

  lcd.print("Temp: ");

  lcd.setCursor(6, 0);
  lcd.print(temp);

  Serial.println(temp);
  i ++;

  if (temp <= "90degreesC") { // start motor and pump for cycle 1
    brewCycle()
    
    j ++;
  };


  // else: loop 

  delay(1000);

}

void brewCycle(void) {
  lcd.clear();

  lcd.displayBrew()
}

void displayBrew(void) {
  lcd.setCursor(3, 0);
  lcd.print("Brewing...");

  lcd.setCursor(0, 1);
  lcd.print([clock]); // local clock representing est once i add eztime

  lcd.setCursor(8, 1); // temp display
  lcd.print("Temp: ");
  lcd.print(temp);
}

// // custom character of a flame for when it is hot
// byte flame[8] = {
//   0b00100,
//   0b01100,
//   0b11000,
//   0b11010,
//   0b11001,
//   0b11111,
//   0b11111,
//   0b01110
// };
// lcd.createChar(0, flame);

// i = 0;



// // hot or not funct
// if (temp > 400) {

//   lcd.setCursor(11, 1);
//   lcd.print("HOT");
//   lcd.setCursor(15, 1);
//   lcd.write(byte(1));
// };

