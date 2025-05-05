#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

// // Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET -1  // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int temp = A0;
int tempVal;
int in1 = 2;
int in3 = 4;
int butA = 6;
int butB = 8;

int i = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  pinMode(temp, INPUT);
  pinMode(in1, OUTPUT); // motor
  pinMode(in3, OUTPUT); // pump

  digitalWrite(in1, LOW); // start  off
  digitalWrite(in3, LOW); // start  off

    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // initializes display
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();

  // // Draw a single pixel in white
  // display.drawPixel(10, 10, WHITE);

  // // Show the display buffer on the screen. You MUST call display() after
  // // drawing commands to make them visible on screen!
  // .display();
  // delay(2000);

  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setTextWrap(true);
  display.setCursor(0,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  tempVal = analogRead(temp);
  
  display.clearDisplay();
  display.display();

  display.setCursor(0,0);
  // delay(1000);
  // display.setCursor(10,10);
  // display.println("TEST");
  // display.display();


  // Serial.println(analogRead(A4)); //sda
  // Serial.println(analogRead(A5)); //scl

  
  display.print("cycle number: ");
  display.println(i);
  display.print("tempVal: ");
  display.println(tempVal);
  display.display();

  Serial.println(digitalRead(butA));
  Serial.println(digitalRead(butB));

  digitalWrite(in1, HIGH); 
  digitalWrite(in3, HIGH); 
  // display.println("motor on");
  // display.display();

  delay(1000);

  digitalWrite(in1, LOW); // not turning off after
  digitalWrite(in3, LOW);
  // display.println("motor off");
  // display.display();

  delay(1000);
  i++;


}
