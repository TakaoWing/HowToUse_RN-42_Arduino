#include <SoftwareSerial.h>

const int kTxPin = 1;
const int kRxPin = 0;
const int kLedPin = 13;

SoftwareSerial bluetoothSerial(kRxPin, kTxPin);

int ledMode = 0;

void setup()
{
    pinMode(kLedPin, OUTPUT);
    digitalWrite(kLedPin, LOW);

    bluetoothSerial.begin(115200);
}

void readSerialData()
{
    if (bluetoothSerial.available())
    {
        char inputChar = bluetoothSerial.read();

        switch (inputChar)
        {
        case '0':
            bluetoothSerial.println("LED disabled");
            ledMode = 0;
            break;
        case '1':
            bluetoothSerial.println("LED enabled");
            ledMode = 1;
            break;
        }
    }
}

void updateLedState()
{
    digitalWrite(kLedPin, ledMode);
}

void loop()
{
    readSerialData();
    updateLedState();
}