//   FILE:  dht11_test1.pde
// PURPOSE: DHT11 library test sketch for Arduino
#include <dht11.h>
dht11 DHT;
#define DHT11_PIN 4
#define TRIGPIN 8
#define ECHOPIN 9
#define CTM 10


void setup() {
  Serial.begin(9600);
  Serial.println("DHT TEST PROGRAM ");
  Serial.print("LIBRARY VERSION: ");
  Serial.println(DHT11LIB_VERSION);
  Serial.println();
  Serial.println("Type,\tstatus,\tHumidity (%),\tTemperature (C),\tLight,\tdistance");
  pinMode(TRIGPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
}

void loop() {
  int chk;
  chk = DHT.read(DHT11_PIN);    // READ DATA
  switch (chk) {
    case DHTLIB_OK:
      //Serial.print("OK,\t");
      break;
    case DHTLIB_ERROR_CHECKSUM:
      Serial.print("Checksum error,\t");
      break;
    case DHTLIB_ERROR_TIMEOUT:
      Serial.print("Time out error,\t");
      break;
    default:
      Serial.print("Unknown error,\t");
      break;
  }
  
  //温度
  int val1 = analogRead(A0);
  int temperature = (val1 * 500.0 / 1024.0 - 60.0) * 100;
  
  //照度
  int val = analogRead(A1);
  
  //距離
  int dur;
  float dis;
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(CTM);
  digitalWrite(TRIGPIN, LOW);
  dur = pulseIn(ECHOPIN, HIGH);
  dis = (float)dur*0.017;

  //出力
  // DISPLAT DATA
  Serial.print("\t");
  Serial.print(DHT.humidity, 1);
  Serial.print(",\t");
  //Serial.print(DHT.temperature, 1);
  Serial.print(temperature/100);
  Serial.print(".");
  Serial.print(temperature%100);
  Serial.print(",\t");
  Serial.print(val);
  Serial.print("\t");
  Serial.print(dis);
  
  delay(2000);
}




