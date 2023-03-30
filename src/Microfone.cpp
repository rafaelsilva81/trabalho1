#include "Microfone.h"
#include <gui.h>

using namespace std;

Microfone::Microfone(int id, float t_x, float t_y, float t_z,
                     float r_x, float r_y, float r_z,
                     float s_x, float s_y, float s_z,
                     bool sel, bool coord)
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
  show_coord = coord;
  model = new Model3DS("./3ds/microfone.3DS");
}

void Microfone::criar()
{

  if (show_coord)
  {
    GUI::drawOrigin(1);
  }

  if (selected)
  {
    // Amarelo se estiver selecionado
    GUI::setColor(1, 1, 0, 1, true);
  }
  else
  {
    // Colorir (#94a3b8)
    GUI::setColor(0.5804, 0.6392, 0.7216, 1, true);
  }

  glScalef(0.012, 0.012, 0.012);
  glRotatef(270, 90, 0, 0);
  glTranslatef(0, 0, 0);
  model->draw(false); // Só pinta se não estiver selecionado
}

void Microfone::desenha()
{
  glPushMatrix();
  Objeto::desenha(); // T.Rz.Ry.Rx.S. p
  criar();
  glPopMatrix();
}

std::string Microfone::getClassName()
{
  return "Microfone";
}
