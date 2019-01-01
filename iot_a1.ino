#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h> 
#include <Adafruit_SSD1306.h>


#define CommonSenseMetricSystem 

#define threshhold 30 
#define trigPin 13
#define echoPin 12
#define buzzerPin 6
#define ledPin 7 
#define OLED_RESET 4

Adafruit_SSD1306 display(OLED_RESET);

void setup () {
Serial.begin (9600); 
pinMode(trigPin , OUTPUT); 
pinMode(echoPin , INPUT); 
pinMode(buzzerPin , OUTPUT); 
pinMode(ledPin , OUTPUT); 
display.begin(SSD1306_SWITCHCAPVCC ,0x3C); 
display.clearDisplay();
}

void loop () {
float duration , distance, inch;

digitalWrite(trigPin , LOW);
delayMicroseconds(2); 
digitalWrite(trigPin , HIGH);
delayMicroseconds(10); 
digitalWrite(trigPin , LOW);

duration = pulseIn(echoPin , HIGH);

distance = (duration/2) / 29.1;
inch = (duration/2) / 73.914;

display.setCursor(0,10); //oled 
display.setTextSize(1); 
display.setTextColor(WHITE); 
display.println(distance); 
display.setCursor(40,10); 
display.setTextSize(1);


display.println("cm"); 
display.print(inch);
display.print("in");

display.display();
if(distance >threshhold)
{ 
digitalWrite(ledPin,HIGH);
tone(buzzerPin ,1000);
delay(1000); 
noTone(buzzerPin); 
delay(1000);
}
else{
noTone(buzzerPin);
digitalWrite(ledPin,LOW);
}
delay(500);
display.clearDisplay(); 
Serial.println(distance);
}
