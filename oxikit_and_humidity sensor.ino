//10 11 12(Arduino) ... 1 2 3 (relay)

#include <dht.h>

dht DHT;

#define DHT11_PIN 7

const int valve_A = 10;
const int valve_B = 11;
const int EqualValve = 12;

unsigned long Startup_Purge_Delay; //delay variable creation
unsigned long Production_Delay; //delay variable creation
unsigned long Flush_Delay; //delay variable creation
unsigned long PreCharge_Delay; //delay variable 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(valve_A, OUTPUT);
pinMode(valve_B, OUTPUT);
pinMode(EqualValve, OUTPUT);

  Production_Delay = 4000;
  Flush_Delay = 450;
  PreCharge_Delay = 700;
  Startup_Purge_Delay = 1000;


//  digitalWrite(valve_A, HIGH); //Turn on relay
//  digitalWrite(valve_B, HIGH); //Turn on relay
//  digitalWrite(EqualValve, HIGH); //Turn on relay
  delay(Startup_Purge_Delay);

}

void humidity(){
  int chk = DHT.read22(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  }

void loop() {
  // put your main code here, to run repeatedly:

//Production 
digitalWrite(valve_A, HIGH);
digitalWrite(valve_B, LOW);
digitalWrite(EqualValve, HIGH);
humidity();
delay(Production_Delay);

////Flush
digitalWrite(valve_A, HIGH);
digitalWrite(valve_B, LOW);
digitalWrite(EqualValve, LOW);
delay(Flush_Delay);
//
////Precharge
digitalWrite(valve_A, LOW);
digitalWrite(valve_B, LOW);
digitalWrite(EqualValve, LOW);
humidity();
delay(PreCharge_Delay);
//
////Production 
digitalWrite(valve_A, LOW);
digitalWrite(valve_B, HIGH);
digitalWrite(EqualValve, HIGH);
humidity();
delay(Production_Delay);
//
////Flush
digitalWrite(valve_A, LOW);
digitalWrite(valve_B, HIGH);
digitalWrite(EqualValve, LOW);
delay(Flush_Delay);
//
////Precharge
digitalWrite(valve_A, LOW);
digitalWrite(valve_B, LOW);
digitalWrite(EqualValve, LOW);
humidity();
delay(PreCharge_Delay);

}
