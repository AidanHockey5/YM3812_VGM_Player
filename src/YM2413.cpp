#include "YM2413.h"
#include <Arduino.h>
YM2413::YM2413(int * dataPins, int CS, int A0, int WE, int IC)
{
    _dataPins = dataPins;
    _CS = CS;
    _A0 = A0;
    _WE = WE;
    _IC = IC;
    for(int i = 0; i<8; i++)
        pinMode(*(_dataPins+i), OUTPUT);
    pinMode(_CS, OUTPUT);
    pinMode(_A0, OUTPUT);
    pinMode(_WE, OUTPUT);
    pinMode(_IC, OUTPUT);

    digitalWrite(_CS, LOW);
    digitalWrite(_WE, LOW);
    digitalWrite(_A0, LOW);
}

void YM2413::Send(unsigned char addr, unsigned char data)
{
    digitalWrite(_CS, HIGH);
    digitalWrite(_A0, LOW);
    WritePortData(addr);
    digitalWrite(_CS, LOW);
    delayMicroseconds(4);
    digitalWrite(_CS, HIGH);
    digitalWrite(_A0, HIGH);
    WritePortData(data);
    digitalWrite(_CS, LOW);
    delayMicroseconds(25);
    digitalWrite(_CS, HIGH);
}

void YM2413::Reset()
{
    digitalWrite(_IC, LOW);
    delayMicroseconds(25);
    digitalWrite(_IC, HIGH);
}

void YM2413::WritePortData(unsigned char data)
{
    for(int i=0; i<8; i++)
    {
      digitalWrite(*(_dataPins+i), ((data >> i)&1));
    }
}