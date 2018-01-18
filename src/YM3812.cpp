#include "YM3812.h"
#include <Arduino.h>
YM3812::YM3812(int * dataPins, int CS, int RD, int WR, int A0, int IRQ, int IC)
{
    _dataPins = dataPins;
    _CS = CS;
    _RD = RD;
    _WR = WR;
    _A0 = A0;
    _IRQ = IRQ;
    _IC = IC;
    for(int i = 0; i<8; i++)
    {
        pinMode(*(_dataPins+i), OUTPUT);
    }

    pinMode(_CS, OUTPUT);
    pinMode(_RD, OUTPUT);
    pinMode(_WR, OUTPUT);
    pinMode(_A0, OUTPUT);
    pinMode(_IRQ, OUTPUT);
    pinMode(_IC, OUTPUT);

    digitalWrite(_CS, HIGH);
    digitalWrite(_RD, LOW);
    digitalWrite(_WR, LOW);
    digitalWrite(_A0, LOW);
    digitalWrite(_IRQ, LOW);
    digitalWrite(_IC, LOW);
}

void YM3812::Reset()
{
    digitalWrite(_IC, LOW);
    delayMicroseconds(25);
    digitalWrite(_IC, HIGH);
}

void YM3812::WriteDataPins(unsigned char data) //Digital I/O
{
    for(int i=0; i<8; i++)
    {
      digitalWrite(*(_dataPins+i), ((data >> i)&1));
    }
}

void YM3812::SendDataPins(unsigned char addr, unsigned char data)
{
        
        digitalWrite(_CS, HIGH);
        digitalWrite(_RD, HIGH);
        digitalWrite(_WR, LOW);
        digitalWrite(_A0, LOW);
        WriteDataPins(addr);
        digitalWrite(_CS, LOW);
        delayMicroseconds(1); //Replace with 10 nS delay?
        digitalWrite(_CS, HIGH);
        digitalWrite(_RD, HIGH);
        digitalWrite(_WR, LOW);
        digitalWrite(_A0, HIGH);
        WriteDataPins(data);
        digitalWrite(_CS, LOW);
        delayMicroseconds(1); //Replace with 10 nS delay?
        digitalWrite(_CS, HIGH);
        digitalWrite(_RD, LOW);
        digitalWrite(_WR, HIGH);
        digitalWrite(_A0, HIGH);
}