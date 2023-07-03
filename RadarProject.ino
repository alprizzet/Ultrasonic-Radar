#include<Servo.h>

const byte echo=7, trig=6, buzzer=4, led=3;
long time;
int dist;
Servo motor;

void setup() {
  pinMode(buzzer,OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
  motor.attach(5);

}

void loop() {
  
  for(int loc=15;loc<=165;loc++){
    motor.write(loc);
    delay(200);
    dist = calcDistance();
    values(loc,dist);

    if(0<dist && dist<=25){
      digitalWrite(buzzer,HIGH);
      digitalWrite(led,HIGH);
      delay(100);
      digitalWrite(buzzer,LOW);
      digitalWrite(led,LOW);
      delay(100);
    }
  }

  for(int loc=164;loc>15;loc--){
    motor.write(loc);
    delay(200);
    dist = calcDistance();
    values(loc,dist);

    if(dist>0 && dist<=25){
      digitalWrite(buzzer,HIGH);
      digitalWrite(led,HIGH);
      delay(100);
      digitalWrite(buzzer,LOW);
      digitalWrite(led,LOW);
      delay(100);
    }
  }
}
  int calcDistance(){
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  time = pulseIn(echo,HIGH);
  dist = time/2*0.034;
  return dist;
  }

  void values (int loc,int dist){
    Serial.print("Location (degree): ");
    Serial.print(loc);
    Serial.print(" --- ");
    Serial.print(dist);
    Serial.println("cm");
  }



