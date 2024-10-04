#pragma once

#include<iostream>
#include<fstream>
#include<vector>
#include <set>
#include "nodo.h"
#include <cmath>

class Tablero {
 public:
   Tablero (std::string);
   void ImprimirEnFichero(std::string );
   void BusquedaA ();
 private:
   int Calcular_h(int,int);
   int Calcular_f(int,int,int);
   std::vector<std::vector<int>> tablero_;
   int inicialx_;
   int inicialy_;
   int finalx_;
   int finaly_;
};