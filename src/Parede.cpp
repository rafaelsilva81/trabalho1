#include "Parede.h"
#include <gui.h>

using namespace std;

Parede::Parede(int id, float t_x, float t_y, float t_z,
               float r_x, float r_y, float r_z,
               float s_x, float s_y, float s_z,
               bool sel)
{
  object_id = id;
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
}

void Parede::criar()
{

  // Desabilita o culling para que as faces de trás também sejam desenhadas
  glEnable(GL_CULL_FACE);

  // Parede onde
  // x = 5 e y = 5
  glBegin(GL_QUADS);
  glNormal3f(0.0, 0.0, -1.0);
  glVertex3f(-5.0, 0.0, -0.05);
  glVertex3f(-5.0, 5.0, -0.05);
  glVertex3f(5.0, 5.0, -0.05);
  glVertex3f(5.0, 0.0, -0.05);
  glEnd();
}

void Parede::desenha()
{
  glPushMatrix();
  Objeto::desenha(); // T.Rz.Ry.Rx.S. p
  criar();
  glPopMatrix();
}

std::string Parede::getClassName()
{
  return "Parede";
}
