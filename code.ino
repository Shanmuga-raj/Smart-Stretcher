#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);

int trigPin=6;
int echoPin=4;

long duration;
int distance;

void setup() {
  
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); 
 pinMode(echoPin, INPUT);
  
  lcd.setCursor(0, 0);
  lcd.print(" SMART STRECTURE");
  lcd.setCursor(0, 1);
  lcd.print("     SYSTEM    ");
  delay(3000);
  lcd.clear(); 
}

void loop() {
  int resp=analogRead(A0);

  Serial.print("RESP=");
  Serial.println(resp);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");
  
  lcd.setCursor(0,0);
  lcd.print("BRTHLVL=");

  if(resp<=30)
  {
    lcd.setCursor(8,0);
    lcd.print("ABNORMAL");
    
  }

  if((resp>30)&&(resp<1000))
  {
    lcd.setCursor(8,0);
    lcd.print("NORMAL    ");
    lcd.setCursor(10,1);
    lcd.print("       ");
  }

  if(resp>=1000)
  {
    lcd.setCursor(8,0);
    lcd.print("ABNORMAL");
    lcd.setCursor(10,1);
    lcd.print("                  ");
  }

  if(distance<=100)
  {
   lcd.setCursor(0,1);
    lcd.print("OBST DET   "); 
  }

  if(distance>100)
  {
   lcd.setCursor(0,1);
    lcd.print("OBST NDT   "); 
  }

  
delay(500);

}
