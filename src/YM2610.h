#ifndef YM2610_H_
#define YM2610_H_
class YM2610
{
private:
    int * _dataPins; //Digital I/O pins
    int * _radPins;  //ADPCM_A Address pins
    int * _padPins;  //ADPCM_B Address pins
    int _CS;
    int _RD;
    int _WR;
    int _A1;
    int _A0;
    int _IRQ;
    int _IC;
    void WriteDataPins(unsigned char data);
    void WriteRADPins(unsigned char data);
    void WritePADPins(unsigned char data);
public:
    YM2610(int * dataPins, int * radPins, int * padPins, int CS, int RD, int WR, int A1, int A0, int IRQ, int IC);
    void Reset();
    void SendDataPins(unsigned char addr, unsigned char data, bool port);
};
#endif