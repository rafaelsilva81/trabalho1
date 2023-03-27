#ifndef PAREDE_H
#define PAREDE_H

#include <Objeto.h>

using namespace std;

class Parede : public Objeto
{
public:
  Parede(
      float t_x, float t_y, float t_z,
      float r_x, float r_y, float r_z,
      float s_x, float s_y, float s_z,
      bool sel, bool cl);
  void criar();
  void desenha();
};

#endif // PAREDE_H
