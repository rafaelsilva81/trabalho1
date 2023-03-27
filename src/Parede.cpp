#include "Parede.h"
#include <gui.h>

using namespace std;

Parede::Parede(float t_x, float t_y, float t_z,
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

void Parede::criar()
{
	if (local_coord)
  {
    GUI::drawOrigin(1); // Desenha o eixo local
  }
	
	// Desabilita o culling para que as faces de trás também sejam desenhadas
	glDisable(GL_CULL_FACE);

	// Face da parede
	GUI::drawBox(-5, 0, 0, 5, 5, 0.02);


}

void Parede::desenha()
{
	glPushMatrix();
	Objeto::desenha(); // T.Rz.Ry.Rx.S. p
	criar();
	glPopMatrix();
}
