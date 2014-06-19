const int sensor1 = A0;  // Analog input pin that the potentiometer is attached to
const int sensor2 = A1;
const int sensor3 = A2;
const int goPin = 13;

int sensorValue1 = 0;
int sensorValue2 = 0;
int sensorValue3 = 0;
long interval = 150;
long previousMillis = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(115200); 
  pinMode(goPin, OUTPUT);
  digitalWrite(goPin, LOW);
}

void printData() {
  Serial.print(sensorValue1);
  Serial.print(",");
  Serial.print(sensorValue2);
  Serial.print(",");
  Serial.print(sensorValue3);
  Serial.print("\n");
}

void loop() {
  unsigned long currentMillis = millis();
  
  digitalWrite(goPin, HIGH);
  delayMicroseconds(25);
  digitalWrite(goPin, LOW);
  
  if(currentMillis - previousMillis > interval) {
 
  previousMillis = currentMillis;   
  
  sensorValue1 = analogRead(sensor1);  //get sensor 1 value
  sensorValue2 = analogRead(sensor2);  //get sensor 2 value
  sensorValue3 = analogRead(sensor3);  //get sensor 3 value
  }
  
  printData();                   
}
