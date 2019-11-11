
#define BLYNK_PRINT Serial
int TEMP;
int val = 20;
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
WidgetTerminal terminal(V1);

char auth[] = "ihUlOLRPhx83vRZC0x8U-kfjApyp23Q_";

char ssid[] = "Nahian";
char pass[] = "4211842118";
int PIR;
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(D2, OUTPUT);
  pinMode(D0, INPUT);
  pinMode(A0, INPUT);
}

BLYNK_WRITE(V1) {
  val = param.asInt();

}
void loop()
{

  TEMP = analogRead(A0);
  TEMP = (TEMP * 500) / 1023;
  TEMP = TEMP / 2;
  Blynk.virtualWrite(V2, TEMP);
  Serial.print("val=");
  Serial.println(val);
  Serial.print("TEMP=");
  Serial.println(TEMP);

  if (val > TEMP) {
    digitalWrite(D2, LOW);
    Serial.print("D4LOW");
  }
  else if (val <= TEMP) {
    digitalWrite(D2, HIGH);
    Serial.println("D4HIGH");
  }
  PIR = digitalRead(D0);
  if (PIR == 1) {

    Serial.println("PIR DETECT");
    Blynk.notify("PIR DETECT");
  }
  else if (PIR == 0) {
    Serial.print("PIR NOT DETECT");
  }
  delay(2000);
  Blynk.run();
}
