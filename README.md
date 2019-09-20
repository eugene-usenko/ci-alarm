# Troubleshoting

```bash
# avrdude: ser_open(): can't open device "/dev/ttyUSB0": Permission denied
sudo usermod -a -G dialout $USER
sudo chmod a+rw /dev/ttyUSB0
```

# Resources

* [Guide for RF 433MHz Transmitter/Receiver](https://randomnerdtutorials.com/rf-433mhz-transmitter-receiver-module-with-arduino/)
* [How 433MHz RF Tx-Rx Modules Work & Interface with Arduino](https://lastminuteengineers.com/433mhz-rf-wireless-arduino-tutorial/)
* [Arduino Tutorial: Serial Inputs](https://www.norwegiancreations.com/2017/12/arduino-tutorial-serial-inputs/)
* [Achtung!](https://habr.com/ru/company/mailru/blog/193606/)
* [RadioHead](http://www.airspayce.com/mikem/arduino/RadioHead/)
* [Cron Jobs and Crontab on Linux Explained](https://devconnected.com/cron-jobs-and-crontab-on-linux-explained/)
