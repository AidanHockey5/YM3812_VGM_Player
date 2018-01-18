#ifndef YM3812_H_
#define YM3812_H_
class YM3812
{
private:
    int * _dataPins; //Digital I/O pins
    int _CS;
    int _RD;
    int _WR;
    int _A0;
    int _IRQ;
    int _IC;
    void WriteDataPins(unsigned char data);
public:
    YM3812(int * dataPins, int CS, int RD, int WR, int A0, int IRQ, int IC);
    void Reset();
    void SendDataPins(unsigned char addr, unsigned char data);
};
#endif