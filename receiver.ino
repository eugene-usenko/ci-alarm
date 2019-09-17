#include <ESP8266WiFi.h>

WiFiServer server(80);
IPAddress IP(192,168,4,15);
IPAddress mask = (255, 255, 255, 0);

void setup() {
  Serial.begin(9600);
  WiFi.mode(WIFI_AP);
  WiFi.softAP("ci-alarm", "ci-alarm");
  WiFi.softAPConfig(IP, IP, mask);
  server.begin();

//  Serial.println();
//  Serial.println("Server started.");
//  Serial.print("IP: ");     Serial.println(WiFi.softAPIP());
//  Serial.print("MAC:");     Serial.println(WiFi.softAPmacAddress());

  pinMode(D3, OUTPUT);
  digitalWrite(D3, LOW);
}

void loop() {
  WiFiClient client = server.available();
  if (!client) {return;}
  String cmd = client.readStringUntil('\n');
  if(cmd == "on")digitalWrite(D3, HIGH);
  if(cmd == "off")digitalWrite(D3, LOW);
}
