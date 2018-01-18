#include "SPIRAM.h"
#include <SPI.h>

SPIRAM::SPIRAM(int CS)
{
    _CS = CS;
    pinMode(_CS, OUTPUT);

    //Set read mode to "byte"
    digitalWriteFast(_CS, HIGH);
    SPI2.begin();
    digitalWriteFast(_CS, LOW);
    SPI2.transfer(0x05);
    SPI2.transfer(0x00);
    digitalWriteFast(_CS, HIGH);
    SPI2.endTransaction();

    //Set write mode to "byte"
    SPI2.begin();
    digitalWriteFast(_CS, LOW);
    SPI2.transfer(0x01);
    SPI2.transfer(0x00);
    digitalWriteFast(_CS, HIGH);
    SPI2.endTransaction();
}

unsigned char SPIRAM::ReadByte(uint16_t addr)
{
    SPI2.begin();
    digitalWriteFast(_CS, LOW);
    SPI2.transfer(0x03);
    SPI2.transfer16(addr);
    unsigned char data = SPI2.transfer(0x00);
    digitalWriteFast(_CS, HIGH);
    SPI2.endTransaction();
    return data;
}

void SPIRAM::WriteByte(uint16_t addr, unsigned char data)
{
    SPI2.begin();
    digitalWriteFast(_CS, LOW);
    SPI2.transfer(0x02);
    SPI2.transfer16(addr);
    SPI2.transfer(data);
    digitalWriteFast(_CS, HIGH);
    SPI2.endTransaction();  
}