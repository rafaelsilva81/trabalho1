#ifndef CANECA_H
#define CANECA_H

#include <Objeto.h>

using namespace std;

class Caneca : public Objeto
{
public:
  Caneca(
      float t_x, float t_y, float t_z,
      float r_x, float r_y, float r_z,
      float s_x, float s_y, float s_z,
      bool sel, bool cl);
  void criar();
  void desenha();
};

#endif // CANECA_H
