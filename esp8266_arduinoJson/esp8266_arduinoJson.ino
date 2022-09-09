#include <ArduinoJson.h>

int count = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {

  StaticJsonDocument<512> doc;
  doc["temperature"] = 24;
  doc["humidity"] = 74;
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