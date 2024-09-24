#pragma once

#include <iostream>
#include <vector>
#include "nodo.h"

class Arista {
 public:
   double Get_coste() { return coste_;}
   Nodo* Get_origen() { return origen_;}
   Nodo* Get_destino() { return destino_;}
 private:
   double coste_;
   Nodo* origen_;
   Nodo* destino_;
};