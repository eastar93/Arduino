int val1;
int val2;
int led1 = A0;
int led2 = A1;
int led3 = A2;
int led4 = A3;
int led5 = A4;
int led6 = A5;
const int speakerPin = 8;
const int sensorPin =0;
#include <LiquidCrystal.h>
LiquidCrystal lcd(3, 2, 12, 11, 10, 9);

void setup() {
   Serial.begin(9600);
  pinMode(7, OUTPUT); //Trigger  tx 초음파 발생
  pinMode(6, INPUT);  //Echo     rx 초음파 인식
  pinMode(5, OUTPUT);
  pinMode(4, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  lcd.begin(16,2);
}
void loop()
  {
  digitalWrite(7, HIGH); //초음파를 발생시키기 시작합니다.
  delayMicroseconds(10);
  digitalWrite(7, LOW); //초음파의 발생을 정지시킵니다.
  val1=pulseIn(6,HIGH)/58; //초음파가 발생한 후 물체에 맞고 돌아올 때까지의 시간을 측정해 거리를 구합니다.
  Serial.println("==================");
  Serial.print("Distance(cm) = ");
  Serial.println(val1);
  if(val1 >= 120){ //만약 거리가 120cm가 넘는다면 아무것도 출력하지 않습니다.
  digitalWrite(A0, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  lcd.clear();
  lcd.print(" Far ");
  lcd.setCursor(0,1);
  lcd.print("RIGHT");
  delay(1000);
  }
  
  if(val1 < 120 && val1 >= 80){ //만약 거리가 120cm보다 작고 80cm보다 크거나 같다면
    int  sensorValue  =  analogRead(sensorPin);
    int frequency  = map(sensorValue,  0,  1023,  100,  5000);
    int duration  =  100; //피에조 부저가 0.1초 동안 소리가 나고 일정 시간 뒤 다시 소리가 나게 합니다.
    tone(speakerPin, frequency, duration);//스피커핀, 주파수, 재생시간(milli  second)
    Serial.println("[Safety]");
    Serial.println("==================");
    digitalWrite(A0, HIGH);
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    lcd.clear();
    lcd.print(" Safe ");
    lcd.setCursor(0,1);
    lcd.print("RIGHT");
    delay(1000);
    }
  else if(val1 < 80 && val1 > 30){ // 만약 거리가 80cm보다 작고 30cm보다 크다면 
    int  sensorValue  =  analogRead(sensorPin);
    int frequency  = map(sensorValue,  0,  1023,  100,  5000);
    int duration  =  250; //피에조 부저가 0.25초 동안 소리가 나고 일정 시간 뒤 다시 소리가 나게 합니다.
    tone(speakerPin, frequency, duration);//스피커핀, 주파수, 재생시간(milli  second)
    Serial.println("[Be careful]");
    Serial.println("==================");
    digitalWrite(A0, HIGH);
    digitalWrite(A1, HIGH);
    digitalWrite(A2, LOW);
    lcd.clear();
    lcd.print(" Be Careful ");
    lcd.setCursor(0,1);
    lcd.print("RIGHT");
    delay(1000);       
  }
  else if(val1 <= 30){ // 만약 거리가 30cm보다 작거나 같다면
    int  sensorValue  =  analogRead(sensorPin);
    int frequency  = map(sensorValue,  0,  1023,  100,  5000);
    int duration  =  5000; //피에조 부저가 10초동안 울리게 합니다. 즉, 계속 소리가 나도록 합니다.
    tone(speakerPin, frequency, duration);//스피커핀, 주파수, 재생시간(milli  second)
    Serial.println("[Danger]");
    Serial.println("==================");
    digitalWrite(A0, HIGH);
    digitalWrite(A1, HIGH);
    digitalWrite(A2, HIGH);
    lcd.clear();
    lcd.print(" Danger ");
    lcd.setCursor(0,1);
    lcd.print("RIGHT");
    delay(1000); 
  }  
  delay(1000);
    digitalWrite(A0, LOW);
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);  
  
  digitalWrite(5, HIGH); //초음파를 발생시키기 시작합니다.
  delayMicroseconds(10);
  digitalWrite(5, LOW); //초음파의 발생을 정지시킵니다.
  val2=pulseIn(4,HIGH)/58; //초음파가 발생한 후 물체에 맞고 돌아올 때까지의 시간을 측정해 거리를 구합니다.
  Serial.println("==================");
  Serial.print("Distance(cm) = ");
  Serial.println(val2);
  if(val2 >= 120){ //만약 거리가 120cm가 넘는다면 아무것도 출력하지 않습니다.
  digitalWrite(A3, LOW);
  digitalWrite(A4, LOW);
  digitalWrite(A5, LOW);
  lcd.clear();
  lcd.print(" Far ");
  lcd.setCursor(0,1);
  lcd.print("LEFT");
  delay(1000);  
  }
  
  if(val2 < 120 && val2 >= 80){ //만약 거리가 120cm보다 작고 80cm보다 크거나 같다면
    int  sensorValue  =  analogRead(sensorPin);
    int frequency  = map(sensorValue,  0,  1023,  100,  5000);
    int duration  =  100; //피에조 부저가 0.1초 동안 소리가 나고 일정 시간 뒤 다시 소리가 나게 합니다.
    tone(speakerPin, frequency, duration);//스피커핀, 주파수, 재생시간(milli  second)
    Serial.println("[Safety]");
    Serial.println("==================");
    digitalWrite(A3, HIGH);
    digitalWrite(A4, LOW);
    digitalWrite(A5, LOW);
  lcd.clear();
  lcd.print(" Safe ");
  lcd.setCursor(0,1);
  lcd.print("LEFT");
  delay(1000);            
  }
  else if(val2 < 80 && val2 > 30){ // 만약 거리가 80cm보다 작고 30cm보다 크다면 
    int  sensorValue  =  analogRead(sensorPin);
    int frequency  = map(sensorValue,  0,  1023,  100,  5000);
    int duration  =  250; //피에조 부저가 0.25초 동안 소리가 나고 일정 시간 뒤 다시 소리가 나게 합니다.
    tone(speakerPin, frequency, duration);//스피커핀, 주파수, 재생시간(milli  second)
    Serial.println("[Be careful]");
    Serial.println("==================");
    digitalWrite(A3, HIGH);
    digitalWrite(A4, HIGH);
    digitalWrite(A5, LOW);
    lcd.clear();
    lcd.print(" Be Careful ");
    lcd.setCursor(0,1);
    lcd.print("LEFT");
    delay(1000);         
  }
  else if(val2 <= 30){ // 만약 거리가 30cm보다 작거나 같다면
    int  sensorValue  =  analogRead(sensorPin);
    int frequency  = map(sensorValue,  0,  1023,  100,  5000);
    int duration  =  5000; //피에조 부저가 10초동안 울리게 합니다. 즉, 계속 소리가 나도록 합니다.
    tone(speakerPin, frequency, duration);//스피커핀, 주파수, 재생시간(milli  second)
    Serial.println("[Danger]");
    Serial.println("==================");
    digitalWrite(A3, HIGH);
    digitalWrite(A4, HIGH);
    digitalWrite(A5, HIGH);
    lcd.clear();
    lcd.print(" Danger ");
    lcd.setCursor(0,1);
    lcd.print("LEFT");
    delay(1000);   
  }  
  delay(1000);
    digitalWrite(A3, LOW);
    digitalWrite(A4, LOW);
    digitalWrite(A5, LOW);  
}
