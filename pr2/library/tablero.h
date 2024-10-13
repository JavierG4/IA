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
   void ImprimirEnFichero(std::string);
   void BusquedaA (std::string);
   int Get_inicialx() {return inicialx_;}
   int Get_inicialy() {return inicialy_;}
   int Get_finalx() {return finalx_;}
   int Get_finaly() {return finaly_;}
   void Set_inicial(int x, int y);
   void Set_final(int x, int y);
   void tabla(int,int, Nodo*,std::string);

 private:
   int Calcular_h(int,int);
   int Calcular_f(int,int,int);
   std::vector<std::vector<int>> tablero_;
   int inicialx_; // Inicial 3
   int inicialy_; // Inicial 3
   int finalx_; // final 4
   int finaly_;
};