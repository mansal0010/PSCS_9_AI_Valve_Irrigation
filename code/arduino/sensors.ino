#define SENSOR_PIN 34
#define RELAY_PIN 23

int moistureValue = 0;
int threshold = 30;  // Moisture threshold in %

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // Valve OFF initially
}

void loop() {
  moistureValue = analogRead(SENSOR_PIN);
  int percentage = map(moistureValue, 0, 4095, 100, 0);

  Serial.print("Soil Moisture: ");
  Serial.print(percentage);
  Serial.println("%");

  if (percentage < threshold) {
    digitalWrite(RELAY_PIN, LOW);  // Valve ON
    Serial.println("Irrigation ON");
  } else {
    digitalWrite(RELAY_PIN, HIGH); // Valve OFF
    Serial.println("Irrigation OFF");
  }

  delay(2000);
}
