#ifndef YM2413_H_
#define YM2413_H_
class YM2413
{
private:
    int * _dataPins;
    int _CS;
    int _A0;
    int _WE;
    int _IC;
    void WritePortData(unsigned char data);
public:
    YM2413(int * dataPins, int CS, int A0, int WE, int IC);
    void Send(unsigned char addr, unsigned char data);
    void Reset();
};
#endif