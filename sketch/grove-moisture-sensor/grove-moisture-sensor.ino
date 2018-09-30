#include <Adafruit_TFTLCD.h> 
#include <Adafruit_GFX.h>    
#include <TouchScreen.h>

#define LCD_CS A3 
#define LCD_CD A2 
#define LCD_WR A1 
#define LCD_RD A0 
#define LCD_RESET A4 

#define TS_MINX 122
#define TS_MINY 111
#define TS_MAXX 942
#define TS_MAXY 890

#define YP A3
#define XM A2
#define YM 9
#define XP 8

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 364);

int sensorPin = A0;
int sensorValue = 0;

int map_high = 855;
int map_low = 810;
int percentage;

void setup() {

  // MOISTURE SENSOR
  Serial.begin(9600);

  // TFT TOUCH SCREEN
  tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);
  tft.setRotation(1);
  tft.fillScreen(WHITE);
  tft.drawRect(0,0,319,240,YELLOW);

  tft.fillScreen(WHITE);
  tft.drawRect(0,0,319,240,YELLOW);
  tft.setCursor(20,120);
  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.print("Feuchtigkeit (%):");
  
}

void loop() {

  // MOISTURE SENSOR
  sensorValue = analogRead(sensorPin);
  percentage = map(sensorValue, map_low, map_high, 0, 100);

  delay(200);
    
  Serial.print("Moisture = " );
  Serial.println(sensorValue);

  if(percentage >= 0 && percentage <= 100) {
    // TFT TOUCH SCREEN
    tft.setCursor(250,120);
    tft.setTextColor(BLACK, WHITE);
    tft.setTextSize(2);
    tft.print(percentage);
  }
}
