//include necessory libraries
#include <DHT.h>
#define DHTPIN 13
#define DHTTYPE DHT11
#define soil_moisture_pin 4
DHT dht(DHTPIN, DHTTYPE);

/*************************************************************

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/

/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL3QnJ3MD2K"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "wlNOo4CVByUa8tKU7t97phLKpGYn9RDY"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Ajay";
char pass[] = "12345678";

BlynkTimer timer;


void setup()
{
  // Debug console
  Serial.begin(115200);
  dht.begin();
  pinMode(4,OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // You can also specify server:
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);

 
}

void loop()
{
  Blynk.run();
  timer.run();
  delay(2000);
  double h = dht.readHumidity();
  double t = dht.readTemperature();
  double f = dht.readTemperature(true);

  if(isnan(h) || isnan(t) || isnan(f)){
    Serial.println("No Reading from DHT Sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println("%");
  Serial.print("Temoerature: ");
  Serial.print(t);
  Serial.print("°C  ");
  Serial.print(f);
  Serial.println("°F");
  Serial.print("Soil moisture: ");
  Serial.println(analogRead(34));

  //SEND DATA
  double sensorData = analogRead(34); // this is an example of reading sensor data
  Blynk.virtualWrite(V2, sensorData);
  double sensorData1 = t; // this is an example of reading sensor data
  Blynk.virtualWrite(V0, sensorData1);
  double sensorData2 = f; // this is an example of reading sensor data
  Blynk.virtualWrite(V1, sensorData2);

  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}
