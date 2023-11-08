
#include <Ultrasonic.h>
int ledamarelo=4;
int ledverde=5;
int ledvermelho=2;
int ledazul=9;
int buzzer=7;

const int sensor =0; 
double tempCelsius(int valorNTC){
  double temp;
  temp = log(((10240000 / valorNTC) - 10000));
  temp = 1 / (0.001129148 + (0.000234125+(0.0000000876741*temp*temp))*temp);
   return temp = temp - 273.15;
}


Ultrasonic ultrasonic(12, 13);
int distance;

void setup() {
  pinMode(ledamarelo, OUTPUT);
   pinMode(ledazul, OUTPUT);
    pinMode(ledverde, OUTPUT);
   pinMode(ledvermelho, OUTPUT);
   pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  distance = ultrasonic.read();
  Serial.print("Distance in CM: ");
  Serial.println(distance);
  delay(1000);

 int valor= analogRead(sensor);
double c = tempCelsius(valor);
Serial.println(valor);
Serial.println(c);
delay(100);

  if (distance >=2)  { 
        digitalWrite(ledverde, HIGH);

  }
 else{ digitalWrite(ledverde,LOW);
 }
if ((distance <=48)&& (valor >=25) &&(valor <=27) ) { // mais de 40 
        digitalWrite(ledamarelo, HIGH);
    
  }
 else 
 digitalWrite(ledamarelo, LOW);


if (distance >=72)  { 
 
        digitalWrite(buzzer, HIGH);
        tone(7,523,1000);
        delay (1000);
        noTone (7);
        delay(1000);
        digitalWrite(2,LOW);
        
  }
 else digitalWrite(buzzer, LOW);
 
if ((distance <=72) && (valor <=25)){
digitalWrite(ledvermelho, LOW);

}

else {
digitalWrite(ledvermelho, LOW);

}
 if (distance >=64)  { 
        digitalWrite(ledazul, HIGH);
 }
else {
digitalWrite(ledazul, LOW);

}      
}
