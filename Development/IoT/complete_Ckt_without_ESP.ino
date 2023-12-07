// C++ code
//
int moisture = 0;
int temperature = 0;
int humidity = 0;

void setup(){
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, INPUT);
  Serial.begin(9600);
}

void loop(){

  temperature = (-39 + 0.488155 * (analogRead(A0) - 20));
  
  humidity = map(analogRead(A1), 0, 1023, 10, 70);
  
  digitalWrite(A2, HIGH);
  delay(10);
  moisture = analogRead(A3);
  digitalWrite(A2, LOW);

  Serial.print("Temperature:");
  Serial.println(temperature);
  
  Serial.print("Humidity:");
  Serial.println(humidity);
  
  Serial.print("Moisture:");
  Serial.println(moisture);
  
  delay(1000);
  	
}