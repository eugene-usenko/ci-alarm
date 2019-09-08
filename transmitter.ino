#include <RH_ASK.h>
#include <SPI.h>
RH_ASK rftx;

void setup()
{
    Serial.begin(9600);
    rftx.init();
}

void loop()
{
    if (Serial.available())
    {
        uint8_t cmd[5];
        size_t len = sizeof(c) - 1;
        size_t n = Serial.readBytesUntil('\r', cmd, len);

        rftx.send(cmd, n);
        rftx.waitPacketSent();
        delay(1000);
    }
}
