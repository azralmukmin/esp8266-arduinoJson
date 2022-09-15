#include <ArduinoJson.h>
#include <math.h>

int count = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {

  float temperature = 24.115111;
  float humidity = 78.2225222;

  StaticJsonDocument<512> doc;
  doc["temperature"] = setFloat(temperature, 2);
  doc["humidity"] = setFloat(humidity, 1);
  doc["location"] = "Perlis";
  doc["count"] = count;

  Serial.print("\n- SerializeJson -\n");
  String dataJson1;
  serializeJson(doc, dataJson1);
  Serial.println(dataJson1);
  serializeJson(doc, Serial);
  int len1 = measureJson(doc);
  Serial.print("\nSize string : "); Serial.println(len1);

  Serial.print("\n- SerializeJsonPretty -\n");
  String dataJson2;
  serializeJsonPretty(doc, dataJson2);
  Serial.println(dataJson2);
  serializeJsonPretty(doc, Serial);
  int len2 = measureJsonPretty(doc);
  Serial.print("\nSize string : "); Serial.println(len2);

  count++;

  delay(1000);
}

double setFloat(double value, int f) {
  return (int)(value * pow(10,f) + 0.5) / pow(10,f);
}
