#pragma once

#include<iostream>
#include<fstream>
#include<vector>
#include "nodo.h"
#include "arista.h"
#include "tools.h"
#include <sstream>

class Grafo {
 public:
   Grafo(std::string);
   void RecorridoProfundidad();
   void RecorridoAmplitud();

 private:
   std::vector<Nodo*> vertices_;
   std::vector<Arista*> aristas_;


};
