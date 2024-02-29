#define BLYNK_TEMPLATE_ID "TMPL-uPnOlz_"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "kTtyC1yLrOlg1tAkv2bix6isteuYmXAh"
#define BLYNK_PRINT Serial 
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
char ssid[] = "Ajay"; 
char pass[] = "12345678"; 
BlynkTimer timer; 
BLYNK_WRITE(V0) 
{ 
 int value = param.asInt(); 
 Blynk.virtualWrite(V1, value);
 digitalWrite(15,value); 
} 
BLYNK_CONNECTED() 
{ 
 Blynk.setProperty(V3, "offImageUrl", "https://staticimage.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png"); 
 Blynk.setProperty(V3, "onImageUrl", "https://staticimage.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png"); 
 Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-ineed-to-blynk/how-quickstart-device-was-made"); 
} 
void myTimerEvent() 
{ 
 Blynk.virtualWrite(V2, millis() / 1000); 
} 
void setup() 
{ 
 Serial.begin(115200); 
 Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass); 
 timer.setInterval(1000L, myTimerEvent);
 pinMode(15,OUTPUT); 
} 
void loop() 
{ 
 Blynk.run(); 
 timer.run(); 
} 