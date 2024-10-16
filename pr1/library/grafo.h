#pragma once

#include<iostream>
#include<fstream>
#include<vector>
#include "nodo.h"
#include "arista.h"
#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <sstream>
#include <algorithm> 
#include <stack>


class Grafo {
 public:
   Grafo(std::string);
   void RecorridoProfundidad(int, int);
   void RecorridoAmplitud(int, int);
   ~Grafo();
   void Visualizar();

 private:
   std::vector<Nodo*> vertices_;
   std::vector<std::vector<Arista*>> aristas_;
   int Camino(int,int);
   bool Visitado(Nodo*);

};
