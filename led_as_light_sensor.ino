/***************************************************************************
 LED as a light sensor
 
 This software is free provided that this notice is not removed and proper attribution 
 is accorded to Layad Circuits and its Author(s).
 Layad Circuits invests resources in producing free software. By purchasing Layad Circuits'
 products or utilizing its services, you support the continuing development of free software
 for all.
  
 Author(s): C.D.Malecdan for Layad Circuits Electronics Engineering
 Revision: 1.0 - 2017/08/17 - initial creation
 Layad Circuits Electronics Engineering Supplies and Services
 B314 Lopez Bldg., Session Rd. cor. Assumption Rd., Baguio City, Philippines
 www.layadcircuits.com
 general: info@layadcircuits.com
 sales: sales@layadcircuits.com
 +63-916-442-8565
 ****************************************************************************/
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);  
int adc;
char buf[17]="";

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  adc = analogRead(A0);
  Serial.println(adc);
  lcd.setCursor(0,0);
  lcd.print(" LAYAD CIRCUITS ");  
  lcd.setCursor(0,1);
  sprintf(buf,"    ADC=%04d     ",adc);
  lcd.print(buf); 
  delay(300);
}
