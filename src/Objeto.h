#ifndef OBJETO_H
#define OBJETO_H

#include <gui.h>

class Objeto
{
public:
  float trans_x, trans_y, trans_z;
  float rot_x, rot_y, rot_z;
  float scale_x, scale_y, scale_z;
  bool selected;
  bool local_coord;
  virtual void desenha();
};

#endif // OBJETO_H
