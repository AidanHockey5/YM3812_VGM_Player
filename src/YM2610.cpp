#include "YM2610.h"
#include <Arduino.h>

YM2610::YM2610(int * dataPins, int * radPins, int * padPins, int CS, int RD, int WR, int A1, int A0, int IRQ, int IC)
{
    _dataPins = dataPins;
    _radPins = radPins;
    _padPins = padPins;
    _CS = CS;
    _RD = RD;
    _WR = WR;
    _A1 = A1;
    _A0 = A0;
    _IRQ = IRQ;
    _IC = IC;
    for(int i = 0; i<8; i++)
    {
        pinMode(*(_dataPins+i), OUTPUT);
        pinMode(*(_radPins+i), OUTPUT);
        pinMode(*(_padPins+i), OUTPUT);
    }

    pinMode(_CS, OUTPUT);
    pinMode(_RD, OUTPUT);
    pinMode(_WR, OUTPUT);
    pinMode(_A1, OUTPUT);
    pinMode(_A0, OUTPUT);
    pinMode(_IRQ, OUTPUT);
    pinMode(_IC, OUTPUT);

    digitalWrite(_CS, HIGH);
    digitalWrite(_RD, LOW);
    digitalWrite(_WR, LOW);
    digitalWrite(_A1, LOW);
    digitalWrite(_A0, LOW);
    digitalWrite(_IRQ, LOW);
    digitalWrite(_IC, LOW);
}

void YM2610::Reset()
{
    digitalWrite(_IC, LOW);
    delayMicroseconds(25);
    digitalWrite(_IC, HIGH);
}

void YM2610::WriteDataPins(unsigned char data) //Digital I/O
{
    for(int i=0; i<8; i++)
    {
      digitalWrite(*(_dataPins+i), ((data >> i)&1));
    }
}

void YM2610::WriteRADPins(unsigned char data) //ADPCM_A
{
    for(int i=0; i<8; i++)
    {
      digitalWrite(*(_radPins+i), ((data >> i)&1));
    }
}

void YM2610::WritePADPins(unsigned char data) //ADPCM_B
{
    for(int i=0; i<8; i++)
    {
      digitalWrite(*(_padPins+i), ((data >> i)&1));
    }
}

void YM2610::SendDataPins(unsigned char addr, unsigned char data, bool port) //port=0 for PORT0, port=1 for PORT1
{
        digitalWrite(_A1, port);
        digitalWrite(_A0, LOW);
        digitalWrite(_CS, LOW);
        WriteDataPins(addr);
        digitalWrite(_WR, LOW);
        delayMicroseconds(1); //Replace with 10 nS delay?
        digitalWrite(_WR, HIGH);
        digitalWrite(_CS, HIGH);
        delayMicroseconds(1); //Replace with 10 nS delay?
        digitalWrite(_A0, HIGH);
        digitalWrite(_CS, LOW);
        WriteDataPins(data);
        digitalWrite(_WR, LOW);
        delayMicroseconds(1); //Replace with 10 nS delay?
        digitalWrite(_WR, HIGH);
        digitalWrite(_CS, HIGH);
}

