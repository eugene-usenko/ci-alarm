
#include <RH_ASK.h>
#include <SPI.h>
RH_ASK rftx;

void dump(uint8_t* data, uint8_t len) {
  Serial.print("sent: ");
  for(int i=0;i<len;i++){
    Serial.print("0x");
    Serial.print(data[i] < 16 ? "0" : "");
    Serial.print(data[i], HEX); 
    Serial.print(" ");
  }
  Serial.println(); 
}

void setup()
{
    Serial.begin(9600);
    rftx.init();
}

void loop()
{
    if (Serial.available() > 0)
    {
      String cmd = Serial.readString();
      if(cmd == "on" || cmd == "off"){

        uint8_t len = cmd.length();
        uint8_t data[len];
        cmd.toCharArray(data, len);

        rftx.send(data, len);
        rftx.waitPacketSent();
        delay(1000);
        dump(data, len); 
      }
    }
}
