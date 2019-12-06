#include<Servo.h>
Servo servo;

//LED setip
int led1 = 8; 
int led2 = 10;
int led3 = 11;
int led4 = 12;
int led5 = 13;
//servo motor setup
int active = 90;
int deactive = 0;
int value = 0;

//switch setup
int sw1 = 2;
int sw2 = 3;
int sw3 = 4;
int sw4 = 5;
int sw5 = 6;

//flag setup
boolean init_flag = false;
int flag = 6;
int flag_copy = 6;

// speaker setup
int speakerPin = 9;
 
int numTones = 1;
int tones[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440};
// mid C C# D D# E F F# G G# A




void setup() {
  // put your setup code here, to run once:
  servo.attach(7);
  pinMode(sw1, INPUT_PULLUP);
  pinMode(sw2, INPUT_PULLUP);
  pinMode(sw3, INPUT_PULLUP);
  pinMode(sw4, INPUT_PULLUP);
  pinMode(sw5, INPUT_PULLUP);
  Serial.begin(9600);
  servo.write(value);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
}

void on_LED(int led){
  digitalWrite(led, HIGH);
}
void off_LED(int led){
  digitalWrite(led, LOW);
}
void off_all_LED(){
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
}
void making_sound(){
  for (int i = 0; i < numTones; i++)
  {
    tone(speakerPin, tones[i]);
    delay(500);
  }
  noTone(speakerPin);
}
void random_set(){
  flag = random(5);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(init_flag == false){
    random_set();
    init_flag = true;
  }
  
  if(digitalRead(sw1) == LOW && flag == 0){
    value = active;
    
  }else if(digitalRead(sw1)==LOW){
    on_LED(led1);
  }
  if(digitalRead(sw2) == LOW && flag == 1){
    value = active;
    
  }else if(digitalRead(sw2)==LOW){
    on_LED(led2);
  }
  if(digitalRead(sw3) == LOW && flag == 2){
    value = active;
    
  }else if(digitalRead(sw3)==LOW){
    on_LED(led3);
  }
  if(digitalRead(sw4) == LOW && flag == 3){
    value = active;
    
  }else if(digitalRead(sw4)==LOW){
    on_LED(led4);
  }
  if(digitalRead(sw5) == LOW && flag == 4){
    value = active;
    
  }else if(digitalRead(sw5)==LOW){
    on_LED(led5);
  }
 
  if(value == active){
    servo.write(value);
    delay(800);
    making_sound();
    delay(800);
    value = deactive;
    servo.write(value);
    init_flag = false;
    off_all_LED();
  }
}
