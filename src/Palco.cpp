#include "Palco.h"
#include <gui.h>

using namespace std;

Palco::Palco(int id, float t_x, float t_y, float t_z,
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
}

void Palco::criar()
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
    GUI::setColor(0.1176, 0.1607, 0.2313, 1, true);
  }

  // Palco
  GUI::drawBox(-1.5, 0, -0.5, 1.5, 1, 1.5);

  // Escadinha do palco, na direita do palco na frente
  // Alterar a cor para #ef4444
  if (!selected)
  {
    GUI::setColor(0.9373, 0.2667, 0.2667, 1, true);
  }
  GUI::drawBox(0, 0, 1.5, 1.5, 1, 2);
  GUI::drawBox(0, 0, 2, 1.5, 0.5, 2.5);
}

void Palco::desenha()
{
  glPushMatrix();
  Objeto::desenha(); // T.Rz.Ry.Rx.S. p
  criar();
  glPopMatrix();
}

std::string Palco::getClassName()
{
  return "Palco";
}