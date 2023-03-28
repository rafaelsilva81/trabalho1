#ifndef OBJETO_H
#define OBJETO_H

#include <string>
#include <gui.h>

class Objeto
{
public:
  int object_id;
  float trans_x, trans_y, trans_z;
  float rot_x, rot_y, rot_z;
  float scale_x, scale_y, scale_z;
  bool selected;
  virtual void desenha();
  virtual std::string getClassName() = 0; // Função pura
};

#endif // OBJETO_H
