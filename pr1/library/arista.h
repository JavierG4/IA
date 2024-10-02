#pragma once

#include <iostream>
#include <vector>
#include "nodo.h"

class Arista {
 public:
   Arista(int,int,int);
   int Get_coste() { return coste_;}
   int Get_origen() { return origen_;}
   int Get_destino() { return destino_;}
   void Ver_arista();
 private:
   int coste_;
   int origen_;
   int destino_;
};