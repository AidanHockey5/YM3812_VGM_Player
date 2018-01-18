#ifndef SPIRAM_H_
#define SPIRAM_H_
#include <Arduino.h>
class SPIRAM
{
public:
    SPIRAM(int CS);
    unsigned char ReadByte(uint16_t addr);
    void WriteByte(uint16_t addr, unsigned char data);
private:
    int _CS;
};
#endif