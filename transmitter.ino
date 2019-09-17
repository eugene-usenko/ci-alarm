#include <ESP8266WiFi.h>

char ssid[] = "ci-alarm";           
char pass[] = "ci-alarm";         

IPAddress server(192,168,4,15);     
WiFiClient client;

void setup() {
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);           

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("ok");
//  Serial.print("LocalIP:"); Serial.println(WiFi.localIP());
//  Serial.println("MAC:" + WiFi.macAddress());
//  Serial.print("Gateway:"); Serial.println(WiFi.gatewayIP());
//  Serial.print("AP MAC:"); Serial.println(WiFi.BSSIDstr());
//  pinMode(ledPin, OUTPUT);
}

void loop() { 
  if (Serial.available() > 0) {
    String cmd = Serial.readString();
    client.connect(server, 80);
    client.print(cmd+"\n");
    client.flush();
    client.stop();  
  }
  delay(2000);
}
