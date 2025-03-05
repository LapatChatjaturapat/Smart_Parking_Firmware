#include <AceRoutine.h>
using namespace ace_routine;

#define LED1      42
#define LED2      41
#define LED3      40
#define IR1        5
#define IR2        6
#define IR3        7
int state1=0,state2=0,state3=0;

COROUTINE(Parking1) {
  COROUTINE_LOOP() {
    if(digitalRead(IR1)==LOW){
      if(state1==0){
        COROUTINE_DELAY(5000);
        if(digitalRead(IR1)==LOW){
          digitalWrite(LED1,HIGH);
          state1=1;
          Serial.println(1);
        }
      }
    }
    else{
      digitalWrite(LED1,LOW);
      state1=0;
      Serial.println(0);
    }
    COROUTINE_DELAY(0);
  }
}

COROUTINE(Parking2) {
  COROUTINE_LOOP() {
    if(digitalRead(IR2)==LOW){
      if(state2==0){
        COROUTINE_DELAY(5000);
        if(digitalRead(IR2)==LOW){
          digitalWrite(LED2,HIGH);
          state2=1;
          Serial.println(1);
        }
      }
    }
    else{
      digitalWrite(LED2,LOW);
      state2=0;
      Serial.println(0);
    }
    COROUTINE_DELAY(0);
  }
}

COROUTINE(Parking3) {
  COROUTINE_LOOP() {
    if(digitalRead(IR3)==LOW){
      if(state3==0){
        COROUTINE_DELAY(5000);
        if(digitalRead(IR3)==LOW){
          digitalWrite(LED3,HIGH);
          state3=1;
          Serial.println(1);
        }
      }
    }
    else{
      digitalWrite(LED3,LOW);
      state3=0;
      Serial.println(0);
    }
    COROUTINE_DELAY(0);
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);
  pinMode(IR3,INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Parking1.runCoroutine();
  Parking2.runCoroutine();
  Parking3.runCoroutine();
}
