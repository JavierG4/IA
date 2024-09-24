#pragma once

#include <iostream>
#include <vector>

class Nodo {
 public:
   int Get_numero() { return numero_;}
   std::vector<Nodo*> Get_hijo() { return hijo_;}
   Nodo* Get_padre() { return padre_;}


 private:
   int numero_;
   std::vector<Nodo*> hijo_;
   Nodo* padre_;
   // profundiad ?
   // Coste acumulado ?
};