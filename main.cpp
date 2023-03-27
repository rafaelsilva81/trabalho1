#include <iostream>
#include <vector>

// Objeto base
#include "Objeto.h"

// Objetos criados
#include "Balcao.h"
#include "Mesa.h"
#include "Prateleira.h"
#include "Parede.h" // Não iterativo

// Objetos importados do .3DS
#include "Tamborete.h"
#include "Barril.h"
#include "Caneca.h"
#include "Armario.h"

using namespace std;

#include <gui.h>

/*
  Instanciando objetos e montando a cena
*/
Mesa *mesa = new Mesa(3, 0, 2, 0, 0, 0, 1, 1, 1, false, false);
Balcao *balcao = new Balcao(-2, 0, -2.5, 0, 360, 0, 1, 1, 1, false, false);
Prateleira *prateleira = new Prateleira(-2, 2.5, -4.7, 0, 0, 0, 1, 1, 1, false, false);

Tamborete *tamborete = new Tamborete(3, 0, 2, 0, 0, 0, 1, 1, 1, false, true);
Barril *barril = new Barril(0, 0, 0, 0, 0, 0, 1, 1, 1, false, true);
Caneca *caneca = new Caneca(0, 0, 0, 0, 0, 0, 1, 1, 1, false, true);
Armario *armario = new Armario(-4, 0, -4.5, 0, 0, 0, 1, 1, 1, false, true);

Parede *paredeLeft = new Parede(-5, 0, 0, 0, 270, 0, 1, 1, 1, false, false);
Parede *paredeBack = new Parede(0, 0, -5, 0, 180, 0, 1, 1, 1, false, false);

vector<Objeto *> objetos;

void grid()
{
  glBegin(GL_LINES);
  for (float i = -10; i <= 10; i += 1.0)
  {
    // Draw lines along the x-axis
    glVertex3f(i, 0, -10);
    glVertex3f(i, 0, 10);

    // Draw lines along the z-axis
    glVertex3f(-10, 0, i);
    glVertex3f(10, 0, i);
  }
  glEnd();
}

void montarCena()
{

  // Cor de fundo
  glClearColor(0.53, 0.81, 0.92, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  // Definir iluminação
  GUI::setLight(0, 3, 5, 4, true, false);

  // Debug do eixo
  GUI::drawOriginAL(5, 1);
  GUI::setColor(0.8, 0.8, 0.8, 1, true);
  // Piso
  GUI::drawFloor(10, 10, 0.5, 0.5);

  // GUI::setColor(0,1,0, 1,true);
  // GUI::drawBox(0+desl.x,0+desl.y,0+desl.z, 1+desl.x,1+desl.y,1+desl.z);//(x0,y0,z0, xf,yf,zf)

  glPushMatrix();
  paredeLeft->desenha();
  paredeBack->desenha();
  glPopMatrix();

  for (int i = 0; i < objetos.size(); ++i)
  {
    // Itera pelos objetos e desenha
    glPushMatrix();
    objetos[i]->desenha();
    glPopMatrix();
  }
}

void desenha()
{
  GUI::displayInit();

  montarCena();

  /*   glPushMatrix();
    paredeLeft->desenha();
    paredeBack->desenha();
    glPopMatrix(); */

  grid();

  GUI::displayEnd();
}

int main(int argc, char *argv[])
{
  objetos.push_back(mesa);
  objetos.push_back(balcao);
  objetos.push_back(prateleira);

  objetos.push_back(tamborete);
  objetos.push_back(barril);
  objetos.push_back(caneca);
  objetos.push_back(armario);

  // GUI gui(800,600); // (largura, altura)
  GUI gui = GUI(800, 600, desenha);
}

/*
  1. Mesa
  2. Balcao
  3. Cadeira (importado)
  4. Garçom? (importado)
  5. Prato (importado)
*/