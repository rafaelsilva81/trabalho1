#include "Mesa.h"
#include <gui.h>

using namespace std;

Mesa::Mesa(int id, float t_x, float t_y, float t_z,
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

void Mesa::criar()
{
  GUI::setColor(0.5451, 0.2706, 0.0745, 1, true); // Pintura cor da madeira

  if (selected)
  {
    GUI::setColor(1, 1, 1, 1, true); // Pinta de branco ao selecionar
  }

  // Desabilita o culling para que as faces de trás também sejam desenhadas
  glDisable(GL_CULL_FACE);

  // Perna da mesa
  glBegin(GL_POLYGON);
  glNormal3f(0.0, 0.0, -1.0);
  glVertex3f(-0.05, 0.0, -0.05);
  glVertex3f(-0.05, 1.0, -0.05);
  glVertex3f(0.05, 1.0, -0.05);
  glVertex3f(0.05, 0.0, -0.05);
  glEnd();

  glBegin(GL_POLYGON);
  glNormal3f(0.0, 0.0, 1.0);
  glVertex3f(-0.05, 0.0, 0.05);
  glVertex3f(-0.05, 1.0, 0.05);
  glVertex3f(0.05, 1.0, 0.05);
  glVertex3f(0.05, 0.0, 0.05);
  glEnd();

  glBegin(GL_POLYGON);
  glNormal3f(-1.0, 0.0, 0.0);
  glVertex3f(-0.05, 0.0, -0.05);
  glVertex3f(-0.05, 1.0, -0.05);
  glVertex3f(-0.05, 1.0, 0.05);
  glVertex3f(-0.05, 0.0, 0.05);
  glEnd();

  glBegin(GL_POLYGON);
  glNormal3f(1.0, 0.0, 0.0);
  glVertex3f(0.05, 0.0, -0.05);
  glVertex3f(0.05, 1.0, -0.05);
  glVertex3f(0.05, 1.0, 0.05);
  glVertex3f(0.05, 0.0, 0.05);
  glEnd();

  // Tampo da mesa
  // cor do tampo será vermelho 237, 29, 36
  GUI::setColor(237.0 / 255.0, 29.0 / 255.0, 36.0 / 255.0, 1, true);
  glBegin(GL_POLYGON);
  glNormal3f(0.0, 1.0, 0.0);
  glVertex3f(-0.5, 1.0, -0.5);
  glVertex3f(-0.5, 1.0, 0.5);
  glVertex3f(0.5, 1.0, 0.5);
  glVertex3f(0.5, 1.0, -0.5);
  glEnd();
}

void Mesa::desenha()
{
  glPushMatrix();
  Objeto::desenha(); // T.Rz.Ry.Rx.S. p
  criar();
  glPopMatrix();
}

std::string Mesa::getClassName()
{
  return "Mesa";
}