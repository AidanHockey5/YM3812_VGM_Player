#include "AY38910.h"
#include <Arduino.h>
AY38910::AY38910(int * dataPins, int BDIR, int BC1)
{
  _dataPins = dataPins;
  _BDIR = BDIR;
  _BC1 = BC1;

  for(int i = 0; i<8; i++)
    pinMode(*(_dataPins+i), OUTPUT);

  pinMode(_BDIR, OUTPUT);
  pinMode(_BC1, OUTPUT);
  digitalWrite(_BC1, LOW); //Set chip to "inactive"
  digitalWrite(_BDIR, LOW);
}

void AY38910::Send(uint8_t addr, uint8_t data)
{
    digitalWrite(_BC1, LOW); //Set chip to "inactive"
    digitalWrite(_BDIR, LOW);
    WritePortData(addr);
    digitalWrite(_BC1, HIGH); //Set chip to "latch"
    digitalWrite(_BDIR, HIGH);

    digitalWrite(_BC1, LOW); //Set chip to "inactive"
    digitalWrite(_BDIR, LOW);

    digitalWrite(_BC1, LOW); //Set chip to "write"
    digitalWrite(_BDIR, HIGH);
    WritePortData(data);
    digitalWrite(_BC1, LOW); //Set chip to "inactive"
    digitalWrite(_BDIR, LOW);
}

void AY38910::WritePortData(unsigned char data)
{
  for(int i=0; i<8; i++)
  {
    digitalWrite(*(_dataPins+i), ((data >> i)&1));
  }
}

void AY38910::Reset()
{
  for(int i=0; i<16; i++) //Reset AY3810
  {
    Send(i, 0);
  }
}