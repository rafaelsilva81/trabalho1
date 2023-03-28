#include <iostream>
#include <vector>
#include <gui.h>
#include <fstream>
#include <string>

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

#include "bib/json.hpp"

using namespace std;
using json = nlohmann::json;

// Paredes (não serão objetos interativos)
Parede *paredeLeft = new Parede(1, -5., 0., 0., 0., 270., 0., 1., 1., 1., false);
Parede *paredeBack = new Parede(1, 0., 0., -5., 0., 180., 0., 1., 1., 1., false);

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

void saveScene()
{
  // Pegar todos os objetos, e salvar no arquivo save

  std::ifstream f("save.json");

  // Limpar o arquivo (precaução)
  f.clear();

  /*

    Mesa *mesa = new Mesa(1, 3.0, 0.0, 2.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, false);
    FORMATO DO JSON
    [
      {
        id: 1,
        class: "Mesa",
        t_x: 3.0,
        t_y: 0.0,
        t_z: 2.0,
        r_x: 0.0,
        r_y: 0.0,
        r_z: 0.0,
        s_x: 1.0,
        s_y: 1.0,
        s_z: 1.0,
        selected: false
      },
    ]
  */

  // Salvar os objetos
  json j;

  // iniciar o json com array vazio
  j = json::array();

  for (auto &obj : objetos)
  {
    cout << "Salvando objeto " << obj->getClassName() << endl;
    json objJson;
    objJson["id"] = obj->object_id;
    objJson["class"] = obj->getClassName(); // Nome da classe legivel (Mesa, Balcao)
    objJson["t_x"] = obj->trans_x;
    objJson["t_y"] = obj->trans_y;
    objJson["t_z"] = obj->trans_z;
    objJson["r_x"] = obj->rot_x;
    objJson["r_y"] = obj->rot_y;
    objJson["r_z"] = obj->rot_z;
    objJson["s_x"] = obj->scale_x;
    objJson["s_y"] = obj->scale_y;
    objJson["s_z"] = obj->scale_z;
    objJson["selected"] = false; // Nunca vai estar selecionado

    j.push_back(objJson);
  }

  // Salvar o json no arquivo
  std::ofstream o("save.json");
  o << std::setw(4) << j << std::endl;
}

void readSave()
{
  // Lê o arquivo de save
  ifstream save;
  save.open("save.json");

  if (!save.is_open())
  {
    cout << "ARQUIVO DE SAVE NAO ENCONTRADO" << endl;

    // Criar o arquivo
    ofstream createSave;
    createSave.open("save.json");
    createSave.close();
    saveScene();

    // Criar os objetos da cena inicial
    Mesa *mesa = new Mesa(1, 3.0, 0.0, 2.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, false);
    Balcao *balcao = new Balcao(1, -2.0, 0.0, -2.5, 0., 360., 0., 1., 1., 1., false);
    Prateleira *prateleira = new Prateleira(1, -2., 2.5, -4.7, 0., 0., 0., 1., 1., 1., false);

    Tamborete *tamborete = new Tamborete(1, 3., 0., 2., 0., 0., 0., 1., 1., 1., false);
    Barril *barril = new Barril(1, 0., 0., 0., 0., 0., 0., 1., 1., 1., false);
    Caneca *caneca = new Caneca(1, 0., 0., 0., 0., 0., 0., 1., 1., 1., false);
    Armario *armario = new Armario(1, -4.0, 0.0, -4.5, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, false);

    objetos.push_back(mesa);
    objetos.push_back(balcao);
    objetos.push_back(prateleira);

    objetos.push_back(tamborete);
    objetos.push_back(barril);
    objetos.push_back(caneca);
    objetos.push_back(armario);

    saveScene();
  }
  else
  {
    cout << "ARQUIVO DE SAVE ENCONTRADO" << endl;
    // Ler os objetos
    // formato do json:
    /*

      Mesa *mesa = new Mesa(1, 3.0, 0.0, 2.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, false);
      FORMATO DO JSON
      [
        {
          id: 1,
          class: "Mesa",
          t_x: 3.0,
          t_y: 0.0,
          t_z: 2.0,
          r_x: 0.0,
          r_y: 0.0,
          r_z: 0.0,
          s_x: 1.0,
          s_y: 1.0,
          s_z: 1.0,
          selected: false
        },
        {}
      ]
    */
    for (auto &obj : json::parse(save))
    {
      // Cria o objeto baseado na classe
      string classe = obj["class"];

      int id = obj["id"];
      float t_x = obj["t_x"];
      float t_y = obj["t_y"];
      float t_z = obj["t_z"];
      float r_x = obj["r_x"];
      float r_y = obj["r_y"];
      float r_z = obj["r_z"];
      float s_x = obj["s_x"];
      float s_y = obj["s_y"];
      float s_z = obj["s_z"];
      bool selected = obj["selected"];

      // Criar o objeto
      if (classe == "Mesa")
      {
        objetos.push_back(new Mesa(id, t_x, t_y, t_z, r_x, r_y, r_z, s_x, s_y, s_z, selected));
      }
      else if (classe == "Balcao")
      {
        objetos.push_back(new Balcao(id, t_x, t_y, t_z, r_x, r_y, r_z, s_x, s_y, s_z, selected));
      }
      else if (classe == "Prateleira")
      {
        objetos.push_back(new Prateleira(id, t_x, t_y, t_z, r_x, r_y, r_z, s_x, s_y, s_z, selected));
      }
      else if (classe == "Tamborete")
      {
        objetos.push_back(new Tamborete(id, t_x, t_y, t_z, r_x, r_y, r_z, s_x, s_y, s_z, selected));
      }
      else if (classe == "Barril")
      {
        objetos.push_back(new Barril(id, t_x, t_y, t_z, r_x, r_y, r_z, s_x, s_y, s_z, selected));
      }
      else if (classe == "Caneca")
      {
        objetos.push_back(new Caneca(id, t_x, t_y, t_z, r_x, r_y, r_z, s_x, s_y, s_z, selected));
      }
      else if (classe == "Armario")
      {
        objetos.push_back(new Armario(id, t_x, t_y, t_z, r_x, r_y, r_z, s_x, s_y, s_z, selected));
      }
      else if (classe == "Parede")
      {
        objetos.push_back(new Parede(id, t_x, t_y, t_z, r_x, r_y, r_z, s_x, s_y, s_z, selected));
      }
    }
  }
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

  // Adiciona as paredes
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

  grid();

  GUI::displayEnd();
}

int main(int argc, char *argv[])
{

  readSave();
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