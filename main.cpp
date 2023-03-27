#include <iostream>
#include <vector>

#include "Objeto.h"
#include "Balcao.h"
#include "Mesa.h"
#include "Tamborete.h"

#include "Parede.h"

#include "model3ds.h"

using namespace std;

#include <gui.h>

Mesa *mesa = new Mesa(0, 0, 0, 0, 0, 0, 1, 1, 1, false, false);
Balcao *balcao = new Balcao(2, 0, 2.5, 0, 180, 0, 1, 1, 1, false, false);
Tamborete *tamborete = new Tamborete(0, 0, 0, 0, 0, 0, 1, 1, 1, false, true);

Parede *paredeLeft = new Parede(-5, 0, 0, 0, 270, 0, 1, 1, 1, false, false);
Parede *paredeBack = new Parede(0, 0, -5, 0, 0, 0, 1, 1, 1, false, false);

vector<Objeto *> objetos;

void displayInner()
{
  glClearColor(0.53, 0.81, 0.92, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  GUI::setLight(0, 3, 5, 4, true, false); //(tecla de apagar, x,y,z , desligar e ligar luz, (false = forte, true = atenuada))

  // GUI::drawOrigin(0.5);//(pontos em caxa eixo)
  GUI::drawOriginAL(5, 1);               // (tamanho de cada eixo, pontos em cada eixo)
  GUI::setColor(0.8, 0.8, 0.8, 1, true); // (r,g,b, alpha, true = desenha com cor

  GUI::drawFloor(10, 10, 0.5, 0.5); //(largura, comprimento, vertices largura, vertices comprimento)

  // GUI::setColor(0,1,0, 1,true);
  // GUI::drawBox(0+desl.x,0+desl.y,0+desl.z, 1+desl.x,1+desl.y,1+desl.z);//(x0,y0,z0, xf,yf,zf)

  for (int i = 0; i < objetos.size(); ++i)
  {
    glPushMatrix();
    objetos[i]->desenha();
    glPopMatrix();
  }
}

void desenha()
{
  GUI::displayInit();

  displayInner();

  glPushMatrix();
    paredeLeft->desenha();
    paredeBack->desenha();
  glPopMatrix();
  
  GUI::displayEnd();
}

int main(int argc, char *argv[])
{
 /*  objetos.push_back(mesa);
  objetos.push_back(balcao); */
  objetos.push_back(tamborete);

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