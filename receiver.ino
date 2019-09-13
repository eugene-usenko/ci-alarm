#include <RH_ASK.h>
#include <SPI.h>
RH_ASK rftx;

void setup()
{
    Serial.begin(9600);
    if (!rftx.init())
        Serial.println("init failed");
}

void loop()
{

    uint8_t data[5];
    uint8_t len = sizeof(data);
    if (rftx.recv(data, &len))
    {
        Serial.print("Message: ");
        Serial.println((char *)data);
    }

    delay(1000);
    Serial.println("tick");
}