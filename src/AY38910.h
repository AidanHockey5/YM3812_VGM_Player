#ifndef AY38910_H_
#define AY38910_H_

class AY38910
{
private:
  int * _dataPins;
  int _BDIR, _BC1;
  void WritePortData(unsigned char data);
public:
  AY38910(int * dataPins, int BDIR, int BC1); //BC2 should be pulled high (+5v)
  void Send(unsigned char addr, unsigned char data);
  void Reset();
};
#endif
