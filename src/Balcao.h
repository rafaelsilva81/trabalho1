#ifndef BALCAO_H
#define BALCAO_H

#include <Objeto.h>

using namespace std;

class Balcao : public Objeto
{
public:
  Balcao(
      float t_x, float t_y, float t_z,
      float r_x, float r_y, float r_z,
      float s_x, float s_y, float s_z,
      bool sel, bool cl);
  void criar();
  void desenha();
};

#endif // MESA_H
