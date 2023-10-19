#define SENSOR_PIN A0
float SensorValue_normal = 0;
float SensorValue, IncreasedValue, analog_input;
float ppm, ppm1, ppm2, p;

int calculate_ppm(float analog_input) {
  p = analog_input * (10000-300)/1024;
  return p;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("MQ2 SENSOR");
  Serial.println("Sensor heating up...");
  delay(20000);
  Serial.println("Sensor caliberating...");
  
  for(int i = 0; i < 100; i++){
    Serial.print(i);
    SensorValue_normal = SensorValue_normal + analogRead(SENSOR_PIN);
    delay(1000);
   };
   SensorValue_normal = SensorValue_normal / 100;
   
  Serial.println("\nRoom analog AND ppm value= ");
  Serial.println(int(SensorValue_normal));
  ppm = calculate_ppm(SensorValue_normal);
  Serial.println(ppm);
  Serial.println("-------------------------------------------------------------");
}

void loop() {
  // put your main code here, to run repeatedly:
  SensorValue = analogRead(SENSOR_PIN);
  ppm1 = calculate_ppm(SensorValue);
  
  Serial.print("Normal Values: ");
  Serial.print(int(SensorValue_normal));
  Serial.print("    ");
  Serial.print(ppm);
  Serial.println();

  Serial.print("Current Value: ");
  Serial.print(int(SensorValue));
  Serial.print("    ");
  Serial.print(ppm1);
  Serial.println();

  IncreasedValue = SensorValue - SensorValue_normal;
  ppm2 = calculate_ppm(IncreasedValue);
  Serial.print("Change:        ");
  Serial.print(int(IncreasedValue));
  Serial.print("    ");
  Serial.print(ppm2);
  Serial.println("\n==============================================================\n");
  
  delay(2000);
}
