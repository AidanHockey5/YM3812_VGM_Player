#include "LTC6903.h"
#include <SPI.h>
LTC6903::LTC6903(uint16_t oct, uint16_t dac, int target)
{
  _oct = oct;
  _dac = dac;
  _target = target;
}

void LTC6903::Set()
{
  pinMode(_target, OUTPUT);
  SPI.begin();
  //SPI.beginTransaction(SPISettings(20000000, MSBFIRST, SPI_MODE0));
  unsigned char CNF = 0b00000000;
  uint16_t BitMap = (_oct << 12) | (_dac << 2) | CNF;
  byte Byte1=(byte)(BitMap >> 8 );
  byte Byte2=(byte)BitMap;
  digitalWriteFast(_target, LOW);
  SPI.transfer(Byte1);
  SPI.transfer(Byte2);
  digitalWriteFast(_target, HIGH);
  SPI.endTransaction();
}