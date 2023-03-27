#include "Armario.h"
#include <gui.h>

using namespace std;

Armario::Armario(float t_x, float t_y, float t_z,
                 float r_x, float r_y, float r_z,
                 float s_x, float s_y, float s_z,
                 bool sel, bool cl)
{
  trans_x = t_x;
  trans_y = t_y;
  trans_z = t_z;
  rot_x = r_x;
  rot_y = r_y;
  rot_z = r_z;
  scale_x = s_x;
  scale_y = s_y;
  scale_z = s_z;
  selected = sel;
  local_coord = cl;
}

void Armario::criar()
{
  Model3DS *caneca = new Model3DS("./3ds/armario.3DS");

  glScalef(0.02, 0.02, 0.02);
  glRotatef(1, 180, 0, 0);
  glTranslatef(0, 1, 0);
  caneca->draw();
}

void Armario::desenha()
{
  glPushMatrix();
  Objeto::desenha(); // T.Rz.Ry.Rx.S. p
  criar();
  glPopMatrix();
}
