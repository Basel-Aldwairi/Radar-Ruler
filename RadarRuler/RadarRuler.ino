#include <LiquidCrystal.h>

const int trigPin = 10;
const int echoPin = 9;

const int redPin = 6;
const int yellowPin = 7;
const int bluePin = 8;

String dis;

float distance;
long duration;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  Serial.print("woooww");
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  pinMode(2, INPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(13,HIGH);
  //Serial.begin(9600);
  lcd.begin(16, 2);

}

void loop() {

  digitalWrite(trigPin, LOW);

  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.0343 / 2;

  lcd.setCursor(0, 0);
  lcd.print("Distance = ");
   
  delay(100);

  if(distance >= 30 && distance <=500){
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(bluePin, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print(distance);
    lcd.setCursor(8, 1);
    lcd.print("cm");
  } else if(distance >= 10 && distance <= 30){
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, HIGH);
    digitalWrite(bluePin, LOW);
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print(distance);
    lcd.setCursor(8, 1);
    lcd.print("cm");
  } else if( distance <= 10){
    digitalWrite(redPin, HIGH);
    digitalWrite(yellowPin, LOW);
    digitalWrite(bluePin, LOW);
    lcd.setCursor(0, 1);
  lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print(distance);
    lcd.setCursor(8, 1);
    lcd.print("cm");
  } else if(distance > 500){
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print("Error");
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(bluePin, LOW);
  }

}
