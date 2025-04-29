#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET -1  // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// placeholder from adafruit library example - make and upload cylndr logo instead
// #define LOGO_HEIGHT   16
// #define LOGO_WIDTH    16
// static const unsigned char PROGMEM logo_bmp[] =
// { B00000000, B11000000,
//   B00000001, B11000000,
//   B00000001, B11000000,
//   B00000011, B11100000,
//   B11110011, B11100000,
//   B11111110, B11111000,
//   B01111110, B11111111,
//   B00110011, B10011111,
//   B00011111, B11111100,
//   B00001101, B01110000,
//   B00011011, B10100000,
//   B00111111, B11100000,
//   B00111111, B11110000,
//   B01111100, B11110000,
//   B01110000, B01110000,
//   B00000000, B00110000 };

int temp = A0;
int tempVal;
int enA = 5;
int enB = 6;
int i = 0;
int button = 0;  // for brew screen buttons
const int grounds 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(temp, INPUT);
  pinMode(enA, OUTPUT);  // motor
  pinMode(enB, OUTPUT);  // pump

  digitalWrite(enA, LOW);  // start  off
  digitalWrite(enB, LOW);  // start  off

  display.clearDisplay();
  display.display();

  Serial.println("Initialized")
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("cycle: ");
  Serial.println(i);

  tempVal = analogRead(temp);
  Serial.print("temp: ");
  Serial.println(tempVal);

  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);

  delay(2000);

  digitalWrite(enA, LOW);
  digitalWrite(enB, LOW);

  delay(2000);

  i++;
}

void initScr {
  display.clearDisplay();
  display.drawBitmap();  // fill w logo
  display.display();

  delay(2000);
}

void selectScr {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Please select a brew option:");
  display.println("A - mild");
  display.println("B - medium");
  display.println("C - strong");

  
}

void brewScr {
  button = ; // has to be able to take on three values

  split:
  switch (button) { // cases for 12oz of water - avg coffee mug size
    case A: // mild
      grounds = 18;
      break;
    case B: // medium
      grounds = 21;
      break;
    case C: // strong
      grounds = 22;
      break;
    default: // again from top of switch...case
      goto split;
      break;
  }

  display.clearDisplay();

  display.print("Please fill the filter with ");
  display.print(grounds);
  display.print("g of a medium or medium-fine-ground coffee.");

  display.println("Next add 350 mL of just-boiled water to the upper compartment.");
  delay(2000);

  display.clearDisplay();
  display.print("Press button again to start the pour over.");
  delay(500); 

  if (button == A || B || C) { // this syntax is fucked
    brewCycle();
  }
}

void brewCycle {

  //check temp
}

void checkTemp {
  tempVal = analogRead(temp);
  Serial.print("tempVal = ");
  Serial.println(tempVal);
}
